// Programs a Mizzou Airline Reservation System
// Created by Natalie Myers on 10/12/18

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW 12
#define COL 6
#define MAX 25

int costMatrix[ROW][COL]= // initializes cost per seat
        {
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500},
                {500, 200, 500, 500, 200, 500}
        };

void initialSeats(char[][COL], int);
void displayMenu();
void printFlightMap(char[][COL]);
int loginMatch(int, int);
int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL]);
void flightMenu();
void seatReservation(char flight[][COL]);
void printMessage(char name[], char num[]);

int main(void) {

    char flight1[ROW][COL], flight2[ROW][COL], flight3[ROW][COL], name[MAX];
    int user_selection, passcode, flight_selected, revenue;
    int adminPasscode = 105018;
    srand(time(NULL));
    int seats;
    seats = rand() % 20 + 1;
    initialSeats(flight1, seats);
    seats = rand() % 20 + 1;
    initialSeats(flight2, seats);
    seats = rand() % 20 + 1;
    initialSeats(flight3, seats);
    printf("\n********* WELCOME TO MIZZOU AIRLINE BOOKING SYSTEM *********\n\n");
    while (1 == 1) { // while true loop to repeat program functions
        displayMenu();
        scanf("%d", &user_selection);
        while (user_selection <= 0 || user_selection > 3) { // error checks
            printf("Wrong option! Choose a right option\n\n");
            displayMenu();
            scanf("%d", &user_selection);
        }
        if (user_selection == 1) { // conditional for first menu selection
            printf("\nEnter the login passcode to log in as admin: ");
            scanf("%d", &passcode);
            loginMatch(passcode, adminPasscode);
            while (loginMatch(passcode, adminPasscode) == 0) { // error checks passcode
                printf("Invalid Passcode combination\n\nEnter the login passcode to log in as admin: ");
                scanf("%d", &passcode);
            }
            if (loginMatch(passcode, adminPasscode) == 1) { // conditional for correct passcode
                printf("Printing the Flight Map of flight Columbia to Miami....\n");
                printFlightMap(flight1);
                printf("Printing the Flight Map of flight Columbia to Nashville....\n");
                printFlightMap(flight2);
                printf("Printing the Flight Map of flight Columbia to Las Vegas....\n");
                printFlightMap(flight3);
                revenue = getTotalRevenue(flight1, flight2, flight3);
                printf("The total earning from all the flights: $%d\nYou are logged out now!\n", revenue);
            }
        } else if (user_selection == 2) { // conditional for second menu selection
            printf("\n");
            flightMenu();
            scanf("%d", &flight_selected);
            while (flight_selected <= 0 || flight_selected > 3) { // error checks
                printf("\n");
                flightMenu();
                scanf("%d", &flight_selected);
            }
            if (flight_selected == 1) { // conditional for first flight selection
                char flight_num1[] = "MIA1050";
                printf("Enter your first name: ");
                scanf("%s", &name[MAX]);
                printFlightMap(flight1);
                seatReservation(flight1);
                printf("Congrats %s!! Your flight %s is booked; enjoy your trip.\n", name, flight_num1);
                printMessage(name, flight_num1);
                printf("Enjoy your Thanksgiving Break :)\n");
            } else if (flight_selected == 2) { // conditional for second flight selection
                char flight_num2[] = "BNA1050";
                printf("Enter your first name: ");
                scanf("%s", &name[MAX]);
                printFlightMap(flight2);
                seatReservation(flight2);
                printf("Congrats %s!! Your flight %s is booked; enjoy your trip.\n", name, flight_num2);
                printMessage(name, flight_num2);
                printf("Enjoy your Thanksgiving Break :)\n");
            } else { // default for third flight selection
                char flight_num3[] = "LAS1050";
                printf("Enter your first name: ");
                scanf("%s", &name[MAX]);
                printFlightMap(flight3);
                seatReservation(flight3);
                printf("Congrats %s!! Your flight %s is booked; enjoy your trip.\n", name, flight_num3);
                printMessage(name, flight_num3);
                printf("Enjoy your Thanksgiving Break :)\n");
            }
        } else { // default for third menu selection
            printf("\nTerminating the Program\nThank you for using Mizzou Airline Booking System.");
            break;
        }
    }
    return 0;
}

void initialSeats(char flight[ROW][COL], int count) { // initializes randomized seats
    int i, j, row, col;

    for (i = 0; i < ROW; i++) { // iterates through rows
        for (j = 0; j < COL; j++) { // iterates through columns
            flight[i][j] = 'O';
        }
    }

    for (i = 0; i < count; i++) { // iterates through randomized occupied seat number
        row = rand() % ROW;
        col = rand() % COL;
        while (flight[row][col] == 'X') { // conditional for already randomized to occupied seat
            row = rand() % ROW;
            col = rand() % COL;
        }
        flight[row][col] = 'X';
    }
}

