/*
*   Program that cyphers the text according to caesar cypher
*   Author: Nikola Jankovic
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checking if the input is correct
    if (argc > 2 || argc < 2)
    {
        printf("No key specified\n");
        return 1;
    }
    else
    {
        // takes key and string
        int key = atoi(argv[1]);
        string text = GetString();
        
        // loop through string and do ascii math
        for (int i = 0, k = strlen(text); i < k; i++)
        {
            if (isalpha(text[i]) == 0)
            {
                printf("%c", text[i]);
            }
            else if (isupper(text[i]))
            {
                printf("%c", ((text[i] - 65 + key) % 26) + 65);
            }
            else
            {
                printf("%c", ((text[i] - 97 + key) % 26) + 97);
            }
        }
    }
    printf("\n");
}
