# Campus Resource Reservation System — User Guide

## Getting Started
Compile the project on UNT CSE CELL using the command in README.md.
Run the application with ./program.

## Using the Menu
Enter a number from 1 to 16 and follow the prompts.

1. Display all resources.
2. Display resource availability.
3. Create a reservation using a unique reservation ID, student information, resource ID, and a date in YYYY-MM-DD format.
4. Cancel an active reservation. If students are waiting for the resource, the first student is automatically assigned it.
5. Display active reservations.
6. Join the waiting list for an unavailable resource.
7. Remove the next student from a waiting list.
8. Display a resource's waiting list.
9. View cancellation history.
10. Undo the most recent cancellation if the resource is available.
11. Search for a resource by ID.
12. Sort resources alphabetically by name.
13. View waiting-list statistics.
14. View resource utilization.
15. View most requested resources.
16. Exit.

## Important Notes
- Resource IDs must exist in the loaded resource file.
- Reservation IDs must be unique among active reservations.
- Invalid reservation dates are rejected.
- Waiting lists operate in first-in, first-out order.
- Undo cannot double-book an occupied resource.
- Request counts reset when the application restarts.
