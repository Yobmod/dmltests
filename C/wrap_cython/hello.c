
#include "hello.h"

#include <stdio.h> //printf, scanf
#include <stdbool.h>
#include <string.h> //strlen

#include <math.h>
#include <stdlib.h> //malloc
#include <ctype.h>  //toupper, tolower, isalpha, isupper...



int hello(void)
{

    char *name = malloc(sizeof(char) * 10);

    printf("whats ur name?\n");
    scanf("%s", name); //into name adress?

    if (name != NULL)
    {
        char *firstcap = malloc((strlen(name) + 1) * sizeof(char)); //char pointer point to =
        char *allcaps = malloc((strlen(name) + 1) * sizeof(char)); //char pointer point to =

        for (size_t i = 0, n = strlen(name); i <= n; i++)
        {
            firstcap[i] = name[i];
            allcaps[i] = name[i];
        };

        if (strlen(name) > 0)
        {
            *firstcap = toupper(*firstcap);
            for (size_t  i = 0, n = strlen(allcaps); i <= n; i++)
            {
                allcaps[i] = toupper(allcaps[i]);
            }
            printf("hello, %s (original)\n", name);
            printf("hello, %s (first cap)\n", firstcap);
            printf("goodbye, %s (all cap) \n", allcaps);
            system("pause");
        }

    free(name);
    free(firstcap);
    free(allcaps);
    return 0;
    }

    else  // e.g. if name too long
        return 1;


}


int add(int num1, int num2)
{
int res = num1 + num2;

return res;
}
