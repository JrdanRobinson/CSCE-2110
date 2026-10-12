# Campus Resource Reservation System

## CSCE 2110

The Campus Resource Reservation System is a C++ program designed to manage campus resources and student reservations. Milestone 1 focuses on implementing the core system functionality while demonstrating the use of fundamental data structures including vectors, linked lists, queues, and stacks.

The project was developed collaboratively using GitHub feature branches, commits, and pull requests.

## Core Features

The system supports:

- Loading resource information from a file
- Storing campus resource information
- Displaying all campus resources
- Displaying current resource availability
- Creating reservations
- Cancelling reservations
- Displaying active reservations
- Validating duplicate reservation IDs
- Validating resource IDs
- Preventing reservations for unavailable resources
- Updating resource availability when reservations are created or cancelled
- Storing active reservations using a linked list
- Adding students to waiting lists
- Removing students from waiting lists in FIFO order
- Displaying waiting lists
- Managing waiting lists using queues
- Tracking cancelled reservations using a stack
- Displaying cancellation history
- Restoring the most recently cancelled reservation
- Handling invalid reservation requests

## Data Structures

The project uses several data structures to manage different parts of the system.

- **Vector:** Stores campus resource information loaded from the resource file.
- **Linked List:** Stores active reservations and supports insertion, removal, traversal, and display.
- **Queue:** Stores student waiting lists and processes students in FIFO (First In, First Out) order.
- **Stack:** Stores cancelled reservations and allows the most recently cancelled reservation to be restored.

## Project Structure

- `include/` - Header files containing class declarations
- `src/` - C++ implementation files and the main program
- `data/` - Resource input data
- `ComplexityAnalysis.md` - Big-O complexity analysis for the required operations
- `testReservation.cpp` - Reservation and linked-list testing
- `testCancellation.cpp` - Cancellation-history and stack testing
- `README.md` - Project overview and build instructions
- `UserGuide.md` - Instructions for using the system
- `GroupContributionReport.md` - Individual team contributions
- `GitHubURL.txt` - Repository branch URL

## Resource File Format

Resource information is loaded from:

`data/resources.txt`

The resource file uses the following format:

`ID,Name,Type,Availability`

Availability values:

- `1` = Available
- `0` = Unavailable / In Use

Example:

`LAP01,Dell Laptop,Laptop,1`

## Compilation

The project uses C++17 and has been compiled and tested successfully on the UNT CSE CELL machines.

From the root project directory, compile the complete program using:

```bash
g++ -std=c++17 src/main.cpp src/Resource.cpp src/WaitingList.cpp src/Reservation.cpp src/ReservationManager.cpp src/CancellationHistory.cpp src/WaitingListReport.cpp -Iinclude -o program
```

Run the program using:

```bash
./program
```

## Program Menu

The integrated program provides the following options:

1. Display All Resources
2. Display Resource Availability
3. Create Reservation
4. Cancel Reservation
5. Display Active Reservations
6. Add Student to Waiting List
7. Remove Next Student from Waiting List
8. Display Waiting List
9. Display Cancellation History
10. Undo Last Cancellation
11. Search Resource by ID
12. Sort Resources by Name
13. Waiting-List Statistics
14. Resource Utilization
15. Most Requested Resources
16. Exit

## Validation

The reservation system performs validation before creating reservations.

The program:

- Prevents duplicate reservation IDs
- Checks whether a requested resource ID exists
- Checks whether the requested resource is currently available
- Validates manually entered reservation dates, including month lengths and leap years
- Marks a resource as unavailable after it is reserved
- Frees a resource after cancellation and automatically assigns it to the next waiting student, if one exists
- Marks the resource as unavailable again if a cancellation is undone
- Reports when a requested reservation cannot be found
- Handles empty waiting lists and empty cancellation history

## Complexity Analysis

A separate complexity analysis is provided in `ComplexityAnalysis.md`.

The analysis discusses:

- Reservation insertion
- Reservation removal
- Waiting-list processing
- Undo cancellation and cancellation history
- Manually implemented linear search and merge sort
- Active reservations, waiting-list statistics, utilization, and popularity reports

The analysis distinguishes individual queue/stack operations from complete workflows, including map lookups and linked-list traversals.

Big-O notation and explanations are provided based on the data structures and algorithms used in the project.

## Testing

The project was tested throughout development and after integration.

