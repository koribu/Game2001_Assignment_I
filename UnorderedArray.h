#pragma once
#include "Array.h"
#include <cassert>
template<class T>
class UnorderedArray : public Array<T>
{
public:
	UnorderedArray(int size, int grow_by = 1)
		: Array<T>(size, grow_by)
	{

	}

	virtual void push(T searchKey)
	{
		assert(this->m_array != nullptr); // Debugging purposes

		if (this->m_numElements >= this->m_maxSize)	// Check if the array has to expand to accommodate the new data.
		{
			this->Expand();
		}

		// My array has space for a new value. Let's add it!
		this->m_array[this->m_numElements] = searchKey;
		this->m_numElements++;
	}
	virtual int search(T searchKey)
	{
		assert(this->m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == searchKey)
			{
				return i;	// Return the index of where the item is located in the array
			}
		}

		return -1;
	}
};