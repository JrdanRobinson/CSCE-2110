# Milestone 1 Group Contribution Report

## Campus Resource Reservation System
### CSCE 2110

This report describes the individual contributions made by each team member during Milestone 1 of the Campus Resource Reservation System.

## Contribution Summary

| Team Member | Component(s) | Specific Tasks Completed | Testing / Debugging | GitHub Contributions |
|---|---|---|---|---|
| Jordan | Cancellation History, Integration, Validation, Documentation | Implemented cancellation-history functionality using a stack, integrated project components into the main menu, connected cancellations with reservation management, added waiting-list menu operations, added reservation/resource validation, and synchronized resource availability with reservations | Tested cancellation and undo functionality, waiting-list FIFO behavior, reservation validation, resource availability changes, full integration, and compilation/execution on UNT CSE CELL machines | Worked with feature branches, commits, pull requests, merges, integration branch, README, complexity analysis, and final project integration |
| Deepsan | Reservation Management, Linked List | Implemented the Reservation class and ReservationManager, linked-list storage for active reservations, reservation insertion, removal, traversal/display, reservation lookup, and reservation ID uniqueness checking | Created reservation tests and contributed to testing reservation and linked-list operations | Contributed reservation-management code through their own GitHub branch and commits |
| SEOKHYEON | Resource Management, Waiting List | Implemented resource file loading, resource storage/display, resource availability functionality, and queue-based waiting-list operations including add, remove, display, and empty-list checking | Developed and tested resource and waiting-list functionality before integration | Contributed resource-management and waiting-list code through their own GitHub branch and commits |

## Jordan

Jordan worked primarily on cancellation history, project integration, validation, documentation, and final testing. He implemented the cancellation-history component using a stack to store cancelled reservations and support restoration of the most recently cancelled reservation. During integration, he connected the reservation manager, cancellation history, resource management, and waiting-list components through the main program menu.

Jordan also added access to the waiting-list queue operations through the integrated menu and added validation to prevent duplicate reservation IDs, nonexistent resource IDs, and reservations for resources that were already in use. He integrated resource availability with reservation creation, cancellation, and restoration so that resource status remains consistent.

Jordan performed integration testing and debugging after the team's separate components were combined. This included testing reservation creation and cancellation, linked-list operations, FIFO waiting-list behavior, cancellation history, undo functionality, invalid reservation requests, and resource availability changes. He also compiled and tested the complete project on the UNT CSE CELL machines. His GitHub work included branch management, commits, pull requests, merges, integration work, README documentation, and the Milestone 1 complexity analysis.

## Deepsan

Deepsan worked primarily on reservation management and the linked-list implementation. Deepsan implemented the Reservation class used to store reservation information and the ReservationManager used to manage active reservations.

The reservation manager uses a linked list to store active reservation records. Deepsan implemented functionality for inserting reservations, removing cancelled reservations, traversing and displaying reservation records, checking reservation ID uniqueness, and locating reservations by ID. This component provided the active-reservation storage required by Milestone 1 and was later integrated with the cancellation-history and resource-management components. Deepsan also contributed reservation-related testing and GitHub commits through the reservation-management development branch.

## SEOKHYEON

SEOKHYEON worked primarily on resource management and waiting-list management. SEOKHYEON implemented the Resource class and functionality for loading resource information from `data/resources.txt`, storing resources, displaying resource information, and reporting resource availability.

SEOKHYEON also implemented the waiting-list component using queues. The waiting-list implementation supports adding students to the appropriate resource waiting list, removing the next student in FIFO order, displaying students currently waiting, and checking whether a waiting list is empty. These components were developed separately and later integrated into the complete program. SEOKHYEON contributed the resource and waiting-list implementation through GitHub branches and commits.
