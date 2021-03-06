#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define INFINITY 100000
#define Distance(a,b) sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))


//定义二维点Point
typedef struct Point
{
	float x, y;     //二维点的横纵坐标，范围均为[-100,100]
}Point;

bool CMP(Point a, Point b)
{
return a.x<b.x;
}

//求出最近点对记录，并将两点记录再a、b中
float ClosestPair(Point points[], int length, Point &a, Point &b)
{
	float distance;        //记录集合points中最近两点距离
	float d1, d2;           //记录分割后两个子集中各自最小点对距离
	int i = 0, j = 0, k = 0;       //用于控制for循环的循环变量
	Point a1, b1, a2, b2;     //保存分割后两个子集中最小点对

	if (length<2)return INFINITY;    //若子集长度小于2，定义为最大距离，表示不可达
	if (length == 2)
	{
		a = points[0];
		b = points[1];
		distance = Distance(points[0], points[1]);
	}
	else
	{
		Point *pts1 = new Point[length];     //开辟两个子集
		Point *pts2 = new Point[length];

		sort(points, points + length, CMP);   //调用algorithm库中的sort函数对points进行排序，CmpX为自定义的排序规则
		float mid = points[(length - 1) / 2].x;  //排完序后的中间下标值，即中位数

		for (i = 0; i<length / 2; i++)
			pts1[i] = points[i];
		for (int j = 0, i = length / 2; i<length; i++)
			pts2[j++] = points[i];
		d1 = ClosestPair(pts1, length / 2, a1, b1);           //分治求解左半部分子集的最近点
		d2 = ClosestPair(pts2, length - length / 2, a2, b2);    //分治求解右半部分子集的最近点
		if (d1<d2) { distance = d1; a = a1; b = b1; }
		else { distance = d2; a = a2; b = b2; }

		//求解跨分割线并在δ×2δ区间内的最近点对
		Point *pts3 = new Point[length];
		for (i = 0, k = 0; i<length; i++)
			if (abs(points[i].x - mid) <= distance)pts3[k++] = points[i];

		for (i = 0; i<k; i++)
			for (j = i + 1; j <= i + 7 && j<k; j++)    //只需与有序的领接的的7个点进行比较
			{
				if (Distance(pts3[i], pts3[j])<distance)
				{//如果跨分割线的两点距离小于已知最小距离，则记录该距离
					distance = Distance(pts3[i], pts3[j]);
					a = pts3[i];
					b = pts3[j];
				}
			}
	}
	return distance;
}

int main()
{
	int N;      //随机生成的点对个数
	Point a, b;
	float diatance;
    ifstream infile("in.dat");
    ofstream outfile("out.dat");
    string input;
    char c[2];
    getline(infile,input);
	N=atoi(input.c_str());
    Point *points = new Point[N];
    int i = 0;
    while(infile>>input)
    {
//    strcpy(c,input.c_str());
	points[i].x=atof(input.c_str());
	infile>>input;
	points[i++].y=atof(input.c_str());
    }
	diatance = ClosestPair(points, N, a, b);
    outfile<<a.x<<' '<<a.y<<' '<<b.x<<' '<<b.y;
	cout << endl << "最近点对为：" << "(" << a.x << "," << a.y << ")和" << "(" << b.x << "," << b.y << ")" << endl << "最近点对距离为：" << diatance << endl;
	system("pause");

}
