/*

  File: student.c

  Abstract:

	A student ADT handling implementation, database for students details

*/

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structs*/
struct Student_{
	char* name;
	int age, ID;
	char* faculty;
};


/*interface functions*/

/*

  Function: StudentCreate

  Abstract:

	Creates a new student ADT with his name, age, ID and faculty

  Parameters:

	name - new studet's name
	age - new student's age
	ID - new student's ID
	faculty - new student's faculty

  Returns: A pointer of student type to the student created. If the student's creation fails , return NULL.

*/
PStudent StudentCreate(char* name, int age, int ID, char* faculty) {
	/*one of inputs is NULL*/
	if (!(name && age >= 0 && ID && faculty)) return NULL;
	PStudent pNewStudent;
	pNewStudent = (PStudent)malloc(sizeof(Student));
	if (!pNewStudent) return NULL;
	
	/*dynamic allocation for inner fields of newStudent*/
	
	/*allocating the sting length + 1 for "/n" in the end of the new string*/
	int nameLen = strlen(name) + 1;
	int facultyLen = strlen(faculty) + 1;
	pNewStudent->name = (char*)malloc((nameLen) * sizeof(char));
	if (!(pNewStudent->name)) return NULL;
	pNewStudent->faculty = (char*)malloc((facultyLen) * sizeof(char));
	if (!(pNewStudent->faculty)) return NULL;

	/*initialization*/
	strcpy(pNewStudent->name, name);
	pNewStudent->age = age;
	pNewStudent->ID = ID;
	strcpy(pNewStudent->faculty, faculty);

	return pNewStudent;
}

/*

  Function: cloneStudent

  Abstract:

	Clones a student

  Parameters:

	pS - A pointer to generic element that will be casted to student type

  Returns: A pointer to generic element which is the cloned student

*/
PElem cloneStudent(PElem pS) {
	if (!pS) return NULL;
	PStudent newS = (PStudent)pS;
	/*using StudentCreate in order to clone given student*/
	newS = (PElem)StudentCreate(newS->name, newS->age, newS->ID, newS->faculty);
	return newS;
}

/*

  Function: destroyStudent

  Abstract:

	Destroys a student - Frees all the memory allocated to the student ADT

  Parameters:

	pS - A pointer to generic element that will be casted to student type - The student the user wants to remove

  Returns: --

*/
void destroyStudent(PElem pS) {
	if (!pS) return;
	PStudent curS = (PStudent)pS;
	free(curS->name);
	free(curS->faculty);
	free(curS);
}

/*

  Function: compareStudents

  Abstract:

	Compares between 2 students using their unique ID

  Parameters:

	pS1 - A pointer to generic element that will be casted to student type
	pS2 - A pointer to generic element that will be casted to student type

  Returns: TRUE if the students has the same ID or FALSE otherwise

*/
BOOL compareStudents(PElem pS1, PElem pS2) {
	if (!pS1 && !pS2) return TRUE;
	if ((!pS1 && pS2) || (pS1 && !pS2)) return FALSE;
	PStudent curS1 = (PStudent)pS1;
	PStudent curS2 = (PStudent)pS2;
	if (curS1->ID == curS2->ID) return TRUE;
	else return FALSE;
}

/*

  Function: printStudent

  Abstract:

	Prints all the details of a given student

  Parameters:

	pS - A pointer to generic element that will be casted to student type

  Returns: --

*/
void printStudent(PElem pS) {
	if (!pS) return;
	PStudent curS = (PStudent)pS;
	printf("Name: %s, Age: %d, ID: %d, Faculty: %s\n", curS->name, curS->age, curS->ID, curS->faculty);
}