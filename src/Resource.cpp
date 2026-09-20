#include "Resource.h" // Include the class declaration
#include <sstream>    // For splitting strings by comma
#include <fstream>    // For opening files
#include <iostream>   // For console output
#include <string>
#include <vector>
using namespace std;

// Constructor (takes values given to it and save them into this object)
Resource::Resource(string id, string name, string type, bool avail){
    resourceID = id;
    resourceName = name;
    resourceType = type;
    isAvailable = avail;
}

// Getter functions (just return the value)
string Resource::getID() { return resourceID; }
string Resource::getName() { return resourceName; }
string Resource::getType() { return resourceType; }
bool Resource::isItAvailable() { return isAvailable; }


// Update availability status
void Resource::setAvailable(bool status){
    isAvailable = status;
}

// Load resources from a text file into a list
vector<Resource> loadResources(string filename){
    vector<Resource> resourceList;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return resourceList;
    }

    string line;
    while (getline(file, line)) {
        stringstream newLine(line);
        string id, name, type, available;

        getline(newLine, id, ',');
        getline(newLine, name, ',');
        getline(newLine, type, ',');
        getline(newLine, available, ',');

        bool avail = (available == "1"); // "1" means available

        Resource newFile(id, name, type, avail);
        resourceList.push_back(newFile);
    }
    file.close();
    return resourceList;
}

// this function prints one resource's information to the screen.
void Resource::display() {
    cout << resourceID << " | " << resourceName << " | " << resourceType
         << " | " << (isAvailable ? "Available" : "In Use") << endl;
}

// Prints every resource
void displayAllResources(vector<Resource>& resourceList){
    for (int i = 0; i < resourceList.size(); i++){
        resourceList[i].display();
    }
}

// counts how many of each resource type are currently available, and prints.
void showAvailabilityCount(vector<Resource>& resourceList){
    int laptopCount = 0;
    int calculatorCount = 0;
    int mouseCount = 0;
    int studyRoomCount = 0;

    for (int i = 0; i < resourceList.size(); i++){
        string type = resourceList[i].getType();
        bool avail = resourceList[i].isItAvailable();

        if (avail) {
            if (type == "Laptop"){
                laptopCount++;
            } else if (type == "Calculator") {
                calculatorCount++;
            } else if (type == "Mouse") {
                mouseCount++;
            } else if (type == "StudyRoom") {
                studyRoomCount++;
            }
        }
    }

    cout << "Laptop    : " << laptopCount << " available" << endl;
    cout << "Calculator: " << calculatorCount << " available" << endl;
    cout << "Mouse     : " << mouseCount << " available" << endl;
    cout << "StudyRoom : " << studyRoomCount << " available" << endl;
}