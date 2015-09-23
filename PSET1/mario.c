#include <stdio.h>
#include <cs50.h>

/**
*   Mario - print hashes corresponding to specified height
*   Author: Nikola Jankovic
*/

int main(void)
{
    // Prompt the user for height  
    int height;
    do
    {
        printf("Specify the height of the pyramid:");
        height = GetInt();
    }
    while(height > 23 || height < 0);
    
    // Loop that draws the pyramid
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height - (i + 1); j++)
            printf(" ");
        for(int k = 0; k < i + 2; k++)
            printf("#");
        printf("\n");
    }
}
