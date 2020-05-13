Gafei Szeto
CSE 674 - Data Structures and Algorithms
Homework 2
May 11th, 2020

------------
Description
------------

In this homework, we're asked to implement multiple sorting algorithms and run a benchmark test.
The program will first generate 128,000 ascending, descending and random 
numbers to a textfile. Then, it'll step through each sorting algorithm 
starting initially at 1000 numbers and then doubling until 128,000 numbers is reached. 

The user will specify which group of generated numbers to sort, either the ascending, 
descending or random numbers. 

For example, the program will sort 1000 ascending, descending or random 
numbers for each of the sorting algorithms listed below, then 2000 ascending, 
descending or random numbers, 4000 ascending, descending or random numbers, 8000 ascending, 
descending or random numbers...etc, until 128,000 numbers are sorted for each algorithm.


Program usage is as follows:

Usage: main [OPTIONS]
Options:
	-h, --help		    Show this help message
	-a, --ascending		Specify sort with ascending.txt
	-d, --descending	Specify sort with descending.txt
	-r, --random 		Specify sort with random.txt


ex: "main -a" or "main --ascending" to sort with numbers from the ascending.txt file.
ex: "main -d" or "main --descending" to sort with numbers from the descending.txt file.
ex: "main -r" or "main --random" to sort with numbers from the random.txt file.


------------------------
Insertion Sort
------------------------

Insertion Sort is a sorting algorithm that places the input element at the correct 
place during each pass. It's worst case is O(n^2).

------------------------
Selection Sort
------------------------

Selection Sort is a sorting algorithm that 


------------------------
Bubble Sort
------------------------




------------------------
Bubble Sort with Flag
------------------------

------------------------
Heap Sort
------------------------

------------------------
Merge Sort
------------------------


------------------------
Quick Sort
------------------------


------------------------
Radix Sort
------------------------

------------------------
Smooth Sort
------------------------

The smooth sort algorithm was referenced from: 
https://github.com/mkrevuelta/Sorting/blob/master/src/smoothsort.c


------------------------
Counting Sort
------------------------


---------------------------
Number Generation
---------------------------

There are three functions to generate data. There is the genDataAscend(int elements) 
function, the genDataDescend() function, and the genDataRandom() function. 

The genDataAscend(int elements) function generates 10 numbers per line, seperated
by a '-', until "elements" is reached in ascending order. 
These numbers are generated and pushed back to a vector and then returned in a vector.

The genDataDescend(int elements) function generates 10 numbers per line, seperated
by a '-', until "elements" is reached in descending order. 
These numbers are generated and pushed back to a vector and then returned in a vector.

The genDataRandom(int elements) function generates 10 numbers per line, seperated
by a '-', until "elements" is reached in ascending order. 
These numbers are generated in ascending order, pushed back to a vector, 
and then shuffled randomly to be returned in a vector.


---------------------------
Read Numbers From File
---------------------------

In the readFile(enum sortType fileType, int elementsToRead) function,
an inputFile stream is defined to read from the designated file. The
inputFile stream will read each number in the designated file, push 
the number into a vector or until the 'elementsToRead' number is 
reached.

An enum called sortType is created to help select either the ascending,
descending, or random generated numbers file to read from. 

The enum is passed into a switch statement along with the amount of elements
to read from. 

For example, to read from the "ascending.txt" file, you would call:
vector<int> vector = readFile(ascendingNum, initialNum), 
where 'initalNum' is the amount of numbers you want to read from the file, 
and 'vector' is the amount of numbers returned to you.

This returned vector is then passed into a sorting algorithm.


To generate 100 distict numbers generation, I revised a solution proposed in this stackoverflow post:
https://stackoverflow.com/questions/36922371/generate-different-random-numbers

The genDataS2() function modifies the above post and pushes 1-100 to the vector. 
Once in that vector, a seed is utilized to select 100 numbers to be shuffled and 
inserted into the single or doubly linked list using the insertFirst() function. 

