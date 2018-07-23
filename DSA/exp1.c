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
 3. Display days till birthday\n\
 0. Display this menu\n\
-1. Quit");

    printf("\n");
}

void delta_date(struct Date A, struct Date B, struct Date * C)
{
    enum month {Jan=1, Feb, Mar, April, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec};
    short int deltaD, deltaM, deltaY;

    deltaD = 0;
    if( A.dd < B.dd )
    {
        switch( B.mm )
        {
        case Jan: case Mar: case May: case Jul: case Aug: case Oct: case Dec:
            deltaD = 31;
            break;
        case Feb:
            deltaD = (B.yyyy%4 && !B.yyyy%100 || B.yyyy%400) ? 28 : 29;
            break;
        case April: case Jun: case Sept: case Nov:
            deltaD = 30;
            break;
        default:
            printf("\nError: Unvalid month %d\n", B.mm);
        }
    }

    deltaM = 0;
    if( A.mm < B.mm )
    {
        deltaM = 12;
    }
    if( deltaD != 0 )
    {
        deltaM -= 1;
    }

    deltaY = 0;
    if( A.mm < B.mm && deltaM != 0)
    {
        deltaY = -1;
    }

    C->dd = A.dd - B.dd + deltaD;
    C->mm = A.mm - B.mm + deltaM;
    C->yyyy = A.yyyy - B.yyyy + deltaY;
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
    e->DOR = e->DOB;
    e->DOR.yyyy += 60;

    printf("\n");
}

void print_employee_retirement_info(struct Employee * e)
{
    struct Date C; // temporary Date structure
    int funds;     // total earnings
    enum month {Jan=1, Feb, Mar, April, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec};

    printf("%s retires on %hu-%hu-%hu\n", e->name, e->DOR.dd, e->DOR.mm, e->DOR.yyyy);
    printf("They joined on %hu-%hu-%hu\n", e->DOJ.dd, e->DOJ.mm, e->DOJ.yyyy);

    delta_date(e->DOR, e->DOJ, &C);

    switch( C.mm )
    {
        case Jan: case Mar: case May: case Jul: case Aug: case Oct: case Dec:
            C.dd = 31;
            break;
        case Feb:
            C.dd = (C.yyyy%4 && !C.yyyy%100 || C.yyyy%400) ? 28 : 29;
            break;
        case April: case Jun: case Sept: case Nov:
            C.dd = 30;
            break;
        default:
            printf("\nError: Unvalid month %d\n", C.mm);
    }

    printf("They will have worked for ");
    printf( C.dd == 1 ? "%hu day, " : "%hu days, ", C.dd );
    printf( C.mm == 1 ? "%hu month, " : "%hu months and ", C.mm );
    printf( C.yyyy == 1 ? "%hu year, " : "%hu years\n", C.yyyy );

    for(int i = 0; i < C.yyyy; i++)
        funds = funds + e->bonus * funds;

    printf("They will have earned a total of %d", funds);

    printf("\n");
}

void print_employee_birthday_info(struct Employee * e)
{
    char birthday_over = 'F';
    struct Date today;
    time_t t = time(NULL);
    struct tm now = *gmtime(&t);
    today.dd = now.tm_mday;
    today.mm = now.tm_mon + 1;
    today.yyyy = now.tm_year + 1990;

    struct Date delta_birthday;
    delta_birthday = e->DOB;
    delta_birthday.yyyy = today.yyyy;
    if(e->DOB.mm < today.mm)
    {
        birthday_over = 'T';
        delta_birthday.yyyy++;
    }
    else if(e->DOB.mm == today.mm)
    {
        birthday_over = (e->DOB.dd < today.dd)?'T':'F';
        delta_birthday.yyyy++;
    }

    if(birthday_over == 'T')
    {
        delta_date(delta_birthday, today, &delta_birthday);
    }
    else
    {
        delta_date(today, delta_birthday, &delta_birthday);
    }

    printf( delta_birthday.dd == 1 ? "%hu day, " : "%hu days, ", delta_birthday.dd );
    printf( delta_birthday.mm == 1 ? "%hu month, " : "%hu months and ", delta_birthday.mm );
    printf( delta_birthday.yyyy == 1 ? "%hu year, " : "%hu years", delta_birthday.yyyy );
    printf( " till their birthday\n\n");
}

int main()
{
    struct Employee e[NUM_OF_EMPLOYEES];
    int i, eIndex, mIndex;
    
    //Initialise index variables
    i = 0;
    eIndex = 0;
    mIndex = 0;

    do
    {
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
            if(eIndex < i)
                print_employee_retirement_info(&e[eIndex]);
            else
                printf("Database error: Record not found\n");
            break;
        case 3:
            printf("Enter employee index: ");
            scanf("%d", &eIndex);
            print_employee_birthday_info(&e[eIndex]);
            break;
        case 0:
        default:
            print_menu();
        }

        printf(">");
        scanf("%d", &mIndex);

    }while(mIndex != -1);

    return 0;
}