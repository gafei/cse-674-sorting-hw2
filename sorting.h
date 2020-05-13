#include <iostream>
#include <vector>
#include <fstream>

//sorting.h

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

enum sortType{ ascendingNum, descendingNum, randomNum }; //used for readFile function
std::vector<int> genDataAscend(int elements); // used for generating Data
std::vector<int> genDataDescend(int elements); // used for generating Data
std::vector<int> genDataRandom(int elements); // used for generating Data
std::vector<int> readFile(enum sortType fileType, int elementsToRead); // used for reading file

static const uint32_t L[] =  {1UL, 1UL, 3UL, 5UL, 9UL, 15UL, 25UL, 41UL, 67UL, 109UL, 177UL,
    287UL, 465UL, 753UL, 1219UL, 1973UL, 3193UL, 5167UL, 8361UL,
    13529UL, 21891UL, 35421UL, 57313UL, 92735UL, 150049UL,
    242785UL, 392835UL, 635621UL, 1028457UL, 1664079UL, 2692537UL,
    4356617UL, 7049155UL, 11405773UL, 18454929UL, 29860703UL,
    48315633UL, 78176337UL, 126491971UL, 204668309UL, 331160281UL,
    535828591UL, 866988873UL, 1402817465UL, 2269806339UL,
    3672623805UL}; //these numbers only go up to 32 bit

    //lookup table of leo numbers



struct ISort{
    // this is an abstract class
    ISort(){ }
    virtual ~ISort(){}
    virtual void sort (std::vector<int> &vector )= 0;
    // pure virtual function have =0's, functions must be overriden. 
    

};



class insertionSort : public ISort{

    public: 
        void sort(std::vector <int> &vector);

};

class selectionSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
        void swap(std::vector<int>& a, int index1, int index2);
};

class bubbleSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
};

class bubbleSortFlag : public ISort{

    public:
        void sort(std::vector <int> &vector);
        void swap(std::vector<int>& a, int index1, int index2);
        

};

class heapSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
    private:
        void hSort(std::vector <int> &vector);
        void heapify(std::vector <int> &vector, int n, int i);
        void createHeap(std::vector <int> &vector);
        void swap(std::vector <int> &vector, int a, int b);
    
        
};

class mergeSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
    private:
       // void mSort(std::vector <int> &vector); 
       // overloaded function is below
        std::vector <int> & mSort(std::vector <int> &input, int start, int end); 
        std::vector <int> & merge(std::vector <int> &input, int leftLow, int leftHigh, int rightLow, int rightHigh);    

//std::vector <int> & mSort(std::vector <int> &input, int len);
//std::vector <int> & merge(std::vector <int> &left, std::vector <int> &right, int leftSize, int rightSize);

};

class quickSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
    
    private:
        void qSort(std::vector <int> &vector, int start, int end);
        int partition(std::vector <int> &vector, int start, int end);
        void swap(std::vector <int> &vector, int a, int b);
      
};

class radixSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
    private:
        void rSort(std::vector <int> &inputVector, int exp);    
        


};



class smoothSort : public ISort{
    
    public:
    
    typedef struct {
        uint64_t mask; // Leo. nums. in use (sizes of existing heaps)
        int offset;    // Add this to every bit's position ('mask'
     } heapsizes;      // always ends with a '1' bit, so 'offset' is also the size of the smallest heap)

    
    /***
    struct heapSizes {

        uint64_t mask; // size of the heaps
        int offset;

    }; 
    ***/
    public:
        void sort(std::vector <int> &vector);


        heapsizes heapify (int A[], uint32_t num);

        void extract (int A[], uint32_t num, heapsizes hsz);
        void sift_in (int * root, int size);
        void interheap_sift (int * root, heapsizes hsz);
        void smoothsort (int A[], uint32_t num);

        //heapSizes heapify(std::vector <int> &sortVector, uint32_t num);
        //void extract(std::vector <int> &sortVector, uint32_t num, heapSizes hSize);
        //void sSort(std::vector <int> & sortedVector, uint32_t num);

        //void sift_in (std::vector <int> & sortedVector, uint32_t *root, int size);
        //void interheap_sift (std::vector <int> & sortedVector, uint32_t *root, heapSizes hsize);


       // void trinkle(std::vector <int> &sortVector, int p, int pshift, int head, bool isTrusty);
        //void sort(std::vector <int> &inputVector, int low, int hi); //override



};
class countingSort : public ISort{

    public:
        void sort(std::vector <int> &vector);
        

};




// insertion, selection, bubble, bubble sort, with flag, heapsort, mergesort, quicksort, radixsort, 
// smoothsort, countingsort

//heapsort
//readixsort
//countingsort