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

    while (choice != 11) {

        cout << "\n===== Campus Resource Reservation System =====" << endl;
        cout << "1. Display All Resources" << endl;
        cout << "2. Display Resource Availability" << endl;
        cout << "3. Create Reservation" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. Display Active Reservations" << endl;
        cout << "6. Add Student to Waiting List" << endl;
        cout << "7. Remove Next Student from Waiting List" << endl;
        cout << "8. Display Waiting List" << endl;
        cout << "9. Display Cancellation History" << endl;
        cout << "10. Undo Last Cancellation" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        //RESOURCE MANAGEMENT
        if (choice == 1) {

            cout << "\n===== All Resources =====" << endl;
            displayAllResources(resources);
        }

        else if (choice == 2) {

            cout << "\n===== Resource Availability =====" << endl;
            showAvailabilityCount(resources);
        }

        // RESERVATION MANAGEMENT 

        else if (choice == 3) {

            string reservationId;
            string studentId;
            string studentName;
            string resourceId;
            string reservationDate;

            cout << "Reservation ID: ";
            cin >> reservationId;

            // Check if reservation ID already exists
            if (!reservationManager.isReservationIdUnique(reservationId)) {

                cout << "Error: Reservation ID already exists." << endl;
                continue;
            }

            cout << "Student ID: ";
            cin >> studentId;

            cout << "Student Name: ";
            cin.ignore();
            getline(cin, studentName);

            cout << "Resource ID: ";
            cin >> resourceId;

            // Find requested resource
            Resource* selectedResource = nullptr;

            for (int i = 0; i < resources.size(); i++) {

                if (resources[i].getID() == resourceId) {

                    selectedResource = &resources[i];
                    break;
                }
            }

            // Check if resource exists
            if (selectedResource == nullptr) {

                cout << "Error: Resource ID does not exist." << endl;
                continue;
            }

            // Check if resource is available
            if (!selectedResource->isItAvailable()) {

                cout << "Error: Resource is currently unavailable." << endl;
                continue;
            }

            cout << "Reservation Date: ";
            cin >> reservationDate;

            Reservation reservation(
                reservationId,
                studentId,
                studentName,
                resourceId,
                reservationDate
            );

            // Add reservation to linked list
            reservationManager.addReservation(reservation);

            // Mark resource as unavailable
            selectedResource->setAvailable(false);

            cout << "Reservation created successfully." << endl;
        }

        else if (choice == 4) {

            string reservationId;
            Reservation cancelledReservation;

            cout << "Enter Reservation ID to cancel: ";
            cin >> reservationId;

            // Find reservation before deleting it
            if (reservationManager.findReservation(
                    reservationId,
                    cancelledReservation)) {

                // Remove reservation from active linked list
                if (reservationManager.cancelReservation(reservationId)) {

                    // Store cancelled reservation in stack
                    cancellationHistory.addCancellation(
                        cancelledReservation
                    );

                    // Make resource available again
                    string cancelledResourceId =
                        cancelledReservation.getResourceId();

                    for (int i = 0; i < resources.size(); i++) {

                        if (resources[i].getID() ==
                            cancelledResourceId) {

                            resources[i].setAvailable(true);
                            break;
                        }
                    }

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

        //  WAITING LIST MANAGEMENT 

        else if (choice == 6) {

            string studentName;
            string studentId;
            string studentEmail;
            string resourceType;

            cout << "Student Name: ";
            cin.ignore();
            getline(cin, studentName);

            cout << "Student ID: ";
            cin >> studentId;

            cout << "Student Email: ";
            cin >> studentEmail;

            cout << "Resource Type "
                 << "(Laptop, Calculator, Mouse, StudyRoom): ";

            cin >> resourceType;

            waitRequest request(
                studentName,
                studentId,
                studentEmail,
                resourceType
            );

            waitList.addToWaitingList(request);

            cout << "Student added to waiting list." << endl;
        }

        else if (choice == 7) {

            string resourceType;

            cout << "Resource Type "
                 << "(Laptop, Calculator, Mouse, StudyRoom): ";

            cin >> resourceType;

            waitRequest nextStudent("", "", "", "");

            if (waitList.removeNext(resourceType, nextStudent)) {

                cout << nextStudent.getName()
                     << " removed from the waiting list."
                     << endl;
            }
        }

        else if (choice == 8) {

            string resourceType;

            cout << "Resource Type "
                 << "(Laptop, Calculator, Mouse, StudyRoom): ";

            cin >> resourceType;

            waitList.displayWaitingList(resourceType);
        }

        // CANCELLATION HISTORY 

        else if (choice == 9) {

            cout << "\n===== Cancellation History =====" << endl;

            cancellationHistory.displayCancellationHistory();
        }

        else if (choice == 10) {

            Reservation restoredReservation;

            if (cancellationHistory.restoreLastCancellation(
                    restoredReservation)) {

                // Restore reservation to linked list
                reservationManager.addReservation(
                    restoredReservation
                );

                // Mark resource unavailable again
                string restoredResourceId =
                    restoredReservation.getResourceId();

                for (int i = 0; i < resources.size(); i++) {

                    if (resources[i].getID() ==
                        restoredResourceId) {

                        resources[i].setAvailable(false);
                        break;
                    }
                }

                cout << "Most recently cancelled reservation restored."
                     << endl;
            }
            else {

                cout << "No cancelled reservations to restore."
                     << endl;
            }
        }

        // EXIT 

        else if (choice == 11) {

            cout << "Exiting program." << endl;
        }

        else {

            cout << "Invalid choice. Please enter 1-11." << endl;
        }
    }

    return 0;
}
