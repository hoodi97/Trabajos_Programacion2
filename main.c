#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define foreach(item, list)\
        for(T *item=list->head)

char *consonants[22];
char vowels[] = {"aeiou"};

void joinName(const char *name, char **elNombre)
{
    _Bool flag = false;
    printf("\n");
    for (int i = 0; i < strlen(name); ++i)
    {
        flag = false;
        for (int j = 0; j < 5; ++j)
            if (vowels[j] == name[i])
            {
                elNombre[i] = &vowels[j];
                printf("%c: vowels[j]: %p , elNombre[i]: %p\n", vowels[j], &vowels[j], &elNombre[i]);
                flag = true;
                break;
            }

        if (flag)
            continue;

        for (int j = 0; j < 23; ++j)
            if (*consonants[j] == name[i])
            {
                elNombre[i] = consonants[j];
                printf("%c: consonants[j]: %p , elNombre[i]: %p\n", *consonants[j], consonants[j], &elNombre[i]);
                break;
            }
    }

    printf("elNombre:");
    for (int i = 0; i < strlen(name); ++i)
        printf("%c, ", elNombre[i][0]);
}

void main()
{
    for (int i = 0; i < 23; i++)
    {
        consonants[i] = (char *)malloc(sizeof(char) + 1);
        *consonants[i] = "bcdfghjklmnñpqrstvwxyz"[i];
        printf("%c, ", *consonants[i]);
    }

    printf("\n\n");
    for (int i = 0; i < 5; ++i)
        printf("%c, ", vowels[i]);

    char name[11];
    printf("\nIngresa tu nombre: ");

    // scanf("%10s", name); // without spaces
    // fgets(name, 10, stdin); // works as the next line
    scanf("%10[^\n]%*c", name);
    printf("How you doing %s", name);

    char *elNombre[10];

    joinName(name, elNombre);

    printf("elNombre:");
    for (int i = 0; i < strlen(name); ++i)
        printf("%c, ", *elNombre[i]);

    for (int i = 0; i < 22; i++)
        free(consonants[i]);
    // free(consonants); // don't do this, as consonants didn't be instancied as **,but as  *[numRows]

    printf("\n\n");
}
