/*

  Smoothing 平滑

  Reads repeatedly from an analog input, calculating a running average
  and printing it to the computer.  Keeps ten readings in an array and
  continually averages them. 这个程序重复读取一个模拟输入，分析一个运行均值，并且打印到电脑。
  在一个数组中保存10个读数，并持续的对其进行平均。

  The circuit: 电路
    * Analog sensor (potentiometer will do) attached to analog input 0  *模拟传感器（电位器即可）连接到模拟输入0

  Created 22 April 2007 2007年4月22日创建
  By David A. Mellis  <dam@mellis.org> 作者David A. Mellis  <dam@mellis.org>
  modified 9 Apr 2012 被Tom Igoe修改于2012年4月9日
  by Tom Igoe
  http://www.arduino.cc/en/Tutorial/Smoothing

  This example code is in the public domain. 这个实例代码在公共区域


*/


// Define the number of samples to keep track of.  The higher the number,定义要跟踪的样本数量。数字越大
// the more the readings will be smoothed, but the slower the output will 读数越平滑，输出就越慢
// respond to the input.  Using a constant rather than a normal variable lets 响应输入，使用一个常量而不是一个普通的变量
// use this value to determine the size of the readings array. 使用此值确定读取数组的大小
const int numReadings = 10;//限制元素量，平滑度就是求平均值。

int readings[numReadings];      // the readings from the analog input 定义数组，用常量表示。
int readIndex = 0;              // the index of the current reading 设置读取的位置，也就是数组的下标。
int total = 0;                  // the running total 和值
int average = 0;                // the average 平均值

int inputPin = A0;              //输入引脚，A0

void setup() {
  // initialize serial communication with computer:初始化串口，波特率默认9600。
  Serial.begin(9600);
  // initialize all the readings to 0:初始化数值
  for (int thisReading = 0; thisReading < numReadings; thisReading++) //循环，从0开始到设定的值，步长为1
  {
    readings[thisReading] = 0;   //赋值为0
  }
}

void loop() {
  // subtract the last reading:减去最后一项
  total = total - readings[readIndex];
  // read from the sensor:  总和等于总和减去上一次的值，从传感器读取值
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:讲传感器获取的新值加到总和里
  total = total + readings[readIndex];
  // advance to the next position in the array:数组下标加1
  readIndex = readIndex + 1;

  // if we're at the end of the array...比较，如果下标值达到设定最大值
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:数组下标从0开始
    readIndex = 0;
  }

  // calculate the average:计算平均值，和除以定义的元素限量
  average = total / numReadings;
  // send it to the computer as ASCII digits 打印输出平均值
  Serial.println(average);
  delay(1);        // delay in between reads for stability延迟效果，1毫秒保证稳定。
}