#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,n;
	
	//�w�q�ƦC���� 
	printf("�п�J���ƧǤ��ƦC���סG");
	scanf("%d",&n);
	printf("�T�{�ƦC���׬��G%d\n-\n",n);
	
	int sequence[n];
	
	//�w�q���ƧǪ���l�ƦC
	printf("�п�J%d�Ӿ��(�H�Ů�j�})�G\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&sequence[i]);
	 
	//��X��l�ƦC	
	printf("�T�{��l�ƦC���G");
	for(i=0;i<n;i++){
		printf("%d",sequence[i]);
		if(i!=n-1)
			printf(", ");
	}
	printf("\n-\n");
	
	//����Quick Sort�Ƨ� 
	Quicksort(0,n-1,sequence);
	
	//��X�Ƨǫ�ƦC 
	printf("After Quick Sort �ƦC�G");
	for(i=0;i<n;i++){
		printf("%d",sequence[i]);
		if(i!=n-1)
			printf(", ");
	}
	printf("\n");
	return 0;
}
int Quicksort(int f,int l,int s[]){
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
			if(i<j)
				swap(&s[i],&s[j]); //�洫��m 
		}
		swap(&s[f],&s[j]);
		
		//���ջ��j 
		Quicksort(f,j-1,s);
		Quicksort(j+1,l,s);
	}
} 
int swap(int *a,int *b){ //�洫��m��� 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return *a,*b;
}
