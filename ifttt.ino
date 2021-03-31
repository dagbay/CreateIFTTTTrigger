int photo_resistor = A1;
int photo_resistor_power = A0;

void setup() {
    
    pinMode(photo_resistor, INPUT);
    pinMode(photo_resistor_power, OUTPUT);
    
    digitalWrite(photo_resistor_power, HIGH);
}

void loop() {
    int light_level = analogRead(photo_resistor);
    int i = 1;
    
    if (light_level > i) Particle.publish("sun", "up", PRIVATE);
    if (light_level < i) Particle.publish("sun", "down", PRIVATE);
    
    delay(10000);
}
