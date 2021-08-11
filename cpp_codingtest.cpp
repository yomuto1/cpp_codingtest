#include <array>
#include <iostream>
#include <vector>
#include <forward_list>

struct citizen
{
	std::string name;
	int age;
};

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

static void print(const std::vector<int>& vec)
{
	for (int i_s32 = 0; i_s32 < vec.size(); i_s32++)
	{
		std::cout << vec[i_s32] << " ";
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const citizen& c)
{
	return (os << "[" << c.name << ", " << c.age << "]");
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

	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	print(vec);

	vec.push_back(1);

	print(vec);

	vec.push_back(2);

	print(vec);

	vec.insert(vec.begin(), 0);

	print(vec);

	vec.insert(find(vec.begin(), vec.end(), 1), 4);

	print(vec);

	vec.pop_back();

	print(vec);

	vec.erase(vec.begin());

	print(vec);

	vec.erase(vec.begin() + 1, vec.begin() + 4);

	print(vec);

	std::forward_list<citizen> citizens = { {"kim", 22}, {"lee", 25}, {"park", 18}, {"jin", 16} };

	citizens.sort([](const citizen& c1, const citizen& c2)
	{
		return c1.age > c2.age;
	});

	std::cout << "whole citizens: ";
	for (const auto& c : citizens)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	citizens.remove_if([](const citizen& c)
	{
		return (c.age < 19);
	});

	std::cout << "citizens that have vote: ";
	for (const auto& c : citizens)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	return 0;
}
