#include <stdio.h>
#include <string.h>

int Booking();
void ListDestination();
void Aircraft();
void UserInfo();
void ListMeals();
void InflightMeals();

char name[200], nationality[200], placeOfBirth[200];
int age;

int main()
{

    int menu;
    char wantContinue;
    int canContinue = 1;

    /*----------------------------------------------------------------THIS IS ART------------------------------------------------------------*/
    printf("              888                                                     ,e,                                          \n");
    printf(" dP\"Y  ,e e,  888  ,\"Y88b 888 8e   e88 888  e88 88e  888,8,    ,\"Y88b  \"  888,8, Y8b Y8b Y888P  ,\"Y88b Y8b Y888P  dP\"Y \n");
    printf("C88b  d88 88b 888 \"8\" 888 888 88b d888 888 d888 888b 888 \"    \"8\" 888 888 888 \"   Y8b Y8b Y8P  \"8\" 888  Y8b Y8P  C88b  \n");
    printf(" Y88D 888   , 888 ,ee 888 888 888 Y888 888 Y888 888P 888      ,ee 888 888 888      Y8b Y8b \"   ,ee 888   Y8b Y    Y88D \n");
    printf("d,dP   \"YeeP\" 888 \"88 888 888 888  \"88 888  \"88 88\"  888      \"88 888 888 888       YP  Y8P    \"88 888    888    d,dP  \n");
    printf("                                    ,  88P                                                                888          \n");
    printf("                                   \"8\",P\"                                                                 888          \n\n\n");
    /*----------------------------------------------------------------THIS IS ART------------------------------------------------------------*/

    UserInfo();

    while (canContinue == 1)
    {

        printf("%81s", "----------------Menu----------------\n\n");

        printf("%61s", "[0] Start Booking\n");
        printf("%67s", "[1] Display Destination\n");
        printf("%70s", "[2] Display Inflight Meals\n");

        printf("\n\n%94s", "Choose the number provided in the menu to go to your desired page: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            Booking();
            canContinue = 0;
            break;
        case 1:
            ListDestination();
            canContinue = 0;
            break;
        case 2:
            ListMeals();
            canContinue = 0;
            break;
        default:
            printf("\n\n%66s\n", "Invalid Input");
            canContinue = 0;
            break;
        }

        printf("\n\n%79s\n\n", "--------------Shutdown--------------");

        printf("\n%85s", "Do you still want to choose other menu? [y/n]: ");
        scanf(" %c", &wantContinue);

        if (wantContinue == 'y')
        {
            printf("\n\n");
            canContinue = 1;
        }
        else
        {
            canContinue = 0;
        }
    }
}

