#include <iostream>
// #include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;

int main()
{
	OrderedArray<int> ordered_array(3);

	ordered_array.push(3);
	ordered_array.push(53);
	ordered_array.push(83);
	ordered_array.push(23); // <-- Should expand here			// 3 23 82 
	ordered_array.push(82); // <-- Should expand here

	ordered_array[2] = 112;

	ordered_array.pop();
	ordered_array.remove(2);

	cout << "Ordered array contents: ";

	for (int i = 0; i < ordered_array.GetSize(); i++)
	{
		cout << ordered_array[i] << " ";
	}

	cout << endl;

	cout << "Search for 23 was found at index: ";
	cout << ordered_array.search(23);

	cout << endl << endl;

	return 0;
}