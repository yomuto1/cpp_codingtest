#include <array>
#include <iostream>

int main()
{
	std::array<int, 10> arr1;

	arr1[0] = 1;
	std::cout << "1st element in arr1: " << arr1[0] << std::endl;

	std::array<int, 4> arr2 = { 1, 2, 3, 4 };

	std::cout << "every element in arr2: ";

	for (int i_s32 = 0; i_s32 < arr2.size(); i_s32++)
	{
		std::cout << arr2[i_s32] << " ";
	}

	std::cout << std::endl;

	return 0;
}
