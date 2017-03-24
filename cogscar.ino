int leftBackMotor = 7;
int rightBackMotor = 6; 
int rightFrontMotor = 5;
int leftFrontMotor = 4; 
int led = 13; 

 
void setup() 
{ 
  pinMode(leftFrontMotor, OUTPUT);
  pinMode(rightFrontMotor, OUTPUT);
  pinMode(leftBackMotor, OUTPUT);
  pinMode(rightBackMotor, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 
} 
 
 
void loop() 
{ 
  //analogWrite(rightBackMotor, 255);
  //analogWrite(leftBackMotor, 255);
  //analogWrite(rightFrontMotor, 255);
  //analogWrite(leftFrontMotor, 255);

  /*
  if (Serial.available())
  {
    int command = Serial.parseInt();
    Serial.println(command);
    switch (command) { 
      case 1: 
        analogWrite(leftFrontMotor, 255);
        break; 
      case 2: 
        analogWrite(rightFrontMotor, 255);
        break;
      case 3: 
        analogWrite(leftBackMotor, 255);
        break; 
      case 4: 
        analogWrite(rightBackMotor, 255);
        break; 
      case 0: 
        analogWrite(rightBackMotor, 0);
        analogWrite(leftBackMotor, 0);
        analogWrite(rightFrontMotor, 0);
        analogWrite(leftFrontMotor, 0);
        break; 

    
    }
   
  }
  */
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    Serial.println('setting'+speed); 
    if (speed >= 0 && speed <= 255)
    {
      if (speed != 255)
      { 
        digitalWrite(led, HIGH); 
      }
      else
      {
        digitalWrite(led, LOW); 
      }
      analogWrite(rightBackMotor, speed);
      analogWrite(leftBackMotor, speed);
      analogWrite(rightFrontMotor, speed);
      analogWrite(leftFrontMotor, speed);
    }
  }
  
} 
