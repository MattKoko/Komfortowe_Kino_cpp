/** @file mainwindow.cpp
 *  @brief implementation of MainWindow class.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "simulation.h"
#include "controlpanel.h"
#include "room.h"
#include "cinema.h"
#include <QLineEdit>
#include <QRadioButton>
#define _GLIBCXX_USE_CXX11_ABI 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    Temperature* tempInside = new Temperature(getDoubleFromQLineEdit(ui->tempInEdit), "C°"); // temperatura wewnątrzna pomieszczenia w stopniach Celsjusza
    ConcentrationCO2* co2Inside = new ConcentrationCO2(getDoubleFromQLineEdit(ui->concCO2InEdit), "PPM"); // stężenie CO2 wewnątrzne w pomieszczeniu w ppm
    Humidity* humInside = new Humidity(getDoubleFromQLineEdit(ui->HumiInEdit), "%"); // wilgotność wewnątrzna w pomieszczenia w procentach
    Temperature* tempOutside = new Temperature(getDoubleFromQLineEdit(ui->tempOutEdit), "C°"); // temperatura zewnętrzna w stopniach Celsjusza
    ConcentrationCO2* co2Outside = new ConcentrationCO2(getDoubleFromQLineEdit(ui->concCO2OutEdit), "PPM"); // stężenie CO2 zewnęterzna w ppm
    Humidity* humOutside = new Humidity(getDoubleFromQLineEdit(ui->HumiOutEdit), "%"); // wilgotność zewnęterzna w procentach

    std::string roomName = "Sala Horrorów";
    ControlPanel* controlPanel = new ControlPanel(getDoubleFromQLineEdit(ui->PeopleCountInEdit), getRadioButtonChecked(ui->ventilationRadioButton));
    Room* room = new Room(roomName, *tempInside, *co2Inside, *humInside, *tempOutside, *co2Outside, *humOutside, *controlPanel);

    //Tworzenie obiektu klasy Cinema tylko w celu zaprezentowania możliwości kodu
    std::list<Room> listOfRooms;
    listOfRooms.push_back(*room);
    Cinema* cinema = new Cinema(listOfRooms);

    double simulationTime = getDoubleFromQLineEdit(ui->simulationTimeEdit); // czas symulacji podany w minutach

    Simulation* simulation = new Simulation();
    simulation->recalculateConditions((cinema->getRoomByName(roomName)), simulationTime, ui->listWidgetSimulationOutput);
}

double MainWindow::getDoubleFromQLineEdit(QLineEdit* lineEdit) {
    QString text = lineEdit->text();
    return text.toDouble();
}

bool MainWindow::getRadioButtonChecked(QRadioButton* radioButton) {
    return radioButton->isChecked();
}

void MainWindow::on_pushButton_2_clicked() {
    ui->tempInEdit->setText("25");
    ui->concCO2InEdit->setText("1000");
    ui->HumiInEdit->setText("50");
    ui->tempOutEdit->setText("20");
    ui->concCO2OutEdit->setText("900");
    ui->HumiOutEdit->setText("70");
    ui->ventilationRadioButton->setChecked(false);
    ui->PeopleCountInEdit->setText("100");
    ui->simulationTimeEdit->setText("10");
}

void MainWindow::on_pushButton_3_clicked() {
    ui->tempInEdit->setText("20");
    ui->concCO2InEdit->setText("950");
    ui->HumiInEdit->setText("30");
    ui->tempOutEdit->setText("30");
    ui->concCO2OutEdit->setText("1050");
    ui->HumiOutEdit->setText("90");
    ui->ventilationRadioButton->setChecked(true);
    ui->PeopleCountInEdit->setText("78");
    ui->simulationTimeEdit->setText("120");
}


void MainWindow::on_pushButton_4_clicked(){
    ui->tempInEdit->setText("20");
    ui->concCO2InEdit->setText("1050");
    ui->HumiInEdit->setText("70");
    ui->tempOutEdit->setText("0");
    ui->concCO2OutEdit->setText("900");
    ui->HumiOutEdit->setText("30");
    ui->ventilationRadioButton->setChecked(false);
    ui->PeopleCountInEdit->setText("5");
    ui->simulationTimeEdit->setText("180");
}


void MainWindow::on_pushButton_5_clicked(){
    ui->tempInEdit->setText("35");
    ui->concCO2InEdit->setText("1050");
    ui->HumiInEdit->setText("90");
    ui->tempOutEdit->setText("0");
    ui->concCO2OutEdit->setText("980");
    ui->HumiOutEdit->setText("20");
    ui->ventilationRadioButton->setChecked(true);
    ui->PeopleCountInEdit->setText("342");
    ui->simulationTimeEdit->setText("145");
}

