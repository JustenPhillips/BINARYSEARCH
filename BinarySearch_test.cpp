   #include "BinarySearch.h"
   #include <stdint.h>
   #include <iostream>
    
    using namespace std;
    
    int main()
    {
        int32_t size=125026;
        //int32_t array[size];
        int32_t * array = new int32_t[size];
        int32_t number=0, result=0;
        if (NULL == array)
        {
            cout << "Failed to allocate " << size << " bytes of memory!" << endl;
            return -1;
        }
        
       
        
        
        if (readBin(array, size))
            {
                cout<<"file read into memory  successfully"<<endl;
                    	if(mergeSort(array, 0, size-1))
                            {
    			            cout << "Your array "
    			            << "has been successfully "
    			            << "sorted without error."
    			            << endl;}
    			            else{cout<<"could not sort file"<<endl;
    			            return 0;}
                
              
               cout << "Please input a postive integer to search: "<< endl;
            cin >> number;
    			 //accumulator
    			 result = recursiveBinarySearch(array, 0, size, number);
    			 cout << result << endl;
    			 if(result > 0)
    			 {
    			 cout << "Your number was found in " << result <<  " elements in the array" << endl;
    			 }
    			 else
    			 {
    			     cout << "Your number could not be found";
    			 }
            }
    		else
            {
                cout << "Could not read file into memory" << endl;
    		}
    		
    delete[] array;
    
      return 0;
    }
