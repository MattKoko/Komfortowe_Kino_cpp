/** @file cinema.cpp
 *  @brief implementation of Cinema class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "cinema.h"
#include <stdexcept>

Cinema::Cinema(std::list<Room> newListOfRoomsInCinema) {
    listOfRoomsInCinema = newListOfRoomsInCinema;
}


Room Cinema::getRoomByName(std::string roomName) {
    for (auto& elem : listOfRoomsInCinema) {
        if(elem.getRoomName() == roomName) {
            return elem;
        }
    }

    throw std::invalid_argument("NOT FOUND SPECIFIED ROOM!");
}
