
# Speed Warning LED

Speed Warning LED is a project that utilizes an ESP32 microcontroller to monitor vehicle speed using an ultrasonic sensor. The system triggers an LED warning light when the vehicle speed exceeds a predefined threshold. This project demonstrates basic speed measurement and alert systems for vehicles using inexpensive and readily available components.


## Components Used
- **ESP32 Development Board**: Handles sensor data processing and controls the LED.
- **HC-SR04 Ultrasonic Sensor**: Measures the distance to estimate speed.
- **LED**: Lights up to signal when the speed exceeds the set threshold.
- **Resistors**: Used for current limiting and voltage division in the circuit.

## Features
- Measures speed based on distance readings from the ultrasonic sensor.
- Compares the measured speed with a predefined threshold.
- Activates an LED when the speed exceeds the threshold.
- Serial output for debugging and monitoring speed values.

## Circuit Diagram
*(Include your circuit diagram image here)*

## Code Overview
The project code is written in Arduino C++. It performs the following functions:

**Setup:**
- Initializes pins for the ultrasonic sensor and LED.
- Configures serial communication.

**Loop:**
- Sends a pulse to the ultrasonic sensor to start measurement.
- Reads the duration of the echo pulse to calculate distance.
- Converts distance to speed.
- Compares the calculated speed to the predefined threshold.
- Controls the LED based on the speed comparison.

## Installation
1. **Clone the Repository:**
    ```bash
    git clone https://github.com/LeaWeiss206/Speed-Warning-LED.git
    ```

2. **Install Dependencies:**
    Ensure you have PlatformIO installed in Visual Studio Code.

3. **Build and Upload Firmware:**
    - Open the project in Visual Studio Code.
    - Use PlatformIO to build and upload the firmware to your ESP32 board. This can be done through the PlatformIO interface in VS Code by clicking on the "Build" and "Upload" buttons.

4. **Run the Project:**
    After uploading, the ESP32 will start measuring speed and controlling the LED based on the configured threshold.

## Configuration
- **Threshold Value**: Modify the `speedThreshold` variable in the code to set the speed limit for activating the LED.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgements
Thanks to the open-source community and resources that supported the development of this project.

## Project Demo
You can view and interact with the project online here: [Wokwi Project Demo](https://wokwi.com/projects/404193549640837121).
