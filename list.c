/*

  File: list.c

  Abstract:

	Generic Linked-List ADT handling implementation

*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structs*/

struct List_ {
	PNode Head;
	CLONE_ELEM cloneElem;
	DESTROY_ELEM destroyElem;
	COMPARE_ELEM compareElem;
	PRINT_ELEM printElem;
	PNode Iter;
};

struct NODE_ {
	PElem pElem;
	PNode PNext;
};


/*helper functions*/
PNode createNode(PElem, CLONE_ELEM);

/*interface functions*/

/*

  Function: ListCreate

  Abstract:

	Creates a new generic linked list ADT that supports numerous functions

  Parameters:

	cloneElem - A user function that clones an elemnt from designated type
	destroyElem -  A user function that free the memory allocated to an elemnt from designated type
	compareElem -  A user function that compares between 2 elements from designated type according to the user wish
	printElem -  A user function that prints an elemnt from designated type


  Returns: A pointer from type struct List to the list itself. If the list creation fails , return NULL.

*/
PList ListCreate(CLONE_ELEM cloneElem, DESTROY_ELEM destroyElem, COMPARE_ELEM compareElem, PRINT_ELEM printElem) {
	PList pL;
	if ((!cloneElem) || (!destroyElem) || (!compareElem) || (!printElem)) return NULL;
	pL = (PList)malloc(sizeof(struct List_));
	if (!pL) return NULL;
	
	pL->Head = NULL;
	pL->cloneElem = cloneElem;
	pL->destroyElem = destroyElem;
	pL->compareElem = compareElem;
	pL->printElem = printElem;

	return pL;
}


/*

  Function: ListDestroy

  Abstract:

	Destroys a list ADT - Frees a list and all the allocated memory used in the list 

  Parameters:

	pL -  A pointer from type struct List to the list itself

  Returns: --

*/
void ListDestroy(PList pL) {
	if (!pL) return;
	PNode pE;
	while (pL->Head) {
		pE = pL->Head;
		pL->Head=pL->Head->PNext;
		pL->destroyElem(pE->pElem);
		free(pE);
	}
	free(pL);
}


/*

  Function: ListAdd

  Abstract:

	Add's an element to the list. Creates a Node with the element as a KEY and links it to the list

  Parameters:

	pL -  A pointer from type struct List to the list itself
	pE - A pointer to a generic element

  Returns: Result - FAIL if the add failed or SUCCESS if it succeded

*/
Result ListAdd(PList pL, PElem pE) {///need to add clone function
	if (!pL || !pE) return FAIL;
	PNode pN=pL->Head;
	PNode pnewN = createNode(pE, pL->cloneElem);
	if (!pnewN) return FAIL;
	/*adding first node - initialize Iterator to the first node*/
	if (!pN) {
		pL->Head = pnewN;
		pL->Iter = pL->Head;
		return SUCCESS;
	}
	while (pN->PNext) pN = pN->PNext;
	pN->PNext = pnewN;
	return SUCCESS;
}


/*

  Function: ListRemove

  Abstract:

	Searches an element in the list and Removes the element from the list if found

  Parameters:

	pL -  A pointer from type struct List to the list itself
	pE - A pointer to a generic element that user wants to remove

  Returns: Result - FAIL if the remove failed or SUCCESS if it succeded

*/
Result ListRemove(PList pL, PElem pE) {
	if (!pE || !pL) return FAIL;
	PNode pCur = pL->Head;
	/*the first node is the needed one*/
	if (pL->compareElem(pCur->pElem, pE)) {
		pL->Head = pL->Head->PNext;
		pL->destroyElem(pCur->pElem);
		free(pCur);
		return SUCCESS;
	}
	/*advanced pCur until different or reaching last node*/
	while (!(pL->compareElem(pCur->PNext->pElem, pE))) {
		pCur = pCur->PNext;
		if (!pCur->PNext) break;
	}
	if (!pCur->PNext) return FAIL;
	else {
		PNode tmp = pCur->PNext;
		pCur->PNext = pCur->PNext->PNext;
		pL->destroyElem(tmp->pElem);
		
		free(tmp);
		return SUCCESS;
	}
}


/*

  Function: ListGetFirst

  Abstract:

	Set the Iterator pointer, a generic Pointer in the Struct List type,  to points on the first element in the list

  Parameters:

	pL -  A pointer from type struct List to the list itself

  Returns: Result - : A pointer to a generic element - the element that the iterator points on - the first element in the list

*/
PElem ListGetFirst(PList pL) {
	if (!pL || !pL->Head) return NULL;
	pL->Iter = pL->Head;
	return pL->Iter->pElem;
}


/*

  Function: ListGetNext

  Abstract:

	Set the Iterator pointer, a generic Pointer in the Struct List type,  to points on the next element in the list from the element he point now

  Parameters:

	pL -  A pointer from type struct List to the list itself

  Returns: Result - : A pointer to a generic element - the element that the iterator points on

*/
PElem ListGetNext(PList pL) {
	if (!pL) return NULL;
	if (!pL->Iter) return NULL;
	pL->Iter = pL->Iter->PNext;
	if (!pL->Iter) return NULL;
	return pL->Iter->pElem;
}


/*

  Function: ListCompare

  Abstract:

	Compare between 2 lists 

  Parameters:

	pL1 -  A pointer from type struct List to the list itself
	pL2 -  A pointer from type struct List to the list itself

  Returns: TRUE if the lists are equal or FALSE otherwise

*/
BOOL ListCompare(PList pL1, PList pL2) {
	PNode pCur1 = pL1->Head;
	PNode pCur2 = pL2->Head;
	/*both lists are empty*/
	if (!pCur1 && !pCur2) return TRUE;
	/*one list is empty*/
	if ((!pCur1 && pCur2)||(pCur1 && !pCur2)) return FALSE;

	/* iterate comparison on lists elemnts, stops when the elemnts are different or when the lists are finished*/
	while (pL1->compareElem(pCur1->pElem, pCur2->pElem)) {
		pCur1 = pCur1->PNext;
		pCur2 = pCur2->PNext;
		if (!pCur1 || !pCur2) break;
	}
	if (!pCur1 && !pCur2) return TRUE;
	return FALSE;
}


/*

  Function: ListPrint

  Abstract:

	Prints the List according to a designated pattern

  Parameters:

	pL -  A pointer from type struct List to the list itself

  Returns: --

*/
void ListPrint(PList pL) {
	PNode pCur = pL->Head;
	printf("[");
	while (pCur){
		pL->printElem(pCur->pElem);
		pCur = pCur->PNext;
	}
	printf("]\n");
}



/*helper functions*/

/*

  Function: createNode

  Abstract:

	Creates a new "struct node" type , and clones the element entered by user to be the KEY of the node. later linkes the node to the list

  Parameters:

	pE - A generic element that will be cloned and set as the node KEY
	cloneElem - A user function that clones an elemnt from designated type

  Returns: A pointer to the Node created

*/
PNode createNode(PElem pE, CLONE_ELEM cloneElem) {
	PNode pN;
	pN = (PNode)malloc(sizeof(struct NODE_));
	if (!pN) return NULL;
	// saving the external elem in the node.
	pN->pElem = cloneElem(pE);
	pN->PNext = NULL;
	return pN;
}