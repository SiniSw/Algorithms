#include<iostream>
#include <string.h>
int** FLOYD_WARSHALL(int n,int** W)
{
	int D[n+1][n][n];
	int Pre[n+1][n][n];
		for(int i=0;i<n;i++;)
			for(int j=0;j<n;j++)
			{
				if(i==j||D[0][i][j]==100) Pre[0][i][j]= NIL;
					else Pre[0][i][j] = i;				
			}
	D[0]=W;
	for(int k=1;k<=n;k++)
		for(int i=0;i<n;i++;)
			for(int j=0;j<n;j++)
			{
				D[k][i][j]=D[k-1][i][j]<(D[k-1][i][k]+D[k-1][i][j])?D[k-1][i][j]:(D[k-1][i][k]+D[k-1][i][j]);			
				Pre[k][i][j]=D[k-1][i][j]<=(D[k-1][i][k]+D[k-1][i][j])?Pre[k-1][i][j]:Pre[k-1][k][j];
			}
	return D[n];
}

