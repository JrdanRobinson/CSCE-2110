#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H
#include "Reservation.h"

//handles multiple reservation objects
class ReservationManager{
    private:
    //node used to build linked list of active reservations
        struct Node{
            Reservation information;
            Node* next;
        };
        
    //points to the first node in the linked list
        Node* head;


    public:
    //default constructor 
    ReservationManager();
    
    //declares function to add reservation to the linked list
    void addReservation(const Reservation& reservation);

};
#endif