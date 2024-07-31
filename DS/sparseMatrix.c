#include<stdio.h>
#define ROW 10
#define COL 10

void getArray (int mat[ROW][COL],int row, int col){
    for (int i = 0; i < row ; i++){
        for (int j = 0; j < col ; j++){
            printf ("Enter element for cell no %d%d : ",i,j);
            scanf ("%d",&mat[i][j]);
        }
    }
}

void printArray (int mat[ROW][COL],int row, int col){
    for (int i = 0; i < row ; i++){
        for (int j = 0; j < col ; j++){
            printf ("\t%d",mat[i][j]);
        }
        printf ("\n");
    }
}

void printSparseArray(int smatrix[][3], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\t%d", smatrix[i][j]);
        }
        printf("\n");
    }
}

int makeTriplet(int matrix[ROW][COL],int rows, int columns, int smatrix[][3]){
    smatrix[0][0] = rows;
    smatrix[0][1] = columns;
    int count = 1;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (matrix[i][j] != 0){
                smatrix[count][0] = i;
                smatrix[count][1] = j;
                smatrix[count][2] = matrix[i][j];
                count++;
            }
        }
    }
    smatrix[0][2] = count - 1;
    return count;
}

void transposeTriplet(int count, int smatrix[][3], int tmatrix[][3]){
    tmatrix[0][0] = smatrix[0][1];
    tmatrix[0][1] = smatrix[0][0];
    tmatrix[0][2] = count - 1;

    int l = 1;
    for(int i = 0; i < smatrix[0][1]; i++){
        for(int j = 0; j < count; j++){
            if(smatrix[j][1] == i){
                tmatrix[l][0] = smatrix[j][1];
                tmatrix[l][1] = smatrix[j][0];
                tmatrix[l][2] = smatrix[j][2];
                l++;
            }
        }
    }
}

void fastTransposeTriplet(int count, int smatrix[][3], int fmatrix[][3]) {
    int rowTerms[smatrix[0][1]], startingPos[smatrix[0][1]];

    for (int i = 0; i < smatrix[0][1]; i++) {
        rowTerms[i] = 0;
    }

    for (int i = 1; i < count; i++) {
        rowTerms[smatrix[i][1]]++;
    }

    startingPos[0] = 1;
    for (int i = 1; i < smatrix[0][1]; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    fmatrix[0][0] = smatrix[0][1];
    fmatrix[0][1] = smatrix[0][0];
    fmatrix[0][2] = count-1;

    for (int i = 1; i < count; i++) {
        int j = startingPos[smatrix[i][1]]++;
        fmatrix[j][0] = smatrix[i][1];
        fmatrix[j][1] = smatrix[i][0];
        fmatrix[j][2] = smatrix[i][2];
    }
}


int main()
{
    int rows,columns;
    printf ("Enter number of rows : ");
    scanf ("%d",&rows);
    printf("Enter number of columns : ");
    scanf ("%d",&columns);

    int matrix[ROW][COL] = {0};
    getArray (matrix,rows,columns);
    printf ("SPARSE MATRIX : \n");
    printArray (matrix,rows,columns);

    int smatrix[ROW][3] = {0};
    int counter = makeTriplet(matrix,rows,columns,smatrix);
    printf ("TRIPLET MATRIX : \n");
    printSparseArray(smatrix,counter);

    int tmatrix[counter][3];
    transposeTriplet(counter,smatrix,tmatrix);
    printf ("SIMPLE TRANSPOSED MATRIX : \n");
    printSparseArray(tmatrix,counter);

    int fmatrix[counter][3];
    fastTransposeTriplet(counter,smatrix,fmatrix);
    printf ("FAST TRANSPOSED MATRIX : \n");
    printSparseArray(fmatrix,counter);

    
    return 0;

}