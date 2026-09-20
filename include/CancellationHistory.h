#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include <stack>
#include "Reservation.h"

using namespace std;

// Stores cancelled reservations using a stack.
// The most recently cancelled reservation is the first one that can be restored.
class CancellationHistory {
private:
    stack<Reservation> cancelledReservations;

public:
    // Adds a cancelled reservation to the top of the stack
    void addCancellation(const Reservation& reservation);

    // Restores/removes the most recently cancelled reservation
    bool restoreLastCancellation(Reservation& reservation);

    // Displays all cancelled reservations
    void displayCancellationHistory();

    // Checks if there are any cancelled reservations
    bool isEmpty();
};

#endif
