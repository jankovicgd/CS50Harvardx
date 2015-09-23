#include <stdio.h>
#include <cs50.h>
#include <math.h>

/**
*   Application that calculates the lowest ammount of coin returned
*   Author: Nikola Jankovic
*/

int main(void)
{
    // Input of change
    float change;
    do
    {
        printf("The ammount of change:");
        change = GetFloat();
    }
    while (change <= 0);
    
    
    // Convert change to calculate number of coins
    change = round(change * 100);
    
    // Initialize coins
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    // Initialize counter
    int coins = 0;
    
    // Do the math
    do
    {
        if ((change - quarter) >= 0)
        {
            change = change - quarter;
            coins++;
        }
        else if ((change - dime) >= 0)
        {
            change = change - dime;
            coins++;
        }
        else if ((change - nickel) >= 0)
        {
            change = change - nickel;
            coins++;
        }
        else
        {
            change = change - penny;
            coins++;
        }
    }
    while (change > 0);
    
    printf("%i\n", coins);
    
}
