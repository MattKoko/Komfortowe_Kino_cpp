/** @file controlpanel.h
 *  @brief Interface and function prototypes for the control panel.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

/**
 * @brief ControlPanel represents control panel of the room.
 */
class ControlPanel
{
public:
    /**
     * @brief ControlPanel constructor
     *
     * @param peopleInside represents number of people currently located in the room.
     * @param ventilationSystemStatus represents current On/Off status of ventilation system in the room.
     */
    ControlPanel(double peopleInside, bool ventilationSystemStatus);

    /**
     * @brief get number of people currently located in the room.
     * @return double number of people.
     */
    double getNumberOfPeopleInside();

    /**
     * @brief get current On/Off status of ventilation system in the room.
     * @return bool value.
     */
    bool getVentilationStatus();
private:
    /**
     * double value which represents current number of people inside the room.
     */
    double numberOfPeopleInside;

    /**
     * bool value which represents current On/Off status of ventilation system in the room.
     */
    bool ventilationSystemOnOff;
};

#endif // CONTROLPANEL_H
