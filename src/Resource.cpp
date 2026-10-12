#include "Resource.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
Resource::Resource(string id, string name, string type, bool avail) {
    resourceID = id;
    resourceName = name;
    resourceType = type;
    isAvailable = avail;
}

// Getter functions
string Resource::getID() { return resourceID; }
string Resource::getName() { return resourceName; }
string Resource::getType() { return resourceType; }
bool Resource::isItAvailable() { return isAvailable; }

// Update availability status
void Resource::setAvailable(bool status) {
    isAvailable = status;
}

// Load resources from a text file
vector<Resource> loadResources(string filename) {
    vector<Resource> resourceList;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return resourceList;
    }

    string line;

    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back(); // Remove a hidden space (Final revised)
        if (line.empty()) continue; // skip blank lines(Final revised)
        stringstream newLine(line);
        string id, name, type, available;

        getline(newLine, id, ',');
        getline(newLine, name, ',');
        getline(newLine, type, ',');
        getline(newLine, available, ',');

        bool avail = (available == "1");

        Resource newFile(id, name, type, avail);
        resourceList.push_back(newFile);
    }

    file.close();
    return resourceList;
}

// Display one resource
void Resource::display() {
    cout << resourceID << " | "
         << resourceName << " | "
         << resourceType << " | "
         << (isAvailable ? "Available" : "In Use")
         << endl;
}

// Display all resources
void displayAllResources(vector<Resource>& resourceList) {
    for (int i = 0; i < resourceList.size(); i++) {
        resourceList[i].display();
    }
}

// Count available resources by type
void showAvailabilityCount(vector<Resource>& resourceList) {
    int laptopCount = 0;
    int calculatorCount = 0;
    int mouseCount = 0;
    int studyRoomCount = 0;

    for (int i = 0; i < resourceList.size(); i++) {
        string type = resourceList[i].getType();
        bool avail = resourceList[i].isItAvailable();

        if (avail) {
            if (type == "Laptop") {
                laptopCount++;
            }
            else if (type == "Calculator") {
                calculatorCount++;
            }
            else if (type == "Mouse") {
                mouseCount++;
            }
            else if (type == "StudyRoom") {
                studyRoomCount++;
            }
        }
    }

    cout << "Laptop    : " << laptopCount << " available" << endl;
    cout << "Calculator: " << calculatorCount << " available" << endl;
    cout << "Mouse     : " << mouseCount << " available" << endl;
    cout << "StudyRoom : " << studyRoomCount << " available" << endl;
}

// ===== LINEAR SEARCH =====

// Search for a resource by its ID
// Returns the index if found, otherwise -1
int linearSearchResource(vector<Resource>& resourceList, string resourceID) {

    for (int i = 0; i < resourceList.size(); i++) {

        if (resourceList[i].getID() == resourceID) {
            return i;
        }
    }

    return -1;
}

// ===== MERGE SORT =====

// Merge two sorted halves of the resource list
void mergeResources(vector<Resource>& resourceList,
                    int left, int middle, int right) {

    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    vector<Resource> leftHalf;
    vector<Resource> rightHalf;

    // Copy resources into the left half
    for (int i = 0; i < leftSize; i++) {
        leftHalf.push_back(resourceList[left + i]);
    }

    // Copy resources into the right half
    for (int j = 0; j < rightSize; j++) {
        rightHalf.push_back(resourceList[middle + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Compare resource names and merge alphabetically
    while (i < leftSize && j < rightSize) {

        if (leftHalf[i].getName() <= rightHalf[j].getName()) {
            resourceList[k] = leftHalf[i];
            i++;
        }
        else {
            resourceList[k] = rightHalf[j];
            j++;
        }

        k++;
    }

    // Copy any remaining resources from the left half
    while (i < leftSize) {
        resourceList[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copy any remaining resources from the right half
    while (j < rightSize) {
        resourceList[k] = rightHalf[j];
        j++;
        k++;
    }
}

// Recursively divide and sort resources by name
void mergeSortResources(vector<Resource>& resourceList,
                        int left, int right) {

    // Stop when there is only one resource or none
    if (left >= right) {
        return;
    }

    // Find the middle position
    int middle = left + (right - left) / 2;

    // Sort the left half
    mergeSortResources(resourceList, left, middle);

    // Sort the right half
    mergeSortResources(resourceList, middle + 1, right);

    // Merge the two sorted halves
    mergeResources(resourceList, left, middle, right);
}
