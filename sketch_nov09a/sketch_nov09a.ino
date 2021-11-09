long tareWeight = 0;
int HX711_SCK = 3;  ///     作为输出口
int HX711_DT = 2;   ///     作为输入口

unsigned long readHX711(void) //选择芯片工作方式并进行数据读取
{
  unsigned long count;   ///储存输出值
  unsigned char i;
  ////high--高电平 1  low--低电平 0
  digitalWrite(HX711_DT, HIGH);   ////  digitalWrite作用： DT=1；
  delayMicroseconds(1); ////延时 1微秒
  digitalWrite(HX711_SCK, LOW);  ////  digitalWrite作用： SCK=0；
  delayMicroseconds(1);   ////延时 1微秒
  count = 0;
  while (digitalRead(HX711_DT));   //当DT的值为1时，开始ad转换
  for (i = 0; i < 24; i++) ///24个脉冲，对应读取24位数值
  {
    digitalWrite(HX711_SCK, HIGH);  ////  digitalWrite作用： SCK=0；
    /// 利用 SCK从0--1 ，发送一次脉冲，读取数值
    delayMicroseconds(1);  ////延时 1微秒
    count = count << 1; ///用于移位存储24位二进制数值
    digitalWrite(HX711_SCK, LOW);   //// digitalWrite作用： SCK=0；为下次脉冲做准备
    delayMicroseconds(1);
    if (digitalRead(HX711_DT))   ///若DT值为1，对应count输出值也为1
      count++;
  }
  digitalWrite(HX711_SCK, HIGH);    ///再来一次上升沿 选择工作方式  128增益
  count ^= 0x800000;   //按位异或  不同则为1   0^0=0; 1^0=1;
  ///对应二进制  1000 0000 0000 0000 0000 0000  作用为将最高位取反，其他位保留原值
  delayMicroseconds(1);
  digitalWrite(HX711_SCK, LOW);      /// SCK=0；
  delayMicroseconds(1);  ////延时 1微秒
  return (count);    ///返回传感器读取值
}



void initHX711() {

  pinMode(HX711_SCK, OUTPUT);
  pinMode(HX711_DT, INPUT);
  //获取毛皮重量
  tareWeight = HX711_Read();
}

void setup() {
  Serial.begin(9600);
  Serial.print("Welcome to use!\n");
  delay(3000);    ///延时3秒

}

void loop() {
  // put your main code here, to run repeatedly:

}
