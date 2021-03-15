#include <stdio.h>

void counting_sort(int *A, int arrLen, int radix, int position, int head, int tail)
{
    int count[radix], temp[arrLen], filter = 1, base = 1;

    while(position > 0)
    {
        position --;
        if(position != 1)
            base *= radix;
        filter *= radix;
    }

    for(int i=0; i<radix; i++)
        count[i] = 0;

    for(int i=0; i<arrLen; i++)
        temp[i] = 0;
    
    for(int i=head; i<=tail; i++)
        count[ (A[i] % filter) / base ] ++;

    for(int i=0 , psum=0, sum=0; i<radix; i++)
    {
        psum = sum;
        sum += count[i];
        count[i] = psum;
    }

    for(int i=head; i<=tail; i++)
        temp[count[ (A[i] % filter) / base ]++] = A[i];

    for(int i=0; temp[i]!=0; i++)
        A[head+i] = temp[i];
}

void radix_sortMSD(int *A, int n, int r, int d) 
{
    int base = 1;

    for(int i=0; i<d; i++, base*=r){}

    while( base >= 10 )
    {
        int head = 0, flag = A[0] / base;
        for(int i=0; i<n; i++)
        {
            if( flag != A[i] / base )
            {
                counting_sort(A, n, r, d, head, i-1);
                head = i;
                flag = A[i] / base;
            }
        }
        counting_sort(A, n, r, d--, head, n-1);
        base /= 10;
    }
}

int main()
{
    int arr[] = {863, 375, 339, 596, 511, 867, 333, 867, 590, 90, 80, 980, 23, 4, 66};
    
    radix_sortMSD(arr, 15, 10, 3);

    for(int i=0; i<15; i++)
        printf("%d ", arr[i]);

    return 0;
}
