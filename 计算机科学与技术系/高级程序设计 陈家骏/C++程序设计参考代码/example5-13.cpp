#include <iostream>
#include <cstdlib>
using namespace std;
struct Line
{	double x1,y1,x2,y2;
};
struct Rectangle
{	double left,top,right,bottom;
};
struct Circle
{	double x,y,r;
};
union Figure
{	Line line;
	Rectangle rect;
	Circle circle; 
};
enum FigureShape { LINE, RECTANGLE, CIRCLE };
struct TaggedFigure
{	FigureShape shape;
	Figure figure; 
};
const int MAX_NUM_OF_FIGURES=100;
TaggedFigure figures[MAX_NUM_OF_FIGURES];
extern void draw_line(Line line);  //画线函数
extern void draw_rectangle(Rectangle rect);  //画矩形函数
extern void draw_circle(Circle circle);  //画圆函数
int main()
{	//输入图形数据
	int count;
	for (count=0; count<MAX_NUM_OF_FIGURES; count++)
	{	int shape;
		do
		{	cout << "请输入图形的种类(0：线段，1：矩形，2：圆，-1：结束)：";
			cin >> shape;
		} while (shape < -1 || shape > 2);
		if (shape == -1) break;
		switch (shape)
		{ 	case 0: //线
				figures[count].shape = LINE;
				cout << "请输入线段的起点和终点坐标 (x1,y1,x2,y2) ：";
				cin >> figures[count].figure.line.x1 
						>> figures[count].figure.line.y1 
					 	>> figures[count].figure.line.x2 
						>> figures[count].figure.line.y2;
  	 			break;
 		  case 1: //矩形
				figures[count].shape = RECTANGLE;
				cout << "请输入矩形的左上角和右下角坐标 (x1,y1,x2,y2) ：";
				cin >> figures[count].figure.rect.left 
						>> figures[count].figure.rect.top 
					 	>> figures[count].figure.rect.right 
						>> figures[count].figure.rect.bottom;
				break;
 		  case 2: //圆形
				figures[count].shape = CIRCLE;
				cout << "请输入圆的圆心坐标和半径 (x,y,r) ：";
				cin >> figures[count].figure.circle.x 
						>> figures[count].figure.circle.y 
					 	>> figures[count].figure.circle.r;
  	 		break;
	 	}
	}
	//输出所有图形
	for (int i=0; i<count; i++)
	{	switch (figures[i].shape)
		{ 	case LINE:
					draw_line(figures[i].figure.line);
					break;
			case RECTANGLE:
 					draw_rectangle(figures[i].figure.rect);
					break;
			case CIRCLE:
 					draw_circle(figures[i].figure.circle);
 					break;
 		}
	}
	return 0;
}
