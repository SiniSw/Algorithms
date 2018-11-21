#include<iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include<vector>
using namespace std;
int FLOYD_WARSHALL(int n,vector<std::vector<int> > &W,int** &p)
{
	int D[n+1][n][n];
	int Pre[n+1][n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{	
				D[0][i][j]=W[i][j];
				if(i==j||D[0][i][j]==100) Pre[0][i][j]= -1;
					else Pre[0][i][j] = i;				
			}
	for(int k=1;k<=n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(D[k-1][i][k]==100||D[k-1][i][j]==100) {
					D[k][i][j]=D[k-1][i][j];
					Pre[k][i][j]=Pre[k-1][i][j];
				}
					else if(D[k-1][i][j]==100){
						D[k][i][j]=D[k-1][i][k]+D[k-1][i][j];
						Pre[k][i][j]=Pre[k-1][k][j];	
					} 
						else{
							D[k][i][j]=D[k-1][i][j]<(D[k-1][i][k]+D[k-1][i][j])?D[k-1][i][j]:(D[k-1][i][k]+D[k-1][i][j]);			
							Pre[k][i][j]=D[k-1][i][j]<=(D[k-1][i][k]+D[k-1][i][j])?Pre[k-1][i][j]:Pre[k-1][k][j];							
						}
			}
//	memcpy(p,Pre[n],sizeof(int)*n*n);
	p=(int**)Pre[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	
			W[i][j]=D[n][i][j];
		}
	return 1;
}
string Premean(int n,int **p,int i,int j)
{
	string path;
	if(i!=j) path=Premean(n,p,i,p[i][p[i][j]]);
	path+=j;
	return path;
}
int main()
{
	int N;	//测试组数 
	int n;	//结点数n 
    ifstream infile("in.dat");
    ofstream outfile("out.dat");
    string input;
	int** D;
	int** P;
    getline(infile,input);
    N=atoi(input.c_str());
    cout<<N<<endl;   
    outfile<<N<<endl;
	for(int k=0;k<N;k++)
	{

		infile>>input;
		n=atoi(input.c_str());
		vector<vector<int> > D(n,vector<int>(n)); 
	/*	for(int i=0;i<n;i++)
			D[i]=new int*[n]; */
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				infile>>input;
				D[i][j]=atoi(input.c_str());	
			}			
		}
		FLOYD_WARSHALL(n,D,P);	
		outfile<<n<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(D[i][j]>=100)
				{
					cout<<32767<<' ';
					outfile<<32767<<' ';
				}
				
						
				else {
					cout<<D[i][j]<<' ';						
					outfile<<D[i][j]<<' ';		
				}
			}
			cout<<endl;	
			outfile<<endl;		
		}		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) outfile<<i+1<<endl;
					else if(P[i][j]==-1){
						cout<<"NULL"<<endl;
						outfile<<"NULL"<<endl;
					}	
						else {
							cout<<Premean(n,P,i,j)<<endl;	
							outfile<<Premean(n,P,i,j)<<endl;	
						}
			}
		}
	}
}

