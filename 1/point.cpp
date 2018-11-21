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


//�����ά��Point
typedef struct Point
{
	float x, y;     //��ά��ĺ������꣬��Χ��Ϊ[-100,100]
}Point;

bool CMP(Point a, Point b)
{
return a.x<b.x;
}

//��������Լ�¼�����������¼��a��b��
float ClosestPair(Point points[], int length, Point &a, Point &b)
{
	float distance;        //��¼����points������������
	float d1, d2;           //��¼�ָ�������Ӽ��и�����С��Ծ���
	int i = 0, j = 0, k = 0;       //���ڿ���forѭ����ѭ������
	Point a1, b1, a2, b2;     //����ָ�������Ӽ�����С���

	if (length<2)return INFINITY;    //���Ӽ�����С��2������Ϊ�����룬��ʾ���ɴ�
	if (length == 2)
	{
		a = points[0];
		b = points[1];
		distance = Distance(points[0], points[1]);
	}
	else
	{
		Point *pts1 = new Point[length];     //���������Ӽ�
		Point *pts2 = new Point[length];

		sort(points, points + length, CMP);   //����algorithm���е�sort������points��������CmpXΪ�Զ�����������
		float mid = points[(length - 1) / 2].x;  //���������м��±�ֵ������λ��

		for (i = 0; i<length / 2; i++)
			pts1[i] = points[i];
		for (int j = 0, i = length / 2; i<length; i++)
			pts2[j++] = points[i];
		d1 = ClosestPair(pts1, length / 2, a1, b1);           //���������벿���Ӽ��������
		d2 = ClosestPair(pts2, length - length / 2, a2, b2);    //��������Ұ벿���Ӽ��������
		if (d1<d2) { distance = d1; a = a1; b = b1; }
		else { distance = d2; a = a2; b = b2; }

		//����ָ��߲��ڦġ�2�������ڵ�������
		Point *pts3 = new Point[length];
		for (i = 0, k = 0; i<length; i++)
			if (abs(points[i].x - mid) <= distance)pts3[k++] = points[i];

		for (i = 0; i<k; i++)
			for (j = i + 1; j <= i + 7 && j<k; j++)    //ֻ�����������ӵĵ�7������бȽ�
			{
				if (Distance(pts3[i], pts3[j])<distance)
				{//�����ָ��ߵ��������С����֪��С���룬���¼�þ���
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
	int N;      //������ɵĵ�Ը���
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
	cout << endl << "������Ϊ��" << "(" << a.x << "," << a.y << ")��" << "(" << b.x << "," << b.y << ")" << endl << "�����Ծ���Ϊ��" << diatance << endl;
	system("pause");

}
