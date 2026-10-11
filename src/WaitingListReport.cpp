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