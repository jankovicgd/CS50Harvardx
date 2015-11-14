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
 
 /**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 0)
        return -1;
    
    int max = n - 1;
    int min = 0;
    int midpoint;
    int midvalue;
    bool f;
    
    do
    {
        if (max < min)
        {
            f = 0;
            break;
        }
        else
        {
            midpoint = (max + min) / 2;
            if (values[midpoint] < value)
            {
                min = midpoint + 1;
            }
            else if (values[midpoint] > value)
            {
                max = midpoint - 1;
            }
            else
            {
                midvalue = values[midpoint];
                f = 1;
            }
        }
    }while (midvalue != value);
    
    return f;
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
