/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is a bubble sort algorithm. Used to sort arrays into
 * numerical order.
 *
 */


#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

 /**
  * This bubble function move data to the top
  *
  * @param arrayIn[] The array to be sorted.
  * @param size The length of the array.
  */
template <typename TYPE>
void bubblesortArray(TYPE arrayIn[], const int size)
{
	TYPE dTemp;

	if (size > 1)
	{
		for (int i = size -1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (arrayIn[j] > arrayIn[j+1])
				{
					dTemp = arrayIn[j + 1];
					arrayIn[j + 1] = arrayIn[j];
					arrayIn[j] = dTemp;
				}
			}
		}
	}
}

#endif