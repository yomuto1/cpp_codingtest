#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE (10)

static void transformArrayAB1(int* p_array_s32, const int size_s32);
static int getMedian(int* p_array_s32, const int size_s32);
static int getMax(int* p_array_s32, const int size_s32);
static int findMinDiff(int* p_array_s32, const int size_s32);
static void MissingValues(int* p_array_s32, const int size_s32);
static void removeDuplicates(int* p_array_s32, const int size_s32);
static int FirstRepeated(int* p_array_s32, const int size_s32);
static int linearSearchUnsorted(int* p_array_s32, const int size_s32, const int value_s32);
static void swap(int* p_array_s32, const int a_s32, const int b_s32);
static void QuickSortUtil(int* p_array_s32, int lower_s32, int upper_s32);
static void QuickSort(int* p_array_s32, const int size_s32);
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
    static int sa_inp_4_s32[SIZE];
    static int sa_inp_5_s32[SIZE];
    static int sa_inp_6_s32[SIZE];
    static int sa_inp_7_s32[SIZE];
    static int sa_inp_8_s32[SIZE];
    static int sa_inp_9_s32[SIZE];
    static int sa_inp_10_s32[SIZE];
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
    memcpy(sa_inp_4_s32, sa_inp_2_s32, SIZE * sizeof(int));
    sa_inp_5_s32[0] = 7;
    sa_inp_5_s32[1] = 1;
    sa_inp_5_s32[2] = 2;
    sa_inp_5_s32[3] = 2;
    sa_inp_5_s32[4] = 3;
    sa_inp_5_s32[5] = 4;
    sa_inp_5_s32[6] = 4;
    sa_inp_5_s32[7] = 4;
    sa_inp_5_s32[8] = 4;
    sa_inp_5_s32[9] = 6;
    memcpy(sa_inp_6_s32, sa_inp_5_s32, SIZE * sizeof(int));
    sa_inp_7_s32[0] = 8;
    sa_inp_7_s32[1] = 1;
    sa_inp_7_s32[2] = 11;
    sa_inp_7_s32[3] = 0;
    sa_inp_7_s32[4] = 12;
    sa_inp_7_s32[5] = 9;
    sa_inp_7_s32[6] = 5;
    sa_inp_7_s32[7] = 6;
    sa_inp_7_s32[8] = 4;
    sa_inp_7_s32[9] = 7;
    sa_inp_8_s32[0] = 1;
    sa_inp_8_s32[1] = 10;
    sa_inp_8_s32[2] = 15;
    sa_inp_8_s32[3] = 29;
    sa_inp_8_s32[4] = 77;
    sa_inp_8_s32[5] = 25;
    sa_inp_8_s32[6] = 50;
    sa_inp_8_s32[7] = 55;
    sa_inp_8_s32[8] = 100;
    sa_inp_8_s32[9] = 105;
    memcpy(sa_inp_9_s32, sa_inp_8_s32, SIZE * sizeof(int));
    memcpy(sa_inp_10_s32, sa_inp_8_s32, SIZE * sizeof(int));

    cout << "SumArray: " << SumArray(sa_inp_0_s32, SIZE) << "\n";
    cout << "SequentialSearch: " << SequentialSearch(sa_inp_0_s32, SIZE, 5) << "\n";
    cout << "BinarySearch: " << BinarySearch(sa_inp_0_s32, SIZE, 5) << "\n";
    cout << "MaxSubArraySum: " << MaxSubArraySum(sa_inp_1_s32, SIZE) << "\n";
    cout << "ArrayIndexMaxDiff: " << ArrayIndexMaxDiff(sa_inp_2_s32, SIZE) << "\n";
    BubbleSort(sa_inp_3_s32, SIZE);
    PrintArray(sa_inp_3_s32, SIZE);
    QuickSort(sa_inp_4_s32, SIZE);
    PrintArray(sa_inp_4_s32, SIZE);
    cout << "linearSearchUnsorted: " << linearSearchUnsorted(sa_inp_2_s32, SIZE, 5) << "\n";
    cout << "FirstRepeated: " << FirstRepeated(sa_inp_5_s32, SIZE) << "\n";
    removeDuplicates(sa_inp_6_s32, SIZE);
    PrintArray(sa_inp_6_s32, SIZE);
    MissingValues(sa_inp_7_s32, SIZE);
    cout << "findMinDiff: " << findMinDiff(sa_inp_8_s32, SIZE) << "\n";
    cout << "getMax: " << getMax(sa_inp_5_s32, SIZE) << "\n";
    cout << "getMedian: " << getMedian(sa_inp_9_s32, SIZE) << "\n";
    transformArrayAB1(sa_inp_10_s32, SIZE);
    PrintArray(sa_inp_10_s32, SIZE);
}

static void transformArrayAB1(int* p_array_s32, const int size_s32)
{
    int n_s32 = size_s32 / 2;
    int i_s32 = 0;
    int j_s32 = 0;

    for (i_s32 = 1; i_s32 < n_s32; i_s32++)
    {
        for (j_s32 = 0; j_s32 < i_s32; j_s32++)
        {
            swap(p_array_s32, n_s32 - i_s32 + (2 * j_s32), n_s32 - i_s32 + (2 * j_s32) + 1);
        }
    }
}

