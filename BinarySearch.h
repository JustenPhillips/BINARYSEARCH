
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
     
#include <stdint.h>
#include <iostream>
   
//read bin file into array
bool readBin(int32_t [], int32_t);
    
    
void merge(int32_t [], int32_t, int32_t, int32_t);
bool mergeSort(int32_t [], int32_t, int32_t);
    
//search array for integer
int32_t recursiveBinarySearch(int32_t [], int32_t, int32_t, int32_t);
    
#endif
