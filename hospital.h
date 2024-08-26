#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

struct Patients {

    int slNo;
    char disease[30];
    char name[30];
    int age;
    int cabinNo;
    char phoneNo[14];
    char sex;
}p;

struct Date {

    int year;
    int month;
    int date;
};

FILE *fp;
FILE *ptr;

void greet();
int menu();

int takeIntegerInput();
void login();
void addPatient();
void searchPatient();
void editPatient();
void deletePatient();
void viewPatient();


void login() {

    char user_id[15] = "Siddhanta";
    char password[15] = "Siddhanta";
    char u_id[15],pw[15];

    start:
    puts("\n");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\t\t\t\t|-------------------------- LOG IN ---------------------------|");
    puts("\t\t\t\t|------------- SUB DIVISIONAL HOSPITAL, KUCHINDA -------------|");
    puts("\t\t\t\t---------------------------------------------------------------");


    puts("\n\n\t\t\t\t\t Enter Username and Password\n\n");
    printf("\n\n\t\t\t\t\t\tUSER ID : ");
    scanf("%[^\n]%*c",u_id);

    printf("\t\t\t\t\t\tPassword: ");
    scanf("%[^\n]%*c",pw);

    if ( strcmp(user_id,u_id) == 0 && strcmp(pw,password) == 0 ) {
        usleep(1000000);
        printf("\n\n\t\t\t\t\t Log in Successfully...........\n");
    } else {
        usleep(1000000);
        printf("\n\n\t\t\t\t\t Wrong Password.Please Try again...........\n");
        fflush(stdin);
        goto start;
    }
}

int menu() {

    system("cls");
    int choice;

    puts("\n");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\t\t\t\t|--------------------------  MENU  ---------------------------|");
    puts("\t\t\t\t|------------- SUB DIVISIONAL HOSPITAL, KUCHINDA -------------|");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\n");

    puts("\n\t\t\t\t1. Add new patient record");
      puts("\t\t\t\t2. Search patient's record");
      puts("\t\t\t\t3. Edit patient's record");
      puts("\t\t\t\t4. Delete patient's record");
      puts("\t\t\t\t5. view all patient's record");
      puts("\t\t\t\t6. Exit");

      start:
      choice = takeIntegerInput();

    switch(choice)
    {

        case 1:
            {
                //add
                addPatient();
                break;
            }
        case 2:
            {
                searchPatient();
                break;
            }
        case 3:
            {
                break;
            }
        case 4:
            {
                break;
            }
        case 5:
            {
                viewPatient();
                break;
            }
        case 6:
            {
                exit(6);
            }
        default:
            {
                usleep(1000000);
                printf("\n\n\t\t\t\tPlease Enter a integer between 1 to 6 .");
                goto start;
            }
        }


}

int takeIntegerInput() {

    int n;

    start:
    printf("\n\n\t\t\t\tEnter your choice: ");

    while ( !scanf("%d",&n))
    {
        fflush(stdin);
        usleep(1000000);
        printf("\n\n\t\t\t\tplease Enter a valid integer input.\n");
        goto start;
    }

    return n;
}

void addPatient() {

    char ch;

    system("cls");
    puts("\n");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\t\t\t\t|----------------- ADD NEW PATIENT'S RECORD ------------------|");
    puts("\t\t\t\t|------------- SUB DIVISIONAL HOSPITAL, KUCHINDA -------------|");
    puts("\t\t\t\t---------------------------------------------------------------");

    fp = fopen("C:/Users/Siddhanta/Desktop/Practics of Codeblocks/My Project/Hospital Management System/New.txt","a+");

    if ( fp == NULL )
    {
        printf("\n\t\t\t\tFile does not open.");
        exit(10);
    }

    do {

        printf("\n\n\t\t\t\tSerial No: ");
        scanf("%d",&p.slNo);

        fflush(stdin);

        printf("\t\t\t\tPatient's Name: ");
        scanf("%[^\n]%*c",p.name);

        printf("\t\t\t\tAge: ");
        scanf("%d",&p.age);

        fflush(stdin);

        printf("\t\t\t\tGender(Male or female): ");
        p.sex = getchar();

        fflush(stdin);

        printf("\t\t\t\tPhone Number: ");
        scanf("%[^\n]%*c",p.phoneNo);

        printf("\t\t\t\tDisease: ");
        scanf("%[^\n]%*c",p.disease);

        if ( strcmp(p.disease,"Covid-19") == 0 ) {
            p.cabinNo = 100;
            printf("\t\t\t\tCabin No: %d\n",p.cabinNo);
        } else if ( strcmp(p.disease,"Fever") == 0 ) {
            p.cabinNo = 101;
            printf("\t\t\t\tCabin No: %d\n",p.cabinNo);
        } else if ( strcmp(p.disease,"Suger") == 0 ) {
            p.cabinNo = 102;
            printf("\t\t\t\tCabin No: %d\n",p.cabinNo);
        } else if ( strcmp(p.disease,"Eyes Infection") == 0 ) {
            p.cabinNo = 103;
            printf("\t\t\t\tCabin No: %d\n",p.cabinNo);
        } else if ( strcmp(p.disease,"kidney Infection") == 0 ) {
            p.cabinNo = 104;
            printf("\t\t\t\tCabin No: %d\n",p.cabinNo);
        } else {
            //General
            p.cabinNo = 105;
            printf("\t\t\t\tCabin No: %d\n",p.cabinNo);
        }

        fwrite(&p,sizeof(struct Patients),1,fp);

        printf("\n\t\t\t\tDo you want to add another data.(yes(y) or No(n)): ");
        ch = getchar();

    } while ( ch == 'Y' || ch == 'y');

    fclose(fp);

    usleep(1000000);
    printf("\n\n\t\t\t\tPress Enter to go to the main page...........");
    getch();

    system("cls");
    menu();
}

