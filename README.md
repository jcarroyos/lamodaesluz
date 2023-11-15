# Pan-and-Tilt Servo Control System

This Arduino project controls a pan-and-tilt system using two servos, allowing synchronized movement based on potentiometer input. The system consists of a total of 6 modules, each equipped with 2 servos for a total of 12 servos. The pan (horizontal) and tilt (vertical) movements are controlled by potentiometers, providing an intuitive and user-friendly interface.

## Features:

- **Pan Servo Movement:** The pan movement is controlled by a potentiometer attached to analog pin A0. The system divides the analog input into three zones, mapping to left, center, and right servo positions.

- **Tilt Servo Movement:** The tilt movement is controlled by a separate potentiometer attached to analog pin A1. Similar to the pan movement, the analog input is divided into three zones, mapping to top, center, and down servo positions.

- **Synchronization:** The 12 servos across the 6 modules are synchronized, ensuring coordinated pan-and-tilt movements based on the potentiometer input.

- **Adjustable Speed:** The rotation speed of the servos is adjustable by modifying the delay in the code. A longer delay will slow down the rotation, and a shorter delay will speed it up.

## Hardware Requirements:

- Arduino board
- 6 pan-and-tilt modules (each with 2 servos)
- Potentiometers (2x)
- Jumper wires

## Usage:

1. Connect the pan potentiometer to analog pin A0.
2. Connect the tilt potentiometer to analog pin A1.
3. Attach the pan-and-tilt modules to your desired components.
4. Upload the code to your Arduino board.
5. Observe the synchronized pan-and-tilt movements based on potentiometer input.

## Functional prototype:
![Analog movements](./functional_prototype.jpg)
