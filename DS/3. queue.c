#include <stdio.h>
#define size 5
void enqueue();
int isfull();
int isEmpty();
void dequeue();
void display();
struct data
{
    int jobID;
    char name[10];
};
int fr = -1;
int rr = -1;
struct data d[size];


int main()
{
    int choice;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thank You!");
            break;
        default:
            printf("Invalid Choice ! Choose Again : ");
            break;
        }
    } while (choice != 4);
}

int isfull()
{
    if (rr == size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if (rr == fr)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue()
{
    if (isfull())
    {
        printf("The queue is already full\n");
    }
    else
    {
        rr++;
        printf("Enter job Id to be inserted : ");
        scanf("%d", &d[rr].jobID);
        printf("Enter Name : ");
        scanf("%s", d[rr].name);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("The queue is already empty\n");
    }
    else
    {
        fr++;
    }
}
void display()
{
    printf("\nJOB ID\tName\t\n");
    for (int i = fr + 1; i <= rr; i++)
    {
        printf("%d\t%s\t\n", d[i].jobID, d[i].name);
    }
    printf("\n");
}