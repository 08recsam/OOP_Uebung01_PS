
// ****************************************************************************
// *                                                                          *
// * Aufgabe:                                                                 *
// *                                                                          *
// * -> Schreib ein Programm mit folgenden Eigenschaften:                     *
// *    Es gibt zwei Taster (TASTER1, TASTER2), zwei LEDs (LED1, LED2) und    *
// *    ein Potentiometer. Taster1 schaltet einen digitalen Blinker auf die   *
// *    beiden LEDs, Taster2 schaltet einen analogen Blinker auf die beiden   *
// *    LEDs. Die Geschwindigkeit des Blinkers soll mit dem Poti zwischen     *
// *    50ms und 1000ms eingestellt werden können. Ein langer Tastendruck     *
// *    auf einen der beiden Taster toggelt die Blinkfunktion ein/aus.        *
// *                                                                          *
// * -> Suche dir ein/zwei Mitarbeiter und forke dieses Projekt               *
// * -> Teile die Arbeit auf die Mitarbeiter so auf, dass ein fast-forward-   *
// *    merge ermöglicht wird.                                                *
// * -> Fülle die bestehenden Header-Dateien und erzeuge die entsprechenden   *
// *    Implementierungen (cpp-Dateien). Verwende ausschließlich Klassen!     *
// *                                                                          *
// * -> Erstelle einen pull-request                                           *
// *                                                                          *
// *                                                                          *
// ****************************************************************************

#include <Arduino.h>

 #define LED1 5    // Low-side switch (leuchtet mit LOW)
 #define LED2 6    // High-side switch (leuchtet mit HIGH)
 #define TASTER1 3 // HIGH wenn gedrückt
 #define TASTER2 2 // LOW wenn gedrückt
 #define POTI A7   // Poti an A7
 
 #define DB_ZEIT 50
 #define BLINKTIME 300
 #define LONGPRESSTIME 1000
 
 #define ANALOGBLINKER_POLLTIME 10 // ms
 #define ANALOGBLINKER_MIN 100     // ms
 #define ANALOGBLINKER_MAX 3000    // ms
 
 void setup()
 {
     Serial.begin(115200);
     Serial.println("..Start..\n");
     pinMode(LED1, OUTPUT);
     pinMode(LED2, OUTPUT);
     pinMode(TASTER1, INPUT_PULLUP);
     pinMode(TASTER2, INPUT_PULLUP);
     pinMode(POTI, INPUT);
 }

 void loop()
 {
    taster1.init(TASTER1, INPUT_PULLUP, DB_ZEIT, LONGPRESSTIME);
    taster2.init(TASTER1, INPUT_PULLUP, DB_ZEIT, LONGPRESSTIME);

 }
 