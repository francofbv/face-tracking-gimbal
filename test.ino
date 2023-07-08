#include <Servo.h>

int yaw_servo_pin = 3;
int pitch_servo_pin = 9;

Servo yaw_servo;
Servo pitch_servo;

void setup(){
  Serial.begin(9600);
  yaw_servo.attach(yaw_servo_pin);
  pitch_servo.attach(pitch_servo_pin);

  pitch_servo.write(90);
//  delay(5000);
//  pitch_servo.write(0);
//  pitch_servo.write(0);
}
void loop(){
  int x = 90;
  int y = 90;
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    String coords = input.substring(1,input.length() - 1);
    coords.trim();
    int comma_index = input.indexOf(',');
    if (comma_index >= 0) {
      String x_string = input.substring(1, comma_index);
      String y_string = input.substring(comma_index + 1);

      x = x_string.toInt();
      y = y_string.toInt();
     // Serial.println("x: " + x_string);
     // Serial.println("y: " + y_string);
  }
  int servo_yaw_value = map(x, 0, 640, 0, 180);
  int servo_pitch_value = map(y, 0, 480, 0, 90);

  yaw_servo.write(servo_yaw_value);
  pitch_servo.write(servo_pitch_value);
//  if (x < 295) {
//      int yawAngle = map(x, 0, 295, 180, 90);
//      yaw_servo.write(yawAngle);  // Assuming you have a servo named "yaw_servo"
//      //Serial.println("moving left");
//    } else if (x > 345) {
//      int yawAngle = map(x, 345, 640, 90, 0);
//      yaw_servo.write(yawAngle);  // Assuming you have a servo named "yaw_servo"
//      //Serial.println("moving right");
//
//    }
//
//    // Adjusting the pitch
//   if (y < 220) {
//      int pitchAngle = map(y, 0, 220, 0, 90);
//      pitch_servo.write(pitchAngle);  // Assuming you have a servo named "pitch_servo"
//      Serial.println("moving up");
//   } else if (y > 260) {
//      int pitchAngle = map(y, 260, 480, 90, 180);
//      pitch_servo.write(pitchAngle);  // Assuming you have a servo named "pitch_servo"
//      Serial.println("moving down");
//    }
  }
//void process_input(String input) {
//  int comma_index = input.indexOf(',');
//  if (comma_index >= 0) {
//    String x_string = input.substring(0, comma_index);
//    String y_string = input.substring(comma_index + 1);
//
//    int x = x_string.toInt();
//    int y = y_string.toInt();
//  }
}
