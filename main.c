/*
    programmer : Siddhanta Choudhury
    Date : 25/7/2001
*/

#include"hospital.h"

int main()
{
    int choice;

    login();

    usleep(1000000);
    printf("\n\t\t\t\tPress Enter to continue.........");
    getch();

    choice = menu();

    usleep(1000000);
    printf("\n\t\t\t\tPress Enter to continue.........");
    getch();


    return 0;

}
