#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


typedef double (*function)(double);
int first_task();
int second_task();
int third_task();
char menu();

///Взял эту часть кода и функции для второго задания у github.com/pornhub360
char sign(double);
double eq(double);
double dEq(double);
double iteration(function, double*, double, double);
double bisection (function, double*, double, double);
double newton (function, function, double*, double, double);
double secant (function, double*, double, double);
///-----------------------------------------------------------------------

int main(int argc, char *argv[])
{
    char ans;
    while((ans = toupper(menu())) != 'Q')
    {
    if (ans == 'C')
    {
        first_task();
    }
    else if (ans == 'F')
    {
        second_task();
    }
    else if (ans == 'E')
    {
        third_task();
    }
    }
    return 0;
}
int first_task()
{
    int N,M,i,j,diag1,diag2;
    diag1 = 1;
    diag2 = 1;
     printf("Enter number of row: ");
    scanf("%d",&N);
     printf("Enter number of columns: ");
    scanf("%d",&M);
    int A[N][M];
    srand(time(NULL));
    for (i = 0; i < N; i++ )
    {
    for (j = 0; j < M; j++ )
    {
    A[i][j] = rand()% (2 - 1 + 1);
    printf("%d ",A[i][j]);
    }
    puts("\n");
    }

    for ( i = 0; i < N; i++ )
    {
    /// работаем с  A[i][i]
        if(A[i][i] != 1 )
        {
            diag1 = 0;
        }
    }

    for ( i = 0; i < N; i++ )
        {
  /// работаем с  A[i][N-1-i]
        if(A[i][N-1-i] != 1)
        {
            diag2 = 0;
        }
    }


  if(diag1 == 1 || diag2 == 1)
    {
        puts("daig");
    }
  else puts("not_diag");
  return 0;
}
int second_task()
{
    printf("x*x+4sin(x)-1=0\n");
    int pw;
    printf("\nEnter the power of the step: -");
    if(scanf("%d",&pw) != 1 || pw > 7 || pw < 1)
    {
        printf("\nIncorrect input!\n");
        return -1;
    }

    double e = pow(10,0-pw);
    double *arr = (int*)(malloc(sizeof(int) * 3));
    double xa = -2, xb = 0.23;
    printf("\n***********************ITERATION METHOD***********************\n");
    for(int i = 0; i < 3;++i)
    {
        arr[i] = iteration(eq, &xa, e, xb);
        printf("%5.4f\n ", arr[i]);
    }
    printf("\n***********************BISECTION METHOD***********************\n");
    printf("Root: %5.4f\n", bisection(eq, &xa, e, xb));
    printf("\n************************NEWTON METHOD*************************\n");
    printf("Root: %5.4f\n", newton(eq, dEq, &xa, e, xb));
    printf("\n************************SECANT METHOD*************************\n");
    printf("Root: %5.4f\n\n\n", secant(eq, &xa, e, xb));
    free(arr);

    return 0;
}
#define N 10000
int third_Func(int x)
{
    double f;
    f = 1/(1 + exp(x));
    return f;
}

int third_task()
{
    printf("Metod Trapeciy\n");
    float S = 0, h;
    int x, a, b;
    a = 0;
    b = 1;
    ///отрезок [a, b] разобьем на N частей
    h = (b - a)/N;
    x = a + h;
    printf("%d\n",x);
    while (x < b)
    {
        S = S + 4*third_Func(x);
        x = x + h;
    ///проверяем не вышло ли значение x за пределы полуинтервала [a, b)
        if (x >= b) break;
        S = S + 2*third_Func(x);
        x = x + h;
    }
    S = (h/3)*(S + third_Func(a) + third_Func(b));
    printf ("%f", S);
    _getch ();
    return 0;

}
char menu()
{
    char choice;
    printf("*******************************\n");
    printf("What do you want me to do, Senpai?\n");
    printf("*******************************\n");
    printf("[C\\c] Complete the first task\n");
    printf("[F\\f] Complete the second task\n");
    printf("[E\\e] Complete the third task\n");
    printf("[Q\\q] Quit\n");
    printf("*******************************\n");
    printf("Your choice: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}
char sign(double a)
{
    return a < 0 ? -1 : a > 0 ? 1 : 0;
}

double eq(double x)
{
    return pow(2, x)*pow(x-2, 2)-1;
}

double dEq (double x)
{
    return pow(2, x)*pow(x-2, 2)*log(2)+pow(2, x)*(2*x-4);
}

double iteration (function fx, double *xa, double e, double xb)
{
    for(int i = 0; i < 2; ++i)
    {
        for(*xa += e; *xa < xb-e ; *xa += e)
        {
            if(sign(fx(*xa))*sign(fx(*xa+e)) < 0)
            {
                printf("The root of this equation is in [%.8f,%.8f]...\n",*xa,*xa+e);
                if(fabs(fx(*xa))<e)
                {
                    return *xa;
                }
                else
                {
                    return *xa+e;
                }
            }
        }
    }
}

double bisection (function fx, double *xk, double e, double xn)
{
    double dx, bisecx;
    do
    {
        dx = (*xk-xn)/2;
        bisecx = xn + dx;
        if(sign(fx(xn)) != sign(fx(bisecx)))
        {
            *xk = bisecx;
        }
        else
        {
            xn = bisecx;
        }
        } while((*xk-xn) > e);
        return bisecx;
}

double newton (function fx, function dfx, double *xk, double e, double xn)
{
    double newtx  = xn - fx(xn)/dfx(xn);
    while (fabs(newtx-xn) > e)
    {
        xn = newtx;
        newtx = newtx - fx(newtx)/dfx(newtx);
    }
    return newtx;
}

double secant (function fx, double *xk, double e, double xn)
{
    double secantx = 0,x0;
    do
    {
        x0 = secantx;
        secantx = *xk-fx(*xk)*(xn-*xk)/(fx(xn)-fx(*xk));
        if(fx(*xk)*fx(secantx) < 0) xn = secantx;
        else *xk = secantx;
    } while (fabs(secantx-x0) > e);
    return secantx;
}
