//sorting.cpp
#include "sorting.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <list>

std::vector<int> genDataAscend(int elements){

    vector<int> vectorData; 
    std::ofstream ascendout ("ascending.txt"); //gen a file called ascendtest.txt
    int counter =0;


        for(int i=1; i<=elements; i++){
            vectorData.push_back(i);    
            counter++;
 
        if (counter %10==0){
                ascendout << i << "\n";
            }
        else{
                ascendout << i << "-";
            }
        }



    return vectorData;
}
std::vector<int> genDataDescend(int elements){

    vector<int> vectorData; 
    std::ofstream descendout ("descending.txt"); //gen a file called descending.txt
    int counter =0;

        for(int i=elements; i>0; i--){
            vectorData.push_back(i);    
            counter++;

        if (counter %10==0){
                descendout << i << "\n";
            }
        else{
                descendout << i << "-";
            }
        }

        return vectorData;


}

std::vector<int> genDataRandom(int elements){

    vector<int> vectorData; 
    std::ofstream randomout ("random.txt"); //gen a file called random.txt
    int counter =0;

        for(int i=1; i<=elements; i++){
            vectorData.push_back(i);    
        }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(vectorData.begin(), vectorData.end(), std::default_random_engine(seed));

    for(int i=0; i<elements; i++)
        {
            int num = vectorData[i];
            counter++;
           if (counter %10==0){
                randomout << num << "\n";
            }
            else{
                randomout << num << "-";
            }
            

        }

        return vectorData;


}
std::vector<int> readFile(enum sortType fileType, int elementsToRead){

    std::ifstream inputFile; //creates an input file stream
    vector<int> vectorTest;
    std::string str;
    int dCount =0;

    switch (fileType){

        case ascendingNum:
            cout <<"This is ascending. \n";
            inputFile.open("ascending.txt"); //can put a check in here, in case file doesn't exist
            
            int x, xx;
            while(!inputFile.eof()){
                if(getline(inputFile,str, '-')){
                    int pos = str.find("\n");
                    std::string sub = str.substr(pos + 1); 

                    x = stoi(str);
                    vectorTest.push_back(x);
                    // break if it reaches vectorTest.size()?
                    if(vectorTest.size() == elementsToRead){
                        break;
                    }

                    if(pos!=-1){

                        if(sub.empty()==true){
                            //cout <<"end of file reached.";
                            break;
                            }   
                        xx =stoi(sub);
                        vectorTest.push_back(xx);
                    }

                }
            }
            break;

        case descendingNum:
            cout <<"This is descending. \n";
            inputFile.open("descending.txt"); //can put a check in here, in case file doesn't exist
            
            int y, yy;
            
            while(!inputFile.eof()){
                if(getline(inputFile,str, '-')){
                    int pos = str.find("\n");
                    std::string sub = str.substr(pos + 1); // find the number after \n

                    y = stoi(str);
                    vectorTest.push_back(y);
                    // break if it reaches vectorTest.size()?
                    if(vectorTest.size() == elementsToRead){
                        break;
                    }


                    if(pos!=-1){

                        if(sub.empty()==true){
                            //cout <<"end of file reached.";
                            break;
                            }   
                        yy =stoi(sub); // place the number after \n into the vector
                        vectorTest.push_back(yy);
                    }

                }
            }
        break;

        case randomNum:
            cout <<"This is random. \n";
            inputFile.open("random.txt"); //can put a check in here, in case file doesn't exist
            
            int z, zz;
            while(!inputFile.eof()){
            //while(getline(inputFile, str)){
            //while(inputFile >> str){    
                if(getline(inputFile,str, '-')){
                    int pos = str.find("\n");
                    std::string sub = str.substr(pos + 1); 

                    z = stoi(str);
                    vectorTest.push_back(z);
                    // break if it reaches vectorTest.size()?
                    if(vectorTest.size() == elementsToRead){
                        break;
                    }        


                    if(pos!=-1){

                        if(sub.empty()==true){
                            //cout <<"end of file reached.";
                            break;
                            }   
                        zz =stoi(sub);
                        vectorTest.push_back(zz);
                    }

                }
            }
            break;
                  
    }
    
    return vectorTest;


}




