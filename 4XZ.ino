#include "HX711.h"
#include "WeightDetect.h"


void setup() {
  Serial.begin(9600);
  Serial.print("Welcome to use!\n");
  initHX711();
  delay(3000);    ///延时3秒
  tareWeight = readHX711();
  startDetectWeightChanged(tareWeight);

}

void loop() {
  // put your main code here, to run repeatedly:
 long weight = getWeight();  //计算放在传感器上的重物重量
 Serial.print(weight);  //串口显示重量，3意为保留三位小数
 Serial.print(" mg\n"); //显示单位
 Serial.print("\n");  //显示单位
 delay(20);  //延时2s 两秒读取一次传感器所受压力
 
 bool b = detectWeightChanged(weight);
 if(b)
  Serial.print("changed\n");

}