void displayMenu(){ // displays menu options
    printf("\n1.) Admin Log-in\n2.) Reserve a seat\n3.) Exit\nChoose an option: ");
}

int loginMatch(int passcode, int adminPasscode) { // error check for admin login
    if (passcode == adminPasscode){ // checks if inout matches passcode
        return 1;
    } else { // default for incorrect passcode
        return 0;
    }
}

void flightMenu() { // prints flight menu options
    printf("1.) COU ----> MIA\n2.) COU ----> BNA\n3.) COU ----> LAS\nChoose a flight: ");
}

void printFlightMap(char flight[][COL]) { // prints seat layouts for flights
    int i, j;
    for (i = 0; i < ROW; i++) { // iterates through rows
        for (j = 0; j < COL; j++) { // iterates through columns
            printf("%3c", flight[i][j]);
        }
        printf("\n");
    }
}
int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL]) { // calculates total earnings from flights

    int i ,j;
    int revenue = 0;

    for (i = 0; i < ROW; i++) { // iterates through rows
        for (j = 0; j < COL; j++) { // iterates through columns
            if (flight1[i][j] == 'X') { // conditional for occupied seats
                revenue += costMatrix[i][j];
            }
        }
    }
    for (i = 0; i < ROW; i++) { // iterates through rows
        for (j = 0; j < COL; j++) { // iterates through columns
            if (flight2[i][j] == 'X') { // conditional for occupied seats
                revenue += costMatrix[i][j];
            }
        }
    }
    for (i = 0; i < ROW; i++) { // iterates through rows
        for (j = 0; j < COL; j++) { // iterates through columns
            if (flight3[i][j] == 'X') { // conditional for occupied seats
                revenue += costMatrix[i][j];
            }
        }
    }
    return revenue;
}

void seatReservation(char flight[][COL]) { // reserves a seat on selected flight

    int row_selected, col_selected;

    printf("Which seat row do you want?: ");
    scanf("%d", &row_selected);
    while (row_selected < 0 || row_selected > 11) { // error checks for correct row selection
        printf("Seat rows are between 0 to 11.\nTry Again. Which seat row do you want?: ");
        scanf("%d", &row_selected);
    }
    printf("Which seat column do you want?: ");
    scanf("%d", &col_selected);
    while (col_selected < 0 || col_selected > 5) { // error checks for correct column selection
        printf("Seat columns are between 0 to 5.\nTry Again. Which seat column do you want?: ");
        scanf("%d", &col_selected);
    }

    while (flight[row_selected][col_selected] == 'X') { // conditional for taken seats
        printf("Sorry!! Someone has reserved that seat. Please try again.");
        printf("\nWhich seat row do you want?: ");
        scanf("%d", &row_selected);
        while (row_selected < 0 || row_selected > 11) { // error checks for correct row selection
            printf("Seat rows are between 0 to 11.\nTry Again. Which seat row do you want?: ");
            scanf("%d", &row_selected);
        }
        printf("Which seat column do you want?: ");
        scanf("%d", &col_selected);
        while (col_selected < 0 || col_selected > 5) { // error checks for correct column selection
            printf("Seat columns are between 0 to 5.\nTry Again. Which seat column do you want?: ");
            scanf("%d", &col_selected);
        }
    }
    flight[row_selected][col_selected] = 'X';
    printf("Your requested seat has been reserved\n");
    printFlightMap(flight);
}

void printMessage(char name[], char num[]) { // prints final message
    char message[MAX];
    int i = 0;
    int namei = 0;
    int numi = 0;

    while (1 == 1) { // while true loop to repeat until all strings are null
        if (name[namei] != '\0') { // conditional for name string until it ends
            message[i] = name[namei];
            namei++;
            i++;
        } if (num[numi] != '\0') { // conditional for num string until it ends
            message[i] = num[numi];
            numi++;
            i++;
        }
        if (num[numi] == '\0' && name[namei] == '\0') { // check for if both strings have ended
            message[i] = '\0';
            break;
        }
    }
    printf("Your e-ticket number is: %s\n\n", message);
}

/*
void getSafeString(char *string, int maxsize) {

    int indexcur = 0;
    char charcur = '\n';

    while ('\n'==charcur){
        charcur = getc(stdin);
    }
    while (indexcur<(maxsize-1) && '\n'!=charcur)
    {
        if ('\n'!=charcur)
        {
            string[indexcur] = charcur;
        }
        indexcur++;
        charcur = getc(stdin);
    }
    string[indexcur] = '\0';

    while ('\n'!=charcur)
    {
        charcur = getc(stdin);
    }
}
*/
