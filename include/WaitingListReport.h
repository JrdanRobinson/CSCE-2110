#ifndef WAITINGLISTREPORT_H
#define WAITINGLISTREPORT_H

#include <vector>
#include "Resource.h"
#include "WaitingList.h"
using namespace std;

//waiting list for each resource
void printWaitingStats(vector<Resource>& resources, waitingList& waitList);

#endif