#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Resource {
    private:
    string resourceID; // 변수(어떤 정보를 담는지)
    string resourceName;
    string resourceType;
    bool isAvailable;


public:
    Resource(string id, string name, string type, bool avail); // 함수 ( 뭘 할 수 있는지)
    string getID();
    string getName();
    string getType();
    bool isItAvailable();
    void setAvailable(bool status);
    void display();
};  

vector<Resource> loadResources(string filename);
void displayAllResources(vector<Resource>& resourceList);
void showAvailabilityCount(vector<Resource>& resourceList);
