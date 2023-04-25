const int SWpin = 2;
const int xPin = A0;
const int yPin = A1;
//Defualt values for stick's default positon (may need adjustment)
const int defaultX = 506; 
const int defaultY = 500;
const int limit = 350;
int x;
int y;
int input;

void setup() {
  pinMode(SWpin, INPUT);
  Serial.begin(9600);
  digitalWrite(SWpin, HIGH);
}

void loop() {
  x = analogRead(xPin) - defaultX;
  y = analogRead(yPin) - defaultY;
  /*
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.print(y);
  Serial.println("");
  */
  
  input = WASD(x, y);
  Serial.println(input);
  delay(10);
}

int WASD(int x, int y) { //1:W, 2:A, 3:S, 4:D, 0:null
  if(abs(x) > limit || abs(y) > limit) { //Outside dead zone 
    if(abs(x) > abs(y)) { //If x is greater than y
      if(x > 0) {
        return 4; //D
      }
      return 2; //A
    }
    if(y > 0) {
      return 3; //S
    }
    return 1; //W
  }
  return 0;
}
