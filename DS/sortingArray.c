#include<stdio.h>

struct student
{
    int prn;
    char name[10];
};

void getinfo(struct student *s){
        printf ("Enter Your Name : ");
        scanf ("%s", s->name);
        printf ("Enter your PRN : ");
        scanf ("%d",&s->prn);
}

void printinfo(struct student *s){
        printf ("Name : %s\n",s->name);
        printf ("PRN : %d\n", s->prn);
    
}

void bubbleSort (struct student s[], int size){
    for (int i = 0; i < size -1 ; i++){
        for (int j = 0; j < size-i-1; j ++){
            if (s[j].prn > s[j+1].prn){
                struct student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp; 
            }
        }
    }
}
void insertionSort(struct student s[], int size){

    for(int i = 1; i < size; i++){
        struct student key = s[i];
        int j = i - 1;
        while(j >= 0 && s[j].prn > key.prn){
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}
void selectionSort (struct student s[], int size){
    for (int i = 0; i < size -1 ; i++){
        int min = i;
        for (int j = i+1; j < size; j++ ){
            if (s[j].prn < s[min].prn){
                min = j;
            }
        }
        if (min!=i){
            struct student temp = s[min];
                s[min] = s[i];
                s[i] = temp; 
        }
    }
}


int main()
{
    
    int num;
    int choice;
    printf ("Enter the number of students : ");
    scanf ("%d", &num);
    struct student stu[num];
    for (int i = 0; i < num ; i++){
        getinfo(&stu[i]);
    }
    printf ("\n\nBEFORE SWAPPING : \n");
    for (int i = 0; i < num ; i++){
        printinfo(&stu[i]);
    }
    printf("Select a sorting Algorithm\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n");
    scanf ("%d",&choice);

    switch (choice)
    {
    case 1 : (choice == 1);
        bubbleSort (stu,num);
        break;
    case 2 : (choice == 2);
        selectionSort (stu,num);
        break;
    case 3 : (choice == 3);
        insertionSort (stu,num);
        break;
    
    default:
        break;
    }

    bubbleSort (stu,num);
    printf ("\nAFTER SWAPPING : \n");
    for (int i = 0; i < num ; i++){
        printinfo(&stu[i]);
    }
    return 0;
    
}