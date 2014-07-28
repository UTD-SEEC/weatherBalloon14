/*
  Multple serial test
 
  Receives from the main serial port, sends to the others. 
  Receives from serial port 1, sends to the main serial (Serial 0).
 
  The circuit: 
  * Any serial device attached to Serial port 1
  * Serial monitor open on Serial port 0:
 
  created 30 Dec. 2008
  by Your Mom
 
  This example code is in the public domain.
 
*/
#import "math.h"

int s = 100;
float t1Measure = 0;
float t2Measure = 0;
float pMeasure = 0;
float rH = 0;
float altMeasure = 0;



void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
  
}

void loop() {
  // read from port 1, send to port 0:
  Serial.println("PARM:BoxTempVoltage,AirTempVoltage,RelativeHumidity,null,null");//Pressure,RelativeHumidity,Altitude");
  Serial.println("UNIT:Volts,Volts,Volts,null,null");
  Serial.println("EQNS:0,0.01,0,0,0.01,0,0,0.01,0,0,0,0,0,0,0");
  Serial1.println(":PARM.BoxTempVoltage,AirTempVoltage,RelativeHumidity,null,null");//Pressure,RelativeHumidity,Altitude");
  Serial1.println(":UNIT.Volts,Volts,Volts,null,null");
  Serial1.println(":EQNS.0,0.01,0,0,0.01,0,0,0.01,0,0,0,0,0,0,0");
  for(int i = 0;i<50;i++){
    
    //external temp
    t1Measure = 3.3*analogRead(A1)*100/4096;
    t2Measure = 3.3*analogRead(A2)*100/4096;
    pMeasure = 3.3*analogRead(A4)*100/4096;
    rH = 3.3*analogRead(A0)*100/4096;
    altMeasure = 3.3*analogRead(A5)*100/4096;
    //R2 = (47000*t2measure)/(3.3-t2measure);
    //t2 = 1/(0.074743-0.009648*(logf(R2))/(log(2.71819))+C*(logf(R2)/log(2.71819))*(logf(R2)/log(2.71819))*(logf(R2)/log(2.71819)));
    //temp = log(1000);
    
    Serial.println("T#" + String(s) + "," + (int)t1Measure + "," + (int)t2Measure + "," + /*(int)pMeasure + "," + */(int)rH + ",000,000,00000000");// + (int)altMeasure + ",00000000");
    Serial1.println("T#" + String(s) + "," + (int)t1Measure + "," + (int)t2Measure + "," + /*(int)pMeasure + "," + */(int)rH + ",000,000,00000000");// + (int)altMeasure + ",00000000");
    s++;
    delay(30000);
  }
}
