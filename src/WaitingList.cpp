#include "WaitingList.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

waitRequest::waitRequest(string name, string studentId, string studentEmail, string resType){
    waitRequestName = name; 
    waitRequestStudentId = studentId;
    waitRequestEmail = studentEmail;
    resourceType = resType;
}

//getter function (just return the stored values)
string waitRequest::getName(){return waitRequestName;}
string waitRequest::getId(){return waitRequestStudentId;}
string waitRequest::getEmail(){return waitRequestEmail;}
string waitRequest::getResourceType(){return resourceType;}

void waitingList::addToWaitingList(waitRequest request) {

    // find out which Type this person is waiting for
    string resourceType = request.getResourceType();

    //add this person to the end of that type's line (queue)
    allLists[resourceType].push(request);
}

bool waitingList::isEmpty(string resourceType) {

    if (allLists.count(resourceType) == 0) {
        return true;   
    }

    if (allLists[resourceType].empty() == true) {
        return true;   
    }
    return false;  
}

bool waitingList::removeNext(string resourceType, waitRequest& outRequest) {

    bool empty = isEmpty(resourceType);

    if (empty == true) {
        cout << "No one is waiting for " << resourceType << endl;
        return false;   // 
    }
    waitRequest frontPerson = allLists[resourceType].front();
    outRequest = frontPerson;
    allLists[resourceType].pop();

    return true;
}

void waitingList::displayWaitingList(string resourceType) {
    if(isEmpty(resourceType)) {
        cout<<"Waiting list for " << resourceType << ":"<< endl;
        cout<<"No one is waiting. " <<endl;
        return;
    }

    // Make a copy of the line so we don't destroy the real one while printing
    queue<waitRequest> copyQueue = allLists[resourceType];

    cout << "Waiting list for " << resourceType << ":" << endl;

    // number is keep track of the person's poistion in line
    int number = 1;

    //keep going until the copy of the line is empty
    while (copyQueue.empty() == false) {

       
        waitRequest person = copyQueue.front();

        cout << number << ") " << person.getName() << " - Student ID: " << person.getId() << endl;

        copyQueue.pop();

 
        number = number + 1;
    }
}