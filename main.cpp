#include <Arduino.h>
#include <ArrayList.h>
#include <AccelStepper.h>
#define DRIVER 1

AccelStepper stepper(DRIVER, 6, 5);

ArrayList<int> numbers;
String input = "";
int position;
int screwDetected;

void setup() {
  Serial.begin(9600);
  input.reserve(256);  // Reserve enough for many lines
  stepper.setMaxSpeed(500);  // steps per second
  stepper.setAcceleration(250); // steps/sec^2
  stepper.setCurrentPosition(0);
  stepper.moveTo(9);
  stepper.runToPosition();
  stepper.setCurrentPosition(0);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  if (Serial.available()) {
    input = Serial.readStringUntil('~');
    input.trim();
    Serial.print("Input received: ");
    Serial.println(input);  // Print the raw input to see what's being received
    numbers.clear();  // Clear old data

    int startIndex = 0;
    int endIndex;

    while ((input.length() > 0)&&(endIndex = input.indexOf(',', startIndex)) != -1) {
      String numStr = input.substring(startIndex, endIndex);
      numbers.add(numStr.toInt());
      startIndex = endIndex + 1;
    }

    // Add the last number (after the final comma or if no comma exists)
    if (startIndex < input.length()) {
      numbers.add(input.substring(startIndex).toInt());
    }
    Serial.println();
    delay(1000);
    for (int i = 0; i < numbers.size(); i++) {
        int turnPosition = numbers.get(i);
      turnPosition = turnPosition%12;
      position = turnPosition*16.6666;
      stepper.moveTo(position);
      stepper.runToPosition();
      screwDetected=digitalRead(7);
        while(screwDetected!=LOW){
            screwDetected=digitalRead(7);
        }
      delay(200);
    }
  }
  stepper.moveTo(0);
  stepper.runToPosition();
}