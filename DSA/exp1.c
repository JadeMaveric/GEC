/*Array of Structures*/

#include <stdio.h>
#include <time.h>

#define NUM_OF_EMPLOYEES 2

struct Date
{
    int dd, mm, yyyy;
}today;

struct Employee
{
    char name[20];
    unsigned short int age;
    struct Date DOB, DOJ, DOR;
    int salary;
    float bonus;
};

void print_menu()
{
    printf("\
 1. Add entry to Employee Database\n\
 2. Display retirement info of employee\n\
 0. Display this menu\n\
-1. Quit");

    printf("\n");
}

void get_employee_data(struct Employee * e)
{
    printf("Enter Employee Details\n");

    printf("Name: ");
    scanf("%s", e->name);

    printf("Age : ");
    scanf("%hu", &e->age);

    printf("DOB : ");
    scanf("%hu-%hu-%hu", &e->DOB.dd, &e->DOB.mm, &e->DOB.yyyy);

    printf("DOJ : ");
    scanf("%hu-%hu-%hu", &e->DOJ.dd, &e->DOJ.mm, &e->DOJ.yyyy);

    printf("Salary: ");
    scanf("%d", &e->salary);

    printf("Bonus: ");
    scanf("%f", &e->bonus);

    //Figure out date of retirement

    printf("\n");
}

void print_employee_retirement_info(struct Employee * e)
{
    unsigned short int deltaD, deltaM, deltaY;
    int funds;

    deltaM = (e->DOB.dd > e->DOJ.dd)? 12 : 11;
    deltaY = (e->DOB.mm > e->DOJ.mm)? 60 : 59;
    if( e->DOB.mm == 2 )
    {
        deltaD = 28;
    }
    else if ( e->DOB.mm <= 7 )
    {
        deltaD = (e->DOB.mm%2 ? 30 : 31);
    }
    else
    {
        deltaD = (e->DOB.mm%2 ? 31 : 30);
    }


    unsigned short int dd = (e->DOB.dd > e->DOJ.dd)?(e->DOB.dd - e->DOJ.dd):(e->DOB.dd - e->DOJ.dd + deltaD);
    unsigned short int mm = (e->DOB.mm > e->DOJ.mm)?(e->DOB.mm - e->DOJ.mm):(e->DOB.mm - e->DOJ.mm + deltaM);
    unsigned short int yyyy = e->DOB.yyyy - e->DOJ.yyyy + deltaY;

    printf("%s retires on %hu-%hu-%hu\n", e->name, e->DOB.dd, e->DOB.mm, e->DOB.yyyy + 60);
    printf("They joined on %hu-%hu-%hu\n", e->DOJ.dd, e->DOJ.mm, e->DOJ.yyyy);

    printf("They will have worked for ");
    printf( dd == 1 ? "%hu day, " : "%hu days, ", dd );
    printf( mm == 1 ? "%hu month, " : "%hu months and ", mm );
    printf( yyyy == 1 ? "%hu year, " : "%hu years\n", yyyy );

    for(int i = 0; i < yyyy; i++)
        funds = funds + e->bonus * funds;

    printf("They will have earned a total of %d", funds);

    printf("\n");
}

int main()
{
    struct Employee e[NUM_OF_EMPLOYEES];
    int i, eIndex, mIndex;

    //Initialise today
    struct Date today;
    time_t t = time(NULL);
    struct tm now = *gmtime(&t);
    today.dd = now.tm_mday;
    today.mm = now.tm_mon + 1;
    today.yyyy = now.tm_year + 1990;

    do
    {
        print_menu();
        scanf("%d", &mIndex);

        switch(mIndex)
        {
        case 1:
            if(i < NUM_OF_EMPLOYEES)
                get_employee_data(&e[i++]);
            else
                printf("Database full!\n");
            break;
        case 2:
            printf("Enter employee index: ");
            scanf("%d", &eIndex);
            print_employee_retirement_info(&e[eIndex]);
            break;
        case 0:
        default:
            print_menu();
        }

    }while(i != -1);

//    for(int i = 0; i < NUM_OF_EMPLOYEES; i++)
//        get_employee_data(&e[i]);
//
//    for(int i = 0; i < NUM_OF_EMPLOYEES; i++)
//        print_employee_retirement_day(&e[i]);

    return 0;
}