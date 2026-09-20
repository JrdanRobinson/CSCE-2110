#include <iostream>
#include "Resource.h"
#include "WaitingList.h"
using namespace std;


int main(){

    // ===== Resource Testing =====

    // Load resources from the text file
    vector<Resource> resources = loadResources("data/resources.txt");

    // Display all resources
    cout << "All Resources:" << endl;
    displayAllResources(resources);

    // Display availability count for each resource type
    cout << endl;
    cout << "Availability by Resource Type:" << endl;
    showAvailabilityCount(resources);


    // ===== Waiting List Testing =====

    cout << endl;
    cout << "===== Testing Waiting List =====" << endl;

    waitingList wl;

    // Two students both waiting for a "Laptop" (any laptop, not a specific one)
    waitRequest student1("Alice", "1001", "alice@unt.edu", "Laptop");
    waitRequest student2("Bob", "1002", "bob@unt.edu", "Laptop");

    wl.addToWaitingList(student1);
    wl.addToWaitingList(student2);

    // Show the current waiting list for Laptop
    wl.displayWaitingList("Laptop");

    // Remove the next person in line (should be Alice, since she was added first)
    waitRequest nextPerson("", "", "", "");
    bool success = wl.removeNext("Laptop", nextPerson);

    if (success) {
        cout << nextPerson.getName() << " has been given a Laptop!" << endl;
    }

    // Show the waiting list again (should now only show Bob)
    wl.displayWaitingList("Laptop");

    // Test an empty waiting list (no one has requested a Calculator)
    wl.displayWaitingList("Calculator");

    // Test removeNext on an empty list (should print an error message and return false)
    waitRequest emptyTest("", "", "", "");
    bool emptyResult = wl.removeNext("Calculator", emptyTest);
    if (!emptyResult) {
        cout << "As expected, there was no one to remove from Calculator's list." << endl;
    }

    return 0;
}