#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char menu() {
    char choice;
    printf("-----------------------\n");
    printf("What do you want me to do Sempai?\n");
    printf("-----------------------\n");
    printf("[A] DO IT\n");
    printf("[F] DO THE SECOND ONE\n");
    printf("[Q] GO AWAY\n");
    printf("-----------------------\n");
    printf("Sooo: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}
double count_y(double x){
    if (x <= -M_PI/4){
        return x*x-2;
    } else if (x >- M_PI/4 && x < M_PI/4){
        return tan(2*x);
    } else if(x >= M_PI/4){
        return (sqrt(x)+1)/x;
    }
}

double count_f(double x, double y){
    return (x*x+y*y)/(x-y);
}

int main(int argc, char *argv[])
{
    char ans;
    while((ans = toupper(menu())) != 'Q') {
    if (ans == 'F') {
        double a = -M_PI/2, b = M_PI/2, h = 0.1;

        printf("-----------------------------------  Part 1 ----------------------------------- \n");

        printf("x:\t");
        for (double x = a; x <= b; x += h) {
            char c = x + h < b ? '\t' : '\n';
            printf("%.3f%c", x, c);
        }

        printf("y:\t");
        for (double x = a; x <= b; x += h) {
            char c = x + h < b ? '\t' : '\n';
            printf("%.3f%c", count_y(x), c);
        }

        printf("----------------------------------------------------------------------  \n");

        printf("----------------------------------- Part 2 ----------------------------------- \n");

        double a1= 2, b1 = 4, h1 = 0.2;
        double c1= -1, d1 = 3, h2 = 0.1;
        printf("y\\x\t");
        for (double x = a1; x <= b1; x += h1) {
            char c = x + h1 < b1 ? '\t' : '\n';
            printf("%.3f%c", x, c);
        }

        for (double y = c1; y <= d1; y += h2) {
            printf("%.3f\t", y);
            for (double x = a1; x <= b1; x += h1) {
                char c = x + h1 < b1 ? '\t' : '\n';
                printf("%.3f%c", count_f(x, y), c);
            }
        }
    }
else if( ans == 'A'){
      int N;
    double x, leftX = 0, rightX = M_PI/2;

    printf("Enter x, N: ");
    if (scanf("%lf %d", &x, &N) != 2) {
        printf("Invalid input\n");
        return -1;
    }

    if (x < leftX || x > rightX) {
        char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
        printf(fmt, x, leftX, rightX);
        return -1;
    }

    double a = 1, S = a;

    for (int n = 0; n <= N; ++n) {
        double q = (sin(x)*sin(x)*n)/(n+1);
        a *= q;
        S += a;
    }
    //Calc result
    S = - S;
    double y = sin(x)*sin(x);
    printf("S=%.7f\n", S);
    printf("y=%.7f\n", y);
    double eps = fabs(y-S)/fabs(S)*100;
    printf("e=%.2f%%\n", eps);
        }

}
return 0;
}
