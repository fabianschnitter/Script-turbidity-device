//constants
#define ANALOG_SENSOR_PIN  A0 
#define DIGITAL_SENSOR_PIN 3
#define LASER    13

//variables
int  switch_state;
int  LightAnalogValue;
int timer=5;                      //sets_the_timer_in_hours
int datapoint_delay = 10;       //everyxseconds

int timer_sec = timer*3600;
int actual_timer;
       

void setup() 
{
  pinMode(LASER, OUTPUT);
  Serial.begin(9600);          // Enable the Serial data output
  Serial.println("I am your turbidity measurement device");
  Serial.println("values between 0(super turbid) and 1023(transparent)");
  Serial.println("measured blanks without nothing in there:");
  Serial.println("UV cuvette 200 uL: 351");
  Serial.println("big HPLC vial: 246");
  Serial.println("small HPLC vial: 263");
  Serial.println("measurement started");
  Serial.print("datapoint every:");
  Serial.println(datapoint_delay);

}


void loop()
{
    digitalWrite(LASER, HIGH);

  LightAnalogValue = analogRead(ANALOG_SENSOR_PIN);  //Read the voltage from sensor
  Serial.println(LightAnalogValue,DEC);      // Send result to Serial Monitor
  actual_timer = actual_timer+datapoint_delay;
   if (actual_timer == timer_sec)
   {
    digitalWrite(LASER, LOW);
   }
  delay(datapoint_delay*1000); // Set datainterval here in ms (60 000 = 1 minute) 
  
}
