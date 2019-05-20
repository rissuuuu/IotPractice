#include<VirtualWire.h>
const char *message="Merry Christmas";

int up=3;
int right=4;
int down=5;
int left=6;
int ball_click=2;
int ball_x_axis=A0;
int ball_y_axis=A1;
void setup() {
vw_set_ptt_inverted(true);
vw_set_tx_pin(12);
vw_setup(4000);
  
pinMode(up,INPUT);
pinMode(right,INPUT);
pinMode(left,INPUT);
pinMode(down,INPUT);
pinMode(ball_click,INPUT);
pinMode(ball_x_axis,INPUT);
pinMode(ball_y_axis,INPUT);
Serial.begin(9600);

}

void loop() {
int l=digitalRead(left);
int r=digitalRead(right);
int u=digitalRead(up);
int d=digitalRead(down);
int c=digitalRead(ball_click);
int b_x=analogRead(ball_x_axis);
int b_y=analogRead(ball_y_axis);

if(l==HIGH){
 message="L";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
else if(r==HIGH){
 message="R";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
else if(u==HIGH){
 message="F";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
else if(d==HIGH){
 message="D";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
else if(c==HIGH){
 message="C";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
else if(b_x>100){
 message="X";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
else if(b_y>100){
 message="Y";
  vw_send((uint8_t *)message,strlen(message));
  vw_wait_tx();
  }
}
