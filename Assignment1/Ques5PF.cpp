#include <stdio.h>

int main()
{
    int n, i;
    int capacityA = 20;
    int capacityB = 40;
    int capacityC = 15;

    int occupiedA = 0;
    int occupiedB = 0;
    int occupiedC = 0;

    int accepted = 0;
    int rejected = 0;
    int cars = 0;
    int bikes = 0;
    int vans = 0;

    char vehicle;
    char category;
    char permit;
    char emergency;

    int valid;

    printf("===== SMART CAMPUS PARKING SYSTEM =====\n");

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Error: Number of vehicles must be greater than 0\n");
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        printf("\n========== VEHICLE %d ==========\n", i);

        do
        {
            valid = 1;

            printf("Enter vehicle type (C = Car, B = Bike, V = Van): ");
            scanf(" %c", &vehicle);

            if (vehicle != 'C' && vehicle != 'B' && vehicle != 'V')
            {
                printf("Invalid vehicle type!Try again\n");
                valid = 0;
            }

        } while (valid == 0);

        do
        {
            valid = 1;

            printf("Enter category (F = Faculty, S = Student, G = Visitor): ");
            scanf(" %c", &category);

            if (category != 'F' && category != 'S' && category != 'G')
            {
                printf("Invalid category.Try again\n");
                valid = 0;
            }

        } while (valid == 0);

        do
        {
            valid = 1;

            printf("Valid parking permit? (Y/N): ");
            scanf(" %c", &permit);

            if (permit != 'Y' && permit != 'N')
            {
                printf("Invalid permit value. Try again.\n");
                valid = 0;
            }

        } while (valid == 0);
        if (permit == 'N')
        {
            do
            {
                valid = 1;

                printf("Is this an emergency vehicle? (Y/N): ");
                scanf(" %c", &emergency);

                if (emergency != 'Y' && emergency != 'N')
                {
                    printf("Invalid value. Try again.\n");
                    valid = 0;
                }

            } while (valid == 0);
        }
        else
        {
            emergency = 'N';
        }

        if (emergency == 'Y')
        {
            if (category == 'F')
            {
                if (vehicle == 'V')
                {
                    if (occupiedA < capacityA)
                    {
                        occupiedA++;
                        accepted++;
                        vans++;

                        printf("Accepted: Emergency van assigned to Zone A.\n");
                        printf("Remaining capacity: %d\n",capacityA - occupiedA);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone A is full.\n");
                    }
                }
                else
                {
                    if (occupiedA < capacityA)
                    {
                        occupiedA++;
                        accepted++;

                        if (vehicle == 'C')
                            cars++;
                        else
                            bikes++;

                        printf("Accepted: Emergency vehicle assigned to Zone A.\n");
                        printf("Remaining capacity: %d",capacityA - occupiedA);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone A is full.\n");
                    }
                }
            }
            else if (category == 'S')
            {
                if (vehicle == 'V')
                {
                    if (occupiedB < capacityB)
                    {
                        occupiedB++;
                        accepted++;
                        vans++;

                        printf("Accepted: Emergency van assigned to Zone B.\n");
                        printf("Remaining capacity: %d\n",capacityB - occupiedB);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone B is full.\n");
                    }
                }
                else
                {
                    if (occupiedB < capacityB)
                    {
                        occupiedB++;
                        accepted++;

                        if (vehicle == 'C')
                            cars++;
                        else
                            bikes++;

                        printf("Accepted: Emergency vehicle assigned to Zone B.\n");
                        printf("Remaining capacity: %d\n",capacityB - occupiedB);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone B is full.\n");
                    }
                }
            }
            else
            {
                if (vehicle == 'V')
                {
                    if (capacityC - occupiedC >= 2)
                    {
                        occupiedC += 2;
                        accepted++;
                        vans++;

                        printf("Accepted: Emergency van assigned to Zone C.\n");
                        printf("Remaining capacity: %d\n",capacityC - occupiedC);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone C does not have 2 spaces.\n");
                    }
                }
                else
                {
                    if (occupiedC < capacityC)
                    {
                        occupiedC++;
                        accepted++;

                        if (vehicle == 'C')
                            cars++;
                        else
                            bikes++;

                        printf("Accepted: Emergency vehicle assigned to Zone C.\n");
                        printf("Remaining capacity: %d\n",capacityC - occupiedC);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone C is full.\n");
                    }
                }
            }
        }

        else
        {
            if (permit == 'N')
            {
                rejected++;
                printf("Rejected: Invalid parking permit.\n");
            }
            else if (category == 'F')
            {
                if (vehicle == 'V')
                {
                    if (occupiedA < capacityA)
                    {
                        occupiedA++;
                        accepted++;
                        vans++;

                        printf("Accepted: Van assigned to Zone A.\n");
                        printf("Remaining capacity: %d\n",capacityA - occupiedA);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: No space available in Zone A.\n");
                    }
                }
                else
                {
                    if (occupiedA < capacityA)
                    {
                        occupiedA++;
                        accepted++;

                        if (vehicle == 'C')
                            cars++;
                        else
                            bikes++;

                        printf("Accepted: Vehicle assigned to Zone A.\n");
                        printf("Remaining capacity: %d\n",capacityA - occupiedA);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: No space available in Zone A.\n");
                    }
                }
            }
            else if (category == 'S')
            {
                if (vehicle == 'V')
                {
                    if (capacityC - occupiedC >= 2)
                    {
                        occupiedC += 2;
                        accepted++;
                        vans++;

                        printf("Accepted: Student van redirected to Zone C.\n");
                        printf("Remaining capacity: %d\n",capacityC - occupiedC);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: No space available in Zone C.\n");
                    }
                }
                else
                {
                    if (occupiedB < capacityB)
                    {
                        occupiedB++;
                        accepted++;

                        if (vehicle == 'C')
                            cars++;
                        else
                            bikes++;

                        printf("Accepted: Vehicle assigned to Zone B.\n");
                        printf("Remaining capacity: %d\n",capacityB - occupiedB);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: No space available in Zone B.\n");
                    }
                }
            }
            else
            {
                if (vehicle == 'V')
                {
                    if (capacityC - occupiedC >= 2)
                    {
                        occupiedC += 2;
                        accepted++;
                        vans++;

                        printf("Accepted: Visitor van assigned to Zone C.\n");
                        printf("Remaining capacity: %d\n",capacityC - occupiedC);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: Zone C needs at least 2 spaces.\n");
                    }
                }
                else
                {
                    if (occupiedC < capacityC)
                    {
                        occupiedC++;
                        accepted++;

                        if (vehicle == 'C')
                            cars++;
                        else
                            bikes++;

                        printf("Accepted: Visitor vehicle assigned to Zone C.\n");
                        printf("Remaining capacity: %d\n",capacityC - occupiedC);
                    }
                    else
                    {
                        rejected++;
                        printf("Rejected: No space available in Zone C.\n");
                    }
                }
            }
        }
    }
    printf("\n\n========================================\n");
    printf("          PARKING SUMMARY\n");
    printf("========================================\n");

    printf("Total vehicles processed : %d\n", n);
    printf("Total accepted vehicles  : %d\n", accepted);
    printf("Total rejected vehicles  : %d\n", rejected);

    printf("\nSuccessfully parked:\n");
    printf("Cars                     : %d\n", cars);
    printf("Bikes                    : %d\n", bikes);
    printf("Vans                     : %d\n", vans);

    printf("\nZone A - Faculty\n");
    printf("Occupied                 : %d\n", occupiedA);
    printf("Remaining capacity       : %d\n",capacityA - occupiedA);

    printf("\nZone B - Students\n");
    printf("Occupied                 : %d\n", occupiedB);
    printf("Remaining capacity       : %d\n",capacityB - occupiedB);

    printf("\nZone C - Visitors\n");
    printf("Occupied                 : %d\n", occupiedC);
    printf("Remaining capacity       : %d\n",capacityC - occupiedC);
    if (occupiedA >= occupiedB && occupiedA >= occupiedC)
    {
        printf("\nZone with highest occupancy: Zone A\n");
    }
    else if (occupiedB >= occupiedA && occupiedB >= occupiedC)
    {
        printf("\nZone with highest occupancy: Zone B\n");
    }
    else
    {
        printf("\nZone with highest occupancy: Zone C\n");
    }

    if (occupiedA == capacityA && occupiedB == capacityB && occupiedC == capacityC)
    {
        printf("Entire campus parking facility is FULL.\n");
    }
    else
    {
        printf("Entire campus parking facility is NOT FULL.\n");
    }

    printf("========================================\n");
}
