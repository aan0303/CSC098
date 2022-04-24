#include <stdio.h>
int main()
// Made by Ainul
{

    char type;
    float weight, bill;
    int quantity, x = 0;

    printf("\n\t\t*BUGGAGE ALLOWANCE*\n\n");
    printf("-------------------------------------------------------------\n");
    printf("|Weight Category\t\t|         Domestic          |\n");
    printf("|\t\t\t\t|---------------------------|\n");
    printf("|\t\t\t\t|Online(MYR) | Counter(MYR) | \n");
    printf("|-----------------------------------------------------------|\n");
    printf("|0-20kg \t\t\t|    Free    |     Free     |\n");
    printf("|21-25kg\t\t\t|     60     |      75      |\n");
    printf("|26-30kg\t\t\t|    120     |     150      |\n");
    printf("|31-35kg\t\t\t|    180     |     225      |\n");
    printf("-------------------------------------------------------------\n\n");

    printf("Payment type;\n");
    printf("O = Online\n");
    printf("C = Counter\n\n");

    do
    {
        printf("Insert Payment Type: ");
        scanf(" %c", &type);

        printf("Weight (kg) : ");
        scanf("%f", &weight);
        if (type == 'O' || type == 'o')
        {

            if (weight > 0 && weight <= 20)
            {
                printf("Your bill : FREE  ");
                x = 0;
            }
            else if (weight >= 21 && weight <= 25)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 60;
                printf("Bill = RM%.2f", bill);
                x = 0;
            }
            else if (weight >= 26 && weight <= 30)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 120;
                printf("Bill = RM%.2f", bill);
                x = 0;
            }
            else if (weight >= 31 && weight <= 35)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 180;
                printf("Bill = RM%.2f", bill);
                x = 0;
            }
            else
            {
                printf("invalid\n");
                x++;
            }
        }

        else if (type == 'C' || type == 'c')
        {

            if (weight > 0 && weight <= 20)
            {
                printf("Your bill : FREE  ");
                x = 0;
            }
            else if (weight >= 21 && weight <= 25)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 75;
                printf("Bill = RM%.2f", bill);
                x = 0;
            }
            else if (weight >= 26 && weight <= 30)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 150;
                printf("Bill = RM%.2f", bill);
                x = 0;
            }
            else if (weight >= 31 && weight <= 35)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 225;
                printf("Bill = RM%.2f", bill);
                x = 0;
            }
            else
            {
                printf("invalid\n");
                x++;
            }
        }
        else
        {
            printf("invalid\n");
            x++;
        }

    } while (x >= 1);

    return 0;
}