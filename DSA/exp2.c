#include <stdio.h>  //For I/O functions
#include <stdlib.h> //For memory management functions
#include <string.h> //For string compare

/* Dynamic Allocation of Array of students
 * read, write, update data using
 * - name, city, roll no
 * - merit
 * should use the following concepts
 * - pointer within structure
 * - passing structure pointer to func
 * - passing structure variable to func
 * - return structure variable from func
 * - return structure pointer from func
**/

int print_menu()
{
    int ans;
    printf("\n\
1. Add Entry\n\
2. Search and Display Entry\n\
0. Quit\n\
> ");
    scanf("%d", &ans);
    return ans;
}

struct Student
{
    int roll;
    float sem[2];

    struct Name
    {
        char first[15];
        char middle[15];
        char last[15];
    } name;

    struct Address
    {
        char house[15];
        char street[15];
        char city[15];
    } addr;
};

void get_data( struct Student * S )
{
    printf("Roll No: ");
    scanf("%d", &S->roll);

    printf("First Name: ");
    scanf("%s", S->name.first);

    printf("Middle Name: ");
    scanf("%s", S->name.middle);

    printf("Last Name: ");
    scanf("%s", S->name.last);

    printf("Sem 1 Marks: ");
    scanf("%f", &S->sem[0]);

    printf("Sem 2 Marks: ");
    scanf("%f", &S->sem[1]);

    printf("House No: ");
    scanf("%s", S->addr.house);

    printf("Street: ");
    scanf("%s", S->addr.street);

    printf("City: ");
    scanf("%s", S->addr.city);

    printf("\n");
}

void display( struct Student * S)
{
    printf("Roll No: ");
    printf("%d\n", S->roll);

    printf("First Name: ");
    printf("%s\n", S->name.first);

    printf("Middle Name: ");
    printf("%s\n", S->name.middle);

    printf("Last Name: ");
    printf("%s\n", S->name.last);

    printf("Sem 1 Marks: ");
    printf("%f\n", S->sem[0]);

    printf("Sem 2 Marks: ");
    printf("%f\n", S->sem[1]);

    printf("House No: ");
    printf("%s\n", S->addr.house);

    printf("Street: ");
    printf("%s\n", S->addr.street);

    printf("City: ");
    printf("%s\n", S->addr.city);

    printf("\n");
}

int search( struct Student * S, int length )
{
    int i, roll;
    char first[15], middle[15], last[15];
    
    printf("Search by:\n1. Full Name\n2. Roll Number\n>");
    scanf("%d", &i);
    
    switch (i)
    {
        case 1:

            printf("Enter Full Name: ");
            scanf("%s %s %s", first, middle, last);
            
            for(i = 0; i < length; i++)
            {
                if(strcmp(S[i].name.last, last) == 0)
                    if(strcmp(S[i].name.first, first) == 0)
                        if(strcmp(S[i].name.middle, middle) == 0)
                            return i;
            }
            
            break;
        case 2:

            printf("Enter Roll: ");
            scanf("%d", &roll);
            
            for(i = 0; i < length; i++)
            {
                if(S[i].roll == roll)
                    return i;
            }
            
            break;
        default:
            printf("ERROR: Invalid Option %d", i);
            break;
    }

    return -2;
}

int main()
{
    int i, sIndex;
    struct Student * student, * temp;
    int no_of_students = 0;
    do
    {
        i = print_menu();

        switch(i)
        {
        case 1:
            if(no_of_students++)
                realloc( temp, sizeof(struct Student) * no_of_students);
            else
                temp = malloc(sizeof(struct Student));
            for(int j = 0; j < no_of_students - 1; j++)
            {
                temp[j] = student[j];
            }
            student = temp;
            get_data(&student[no_of_students - 1]);
            break;
        case 2:
            sIndex = search( student, no_of_students);
            if(sIndex < 0)
                printf("Record not found\n");
            else
                display( &student[sIndex] );
            break;
        }
    } while(i != 0);
}
