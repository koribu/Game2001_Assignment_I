#include <iostream>
// #include "UnorderedArray.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"

using namespace std;

int main()
{
	OrderedArray<int> ordered_array(3,false);
	UnorderedArray<int> unOrdered_array(5, false);

	ordered_array.push(2);
	ordered_array.push(77);
	ordered_array.push(44);//<< reached to limit
	ordered_array.push(16);
	ordered_array.push(99);
	ordered_array.push(483);
	ordered_array.push(7);
	ordered_array.push(487);
	ordered_array[2] = 66;

	unOrdered_array.push(483);
	unOrdered_array.push(7);
	unOrdered_array.push(487);

	ordered_array.pop();
	ordered_array.remove(5);

	unOrdered_array.pop();
	unOrdered_array.remove(3);

	cout <<endl<<endl<< "Ordered array contents: ";

	for (int i = 0; i < ordered_array.GetSize(); i++)
	{
		cout << ordered_array[i] << " ";
	}

	cout << endl;

	cout << "Search for 66 was found at index: ";
	cout << ordered_array.search(66) << endl << endl;



	cout << "Unordered array contents: ";

	for (int i = 0; i < unOrdered_array.GetSize(); i++)
	{
		cout << unOrdered_array[i] << " ";
	}

	cout << endl;

	cout << "Search for 487 was found at index: ";
	cout << unOrdered_array.search(483);

	cout << endl << endl;

	return 0;
}