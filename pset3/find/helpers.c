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
 */
bool search(int value, int values[], int n)
{
    if(n<0){
        return false;
    }
    int first = 0;
    int last = n - 1;
    int middle = (first + last) / 2;
    while(first<=last){
        if(values[middle] <value){
            first = middle + 1;
        }else if (values[middle] >  value){
            last = middle - 1;
        }else{
            return true;
        }
        middle = (first + last) / 2;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i , temp;
    int swapped = 0;
    while(1){
        if(swapped){
            break;
        }
        swapped = 1;
        for(i=0;i<n-1;i++){
            if(values[i]>values[i+1]){
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swapped = 0;
            }
        }
    }
}
