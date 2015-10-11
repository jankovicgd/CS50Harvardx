/*
*   Program that shifts letters according to the vigenere cypher
*   Author: Nikola Jankovic
*   NOTICE: Doesn't account for spaces
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool alphacheck(string word);

int main(int argc, string argv[])
{
    // checking if the input is correct
    if (argc > 2 || argc < 2 || alphacheck(argv[1]) == false)
    {
        printf("No or wrong key specified\n");
        return 1;
    }
    else
    {
        // takes key and string and initializes key for later
        string key = argv[1];
        string text = GetString();
        int keyint = 0;
        int keylength = strlen(key);
        
        // loop through string and do ascii math
        for (int i = 0, k = strlen(text); i < k; i++)
        {
            if (isalpha(text[i]) == 0)
            {
                printf("%c", text[i]);
            }
            else if (isupper(text[i]))
            {
                // inner branch checks if the key is in lower/upper case
                if (isupper(key[(i % keylength)]))
                {
                    keyint = key[(i % keylength)] - 65;
                }
                else
                {
                    keyint = key[(i % keylength)] - 97;
                }                  
                printf("%c", ((text[i] - 65 + keyint) % 26) + 65);
            }
            else
            {
                // inner branch checks if the key is in lower/upper case
                if (isupper(key[(i % keylength)]))
                {
                    keyint = key[(i % keylength)] - 65;
                }
                else
                {
                    keyint = key[(i % keylength)] - 97;
                }            
                printf("%c", ((text[i] - 97 + keyint) % 26) + 97);
            }
        }
    }
    printf("\n");
}

// function to check if the world is alphabetical
bool alphacheck(string word)
{    
    int counter = 0;
    for (int i = 0, k = strlen(word); i < k; i++)
    {
        if (isalpha(word[i]))
        {
            counter += 1;
        }
    }
    // return the value
    if (counter == strlen(word))
    {
        return true;
    }
    else
    {
        return false;
    }
}
