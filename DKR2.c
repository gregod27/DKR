#include <stdio.h>
#include <stdlib.h>
int i = 0, j = 0, sum_line = 0,N,**A,**B,value;
int sumering(int *line,int N);
void sorting(int **B, int N);
void printMatrix(int **matrix,int N);
int main()
{
    printf("Enter the square matriix number, N= ");
    scanf("%d", &N);

    A=(int**)malloc(N*sizeof(int*));

    printf("\nEnter matrix elements values NxN= %d:\n\n", N*N);

    for(i=0; i<N; i++)
    {
        A[i]=(int*)malloc(N*sizeof(int));

        if(A[i]==NULL)
        {
            printf("Error allocate memory A2.\n");
            for(i=0; i<N; i++)
            {
                free(A[i]);
                free(A);
                exit(1);
            }
        }

        for(j=0; j<N; j++)
        {
            printf("A[%d][%d]= ", i, j);
            scanf("%d", &value);
            A[i][j]= value;
        }
    }

    B=(int**)malloc(N*sizeof(int*));

    if(B==NULL)
    {
        printf("Error allocate memory B1.\n");
        exit(1);
    }

    for(i=0; i<N; i++)
    {
        B[i]=(int*)malloc(value*sizeof(int));

        if(B[i]==NULL)
        {
            printf("Error allocate memory B2.\n");
            for(i=0; i<N; i++)
            {
                free(B[i]);
                free(B);
                exit(1);
            }
        }

        for(j=0; j<N; j++)
        {
            B[i][j]=A[i][j];
        };
    }
    printf("\nA Matrix:\n");
    printMatrix(A,N);
    printf("\nB Matrix:\n");
    sorting(B,N);
}

int sumering(int *line,int N)
{
    int sum = 0;
    for (i=0; i<N; i++)
    {
        sum +=line[i];
    }
    return sum;
}

void sorting(int **B, int N)
{

    for (int step = 0; step < N - 1; ++step)
    {


        for (int i = 0; i < N - step - 1; ++i)
        {

            if (sumering(B[i],N) < sumering(B[i+1],N))
            {

                int *temp = B[i];
                B[i] = B[i+1];
                B[i+1] = temp;

            }
        }
    }
    printMatrix(B,N);

}

void printMatrix(int **matrix,int N)
{
    for (i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%d     ", matrix[i][j]);
        }
        printf("\n");
    }
}













