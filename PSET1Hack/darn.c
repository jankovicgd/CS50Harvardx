#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    long long x = 5105105105105100;
    char y[256];
    sprintf(y,"%lld",x);
    int checksum1 = 0;
    for (int i = 0; i < strlen(y); i++)
    {
        printf("%c", y[i]);
    }    
    printf ("\n");
    // calculating checksum
    for (int i = 0, z = strlen(y); i < z; i += 2)
    {
        if (((y[i] - 48) * 2) >= 10)
        {
            // if the number*2 is greater than 10
            int number = (y[i] - 48)*2;
            checksum1 += number/10 + ((float)number/10 - 1)*10;
            printf("%i and %i checksum: %i\n",y[i]-48, i, checksum1);
        }
        else
        {
            checksum1 += (y[i] - 48) * 2;
            printf("%i and %i checksum: %i\n",y[i]-48, i, checksum1);
        }
    }          
    
    printf("checksum: %i\n", checksum1);
    
    for (int j = 1, z = strlen(y); j < z; j += 2)
    {
        checksum1 += (y[j] - 48);
        printf("%c and %i\n", y[j], checksum1);
    }
    
    printf("checksum: %i\n", checksum1);
    
    if(y[0] == 53 && (y[1] == 49 || y[1] == 50 || y[1] == 51 || y[1] == 52 || y[1] == 53) && checksum1%10 == 0 && strlen(y) == 16)
        printf("true\n");
    else
        printf("false\n");
}
