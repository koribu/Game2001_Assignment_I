#pragma once
#include "Array.h"

template <class T >
class OrderedArray : public Array<T>
{
public:
	OrderedArray(int size, int grow_by)
		: Array<T>(size, grow_by)
	{
	}

	void push(T val) override
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;	// i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into the array at index
		m_array[i] = val;

		m_numElements++;

		// return i;
	}
	int search(T val) override
	{
		assert(m_array != nullptr);

		// Helper variables.
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)	// <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1;	// Preview of bitwise operatrions. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for.
			if (m_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			// Step 3: Check which half of the array the value is in.
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1;	// Value may be in the upper half
				}
				else
				{
					upperBound = current - 1;	// Value may be in the lower half
				}
			}
		}

		return -1;	// Catch all return from danger.

	}
};