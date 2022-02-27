#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 
const int analogIn = A0; //current sensor pin A0
int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;
double Watt = 0;
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
void setup(){
  Serial.begin(9600);
   sensors.begin(); 


}
void loop(){
   
 RawValue = analogRead(analogIn);
 Voltage = (RawValue / 1024.0) * 5000; // Gets you mV
 Amps = ((Voltage - ACSoffset) / mVperAmp);
 Watt = ((Voltage/1000)*Amps); // the equation of the watt = voltage in (V)* amperes in (A)
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.print("V = "); // shows the voltage measured 
 Serial.print(Voltage/1000,2); //1000 to print voltage in V not mV,the '2' after voltage allows you to display 2 digits after decimal point
 Serial.print("   Amps = "); // shows the current measured 
 Serial.print(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("   Watt = "); //shows the Watt measured by the equation W = A*V
 Serial.print(Watt,4); //the '4' after voltage allows you to disblay 4 digits after decimal point
 Serial.print("   Temperature is: "); 
 Serial.println(sensors.getTempCByIndex(0));
  Serial.print("   Temperature 2 is: "); 
 Serial.println(sensors.getTempCByIndex(1));
 int sensorValue = A0;
 sensorValue = analogRead(A0);
 delay(2000);
}
