#include <stdio.h>
#include <string.h>
// Made by Megat
void Booking(void);
void Destination(void);

int main()
{

    int menu, canContinue = 1;
    char wantContinue;

    while (canContinue == 1)
    {

        printf("%81s", "----------------Menu----------------\n\n");

        printf("%61s", "[0] Start Booking\n");
        printf("%67s", "[1] Display Destination\n");

        printf("\n\n%94s", "Choose the number provided in the menu to go to your desired page: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            Booking();
            canContinue = 0;
            break;
        case 1:
            Destination();
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

void Booking(void)
{
    Destination();

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

        printf("\n%78s\n", "--------------Receipt--------------");

        printf("\n%63s%s\n", "Destination: ", destinationName);
        printf("%63s%s\n", "Departure Time: ", departure);
        printf("%63s%s\n", "Arrival Time: ", arrival);

        if (totalPrice > 500)
        {
            discount = 0.9;
            priceDiscount = discount * totalPrice;
            printf("%65s%.2f\n%62s %d", "Total ticket price: RM", priceDiscount, "Total number ticket:", numberTicket);
            printf("\n\n%102s\n%78s", "Due to the pandemic of Covid 19, Selangor Airways will give a 10% discount ", "for customers with a total price more than RM500.00.");
        }
        else
        {
            printf("%65s%.2f\n%63s%d", "Total ticket price: RM", totalPrice, "Number of ticket: ", numberTicket);
        }
    }
}

void Destination(void)
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
