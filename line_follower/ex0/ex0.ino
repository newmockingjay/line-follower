/*line following robot.
   This code created by the SriTu Hobby team.
   https://srituhobby.com
*/

#define left A0
#define center A2
#define right A1

//motor one
// #define ENA 9
#define IN1 6
#define IN2 11

//motor two
// #define ENB 10
#define IN3 9
#define IN4 10

int Speed = 100; // speed of this robot

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);

  // pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // pinMode(ENB, OUTPUT);
}

void loop() {
  bool leftV = digitalRead(left);
  bool centerV = digitalRead(center);
  bool rightV = digitalRead(right);

  leftV = !leftV;
  centerV = !centerV;
  rightV = !rightV;

  Serial.println(centerV);


  if (leftV == 1 && centerV == 0 && rightV == 1) {
    carforward();
    Serial.println("forward");
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carturnleft();
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnright();
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnleft();
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnright();
  }
}

void carforward() {
  // analogWrite(ENA, Speed);
  // analogWrite(ENB, Speed);
  analogWrite(IN1, Speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, Speed);
  analogWrite(IN4, 0);
}
void carturnleft() {
  // analogWrite(ENA, Speed);
  // analogWrite(ENB, Speed);
  analogWrite(IN1, 0);
  analogWrite(IN2, Speed);
  analogWrite(IN3, Speed);
  analogWrite(IN4, 0);
}
void carturnright() {
  // analogWrite(ENA, Speed);
  // analogWrite(ENB, Speed);
  analogWrite(IN1, Speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, Speed);
}
void carStop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}