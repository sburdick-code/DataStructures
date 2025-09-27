/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program contains array searching functions. Used to find specific
 * data in an array.
 *
 */

#ifndef SEARCHES_H
#define SEARCHES_H

 /**
  * Linear search. Search for an element in an array by checking every value
  * until you find the target. Worst search O(n)
  *
  * @param arrayIn[] The array to be searched.
  * @param size The length of the array.
  * @param target The value you are searching for.
  * 
  * @return Returns the index of the target if found. -1 if not found.
  */
template <typename TYPE>
int linearSearch(const TYPE arrayIn[], const int size, const TYPE target)
{
	for (int i = 0; i < size; i++)
	{
		if (arrayIn[i] == target)
			return i;
	}

	return -1;
}

/**
 * Binary search. Search for an element in an ordered array by checking the 
 * middle value, halving the list, then checking the value in the middle of 
 * the list. Do this until one value is left.
 *
 * @param arrayIn[] The array to be searched.
 * @param size The length of the array.
 * @param target The value you are searching for.
 *
 * @return Returns the index of the target if found. -1 if not found.
 */
template <typename TYPE>
int binarySearch(const TYPE arrayIn[], const int size, const TYPE target)
{
	int iLow = 0;
	int iHigh = size;

	while (iLow + 1 < iHigh)
	{
		int iCheck = (iLow + iHigh) / 2;

		if (arrayIn[iCheck] > target)
			iHigh = iCheck;
		else
			iLow = iCheck;
	}

	if (arrayIn[iLow] == target)
		return iLow;
	else
		return -1;
}

#endif