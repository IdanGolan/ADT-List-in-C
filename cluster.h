/*

  File: cluster.h

  Abstract:

    Generic cluster ADT handaling interface

*/

#ifndef _CLUSTER_H_
#define _CLUSTER_H_
#include "defs.h"
#include "point.h"

/*The ADT*/
typedef struct Cluster_* PCluster;

/*Interface functions*/


//**************************************************************************************************************************************
//* Function name: ClusterCreate
//* Function description: Creates a new Cluster ADT with designated dimension
//* Parameters: dim - The wanted Point's dimension in the Cluster.
//* Return value:  A cluster pointer type to the new ADT created. If the point creation fails , return NULL.
//**************************************************************************************************************************************
PCluster ClusterCreate(int);

//**************************************************************************************************************************************
//* Function name: Clusterdestroy
//* Function description: Destroys a cluster - Frees all the memory allocated to the cluster ADT
//* Parameters: pC - A pointer to cluster element that will be destroyed.
//* Return value: None
//**************************************************************************************************************************************
void ClusterDestroy(PCluster);

//**************************************************************************************************************************************
//* Function name: ClusterAddPoint
//* Function description: Adds a point with same dimenson to a selected cluster, after checking that the point new to the cluster
//* Parameters: pC - The cluster which the user wants to add his point to
//*             pP - A pointer to type point - The point the user wants to add to the cluster
//* Return value: Result - FAIL if the add failed or SUCCESS if it succeded
//**************************************************************************************************************************************
Result ClusterAddPoint(PCluster, PPoint);

//**************************************************************************************************************************************
//* Function name: ClusterGetMinDistance
//* Function description: Computes the minimum square distance between given point to the closest point to it from the cluster
//* Parameters: pP - A pointer to type point - The point which needed to be checked
//*             pC - A pointer to the Cluster which we want the minimum squre distance fron the given point to it
//* Return value: A pointer from type struct List to the list itself
//**************************************************************************************************************************************
int ClusterGetMinDistance(PCluster, PPoint);

//**************************************************************************************************************************************
//* Function name: ClusterPrint
//* Function description: Prints the cluster points , each point with the it's coordinates, size and dimension
//* Parameters: pC - A pointer to the wanted cluster to be printed
//* Return value: None
//**************************************************************************************************************************************
void ClusterPrint(PCluster);

#endif
