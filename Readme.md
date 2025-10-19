# Smart Assistant Robot - Arduino & Python Prototype

This repository contains the source code for building and testing a Smart Assistant Robot, as conceptualized in the project video. The project is broken down into individual hardware test sketches for the Arduino platform and a Python-based voice control simulator.

## 🤖 Project Overview

The goal of this project is to create a semi-autonomous robot for educational spaces. Its core functions include:
-   **Mobility**: Moving and avoiding obstacles.
-   **Environmental Sensing**: Monitoring temperature, humidity, and light.
-   **Command Response**: Responding to external commands (initially via Bluetooth, simulated with voice in Python).

This repository provides the foundational code to test each hardware component individually before integrating them into a final, unified project.

---

## Arduino Hardware Tests

The `arduino_tests` directory contains separate sketches for testing each major component of the robot. This is crucial for debugging and ensuring each part works before combining them.

### Folders:
-   **`1_Ultrasonic_Sensor_Test`**: Tests the HC-SR04 distance sensor.
-   **`2_Motor_Driver_Test`**: Tests the L298N motor driver and DC motors.
-   **`3_DHT11_Sensor_Test`**: Tests the DHT11 temperature and humidity sensor. (*Requires Adafruit DHT library*).
-   **`4_LDR_Sensor_Test`**: Tests the Light Dependent Resistor (LDR) for ambient light.
-   **`5_Bluetooth_Module_Test`**: Tests the HC-05/HC-06 Bluetooth module for receiving commands.

### How to Use:
1.  Navigate to the desired test folder.
2.  Open the `.ino` file in the Arduino IDE.
3.  Wire your components according to the connection guide in the code's comments.
4.  Upload the sketch to your Arduino and open the Serial Monitor at 9600 baud to see the output.

---

## 🐍 Python Voice Control Simulator

The `python_simulator` directory contains a script to simulate the robot's logic and control it using voice commands from your computer's microphone.

### Setup:
1.  Ensure you have Python installed.
2.  Install the required libraries by running:
    ```sh
    pip install SpeechRecognition PyAudio
    ```
3.  Save the dependencies to a `requirements.txt` file for easy installation by others:
    ```sh
    pip freeze > requirements.txt
    ```

### How to Run:
1.  Navigate to the `python_simulator` directory.
2.  Run the script from your terminal:
    ```sh
    python voice_robot_simulator.py
    ```
3.  Allow microphone access if prompted.
4.  Speak commands like "forward", "stop", "turn left", "turn right", or "exit".

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