int Booking()
{
    ListDestination();

    int numberTicket, canContinue2 = 1;
    char destinationCharacter, destinationName[60], departure[60], arrival[60];
    float totalPrice, discount, priceDiscount, ticketPrice;

    printf("\n\n%96s", "Please choose your desired destination based on the destination code: ");
    scanf(" %c", &destinationCharacter);

    switch (destinationCharacter)
    {
    case 'A':
        strcpy(destinationName, "Kuantan");
        strcpy(departure, "9:30am");
        strcpy(arrival, "10:40pm");
        ticketPrice = 185.5;

        break;
    case 'B':
        strcpy(destinationName, "Kuala Terengganu");
        strcpy(departure, "10:30am");
        strcpy(arrival, "12:00pm");
        ticketPrice = 190.5;

        break;
    case 'C':
        strcpy(destinationName, "Kota Bharu");
        strcpy(departure, "11:30am");
        strcpy(arrival, "1:30pm");
        ticketPrice = 210.0;

        break;
    case 'D':
        strcpy(destinationName, "Johor Bharu");
        strcpy(departure, "11:30am");
        strcpy(arrival, "11:15pm");
        ticketPrice = 185.5;

        break;
    case 'E':
        strcpy(destinationName, "Penang");
        strcpy(departure, "11:00am");
        strcpy(arrival, "12:30pm");
        ticketPrice = 190.5;

        break;
    case 'F':
        strcpy(destinationName, "Alor Setar");
        strcpy(departure, "12:00am");
        strcpy(arrival, "2:00pm");
        ticketPrice = 210.5;

        break;
    default:
        printf("\n%67s", "Invalid Input");
        canContinue2 = 0;
        break;
    }

    if (canContinue2 == 1)
    {

        printf("\n%84s", "Please insert number of tickets you want to buy: ");
        scanf("%d", &numberTicket);
        totalPrice = numberTicket * ticketPrice;

        printf("\n\n");
        printf("%79s", "-----Personal Information------\n\n");
        printf("%63s %s", "Name:", name);
        printf("%63s %d\n", "Age:", age);
        printf("%63s %s", "Nationality:", nationality);
        printf("%63s %s\n", "Place of birth:", placeOfBirth);

        printf("\n%78s\n", "--------------Receipt--------------");

        printf("\n%63s%s\n", "Destination: ", destinationName);
        printf("%63s%s\n", "Departure Time: ", departure);
        printf("%63s%s\n", "Arrival Time: ", arrival);

        if (totalPrice > 500)
        {
            discount = 0.1;
            priceDiscount = discount * totalPrice;
            printf("%65s%.2f\n%62s %d", "Total ticket price: RM", totalPrice, "Total number ticket:", numberTicket);
            printf("\n\n%102s\n%78s", "Due to the pandemic of Covid 19, Selangor Airways will give a 10%% discount ", "for customers with a total price more than RM500.00.");

            Aircraft();
        }
        else
        {
            printf("%65s%.2f\n%63s%d", "Total ticket price: RM", totalPrice, "Number of ticket: ", numberTicket);

            Aircraft();
        }
    }
}

void ListDestination()
{

    printf("\n\n%79s\n", "-------Available Destinations-------");

    printf("\n\n%107s\n", "Destination Code      Destination         Departure Time     Arrival Time      Ticket Price");
    printf("%107s", "[A]             Kuantan               9:30am            10:40pm          RM185.50 \n");
    printf("%107s", "[B]             Kuala Terengganu      10:30am           12:00pm          RM190.50 \n");
    printf("%107s", "[C]             Kota Bharu            11:30am           1:30pm           RM210.00 \n");
    printf("%107s", "[D]             Johor Bharu           10:00am           11:15pm          RM185.50 \n");
    printf("%107s", "[E]             Penang                11:00am           12:30pm          RM190.50 \n");
    printf("%107s", "[F]             Alor Setar            12:00am           2:00pm           RM210.00 \n");
}

void Aircraft()
{

    printf("\n\n%80s\n\n", "Thanks for choosing Selangor Airways!");

    printf("%90s", "______                                                    \n");
    printf("%90s", "         _\\ _~-\\___                                       \n");
    printf("%90s", " =  = ==(____AA____D                                      \n");
    printf("%90s", "             \\_____\\___________________,-~~~~~~~`-.._     \n");
    printf("%90s", "             /     o O o o o o O O o o o o o o O o  |\\_   \n");
    printf("%90s", "             `~-.__        ___..----..                  ) \n");
    printf("%90s", "                   `---~~\\___________/------------`````   \n");
    printf("%90s", "                   =  ===(_________D                      \n");
}

