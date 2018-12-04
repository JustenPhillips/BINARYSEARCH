#include "BinarySearch.h"
#include <iostream>
#include <fstream>
#include <stdint.h>
    
using namespace std;
    
    bool readBin(int32_t array[], int32_t size)
    {
        int32_t buff, index=0;
    
        fstream readFile;
    
        readFile.open("dataarray.bin", ios::in | ios::binary);
        if (readFile.is_open())
        {
            do
            {
                
                
                if (index < size)
                {
                    readFile.read(reinterpret_cast<char *>(&buff), sizeof(int32_t));
                    array[index] = buff;
                    ++index;
                    
                    
                }
                else
                {
                    cout << "file has too many values!" << endl;
                    return false;
                }
            } 
            while (!readFile.eof());
    
            cout << "total values read = " << index << endl;
            readFile.close();
            return true;
        }
        return false;
    }
    
    int32_t recursiveBinarySearch(int32_t array[], int32_t startIndex, int32_t endIndex, int32_t target)
    {
         if(startIndex < endIndex)
         {
             int32_t mid = (startIndex + endIndex)/2;
             
             if(target == array[mid])
             {
                 return mid;
             }
             else if(target < array[mid])
             {
                 return recursiveBinarySearch(array, startIndex, mid-1, target);
             }
             else if(target > array[mid])
             {
                 return recursiveBinarySearch(array, mid+1, endIndex, target);
             }
             else
             {
                 cout << "error" << endl;
             }
         }     
          return 0;
    }
    
    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    void merge(int32_t arr[], int32_t l, int32_t m, int32_t r)
    {
        int32_t i, j, k;
        int32_t n1 = m - l + 1;
        int32_t n2 =  r - m;
     
        /* create temp arrays */
        int32_t L[n1], R[n2];
     
        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];
     
        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
           if (L[i] <= R[j])
           {
               arr[k] = L[i];
               i++;
           }
           else
           {
               arr[k] = R[j];
               j++;
           }
           k++;
       }
    
       /* Copy the remaining elements of L[], if there
          are any */
       while (i < n1)
       {
           arr[k] = L[i];
           i++;
           k++;
       }
    
       /* Copy the remaining elements of R[], if there
          are any */
       while (j < n2)
       {
           arr[k] = R[j];
           j++;
           k++;
       }
   }
    
   /* l is for left index and r is right index of the
      sub-array of arr to be sorted */
   bool mergeSort(int32_t arr[], int32_t l, int32_t r)
   {  
   
       
       if(l < r)
       {
           // Same as (l+r)/2, but avoids overflow for
           // large l and h
           int32_t m = l+(r-l)/2;
    
           // Sort first and second halves
           mergeSort(arr, l, m);
           mergeSort(arr, m+1, r);
    
           merge(arr, l, m, r);
       }
   
       return true;//succesful
   
   }