Testing included:

- Loading resources from the input file
- Displaying resource information
- Creating valid reservations
- Rejecting invalid resource IDs
- Rejecting duplicate reservation IDs
- Preventing reservations for unavailable resources
- Cancelling reservations
- Verifying resource availability after cancellation
- Restoring cancelled reservations
- Verifying resource availability after undo
- Adding multiple students to waiting lists
- Verifying FIFO queue behavior
- Removing students from waiting lists
- Handling empty waiting lists
- Displaying cancellation history
- Compiling and running the complete integrated project on the UNT CSE CELL machines

### Running the Included Component Tests

Compile and run each test separately from the project root:

```bash
g++ -std=c++17 testReservation.cpp src/Reservation.cpp src/ReservationManager.cpp -Iinclude -o testReservation
./testReservation

g++ -std=c++17 testCancellation.cpp src/Reservation.cpp src/CancellationHistory.cpp -Iinclude -o testCancellation
./testCancellation
```

These tests print results for manual inspection. They cover reservation-list and cancellation-stack operations; they do not automatically verify the complete menu, search, sorting, or reports.

## GitHub Repository

GitHub Repository: https://github.com/JrdanRobinson/CSCE-2110

Branch URL recorded in `GitHubURL.txt`: https://github.com/JrdanRobinson/CSCE-2110/tree/feature/final-integration

## Team Collaboration

The project was developed collaboratively using GitHub.

Each team member used their own GitHub account to contribute to the repository. Development work was separated using feature branches so that individual components could be implemented and tested before being integrated into the complete program.

The team used:

- GitHub commits to document code changes
- Feature branches to separate development work
- Pull requests to review and integrate completed features
- Branch merging to combine individual components
- Integration testing to verify that the different components worked together
- UNT CSE CELL machines to verify final compilation and execution

The final integrated version combines resource management, reservation management, linked-list storage, queue-based waiting lists, stack-based cancellation history, validation, and the main program interface.

## Authors and Responsibilities

### Jordan

- Implemented cancellation-history functionality using a stack
- Worked on cancellation restoration/undo functionality
- Integrated the individual project components into the main program
- Connected reservation cancellation with cancellation history
- Added waiting-list operations to the integrated program menu
- Added reservation and resource validation
- Integrated resource availability changes with reservation creation, cancellation, and restoration
- Performed debugging and integration testing
- Tested the complete project on the UNT CSE CELL machines
- Managed GitHub integration, branches, pull requests, and merges
- Contributed to project documentation and complexity analysis

### Deepsan

- Implemented reservation management
- Created the reservation data structure and related functionality
- Implemented the linked list used to store active reservations
- Implemented reservation insertion
- Implemented reservation removal
- Implemented traversal and display of active reservations
- Added reservation ID uniqueness checking
- Contributed reservation-related testing

### SEOKHYEON

- Implemented resource management
- Implemented resource loading from the input file
- Implemented resource storage and display functionality
- Implemented resource availability functionality
- Implemented waiting-list management
- Used queues to maintain waiting lists in FIFO order
- Implemented adding students to waiting lists
- Implemented removing the next student from waiting lists
- Implemented waiting-list display functionality

## Authors

- Jordan
- Deepsan
- SEOKHYEON

## Searching, Sorting, and Reporting

### Searching and Sorting

- Manually implemented linear search locates resources by ID in O(R) time and does not require sorted data.
- Manually implemented merge sort organizes resources alphabetically by name in O(R log R) time with O(R) extra space.

R is the number of resources. Neither feature uses a library function to perform its required search or sort.

### Reporting

- Active Reservations: Displays currently active reservations.
- Resource Utilization: Displays the number of active reservations for each resource.
- Waiting-List Statistics: Displays the number of waiting students for each resource.
- Most Requested Resources: Ranks resources by successful reservation and waiting-list request counts.

Request counts are maintained during program execution and reset when the program restarts. Automatic waiting-list promotion and undo do not count the same request again. The most-requested report ranks resources with a separate O(R²) nested-loop algorithm.

Reservations, waiting lists, cancellation history, and availability changes also remain in memory only; they are not saved on exit. Automatically assigned reservations display `Auto-Assigned` in the date field.

### Cancellation Safety

The system stores cancelled reservations using a stack. Undo restores the most recent cancellation only when its resource is available and its reservation ID is not already in use.
