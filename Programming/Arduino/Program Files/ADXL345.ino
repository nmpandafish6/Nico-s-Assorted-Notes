#include <Wire.h> //I2C library

//Sensor Data Variables
//Variables are set to measure using the default gravity as a unit.
//A value of 1 is approximately equal to 9.6 (meters / (seconds^2))
double x_axisAccel = 0.0, y_axisAccel = 0.0, z_axisAccel = 0.0;

/*
 *Setup Code Ran at System Start
 */
void setup() {
  //Initialize the output stream
  Serial.begin(9600);
  //Initialize the I2C bus
  Wire.begin();
  //Initialize the Accelerometer Device
  initAccel();
  //Print Default Output Text
  Serial.println(">>>>>>>>>>>>>>>>>>>");
  Serial.println("Time\tXAxis\tYAxis\tZAxis");
}

/*
 *Code run continuously once setup code has completed
 */
void loop() {
  //Read variables from the device and assign values to local variables
  read();
  double xAxis = getX();
  double yAxis = getY();
  double zAxis = getZ();
  long   time  = millis(); 
  //Print Values to output stream
  Serial.println(); 
  Serial.print(time);
  Serial.print("\t");
  Serial.print(xAxis);
  Serial.print("\t");
  Serial.print(yAxis);
  Serial.print("\t");
  Serial.print(zAxis);
}

/*
 *Initialization code for the Accelerometer
 */
void initAccel(){
   Wire.beginTransmission(0x53);//Accel Address
   Wire.write(0x2D);
   Wire.write(0x08);//Configures the POWER_CTL to start measuring
   Wire.endTransmission();
}

/*
 *Read command for the accelerometer device.
 *Also parses multi-byte data into human readable format.
 */ 
void read(){
  Wire.beginTransmission(0x53);
  Wire.write(0x32);
  Wire.requestFrom(0x53, 6);
  int buffer[6];
  int bufferNumber = 0;
  
  while(Wire.available()){
    buffer[bufferNumber] = Wire.read();
    bufferNumber++;
  }
  Wire.endTransmission();
  
  x_axisAccel = ((buffer[1] << 8) & 0xff00) | (buffer[0] & 0xff);
  y_axisAccel = ((buffer[3] << 8) & 0xff00) | (buffer[2] & 0xff);
  z_axisAccel = ((buffer[5] << 8) & 0xff00) | (buffer[4] & 0xff);  
}


/* 
 *Return functions for accelerometer data. Scales data so 
 *as to return values with the correct units.
 */

double getX(){
  return x_axisAccel * 0.004; 
}

double getY(){
  return y_axisAccel * 0.004; 
}

double getZ(){
  return z_axisAccel * 0.004; 
}
