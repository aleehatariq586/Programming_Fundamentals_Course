#include <stdio.h>

int main()
{
    char vehicleType, membership, disabled, stationAvailable;
    float currentBattery, requiredLevel;
    float requiredCharging, parkingHours;
    int currentTime;
    float chargingRate;
    float chargingCost = 0;
    float parkingCost = 0;
    float chargingDiscount = 0;
    float parkingDiscount = 0;
    float totalDiscount;
    float finalAmount;

    printf("===== SMART EV CHARGING AND PARKING SYSTEM =====\n");

    printf("Enter vehicle type (E = Electric, H = Hybrid): ");
    scanf(" %c", &vehicleType);

    printf("Enter current battery level: ");
    scanf("%f", &currentBattery);

    printf("Enter required charging level: ");
    scanf("%f", &requiredLevel);

    printf("Enter expected parking duration in hours: ");
    scanf("%f", &parkingHours);

    printf("Enter current time (0-23): ");
    scanf("%d", &currentTime);

    printf("Parking membership? (Y/N): ");
    scanf(" %c", &membership);

    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Charging station available? (Y/N): ");
    scanf(" %c", &stationAvailable);

    if (vehicleType != 'E' && vehicleType != 'H')
    {
        printf("Error: Invalid vehicle type\n");
    }

    if (currentBattery < 0 || currentBattery > 100)
    {
        printf("Error: Battery level must be between 0 and 100.\n");
    }

    if (requiredLevel < 0 || requiredLevel > 100)
    {
        printf("Error: Required charging level must be between 0 and 100.\n");
    }

    if (parkingHours < 0)
    {
        printf("Error: Parking duration cannot be negative.\n");
    }

    if (currentTime < 0 || currentTime > 23)
    {
        printf("Error: Invalid time.\n");
    }

    if (membership != 'Y' && membership != 'N')
    {
        printf("Error: Invalid membership value\n");
    }

    if (disabled != 'Y' && disabled != 'N')
    {
        printf("Error: Invalid disabled-person status.\n");
    }

    if (stationAvailable != 'Y' && stationAvailable != 'N')
    {
        printf("Error: Invalid station availability\n");
    }

    if (stationAvailable == 'N')
    {
        if (vehicleType == 'H')
        {
            printf("Charging unavailable - Parking only.\n");
        }
        else
        {
            printf("No charging slot available.\n");
        }
    }

    if (vehicleType == 'H')
    {
        if (currentBattery >= 40)
        {
            printf("Vehicle does not qualify for EV charging\n");
        }
}

    requiredCharging = requiredLevel - currentBattery;

    if (requiredCharging <= 0)
    {
        printf("No charging required\n");

        chargingCost = 0;

        if (parkingHours <= 2)
        {
            parkingCost = 200;
        }
        else if (parkingHours <= 5)
        {
            parkingCost = 400;
        }
        else
        {
            parkingCost = 700;
        }
        if (disabled == 'Y')
        {
            parkingDiscount = parkingCost;
            parkingCost = 0;
        }
        else if (membership == 'Y')
        {
            parkingDiscount = parkingCost * 0.20;
            parkingCost = parkingCost - parkingDiscount;
        }

        totalDiscount = parkingDiscount;
        finalAmount = parkingCost;

        printf("\n========== FINAL BILL ==========\n");

        printf("Vehicle Type         : %c\n", vehicleType);
        printf("Current Battery      : %.2f%%\n", currentBattery);
        printf("Required Level       : %.2f%%\n", requiredLevel);
        printf("Charging Priority    : No Charging Required\n");
        printf("Charging Cost        : Rs. %.2f\n", chargingCost);
        printf("Parking Cost         : Rs. %.2f\n", parkingCost);
        printf("Total Discount       : Rs. %.2f\n", totalDiscount);
        printf("Final Payable Amount : Rs. %.2f\n", finalAmount);
    }

    if (currentBattery <= 15 && requiredLevel >= 80)
    {
        printf("\nCharging Priority: Emergency Charging Priority\n");
    }
    else if (disabled == 'Y' ||
             (membership == 'Y' && currentBattery <= 30))
    {
        printf("\nCharging Priority: Priority Charging\n");
    }
    else
    {
        printf("\nCharging Priority: Normal Charging\n");
    }

    if (currentTime < 17 || currentTime > 22)
    {
        chargingRate = 35;

        printf("Time Status: Off-Peak\n");

        chargingCost = requiredCharging * chargingRate;

        if (membership == 'Y' && !(currentBattery <= 15 && requiredLevel >= 80))
        {
            chargingDiscount = chargingCost * 0.20;
        }
    }
    else
    {
        chargingRate = 50;

        printf("Time Status: Peak\n");

        chargingCost = requiredCharging * chargingRate;

        chargingDiscount = chargingCost * 0.10;
    }

    chargingCost = chargingCost - chargingDiscount;

    if (parkingHours <= 2)
    {
        parkingCost = 200;
    }
    else if (parkingHours <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }

    if (disabled == 'Y')
    {
        parkingDiscount = parkingCost;
        parkingCost = 0;
    }
    else if (membership == 'Y')
    {
        parkingDiscount = parkingCost * 0.20;
        parkingCost = parkingCost - parkingDiscount;
}

    totalDiscount = chargingDiscount + parkingDiscount;

    finalAmount = chargingCost + parkingCost;

    if (parkingHours > 8)
    {
        printf("\nLong-stay warning: Please relocate your vehicle after charging\n");
    }
    else
    {
        printf("\nStandard parking duration\n");
    }

    printf("\n========================================\n");
    printf("              FINAL BILL\n");
    printf("========================================\n");

    printf("Vehicle Type          : %c\n", vehicleType);
    printf("Current Battery       : %.2f%%\n", currentBattery);
    printf("Required Charging     : %.2f%%\n", requiredLevel);
    printf("Charging Required     : %.2f%%\n", requiredCharging);

    if (currentBattery <= 15 && requiredLevel >= 80)
    {
        printf("Charging Priority     : Emergency Charging Priority\n");
    }
    else if (disabled == 'Y' ||
             (membership == 'Y' && currentBattery <= 30))
    {
        printf("Charging Priority     : Priority Charging\n");
    }
    else
    {
        printf("Charging Priority     : Normal Charging\n");
    }

    if (currentTime < 17 || currentTime > 22)
    {
        printf("Peak Status           : Off-Peak\n");
    }
    else
    {
        printf("Peak Status           : Peak\n");
    }

    printf("Charging Cost         : Rs. %.2f\n", chargingCost);
    printf("Parking Cost          : Rs. %.2f\n", parkingCost);
    printf("Charging Discount     : Rs. %.2f\n", chargingDiscount);
    printf("Parking Discount      : Rs. %.2f\n", parkingDiscount);
    printf("Total Discount        : Rs. %.2f\n", totalDiscount);
    printf("Final Payable Amount  : Rs. %.2f\n", finalAmount);

    if (parkingHours > 8)
    {
        printf("Warning               : Long-stay warning\n");
    }
    else
    {
        printf("Warning               : Standard parking duration\n");
    }

    printf("========================================\n");
}
