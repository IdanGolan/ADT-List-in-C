#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "defs.h"
#include "list.h"

/*The ADT*/
typedef struct Student_ Student, *PStudent;

/*Interface functions*/

//**************************************************************************************************************************************
//* Function name: StudentCreate
//* Function description: Creates a new student ADT with his name, age, ID and faculty
//* Parameters: 	name - new studet's name
//*					age - new student's age
//*					ID - new student's ID
//*					faculty - new student's faculty
//* Return value: A pointer of student type to the student created. If the student's creation fails , return NULL.
//**************************************************************************************************************************************
PStudent StudentCreate(char*, int, int, char*);

/*ADT interface functions*/

//**************************************************************************************************************************************
//* Function name: cloneStudent
//* Function description: Clones a student
//* Parameters: pS - A pointer to generic element that will be casted to student type
//* Return value: A pointer to generic element which is the cloned student
//**************************************************************************************************************************************
PElem cloneStudent(PElem);

//**************************************************************************************************************************************
//* Function name: destroyStudent
//* Function description: Destroys a student - Frees all the memory allocated to the student ADT
//* Parameters: pS - A pointer to generic element that will be casted to student type - The student the user wants to remove
//* Return value: None
//**************************************************************************************************************************************
void destroyStudent(PElem);

//**************************************************************************************************************************************
//* Function name: compareStudents
//* Function description: Compares between 2 students using their unique ID
//* Parameters: pS1 - A pointer to generic element that will be casted to student type
//*				pS2 - A pointer to generic element that will be casted to student type
//* Return value: TRUE if the students has the same ID or FALSE otherwise
//**************************************************************************************************************************************
BOOL compareStudents(PElem, PElem);


//**************************************************************************************************************************************
//* Function name: printStudent
//* Function description: Prints all the details of a given student
//* Parameters: pS - A pointer to generic element that will be casted to student type
//* Return value: None
//**************************************************************************************************************************************
void printStudent(PElem);

#endif
