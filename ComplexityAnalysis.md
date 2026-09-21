Campus Resource Reservation System
Milestone 1 – Complexity Analysis


Reservation Insertion — O(n)

Active reservations are stored using a linked list. When a new reservation is added, the program first checks the existing reservations to make sure the reservation ID is unique. It then travels through the linked list to reach the end before adding the new reservation. Because the program may need to look through all existing reservations, the time complexity for reservation insertion is O(n), where n is the number of active reservations.

Reservation Removal — O(n)

When a reservation is cancelled, the program searches through the linked list using the reservation ID. In the worst case, the reservation could be located at the end of the list or may not exist. This means the program may have to check every reservation. Therefore, reservation removal has a time complexity of O(n).

Waiting-List Processing — O(1)

The waiting list uses a queue. A student is added to the back of the queue using push(), and the next student is accessed from the front using front() and removed using pop(). These queue operations do not require searching through the other students in the queue. Therefore, adding or removing a student from a waiting list has a time complexity of O(1).

Displaying the entire waiting list is O(n) because each student in the queue must be visited.

Undo Cancellation — O(1)

Cancellation history is stored using a stack. When a reservation is cancelled, it is placed on top of the stack using push(). To undo the most recent cancellation, the program accesses and removes the reservation at the top of the stack using top() and pop(). These stack operations have a time complexity of O(1).

In the complete program, restoring the reservation to the active-reservation linked list can take O(n) because the reservation manager traverses the linked list when inserting the restored reservation. Therefore, the stack operation itself is O(1), while the complete undo-and-restore operation can be O(n).