void insertionSort::sort(std::vector <int> &vector){

    for (int i = 1; i < vector.size(); i++){

        int element = vector[i]; // element contains data we intend on bringing to the sorted array 
        int j = i -1; //points to the last index of the sorted array

        while(j>=0 && vector[j] > element){

            vector [j+1] = vector[j];
            j--;
        }

        vector[j+1] = element;
    }

}

void selectionSort::sort(std::vector <int> &vector){
     size_t j, least;
        for(size_t i = 0; i < (vector.size() - 1); ++i){
            for(j = i + 1, least = i; j < vector.size(); ++j){ 

                if(vector[j] <vector[least]){

                    least = j; 
                    
                    }
                }
            swap(vector, least, i); 
            
        }



}
void selectionSort::swap(std::vector<int>& a, int index1, int index2){ 
        
        int lhs = a[index1];
        int rhs = a[index2];
        a[index1] = rhs;
        a[index2] = lhs;

    }

void bubbleSort::sort(std::vector <int> &vector){

    for(int i = 0; i < vector.size(); ++i){
        for(int j = i + 1; j < vector.size(); ++j){
        int lhs = vector[i];
        int rhs = vector[j];
        if(rhs < lhs){
            vector[i] = rhs;
            vector[j] = lhs;
            }
        }
    }


}

void bubbleSortFlag::sort(std::vector <int> &vector){

    bool swapped = true;
    while(swapped){
        swapped = false;
        for(size_t i = 1; i < vector.size(); ++i){
            if(vector[i - 1] > vector[i]){
                swap(vector, i-1, i);
                swapped = true;
                }
        }
    }

}

void bubbleSortFlag::swap(std::vector<int>& a, int index1, int index2){

    int lhs = a[index1];
    int rhs = a[index2];
    a[index1] = rhs;
    a[index2] = lhs;


}

void quickSort::sort(std::vector <int> &vector){

    // start and end are fixed here
    int start = 0;
    int end = vector.size() - 1;

    qSort(vector, start, end);



}
void quickSort::qSort(std::vector <int> &vector, int start, int end){

        if (start < end){
        
        int q;
        q = partition(vector, start, end); 
        qSort(vector, start, q-1);
        qSort(vector, q+1, end);


    }

}


int quickSort::partition(std::vector <int> &vector, int start, int end){

    //int start = vector[0];
    //int end = vector.size() - 1;

    int x, i, j;
    x = vector[end]; // end is the initial pivot point
    i = start - 1;

    for (j = start; j<=end-1; j++){
        if(vector[j] <= x){
            i = i + 1;
            swap(vector, i, j);

        }

    }

    swap(vector, i+1, end);
    return i + 1;


}
void quickSort::swap(std::vector <int> &vector, int a, int b){

    int temp = vector[a];
    vector[a] = vector[b];
    vector[b] = temp;

}
void mergeSort::sort(std::vector <int> &vector){


//std::vector<int> returnVector = mSort(vector, 0, vector.size()-1);
    mSort(vector, 0, vector.size()-1);
//mSort(vector, vector.size());
/***
std::vector<int> returnVector = mSort(vector, vector.size());
    size_t i = 0;
    for(size_t i = 0; i < returnVector.size(); ++i){ 
        
        std::cout << returnVector[i] << " ";
        
        }
*****/
}

std::vector <int> & mergeSort::mSort(std::vector <int> &input, int start, int end){
    
    if (start>=end){
        return input; // we're done traversing the array here
    }
    else{

        int mid = (start + end) /2;
        mSort(input, start, mid);
        mSort(input, mid+1, end);
        merge(input, start, mid, mid+1, end);

        return input;


    }


}
std::vector <int> & mergeSort::merge(std::vector <int> &input, int leftLow, int leftHigh, int rightLow, int rightHigh){

    int length = rightHigh - leftLow+1;
    std::vector<int> *temp = new std::vector<int>(length);
    int left = leftLow;
    int right = rightLow;

    for (int i = 0; i < length; ++i) { 
        if (left > leftHigh)
            temp->at(i) = input[right++]; 
        else if (right > rightHigh)
            temp->at(i) = input[left++];
        else if (input[left] <= input[right])
            temp->at(i) = input[left++];
        else
            temp->at(i) = input[right++]; 
    }
    
    for (int i=0; i< length; ++i){
        input[leftLow++] = temp->at(i);

    } 

    return *temp;

}  

