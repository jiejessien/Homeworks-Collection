#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 //�I�y�Ъ�x�Ȥ��̤j�� 
#define M 15 //�I�y�Ъ�y�Ȥ��̤j�� 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int number;
	printf("�п�J�nRank�X���I�y�СG");
	scanf("%d",&number);
	
	//�üƥͦ��I�y�СA�æL�X 
	printf("-\n�U�C���üƦ۰ʥͦ����I�y�СG\n");
	int i,x[number],y[number],g;
	srand(time(NULL)); 
	for(i=0;i<number;i++){
		g=(rand()%N)+1;
		x[i]=g;
		g=(rand()%M)+1;
		y[i]=g;
		printf("(%3d,%3d )\t",x[i],y[i]);
		if((i+1)%5==0)
			printf("\n");
	}
	printf("\n");
	
	//�̷�x�ȭ��s�ƧǡA�æL�X 
	Quicksort(0,number-1,x,y);
	printf("�̷�x�ȭ��s�Ƨǫ᪺�I�y�СG\n");
	for(i=0;i<number;i++){
		printf("(%3d,%3d )\t",x[i],y[i]);
		if((i+1)%5==0)
			printf("\n");
	}
	printf("\n");
	
	//ø�s�y�й�
	char graph[M+1][N+1];
	printf("-\nø�s�y�й�\n\n");
	drawgraph(x,y,graph,number);
	
	//�p��2D Rank 
	int maxima[number],k,j;
	
		//divid�A�]�w������ 
	if(number%2==0)
		k=number/2;
	else
		k=number/2+1;
		
		//conquer
	for(i=0;i<k;i++){
		maxima[i]=1; //��l��1
		if(i+k<number)
			maxima[i+k]=1;
		for(j=i;j<k;j++){
			if(y[i]<y[j]&&x[i]<x[j]) //A�� 
				maxima[i]=0;
			if(y[i+k]<y[j+k]&&i+k<number&&x[i+k]<x[j+k]) //B�� 
				maxima[i+k]=0;
		}
	}
	for(i=0;i<k;i++) //A�϶פJB�� 
		for(j=k;j<number;j++)
			if(y[i]<y[j]&&x[i]<x[j])
				maxima[i]=0;
	
	//�L�X�p��᪺2D Rank�� 
	printf("-\nmaxima�y�СG\n");
	for(i=0;i<number;i++)
		if(maxima[i]==1) 
		printf("(%3d,%3d ) \n",x[i],y[i]);

	return 0;
}
int Quicksort(int f,int l,int s[],int t[]){
	//�ѦҦ۽ҥ�p.33���t��k�A�Ѥp��j�Ƨ� 
	if(f>=l)  //�Ʀn�F 
		return s;
	else{
		int X=s[f]; //�]�mpilot 
		int i=f,j=l; //�]�m���k�_�I 
		while(i<j){  //�٨S�۹J 
			while(s[j]>=X&&j>=f+1) //�p�G��e�k�Ƥj��pilot�A�V�����@�B 
				j--;
			while(s[i]<=X&&i<=l) //�p�G��e���Ƥp��pilot�A�V�k���@�B  
				i++;
			if(i<j){
				swap(&s[i],&s[j]); //�洫��m 
				swap(&t[i],&t[j]);
			}
		}
		swap(&s[f],&s[j]);
		swap(&t[f],&t[j]);
		
		//���ջ��j 
		Quicksort(f,j-1,s,t);
		Quicksort(j+1,l,s,t);
	}
} 
int swap(int *a,int *b){ //�洫��m��� 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return *a,*b;
}
void drawgraph(int s[],int t[],char g[],int n){ //ø�s�y�йϨ�� 
	int i,j;
	
	//��Jx�b.y�b.�ť� 
	for(i=0;i<M+1;i++){
		for(j=0;j<N+1;j++)
		if(j==0)
			g[i*(N+1)+j]='|';
		else if(i==M)
			g[i*(N+1)+j]='_';
		else g[i*(N+1)+j]=' ';
	}
	
	//��J�y���I 
	for(i=0;i<n;i++){
		g[(M-t[i])*(N+1)+s[i]]='*';
	} 
	
	//��X�y�й� 
	for(i=0;i<M+1;i++){
		for(j=0;j<N+1;j++)
			printf("%c ",g[i*(N+1)+j]);
		printf("\n");
	}	
}
