#include "mainwindow.h"
#include "simulation.h"
#include "temperature.h"
#include "humidity.h"
#include "concentrationco2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    double temp_in = 25.0; // temperatura wewnątrz pomieszczenia w stopniach Celsjusza
    double co2_in = 1000.0; // stężenie CO2 w pomieszczeniu w ppm
    double hum_in = 50.0; // wilgotność wewnątrz pomieszczenia w procentach
    double temp_out = 20.0; // temperatura na zewnątrz w stopniach Celsjusza
    double co2_out = 900.0; // stężenie CO2 w pomieszczeniu w ppm
    double hum_out = 70.0;
    bool ventOnOff = true;
    double peopleInside = 100;

    Simulation simulation(temp_in, co2_in, hum_in, temp_out, co2_out, hum_out, ventOnOff, peopleInside);
    simulation.recalculateConditions(25);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    return 0;
}
