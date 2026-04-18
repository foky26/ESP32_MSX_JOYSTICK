#include <Joystick_ESP32S2.h>

int arriba=37;
int abajo=38;
int derecha=40;
int izquierda=39;
int boton1=36;
int boton2=35;

int16_t simMin = -1;        // Set simulation minimum axes to zero.
int16_t axesCenter = 0;
int16_t simMax = 1;

// Create Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


void setup() {
  Serial.begin(9600);

  pinMode(arriba,INPUT_PULLUP);
  pinMode(abajo,INPUT_PULLUP);
  pinMode(derecha,INPUT_PULLUP);
  pinMode(izquierda,INPUT_PULLUP);
  pinMode(boton1,INPUT_PULLUP);
  pinMode(boton2,INPUT_PULLUP);
 
  Joystick.setXAxisRange(simMin, simMax);
  Joystick.setYAxisRange(simMin, simMax);

   Joystick.begin();
   


  delay(3000);
  

  
}

void loop() {

   
  


int e_arriba=digitalRead(arriba);
int e_abajo=digitalRead(abajo);
int e_derecha=digitalRead(derecha);
int e_izquierda=digitalRead(izquierda);
int e_boton1=digitalRead(boton1);
int e_boton2=digitalRead(boton2);

delay(30);

 e_arriba+=digitalRead(arriba);
 e_abajo+=digitalRead(abajo);
 e_derecha+=digitalRead(derecha);
 e_izquierda+=digitalRead(izquierda);
 e_boton1+=digitalRead(boton1);
 e_boton2+=digitalRead(boton2);


/*
Serial.print(e_arriba); Serial.print(" ");
Serial.print(e_abajo); Serial.print(" ");
Serial.print(e_derecha); Serial.print(" ");
Serial.print(e_izquierda);Serial.print(" ");
Serial.print(e_boton1);Serial.print(" ");
Serial.println(e_boton2);
*/

if (e_arriba==0) { Serial.println("ARRIBA");  Joystick.setYAxis(simMin);  delay(50);}
if (e_abajo==0) { Serial.println("ABAJO"); Joystick.setYAxis(simMax);  delay(50);}
if (e_derecha==0) { Serial.println("DERECHA"); Joystick.setXAxis(simMax); delay(50);}
if (e_izquierda==0) { Serial.println("IZQUIERDA"); Joystick.setXAxis(simMin);  delay(50);}
if (e_boton1==0) { Serial.println("BOTON1");Joystick.pressButton(1); delay(80);Joystick.releaseButton(1);delay(50);}
if (e_boton2==0) { Serial.println("BOTON2");Joystick.pressButton(0); delay(80);Joystick.releaseButton(0);delay(50);}


if ((e_arriba!=0) && (e_abajo!=0) && (e_derecha!=0) && (e_izquierda!=0)) {
  Joystick.setXAxis(axesCenter);
  Joystick.setYAxis(axesCenter);

}


}
