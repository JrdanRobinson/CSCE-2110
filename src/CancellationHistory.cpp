#include "../include/CancellationHistory.h"
#include <iostream>

using namespace std;

// Adds a cancelled reservation to the top of the stack
void CancellationHistory::addCancellation(const Reservation& reservation) {
    cancelledReservations.push(reservation);
}

// Restores the most recently cancelled reservation
bool CancellationHistory::restoreLastCancellation(Reservation& reservation) {

    // Cannot restore anything if the stack is empty
    if (cancelledReservations.empty()) {
        cout << "No cancelled reservations to restore." << endl;
        return false;
    }

    // Get the most recently cancelled reservation
    reservation = cancelledReservations.top();

    // Remove it from cancellation history
    cancelledReservations.pop();

    return true;
}

// Displays all cancelled reservations
void CancellationHistory::displayCancellationHistory() {

    if (cancelledReservations.empty()) {
        cout << "No cancellation history." << endl;
        return;
    }

    // Make a copy so displaying the history does not destroy the real stack
    stack<Reservation> copyStack = cancelledReservations;

    cout << "Cancellation History:" << endl;

    while (!copyStack.empty()) {

        Reservation reservation = copyStack.top();

        cout << "Reservation ID: "
             << reservation.getReservationId() << endl;

        cout << "Student ID: "
             << reservation.getStudentId() << endl;

        cout << "Student Name: "
             << reservation.getStudentName() << endl;

        cout << "Resource ID: "
             << reservation.getResourceId() << endl;

        cout << "Reservation Date: "
             << reservation.getReservationDate() << endl;

        cout << "------------------------" << endl;

        copyStack.pop();
    }
}

// Checks whether the cancellation stack is empty
bool CancellationHistory::isEmpty() {
    return cancelledReservations.empty();
}
