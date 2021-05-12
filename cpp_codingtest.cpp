#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE (10)

static void PrintArray(const int* p_array_s32, const int size_s32);
static void BubbleSort(int* p_array_s32, const int size_s32);
static int ArrayIndexMaxDiff(const int* p_array_s32, const int size_s32);
static int MaxSubArraySum(const int* p_array_s32, const int size_s32);
static int BinarySearch(const int* p_array_s32, const int size_s32, const int value_s32);
static int SequentialSearch(const int* p_array_s32, const int size_s32, const int value_s32);
static int SumArray(const int* p_array_s32, const int size_s32);

int main()
{
    static int sa_inp_0_s32[SIZE];
    static int sa_inp_1_s32[SIZE];
    static int sa_inp_2_s32[SIZE];
    static int sa_inp_3_s32[SIZE];
    int i_s32 = 0;

    for (i_s32 = 0; i_s32 < SIZE; i_s32++)
    {
        sa_inp_0_s32[i_s32] = i_s32;
    }
    for (i_s32 = 0; i_s32 < SIZE; i_s32++)
    {
        sa_inp_1_s32[i_s32] = i_s32 - 5;
    }
    sa_inp_2_s32[0] = 7;
    sa_inp_2_s32[1] = 1;
    sa_inp_2_s32[2] = 9;
    sa_inp_2_s32[3] = 0;
    sa_inp_2_s32[4] = 8;
    sa_inp_2_s32[5] = 2;
    sa_inp_2_s32[6] = 5;
    sa_inp_2_s32[7] = 3;
    sa_inp_2_s32[8] = 4;
    sa_inp_2_s32[9] = 6;
    memcpy(sa_inp_3_s32, sa_inp_2_s32, SIZE * sizeof(int));

    cout << "SumArray: " << SumArray(sa_inp_0_s32, SIZE) << "\n";
    cout << "SequentialSearch: " << SequentialSearch(sa_inp_0_s32, SIZE, 5) << "\n";
    cout << "BinarySearch: " << BinarySearch(sa_inp_0_s32, SIZE, 5) << "\n";
    cout << "MaxSubArraySum: " << MaxSubArraySum(sa_inp_1_s32, SIZE) << "\n";
    cout << "ArrayIndexMaxDiff: " << ArrayIndexMaxDiff(sa_inp_2_s32, SIZE) << "\n";
    BubbleSort(sa_inp_3_s32, SIZE);
    PrintArray(sa_inp_3_s32, SIZE);
}

static void PrintArray(const int* p_array_s32, const int size_s32)
{
    int i_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        cout << p_array_s32[i_s32] << ", ";
    }
    cout << "\n";
}

static void BubbleSort(int* p_array_s32, const int size_s32)
{
    int i_s32 = 0;
    int j_s32 = 0;
    int temp_s32 = 0;

    for (i_s32 = 0; i_s32 < (size_s32 - 1); i_s32++)
    {
        for (j_s32 = 0; j_s32 < (size_s32 - i_s32 - 1); j_s32++)
        {
            if (p_array_s32[j_s32] > (p_array_s32[j_s32 + 1]))
            {
                temp_s32 = p_array_s32[j_s32];
                p_array_s32[j_s32] = p_array_s32[j_s32 + 1];
                p_array_s32[j_s32 + 1] = temp_s32;
            }
        }
    }
}

static int ArrayIndexMaxDiff(const int* p_array_s32, const int size_s32)
{
    int maxDiff_s32 = -1;
    int i_s32 = 0;
    int j_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        j_s32 = size_s32 - 1;

        while (j_s32 > i_s32)
        {
            if (p_array_s32[j_s32] > p_array_s32[i_s32])
            {
                maxDiff_s32 = max(maxDiff_s32, j_s32 - 1);
                break;
            }
            j_s32 -= 1;
        }
    }

    return maxDiff_s32;
}

static int MaxSubArraySum(const int* p_array_s32, const int size_s32)
{
    int maxSoFar_s32 = INT_MIN;
    int maxEndingHere_s32 = 0;
    int i_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        maxEndingHere_s32 += p_array_s32[i_s32];
        if (maxSoFar_s32 < maxEndingHere_s32)
        {
            maxSoFar_s32 = maxEndingHere_s32;
        }
    }

    return maxSoFar_s32;
}

static int BinarySearch(const int* p_array_s32, const int size_s32, const int value_s32)
{
    int low_s32 = 0;
    int mid_s32 = 0;
    int high_s32 = size_s32 - 1;
    int ret_s32 = -1;

    while (low_s32 <= high_s32)
    {
        mid_s32 = low_s32 + (high_s32 - low_s32) / 2;
        if (value_s32 == p_array_s32[mid_s32])
        {
            ret_s32 = mid_s32;
            break;
        }
        else if (value_s32 > p_array_s32[mid_s32])
        {
            low_s32 = mid_s32 + 1;
        }
        else
        {
            high_s32 = mid_s32 - 1;
        }
    }

    return ret_s32;
}

static int SequentialSearch(const int* p_array_s32, const int size_s32, const int value_s32)
{
    int i_s32 = 0;
    int ret_s32 = -1;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        if (value_s32 == p_array_s32[i_s32])
        {
            ret_s32 = i_s32;
            break;
        }
    }

    return ret_s32;
}

static int SumArray(const int* p_array_s32, const int size_s32)
{
    int total_s32 = 0;
    int i_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        total_s32 += *p_array_s32++;
    }

    return total_s32;
}
