/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is a quick sort algorithm. Used to sort arrays into
 * numerical order.
 *
 */

#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <ctime>

 /**
  * This partition function is a recursive function that calls itself to
  * continually shorten the length it has to sort.
  *
  * @param arrayIn[] The array to be sorted.
  * @param size The length of the array.
  */
template <typename TYPE>
void partition(TYPE arrayIn[], const int size)
{
	if (size < 2)
		return;

	TYPE pivot = arrayIn[(rand() % size)];
	int iLower = 0;
	int iUpper = size - 1;

	while (iLower < iUpper)
	{
		while (arrayIn[iLower] < pivot)
			++iLower;
		while (arrayIn[iUpper] > pivot)
			--iUpper;

		TYPE temp = arrayIn[iLower];
		arrayIn[iLower] = arrayIn[iUpper];
		arrayIn[iUpper] = temp;
	}

	partition(arrayIn, iLower);
	partition(&(arrayIn[iLower + 1]), size - iLower - 1);
}

 /**
  * Quick Sort an array in numerical order.
  *
  * @param arrayIn[] The array to be sorted.
  * @param size The length of the array.
  */
template <typename TYPE>
void quickSort(TYPE arrayIn[], const int size)
{
	srand((unsigned int)time(0));
	partition(arrayIn, size);
}

#endif