/*Test file to test the ReservationManager functionality*/

#include <iostream>
#include "include/ReservationManager.h"
#include "include/Reservation.h"

int main(){
    //creates a reservation manager object to manage reservations
    ReservationManager manager;

    //creates some reservation objects to test the functionality
    Reservation r1("R001", "S001", "Don McLean", "ResourceA", "2020-01-01");
    Reservation r2("R002", "S002", "Bob Dylan", "ResourceB", "2020-01-02");  
    Reservation r3("R003", "S003", "Mick Jagger", "ResourceC", "2020-01-03");

    //adds the reservations to the manager
    manager.addReservation(r1);
    manager.addReservation(r2); 
    manager.addReservation(r3);

    //displays the reservations to verify they were added correctly
    std::cout << "Current reservations:" << std::endl;
    manager.displayReservations();
    
    //attempts to add a duplicate reservation to test the uniqueness check
    Reservation duplicate("R003", "S003", "Mick Jagger", "ResourceC", "2020-01-03");
    manager.addReservation(duplicate);

    //cancels a reservation and displays the list again to verify it was removed
    manager.cancelReservation("R002");
    std::cout << "After cancellation:\n" << std::endl;
    manager.displayReservations();

    //attempts to cancel a non-existent reservation to test the cancellation function
    if (manager.cancelReservation("non-existentId")) {
        std::cout << "Reservation ID non-existentId cancelled successfully.\n" << std::endl;
    } else {
        std::cout << "Error:Reservation ID not found.\n" << std::endl;
    }


    //attempt to cleanly remove the head node and display the list again to verify it was removed
    manager.cancelReservation("R001");
    std::cout << "After removing head node:\n" << std::endl;
    manager.displayReservations();

    //remove the last remaining reservation to test the empty list case
    manager.cancelReservation("R003");
    std::cout << "After removing last reservation:\n" << std::endl;
    manager.displayReservations(); //should show no reservations
    
    //attempt to cancel a reservation from an empty list to test the empty list case
    if (manager.cancelReservation("R001")) {
        std::cout << "Reservation ID R001 cancelled successfully.\n" << std::endl;
    } else {
        std::cout << "Error: Reservation ID not found.\n" << std::endl;
    }


    return 0;
}