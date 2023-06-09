#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentResult = 0.0;
    currentOperator = "";
    isOperatorClicked = false;
    connectSignalsAndSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_digitButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();
    QString currentText = ui->lineEdit->text();
    if (currentText == "0" || isOperatorClicked) {
        ui->lineEdit->setText(buttonText);
        isOperatorClicked = false;
    } else {
        ui->lineEdit->setText(currentText + buttonText);
    }
}

void MainWindow::on_operatorButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();
    currentResult = ui->lineEdit->text().toDouble();
    currentOperator = buttonText;
    isOperatorClicked = true;
}
void MainWindow::on_equalsButton_clicked()
{
    double secondOperand = ui->lineEdit->text().toDouble();
    double result = currentResult; // Используем текущий результат как исходное значение
    if (currentOperator == "+") {
        result += secondOperand;
    } else if (currentOperator == "-") {
        result -= secondOperand;
    } else if (currentOperator == "*") {
        result *= secondOperand;
    } else if (currentOperator == "/") {
        if (secondOperand != 0.0) {
            result /= secondOperand;
        } else {
            ui->lineEdit->setText("Error: Division by zero");
            return;
        }
    }
    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_addButton_clicked()
{
    currentResult = ui->lineEdit->text().toDouble();
    currentOperator = "+";
    isOperatorClicked = true;
}

void MainWindow::on_subtractButton_clicked()
{
    currentResult = ui->lineEdit->text().toDouble();
    currentOperator = "-";
    isOperatorClicked = true;
}

void MainWindow::on_multiplyButton_clicked()
{
    currentResult = ui->lineEdit->text().toDouble();
    currentOperator = "*";
    isOperatorClicked = true;
}

void MainWindow::on_divideButton_clicked()
{
    currentResult = ui->lineEdit->text().toDouble();
    currentOperator = "/";
    isOperatorClicked = true;
}

void MainWindow::on_clearButton_clicked()
{
    ui->lineEdit->setText("0");
    currentResult = 0.0;
    currentOperator = "";
    isOperatorClicked = false;
}

void MainWindow::connectSignalsAndSlots() //соединения сигналов и слотов для кнопок сложения, вычитания, умножения и деления.
{
    connect(ui->button0, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button5, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button6, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button7, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button8, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);
    connect(ui->button9, &QPushButton::clicked, this, &MainWindow::on_digitButton_clicked);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->subtractButton, &QPushButton::clicked, this, &MainWindow::on_subtractButton_clicked);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &MainWindow::on_multiplyButton_clicked);
    connect(ui->divideButton, &QPushButton::clicked, this, &MainWindow::on_divideButton_clicked);

    connect(ui->equalsButton, &QPushButton::clicked, this, &MainWindow::on_equalsButton_clicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
}
