#include <Wire.h>
#include <TinyMPU6050.h>

MPU6050 mpu (Wire);

void send_data() {
  delay(500);
}

void setup() 
{
  Serial.begin(9600);

  Serial.println("Calibration starting");
  mpu.Initialize();
  mpu.Calibrate();
  Serial.println("Calibration done");

}

void loop()
{
  mpu.Execute();

  // move forwards
  while (mpu.GetRawAccX() <= -8000) {
    Serial.println("going forwards");
    send_data();
    mpu.Execute();
  }

  // move backwards
  while (mpu.GetRawAccX() >= 8000) {
    Serial.println("going backwards");
    send_data();
    mpu.Execute();
  }

  // move left
  while (mpu.GetRawAccY() <= -8000) {
    Serial.println("going left");
    send_data();
    mpu.Execute();
  }

  // move right
  while (mpu.GetRawAccY() >= 8000) {
    Serial.println("going right");
    send_data();
    mpu.Execute();
  }

  while (mpu.GetRawAccX() < 8000 and mpu.GetRawAccX() > -8000 and mpu.GetRawAccY() < 8000 and mpu.GetRawAccY() > -8000) {
    Serial.println("not going");
    send_data();
    mpu.Execute();
  }
  
  delay(500);
}
