#ifndef WAITINGLISTREPORT_H
#define WAITINGLISTREPORT_H

#include <vector>
#include "Resource.h"
#include "WaitingList.h"
#include "ReservationManager.h"
using namespace std;

//waiting list for each resource
void printWaitingStats(vector<Resource>& resources, waitingList& waitList);
// Prints every resource 
void printUtilization(vector<Resource>& resources, ReservationManager& manager);
void printMostRequested(vector<Resource>& resources);
#endif

