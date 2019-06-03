#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x = 0.0f;
    float y = 0.0f;
    printf("X, Y:");
    if (2 != scanf("(%f;%f)", &x, &y))
    {
        printf("Input Error");
        return -1;
    }
    double functionFirst = x * x + y * y;
    double functionSecond = pow(x + 1, 2) + y * y;
    if (functionFirst <= 1 && functionSecond <= 1)
    {
        printf("Inside");
    }
    else
    {
        printf("Outside");
    }
    return 0;
}