void searchPatient() {


    int choice,p_slno,f = 0;
    char p_name[30],p_phone[14];

    system("cls");
    puts("\n");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\t\t\t\t|------------------ SEARCH PATIENT'S RECORD ------------------|");
    puts("\t\t\t\t|------------- SUB DIVISIONAL HOSPITAL, KUCHINDA -------------|");
    puts("\t\t\t\t---------------------------------------------------------------");

    fp = fopen("C:/Users/Siddhanta/Desktop/Practics of Codeblocks/My Project/Hospital Management System/New.txt","r");

    if ( fp == NULL )
    {
        printf("\n\t\t\t\tFile does not open.");
        exit(10);
    }

    start:
    puts("\n\n\t\t\t\t1.Search by Patient's name and Mobile number");
        puts("\t\t\t\t2.Search by Patient's Serial No and Mobile number");


    choice = takeIntegerInput();

    if ( choice <= 0 && choice > 2 )
    {
        usleep(1000000);
        puts("\n\n\t\t\t\tEnter a valid number.........\n");
        goto start;
    }

    switch ( choice )     {

    case 1:
        {

            fflush(stdin);

            printf("\n\n\t\t\t\tEnter Patient's name: ");
            scanf("%[^\n]%*c",p_name);

            printf("\t\t\t\tEnter Patient's Mobile Number: ");
            scanf("%[^\n]%*c",p_phone);


            while(fread(&p,sizeof(p),1,fp) != 0)
            {
                if ( strcmp(p_phone , p.phoneNo) == 0 && strcmp(p_name , p.name) == 0 )
                {

                    printf("\n\n\t\t\t\tSerial no : %d",p.slNo);
                    printf("\n\t\t\t\tPatient's Name: %s",p.name);
                    printf("\n\t\t\t\tGender: %c",p.sex);
                    printf("\n\t\t\t\tAge: %d",p.age);
                    printf("\n\t\t\t\tPhone Number: %s",p.phoneNo);
                    printf("\n\t\t\t\tDisease: %s",p.disease);
                    printf("\n\t\t\t\tCabin No: %d",p.cabinNo);
                    f++;
                }
            }

            break;
        }
    case 2:
        {
            printf("\n\n\t\t\t\tEnter Patient's Serial No: ");
            scanf("%d",&p_slno);

            fflush(stdin);

            printf("\t\t\t\tEnter Patient's Mobile Number: ");
            scanf("%[^\n]%*c",p_phone);


            while(fread(&p,sizeof(p),1,fp) != 0)
            {
                if ( strcmp(p_phone , p.phoneNo) == 0 && p.slNo == p_slno )
                {
                    printf("\n\n\t\t\t\tSerial no : %d",p.slNo);
                    printf("\n\t\t\t\tPatient's Name: %s",p.name);
                    printf("\n\t\t\t\tGender: %c",p.sex);
                    printf("\n\t\t\t\tAge: %d",p.age);
                    printf("\n\t\t\t\tPhone Number: %s",p.phoneNo);
                    printf("\n\t\t\t\tDisease: %s",p.disease);
                    printf("\n\t\t\t\tCabin No: %d",p.cabinNo);
                    f++;
                }
            }
            break;
        }
    }

    if ( f == 0 ) {
        usleep(1000000);
        printf("\n\n\t\t\t\tRecord is not found..........");
    }

    fclose(fp);

    usleep(1000000);
    printf("\n\n\t\t\t\tPress Enter to go to the main page...........");
    getch();

    system("cls");
    menu();
}

