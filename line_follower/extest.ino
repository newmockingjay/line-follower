
 int in1 = 6;
 int in2 = 11;
int in3 = 9;
int in4 = 10;
void setup() {
    // pinMode( ena, OUTPUT );
    // pinMode( enb, OUTPUT );
    pinMode( in1, OUTPUT );
    pinMode( in2, OUTPUT );
    pinMode( in3, OUTPUT );
    pinMode( in4, OUTPUT );

    analogWrite( in2, 0 );
    analogWrite( in4, 0 );

 
}
void loop() {
    //выставляем режим мотора - вращение по часовой
    analogWrite( in1, 80 );
    analogWrite( in3, 70 );

}