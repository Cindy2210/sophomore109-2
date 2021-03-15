#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
void sort(int *Arr, int first, int last, int n, int R, int base)
{
    int count[R], B[n];
    for (int i = 0; i < R; i++)
        count[i] = 0;
    for (int i = first; i <= last; i++)
    {
        count[(Arr[i] / base) % R]++;
        printf("A[i]:%d ", Arr[i]);
        printf("base:%d \t", base);
        printf("A[i] / base:%d \t", Arr[i] / base);
        printf("(A[i] / base) % r:%d \n", (Arr[i] / base) % R);
    }
    printf("\n");

    getch();

    printf("counts\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", count[i]);
    printf("\n");

    getch();

    for (int j = 0, psum = 0, sum = 0; j < R; ++j) //psum is prefix sum
    {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }

    printf("After  counts\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", count[i]);
    printf("\n");
    int tmpCounts[n];
    for (int i = 0; i < n; i++)
        tmpCounts[i] = count[i];

    getch();

    for (int i = first; i <= last; i++)
        B[count[(Arr[i] / base) % R]++] = Arr[i];

    for (int j = first; j <= last; ++j)
        Arr[j] = B[j-first];
    for (int i = 0; i < n; i++)
    {
        printf("A[i]:%d ", Arr[i]);
    }
    printf("\n");

    getch();

    for (int i = first; i < last; i++)
    {
        printf("i:%d\tarr[i]:%d   [i+1]:%d   tmpCounts[i]:%d   tmpCounts[i+1]:%d\n", i, Arr[i], Arr[i + 1], tmpCounts[i], tmpCounts[i + 1]);

        getch();
        if (((Arr[i] / base) % R) == ((Arr[i + 1] / base) % R))
        {
            int TMP = i;
            int rep = 0;
            while ( ((Arr[TMP] / base) % R) == ((Arr[TMP+1] / base) % R) )
                rep++, TMP++;
            printf("first:%d last:%d\n", i, i+rep);
            if(i+rep > n)
            continue;
            sort(Arr, i, i+rep, n, R, base / 10);
            printf("===============out====================\n");
        }
        printf("out!\\\\\\\\\\\\\\\\\\\\\\\\");
        // printf();
        // printf();
    }
}


void radixsort(int *A, int n, int r, int d)
{
    int base = 1;
    int tmp = d - 1;
    while (tmp > 0)
    {
        tmp--;
        base *= r;
    }
    printf("base:%d\n", base);
    sort(A, 0, n - 1, n, r, base);
}

void main()
{
    int Array[100];
    srand(1);
    for (int i = 0; i < 10; i++)
        Array[i] = rand() % 10000;

    for (int i = 0; i < 10; i++)
        printf("%d ", Array[i]);

    printf("\n");
    radixsort(Array, 10, 10, 4);
    printf("\n========================\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", Array[i]);
}



//find minimum usable 𝑑 of list 𝐴 ：
void main()
{
    int Array[100];
    srand(1);
    for (int i = 0; i < 10; i++)
        Array[i] = rand() % 10000;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
    int MAX = 0, i, MAXr = 0, tmp, base;
    for (i = 0; i < 10; i++)
    {
        base = 1;
        if(MAX < Array[i])
            MAX = Array[i];

        tmp = Array[i];
        while(tmp != 0)
        {
            //printf("tmp:%d \n", tmp);
            //getch();
            //printf("tmp % 10:%d \n", tmp%10);
            //printf("(tmp % 10)/10:%d \n", (tmp%10)/10);
            
            if((tmp%10) > MAXr)
                MAXr = tmp%10;
            //printf("MAXr:%d \n", MAXr);
            //getch();
            tmp/=10;
        }
    }
    printf("MAX:%d\n", MAX);
    printf("MAXr:%d\n", MAXr);
    int D = 0;
    while (MAX != 0)
    {
        MAX/=10;
        D++;
    }
    printf("D:%d\n", D);
}
