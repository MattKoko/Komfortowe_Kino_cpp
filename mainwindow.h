/** @file mainwindow.h
 *  @brief Interface and function prototypes for the main window.
 *  Generated by QTCVreator tool
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief MainWindow is a class generated by QTCreator tool and extended by additional funonalities.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor.
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief MainWindow destructor.
     */
    ~MainWindow();

private slots:
    /**
     * @brief MainWindow constructor.
     */
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    /**
     * @brief method used to get double value from targeted line edit field.
     * @param lineEdit from which double should be pulled
     * @return double value pulled from QLineEdit object
     */
    double getDoubleFromQLineEdit(QLineEdit *lineEdit);

    /**
     * @brief method used to get boolean value from targeted radio button.
     * @param radioButton from which status should be pulled
     * @return boolean value pulled from QRadioButton object
     */
    bool getRadioButtonChecked(QRadioButton *radioButton);
};
#endif // MAINWINDOW_H
