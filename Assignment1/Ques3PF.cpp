#include<stdio.h>
int main()
{
	int N;
	printf("Enter number of students: ");
	if(scanf("%d",&N)!=1 || N<=0){
		printf("Invalid Number of students\n");
	}
	for(int i=1;i<=N;i++){
		float sum=0.0;
		float average;
		int marks;
		int has_deficiency=0;
		printf("\n---Processing Student %d---\n",i);
		for(int j =1;j<=5;j++){
			printf("Enter Marks: ");
			scanf("%d",&marks);
			
			sum=sum+marks;
			if(marks<33){
				has_deficiency=1;
			}
		}
		average=sum/5.0;
		printf("Average marks=%.2f\n",average);
		if(has_deficiency){
			printf("Result:Fail-Subject Deficiency\n");
		}
		else if(average>=80.0){
			printf("Result:Distinction\n");
		}
		else if(average>=60.0){
			printf("Result:Pass\n");
		}
		else {
			printf("Result:Fail\n");
		}
	}
}
