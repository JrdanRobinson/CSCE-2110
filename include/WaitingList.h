#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;


// this class stores the information for one person is waiting
class waitRequest { 
    private:
    string waitRequestName;  //student's name
    string waitRequestStudentId; //student's ID number
    string waitRequestEmail; //student's email
    string resourceId;  // which resource( by Id) they are waiting for 
 

   public: 
    waitRequest(string name, string studentId, string studentEmail, string resId);
    string getName();
    string getId();
    string getEmail();
    string getResourceId();
};

// manages all the waiting lines, one line per resource
class waitingList {
    private:
    // each resourceId maps to its own line(queue)
    map<string, queue<waitRequest>> allLists; // 

    public:
        void addToWaitingList(waitRequest request);  // add a person to the correct line
        bool removeNext(string resourceId, waitRequest& outRequest); // remove the next person in line
        void displayWaitingList(string resourceId); //show everyone waiting
        bool isEmpty(string resourceId); // check if a line has no one waiting
        int getCount(string resourceId); //  how many student or people are waiting for this resource

};

#endif