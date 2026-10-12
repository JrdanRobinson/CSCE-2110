#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "CancellationHistory.h"
#include "Resource.h"
#include "WaitingList.h"
#include "Reservation.h"
#include "ReservationManager.h"
#include "CancellationHistory.h"
#include "WaitingListReport.h"


using namespace std;

int main() {

    // Load resources from file
    vector<Resource> resources = loadResources("data/resources.txt");

    ReservationManager reservationManager;
    waitingList waitList;
    CancellationHistory cancellationHistory;

    int choice = 0;

    while (choice != 16) {

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
        cout << "13. Waiting-List Statistics" << endl;
	cout << "14. Resource Utilization" << endl;
	cout << "15. Most Requested Resources" << endl;
	cout << "16. Exit" << endl;
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
resources[resourceIndex].incrementRequestCount();

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

    string resourceId;

    cout << "Resource ID (example: LAP01): ";
    cin >> resourceId;

    int resourceIndex = linearSearchResource(resources, resourceId);

    if (resourceIndex == -1) {
        cout << "Error: Resource ID does not exist." << endl;
        continue;
    }

    if (resources[resourceIndex].isItAvailable()) {
        cout << "This resource is available. Please reserve it instead." << endl;
        continue;
    }

    string studentName, studentId, studentEmail;

    cout << "Student Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, studentName);

    cout << "Student ID: ";
    cin >> studentId;

    cout << "Student Email: ";
    cin >> studentEmail;

    waitRequest request(studentName, studentId, studentEmail, resourceId);
waitList.addToWaitingList(request);
resources[resourceIndex].incrementRequestCount();

cout << "Student added to waiting list." << endl;
}

	else if (choice == 7) {

    string resourceId;

    cout << "Resource ID (example: LAP01): ";
    cin >> resourceId;

    waitRequest nextStudent("", "", "", "");

    if (waitList.removeNext(resourceId, nextStudent)) {
        cout << nextStudent.getName()
             << " removed from the waiting list." << endl;
    }
}
	else if (choice == 8) {

    string resourceId;

    cout << "Resource ID (example: LAP01): ";
    cin >> resourceId;

    waitList.displayWaitingList(resourceId);
}
        // CANCELLATION HISTORY

        else if (choice == 9) {

            cout << "\n===== Cancellation History =====" << endl;
            cancellationHistory.displayCancellationHistory();
        }

        else if (choice == 10) {

    Reservation restoredReservation;

    // Look at the most recent cancellation without removing it
    if (!cancellationHistory.peekLastCancellation(restoredReservation)) {
        cout << "No cancelled reservations to restore." << endl;
    }
    else {
        string restoredResourceId = restoredReservation.getResourceId();

        int resourceIndex =
            linearSearchResource(resources, restoredResourceId);

        if (resourceIndex == -1) {
            cout << "Cannot restore: Resource no longer exists." << endl;
        }
        else if (!resources[resourceIndex].isItAvailable()) {
            cout << "Cannot restore: Resource is already reserved." << endl;
        }
        else if (!reservationManager.isReservationIdUnique(
                     restoredReservation.getReservationId())) {
            cout << "Cannot restore: Reservation ID already exists." << endl;
        }
        else {
            // Resource is available and reservation ID is unique
            reservationManager.addReservation(restoredReservation);
            resources[resourceIndex].setAvailable(false);

            // Remove the cancellation from history after restoring
            Reservation removedReservation;
            cancellationHistory.restoreLastCancellation(removedReservation);

            cout << "Most recently cancelled reservation restored." << endl;
        }
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

       // WAITING-LIST STATISTICS

	else if (choice == 13) {
    	cout << "\n===== Waiting-List Statistics =====" << endl;
    	printWaitingStats(resources, waitList);
}

	// RESOURCE UTILIZATION

	else if (choice == 14) {
    	cout << "\n===== Resource Utilization =====" << endl;
    	printUtilization(resources, reservationManager);
}

	// EXIT

	else if (choice == 15) {
    	printMostRequested(resources);
}
	else if (choice == 16) {
    	     cout << "Exiting program." << endl;
}
	else {
    	     cout << "Invalid choice. Please enter 1-16." << endl;
}
    }

    return 0;
}
