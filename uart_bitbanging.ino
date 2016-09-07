#define DELAY_TIME 208-10
#define ENTER_VALUE 0xA
int calc_func_time;
int delaytime;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
 pinMode(10,OUTPUT);                //tx
 pinMode(11,INPUT);                 //rx
 digitalWrite(10,HIGH);
 delay(10);
 uint32_t time_start = millis();
for (int x = 0; x<100; x++)
{
  digitalWrite(10,LOW);
  digitalWrite(10,HIGH);
}
 uint32_t time_end = millis();
 calc_func_time = time_end - time_start;
 Serial.print("time_start");
 Serial.println(time_start);
 Serial.print("time_end");
 Serial.println(time_end);
 Serial.print("calc_func_time");
 Serial.println(calc_func_time);
 Serial.print("delaytime");
 Serial.println(delaytime);
 delaytime = DELAY_TIME-calc_func_time;
 void loop();
  }

  void transmit_via_uart(uint8_t data)
  {
    digitalWrite(10,LOW);
    delayMicroseconds(delaytime);
    
    for(int i = 0; i<8;i++)
    {
      if(((data>>i)& 0x01)==0)
      {
        digitalWrite(10,LOW);
      }
      else
      {
        digitalWrite(10,HIGH);
      }
      delayMicroseconds(delaytime);
    }
    digitalWrite(10,HIGH);
     
  }

void loop()
{ 
 
 int value = 0;
    
    value = Serial.read();
    if(value > 0 )
    {
    transmit_via_uart(value);
    }

  
}
