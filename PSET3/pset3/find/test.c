#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int values[], int n)
{
    bool swap;
    int temp;
    do
    {
        swap = false;
        for (int i = 1; i < n; i++)
        {
            if(values[i - 1] > values[i])
            {
                temp = values[i - 1];
                values[i - 1] = values[i];
                values[i] = temp;
                swap = true;
            }
        }
    }while(swap == true);
}

int main(void)
{
    int a[] = {5, 3, 1, 4, 6};
    sort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%i", a[i]);
    }
    printf("\n");
}
