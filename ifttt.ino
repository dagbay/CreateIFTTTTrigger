int photo_resistor = A0;
int photo_resistor_power = A1;
int led = D7;

void setup() {
    
    // We provide the resistor and LED pins and set their pins.
    pinMode(photo_resistor, INPUT);
    pinMode(photo_resistor_power, OUTPUT);
    pinMode(led, OUTPUT);
    
    // We give the photo resistor power before we start.
    digitalWrite(photo_resistor_power, HIGH); 
}

void loop() {
    
    // Declare int variable light_level and always assign it with the latest values of photo_resistor.
    int light_level = analogRead(photo_resistor);
    // Declare int variable i for comparison against light_level.
    int i = 1;
    
    // If light level is greater than i, then publish to IFTTT that the sun is up.
    if (light_level > i) {
        Particle.publish("sun", "up", PRIVATE);
        // Let the user know by turning on the LED Light.
        digitalWrite(led, HIGH);
    }
    
    // Otherwise, if less than i, then publish to IFTTT that the sun is down.
    else if (light_level < i) {
        Particle.publish("sun", "down", PRIVATE);
        digitalWrite(led, LOW);
    }
    
    // Delay for 5 seconds.
    delay(5000);
}