void heapSort::sort(std::vector <int> &vector){

    hSort(vector);

}
void heapSort::hSort(std::vector <int> &vector){

     int n = vector.size();   
        // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(vector, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(vector, 0, i); 
  
        // call max heapify on the reduced heap 
        heapify(vector, i, 0); 
    } 



}
void heapSort::heapify(std::vector <int> &vector, int heapSize, int index){

   int largest = index; // largest is the index root
   int leftChildIndex = 2*index +1; // left is 2i+1
   int rightChildIndex = 2*index+2; //right is 2i+2

    // if the left child is larger than root 
    if (leftChildIndex < heapSize && vector[leftChildIndex] > vector[largest]) 
        largest = leftChildIndex; 
  
    // if the right child is larger than largest so far 
    if (rightChildIndex < heapSize && vector[rightChildIndex] > vector[largest]) 
        largest = rightChildIndex; 
  
    // If largest is not root 
    if (largest != index) 
    { 
        swap(vector, index, largest); 
  
        // Recursively heapify the affected sub-tree 
        heapify(vector, heapSize, largest); 
    } 



}
void heapSort::swap(std::vector <int> &vector, int a, int b){

    int temp = vector[a];
    vector[a] = vector[b];
    vector[b] = temp;

}

void smoothSort::sort(std::vector <int> &vector){

    int *inputArray = vector.data();
    int elements = vector.size();
    smoothsort(inputArray, elements);


}

smoothSort::heapsizes smoothSort::heapify (int A[], uint32_t num){

    heapsizes hsz;       
    
    uint32_t i;          
    
    int wbf;             

    hsz.mask = 1;            
    hsz.offset = 1;           

    for (i=1; i<num; i++) 
    {
        if (hsz.mask & 2)          
        {                                  
            hsz.mask = (hsz.mask>>2) | 1;  
            hsz.offset += 2;
        }                          
        else if (hsz.offset == 1)  
        {
            hsz.mask = (hsz.mask << 1) | 1;  
            hsz.offset = 0;
        }
        else                       
        {
            hsz.mask = (hsz.mask << (hsz.offset-1)) | 1;
            hsz.offset = 1;
        }
        

        wbf = ( (hsz.mask & 2) &&
                i+1 < num                 ) ||
              ( hsz.offset > 0    &&
                1ULL+i+L[hsz.offset-1] < num );

        if (wbf)                       
            sift_in (A+i, hsz.offset); 
        else                           
            interheap_sift (A+i, hsz); 
    }                                  
                                       
    return hsz;   


}

