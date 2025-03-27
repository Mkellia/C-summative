#include <IRremote.h>

#define RELAY_PIN 7   
#define IR_PIN 2     

IRrecv irrecv(IR_PIN);
decode_results results;

bool lightState = false; 

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); 
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); 

        // Assuming ON button sends 0xFFA25D and OFF sends 0xFF629D
        if (results.value == 0xFFA25D) {  
            lightState = !lightState;
            digitalWrite(RELAY_PIN, lightState ? HIGH : LOW);
            Serial.println(lightState ? "Light ON" : "Light OFF");
        }

        irrecv.resume(); 
    }
}

