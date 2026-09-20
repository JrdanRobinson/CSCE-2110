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


public:
    Resource(string id, string name, string type, bool avail); // Constructor: creates a new Resource
    string getID();
    string getName();
    string getType();
    bool isItAvailable();
    void setAvailable(bool status);
    void display();
};  

vector<Resource> loadResources(string filename); //Reads resource.txt and builds a list
void displayAllResources(vector<Resource>& resourceList); //prints every resource in the list
void showAvailabilityCount(vector<Resource>& resourceList); //prints how many of each type are avail

#endif