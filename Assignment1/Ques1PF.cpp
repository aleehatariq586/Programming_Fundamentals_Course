#include<stdio.h>
int main()
{
	int N,season,roomtype,nights;
    float rate,total,discount,hotelRevenue = 0;

    printf("Enter number of guests: ");
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
     	printf("---Guests %d---",i);
     	
     	printf("Enter season (1 = Peak, 2 = Off-Peak): ");
        scanf("%d", &season);

        printf("Enter room type (1 = Standard, 2 = Deluxe, 3 = Suite): ");
        scanf("%d", &roomtype);

        printf("Enter number of nights: ");
        scanf("%d", &nights);
        
        if (season == 1){
        	if (roomtype==1)
        	rate = 5000;
        	else if (roomtype==2)
        	rate=8000;
        	else if (roomtype==3)
        	rate = 12000;
        	else {
        	printf("Invalid Roomtype\n");
        	continue;}
    }
    else if (season ==2){
    	 if (roomtype == 1)
                rate = 3000;
        else if (roomtype == 2)
                rate = 5000;
            else if (roomtype == 3)
                rate = 8000;
            else
            {
                printf("Invalid room type\n");
                continue;
            }
	}
	else
        {
            printf("Invalid season\n");
            continue;
        }
        total = rate * nights;
        if (nights > 7)
        {
            discount = total * 0.15;
            total = total - discount;
        }
        hotelRevenue = hotelRevenue + total;

    printf("Rate per night = Rs. %.2f\n", rate);
    printf("Final price for Guest %d = Rs. %.2f\n", i, total);
    printf("\n==============================\n");
    printf("Hotel Total Revenue = Rs. %.2f\n", hotelRevenue);
    printf("==============================\n");
	
}
}
