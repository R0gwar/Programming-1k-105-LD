#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int x;
    int simple = 0;
    printf("enter x:" );
    scanf("%d", &x);

    for(int i = 2; i < x; i++){
    if(x % i == 0){
        simple = 1;
        int f = (x % i);
        printf("%d\n", f);
        printf("x is not simple\n");
        break;
        }
        else{
            printf("x is simple");
            break;
        }
    }

    return 0;
}
