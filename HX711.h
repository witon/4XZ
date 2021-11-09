#define GapValue 1057       ///该值需校准 每个传感器都有所不同

extern long tareWeight;
extern int HX711_SCK;  ///     作为输出口
extern int HX711_DT;   ///     作为输入口
unsigned long readHX711(void); //选择芯片工作方式并进行数据读取
long getWeight();
void initHX711();
