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
#include "Others1.h"
#include "time.h"
#include <vector>
#include "Others2.h"
#include "Others3.h"

#ifndef speedtest__             
#define speedtest__   for (long blockTime = NULL; (blockTime == NULL ? (blockTime = clock()) != NULL : false); std::cout<< "\nTime: " << ((double) (clock() - blockTime) / CLOCKS_PER_SEC))
#endif
int main()
{
	//Couple of basics about cpp:
	//http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
	//http://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap#79936

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
	//arraysAndString::taskOneOnBuff();

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
	//Others::simpleTest();
	//const long long int size = 244444;
	//const long long int size = 9999999;
	/*const long long int size = 4;
	std::cout << size << std::endl;
	std::vector<int> arr(size);
	int *a = new int[size];
	for (int i = 0; i < size; ++i) {
		int val = rand() % 1000;
		arr[i] = (val);
		a[i] = val;
	}*/
	/*speedtest__
	{
		Others::task0_merge_vectors(arr, size);
	} std::cout << "\nMergeVectors-------------------" << std::endl;

	speedtest__
	{
		Others::task0_merge_arrays(a, size);
	} std::cout << "\nMergeArray-------------------" << std::endl;
	
	speedtest__
	{
		Others::task3a_merge_parity(arr);
	} std::cout << "\nMergeParityVector-------------------" << std::endl;
	
	speedtest__
	{
		Others::task3a_merge_parity_optimized(arr);
	} std::cout << "\nMergeParityVectorOptimized-------------------" << std::endl;

	speedtest__
	{
		Others::task3a_move(arr);
	} std::cout << "\nMove-------------------" << std::endl;

	speedtest__
	{
		Others::task3a_move_array(a, size);
	} std::cout << "\nMoveArray-------------------" << std::endl;

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

	speedtest__
	{
		Others::task3b_iter_return_array(a, size);
	} std::cout << "\nSwapRecursiveReturnArray-------------------" << std::endl;
	
	delete[] a;*/
	//Others::task3();
	//Others::task4a(a, size);
	//Others::task4b(a, size);
	//Others::task5();

	/*for (int i = 0; i < size; i += 2) {
		arr[i] = arr[i] * -1;
	}

	speedtest__
	{
	Others::task6a(arr);
	} std::cout << std::endl;	

	speedtest__
	{
		Others::task6b(arr);
	} std::cout << std::endl;*/

	// Others::task7();
	// Others::task8();
	
	//Others1::task1();
	//Others1::task1a();
	//Others1::task2();
	//Others1::task3();
	//Others1::task4();
	//Others1::task5();
	//Others1::task6();
	//Others1::task7();

	//Others2::task1();
	//Others2::task2();
	//Others2::task3();
	//Others2::task4();
	//Others2::task5();
	//Others2::task6();
	//Others2::task7();
	//Others2::task8();todo//tbd
	//Others2::task9();
	//Others2::task10();
	//Others2::task11();

	Others3::task1();
	int breakInt;
	std::cin >> breakInt;
    return 0;
}

