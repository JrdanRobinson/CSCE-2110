#include "WaitingList.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

waitRequest::waitRequest(string name, string studentId, string studentEmail, string resId){
    waitRequestName = name; 
    waitRequestStudentId = studentId;
    waitRequestEmail = studentEmail;
    resourceId = resId;
}

//getter function (just return the stored values)
string waitRequest::getName(){return waitRequestName;}
string waitRequest::getId(){return waitRequestStudentId;}
string waitRequest::getEmail(){return waitRequestEmail;}
string waitRequest::getResourceId(){return resourceId;}

void waitingList::addToWaitingList(waitRequest request) {

    // find out which resource this person is waiting for
    string resourceId = request.getResourceId();

    // add this person to the end of that resource's line (queue)
    allLists[resourceId].push(request);
}

bool waitingList::isEmpty(string resourceId) {

    if (allLists.count(resourceId) == 0) {
        return true;   
    }

    if (allLists[resourceId].empty() == true) {
        return true;   
    }
    return false;  
}

bool waitingList::removeNext(string resourceId, waitRequest& outRequest) {

    bool empty = isEmpty(resourceId);

    if (empty == true) {
        cout << "No one is waiting for " << resourceId << endl;
        return false;
    }
    waitRequest frontPerson = allLists[resourceId].front();
    outRequest = frontPerson;
    allLists[resourceId].pop();

    return true;
}

void waitingList::displayWaitingList(string resourceId) {
    if(isEmpty(resourceId)) {
        cout<<"Waiting list for " << resourceId << ":"<< endl;
        cout<<"No one is waiting. " <<endl;
        return;
    }

    // Make a copy of the line so we don't destroy the real one while printing
    queue<waitRequest> copyQueue = allLists[resourceId];

    cout << "Waiting list for " << resourceId << ":" << endl;

    // number keeps track of the person's position in line
    int number = 1;

    // keep going until the copy of the line is empty
    while (copyQueue.empty() == false) {

        waitRequest person = copyQueue.front();

        cout << number << ") " << person.getName() << " - Student ID: " << person.getId() << endl;

        copyQueue.pop();

        number = number + 1;
    }
}

// return how many students are waiting for this resource
int waitingList::getCount(string resourceId) {
    if (allLists.count(resourceId) == 0) {
        return 0;
    }
    return allLists[resourceId].size();
}