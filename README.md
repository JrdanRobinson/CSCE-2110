# Campus Resource Reservation System

## CSCE 2110

The Campus Resource Reservation System is a C++ program designed to manage campus resources and student reservations. Milestone 1 focuses on the core system functionality and the use of fundamental data structures.

## Milestone 1 Features

The system supports:

- Loading resource information from a file
- Displaying campus resources and their availability
- Creating and cancelling reservations
- Storing active reservations using a linked list
- Managing waiting lists using a queue
- Tracking cancelled reservations using a stack
- Restoring the most recently cancelled reservation
- Validating reservation requests

## Data Structures

- **Vector:** Stores campus resource information
- **Linked List:** Stores active reservations
- **Queue:** Manages student waiting lists in FIFO order
- **Stack:** Stores cancellation history and supports undo functionality

## Project Structure

- `include/` - Header files for project classes
- `src/` - C++ implementation files
- `data/` - Resource input files
- `testReservation.cpp` - Reservation and linked-list testing
- `testCancellation.cpp` - Cancellation-history and stack testing

## Resource File Format

Resource information is loaded from `data/resources.txt`.

Format:

`ID,Name,Type,Availability`

Availability uses:
- `1` = available
- `0` = unavailable/in use

Example:

`LAP01,Dell Laptop,Laptop,1`

## Compilation

The project uses C++17.

Individual components can be compiled for testing during development. Final compilation instructions will be updated after all Milestone 1 components have been integrated.

The final project will be compiled and tested on the UNT CSE CELL machines before submission.

## Team Collaboration

The project is maintained using GitHub. Team members contribute using their own GitHub accounts, commits, and feature branches. Pull requests are used to integrate completed components into the main branch.

## Authors

- Jordan - Cancellation history, documentation, GitHub management, integration, and testing
- Deepsan - Reservation management and linked list
- SEOKHYEON - Resource management and waiting list