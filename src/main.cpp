#include <iostream>
#include "Resource.h"
using namespace std;


int main(){
    
    // Load resources from the text file
    vector<Resource> resources = loadResources("data/resources.txt");

    // display all resources
    cout <<"All resources:" <<endl;
    displayAllResources(resources);

    // display availability count for each resource type
    cout <<endl;
    cout <<"Availability by Resource Type: " <<endl;
    showAvailabilityCount(resources);

    return 0;

}