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

    // 1. find out which Type this person is waiting for
    string resourceType = request.getResourceType();

    // 2. add this person to the end of that type's line (queue)
    allLists[resourceType].push(request);
}

bool waitingList::isEmpty(string resourceType) {

    // Step 1 : check if this resourceId has never had a waiting line before
    if (allLists.count(resourceType) == 0) {
        return true;   
    }

    // 2. check if the line exists but currently has no one in it
    if (allLists[resourceType].empty() == true) {
        return true;   
    }

    // 3. if neither case above is true, the line has people in it
    return false;  
}

bool waitingList::removeNext(string resourceType, waitRequest& outRequest) {

    // 1. check if the line is empty first
    bool empty = isEmpty(resourceType);

    if (empty == true) {
        cout << "No one is waiting for " << resourceType << endl;
        return false;   // 
    }

    // 2. line is not empty, so get the person at the front;
    waitRequest frontPerson = allLists[resourceType].front();

    // 3. save that person's info into outRequest so ti can be used outside this funtion
    outRequest = frontPerson;

    // 4. remove that perosn from the line (they are no longer waiting)
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
    queue<waitRequest> copyOfQueue = allLists[resourceType];

    cout << "Waiting list for " << resourceType << ":" << endl;

    // number is keep track of the person's poistion in line
    int number = 1;

    // 4. keep going until the copy of the line is empty
    while (copyOfQueue.empty() == false) {

        // look at the person at the front of the copy
        waitRequest person = copyOfQueue.front();

        // print info
        cout << number << ") " << person.getName() << " - Student ID: " << person.getId() << endl;

        // remove them from the copy ( so we can see the next person)
        copyOfQueue.pop();

        // Move to the next number
        number = number + 1;
    }
}