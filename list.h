/*

  File: list.h

  Abstract:

    Generic Linked-List ADT handling interface

*/

#ifndef _LIST_H_
#define _LIST_H_
#include "defs.h"

/*The ADT*/
typedef struct List_* PList;
typedef struct NODE_* PNode;
typedef void* PElem;



/*Function types*/
typedef void* (*CLONE_ELEM)(PElem);
typedef void (*DESTROY_ELEM)(PElem);
typedef BOOL(*COMPARE_ELEM)(PElem, PElem);
typedef void(*PRINT_ELEM)(PElem);


/*Interface functions*/

//**************************************************************************************************************************************
//* Function name: ListCreate
//* Function description: Creates a new generic linked list ADT that supports numerous functions
//* Parameters: 4 Functions uniqe to the list type in order to use them in the list's actions (clone ,destroy, compare, print)
//* Return value: A pointer from type struct List to the list itself
//**************************************************************************************************************************************
PList ListCreate(CLONE_ELEM, DESTROY_ELEM, COMPARE_ELEM, PRINT_ELEM);

//**************************************************************************************************************************************
//* Function name: ListDestroy
//* Function description: Frees a list and all the allocated memory used in the list 
//* Parameters: A pointer from type List
//* Return value: None
//**************************************************************************************************************************************
void ListDestroy(PList);

//**************************************************************************************************************************************
//* Function name: ListAdd
//* Function description: Add's an element to the list. Creates a Node with the element as a KEY and links it to the list
//* Parameters: A pointer to a List and a pointer to a generic element
//* Return value: Result - FAIL if the add failed or SUCCESS if it succeded
//**************************************************************************************************************************************
Result ListAdd(PList, PElem);

//**************************************************************************************************************************************
//* Function name: ListRemove
//* Function description: Removes an element from the list
//* Parameters: A pointer to a List and a pointer to a generic element
//* Return value: Result - FAIL if the remove failed or SUCCESS if it succeded
//**************************************************************************************************************************************
Result ListRemove(PList, PElem);

//**************************************************************************************************************************************
//* Function name: ListGetFirst
//* Function description: Set the Iterator pointer of the list to the first element in the list
//* Parameters:  A pointer to a List
//* Return value: A pointer to a generic element - the element that the iterator points on - the first element in the list
//**************************************************************************************************************************************
PElem ListGetFirst(PList);

//**************************************************************************************************************************************
//* Function name: ListGetNext
//* Function description: Set the Iterator pointer of the list to the next element in the list
//* Parameters:  A pointer to a List
//* Return value:  A pointer to a generic element - the element that the iterator points on
//**************************************************************************************************************************************
PElem ListGetNext(PList);

//**************************************************************************************************************************************
//* Function name: ListCompare
//* Function description: Compare between 2 lists 
//* Parameters: 2 Pointers to List
//* Return value: TRUE if the lists are equal or FALSE otherwise
//**************************************************************************************************************************************
BOOL ListCompare(PList, PList);

//**************************************************************************************************************************************
//* Function name: ListPrint
//* Function description: Prints the List
//* Parameters: A pointer to a List
//* Return value: None
//**************************************************************************************************************************************
void ListPrint(PList);

#endif
