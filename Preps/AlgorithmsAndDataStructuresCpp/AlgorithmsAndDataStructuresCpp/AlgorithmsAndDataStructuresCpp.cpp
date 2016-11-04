// AlgorithmsAndDataStructuresCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArraysAndStrings.h"
#include "LinkedLists.h"
#include "BitsManipulation.h"
#include <iostream>
#include "StackAndQueues.h"
#include "GraphsAndTrees.h"
#include "Moderate.h"
#include "Others.h"
#include "time.h"
#include <vector>


#ifndef speedtest__             
#define speedtest__   for (long blockTime = NULL; (blockTime == NULL ? (blockTime = clock()) != NULL : false); std::cout<< "\nTime: " << ((double) (clock() - blockTime) / CLOCKS_PER_SEC))
#endif
int main()
{
	//----------Arrays and strings----------
	//Maps
	//arraysAndString::mapExample();
	//arraysAndString::unorderedMapExample();
	//arraysAndString::multimapExample();
	
	//Sets
	//setExample();
	//unorderedSetExample();

	//arrayListExample();
	//stringBuilderExample();

	//taskOne();
	//taskOneOnBuff();

	//char a[] = "abcde12345";
	//taskTwo(a);

	//taskThree();
	//taskFour();
	//taskFive();

	// std::cout << sizeof(int); // 4 BYTES

	//taskSix();
	//taskSeven();
	//taskEight();

	//----------Linked Lists----------
	//linkedLists::test1();
	//linkedLists::taskTwo();
	//linkedLists::taskTwoRecursive();
	//linkedLists::taskThree();
	//linkedLists::taskFour();
	//linkedLists::taskFive();
	//linkedLists::taskSix();
	//linkedLists::taskSeven();

	//------------------Stacks and Queues------------------
	//stackAndQueues::test();
	//stackAndQueues::taskOne();
	//stackAndQueues::taskTwo();
	//stackAndQueues::taskThree();
	//stackAndQueues::taskFour();
	//stackAndQueues::taskFive();
	//stackAndQueues::taskSix();
	//stackAndQueues::taskSeven();

	//------------------Graphs and trees---------------------
	//graphsAndTrees::test();
	//graphsAndTrees::taskOne();
	//graphsAndTrees::taskTwo();
	//graphsAndTrees::taskThree();
	//graphsAndTrees::taskFour();
	//graphsAndTrees::taskFive();
	//graphsAndTrees::taskSix();
	//graphsAndTrees::taskSeven();
	//*dototodo*graphsAndTrees::taskEight();

	//----------Bit manipulations------
	//bitManipulation::test();

	//-------------Moderate------------------
	//moderate::taskOne();
	//Break

	//------------------Others------------------
	//Others::task1();
	//Others::task2();
	//Others::task3();
	const int size = 166666;
	std::vector<int> arr;
	int a[size];
	for (int i = 0; i < size; ++i) {
		int val = rand() % 1000;
		arr.push_back(val);
		a[i] = val;
	}

	//Others::simpleTest();

	speedtest__
	{
		Others::task0_merge_vectors(arr, size);
	} std::cout << "\nMergeVectors-------------------" << std::endl;

	speedtest__
	{
		Others::task0_merge_arrays(a, size);
	} std::cout << "\nMergeArray-------------------" << std::endl;

	speedtest__
	{
		//TO CHECK
		Others::task0_merge_optimized_vectors(arr);
	} std::cout << "\nMergeOptimizedVectors-------------------" << std::endl;

	speedtest__
	{
		Others::task3a_merge_parity(arr);
	} std::cout << "\nMergeParityVector-------------------" << std::endl;

	speedtest__
	{
		Others::task3a_move(arr);
	} std::cout << "\nMove-------------------" << std::endl;


	speedtest__
	{
		Others::task3b_recursive_ref(arr);
	} std::cout << "\nSwapRecursiveReference-------------------" << std::endl;

	speedtest__
	{
		Others::task3b_iter_ref(arr);
	} std::cout << "\nSwapIterReference-------------------" << std::endl;

	speedtest__
	{
		Others::task3b_recursive_return(arr);
	} std::cout << "\nSwapRecursiveReturn-------------------" << std::endl;

	speedtest__
	{
		Others::task3b_iter_return(arr);
	} std::cout << "\nSwapRecursiveReturn-------------------" << std::endl;



	int breakInt;
	std::cin >> breakInt;
    return 0;
}

