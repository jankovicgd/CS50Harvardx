/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 *
bool search(int value, int values[], int n)
{
    if (value < 0 || n < 0)
    {
        return false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }   
    }
    
    return false;
}
 */
bool search(int value, int values[], int n)
{
    int min = values[0];
    int max = values[n - 1];
    do
    {
        if(n%2 == 0)
        {
        
        }
        else
        {
        
        }
    
    }while (current != value)
}
/**
 * Sorts array of n values.
 */
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
