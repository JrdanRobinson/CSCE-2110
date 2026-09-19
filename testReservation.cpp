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


    return 0;
}