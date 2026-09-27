#include <stdio.h>
int main()
{
    int quantity;
    float price, discount, tax;
    float subtotal, discountedAmount, finalBill;
    float discountAmount, taxAmount;

    printf("===== ONLINE SHOPPING BILL CALCULATOR =====\n");

    printf("Enter quantity of products: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    printf("Enter tax percentage: ");
    scanf("%f", &tax);
    if (quantity <= 0)
    {
        printf("Error: Quantity must be greater than 0\n");
        return 0;
    }

    if (price <= 0)
    {
        printf("Error: Price must be greater than 0\n");
        return 0;
    }

    if (discount < 0 || discount > 100)
    {
        printf("Error: Discount must be between 0 and 100\n");
        return 0;
    }

    if (tax < 0 || tax > 100)
    {
        printf("Error: Tax must be between 0 and 100.\n");
        return 0;
    }

    subtotal = quantity * price;

    discountAmount = (subtotal * discount) / 100;
    discountedAmount = subtotal - discountAmount;

    taxAmount = (discountedAmount * tax) / 100;
    finalBill = discountedAmount + taxAmount;

    printf("\n====================================\n");
    printf("          SHOPPING BILL\n");
    printf("====================================\n");

    printf("Quantity             : %d\n", quantity);
    printf("Price per item       : Rs. %.2f\n", price);
    printf("Subtotal             : Rs. %.2f\n", subtotal);
    printf("Discount             : %.2f%%\n", discount);
    printf("Discount Amount      : Rs. %.2f\n", discountAmount);
    printf("After Discount       : Rs. %.2f\n", discountedAmount);
    printf("Tax                  : %.2f%%\n", tax);
    printf("Tax Amount           : Rs. %.2f\n", taxAmount);
    printf("Final Bill           : Rs. %.2f\n", finalBill);

    printf("====================================\n");
}
