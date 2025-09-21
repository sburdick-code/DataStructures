/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is a insertion sort algorithm. Used to sort arrays into
 * numerical order.
 *
 */

#pragma once
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

 /**
  * Insertion Sort an array in numerical order.
  *
  * @param arrayIn[] The array to be sorted.
  * @param length The length of the array.
  */
template <typename TYPE>
void insertionSortArray(TYPE arrayIn[], const int length)
{
	TYPE dTemp;
	int iInsert;

	for (int i = 0; i < length; i++)
	{
		iInsert = i;
		while (iInsert > 0 && arrayIn[iInsert - 1] > arrayIn[iInsert])
		{
			// cout << "Swapping " << arrayIn[iInsert] << " for " << arrayIn[iInsert - 1] << endl;

			dTemp = arrayIn[iInsert];
			arrayIn[iInsert] = arrayIn[iInsert - 1];
			arrayIn[iInsert - 1] = dTemp;

			iInsert--;
		}

	}
}

#endif