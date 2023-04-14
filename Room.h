/** @file room.h
 *  @brief Interface and function prototypes for the room.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef ROOM_H
#define ROOM_H

#include "temperature.h"
#include "humidity.h"
#include "concentrationco2.h"
#include "controlPanel.h"

/**
 * @brief Room is used to group all condition values for specific room with calucations of each condition for prepared paramters.
 */
class Room {
    public:
        /**
         * @brief Room constructor
         *
         * @param newRoomName
         * @param newTempInside
         * @param newCO2Inside
         * @param newHumInside
         * @param newTempOutside
         * @param newCO2Outside
         * @param newHumOutside
         * @param newControlPanel
         */
        Room( std::string newRoomName,
            Temperature newTempInside,
            ConcentrationCO2 newCO2Inside,
            Humidity newHumInside,
            Temperature newTempOutside,
            ConcentrationCO2 newCO2Outside,
            Humidity newHumOutside,
            ControlPanel newControlPanel
             ) : roomName(newRoomName), tempInside(newTempInside), co2Inside(newCO2Inside),
                humInside(newHumInside), tempOutside(newTempOutside), co2Outside(newCO2Outside),
                humOutside(newHumOutside), controlPanel(newControlPanel){};

        /**
         * @brief recalculate value of temperature inside the room
         *
         * @param tempConst represents first temperature constant value used for caluclations of conditions
         * @param ventStatus represent current On/Off status of ventilation system in the room
         * @param peopleInside represent number of people which are currently in the room
         */
        void recalculateInsideTemperature(double tempConst, bool ventStatus, double peopleInside);

        /**
         * @brief recalculate value of concentration CO2 inside the room
         *
         * @param co2Const1 represents first concentration CO2 constant value used for caluclations of conditions
         * @param co2Const2 represents first concentration CO2 constant value used for caluclations of conditions
         * @param ventStatus represent current On/Off status of ventilation system in the room
         * @param peopleInside represent number of people which are currently in the room
         */
        void recalculateInsideConcentrationCO2(double co2Const1, double co2Const2, bool ventStatus, double peopleInside);

        /**
         * @brief recalculate value of humidity inside the room
         *
         * @param humConst1 represents first humidity constant value used for caluclations of conditions
         * @param ventStatus represent current On/Off status of ventilation system in the room
         * @param peopleInside represent number of people which are currently in the room
         */
        void recalculateInsideHumidity(double humConst1, bool ventStatus, double peopleInside);

        /**
         * @brief get  room name.
         * @return string value of room name.
         */
        std::string getRoomName();

        /**
         * @brief get room's inside temperature value.
         * @return Temperature object.
         */
        Temperature getTempInside();

        /**
         * @brief get room's inside concentration CO2 value.
         * @return ConcentrationCO2 object.
         */
        ConcentrationCO2 getCO2Inside();

        /**
         * @brief get room's inside humidity value.
         * @return Humidity object.
         */
        Humidity getHumInside();

        /**
         * @brief get room's outside temperature value.
         * @return Temperature object.
         */
        Temperature getTempOutside();

        /**
         * @brief get room's outside concentration CO2 value.
         * @return ConcentrationCO2 object.
         */
        ConcentrationCO2 getCO2Outside();

        /**
         * @brief get room's outside humidity value.
         * @return Humidity object.
         */
        Humidity getHumOutside();

        /**
         * @brief get room's control panel values.
         * @return ControlPanel object.
         */
        ControlPanel getControlPanel();

    private:
        /**
         * Group of all internal and external conditions assigned to this room
         */
        std::string roomName;
        Temperature tempInside;
        ConcentrationCO2 co2Inside;
        Humidity humInside;
        Temperature tempOutside;
        ConcentrationCO2 co2Outside;
        Humidity humOutside;
        ControlPanel controlPanel;
};

#endif // ROOM_H
