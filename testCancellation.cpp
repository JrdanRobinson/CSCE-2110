#include <iostream>
#include "include/CancellationHistory.h"

using namespace std;

int main() {

    CancellationHistory history;

    // Create reservations for testing
    Reservation r1("R001", "S001", "Alice", "LAP01", "2026-09-20");
    Reservation r2("R002", "S002", "Bob", "ROOM01", "2026-09-21");

    // Test empty cancellation history
    cout << "===== Empty History Test =====" << endl;
    history.displayCancellationHistory();

    // Add cancelled reservations to the stack
    cout << "\n===== Adding Cancellations =====" << endl;
    history.addCancellation(r1);
    history.addCancellation(r2);

    // Display cancellation history
    history.displayCancellationHistory();

    // Restore the most recently cancelled reservation
    cout << "\n===== Undo Cancellation =====" << endl;

    Reservation restored;

    if (history.restoreLastCancellation(restored)) {
        cout << "Restored Reservation: "
             << restored.getReservationId() << endl;
    }

    // Display history after restoring
    cout << "\n===== History After Restore =====" << endl;
    history.displayCancellationHistory();

    return 0;
}
