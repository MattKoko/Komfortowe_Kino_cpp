/** @file mainwindow.cpp
 *  @brief implementation of MainWindow class.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "simulation.h"
#include <QLineEdit>
#include <QRadioButton>
#define _GLIBCXX_USE_CXX11_ABI 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double temp_in = getDoubleFromQLineEdit(ui->tempInEdit); // temperatura wewnątrzna pomieszczenia w stopniach Celsjusza
    double co2_in = getDoubleFromQLineEdit(ui->concCO2InEdit); // stężenie CO2 wewnątrzne w pomieszczeniu w ppm
    double hum_in = getDoubleFromQLineEdit(ui->HumiInEdit); // wilgotność wewnątrzna w pomieszczenia w procentach
    double temp_out = getDoubleFromQLineEdit(ui->tempOutEdit); // temperatura zewnętrzna w stopniach Celsjusza
    double co2_out = getDoubleFromQLineEdit(ui->concCO2OutEdit); // stężenie CO2 zewnęterzna w ppm
    double hum_out = getDoubleFromQLineEdit(ui->HumiOutEdit); // wilgotność zewnęterzna w procentach
    bool ventOnOff = getRadioButtonChecked(ui->ventilationRadioButton); // status wlaczony/wylaczony systemu wentylacji
    double peopleInside = getDoubleFromQLineEdit(ui->PeopleCountInEdit); // ilosc osob w pomieszczeniu kina
    double simulationTime = getDoubleFromQLineEdit(ui->simulationTimeEdit); // czas symulacji podany w minutach

    Simulation simulation(temp_in, co2_in, hum_in, temp_out, co2_out, hum_out, ventOnOff, peopleInside);
    simulation.recalculateConditions(simulationTime, ui->listWidgetSimulationOutput);
}

double MainWindow::getDoubleFromQLineEdit(QLineEdit* lineEdit) {
    QString text = lineEdit->text();
    return text.toDouble();
}

bool MainWindow::getRadioButtonChecked(QRadioButton* radioButton) {
    return radioButton->isChecked();
}
