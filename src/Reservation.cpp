#include "../include/Reservation.h"

//the default constructor initializes everything as empty first

Reservation::Reservation()
    :   reservationId(""),
        studentId(""),
        studentName(""),
        resourceId(""),
        reservationDate("")
{
}

//info included constructor initialization
Reservation::Reservation(
    std::string reservationId,
    std::string studentId,
    std::string studentName,
    std::string resourceId,
    std::string reservationDate)
    :   reservationId(reservationId),
        studentId(studentId),
        studentName(studentName),
        resourceId(resourceId),
        reservationDate(reservationDate)
{
}

//getters

std::string Reservation::getReservationId() const{
    return reservationId;
}
std::string Reservation::getStudentId() const{
    return studentId;
}
std::string Reservation::getStudentName() const{
    return studentName;
}
std::string Reservation::getResourceId() const{
    return resourceId;
}
std::string Reservation::getReservationDate() const{
    return reservationDate;
}