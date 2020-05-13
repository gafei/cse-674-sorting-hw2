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
place during each pass. 

It's best case time complexity is O(n) and worst case is O(n^2).

Insertion sort was referenced from the trifort material.

------------------------
Selection Sort
------------------------

Selection Sort is a sorting algorithm that divides an input list into 2 parts,
where, a sorted sublist is built from left to right at the front of the list
and the unsorted sublist is placed on the right of the list. This selection sort
will swap elements correctly into place. 

It's best case time complexity is O(n^2) and worst case is O(n^2).

Selection Sort was referenced from the trifort material.


------------------------
Bubble Sort
------------------------

The bubble sort is a sorting algorithm that will step through a list, compare
adjacent elements, and swap them into the correct order. 

It's best case time complexity is O(n) and worst case is O(n^2).

Bubble sort was referenced from the trifort material.



------------------------
Bubble Sort with Flag
------------------------

Bubble Sort with Flag is a variant of the bubble sort algorithm that contains
an additional flag to check whether the list of items has already been swapped.
If a swap hasn't occured then the list of items do not need to be sorted.

Bubble sort with flag was referenced from the trifort material.

It's best case time complexity is O(n) and worst case is O(n^2).


------------------------
Heap Sort
------------------------

The heapsort is a comparison based sorting algorithm. Heapsort will divide its
input into a sorted and unsorted region. It'll build the input into a heap
structure, then move the root element to the end, and then heapify.

It's best case time complexity is O(n log n) and worst case is O(n log n).

------------------------
Merge Sort
------------------------

Merge sort is a divide and conquer sorting algorithm. It'll first divide
the unsorted list into sublists to contain one element, then repeatedly merge
the the smaller sublists to make a larger sublist until only one remains.

It's best case time complexity is O(n log n) and worst case is O(n log n).

Merge sort code was referenced from:
https://nerohoop.gitbooks.io/cs-knowledge/sorting/merge-sort.html


------------------------
Quick Sort
------------------------

Quicksort is also a divide and conquer sorting algorithm. A pivot element 
starting at the end of the input list is selected, where elements smaller
then the pivot will be placed on a subarray to the left of the pivot, and 
the elements larger then the pivot will be placed on the subarray to the right.
Elements are moved with the help of a swap function that is called. 

It's best case time complexity is O(n log n) and worst case is O(n^2).

------------------------
Radix Sort
------------------------

Radix sort is an integer sorting algorithm that sorts data by grouping
individual digits in the same significant position and value. The basis
of the radix sort is the counting sort. It will take a list of integers,
in base 10 and sort them.

The radix sort algorithm was referenced from:

It's best case time complexity is O(n * k) and worst case is O(n * k).

------------------------
Smooth Sort
------------------------

Smooth sort, invented by Edsger Dijkstra, is based on heapsort. Initially,
the algorithm will obtain the input list into a Leonardo heap 
data structure, then extracts the largest element, which is positioned 
in the right most part of the heap.


The smooth sort algorithm was referenced from: 
https://github.com/mkrevuelta/Sorting/blob/master/src/smoothsort.c

It's best case time complexity is O(n) and worst case is O(n log n).


------------------------
Counting Sort
------------------------

Counting sort is a sorting technique based on the keys between a
specific range. It works by counting the number of number of objects having 
distinct key values. It'll find what the maximum element is, initialize a new
vector with max element +1  size, and then 0's it. This vector will be used to
store the count of elements.


The counting sort was referenced from the trifort material.

It's best case time complexity is O(n + k) and worst case is O(n + k).

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

