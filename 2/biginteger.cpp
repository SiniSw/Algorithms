#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define parameter 100
#define SIGN(A) ((A > 0) ? 1 : -1)

string s_Divi(string X,int N)
{
    string result(X,N-N/2);
    return result;
}
string s_Mult(string X,int N)
{
    string result(X);
    string loaner(N/2,0);
    result+=Loaner;
    return result;
}
string s_Add(string A,string B)
{
    string result;
    if(A[0]=='-'&&B[0]=='-'){
        result+='-';
        A=A.substr(1,A.size()-1);
        B=B.substr(1,B.size()-1);
    }
    if(A[0]!='-'&&B[0]=='-'){
        B=B.substr(1,B.size()-1);
        return s_Sub(A,B);
    }
    if(B[0]!='-'&&A[0]=='-'){
        A=A.substr(1,A.size()-1);
        return s_Sub(B,A);
    }
    int Max=(A.size()>B.size())?A.size():B.size();  //最大位数
    int* newA=new int[A.size()];
    int* newB=new int[B.size()];
    int* result_=new int[Max+1];              //运算结果的数组形式
    int carry=0;                              //进位

//    char* c=new char[A.size+1];
    char c;
    int i=A.size();
    for(c:A)
        newA[--i]=(int)c;
    int j=B.size();
    for(c:B)
        newA[--i]=(int)c;
    for(int k=0;k<=Max;k++)
    {
        i=newA[k];
        j=newB[k];
        if(k>=A.size)i=0;
        if(k>=B.size)j=0;
        result_[k]=newA[k]+newB[k]+carry;
        carry=result_[k]/10;
        result_[k]=result_[k]%10;
    }
    if(result_[Max]==0)k=Max;
        else k=Max-1;
    for(;k>=0;k--);
        result+=(char)result_[k];
    return result;
}

string s_Sub(string A,string B)
{
    string result;
    if(A[0]=='-'&&B[0]=='-'){
        A=A.substr(1,A.size()-1);
        B=B.substr(1,B.size()-1);
        return s_Sub(B,A);
    }
    if(A[0]!='-'&&B[0]=='-'){
        B=B.substr(1,B.size()-1);
        return s_Add(A,B);
    }
    if(B[0]!='-'&&A[0]=='-'){
        result+='-';
        A=A.substr(1,A.size()-1);
        return s_Add(A,B);
    }
    int Max=(A.size()>B.size())?A.size():B.size();  //最大位数
    int* newA=new int[A.size()];
    int* newB=new int[B.size()];
    int* result_=new int[Max+1];              //运算结果的数组形式
    int carry=0;                              //进位

//    char* c=new char[A.size+1];
    char c;
    int i=A.size();
    for(c:A)
        newA[--i]=(int)c;
    int j=B.size();
    for(c:B)
        newA[--i]=(int)c;
    for(int k=0;k<=Max;k++)
    {
        i=newA[k];
        j=newB[k];
        if(k>=A.size)i=0;
        if(k>=B.size)j=0;
        result_[k]=newA[k]+newB[k]+carry;
        carry=result_[k]/10;
        result_[k]=result_[k]%10;
    }
    if(result_[Max]==0)k=Max;
        else k=Max-1;
    for(;k>=0;k--);
        result+=(char)result_[k];
    return result;
}

long long Addition(int X, int Y, int N)
{
	if((Y==0)||(X==0))
		return X+Y;
	if(N==1)
		return X+Y;
	else
	{
		long long XL = X / (int)pow(10,(int)N/2);
		long long XR = X - XL * (int)pow(10,N/2);
		long long YL = Y / (int)pow(10,(int)N/2);
		long long YR = Y - YL * (int)pow(10,N/2);

		long long XLYL = Addition(XL,YL,N-N/2);
		long long XRYR = Addition(XR,YR,N/2);
			return (XLYL*(int)pow(10,N/2)+XRYR);
	}
}
long long Multiplication(long long X, long long Y, int N)
{
	int sign=SIGN(X)*SIGN(Y);
	long long x=abs(X);
	long long y=abs(Y);
	if((x==0)||(y==0))
		return x;
	if(N==1)
		return x*y;
	else
	{
		long long XL = x / (int)pow(10,(int)N/2);
		long long XR = x - XL * (int)pow(10,N/2);
		long long YL = y / (int)pow(10,(int)N/2);
		long long YR = y - YL * (int)pow(10,N/2);

		long long XLYL = Multiplication(XL,YL,N-N/2);
		long long XRYR = Multiplication(XR,YR,N/2);
		long long XLYRXRYL = Multiplication(XL - XR, YR - YL, N - N/2) + XLYL + XRYR;
			return sign*(XLYL*(int)pow(10,N/2+N/2)+XLYRXRYL*(int)pow(10,N/2)+XRYR);
	}
}
int main()
{
	FILE *fp1=fopen("in.dat","rt+");
	FILE *fp2=fopen("out.dat","rt+");
	long long x,y;
	int n,N;
	int flag=0;
	char X[parameter],Y[parameter];
	fscanf(fp1,"%d\n",&n);
	for(int i=0;i<n;i++)
	{
		if(flag!=0)
			fprintf(fp2,"\n");
		fscanf(fp1,"%s ",X);
		fscanf(fp1,"%s ",Y);
		fscanf(fp1,"%d\n",&flag);
		if(flag==1)
		{
			fprintf(fp2,"%d",Addition(atoll(X),atoll(Y),strlen(X)));
		}
		else if(flag==2)
		{
				fprintf(fp2,"%d",Addition(atoll(X),-atoll(Y),strlen(X)));
		}
		else if(flag==3)
		{
				fprintf(fp2,"%d",Multiplication(atoll(X),atoll(Y),strlen(X)));
		}
	}
	return 0;
}


