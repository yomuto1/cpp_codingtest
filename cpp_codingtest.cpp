﻿#include <array>
#include <iostream>

template <size_t N>
static void print(const std::array<int, N>& arr)
{
#if 0
	for (auto ele : arr)
	{
		std::cout << ele << ", ";
	}
#else
	for (auto i = arr.begin(); i != arr.end(); i++)
	{
		auto element = (*i);
		std::cout << element << ", ";
	}
#endif

	std::cout << std::endl;
}

int main(void)
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

	std::array<int, 4> arr3 = { 2, 4, 6, 7 };

	try
	{
		std::cout << arr3.at(3) << std::endl;
		std::cout << arr3.at(4) << std::endl;
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	std::array<int, 5> arr4 = { 2, 4, 6, 7, 5 };

	print(arr4);

	std::cout << arr4.front() << std::endl;
	std::cout << arr4.back() << std::endl;
	std::cout << *(arr4.data() + 1) << std::endl;

	return 0;
}
