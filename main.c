#include <stdio.h>
#include <stdlib.h>


int pow(int a, int N);
int main ()
{
    int N = 0;
    float S = 1 ,a = 0;
    printf("N: ");
    scanf("%d", &N);
    printf("a: ");
    scanf("%f", &a);

    for(int n=0; n<=N; n++)
        if(a+n != 0){
            S = S + pow(-1, n)*(pow(a, n))/(a+n);
        }

    printf("S: %f",S);
    getch();
    return 0;

}
int pow(int a, int N)
{
    int value=1;
    if(N==0)
    {
        return 1;
    }
    else if (N==1)
    {
        return a;
    }
    else
    {
        for(int i=0; i<=N; i++)
        {
            value*=a;
        }
    }
    return value;
}


