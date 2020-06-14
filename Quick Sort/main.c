#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,n;
	
	//定義數列長度 
	printf("請輸入欲排序之數列長度：");
	scanf("%d",&n);
	printf("確認數列長度為：%d\n-\n",n);
	
	int sequence[n];
	
	//定義欲排序的原始數列
	printf("請輸入%d個整數(以空格隔開)：\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&sequence[i]);
	 
	//輸出原始數列	
	printf("確認原始數列為：");
	for(i=0;i<n;i++){
		printf("%d",sequence[i]);
		if(i!=n-1)
			printf(", ");
	}
	printf("\n-\n");
	
	//執行Quick Sort排序 
	Quicksort(0,n-1,sequence);
	
	//輸出排序後數列 
	printf("After Quick Sort 數列：");
	for(i=0;i<n;i++){
		printf("%d",sequence[i]);
		if(i!=n-1)
			printf(", ");
	}
	printf("\n");
	return 0;
}
int Quicksort(int f,int l,int s[]){
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
			if(i<j)
				swap(&s[i],&s[j]); //交換位置 
		}
		swap(&s[f],&s[j]);
		
		//分組遞迴 
		Quicksort(f,j-1,s);
		Quicksort(j+1,l,s);
	}
} 
int swap(int *a,int *b){ //交換位置函數 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return *a,*b;
}
