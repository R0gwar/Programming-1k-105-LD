#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

char main_menu(void);
void swap(int *a, int *b);

int main(int argc, char *argv[])
{
    char ans;
    while((ans = toupper(main_menu())) != 'Q')
    {
        if (ans == 'C')
        {int i = 0; int S = 0;
            int arr[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
            for(i; i<20; i = i + 2)
                {
                    S += arr[i]*arr[i];
                }
    printf("Sum = %d \n", S);
        } else if (ans == 'F')
            {
                int row, column, i, j, k;
                printf("Enter number of row: ");
                scanf("%d", &row);
                printf("Enter number of column: ");
                int **matrix = (int*)malloc(row * sizeof(int));
                scanf("%d", &column);
                for (i = 0; i < row; ++i)
                {
                    matrix[i] = (int*)malloc(column * sizeof(int));
                }
                srand(time(NULL));
                for (i = 0; i < row; ++i)
                {
                    for (j = 0; j < column; ++j)
                    {
                        matrix[i][j] = rand()%101 - 30;
                    }
                }
                printf("Your matrix: \n");
                for (i = 0; i < row; ++i)
                {
                    for (j = 0; j < column; ++j)
                    {
                        printf("%d\t", matrix[i][j]);
                    }
                    printf("\n\n");
                }
                printf("\n");
                printf("Sorted matrix: \n");
                for (i = 0; i < row; ++i)
                {
                    for(j = 0; j < column; ++j)
                    {
                        for (k = column - 1; k > j; --k)
                            if (matrix[i][k] < matrix[i][k-1])
                            {
                                swap(&matrix[i][k], &matrix[i][k-1]);
                            }
                        printf("%d\t", matrix[i][j]);
                    }
                    printf("\n\n");
                }
            }
    }


    printf("\n");
    return 0;
}

char main_menu() {
    char choice;
     printf("-----------------------\n");
    printf("What do you want me to do Sempai?\n");
    printf("-----------------------\n");
    printf("[C] DO IT\n");
    printf("[F] DO THE SECOND ONE\n");
    printf("[Q] GO AWAY\n");
    printf("-----------------------\n");
    printf("Sooo: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
