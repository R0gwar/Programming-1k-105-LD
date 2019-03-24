#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char menu() {
    char choice;
    printf("-----------------------\n");
    printf("What do you want me to do Sempai?\n");
    printf("-----------------------\n");
    printf("[F] DO IT\n");
    printf("[Q] GO AWAY\n");
    printf("-----------------------\n");
    printf("Sooo: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}

int main(int argc, char *argv[]){
    char answ;
    while((answ = toupper(menu())) != 'Q') {
    if (answ == 'F') {
            double a, b, x, res;
            printf("a = ");
            scanf("%lf", &a);
            printf("b = ");
            scanf("%lf", &b);
            printf("x = ");
            scanf("%lf", &x);
            double k = (pow(x, a*cos(2*x))-1);
            double o = exp(b*x*x);
             res = (k/o);
            printf("F(x) = %.15f\n\n", res);
    }
    }
    return 0;
}
