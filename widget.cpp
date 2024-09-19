#include "widget.h"
#include "./ui_widget.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QWidget>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->turnOnButton, &QPushButton::pressed, this, &Widget::on_turnOnButton_pressed);
    connect(ui->turnOnButton, &QPushButton::released, this, &Widget::on_turnOnButton_released);


    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            // Compare the actual vendor and product IDs
            if (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id) {
                if (serialPortInfo.productIdentifier() == arduino_uno_product_id) {
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }


    if(arduino_is_available){
        //open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

    }else{
        QMessageBox::warning(this,"Port error","Couldn't find the Arduino");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_turnOnButton_pressed()
{
    if (arduino->isWritable()) {
        arduino->write("1"); // Send the command to turn on the LED
    } else {
        QMessageBox::warning(this, "Serial Port Error", "Couldn't write to the Arduino");
    }
}

void Widget::on_turnOnButton_released()
{
    if (arduino->isWritable()) {
        arduino->write("0"); // Send the command to turn off the LED
    } else {
        QMessageBox::warning(this, "Serial Port Error", "Couldn't write to the Arduino");
    }
}



