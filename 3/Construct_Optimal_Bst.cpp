#include<iostream>
#include <string.h>
using namespace std;

void CONSTRUCT_OPTIMAL_BST(int** root, int i, int j, int flag){
	if (i <= j){
		if (flag == 1){
			cout << "k" << root[i][j] << "为根" << endl;
		}
		else if (flag == 0){
			cout << "k" << root[i][j] << "为k" << j + 1 << "的左孩子" << endl;
		}
		else{
			cout << "k" << root[i][j] << "为k" << i - 1 << "的右孩子" << endl;
		}
		CONSTRUCT_OPTIMAL_BST(root,i, root[i][j] - 1, 0);
		CONSTRUCT_OPTIMAL_BST(root,root[i][j] + 1, j, 2);
	}
	else if (j == (i - 1)){
		if (flag == 0){
			cout << "d" << j << "为k" << i << "的左孩子" << endl;
		}
		else if (flag == 2){
			cout << "d" << j << "为k" << j << "的右孩子" << endl;
		}
	}
}
 
int main()
{
	int array[6][6] = { 
		0, 0, 0, 0, 0, 0,
		0, 1, 1, 2, 2, 2,
		0, 0, 2, 2, 2, 4,
		0, 0, 0, 3, 4, 5,
		0, 0, 0, 0, 4, 5,
		0, 0, 0, 0, 0, 5,
	};
	int** root=new int*[6];
	for(int i=0;i<6;i++)
		root[i]=new int[6];
	for(int i=0;i<6;i++)
		memcpy(root[i],array[i],sizeof(int)*6);
	CONSTRUCT_OPTIMAL_BST(root,1, 5, 1);
}
