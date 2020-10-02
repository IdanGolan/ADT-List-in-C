/*

  File: cluster.c

  Abstract:

	A Cluster ADT handling implementation, database for points

*/

#include "point.h"
#include "list.h"
#include "cluster.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMUMDISTANCE 10000

/*structs*/
struct Cluster_ {
	PList pointL;
	int dim;
	int MinSqDistance;
};


/*interface functions*/

/*

  Function: ClusterCreate

  Abstract:

	Creates a new Cluster ADT with designated dimension

  Parameters:

	dim - The wanted Point's dimension in the Cluster.

  Returns: A cluster pointer type to the new ADT created. If the point creation fails , return NULL.

*/
PCluster ClusterCreate(int dim) {
	if (!dim) return NULL;
	PCluster newCluster;
	newCluster = (PCluster)malloc(sizeof(struct Cluster_));
	if (!newCluster) return NULL;

	/*dynamic allocation for the cluster that saves Point elements*/
	newCluster->pointL = ListCreate(PointClone, PointDestroy, PointsCompare, PointPrint);
	/*initialization*/
	newCluster->dim = dim;
	newCluster->MinSqDistance = MAXIMUMDISTANCE;
	
	return newCluster;
}

/*

  Function: ClusterDestroy

  Abstract:

	Destroys a cluster - Frees all the memory allocated to the cluster ADT

  Parameters:

	pC - A pointer to cluster element that will be destroyed.

  Returns: --

*/
void ClusterDestroy(PCluster pC) {
	if (!pC) return;
	ListDestroy(pC->pointL);
	free(pC);
}

/*

  Function: ClusterAddPoint

  Abstract:

	Adds a point with same dimenson to a selected cluster, after checking that the point new to the cluster 

  Parameters:

	pC - The cluster which the user wants to add his point to
	pP - A pointer to type point - The point the user wants to add to the cluster
	
  Returns: Result - FAIL if the add failed or SUCCESS if it succeded

*/
Result ClusterAddPoint(PCluster pC,PPoint pP) {
	if (!pP || !pC) return FAIL;
	if (pC->dim != PointGetDimension(pP)) return FAIL;
	PPoint pCur = ListGetFirst(pC->pointL);
	if (!pCur) return ListAdd(pC->pointL, pP);
	/*continues while new point different from cur point in cluster, stops if the wanted point already exists or finished all comparisons*/
	while (!(PointsCompare(pCur, pP) || !pCur)) {
		pCur = ListGetNext(pC->pointL);
	}
	/*new point isn't in the cluster*/
	if (!pCur) {
		/*
		check if the need point min sqrt distance is smaller
		if TRUE updates the field needed in the struct
		*/
		int newPSqDistance = ClusterGetMinDistance(pC, pP);
		if (newPSqDistance < pC->MinSqDistance) pC->MinSqDistance = newPSqDistance;
		return ListAdd(pC->pointL, pP);
	}
	return FAIL;
}

/*

  Function: ClusterGetMinDistance

  Abstract:

	Computes the minimum square distance between given point to the closest point to it from the cluster

  Parameters:

	pP - A pointer to type point - The point which needed to be checked
	pC - A pointer to the Cluster which we want the minimum squre distance fron the given point to it

  Returns: The minimum square distance

*/
int ClusterGetMinDistance(PCluster pC, PPoint pP) {
	int minSqDis = MAXIMUMDISTANCE;
	int mul = 0, sum = 0;
	PPoint curPoint = ListGetFirst(pC->pointL);
		
	while (curPoint) {
		/*gets first coordinate of the first point in the cluster*/
		int curPointCurCoordinate = PointGetFirstCoordinate(curPoint);
		int newPointCurCoordiante = PointGetFirstCoordinate(pP);
		int i = 0;
		/*computes and sums the squre distance of each coordinate, moves from one coordinate to other using PointGetNextCoordinate*/
		while (i < pC->dim) {
			mul = (curPointCurCoordinate - newPointCurCoordiante) * (curPointCurCoordinate - newPointCurCoordiante);
			sum += mul;
			curPointCurCoordinate = PointGetNextCoordinate(curPoint);
			newPointCurCoordiante = PointGetNextCoordinate(pP);
			i++;
		}
		
		if (sum < minSqDis) minSqDis = sum;
		/*gets the next point from cluster needed to be checked*/
		curPoint = ListGetNext(pC->pointL);
	}
	return minSqDis;
}

/*

  Function: ClusterPrint

  Abstract:

	Prints the cluster points , each point with the it's coordinates, size and dimension

  Parameters:

	pC - A pointer to the wanted cluster to be printed

  Returns: --

*/
void ClusterPrint(PCluster pC) {
	printf("Cluster's dimension: %d\n", pC->dim);
	ListPrint(pC->pointL);
	printf("Minimum Square Distance: %d\n", pC->MinSqDistance);
}



