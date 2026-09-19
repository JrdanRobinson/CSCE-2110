#include "../include/ReservationManager.h"

//the default constructor to initialize an empty linked list
ReservationManager::ReservationManager()
    : head(nullptr)
{
}

//defines function to add reservation to the linked list
void ReservationManager::addReservation(const Reservation& reservation){
    Node* newNode = new Node;
    newNode->information = reservation;
    newNode->next=nullptr;

    if(head==nullptr){
        head = newNode;
    }
}

