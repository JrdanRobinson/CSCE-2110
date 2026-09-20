#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>

//defines the reservation class used to store reservation info
class Reservation{
    private:
    //info associated with each reservation
        std::string reservationId;
        std::string studentId;
        std::string studentName;
        std::string resourceId;
        std::string reservationDate;

    public:
    //constructors

    //default constructor which is to be defined in Reservation.cpp
        Reservation();
    //constructor for creating a reservation with the info included
        Reservation(
            std::string reservationId,
            std::string studentId,
            std::string studentName,
            std::string resourceId,
            std::string reservationDate
        );
        
    //getters for code elsewhere
        std::string getReservationId() const;
        std::string getStudentId() const;
        std::string getStudentName() const;
        std::string getResourceId() const;
        std::string getReservationDate() const;
};

#endif