void UserInfo()
{
    char terms1, terms2;
    int birthYear, i, numberOfTerms = 2;

    printf("\n\n");
    printf("%82s", "-------------User Info--------------\n\n");

    printf("%62s", "Insert your full name: ");
    gets(name);

    printf("%62s", "Please insert your nationality: ");
    gets(nationality);

    printf("%62s", "Place of birth: ");
    gets(placeOfBirth);

    printf("%62s", "Please insert your age: ");
    scanf("%d", &age);

    if (age < 18)
    {
        printf("%80s", "Sorry but you're not permitted to travel alone at the age of below 18\n");
    }

    printf("\n\n");
    printf("%81s", "-------Terms and Regulations--------\n\n");
    printf("%97s", "Please read the terms accordingly and agree to continue this operation");

    for (i = 0; i < numberOfTerms; i++)
    {
        switch (i)
        {
        case 0:
        {
            printf("\n\n");
            printf("%102s", "Customers must arrive at the departure stations 30 mins before take off (y/n): ");
            scanf(" %c", &terms1);
            break;
        }
        case 1:
        {
            printf("\n");
            printf("%110s", "Customers should not bring any dangerous substance or alcholic drinks on the aircraft (y/n): ");
            scanf(" %c", &terms2);
            break;
        }
        }
    }

    if (terms1 == 'y' && terms2 == 'y')
    {
        printf("\n");
        printf("%77s", "Thank you for your cooperation\n\n");
    }
    else
    {
        printf("\nDue to the fact that you doesn't agree with our terms and regulations we cannot continue this operation.");
    }
}

void ListMeals()
{
    printf("\n");
    printf("%81s", "----------------Meal----------------\n");

    printf("%82s", "[1] Nasi lemak               (RM15.00)\n");
    printf("%82s", "[2] Nasi kandar              (RM15.00)\n");
    printf("%82s", "[3] Sandwich                 (RM 7.00)\n");
    printf("%82s", "[4] Nasi goreng ayam         (RM15.00)\n");
    printf("%82s", "[5] Mee kari                 (RM10.00)\n");
    printf("%82s", "[6] Spaghetti bolognese      (RM13.00)\n");
}

void InflightMeals()
{
    int num;
    char meal, repeat;
    float price[6] = {15.00, 15.00, 7.00, 15.00, 10.00, 13.00}, totalPrice = 0;

    ListMeals();

    do
    {
        printf("\nEnter code of meal: ");
        scanf("%d", &meal);
        printf("Total: ");
        scanf("%d", &num);

        switch (meal)
        {
        case 1:
            totalPrice = num * price[meal - 1];
            break;
        case 2:
            totalPrice = num * price[meal - 1];
            break;
        case 3:
            totalPrice = num * price[meal - 1];
            break;
        case 4:
            totalPrice = num * price[meal - 1];
            break;
        case 5:
            totalPrice = num * price[meal - 1];
            break;
        case 6:

            totalPrice = num * price[meal - 1];
            break;
        default:
            printf("Please enter right code of meal\n");
            break;
        }

        printf("Do you want to book another meal (Y/N): ");
        scanf(" %c", &repeat);

    } while (repeat == 'Y' || repeat == 'y');

    printf("\nTotal price: %.2f", totalPrice);
}

BaggageAllowance()
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

        if (type == 'O' || type == 'o')
        {
            printf("Weight (kg) : ");
            scanf("%f", &weight);

            if (weight > 0 && weight <= 20)
            {
                printf("Your bill : FREE  ");
                break;
            }
            else if (weight >= 21 && weight <= 25)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 60;
                printf("Bill = RM%.2f", bill);
                break;
            }
            else if (weight >= 26 && weight <= 30)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 120;
                printf("Bill = RM%.2f", bill);
                break;
            }
            else if (weight >= 31 && weight <= 35)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 180;
                printf("Bill = RM%.2f", bill);
                break;
            }
            else
            {
                printf("invalid\n");
                x++;
            }
        }

        else if (type == 'C' || type == 'c')
        {
            printf("Weight (kg) : ");
            scanf("%f", &weight);

            if (weight > 0 && weight <= 20)
            {
                printf("Your bill : FREE  ");
                break;
            }
            else if (weight >= 21 && weight <= 25)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 75;
                printf("Bill = RM%.2f", bill);
                break;
            }
            else if (weight >= 26 && weight <= 30)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 150;
                printf("Bill = RM%.2f", bill);
                break;
            }
            else if (weight >= 31 && weight <= 35)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                bill = quantity * 225;
                printf("Bill = RM%.2f", bill);
                break;
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
