/** @file cinema.h
 *  @brief Interface and function prototypes for the cinema.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef CINEMA_H
#define CINEMA_H

#include <list>
#include "room.h"

/**
 * @brief Cinema represents whole build of cinema which can contains many rooms inside.
 * Cinema aggregates manu room which each has specific conditions inside.
 */
class Cinema {
    public:
        /**
         * @brief Cinema constructor
         *
         * @param newListOfRoomsInCinema list of all rooms located in this cinema
         */
        Cinema(std::list<Room> newListOfRoomsInCinema);

        /**
         * @brief find room in the list of rooms by its name
         * @return Room object.
         */
        Room getRoomByName(std::string roomName);

    private:
        /**
         * list of objects of Room type which contains all rooms in the cinema building.
         */
        std::list<Room> listOfRoomsInCinema;
};

#endif // CINEMA_H
