#include<bits/stdc++.h>
using namespace std;
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OK 1
#define initialSize 10
#define IncrementSize 20
//typedef int int;
typedef char ElemType;
typedef struct {
	int i;
    int j;
	ElemType e;
}Triple;
 
typedef struct {
	Triple number[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;
 
void wise(int num[][MAXSIZE],TSMatrix *T)
	T->tu = 1;
	for(int i=1;i<=T->mu;i++)
	{
		for(int j=1;j<=T->nu;j++)
		{
			if(num[i][j]!=0)
			{
				T->number[T->tu].i = i;
				T->number[T->tu].j = j;
				T->number[T->tu].e = num[i][j];
				T->tu++;
			}
		}
	}
	T->tu--;
}
 
void counterwise(TSMatrix T,int num[][MAXSIZE])
{
	for(int i=1;i<=T.tu;i++)
	{
		num[T.number[i].i][T.number[i].j] = T.number[i].e;
	}
}
 
Status Create_Matrix(TSMatrix *T)
{
	int num[MAXSIZE][MAXSIZE]={0};
	scanf("%d %d", &T->mu, &T->nu);
	for (int i = 1; i <= T->mu; i++)
	{
		for (int j = 1; j <= T->nu; j++)
		{
			scanf("%d", &num[i][j]);
		}
	}
 
	wise(num, T);
}

Status Matrix_Addition(TSMatrix A, TSMatrix B, TSMatrix *C)
{
	int row_a, row_b,col_a, col_b, num_a, num_b, num_c;
	C->mu = A.mu;
	C->nu = A.nu;
	if (A.mu != B.mu || A.nu != B.nu) {
		return ERROR;
	}
	for(num_a=1,num_b=1,num_c=1;num_a<=A.tu&&num_b<=B.tu;)
	{
 
		row_a = A.number[num_a].i;
		row_b = B.number[num_b].i;
		col_a = A.number[num_a].j;
		col_b = B.number[num_b].j;
		if(row_a>row_b){
			C->number[num_c].i = B.number[num_b].i;
			C->number[num_c].j = B.number[num_b].j;
			C->number[num_c].e = B.number[num_b].e;
			num_b++;
			num_c++;
		}
		else if(row_a<row_b)
		{
			C->number[num_c].i = A.number[num_a].i;
			C->number[num_c].j = A.number[num_a].j;
			C->number[num_c].e = A.number[num_a].e;
			num_a++;
			num_c++;
		}
		else{
			if(col_a>col_b){
				C->number[num_c].i = B.number[num_b].i;
				C->number[num_c].j = B.number[num_b].j;
				C->number[num_c].e = B.number[num_b].e;
				num_b++;
				num_c++;
			}
			else if(col_a<col_b)
			{
				C->number[num_c].i = A.number[num_a].i;
				C->number[num_c].j = A.number[num_a].j;
				C->number[num_c].e = A.number[num_a].e;
				num_a++;
				num_c++;
			}
			else{
				if((A.number[num_a].e+B.number[num_b].e)){
					C->number[num_c].i = A.number[num_a].i;
					C->number[num_c].j = A.number[num_a].j;
					C->number[num_c].e = A.number[num_a].e + B.number[num_b].e;
					num_c++;
				}
				num_a++;
				num_b++;
			}
		}
	}
 
	while (num_a <= A.tu)
	{
		C->number[num_c].i = A.number[num_a].i;
		C->number[num_c].j = A.number[num_a].j;
		C->number[num_c].e = A.number[num_a].e;
		num_a++;
		num_c++;
	}
 
	while (num_b <= B.tu)
	{
		C->number[num_c].i = B.number[num_b].i;
		C->number[num_c].j = B.number[num_b].j;
		C->number[num_c].e = B.number[num_b].e;
		num_b++;
		num_c++;
	}
	C->tu = num_c - 1;
}
 