/*

  File: pont.h

  Abstract:

    A Point ADT handling interface

*/


#ifndef _POINT_H_
#define _POINT_H_

#include "defs.h"
#include "list.h"

/*The ADT*/
typedef struct Point_* PPoint;


/*Interface functions*/

//**************************************************************************************************************************************
//* Function name: PointCreate
//* Function description: Creates a new Point ADT 
//* Parameters: An integer that will be the point's dimension
//* Return value: A pointer from type point to the to the created point
//**************************************************************************************************************************************
PPoint PointCreate(int);

//**************************************************************************************************************************************
//* Function name: PointDestroy
//* Function description: Frees all the memory allocated to the point ADT
//* Parameters: An pointer to generic elemnt that will be casted to type point
//* Return value: None
//**************************************************************************************************************************************
void PointDestroy(PElem);

//**************************************************************************************************************************************
//* Function name: PointAddCoordinate
//* Function description: Add's a coordinate to a selected point
//* Parameters: An pointer to a point and an integer (coordinate)
//* Return value: Result - FAIL if the add failed or SUCCESS if it succeded
//**************************************************************************************************************************************
Result PointAddCoordinate(PPoint, int);

//**************************************************************************************************************************************
//* Function name: PointGetFirstCoordinate
//* Function description: Fetch the first coordinate in a selected point
//* Parameters: An pointer to a point
//* Return value: The first coordinate that entered to a point
//**************************************************************************************************************************************
int PointGetFirstCoordinate(PPoint);

//**************************************************************************************************************************************
//* Function name: PointGetNextCoordinate
//* Function description: Fetch the next coordinate in a selected point
//* Parameters: An pointer to a point
//* Return value: A coordinate in a point
//**************************************************************************************************************************************
int PointGetNextCoordinate(PPoint);

//**************************************************************************************************************************************
//* Function name: PointPrint
//* Function description: Prints the point coordinetions , size and dimension
//* Parameters: An pointer to a generic elemnt that will be casted to type point 
//* Return value: A coordinate in a point
//**************************************************************************************************************************************
void PointPrint(PElem);

//**************************************************************************************************************************************
//* Function name: PointGetDimension
//* Function description: Returns the Point dimension
//* Parameters: A pointer to a point
//* Return value: Integer - the point dimension
//**************************************************************************************************************************************
int PointGetDimension(PPoint);

//**************************************************************************************************************************************
//* Function name: PointClone
//* Function description: Clones a point
//* Parameters: A pointer to a generic elemnt that will be casted to type point 
//* Return value: A pointer to a generic elemnt that will be casted to type point 
//**************************************************************************************************************************************
PElem PointClone(PElem);

//**************************************************************************************************************************************
//* Function name: PointsCompare
//* Function description: Compares between 2 points
//* Parameters: 2 pointers to a generic elemnt that will be casted to type point
//* Return value: TRUE if the points are equal or FALSE otherwise
//**************************************************************************************************************************************
BOOL PointsCompare(PElem, PElem);

#endif