void smoothSort::extract (int A[], uint32_t num, heapsizes hsz){
    uint32_t i;          // Loop index for traversing the array

    uint32_t ch[2];      
                         
    int j;
                             
    for (i=num-1; i>1; i--)  
    {
        if (hsz.offset<2)         
        {                         
            do                    
            {                    
                hsz.mask >>= 1;   
                hsz.offset ++;
            }                       
            while (!(hsz.mask&1));  
        }                           
        else                        
        {
            ch[1] = i - 1;                   
            ch[0] = ch[1] - L[hsz.offset-2]; 

            hsz.mask &= ~1ULL;       

            for (j=0; j<2; j++)     
            {                                           
                hsz.mask = (hsz.mask << 1) | 1;
                hsz.offset --;                  
                                               
                interheap_sift (A+ch[j], hsz);  
            }                                   
        }
    }
}
void smoothSort::sift_in (int * root, int size){
    
    
    int * left, * right; // Position of children heaps
    int * next;         
    int tmp;             
    int nsz;                     
    
    if (size < 2)      
        return;         

    tmp = *root;        
    
    do                      
    {
        right = root - 1;          
        left = right - L[size-2];
        
        if (*right < *left)         
        {
            next = left;            
            nsz = size - 1;         
        }
        else
        {
            next = right;           
            nsz = size - 2;         
        }
                                    
        if (*next <= tmp)           
            break;                  

        *root = *next;              
                                   
        root = next;                
        size = nsz;                 
    }
    while (size > 1);          
    
    *root = tmp;  

}
void smoothSort::interheap_sift (int * root, heapsizes hsz){

    int * next;   // Position of (root of) next heap
    int * left;   // Position of left child of current heap
    int * right;  // Position of right child of current heap
    int tmp;      // Value to move left
    int max;      // Effective root value of curr. heap
    
    tmp = *root;      
    
    while (hsz.mask != 1)  
    {                      
        max = tmp;
        
        if (hsz.offset > 1)           
        {
            right = root - 1;                 
            left = right - L[hsz.offset-2];
            
            if (max < *left)                  
                max = *left;                  
                                              
            if (max < *right)                
                max = *right;                
        }                                     
        
        next = root - L[hsz.offset];  

        if (*next <= max)           
            break;                   

        *root = *next;                
        root = next;                  
                                      
        do
        {                             
            hsz.mask >>= 1;           
            hsz.offset ++;            
        }                             
        while (!(hsz.mask&1));
    }
                                      
    *root = tmp;                      
    sift_in (root, hsz.offset);      



}
void smoothSort::smoothsort (int A[], uint32_t num){
       
    heapsizes hsz;
 
    if (num < 2)  // If there's only one element, it's done.
        return;   // The other functions assume 2 or more elements

    hsz = heapify (A, num);   // Build the ordered list of heaps

    extract (A, num, hsz);    // Consume the list of heaps


}

void radixSort::sort(std::vector <int> &vector){

    //int maxNum = vector.size();
    int maxNum = *max_element(vector.begin(), vector.end());
    for(int exp = 1; maxNum/exp > 0; exp *=10){
        rSort(vector, exp);
    }
    

}

void radixSort::rSort(std::vector <int> &inputVector, int exp){

        //gets max value of vector
        int max_value = *max_element(inputVector.begin(), inputVector.end());
        max_value = max_value+1; //since we start at 1, we need to add another number here
        int counts[max_value];

        //make an output vector?
        std::vector <int> output(inputVector.size());

        // n is the total amount of elements. should be vector.size()-1
        //clear counts
        for(int i = 0; i < max_value; ++i){
            counts[i] = 0; //sets all elements in counts to 0
        }

        //Store count of occurances in counts[]
        for(size_t i = 0; i < inputVector.size(); i++){
            //++counts[vector[i]];
            counts[(inputVector[i]/exp)%10]++;
            //(vector[i]/exp)%10
        }

        // Change count[i] so that count[i] now contains actual 
        //  position of this digit in output[] 
        for (int i = 1; i < 10; i++)  // max number of 10 digits here
            counts[i] += counts[i - 1]; 


        //build the output array

        for(int i = inputVector.size()-1; i>=0; i--){
            
            output[counts[ (inputVector[i]/exp)%10 ] - 1] = inputVector[i]; 
            counts[ (inputVector[i]/exp)%10 ]--; 
            
        }

        //copy output vector to input vector, so that input vector
        // now contains the sorted numbers according to the digits
        for(int i = 0; i < inputVector.size(); i++){
            inputVector[i] = output[i];
        }
        
}

void countingSort::sort(std::vector <int> &vector){

        //gets max value of vector
        int max_value = *max_element(vector.begin(), vector.end());
        max_value = max_value+1; //since we start at 1, we need to add another number here
        int counts[max_value];


        //clear counts
        for(int i = 0; i < max_value; ++i){
            counts[i] = 0; //sets all elements in counts to 0
        }

        //calculate count of each number
        for(size_t i = 0; i < vector.size(); ++i){
            ++counts[vector[i]];
        }

        //write back to the vector
        vector.clear();
        for(int i = 0; i < max_value; ++i){
            int c = counts[i];
                for(int j = 0; j < c; ++j){ //only push back numbers that have 1 or more counts
                vector.push_back(i);
            } 
        }

}

//selection, bubble, bubble sort, with flag, heapsort, mergesort, quicksort, radixsort, 
// countingsort

