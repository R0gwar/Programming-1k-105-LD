#include <stdio.h>
#include <string.h>

int main()
{
    char string[125];
    printf("Enter:");
    gets(string);
    char words[100][100], small[100], *p = string;
    int i = 0, j = 0, k, length, count = 0;
    for(k = 0; string[k] != '\0'; ++k)
    {
        if(string[k] != ' ' && string[k] != '\0')
        {
            words[i][j++] = string[k];
        }
        else
        {
            words[i][j] = '\0';
            ++i;
            j = 0;
        }
    }
    length = i + 1;
    strcpy(small, words[0]);
    for(k = 0; k < length; ++k)
    {
        if(strlen(small) > strlen(words[k]))
        {
            strcpy(small, words[k]);
        }
    }
    printf("Smallest word: %s\n", small);
     do
    {
        p = strstr(p, small);

    if (p != NULL)
    {
      ++count;
      p = &p[strlen(small)];
    }

  } while (p != NULL);
  printf("Amount of time that smallest word was written: = %d\n", count);
    return 0;
}
