   const int TrigPin = 9; //发送超声波
const int EchoPin = 10; //接收超声波
float cm;
#include <SoftwareSerial.h>
//实例化软串口
SoftwareSerial mySerial(2, 3); // RX, TX
void setup()
{
Serial.begin(115200);  
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
  while (!Serial) {
  }

  Serial.println("Goodnight moon!");

  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}
void loop()
{
// 产生一个10us的高电平脉冲去触发TrigPin
digitalWrite(TrigPin, LOW);
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);

// 检测脉冲宽度，并计算出距离
cm = pulseIn(EchoPin, HIGH) / 58.0;
//通过串口监视器输出
Serial.print("身高"); 
Serial.print(cm);
Serial.println("cm");
delay(1000);
}

 
