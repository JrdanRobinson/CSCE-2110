#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Resource {
private:
    string resourceID;
    string resourceName;
    string resourceType;
    bool isAvailable;
    int requestCount;

public:
    // Constructor
    Resource(string id, string name, string type, bool avail);

    // Getters
    string getID();
    string getName();
    string getType();
    bool isItAvailable();

    // Request tracking
    void incrementRequestCount();
    int getRequestCount();

    // Update availability
    void setAvailable(bool status);

    // Display resource information
    void display();
};

// Load resources from a file
vector<Resource> loadResources(string filename);

// Display all resources
void displayAllResources(vector<Resource>& resourceList);

// Display available resource counts
void showAvailabilityCount(vector<Resource>& resourceList);

// Linear Search
int linearSearchResource(vector<Resource>& resourceList, string resourceID);

// Merge Sort
void mergeSortResources(vector<Resource>& resourceList, int left, int right);

#endif
