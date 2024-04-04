
// #define DIR_LEFT         7 
// #define DIR_RIGHT        4 
// #define LEFT_SENSOR_PIN  A0 
// #define RIGHT_SENSOR_PIN A1 
#define IN1 6//r 
#define IN2 11 
#define IN3 9//l 
#define IN4 10   

#define SENSOR_RIGHT A1
#define SENSOR_CENTER A2
#define SENSOR_LEFT A0 

 
// Скорость, с которой мы движемся вперёд (0-255) 
#define SPEED            50 

int SPEED_RIGHT = IN1;
int SPEED_LEFT = IN3;

int LOW_RIGHT = IN2;
int LOW_LEFT = IN4;

  
 
float Kp=0, Ki=0, Kd=0; 
float error=0, P=0, I=0, D=0, PID_value=0; 
float previous_error=0,previous_I=0; 
int sensor[3]={0,0,0}; 
 
void setup()  
{ 
    // Настраивает выводы платы 4,5,6,7 на вывод сигналов  
    pinMode( IN1, OUTPUT );
    pinMode( IN2, OUTPUT );
    pinMode( IN3, OUTPUT );
    pinMode( IN4, OUTPUT );
} 
 
int read_sensor_values() 
{ 
   sensor[0]=digitalRead(SENSOR_LEFT); 
   sensor[1]=digitalRead(SENSOR_CENTER); 
   sensor[2]=digitalRead(SENSOR_RIGHT); 
 
   if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)) 
     error=-2; 
     else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)) 
            error=-1; 
            else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)) 
                   error=0; 
                   else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)) 
                         error=1; 
                         else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)) 
                               error=2; 
                               else  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)) 
   if(error<0) error=-3; 
     else error=3; 
  
  return error;
} 
 
// float calculate_pid() 
// { 
//    P = Kp*error; 
//    I = Ki*error + previous_I; 
//    D = Kd*(error-previous_error); 
//    PID_value = (P) + (I) + (D); 
//    previous_I=I; 
//    previous_error=error; 
//    return PID_value;
// } 

float calculate_pid() 
{ 
   P = error; 
   I = I + error; 
   D = error-previous_error; 
   PID_value = (Kp*P) + (Ki*I) + (Kd*D); 
   previous_error=error; 
   return PID_value;
} 
 
void motor_control() 
{ 
  // Расчет оптимальной скорости двигателя 
   int left_motor_speed = SPEED+PID_value; 
   int right_motor_speed = SPEED-PID_value; 
 
  // Скорость двигателя не должна превышать максимальное значение ШИМ 
  constrain(left_motor_speed,0,255); 
  constrain(right_motor_speed,0,255); 

  analogWrite(SPEED_LEFT,left_motor_speed); //Left Motor Speed 
  analogWrite(SPEED_RIGHT,right_motor_speed); //Right Motor Speed 
 
  //следующие строки кода - заставят бота двигаться вперед 
  digitalWrite(LOW_RIGHT, LOW); 
  digitalWrite(LOW_LEFT, LOW);


  //   if (PID_value > 0){
  //     analogWrite(SPEED_RIGHT, SPEED};
  //     analogWrite(SPEED_LEFT, SPEED-PID_value};
  //   }
  //   else{
  //     analogWrite(SPEED_RIGHT, SPEED+PID_value};
  //     analogWrite(SPEED_LEFT, SPEED};
  //   }
}
 
void loop () 
{ 
read_sensor_values (); 
calculate_pid (); 
motor_control(); 
}