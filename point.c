/*

  File: point.c

  Abstract:

	A Point ADT handling implementation

*/


#include "point.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*structs*/
struct Point_ {
	PList CoordinatesL;
	int size, dim;
};

/*helper functions*/
int* cloneCoordinate(int*);
void deleteCoordinate(int*);
BOOL compareCoordinates(int*, int*);
void printCoordinate(int*);


/*interface functions*/

/*

  Function: PointCreate

  Abstract:

	Creates a new point ADT with designated dimension

  Parameters:
	
	dim - The wanted Point's dimension
	
  Returns: A pointer of point type to the point created. If the point's creation fails , return NULL.

*/
PPoint PointCreate(int dim) {
	if (!dim) return NULL;
	PPoint newPoint;
	newPoint = (PPoint)malloc(sizeof(struct Point_));
	if (!newPoint) return NULL;

	/*dynamic allocation for the list that saves the coordinates*/
	newPoint->CoordinatesL = ListCreate((CLONE_ELEM)cloneCoordinate,(DESTROY_ELEM) deleteCoordinate,(COMPARE_ELEM) compareCoordinates,(PRINT_ELEM) printCoordinate);

	/*initialization*/
	newPoint->dim = dim;
	newPoint->size = 0;

	return newPoint;
}

/*

  Function: PointDestroy

  Abstract:

	Destroys a point - Frees all the memory allocated to the point ADT

  Parameters:

	pP - A pointer to generic element that will be casted to point type - The point the user wants to remove

  Returns: --

*/
void PointDestroy(PElem pP) {
	if (!pP) return;
	PPoint curP = (PPoint)pP;
	ListDestroy(curP->CoordinatesL);
	free(pP);
}

/*

  Function: PointAddCoordinate

  Abstract:

	Adds a coordinate to a selected point

  Parameters:

	pP - A pointer to type point - The point which the user wants to add coordinate to
	newC - the coordinate to be added

  Returns: Result - FAIL if the add failed or SUCCESS if it succeded

*/
Result PointAddCoordinate(PPoint pP, int newC) {
	if (!pP) return FAIL;
	if (pP->size >= pP->dim) return FAIL;
	pP->size++;
	return ListAdd(pP->CoordinatesL, &newC);
}

/*

  Function: PointGetFirstCoordinate

  Abstract:

	Fetch the first coordinate in a selected point using the list iterator

  Parameters:

	pP - A pointer to type point - The point the user wants to get first coordinate

  Returns: The first coordinate that entered to a point

*/
int PointGetFirstCoordinate(PPoint pP) {
	if (!pP) return 0;
	int* first = (int*) ListGetFirst(pP->CoordinatesL);
	return *first;
}

/*

  Function: PointGetNextCoordinate

  Abstract:

	Fetch the next coordinate in a selected point using the list iterator and moves the itaretor forward

  Parameters:

	pP - A pointer to type point - The point the user wants to get next coordinate

  Returns: The next coordinate in a point

*/
int PointGetNextCoordinate(PPoint pP) {
	if (!pP) return 0;
	int* next = (int*)ListGetNext(pP->CoordinatesL);
	if (!next) return 0;
	return *next;
}

/*

  Function: PointPrint

  Abstract:

	Prints the point coordinetions , size and dimension

  Parameters:

	pP - A pointer to type point

  Returns: --

*/
void PointPrint(PElem pP) {
	PPoint curP = (PPoint)pP;
	printf("Point Dimension: %d, Size: %d, Coordinates: ", curP->dim, curP->size);
	ListPrint(curP->CoordinatesL);
}




/*extra functions*/

/*

  Function: PointGetDimension

  Abstract:

	Getter function to the Point dimension

  Parameters:

	pP - A pointer to type point

  Returns: the Point dimension

*/
int PointGetDimension(PPoint pP) {
	if (!pP) return 0;
	return pP->dim;
}

/*

  Function: PointClone

  Abstract:

	Clones a point

  Parameters:

	pP - A pointer to generic element that will be casted to type point

  Returns: A pointer to generic element that will be casted to type point

*/
PElem PointClone(PElem pP) {
	if (!pP) return NULL;
	PPoint curP = (PPoint)pP;
	PPoint newP = PointCreate(curP->dim);
	int curC = PointGetFirstCoordinate(curP);
	int i;
	for (i = 0; i < curP->size;i++) {
		PointAddCoordinate(newP, curC);
		curC = PointGetNextCoordinate(curP);
	}
	return (PElem) newP;
}

/*

  Function: PointsCompare

  Abstract:

	Compares between 2 points

  Parameters:

	pP1 - A pointer to generic element that will be casted to point type
	pP2 - A pointer to generic element that will be casted to point type

  Returns: TRUE if the points are equal or FALSE otherwise

*/
BOOL PointsCompare(PElem pP1, PElem pP2) {
	if (!pP1 && !pP2) return TRUE;
	if ((!pP1 && pP2) || (pP1 && !pP2)) return FALSE;
	PPoint curP1 = (PPoint)pP1;
	PPoint curP2 = (PPoint)pP2;
	return ListCompare(curP1->CoordinatesL, curP2->CoordinatesL);
}



/*helper functions*/

/*

  Function: cloneCoordinate

  Abstract:

	Clones a coordinate using memory allocation

  Parameters:

	c - A pointer to a coordinate that will be copied to a new one

  Returns: A pointed to the cloned coordinate

*/
int* cloneCoordinate(int* c) {
	int* cNew;
	cNew = (int*)malloc(sizeof(int));
	*cNew = *c;
	return cNew;
}

/*

  Function: deleteCoordinate

  Abstract:

	Free the memory allocated to create a coordinate

  Parameters:

	c - A pointer to a coordinate that will be freed

  Returns: --

*/
void deleteCoordinate(int* c) {
	free(c);
}

/*

  Function: compareCoordinates

  Abstract:

	Compares between 2 coordinates - used by points copmare

  Parameters:

	c1 - A pointer to a coordinate
	c2 - A pointer to a coordinate

  Returns: TRUE if the integers are equal or FALSE otherwise

*/
BOOL compareCoordinates(int* c1, int* c2) {
	if (!c1 && !c2) return TRUE;
	if ((!c1 && c2) || (c1 && !c2)) return FALSE;
	if (*c1 == *c2) return TRUE;
	else return FALSE;
}

/*

  Function: printCoordinate

  Abstract:

	Prints a single coordinate - used by the point print 

  Parameters:

	c - A pointer to a coordinate

  Returns: --

*/
void printCoordinate(int* c) {
	if (!c) return;
	printf("%d ", *c);
}

