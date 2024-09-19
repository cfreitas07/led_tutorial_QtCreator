# LED Control Example Using Qt Creator

This project demonstrates how to control an LED using **Qt Creator** and **Arduino** via the `QSerialPort` library. The project involves creating a simple Qt application that sends signals to an Arduino to turn an LED on or off.

## Requirements

To run this project, you will need the following:

- **Qt Creator** (Version 14.0.1 or higher recommended)
- **Arduino Uno** (or similar)
- **CMake** (for building the project)
- **QSerialPort** library (included in Qt, but you may need to add it to your project)
- **LED** connected to pin D4 of the Arduino
- **Vendor and Product IDs**: You will need to find the vendor and product IDs of your Arduino board. In this project, we are using `vendor_id: 9025` and `product_id: 4098`, but your values may differ. For help finding these values, please refer to the [tutorial](https://claudiocsdefreitas.com/blog.html).

## About This Code

This project is part of a tutorial explaining how to set up a Qt project to control an LED via Arduino. The tutorial covers setting up the project, writing the necessary code, and configuring the serial port for communication. 

For detailed instructions on how to run this project, visit the full tutorial [here](https://claudiocsdefreitas.com/blog.html).

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
