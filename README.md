# CSCE-2110
data/resource.txt form:
id,name,type,available(1(true) or 0(false))
ex) LAP01, Dell Laptop, Laptop, 1

# Campus Resource Reservation System

## My Part: Resource Management & Waiting List

### Files
- include/Resource.h
- src/Resource.cpp
- include/WaitingList.h
- src/WaitingList.cpp
- data/resources.txt
- src/main.cpp (this is the text version of main files)

### How to Compile
g++ -std=c++17 src/main.cpp src/Resource.cpp src/WaitingList.cpp -Iinclude -o program

### How to Run
./program

### Resource File Format
ID,Name,Type,Availability(1=available/0=in use)
Example: LAP01,Dell Laptop,Laptop,1