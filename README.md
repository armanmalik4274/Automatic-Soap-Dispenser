 # Automatic Soap Dispenser

This project is an implementation of an automatic soap dispenser using Embedded C programming, an ultrasonic sensor, and a stepper motor. The dispenser uses an ultrasonic sensor to detect the proximity of a user's hand and then activates a stepper motor to dispense soap.

## Components Used

- **LPC1768 Microcontroller**
- **Ultrasonic Sensor**: Used to detect the presence of a hand within a certain range.
- **Stepper Motor**: Used to control the dispensing mechanism.
- **Embedded C Programming**: The project is implemented in C using the LPC17xx library.

## Circuit Diagram

- **TRIG Pin**: Connected to P0.2 (configured as an output pin)
- **ECHO Pin**: Connected to P0.3 (configured as an input pin)
- **Stepper Motor Pins**: Connected to P0.4 - P0.7 (configured as output pins)

## How It Works

1. **Initialization**:
   - The system is initialized, and the timer is set up.
   - The ultrasonic sensor's TRIG pin is set to LOW initially.

2. **Distance Measurement**:
   - A 10 microsecond HIGH pulse is sent to the TRIG pin to start the measurement.
   - The ECHO pin receives the reflected signal, and the time is measured using a timer.
   - The distance is calculated based on the time taken for the pulse to return.

3. **Soap Dispensing**:
   - If the measured distance is less than 20 cm, the stepper motor is activated to dispense soap.
   - The motor rotates in a clockwise or anti-clockwise direction to control the dispensing mechanism.

## Code Explanation

The project includes several key functions:

- **initTimer0()**: Initializes Timer0 for delay calculations.
- **startTimer0()**: Starts the timer.
- **stopTimer0()**: Stops the timer and returns the elapsed time.
- **delayUS()**: Creates a delay in microseconds using Timer0.
- **delayMS()**: Creates a delay in milliseconds using Timer0.
- **clock_wise()**: Rotates the stepper motor clockwise.
- **anti_clock_wise()**: Rotates the stepper motor anti-clockwise.
- **main()**: The main function that continuously monitors the sensor and controls the dispensing process.

## Usage

1. **Setup the Hardware**: Connect the components as per the circuit diagram.
2. **Upload the Code**: Use an appropriate IDE (like Keil uVision) to compile and upload the code to the microcontroller.
3. **Power the Circuit**: Once powered, the system will automatically detect the presence of a hand and dispense soap accordingly.

## License

This project is open-source and available under the MIT License.

---
