#include <Arduino.h>
#include "qpn.h"
#include "lcd.h"
#include "main.h"
#include "Clock_Alarm_SM.h"

void setup() {

}

void loop() {
 static uint32_t tick_time = millis();
 while (millis() - tick_time >= 50)  //every 50 ms
 {
   tick_time=millis();
   Q_SIG(Clock_Alarm_super) = TICK_SIG; 
   QHSM_DISPATCH(Clock_Alarm_super);
 }
 
}



static void Timer1_setup(void){
  TCCR1A = 0;                 //CTC mode            
  TCCR1B = B00001100;        //prescaler=256,CTC mode
  TIMSK1 |= B00000010;       //Interrupt enable for OCR1A compare match
  OCR1A = 6250-1;          //OC match value for 100ms time base generation
}



