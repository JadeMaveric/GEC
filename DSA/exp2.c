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
3. Search and Update Entry\n\
4. Update Entry\n\
0. Quit\n\
> ");
    scanf("%d", &ans);
    return ans;
}

struct Student
{
    int roll;
    float * sem;
    int class;

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

struct Student get_data( )
{
    struct Student S;
    S.sem = malloc(2 * sizeof(float));
    printf("Roll No: ");
    scanf("%d", &S.roll);

    printf("First Name: ");
    scanf("%s", S.name.first);

    printf("Middle Name: ");
    scanf("%s", S.name.middle);

    printf("Last Name: ");
    scanf("%s", S.name.last);

    printf("Sem 1 Percentage: ");
    scanf("%f", &S.sem[0]);

    printf("Sem 2 Percentage: ");
    scanf("%f", &S.sem[1]);

    printf("House No: ");
    scanf("%s", S.addr.house);

    printf("Street: ");
    scanf("%s", S.addr.street);

    printf("City: ");
    scanf("%s", S.addr.city);

    printf("\n");

    //assign class based on average percentage
    int percentage = (S.sem[0] + S.sem[1]) / 2;
    if (percentage >= 75)
        S.class = 1;
    else if (percentage >= 60)
        S.class = 2;
    else if (percentage >= 35)
        S.class = 3;
    else
        S.class = 4;

    return S;
}

void display( struct Student S)
{
    printf("Roll No: ");
    printf("%d\n", S.roll);

    printf("First Name: ");
    printf("%s\n", S.name.first);

    printf("Middle Name: ");
    printf("%s\n", S.name.middle);

    printf("Last Name: ");
    printf("%s\n", S.name.last);

    printf("Sem 1 Marks: ");
    printf("%f\n", S.sem[0]);

    printf("Sem 2 Marks: ");
    printf("%f\n", S.sem[1]);

    printf("House No: ");
    printf("%s\n", S.addr.house);

    printf("Street: ");
    printf("%s\n", S.addr.street);

    printf("City: ");
    printf("%s\n", S.addr.city);

    printf("\n");
}

struct Student * search( struct Student * S, int length )
{
    int i, roll, class;
    char first[15], middle[15], last[15];
    char city[15];

    printf("Search by:\n1. Full Name\n2. Roll Number\n3. City\n4. Merit Class\n>");
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
                            return &S[i];
            }

            break;
        case 2:
            printf("Enter Roll: ");
            scanf("%d", &roll);

            for(i = 0; i < length; i++)
            {
                if(S[i].roll == roll)
                    return &S[i];
            }

            break;
        case 3:
            printf("Enter City: ");
            scanf("%s", city);

            for(i = 0; i < length; i++)
            {
                if(strcmp(S[i].addr.city, city) == 0)
                    display( S[i] );
            }

            return NULL;
        case 4:
            printf("Select Class\n1. Distinction\n2. First Class\n3. Second Class\n4. Fail\n>");
            scanf("%d", &class);

            for(i = 0; i < length; i++)
            {
                if(S[i].class == class)
                    display( S[i] );
            }

            return NULL;
        default:
            printf("ERROR: Invalid Option %d", i);
            break;
    }

    printf("Record not found\n");
    return NULL;
}

void update( struct Student * S )
{
    char userChoice;

    printf("Updating Data for %s (%d)\n", S->name.first, S->roll);
    printf("Continue? [Y/n]: ");
    do {
        scanf("%c", &userChoice);
    } while (userChoice == '\n');

    if (userChoice != 'n')
    {
        printf("Current record is...\n");
        display( *S );
        printf("Enter updated details...\n");
        *S = get_data();
        printf("Update Succesfull!\n");
    }
    else
    {
        return;
    }

}

int main()
{
    int i, sIndex;
    struct Student * student, *temp;
    int no_of_students = 0;
    do
    {
        i = print_menu();

        switch(i)
        {
        case 1:
            if(no_of_students++)
                student = realloc( student, sizeof(struct Student) * no_of_students);
            else
                student = malloc(sizeof(struct Student));
            student[no_of_students-1] = get_data();
            break;
        case 2:
            temp = search( student, no_of_students);
            if (temp == NULL)
                ;//do nothing - search function took care of displaying
            else
                display( *temp );
            break;
        case 3:
            temp = search( student, no_of_students);
            if(temp == NULL)
                printf("That search parameter cannot be used to update entries\n");
            else
                update( temp );
            break;
        case 4:
            printf("Enter Database ID: ");
            scanf("%d", &sIndex);
            if(sIndex < 0 || sIndex >= no_of_students)
                printf("Invalid Record\n");
            else
                update( &student[sIndex] );
            break;
        }
    } while(i != 0);
}
