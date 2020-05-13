#include <iostream>
#include <string>
#include "sorting.h"
#include <chrono>



selectionSort selectionSortObj;
insertionSort insertionSortObj;
bubbleSort bubbleSortObj;
bubbleSortFlag bubbleSortFlagObj;
quickSort quickSortObj;
mergeSort mergeSortObj;
heapSort heapSortObj;
countingSort countingSortObj;
smoothSort smoothSortObj;
radixSort radixSortObj;


static void showUsage(std::string name)
{
    std::cerr << "Usage: " << "main " << "[OPTIONS]\n"
              << "Options:\n"
              << "\t-h, --help\t\tShow this help message\n"
              << "\t-a, --ascending\t\tSpecify sort with ascending.txt\n"
			  << "\t-d, --descending\tSpecify sort with descending.txt\n"
			  << "\t-r, --random \t\tSpecify sort with random.txt\n"
              << std::endl;
}



int main(int argc, char *argv[]){

   int numbersToGen = 128000;
   int initialNum =1000;
	 
	 cout <<"\n";
     cout << "Generating " << numbersToGen << " Numbers to ";
     cout << "ascending.txt, descending.txt and random.txt\n\n";
    
    genDataAscend(numbersToGen);
    genDataDescend(numbersToGen);
    genDataRandom(numbersToGen);
	
	if (argc < 1) {
			showUsage(argv[0]);
			return 1;
		}
		std::vector <std::string> sortType;
		std::string ascending;
		std::string descending;
		std::string random;
		for (int i = 1; i < argc; ++i) {
			std::string arg = argv[i];
			if ((arg == "-h") || (arg == "--help")) {			
				showUsage(argv[0]);
				return 0;
			
			
			} 
			else if ((arg == "-a") || (arg == "--ascending")) {
	
			while(initialNum <=numbersToGen){ 
        
				cout << "Sorting " << initialNum << " Ascending Elements\n";
			   
				cout <<"After Insertion Sort\n";
				vector<int> vectorTestascendInsertion = readFile(ascendingNum, initialNum);

				auto startInsertion = std::chrono::high_resolution_clock::now();
				insertionSortObj.sort(vectorTestascendInsertion);
				auto finishInsertion = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedInsertion = finishInsertion - startInsertion;
				std::cout << "Elapsed time: " << qselapsedInsertion.count() << " s\n";
				std::cout <<"\n";
				
				cout <<"After Selection Sort\n";
				vector<int> vectorTestascendSelection = readFile(ascendingNum, initialNum);

				auto startSelection = std::chrono::high_resolution_clock::now();
				selectionSortObj.sort(vectorTestascendSelection);
				auto finishSelection = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedSelection = finishSelection - startSelection;
				std::cout << "Elapsed time: " << qselapsedSelection.count() << " s\n";
				std::cout <<"\n";
				
				
				cout <<"After Bubble Sort\n";
				vector<int> vectorTestascendbSort = readFile(ascendingNum, initialNum);

				auto startbSort = std::chrono::high_resolution_clock::now();
				bubbleSortObj.sort(vectorTestascendbSort);
				auto finishbSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedbSort = finishbSort - startbSort;
				std::cout << "Elapsed time: " << qselapsedbSort.count() << " s\n";
				std::cout <<"\n";
				

			   
				cout <<"After Bubble Sort with flag\n";
				vector<int> vectorTestascendbSortFlag = readFile(ascendingNum, initialNum);

				auto startbSortFlag = std::chrono::high_resolution_clock::now();
				bubbleSortFlagObj.sort(vectorTestascendbSortFlag);
				auto finishbSortFlag = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedbSortFlag = finishbSortFlag - startbSortFlag;
				std::cout << "Elapsed time: " << qselapsedbSortFlag.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Heapsort\n";
				vector<int> vectorTestascendheapSort = readFile(ascendingNum, initialNum);

				auto startheapSort = std::chrono::high_resolution_clock::now();
				heapSortObj.sort(vectorTestascendheapSort);
				auto finishheapSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedheapSort = finishheapSort - startheapSort;
				std::cout << "Elapsed time: " << qselapsedheapSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Merge Sort\n";
				vector<int> vectorTestascendmergeSort = readFile(ascendingNum, initialNum);

				auto startmergeSort = std::chrono::high_resolution_clock::now();
				mergeSortObj.sort(vectorTestascendmergeSort);
				auto finishmergeSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedmergeSort = finishmergeSort - startmergeSort;
				std::cout << "Elapsed time: " << qselapsedmergeSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Quicksort\n";
				vector<int> vectorTestascendqSort = readFile(ascendingNum, initialNum);

				auto startqSort = std::chrono::high_resolution_clock::now();
				quickSortObj.sort(vectorTestascendqSort);
				auto finishqSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedqSort = finishqSort - startqSort;
				std::cout << "Elapsed time: " << qselapsedqSort.count() << " s\n";
				std::cout <<"\n";


				cout <<"After Radix Sort\n";

				vector<int> vectorTestascendrSort = readFile(ascendingNum, initialNum);

				auto startrSort = std::chrono::high_resolution_clock::now();
				radixSortObj.sort(vectorTestascendrSort);
				auto finishrSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedrSort = finishrSort - startrSort;
				std::cout << "Elapsed time: " << qselapsedrSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Smooth Sort\n";
				 
				vector<int> vectorTestascendsmoothsort = readFile(ascendingNum, initialNum);
				auto startsSort = std::chrono::high_resolution_clock::now();
				smoothSortObj.sort(vectorTestascendsmoothsort);
				auto finishsSort = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> qselapsedsSort = finishsSort - startsSort;
				std::cout << "Elapsed time: " << qselapsedsSort.count() << " s\n";
        std::cout <<"\n";

				cout <<"After Counting Sort\n";

				vector<int> vectorTestascendcSort = readFile(ascendingNum, initialNum);

				auto startcSort = std::chrono::high_resolution_clock::now();
				countingSortObj.sort(vectorTestascendcSort);
				auto finishcSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedcSort = finishcSort - startcSort;
				std::cout << "Elapsed time: " << qselapsedcSort.count() << " s\n";
				std::cout <<"\n";
			   
			/*********************************************************
				 vector<int> vectorTestdescendsmoothsort = readFile(descendingNum, initialNum);
				 auto start = std::chrono::high_resolution_clock::now();
				 smoothSortObj.sort(vectorTestdescendsmoothsort);
				 auto finish = std::chrono::high_resolution_clock::now();

				 std::chrono::duration<double> qselapsed = finish - start;
				 std::cout << "Elapsed time: " << qselapsed.count() << " s\n";

			************************************************************/
				initialNum = initialNum*2;
			 }
			
			
			//return 0;
			}
			else if ((arg == "-d") || (arg == "--descending")){
				
				while(initialNum <=numbersToGen){ 
        
				cout << "Sorting " << initialNum << " Descending Elements\n";
			   
				cout <<"After Insertion Sort\n";
				vector<int> vectorTestdescendInsertion = readFile(descendingNum, initialNum);

				auto startInsertion = std::chrono::high_resolution_clock::now();
				insertionSortObj.sort(vectorTestdescendInsertion);
				auto finishInsertion = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedInsertion = finishInsertion - startInsertion;
				std::cout << "Elapsed time: " << qselapsedInsertion.count() << " s\n";
				std::cout <<"\n";
				//vectorTestdescend.clear();
				
				cout <<"After Selection Sort\n";
				vector<int> vectorTestdescendSelection = readFile(descendingNum, initialNum);

				auto startSelection = std::chrono::high_resolution_clock::now();
				selectionSortObj.sort(vectorTestdescendSelection);
				auto finishSelection = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedSelection = finishSelection - startSelection;
				std::cout << "Elapsed time: " << qselapsedSelection.count() << " s\n";
				std::cout <<"\n";
				
				
				cout <<"After Bubble Sort\n";
				vector<int> vectorTestdescendbSort = readFile(descendingNum, initialNum);

				auto startbSort = std::chrono::high_resolution_clock::now();
				bubbleSortObj.sort(vectorTestdescendbSort);
				auto finishbSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedbSort = finishbSort - startbSort;
				std::cout << "Elapsed time: " << qselapsedbSort.count() << " s\n";
				std::cout <<"\n";
				

			   
				cout <<"After Bubble Sort with flag\n";
				vector<int> vectorTestdescendbSortFlag = readFile(descendingNum, initialNum);

				auto startbSortFlag = std::chrono::high_resolution_clock::now();
				bubbleSortFlagObj.sort(vectorTestdescendbSortFlag);
				auto finishbSortFlag = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedbSortFlag = finishbSortFlag - startbSortFlag;
				std::cout << "Elapsed time: " << qselapsedbSortFlag.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Heapsort\n";
				vector<int> vectorTestdescendheapSort = readFile(descendingNum, initialNum);

				auto startheapSort = std::chrono::high_resolution_clock::now();
				heapSortObj.sort(vectorTestdescendheapSort);
				auto finishheapSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedheapSort = finishheapSort - startheapSort;
				std::cout << "Elapsed time: " << qselapsedheapSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Merge Sort\n";
				vector<int> vectorTestdescendmergeSort = readFile(descendingNum, initialNum);

				auto startmergeSort = std::chrono::high_resolution_clock::now();
				mergeSortObj.sort(vectorTestdescendmergeSort);
				auto finishmergeSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedmergeSort = finishmergeSort - startmergeSort;
				std::cout << "Elapsed time: " << qselapsedmergeSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Quicksort\n";
				vector<int> vectorTestdescendqSort = readFile(descendingNum, initialNum);

				auto startqSort = std::chrono::high_resolution_clock::now();
				quickSortObj.sort(vectorTestdescendqSort);
				auto finishqSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedqSort = finishqSort - startqSort;
				std::cout << "Elapsed time: " << qselapsedqSort.count() << " s\n";
				std::cout <<"\n";


				cout <<"After Radix Sort\n";

				vector<int> vectorTestdescendrSort = readFile(descendingNum, initialNum);

				auto startrSort = std::chrono::high_resolution_clock::now();
				radixSortObj.sort(vectorTestdescendrSort);
				auto finishrSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedrSort = finishrSort - startrSort;
				std::cout << "Elapsed time: " << qselapsedrSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Smooth Sort\n";
				
				vector<int> vectorTestdescendsmoothsort = readFile(descendingNum, initialNum);
				auto startsSort = std::chrono::high_resolution_clock::now();
				smoothSortObj.sort(vectorTestdescendsmoothsort);
				auto finishsSort = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> qselapsedsSort = finishsSort - startsSort;
				std::cout << "Elapsed time: " << qselapsedsSort.count() << " s\n";
        std::cout <<"\n";

				cout <<"After Counting Sort\n";

				vector<int> vectorTestdescendcSort = readFile(descendingNum, initialNum);

				auto startcSort = std::chrono::high_resolution_clock::now();
				countingSortObj.sort(vectorTestdescendcSort);
				auto finishcSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedcSort = finishcSort - startcSort;
				std::cout << "Elapsed time: " << qselapsedcSort.count() << " s\n";
				std::cout <<"\n";
			   
			/*********************************************************
				 vector<int> vectorTestdescendsmoothsort = readFile(descendingNum, initialNum);
				 auto start = std::chrono::high_resolution_clock::now();
				 smoothSortObj.sort(vectorTestdescendsmoothsort);
				 auto finish = std::chrono::high_resolution_clock::now();

				 std::chrono::duration<double> qselapsed = finish - start;
				 std::cout << "Elapsed time: " << qselapsed.count() << " s\n";

			************************************************************/
				initialNum = initialNum*2;
			 }
				
			}
			else if ((arg == "-r") || (arg == "--random")){

				while(initialNum <=numbersToGen){ 
				cout << "Sorting " << initialNum << " Random Elements\n";
			   
				cout <<"After Insertion Sort\n";
				vector<int> vectorTestrandomInsertion = readFile(randomNum, initialNum);

				auto startInsertion = std::chrono::high_resolution_clock::now();
				insertionSortObj.sort(vectorTestrandomInsertion);
				auto finishInsertion = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedInsertion = finishInsertion - startInsertion;
				std::cout << "Elapsed time: " << qselapsedInsertion.count() << " s\n";
				std::cout <<"\n";
				
				cout <<"After Selection Sort\n";
				vector<int> vectorTestrandomSelection = readFile(randomNum, initialNum);

				auto startSelection = std::chrono::high_resolution_clock::now();
				selectionSortObj.sort(vectorTestrandomSelection);
				auto finishSelection = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedSelection = finishSelection - startSelection;
				std::cout << "Elapsed time: " << qselapsedSelection.count() << " s\n";
				std::cout <<"\n";
				
				
				cout <<"After Bubble Sort\n";
				vector<int> vectorTestrandombSort = readFile(randomNum, initialNum);

				auto startbSort = std::chrono::high_resolution_clock::now();
				bubbleSortObj.sort(vectorTestrandombSort);
				auto finishbSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedbSort = finishbSort - startbSort;
				std::cout << "Elapsed time: " << qselapsedbSort.count() << " s\n";
				std::cout <<"\n";
				

			   
				cout <<"After Bubble Sort with flag\n";
				vector<int> vectorTestrandombSortFlag = readFile(randomNum, initialNum);

				auto startbSortFlag = std::chrono::high_resolution_clock::now();
				bubbleSortFlagObj.sort(vectorTestrandombSortFlag);
				auto finishbSortFlag = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedbSortFlag = finishbSortFlag - startbSortFlag;
				std::cout << "Elapsed time: " << qselapsedbSortFlag.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Heapsort\n";
				vector<int> vectorTestrandomheapSort = readFile(randomNum, initialNum);

				auto startheapSort = std::chrono::high_resolution_clock::now();
				heapSortObj.sort(vectorTestrandomheapSort);
				auto finishheapSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedheapSort = finishheapSort - startheapSort;
				std::cout << "Elapsed time: " << qselapsedheapSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Merge Sort\n";
				vector<int> vectorTestrandommergeSort = readFile(randomNum, initialNum);

				auto startmergeSort = std::chrono::high_resolution_clock::now();
				mergeSortObj.sort(vectorTestrandommergeSort);
				auto finishmergeSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedmergeSort = finishmergeSort - startmergeSort;
				std::cout << "Elapsed time: " << qselapsedmergeSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Quicksort\n";
				vector<int> vectorTestrandomqSort = readFile(randomNum, initialNum);

				auto startqSort = std::chrono::high_resolution_clock::now();
				quickSortObj.sort(vectorTestrandomqSort);
				auto finishqSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedqSort = finishqSort - startqSort;
				std::cout << "Elapsed time: " << qselapsedqSort.count() << " s\n";
				std::cout <<"\n";


				cout <<"After Radix Sort\n";

				vector<int> vectorTestrandomrSort = readFile(randomNum, initialNum);

				auto startrSort = std::chrono::high_resolution_clock::now();
				radixSortObj.sort(vectorTestrandomrSort);
				auto finishrSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedrSort = finishrSort - startrSort;
				std::cout << "Elapsed time: " << qselapsedrSort.count() << " s\n";
				std::cout <<"\n";

				cout <<"After Smooth Sort\n";
				 
				vector<int> vectorTestrandomsmoothsort = readFile(randomNum, initialNum);
				auto startsSort = std::chrono::high_resolution_clock::now();
				smoothSortObj.sort(vectorTestrandomsmoothsort);
				auto finishsSort = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> qselapsedsSort = finishsSort - startsSort;
				std::cout << "Elapsed time: " << qselapsedsSort.count() << " s\n";
        std::cout <<"\n";

				cout <<"After Counting Sort\n";

				vector<int> vectorTestrandomcSort = readFile(randomNum, initialNum);

				auto startcSort = std::chrono::high_resolution_clock::now();
				countingSortObj.sort(vectorTestrandomcSort);
				auto finishcSort = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> qselapsedcSort = finishcSort - startcSort;
				std::cout << "Elapsed time: " << qselapsedcSort.count() << " s\n";
				std::cout <<"\n";
			   
			/*********************************************************
				 vector<int> vectorTestdescendsmoothsort = readFile(descendingNum, initialNum);
				 auto start = std::chrono::high_resolution_clock::now();
				 smoothSortObj.sort(vectorTestdescendsmoothsort);
				 auto finish = std::chrono::high_resolution_clock::now();

				 std::chrono::duration<double> qselapsed = finish - start;
				 std::cout << "Elapsed time: " << qselapsed.count() << " s\n";

			************************************************************/
				initialNum = initialNum*2;
			 }	


				//return 0;
			
			} 
			else {
				
				cout <<"Invalid sort option selected.\n";
				sortType.push_back(argv[i]);
				showUsage(argv[0]);
				return 0;
			}
		}
		return 0;
	
	
}        
