#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int x,y,z;
   printf("Enter X, Y, Z\n");
   scanf("%i %i %i", &x, &y, &z);
   if(x>y && x>z){
    printf("X is the biggest");
   }
   else if(y>x && y>z){
    printf("Y is the biggest");
   }
   else if(z>x && z>y){
    printf("Z is the biggest");
   }
   else if (x==y && x==z){
    printf("X=Y=Z");
   }
   else if(x==y && x>z){
    printf("X = Y, both bigger than z");
   }
    else if(z==y && z>x){
    printf("Z = Y, both bigger than x");
   } else if(x==z && x>y){
    printf("X = Z, both bigger than y");
   }
   return 0;
}


