#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

/**
*   Checksum calculator - hacker edition
*   Author: Nikola Jankovic
*/

// Call made functions
bool checksum(long long x);
bool isVisa(long long x);
bool isMaster(long long x);
bool isAmex(long long x);

int main(void)
{

    // Prompt user for credit card
    printf("Enter credit card no:");
    long long cardno = GetLongLong();
    
    // Check what card it is
    if (isAmex(cardno) == true)
    {
        printf("AMEX\n");
    }
    else if (isVisa(cardno) == true)
    {
        printf("VISA\n");
    }
    else if (isMaster(cardno) == true)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }    
}

// checksum calculates if the number is legitimate
bool checksum(long long x)
{

    char y[256];
    sprintf(y,"%lld",x);
    int checksum1 = 0;
    
    // calculating checksum
    if (strlen(y) % 2 == 0)
    {
        // calculating for even numbers
        for (int i = 0, length = strlen(y); i < length; i += 2)
        {
            if (((y[i] - 48) * 2) >= 10)
            {
                // if the number*2 is greater or equal to 10
                int n = (y[i] - 48) * 2;
                checksum1 += n / 10 + ( ( float ) n / 10 - 1) * 10;
            }
            else
            {
                checksum1 += (y[i] - 48) * 2;
            }            
        }
        for (int j = 1, length = strlen(y); j < length; j += 2)
        {
            checksum1 += (y[j] - 48);
        }        
    }
    else
    {
        // calculating for odd numbers
        for (int i = 1, length = strlen(y); i < length ; i += 2)
        {
            if (((y[i] - 48) * 2) >= 10)
            {
                // if the number*2 is greater or equal to 10
                int n = (y[i] - 48) * 2;
                checksum1 += n / 10 + ( ( float ) n / 10 - 1) * 10;
            }
            else
            {
                checksum1 += (y[i] - 48) * 2;
            }
        }
        for (int j = 0, length = strlen(y); j <= length; j += 2)
        {
            checksum1 += (y[j] - 48);
        }        
    }    

    if (checksum1 % 10 == 0)
        return true;
    else
        return false;
}

// isVisa checks if the card is Visa
bool isVisa(long long x)
{
    char y[256];
    sprintf(y,"%lld",x);
    if (y[0] == 52 && checksum(x) == true && strlen(y) == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isAmex checks if the card is Amex
bool isAmex(long long x)
{
    char y[256];
    sprintf(y,"%lld",x);
    if (y[0] == 51 && (y[1] == 52 || y[1] == 55) 
    && checksum(x) == true && strlen(y) == 15)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isMaster checks if the card is Master
bool isMaster(long long x)
{
    char y[256];
    sprintf(y,"%lld",x);
    if (y[0] == 53 && 
    (y[1] == 49 || y[1] == 50 || y[1] == 51 || y[1] == 52 || y[1] == 53) && 
    checksum(x) == true && strlen(y) == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}
