#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template <typename TYPE>
void bubblesortArray(TYPE arrayIn[], const int length)
{
	TYPE dTemp;

	if (length > 1)
	{
		for (int i = length-1; i > 0; i--)
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