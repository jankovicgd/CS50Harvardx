#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

/*
*   Program that gets the initials of the user
*   Author: Nikola Jankovic
*/


int main(void)
{
    string name = GetString();
    
    printf("%c", toupper(name[0]));
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        if (name[i - 1] ==  (char) 32)
            printf("%c", toupper(name[i]));
    }
    printf("\n");
}