void viewPatient() {

    int choice,p_slno,f = 0;
    char p_disease[30],p_phone[14];

    system("cls");
    puts("\n");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\t\t\t\t|----------------- VIEW ALL PATIENT'S RECORD -----------------|");
    puts("\t\t\t\t|------------- SUB DIVISIONAL HOSPITAL, KUCHINDA -------------|");
    puts("\t\t\t\t---------------------------------------------------------------");

    fp = fopen("C:/Users/Siddhanta/Desktop/Practics of Codeblocks/My Project/Hospital Management System/New.txt","r");

    if ( fp == NULL )
    {
        printf("\n\t\t\t\tFile does not open.");
        exit(10);
    }

    start:
    puts("\n\n\t\t\t\t1.View all Patients details by Disease name");
        puts("\t\t\t\t2.View all Patients details");


    choice = takeIntegerInput();

    if ( choice <= 0 && choice > 2 )
    {
        usleep(1000000);
        puts("\n\n\t\t\t\tEnter a valid number.........\n");
        goto start;
    }

    switch ( choice )     {

    case 1:
        {

            fflush(stdin);

            printf("\n\n\t\t\t\tEnter Patient's disease name: ");
            scanf("%[^\n]%*c",p_disease);

            while(fread(&p,sizeof(p),1,fp) != 0)
            {
                if ( strcmp(p_disease , p.disease) == 0 )
                {

                    printf("\n\n\t\t\t\tSerial no : %d",p.slNo);
                    printf("\n\t\t\t\tPatient's Name: %s",p.name);
                    printf("\n\t\t\t\tGender: %c",p.sex);
                    printf("\n\t\t\t\tAge: %d",p.age);
                    printf("\n\t\t\t\tPhone Number: %s",p.phoneNo);
                    printf("\n\t\t\t\tDisease: %s",p.disease);
                    printf("\n\t\t\t\tCabin No: %d",p.cabinNo);
                    f++;
                }
            }

            break;
        }
    case 2:
        {

            while(fread(&p,sizeof(p),1,fp) != 0)
            {
                    printf("\n\n\t\t\t\tSerial no : %d",p.slNo);
                    printf("\n\t\t\t\tPatient's Name: %s",p.name);
                    printf("\n\t\t\t\tGender: %c",p.sex);
                    printf("\n\t\t\t\tAge: %d",p.age);
                    printf("\n\t\t\t\tPhone Number: %s",p.phoneNo);
                    printf("\n\t\t\t\tDisease: %s",p.disease);
                    printf("\n\t\t\t\tCabin No: %d",p.cabinNo);
                    f++;
            }
            break;
        }
    }

    if ( f == 0 ) {
        usleep(1000000);
        printf("\n\n\t\t\t\tRecord is not found..........");
    }

    fclose(fp);

    usleep(1000000);
    printf("\n\n\t\t\t\tPress Enter to go to the main page...........");
    getch();

    system("cls");
    menu();
}

void deletePatient() {

    int choice,p_slno,f = 0;
    char p_name[30],p_phone[14];

    system("cls");
    puts("\n");
    puts("\t\t\t\t---------------------------------------------------------------");
    puts("\t\t\t\t|------------------ DELETE PATIENT'S RECORD ------------------|");
    puts("\t\t\t\t|------------- SUB DIVISIONAL HOSPITAL, KUCHINDA -------------|");
    puts("\t\t\t\t---------------------------------------------------------------");

    fp = fopen("C:/Users/Siddhanta/Desktop/Practics of Codeblocks/My Project/Hospital Management System/New.txt","r");
    ptr = fopen("C:/Users/Siddhanta/Desktop/Practics of Codeblocks/My Project/Hospital Management System/New.txt","a+");



    if ( fp == NULL || ptr == NULL )
    {
        printf("\n\t\t\t\tFile does not open.");
        exit(10);
    }

    start:
    puts("\n\n\t\t\t\t1.Delete by Patient's name and Mobile number");
        puts("\t\t\t\t2.Delete by Patient's Serial No and Mobile number");


    choice = takeIntegerInput();

    if ( choice <= 0 && choice > 2 )
    {
        usleep(1000000);
        puts("\n\n\t\t\t\tEnter a valid number.........\n");
        goto start;
    }

    switch ( choice )     {

    case 1:
        {

            fflush(stdin);

            printf("\n\n\t\t\t\tEnter Patient's name: ");
            scanf("%[^\n]%*c",p_name);

            printf("\t\t\t\tEnter Patient's Mobile Number: ");
            scanf("%[^\n]%*c",p_phone);



            while(fread(&p,sizeof(p),1,fp) != 0)
            {
                f = 0;
                if ( strcmp(p_phone , p.phoneNo) != 0 && strcmp(p_name , p.name) != 0 )
                {
                    fwrite(&p,sizeof(p),1,ptr);
                    f++;
                }
            }

            break;
        }
    case 2:
        {
            printf("\n\n\t\t\t\tEnter Patient's Serial No: ");
            scanf("%d",&p_slno);

            fflush(stdin);

            printf("\t\t\t\tEnter Patient's Mobile Number: ");
            scanf("%[^\n]%*c",p_phone);


            while(fread(&p,sizeof(p),1,fp) != 0)
            {
                f = 0;
                if ( strcmp(p_phone , p.phoneNo) != 0 && p.slNo != p_slno )
                {
                    fwrite(&p,sizeof(p),1,ptr);
                    f++;
                }
            }
            break;
        }
    }

    if ( f == 0 ) {
        usleep(1000000);
        printf("\n\n\t\t\t\tRecord is not found..........");
    }

    fclose(fp);

    usleep(1000000);
    printf("\n\n\t\t\t\tPress Enter to go to the main page...........");
    getch();

    system("cls");
    menu();
}
