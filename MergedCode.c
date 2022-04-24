#include <stdio.h>
#include <string.h>

void UserInfo();

int Booking();
void ListDestination();

void InflightMeals();
void ListMeals();

void BaggageAllowance();
void ListBaggageAllowance();

void Aircraft();
void Logo();

void Condition();
char name[200], nationality[200], placeOfBirth[200];
int age, canContinue = 1;

float totalMeal = 0, totalPriceTicket, totalPrice, totalBaggage;

int main()
{

    int menu;
    char wantContinue;

    Logo();
    UserInfo();
    Condition();

    while (canContinue == 1)
    {

        printf("%81s", "----------------Menu----------------\n\n");

        printf("%61s", "[0] Start Booking\n");
        printf("%67s", "[1] Display Destination\n");
        printf("%70s", "[2] Display Inflight Meals\n");
        printf("%73s", "[3] Display Baggage Allowance\n");

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
        case 3:
            ListBaggageAllowance();
            canContinue = 0;
            break;
        default:
            printf("\n\n%66s\n", "Invalid Input Number 1");
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
    char destinationCharacter, destinationName[60], departure[60], arrival[60], continueMeal;
    float discount, priceDiscount, ticketPrice;

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
        printf("\n%67s", "Invalid Input Number 2");
        canContinue2 = 0;
        break;
    }

    if (canContinue2 == 1)
    {

        printf("\n%84s", "Please insert number of tickets you want to buy: ");
        scanf("%d", &numberTicket);
        totalPriceTicket = numberTicket * ticketPrice;

        printf("%68s %.2f\n", "Total Price Ticket: ", totalPriceTicket);

        InflightMeals();
        BaggageAllowance();

        printf("\n\n");
        printf("%79s", "-----Personal Information------\n\n");
        printf("%63s %s\n", "Name:", name);
        printf("%63s %d\n", "Age:", age);
        printf("%63s %s\n", "Nationality:", nationality);
        printf("%63s %s\n", "Place of birth:", placeOfBirth);

        printf("\n%78s\n", "--------------Receipt--------------");

        printf("\n%63s%s\n", "Destination: ", destinationName);
        printf("%63s%s\n", "Departure Time: ", departure);
        printf("%63s%s\n", "Arrival Time: ", arrival);

        totalPrice = totalBaggage + totalMeal + totalPriceTicket;

        if (totalPrice > 500)
        {
            totalPrice *= 0.9;
            printf("%62s %d\n%65s%.2f", "Total number ticket:", numberTicket, "Overall Total: RM", totalPrice);
            printf("\n\n%102s\n%78s", "Due to the pandemic of Covid 19, Selangor Airways will give a 10%% discount ", "for customers with a total price more than RM500.00.");

            Aircraft();
        }
        else
        {
            printf("%62s %d\n%65s%.2f", "Total number ticket:", numberTicket, "Overall Total: RM", totalPrice);

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
    printf("%107s", "[F]             Alor Setar            12:00am           2:00pm           RM210.50 \n");
}

void UserInfo()
{

    printf("\n\n");
    printf("%82s", "-------------User Info--------------\n\n");

    printf("%69s", "Insert your full name: ");
    gets(name);

    printf("%69s", "Please insert your nationality: ");
    gets(nationality);

    printf("%69s", "Place of birth: ");
    gets(placeOfBirth);

    printf("%69s", "Please insert your age: ");
    scanf("%d", &age);
}

void Condition()
{
    int numberOfTerms = 2, i;
    char terms1, terms2;

    if (age < 18)
    {
        printf("\n");
        printf("%98s", "Sorry but you're not permitted to travel alone at the age of below 18\n");
        canContinue = 0;
    }
    else
    {
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

        if ((terms1 == 'y' || terms1 == 'Y') && (terms2 == 'y' || terms2 == 'Y'))
        {
            printf("\n");
            printf("%77s", "Thank you for your cooperation\n\n");
        }
        else
        {
            printf("\n");
            printf("%120s", "Due to the fact that you doesn't agree with our terms and regulations we cannot continue this operation.\n");
            canContinue = 0;
        }
    }
}

void ListMeals()
{
    printf("\n");
    printf("%81s", "----------------Meal----------------\n\n");

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
    float price[6] = {15.00, 15.00, 7.00, 15.00, 10.00, 13.00}, priceMeal;

    ListMeals();
    printf("\n");
    printf("%80s", "Enter code 7 to skip this operation\n");

    do
    {
        printf("\n");
        printf("%72s", "Enter code of meal: ");
        scanf("%d", &meal);

        if (meal == 7)
        {
            repeat = 'n';
        }
        else
        {
            printf("%72s", "Total: ");
            scanf("%d", &num);

            switch (meal)
            {
            case 1:
                priceMeal = num * price[meal - 1];
                break;
            case 2:
                priceMeal = num * price[meal - 1];
                break;
            case 3:
                priceMeal = num * price[meal - 1];
                break;
            case 4:
                priceMeal = num * price[meal - 1];
                break;
            case 5:
                priceMeal = num * price[meal - 1];
                break;
            case 6:
                priceMeal = num * price[meal - 1];
                break;
            default:
                printf("\n");
                printf("%78s", "Please enter right code of meal\n");
                break;
            }

            totalMeal += priceMeal;
            printf("\n");
            printf("%80s", "Do you want to book another meal (Y/N): ");
            scanf(" %c", &repeat);
        }
    } while (repeat == 'Y' || repeat == 'y');

    if (meal == 7)
        printf("%63s\n", "Price meal: RM0.00");
    else
        printf("%63s %.2f\n", "Price Meal:", totalMeal);
}

void ListBaggageAllowance()
{
    printf("\n");
    printf("%81s", "-------------Baggage Allowance---------\n\n");
    printf("\t\t\t\t\t---------------------------------------------\n");
    printf("\t\t\t\t\t|Weight Category|         Domestic          |\n");
    printf("\t\t\t\t\t|               |---------------------------|\n");
    printf("\t\t\t\t\t|               |Online(MYR) | Counter(MYR) | \n");
    printf("\t\t\t\t\t|-------------------------------------------|\n");
    printf("\t\t\t\t\t|0-20kg         |    Free    |     Free     |\n");
    printf("\t\t\t\t\t|21-25kg        |     60     |      75      |\n");
    printf("\t\t\t\t\t|26-30kg        |    120     |     150      |\n");
    printf("\t\t\t\t\t|31-35kg        |    180     |     225      |\n");
    printf("\t\t\t\t\t---------------------------------------------");
}

void BaggageAllowance()
{
    char type;
    float weight;
    int quantity, x = 0;

    ListBaggageAllowance();

    printf("\n\n");
    printf("%67s", "Payment Type\n");
    printf("%65s", "O : Online\n");
    printf("%67s", "C : Counter\n\n");

    do
    {
        printf("%72s", "Insert Payment Type: ");
        scanf(" %c", &type);

        printf("%65s", "Weight (kg) : ");
        scanf("%f", &weight);

        if (type == 'O' || type == 'o')
        {

            if (weight > 0 && weight <= 20)
            {
                printf("%79s", "Baggage Allowance Bill: Free");
                x = 0;
            }
            else if (weight >= 21 && weight <= 25)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                totalBaggage = quantity * 60;
                printf("Bill = RM%.2f", totalBaggage);
                x = 0;
            }
            else if (weight >= 26 && weight <= 30)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                totalBaggage = quantity * 120;
                printf("Bill = RM%.2f", totalBaggage);
                x = 0;
            }
            else if (weight >= 31 && weight <= 35)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                totalBaggage = quantity * 180;
                printf("Bill = RM%.2f", totalBaggage);
                x = 0;
            }
            else
            {
                printf("\n%67s", "Invalid\n\n");
                x++;
            }
        }

        else if (type == 'C' || type == 'c')
        {

            if (weight >= 0 && weight <= 20)
            {
                printf("%82s", "Baggage Allowance Bill: Free");
                x = 0;
            }
            else if (weight >= 21 && weight <= 25)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                totalBaggage = quantity * 75;
                printf("Bill = RM%.2f", totalBaggage);
                x = 0;
            }
            else if (weight >= 26 && weight <= 30)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                totalBaggage = quantity * 150;
                printf("Bill = RM%.2f", totalBaggage);
                x = 0;
            }
            else if (weight >= 31 && weight <= 35)
            {
                printf("Quantity : ");
                scanf("%d", &quantity);
                totalBaggage = quantity * 225;
                printf("Bill = RM%.2f", totalBaggage);
                x = 0;
            }
            else
            {
                printf("\n%63s", "Invalid\n\n");
                x++;
            }
        }
        else
        {
            printf("\n%63s", "Invalid\n\n");
            x++;
        }

    } while (x >= 1);
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

