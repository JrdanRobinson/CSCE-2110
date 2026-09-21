#include <iostream>
#include "../include/ReservationManager.h"

// the default constructor to initialize an empty linked list
ReservationManager::ReservationManager()
    : head(nullptr)
{
}

// the destructor to free the memory used by the linked list
ReservationManager::~ReservationManager() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// defines function to add reservation to the linked list
void ReservationManager::addReservation(const Reservation& reservation) {

    if (!isReservationIdUnique(reservation.getReservationId())) {
        std::cout << "Error: Reservation ID "
                  << reservation.getReservationId()
                  << " is not unique. Reservation not added."
                  << std::endl;
        return;
    }

    Node* newNode = new Node;
    newNode->information = reservation;
    newNode->next = nullptr;

    // if the linked list is empty, set the head to the new node
    if (head == nullptr) {
        head = newNode;
    }

    // if the linked list is not empty, traverse to the end
    else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }
}

// defines function to display all reservations in the linked list
void ReservationManager::displayReservations() const {

    Node* current = head;

    // if the linked list is empty, display a message
    if (current == nullptr) {
        std::cout << "No reservations found." << std::endl;
        return;
    }

    while (current != nullptr) {

        std::cout << "Reservation ID: "
                  << current->information.getReservationId() << std::endl;

        std::cout << "Student ID: "
                  << current->information.getStudentId() << std::endl;

        std::cout << "Student Name: "
                  << current->information.getStudentName() << std::endl;

        std::cout << "Resource ID: "
                  << current->information.getResourceId() << std::endl;

        std::cout << "Reservation Date: "
                  << current->information.getReservationDate() << std::endl;

        std::cout << "------------------------" << std::endl;

        current = current->next;
    }
}

// defines function to cancel a reservation by its ID
bool ReservationManager::cancelReservation(
    const std::string& reservationId)
{
    if (head == nullptr) {
        return false;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {

        if (current->information.getReservationId() == reservationId) {

            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            delete current;

            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

// defines function to check if a reservation ID is unique
bool ReservationManager::isReservationIdUnique(
    const std::string& reservationId) const
{
    Node* current = head;

    while (current != nullptr) {

        if (current->information.getReservationId() == reservationId) {
            return false;
        }

        current = current->next;
    }

    return true;
}

// finds a reservation by its ID
bool ReservationManager::findReservation(
    const std::string& reservationId,
    Reservation& reservation) const
{
    Node* current = head;

    while (current != nullptr) {

        if (current->information.getReservationId() == reservationId) {
            reservation = current->information;
            return true;
        }

        current = current->next;
    }

    return false;
}
