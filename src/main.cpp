#include <iostream>
#include <string>
#include <vector>

#include "Resource.h"
#include "WaitingList.h"
#include "Reservation.h"
#include "ReservationManager.h"
#include "CancellationHistory.h"

using namespace std;

int main() {

    // Load resources from file
    vector<Resource> resources = loadResources("data/resources.txt");

    ReservationManager reservationManager;
    waitingList waitList;
    CancellationHistory cancellationHistory;

    int choice = 0;

    while (choice != 9) {

        cout << "\n===== Campus Resource Reservation System =====" << endl;
        cout << "1. Display All Resources" << endl;
        cout << "2. Display Resource Availability" << endl;
        cout << "3. Create Reservation" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. Display Active Reservations" << endl;
        cout << "6. Display Waiting List" << endl;
        cout << "7. Display Cancellation History" << endl;
        cout << "8. Undo Last Cancellation" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) {

            cout << "\n===== All Resources =====" << endl;
            displayAllResources(resources);
        }

        else if (choice == 2) {

            cout << "\n===== Resource Availability =====" << endl;
            showAvailabilityCount(resources);
        }

        else if (choice == 3) {

            string reservationId;
            string studentId;
            string studentName;
            string resourceId;
            string reservationDate;

            cout << "Reservation ID: ";
            cin >> reservationId;

            cout << "Student ID: ";
            cin >> studentId;

            cout << "Student Name: ";
            cin.ignore();
            getline(cin, studentName);

            cout << "Resource ID: ";
            cin >> resourceId;

            cout << "Reservation Date: ";
            cin >> reservationDate;

            Reservation reservation(
                reservationId,
                studentId,
                studentName,
                resourceId,
                reservationDate
            );

            reservationManager.addReservation(reservation);

            cout << "Reservation request processed." << endl;
        }

       else if (choice == 4) {

    string reservationId;
    Reservation cancelledReservation;

    cout << "Enter Reservation ID to cancel: ";
    cin >> reservationId;

    // Find the reservation before deleting it
    if (reservationManager.findReservation(reservationId, cancelledReservation)) {

        // Remove it from the active reservation linked list
        if (reservationManager.cancelReservation(reservationId)) {

            // Save the cancelled reservation in the stack
            cancellationHistory.addCancellation(cancelledReservation);

            cout << "Reservation cancelled." << endl;
        }
    }
    else {
        cout << "Reservation not found." << endl;
    }
}
        else if (choice == 5) {

            cout << "\n===== Active Reservations =====" << endl;
            reservationManager.displayReservations();
        }

        else if (choice == 6) {

            string resourceType;

            cout << "Enter resource type (Laptop, Calculator, Mouse, StudyRoom): ";
            cin >> resourceType;

            waitList.displayWaitingList(resourceType);
        }

        else if (choice == 7) {

            cout << "\n===== Cancellation History =====" << endl;
            cancellationHistory.displayCancellationHistory();
        }

        else if (choice == 8) {

            Reservation restoredReservation;

            if (cancellationHistory.restoreLastCancellation(restoredReservation)) {

                reservationManager.addReservation(restoredReservation);

                cout << "Most recently cancelled reservation restored." << endl;
            }
            else {
                cout << "No cancelled reservations to restore." << endl;
            }
        }

        else if (choice == 9) {

            cout << "Exiting program." << endl;
        }

        else {

            cout << "Invalid choice. Please enter 1-9." << endl;
        }
    }

    return 0;
}
