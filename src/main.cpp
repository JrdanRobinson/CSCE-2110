#include <iostream>
#include <string>
#include <vector>
#include <limits>

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

    while (choice != 13) {

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
        cout << "11. Search Resource by ID" << endl;
        cout << "12. Sort Resources by Name" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // RESOURCE MANAGEMENT

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

            if (!reservationManager.isReservationIdUnique(reservationId)) {
                cout << "Error: Reservation ID already exists." << endl;
                continue;
            }

            cout << "Student ID: ";
            cin >> studentId;

            cout << "Student Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, studentName);

            cout << "Resource ID: ";
            cin >> resourceId;

            // Find resource using Linear Search
            int resourceIndex = linearSearchResource(resources, resourceId);

            if (resourceIndex == -1) {
                cout << "Error: Resource ID does not exist." << endl;
                continue;
            }

            if (!resources[resourceIndex].isItAvailable()) {
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

            reservationManager.addReservation(reservation);
            resources[resourceIndex].setAvailable(false);

            cout << "Reservation created successfully." << endl;
        }

        else if (choice == 4) {

            string reservationId;
            Reservation cancelledReservation;

            cout << "Enter Reservation ID to cancel: ";
            cin >> reservationId;

            if (reservationManager.findReservation(
                    reservationId, cancelledReservation)) {

                if (reservationManager.cancelReservation(reservationId)) {

                    cancellationHistory.addCancellation(cancelledReservation);

                    string cancelledResourceId =
                        cancelledReservation.getResourceId();

                    int resourceIndex =
                        linearSearchResource(resources, cancelledResourceId);

                    if (resourceIndex != -1) {
                        resources[resourceIndex].setAvailable(true);
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

        // WAITING LIST MANAGEMENT

        else if (choice == 6) {

            string studentName;
            string studentId;
            string studentEmail;
            string resourceType;

            cout << "Student Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                     << " removed from the waiting list." << endl;
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

                reservationManager.addReservation(restoredReservation);

                string restoredResourceId =
                    restoredReservation.getResourceId();

                int resourceIndex =
                    linearSearchResource(resources, restoredResourceId);

                if (resourceIndex != -1) {
                    resources[resourceIndex].setAvailable(false);
                }

                cout << "Most recently cancelled reservation restored."
                     << endl;
            }
            else {
                cout << "No cancelled reservations to restore." << endl;
            }
        }

        // LINEAR SEARCH

        else if (choice == 11) {

            string resourceId;

            cout << "\n===== Search Resource by ID =====" << endl;
            cout << "Enter Resource ID: ";
            cin >> resourceId;

            int resourceIndex = linearSearchResource(resources, resourceId);

            if (resourceIndex == -1) {
                cout << "Resource not found." << endl;
            }
            else {
                cout << "\nResource found:" << endl;
                resources[resourceIndex].display();
            }
        }

        // MERGE SORT

        else if (choice == 12) {

            cout << "\n===== Sort Resources by Name =====" << endl;

            if (resources.empty()) {
                cout << "No resources available to sort." << endl;
            }
            else {
                mergeSortResources(resources, 0,
                                   static_cast<int>(resources.size()) - 1);

                cout << "\nResources sorted alphabetically:" << endl;
                displayAllResources(resources);
            }
        }

        // EXIT

        else if (choice == 13) {
            cout << "Exiting program." << endl;
        }

        else {
            cout << "Invalid choice. Please enter 1-13." << endl;
        }
    }

    return 0;
}
