#include <iostream>
#include <cstring>
using namespace std;

#include <iostream>
using namespace std;
class Figure
{	public:
		virtual void draw() const=0;
		virtual void input_data()=0;
};
class Rectangle: public Figure
{		double left,top,right,bottom;
	public:
		void draw() const
		{	//...... //画矩形
		}
		void input_data()
		{	cout << "请输入矩形的左上角和右下角坐标 (x1,y1,x2,y2) ：";
			cin >> left >> top >> right >> bottom;
		}
		double area() const { return (bottom-top)*(right-left); }
};
const double PI=3.1416;
class Circle: public Figure
{		double x,y,r;
	public:
		void draw() const
		{	//...... //画圆
		}
		void input_data()
		{	cout << "请输入圆的圆心坐标和半径 (x,y,r) ：";
			cin >> x >> y >> r;
		}
		double area() const { return r*r*PI; }
};
class Line: public Figure
{		double x1,y1,x2,y2;
	public:
		void draw() const
		{	//...... //画线
		}
		void input_data()
		{	cout << "请输入线段的起点和终点坐标 (x1,y1,x2,y2) ：";
			cin >> x1 >> y1 >> x2 >> y2;
		}
		double area() const { return 0.0; }
};
const int MAX_NUM_OF_FIGURES=100;
enum FigureShape { LINE, RECTANGLE, CIRCLE };
class FigureGroup  //图形对象管理类
{		Figure *figures_buf[MAX_NUM_OF_FIGURES];
		int num_of_figures;
	public:
		FigureGroup() { num_of_figures = 0; }
		void display_figures()
		{ for (int i=0; i<num_of_figures; i++)	
				figures_buf[i]->draw();  //通过动态绑定调用相应类的draw。
		}
		void input_figures_data()
		{	for (num_of_figures=0; num_of_figures<MAX_NUM_OF_FIGURES;
					num_of_figures++)
			{	int shape;
				do
				{	cout << "请输入图形的种类(0：线段，1：矩形，2：圆，-1：结束)：";
					cin >> shape;
				} while (shape < -1 || shape > 2);
				if (shape == -1) break;
				switch (shape)
				{	case LINE: //线
						figures_buf[num_of_figures] = new Line;
   					break;
					case RECTANGLE: //矩形
						figures_buf[num_of_figures] = new Rectangle;
						break;
					case CIRCLE: //圆
						figures_buf[num_of_figures] = new Circle;
   					break;
 				}
				figures_buf[num_of_figures]->input_data(); //通过动态绑定调用相应类的input_data。
			}
		}
};
FigureGroup figures;  //定义了一个FigureGroup 类的全局对象
int main()
{	//输入图形数据
	figures.input_figures_data();
	//输出所有图形
	figures.display_figures();
	return 0;
}
