# Campus Resource Reservation System

## CSCE 2110

The Campus Resource Reservation System is a C++ program designed to manage campus resources and student reservations. Milestone 1 focuses on implementing the core system functionality while demonstrating the use of fundamental data structures including vectors, linked lists, queues, and stacks.

The project was developed collaboratively using GitHub feature branches, commits, and pull requests.

## Milestone 1 Features

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
- `README.md` - Project documentation

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
g++ -std=c++17 src/main.cpp src/Resource.cpp src/WaitingList.cpp src/Reservation.cpp src/ReservationManager.cpp src/CancellationHistory.cpp -Iinclude -o program
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
11. Exit

## Validation

The reservation system performs validation before creating reservations.

The program:

- Prevents duplicate reservation IDs
- Checks whether a requested resource ID exists
- Checks whether the requested resource is currently available
- Marks a resource as unavailable after it is reserved
- Marks the resource as available after its reservation is cancelled
- Marks the resource as unavailable again if a cancellation is undone
- Reports when a requested reservation cannot be found
- Handles empty waiting lists and empty cancellation history

## Complexity Analysis

A separate complexity analysis is provided in `ComplexityAnalysis.md`.

The analysis discusses:

- Reservation insertion
- Reservation removal
- Waiting-list processing
- Undo cancellation

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