static int getMedian(int* p_array_s32, const int size_s32)
{
    QuickSort(p_array_s32, size_s32);

    return p_array_s32[size_s32 / 2];
}

static int getMax(int* p_array_s32, const int size_s32)
{
    int max_s32 = p_array_s32[0];
    int count_s32 = 1;
    int maxCount_s32 = 1;
    int i_s32 = 0;
    int j_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        count_s32 = 1;

        for (j_s32 = (i_s32 + 1); j_s32 < size_s32; j_s32++)
        {
            if (p_array_s32[i_s32] == p_array_s32[j_s32])
            {
                count_s32++;
            }
        }

        if (count_s32 > maxCount_s32)
        {
            max_s32 = p_array_s32[i_s32];
            maxCount_s32 = count_s32;
        }
    }

    return max_s32;
}

static int findMinDiff(int* p_array_s32, const int size_s32)
{
    int diff_s32 = INT_MAX;
    int i_s32 = 0;

    QuickSort(p_array_s32, size_s32);

    for (i_s32 = 0; i_s32 < (size_s32 - 1); i_s32++)
    {
        if (p_array_s32[i_s32 + 1] - p_array_s32[i_s32] < diff_s32)
        {
            diff_s32 = p_array_s32[i_s32 + 1] - p_array_s32[i_s32];
        }
    }

    return diff_s32;
}

static void MissingValues(int* p_array_s32, const int size_s32)
{
    int i_s32 = 0;
    int j_s32 = 0;
    int value_s32 = 0;
    int temp_s32 = 0;

    QuickSort(p_array_s32, size_s32);

    value_s32 = p_array_s32[0];

    for (i_s32 = 1; i_s32 < size_s32; i_s32++)
    {
        if (value_s32 == p_array_s32[i_s32])
        {
            // the same
        }
        else if ((value_s32 + 1) == p_array_s32[i_s32])
        {
            // sequential
            value_s32++;
        }
        else
        {
            // missing 2 or more
            temp_s32 = value_s32;
            for (j_s32 = temp_s32; j_s32 < (p_array_s32[i_s32] - 1); j_s32++)
            {
                value_s32++;
                printf("missing: %d\n", value_s32);
            }
            value_s32++;
        }
    }
}

static void removeDuplicates(int* p_array_s32, const int size_s32)
{
    int i_s32 = 0;
    int j_s32 = 0;

    QuickSort(p_array_s32, size_s32);

    for (i_s32 = 1; i_s32 < size_s32; i_s32++)
    {
        if (p_array_s32[i_s32] != p_array_s32[j_s32])
        {
            j_s32++;
            p_array_s32[j_s32] = p_array_s32[i_s32];
        }
    }
}

static int FirstRepeated(int* p_array_s32, const int size_s32)
{
    int i_s32 = 0;
    int j_s32 = 0;
    int ret_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        for (j_s32 = (i_s32 + 1); j_s32 < size_s32; j_s32++)
        {
            if (p_array_s32[i_s32] == p_array_s32[j_s32])
            {
                ret_s32 = p_array_s32[i_s32];

                break;
            }
        }
        if (0 != ret_s32)
        {
            break;
        }
    }

    return ret_s32;
}

static int linearSearchUnsorted(int* p_array_s32, const int size_s32, const int value_s32)
{
    int i_s32 = 0;
    int ret_s32 = 0;

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        if (value_s32 == p_array_s32[i_s32])
        {
            ret_s32 = 1;

            break;
        }
    }

    return ret_s32;
}

static void swap(int* p_array_s32, const int a_s32, const int b_s32)
{
    int temp_s32 = p_array_s32[a_s32];

    p_array_s32[a_s32] = p_array_s32[b_s32];
    p_array_s32[b_s32] = temp_s32;
}

static void QuickSortUtil(int* p_array_s32, int lower_s32, int upper_s32)
{
    int pivot_s32 = p_array_s32[lower_s32];
    int start_s32 = lower_s32;
    int stop_s32 = upper_s32;

    if (upper_s32 <= lower_s32)
    {
        return;
    }

    while (lower_s32 < upper_s32)
    {
        while (p_array_s32[lower_s32] <= pivot_s32)
        {
            lower_s32++;
        }
        while (p_array_s32[upper_s32] > pivot_s32)
        {
            upper_s32--;
        }
        if (lower_s32 < upper_s32)
        {
            swap(p_array_s32, upper_s32, lower_s32);
        }
    }

    swap(p_array_s32, upper_s32, start_s32);
    QuickSortUtil(p_array_s32, start_s32, upper_s32 - 1);
    QuickSortUtil(p_array_s32, upper_s32 + 1, stop_s32);
}

static void QuickSort(int* p_array_s32, const int size_s32)
{
    QuickSortUtil(p_array_s32, 0, size_s32 - 1);
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
