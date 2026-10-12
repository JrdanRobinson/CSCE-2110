#include "WaitingListReport.h"
#include <iostream>
using namespace std;

void printWaitingStats(vector<Resource>& resources, waitingList& waitList) {
    

    cout << "Resource ID | Name | Students waiitng" << endl; // print the title

    for (int i =0 ; i < resources.size(); i++){

        // get id, name, and type from resources
        string id = resources[i].getID();
        string name = resources[i].getName();
        
        // each resource has its own waiting line, so ask by Id
        int count = waitList.getCount(id);

        cout << id << " | "<< name << " | " << count <<endl;
    }
}

void printUtilization(vector<Resource>& resources, ReservationManager& manager) {

    string lastType = "";   // the type we printed last

    for (int i = 0; i < resources.size(); i++) {

        string id = resources[i].getID();
        string name = resources[i].getName();
        string type = resources[i].getType();

        // when the type changes, print a new title
        if (type != lastType) {
            cout << "\n[" << type << "]" << endl;
            lastType = type;
        }

        // count how many reservations this resource has
        int count = manager.countReservationsFor(id);

        cout << id << " | " << name << " | " << count << " reservation(s)" << endl;
    }
}