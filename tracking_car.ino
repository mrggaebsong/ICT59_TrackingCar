int enA = 10; //left motor
int in1 = 9;
int in2 = 8;
int enB = 5; //right motor
int in3 = 6;
int in4 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void moveForward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 120);
  analogWrite(enB, 140);

}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 30);
  analogWrite(enB, 100);

}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 30);
  analogWrite(enB, 100);

}

void STOP() {
  moveForward();
  delay(2000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void turntoleft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 120);
  analogWrite(enB, 120);

}

void turntoright() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 120);
  analogWrite(enB, 120);

}

void move2() {
  turnLeft(); delay(100);
  turnRight(); delay(100);
}

void loop() {
 int left_sensor = analogRead(A0); //black 50-100 white 240-285
  int right_sensor = analogRead(A3);//black 40-180 white 215-230

  Serial.print(left_sensor);
  Serial.print(" ");
  Serial.print(right_sensor);
  Serial.println(" ");

  if (left_sensor > 300 && right_sensor > 300) 
     {
        moveForward();
     }
    
   if (left_sensor < 600)
    { 
      turntoleft();
    }
    if (right_sensor < 200 )
    { 
      turntoright();
    }

  //else STOP();
 
}
    
    
    /*else if(left_sensor1 <= 100 && right_sensor2 <= 100){
      STOP();
      }*/
  
