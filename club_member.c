#include <stdio.h>
#include <string.h>

#define MAX 50

char name[MAX][50];
char domain[MAX][30];
int id[MAX];
int count = 0;

void addMember()
{
    if (count == MAX)
    {
        printf("Member list is full.\n");
        return;
    }

    printf("\nEnter member name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter domain: ");
    scanf(" %[^\n]", domain[count]);

    id[count] = count + 1;
    count++;

    printf("Member added successfully.\n");
}

void listMembers()
{
    int i;

    if (count == 0)
    {
        printf("\nNo members added.\n");
        return;
    }

    printf("\n--- Club Members ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d  Name: %s  Domain: %s\n",
               id[i], name[i], domain[i]);
    }
}

void searchDomain()
{
    char search[30];
    int i;
    int found = 0;

    printf("\nEnter domain to search: ");
    scanf(" %[^\n]", search);

    for (i = 0; i < count; i++)
    {
        if (strcmp(domain[i], search) == 0)
        {
            printf("ID: %d  Name: %s  Domain: %s\n",
                   id[i], name[i], domain[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No member found in this domain.\n");
    }
}

void removeMember()
{
    int number;
    int i;

    printf("\nEnter member ID to remove: ");
    scanf("%d", &number);

    if (number < 1 || number > count)
    {
        printf("Member not found.\n");
        return;
    }

    for (i = number - 1; i < count - 1; i++)
    {
        id[i] = id[i + 1];
        strcpy(name[i], name[i + 1]);
        strcpy(domain[i], domain[i + 1]);
    }

    count--;

    for (i = number - 1; i < count; i++)
    {
        id[i] = i + 1;
    }

    printf("Member removed successfully.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== CLUB MEMBER DIRECTORY =====\n");
        printf("1. Add Member\n");
        printf("2. List Members\n");
        printf("3. Search by Domain\n");
        printf("4. Remove Member\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addMember();
        }
        else if (choice == 2)
        {
            listMembers();
        }
        else if (choice == 3)
        {
            searchDomain();
        }
        else if (choice == 4)
        {
            removeMember();
        }
        else if (choice == 5)
        {
            printf("Program ended.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}