void Logo()
{
    /*----------------------------------------------------------------THIS IS ART------------------------------------------------------------*/
    printf("              888                                                     ,e,                                          \n");
    printf(" dP\"Y  ,e e,  888  ,\"Y88b 888 8e   e88 888  e88 88e  888,8,    ,\"Y88b  \"  888,8, Y8b Y8b Y888P  ,\"Y88b Y8b Y888P  dP\"Y \n");
    printf("C88b  d88 88b 888 \"8\" 888 888 88b d888 888 d888 888b 888 \"    \"8\" 888 888 888 \"   Y8b Y8b Y8P  \"8\" 888  Y8b Y8P  C88b  \n");
    printf(" Y88D 888   , 888 ,ee 888 888 888 Y888 888 Y888 888P 888      ,ee 888 888 888      Y8b Y8b \"   ,ee 888   Y8b Y    Y88D \n");
    printf("d,dP   \"YeeP\" 888 \"88 888 888 888  \"88 888  \"88 88\"  888      \"88 888 888 888       YP  Y8P    \"88 888    888    d,dP  \n");
    printf("                                    ,  88P                                                                888          \n");
    printf("                                   \"8\",P\"                                                                 888          \n\n\n");
    /*----------------------------------------------------------------THIS IS ART------------------------------------------------------------*/
}
