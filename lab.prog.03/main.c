#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int i = 0; int S = 0;
    int arr[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    for(i; i<20; i = i + 2){
        S += arr[i]*arr[i];
    }
    printf("Sum = %d", S);
}
