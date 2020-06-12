#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo myservo;

// FORWARD
void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// BACKWARD
void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

// RIGHT
void right() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

// LEFT
void left() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

// RIGHT FORWARD
void right_forward() {
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
}

// LEFT FORWARD
void left_forward() {
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
}

// RIGHT BACKWARD
void right_backward() {
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);
}

//LEFT BACKWARD
void left_backward() {
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
}

// RIGHT ROTATE
void right_rotate() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

// LEFT ROTATE
void left_rotate() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

// Initialize variables
int movement;
int byte_number;
int action;
 
void setup() {
  Serial.begin(9600);

  myservo.attach(9);

  // Set up the speed for 4 motors
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
      
}

void loop() { 
  // Read the incoming data from SoccerBot App
  while (Serial.available()) {
    byte_number = Serial.read();
    if (byte_number >= 48 & byte_number <= 57 ) {
      movement = byte_number;
    }
    else {
      action = byte_number;
    }
  }
  delay(10);

  // Movements
  if (movement == '1') {
    forward();
  }
  else if (movement == '2') {
    backward();
  }
  else if (movement == '3') {
    right();
  }
  else if (movement == '4') {
    left();
  }
  else if (movement == '5') {
    right_forward();  
  }
  else if (movement == '6') {
    left_forward();
  }
  else if (movement == '7') {
    right_backward();
  }
  else if (movement == '8') {
    left_backward();
  }
  else if (movement == '0') {
    right_rotate();
  }
  else if (movement == '9') {
    left_rotate();
  }

  // Actions
  if (action == 'L') {     
    myservo.write(60);              // Servo at 30 degree angle to the left
  }
  else if (action == 'M') {
    myservo.write(90);              // Servo at 0 degree angle 
  }
  else if (action == 'R') {
    myservo.write(120);             // Servo at 30 degree angle to the right
  }
  else if (action == 's') {
    
  }
  

   
}
