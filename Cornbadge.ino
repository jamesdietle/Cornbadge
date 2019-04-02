#cornbadge
# Flattire

// The cornbadge

//Brightness is has indepentdent values 
// for each led
  int brightness0 = 0;
  int brightness1 = 75;
  int brightness2 = 150;
  int brightness3 = 225;
  int brightness4 = 250;

  long randNumber;

// Fade is how big the steps for everything 
// changing
  int fadeAmount0 = 5;
  int fadeAmount1 = 5;
  int fadeAmount2 = 5;
  int fadeAmount3 = 5;
  int fadeAmount4 = 5;

//How quick the fade occurs
  int startdelay=50;

//Which routine is being run
  int routine = 1;

//Sets up when reset
void setup(){                
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);   
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

// Get a random
  randomSeed(analogRead(0));
  routine =random(4);
//Chooses which routine
  switch(routine){
    //Normal
    case 0:
      break;
    case 1: ///lights all start full
      brightness0 = 0;
      brightness1 = 0;
      brightness2 = 0;
      brightness3 = 0;
      brightness4 = 0;
      break;
    case 2: //lights move faster
      fadeAmount0 = 15;
      fadeAmount1 = 15;
      fadeAmount2 = 15;
      fadeAmount3 = 15;
      fadeAmount4 = 15;  
      break;  
    case 3:
      startdelay = 10; //fast
      break;
    case 4:
      startdelay = 100; //Slow
      break; 
  }
}

// the loop routine runs over and over again forever:
void loop(){
  light();
  delay(startdelay);
  changeBrightnessAll();   
}

// Makes the change to the led
void light(){
  analogWrite(0, brightness0);
  analogWrite(1, brightness1);
  analogWrite(2, brightness2);
  analogWrite(3, brightness3);
  analogWrite(4, brightness4);
}

//Changes the brightness for each led and stores it
void changeBrightness(int &led, int &fade) {
  led = led + fade;
  
  if (led <= 0 || led >= 255) {
    fade = -fade;
  }
}

//Changes all the leds brightness and fades
void changeBrightnessAll(){
  changeBrightness(brightness0, fadeAmount0);
  changeBrightness(brightness1, fadeAmount1);
  changeBrightness(brightness2, fadeAmount2);
  changeBrightness(brightness3, fadeAmount3);
  changeBrightness(brightness4, fadeAmount4);
}