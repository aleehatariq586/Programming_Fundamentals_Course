#include<stdio.h>
int main()
{
	int currentfloor=0;
	int N;
	printf("Elevator Simulation\n");
	printf("Enter the number of floor requests:");
	if(scanf ("%d",&N)!=1 || N<=0){
		printf("Invalid number of requests\n");
	}
	int requests[N];
	printf("Enter the %d  floor requests:",N);
	for(int i =0;i<N;i++){
		scanf("%d",&requests[i]);
	}
	printf("Starting Elevator Simulation from Floor %d\n",currentfloor);
	for(int i=0;i<N;i++){
		int requestedfloor=requests[i];
		printf("Processing Request for floor %d\n",requestedfloor);
		
		if (requestedfloor>currentfloor){
			printf("Moving Up\n");
		}
		else if(requestedfloor<currentfloor){
			printf("Moving Down\n");
		}
		else{
			printf("Doors Opening\n");
		}
		currentfloor=requestedfloor;
		printf("Current Elevator Position:Floor %d\n",currentfloor);
	}
	printf("All Simulation requests processed successfully\n ");
}
