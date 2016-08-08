#include <cs50.h>
#include <stdlib.h>
#include "helpers.h"

//Binary search
bool search(int value, int values[], int n) {
    int n0 = 0;
    while (n > 0) {
    int m = n / 2;
        if (values[n0 + m] == value) return true;
        else if (values[n0 + m] > value) n = m; // left part
        else { //right part
            n0 = n0 + m + 1;
            n = n - m - 1;
        }
    } 
    return false;
}

//Bubble sort
void sort(int values[], int n) {
    int swaps = 0;  
    int temp = 0;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (values[j+1] < values[j]) {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
                swaps += 1;
            }  
        }
        if (swaps == 0) break;
    }
    return;
}
