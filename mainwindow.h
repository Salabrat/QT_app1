#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_digitButton_clicked();
    void on_operatorButton_clicked();
    void on_equalsButton_clicked();
    void on_addButton_clicked();
    void on_subtractButton_clicked();
    void on_multiplyButton_clicked();
    void on_divideButton_clicked();

private:
    void connectSignalsAndSlots();

    Ui::MainWindow *ui;
    double currentResult;
    QString currentOperator;
    bool isOperatorClicked;
};

#endif // MAINWINDOW_H
