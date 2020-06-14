#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 //點座標的x或y值之最大值 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int number;
	printf("請輸入要Rank幾個點座標：");
	scanf("%d",&number);
	
	//亂數生成點座標，並印出 
	printf("-\n下列為亂數自動生成的點座標：\n");
	int i,x[number],y[number],g;
	srand(time(NULL)); 
	for(i=0;i<number;i++){
		g=(rand()%N)+1;
		x[i]=g;
		g=(rand()%N)+1;
		y[i]=g;
		printf("(%3d,%3d )\t",x[i],y[i]);
		if((i+1)%5==0)
			printf("\n");
	}
	printf("\n");
	
	//依照x值重新排序，並印出 
	Quicksort(0,number-1,x,y);
	printf("依照x值重新排序後的點座標：\n");
	for(i=0;i<number;i++){
		printf("(%3d,%3d )\t",x[i],y[i]);
		if((i+1)%5==0)
			printf("\n");
	}
	printf("\n");
	
	//繪製座標圖
	char graph[N+1][N+1];
	printf("-\n繪製座標圖\n\n");
	drawgraph(x,y,graph,number);
	
	//計算2D Rank 
	int rank[number],k,j;
	
		//divid，設定劃分值 
	if(number%2==0)
		k=number/2;
	else
		k=number/2+1;
		
		//conquer
	for(i=0;i<k;i++){
		rank[i]=0; //rank值計算前歸零 
		if(i+k<number)
			rank[i+k]=0;
		for(j=0;j<i;j++){
			if(y[i]>y[j]&&x[i]>x[j]) //A區 
				rank[i]++;
			if(y[i+k]>y[j+k]&&i+k<number&&x[i+k]>x[j+k]) //B區 
				rank[i+k]++;
		}
	}
	for(i=k;i<number;i++) //A區匯入B區 
		for(j=0;j<k;j++)
			if(y[i]>y[j]&&x[i]>x[j])
				rank[i]++;
	
	//印出計算後的2D Rank值 
	printf("-\n每個點的Rank值：\n");
	for(i=0;i<number;i++)
		printf("Rank of (%3d,%3d ) = %d\n",x[i],y[i],rank[i]);

	return 0;
}
int Quicksort(int f,int l,int s[],int t[]){
	//參考自課本p.33的演算法，由小到大排序 
	if(f>=l)  //排好了 
		return s;
	else{
		int X=s[f]; //設置pilot 
		int i=f,j=l; //設置左右起點 
		while(i<j){  //還沒相遇 
			while(s[j]>=X&&j>=f+1) //如果當前右數大於pilot，向左走一步 
				j--;
			while(s[i]<=X&&i<=l) //如果當前左數小於pilot，向右走一步  
				i++;
			if(i<j){
				swap(&s[i],&s[j]); //交換位置 
				swap(&t[i],&t[j]);
			}
		}
		swap(&s[f],&s[j]);
		swap(&t[f],&t[j]);
		
		//分組遞迴 
		Quicksort(f,j-1,s,t);
		Quicksort(j+1,l,s,t);
	}
} 
int swap(int *a,int *b){ //交換位置函數 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return *a,*b;
}
void drawgraph(int s[],int t[],char g[],int n){ //繪製座標圖函數 
	int i,j;
	
	//填入x軸.y軸.空白 
	for(i=0;i<N+1;i++){
		for(j=0;j<N+1;j++)
		if(j==0)
			g[i*(N+1)+j]='|';
		else if(i==N)
			g[i*(N+1)+j]='_';
		else g[i*(N+1)+j]=' ';
	}
	
	//填入座標點 
	for(i=0;i<n;i++){
		g[(N-t[i])*(N+1)+s[i]]='*';
	} 
	
	//輸出座標圖 
	for(i=0;i<N+1;i++){
		for(j=0;j<N+1;j++)
			printf("%c ",g[i*(N+1)+j]);
		printf("\n");
	}	
}
