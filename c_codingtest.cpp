#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE (10)
#define MAX_CAPACITY (1024)
#define ERROR_VALUE (INT_MIN)
#define EMPTY_NODE (-1)
#define DELETED_NODE (-2)
#define FILLED_NODE (-3)

typedef struct graph
{
    int count_s32;
    int** p_adj;
} Graph;
typedef struct hashTable_t
{
    int size_s32;
    int* p_array_s32;
    char* p_flag_s8;
} HashTable;
typedef struct tNode
{
    int value_s32;
    struct tNode* pst_lChild;
    struct tNode* pst_rChild;
} treeNode;
typedef struct Queue_t
{
    int front_s32;
    int back_s32;
    int size_s32;
    int a_data_s32[MAX_CAPACITY];
} Queue;
typedef struct stack
{
    int top_s32;
    int a_data_s32[MAX_CAPACITY];
} Stack;
typedef struct Node
{
    int value_s32;
    struct Node* pst_next;
} ListNode;

static void reverseString(char* p_a, int lower_s32, int upper_s32);
static void reverseWords(char* p_a);
static int BruteForceSearch(const char* p_text, const char* p_pattern);
static void graphInit(Graph* pst_graph, const int count_s32);
static void addDirectedEdge(Graph* pst_graph, const int src_s32, const int dst_s32, const int cost_s32);
static void addUndirectedEdge(Graph* pst_graph, const int src_s32, const int dst_s32, const int cost_s32);
static void graphPrint(Graph* pst_graph);
static unsigned int Hash(const int key_s32, const int size_s32);
static int CollisionFunction(const int i_s32);
static void HashInit(HashTable* pst_hTable, const int size_s32);
static int HashAdd(HashTable* pst_hTable, const int value_s32);
static int HashFind(HashTable* pst_hTable, const int value_s32);
static int HashRemove(HashTable* pst_hTable, const int value_s32);
static void HashPrint(HashTable* pst_hTable);
static treeNode* freeTree(treeNode* pst_root);
static void printPreOrder(treeNode* pst_root);
static treeNode* levelOrderBinaryTreeUtil(int* p_array_s32, const int size_s32, int start_s32);
static treeNode* levelOrderBinaryTree(int* p_array_s32, const int size_s32);
static void maxSlidingWindows(int* p_array_s32, const int size_s32, int window_s32);
static void QueueInitialize(Queue* pst_que);
static void QueueAdd(Queue* pst_que, int value_s32);
static int QueueRemove(Queue* pst_que);
static int QueueFront(Queue* pst_que);
static int QueueBack(Queue* pst_que);
static int QueueRemoveBack(Queue* pst_que);
static int QueueIsEmpty(Queue* pst_que);
static int QueueSize(Queue* pst_que);
static void StackInitialize(Stack* pst_stk);
static int StackEmpty(Stack* pst_stk);
static int StackSize(Stack* pst_stk);
static void StackPrint(Stack* pst_stk);
static void StackPush(Stack* pst_stk, int value_s32);
static int StackPop(Stack* pst_stk);
static int StackTop(Stack* pst_stk);
static void deleteList(ListNode** pst_head);
static void deleteNodes(ListNode** pst_head, int delValue_s32);
static void deleteFirstNodes(ListNode** pst_head);
static void searchList(ListNode* pst_head, int value_s32);
static void printList(ListNode* pst_head);
static int insertNode(ListNode** pst_head, int value_s32);
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
    static int sa_inp_11_s32[SIZE];
    static int sa_inp_12_s32[SIZE];
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
    memcpy(sa_inp_11_s32, sa_inp_8_s32, SIZE * sizeof(int));
    memcpy(sa_inp_12_s32, sa_inp_2_s32, SIZE * sizeof(int));

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

    ListNode* pst_head = (ListNode*)malloc(sizeof(ListNode));
    pst_head->value_s32 = 0;
    ListNode* pst_node0 = (ListNode*)malloc(sizeof(ListNode));
    pst_head->pst_next = pst_node0;
    pst_node0->value_s32 = 1;
    ListNode* pst_node1 = (ListNode*)malloc(sizeof(ListNode));
    pst_node0->pst_next = pst_node1;
    pst_node1->value_s32 = 2;
    ListNode* pst_node2 = (ListNode*)malloc(sizeof(ListNode));
    pst_node1->pst_next = pst_node2;
    pst_node2->value_s32 = 4;
    pst_node2->pst_next = NULL;
    cout << "insertNode: " << insertNode(&pst_head, 3) << "\n";
    printList(pst_head);
    searchList(pst_head, 4);
    deleteFirstNodes(&pst_head);
    deleteNodes(&pst_head, 4);
    deleteList(&pst_head);

    Stack st_stk;

    StackInitialize(&st_stk);
    StackPush(&st_stk, 1);
    StackPush(&st_stk, 2);
    StackPush(&st_stk, 4);
    StackPush(&st_stk, 5);
    StackPush(&st_stk, 7);
    StackPrint(&st_stk);

    maxSlidingWindows(sa_inp_11_s32, SIZE, 3);

    cout << "\nTree\n";

    treeNode* pst_t = levelOrderBinaryTree(sa_inp_12_s32, SIZE);
    printPreOrder(pst_t);

    freeTree(pst_t);

    cout << "\nHash\n";

    HashTable st_myTable;

    HashInit(&st_myTable, 10);
    HashAdd(&st_myTable, 89);
    HashAdd(&st_myTable, 89);
    HashAdd(&st_myTable, 18);
    HashAdd(&st_myTable, 49);
    HashAdd(&st_myTable, 58);
    HashAdd(&st_myTable, 69);
    HashPrint(&st_myTable);
    HashRemove(&st_myTable, 89);
    HashRemove(&st_myTable, 89);
    HashPrint(&st_myTable);
    printf("Find 89: %d\n", HashFind(&st_myTable, 89));
    printf("Find 18: %d\n", HashFind(&st_myTable, 18));

#if 0
    cout << "\nGraph\n";

    Graph st_graph;

    graphInit(&st_graph, 4);
    addUndirectedEdge(&st_graph, 0, 1, 1);
    addUndirectedEdge(&st_graph, 0, 2, 1);
    addUndirectedEdge(&st_graph, 1, 2, 1);
    addUndirectedEdge(&st_graph, 2, 3, 1);
    graphPrint(&st_graph);
#endif

    cout << "\ncharacter search\n";

    const char* p_text = "this is a program in C";
    const char* p_pattern = "program";

    printf("%d\n", BruteForceSearch(p_text, p_pattern));

    char a_ch[100] = "Hello, World!";

    reverseString(a_ch, 0, 12);
    printf("%s\n", a_ch);
    reverseWords(a_ch);
    printf("%s\n", a_ch);
}

static void reverseString(char* p_a, int lower_s32, int upper_s32)
{
    char tempChar = 0;

    while (lower_s32 < upper_s32)
    {
        tempChar = p_a[lower_s32];
        p_a[lower_s32] = p_a[upper_s32];
        p_a[upper_s32] = tempChar;
        lower_s32++;
        upper_s32--;
    }
}

static void reverseWords(char* p_a)
{
    const int length_s32 = strlen(p_a);
    int lower_s32 = 0;
    int upper_s32 = -1;
    int i_s32 = 0;

    for (i_s32 = 0; i_s32 <= length_s32; i_s32++)
    {
        if ((' ' == p_a[i_s32]) || ('\0' == p_a[i_s32]))
        {
            reverseString(p_a, lower_s32, upper_s32);
            lower_s32 = i_s32 + 1;
            upper_s32 = i_s32;
        }
        else
        {
            upper_s32++;
        }
    }

    reverseString(p_a, 0, length_s32 - 1);
}

static int BruteForceSearch(const char* p_text, const char* p_pattern)
{
    const int n_s32 = strlen(p_text);
    const int m_s32 = strlen(p_pattern);
    int i_s32 = 0;
    int j_s32 = 0;

    for (i_s32 = 0; i_s32 <= (n_s32 - m_s32); i_s32++)
    {
        for (j_s32 = 0; j_s32 < m_s32; j_s32++)
        {
            if (p_pattern[j_s32] != p_text[i_s32 + j_s32])
            {
                break;
            }
        }

        if (j_s32 == m_s32)
        {
            return i_s32;
        }
    }

    return -1;
}

static void graphInit(Graph* pst_graph, const int count_s32)
{
    int i_s32 = 0;

    pst_graph->count_s32 = count_s32;
    pst_graph->p_adj = (int**)malloc(count_s32 * sizeof(int*));

    for (i_s32 = 0; i_s32 < count_s32; i_s32++)
    {
        pst_graph->p_adj[i_s32] = (int*)malloc(count_s32 * sizeof(int));
        memset(pst_graph->p_adj[i_s32], 0, count_s32 * sizeof(int));
    }
}

static void addDirectedEdge(Graph* pst_graph, const int src_s32, const int dst_s32, const int cost_s32)
{
    pst_graph->p_adj[src_s32][dst_s32] = cost_s32;
}

static void addUndirectedEdge(Graph* pst_graph, const int src_s32, const int dst_s32, const int cost_s32)
{
    addDirectedEdge(pst_graph, src_s32, dst_s32, cost_s32);
    addDirectedEdge(pst_graph, dst_s32, src_s32, cost_s32);
}

static void graphPrint(Graph* pst_graph)
{
    int count_s32 = pst_graph->count_s32;
    int i_s32 = 0;
    int j_s32 = 0;

    for (i_s32 = 0; i_s32 < count_s32; i_s32++)
    {
        for (j_s32 = 0; j_s32 < count_s32; j_s32++)
        {
            printf("%d ", pst_graph->p_adj[i_s32][j_s32]);
        }
        printf("\n");
    }
}

static unsigned int Hash(const int key_s32, const int size_s32)
{
    const unsigned int hashValue_s32 = key_s32;

    return hashValue_s32 % size_s32;
}

static int CollisionFunction(const int i_s32)
{
    return i_s32 * i_s32;
}

static void HashInit(HashTable* pst_hTable, const int size_s32)
{
    int i_s32 = 0;

    pst_hTable->size_s32 = size_s32;
    pst_hTable->p_array_s32 = (int*)malloc(pst_hTable->size_s32 * sizeof(int));
    pst_hTable->p_flag_s8 = (char*)malloc(pst_hTable->size_s32 * sizeof(char));

    for (i_s32 = 0; i_s32 < pst_hTable->size_s32; i_s32++)
    {
        pst_hTable->p_flag_s8[i_s32] = EMPTY_NODE;
    }
}

static int HashAdd(HashTable* pst_hTable, const int value_s32)
{
    int hashValue_s32 = Hash(value_s32, pst_hTable->size_s32);
    int i_s32 = 0;
    int ret_s32 = 0;

    for (i_s32 = 0; i_s32 < pst_hTable->size_s32; i_s32++)
    {
        if ((EMPTY_NODE == pst_hTable->p_flag_s8[hashValue_s32]) || (DELETED_NODE == pst_hTable->p_flag_s8[hashValue_s32]))
        {
            pst_hTable->p_array_s32[hashValue_s32] = value_s32;
            pst_hTable->p_flag_s8[hashValue_s32] = FILLED_NODE;
            break;
        }

        hashValue_s32 += CollisionFunction(i_s32);
        hashValue_s32 = hashValue_s32 % pst_hTable->size_s32;
    }

    if ((FILLED_NODE == pst_hTable->p_flag_s8[hashValue_s32]) && (value_s32 == pst_hTable->p_array_s32[hashValue_s32]))
    {
        ret_s32 = 1;
    }
    else
    {
        ret_s32 = 0;
    }

    return ret_s32;
}

static int HashFind(HashTable* pst_hTable, const int value_s32)
{
    int hashValue_s32 = Hash(value_s32, pst_hTable->size_s32);
    int i_s32 = 0;
    int ret_s32 = 0;

    for (i_s32 = 0; i_s32 < pst_hTable->size_s32; i_s32++)
    {
        if (((pst_hTable->p_flag_s8[hashValue_s32] == FILLED_NODE) && (pst_hTable->p_array_s32[hashValue_s32] == value_s32)) || (pst_hTable->p_flag_s8[hashValue_s32] == EMPTY_NODE))
        {
            break;
        }

        hashValue_s32 += CollisionFunction(i_s32);
        hashValue_s32 = hashValue_s32 % pst_hTable->size_s32;
    }

    if ((pst_hTable->p_flag_s8[hashValue_s32] == FILLED_NODE) && (pst_hTable->p_array_s32[hashValue_s32] == value_s32))
    {
        ret_s32 = 1;
    }

    return ret_s32;
}

static int HashRemove(HashTable* pst_hTable, const int value_s32)
{
    int hashValue_s32 = Hash(value_s32, pst_hTable->size_s32);
    int i_s32 = 0;
    int ret_s32 = 0;

    for (i_s32 = 0; i_s32 < pst_hTable->size_s32; i_s32++)
    {
        if (((pst_hTable->p_flag_s8[hashValue_s32] == FILLED_NODE) && (pst_hTable->p_array_s32[hashValue_s32] == value_s32)) || (pst_hTable->p_flag_s8[hashValue_s32] == EMPTY_NODE))
        {
            break;
        }

        hashValue_s32 += CollisionFunction(i_s32);
        hashValue_s32 = hashValue_s32 % pst_hTable->size_s32;
    }

    if ((pst_hTable->p_flag_s8[hashValue_s32] == FILLED_NODE) && (pst_hTable->p_array_s32[hashValue_s32] == value_s32))
    {
        pst_hTable->p_flag_s8[hashValue_s32] = DELETED_NODE;
        ret_s32 = 1;
    }

    return ret_s32;
}

static void HashPrint(HashTable* pst_hTable)
{
    int i_s32 = 0;

    for (i_s32 = 0; i_s32 < pst_hTable->size_s32; i_s32++)
    {
        if (pst_hTable->p_flag_s8[i_s32] == FILLED_NODE)
        {
            printf("%d ", pst_hTable->p_array_s32[i_s32]);
        }
    }
    printf("\n");
}

static treeNode* freeTree(treeNode* pst_root)
{
    if (NULL != pst_root)
    {
        pst_root->pst_lChild = freeTree(pst_root->pst_lChild);
        pst_root->pst_rChild = freeTree(pst_root->pst_rChild);
        if ((NULL == pst_root->pst_lChild) && (NULL == pst_root->pst_rChild))
        {
            free(pst_root);
            return NULL;
        }
    }

    return NULL;
}

static void printPreOrder(treeNode* pst_root)
{
    if (NULL != pst_root)
    {
        printf(" %d ", pst_root->value_s32);
        printPreOrder(pst_root->pst_lChild);
        printPreOrder(pst_root->pst_rChild);
    }
}

static treeNode* levelOrderBinaryTreeUtil(int* p_array_s32, const int size_s32, int start_s32)
{
    treeNode* pst_curr = (treeNode*)malloc(sizeof(treeNode));
    int left_s32 = (2 * start_s32) + 1;
    int right_s32 = (2 * start_s32) + 2;

    pst_curr->value_s32 = p_array_s32[start_s32];
    pst_curr->pst_lChild = NULL;
    pst_curr->pst_rChild = NULL;

    if (left_s32 < size_s32)
    {
        pst_curr->pst_lChild = levelOrderBinaryTreeUtil(p_array_s32, size_s32, left_s32);
    }
    if (right_s32 < size_s32)
    {
        pst_curr->pst_rChild = levelOrderBinaryTreeUtil(p_array_s32, size_s32, right_s32);
    }

    return pst_curr;
}

static treeNode* levelOrderBinaryTree(int* p_array_s32, const int size_s32)
{
    return levelOrderBinaryTreeUtil(p_array_s32, size_s32, 0);
}

static void maxSlidingWindows(int* p_array_s32, const int size_s32, int window_s32)
{
    Queue st_que;
    int i_s32 = 0;

    QueueInitialize(&st_que);

    for (i_s32 = 0; i_s32 < size_s32; i_s32++)
    {
        if (QueueSize(&st_que) && (QueueFront(&st_que) <= (i_s32 - window_s32)))
        {
            QueueRemove(&st_que);
        }
        while (QueueSize(&st_que) && (p_array_s32[QueueBack(&st_que)] <= p_array_s32[i_s32]))
        {
            QueueRemoveBack(&st_que);
        }
        QueueAdd(&st_que, i_s32);
        if (i_s32 >= (window_s32 - 1))
        {
            cout << p_array_s32[QueueFront(&st_que)] << " ";
        }
    }
}

static void QueueInitialize(Queue* pst_que)
{
    pst_que->back_s32 = 0;
    pst_que->front_s32 = 0;
    pst_que->size_s32 = 0;
}

static void QueueAdd(Queue* pst_que, int value_s32)
{
    if (pst_que->size_s32 > (MAX_CAPACITY - 1))
    {
        cout << "queue full!\n";
    }
    else
    {
        pst_que->size_s32++;
        pst_que->a_data_s32[pst_que->back_s32] = value_s32;
        pst_que->back_s32 = (pst_que->back_s32 + 1) % (MAX_CAPACITY - 1);
    }
}

static int QueueRemove(Queue* pst_que)
{
    int ret_s32 = ERROR_VALUE;

    if (pst_que->size_s32 <= 0)
    {
        cout << "queue empty!\n";
    }
    else
    {
        pst_que->size_s32--;
        ret_s32 = pst_que->a_data_s32[pst_que->front_s32];
        pst_que->front_s32 = (pst_que->front_s32 + 1) % (MAX_CAPACITY - 1);
    }

    return ret_s32;
}

static int QueueFront(Queue* pst_que)
{
    return pst_que->a_data_s32[pst_que->front_s32];
}

static int QueueBack(Queue* pst_que)
{
    return pst_que->a_data_s32[pst_que->back_s32 - 1];
}

static int QueueRemoveBack(Queue* pst_que)
{
    int ret_s32 = ERROR_VALUE;

    if (pst_que->size_s32 <= 0)
    {
        cout << "queue empty!\n";
    }
    else
    {
        pst_que->size_s32--;
        ret_s32 = pst_que->a_data_s32[pst_que->back_s32 - 1];
        pst_que->back_s32 = (pst_que->back_s32 - 1) % (MAX_CAPACITY - 1);
    }

    return ret_s32;
}

static int QueueIsEmpty(Queue* pst_que)
{
    return pst_que->size_s32 == 0;
}

static int QueueSize(Queue* pst_que)
{
    return pst_que->size_s32;
}

static void StackInitialize(Stack* pst_stk)
{
    pst_stk->top_s32 = -1;
}

static int StackEmpty(Stack* pst_stk)
{
    return (pst_stk->top_s32 == -1);
}

static int StackSize(Stack* pst_stk)
{
    return (pst_stk->top_s32 + 1);
}

static void StackPrint(Stack* pst_stk)
{
    int i_s32 = 0;

    for (i_s32 = pst_stk->top_s32; i_s32 >= 0; i_s32--)
    {
        cout << pst_stk ->a_data_s32[i_s32] << " ";
    }
    cout << "\n";
}

static void StackPush(Stack* pst_stk, int value_s32)
{
    if (pst_stk->top_s32 < (MAX_CAPACITY - 1))
    {
        pst_stk->top_s32++;
        pst_stk->a_data_s32[pst_stk->top_s32] = value_s32;
    }
    else
    {
        cout << "stack overflow!\n";
    }
}

static int StackPop(Stack* pst_stk)
{
    int ret_s32 = 0;

    if (pst_stk->top_s32 >= 0)
    {
        ret_s32 = pst_stk->a_data_s32[pst_stk->top_s32];
        pst_stk->top_s32--;
    }
    else
    {
        cout << "stack empty!\n";
        ret_s32 = ERROR_VALUE;
    }
    
    return ret_s32;
}

static int StackTop(Stack* pst_stk)
{
    return pst_stk->a_data_s32[pst_stk->top_s32];
}

static void deleteList(ListNode** pst_head)
{
    ListNode* pst_deleteMe = *pst_head;
    ListNode* pst_nextNode;

    while (NULL != pst_deleteMe)
    {
        pst_nextNode = pst_deleteMe->pst_next;
        free(pst_deleteMe);
        pst_deleteMe = pst_nextNode;
    }

    *pst_head = NULL;
}

static void deleteNodes(ListNode** pst_head, int delValue_s32)
{
    ListNode* pst_currNode = *pst_head;
    ListNode* pst_nextNode;
    ListNode* pst_delNode;

    while ((NULL != pst_currNode) && (delValue_s32 == pst_currNode->value_s32))
    {
        *pst_head = pst_currNode->pst_next;
        pst_delNode = pst_currNode;
        pst_currNode = pst_currNode->pst_next;
        free(pst_delNode);
    }

    while (NULL != pst_currNode)
    {
        pst_nextNode = pst_currNode->pst_next;
        if ((NULL != pst_nextNode) && (delValue_s32 == pst_nextNode->value_s32))
        {
            pst_currNode->pst_next = pst_nextNode->pst_next;
            free(pst_nextNode);
        }
        else
        {
            pst_currNode = pst_nextNode;
        }
    }
}

static void deleteFirstNodes(ListNode** pst_head)
{
    ListNode* pst_currNode = *pst_head;
    ListNode* pst_nextNode;

    if (NULL != pst_currNode)
    {
        pst_nextNode = pst_currNode->pst_next;
        free(pst_currNode);
        *pst_head = pst_nextNode;
    }
}

static void searchList(ListNode* pst_head, int value_s32)
{
    ListNode* pst_temp = pst_head;

    while (NULL != pst_temp)
    {
        if (pst_temp->value_s32 == value_s32)
        {
            cout << "found value\n";
        }
        pst_temp = pst_temp->pst_next;
    }
}

static void printList(ListNode* pst_head)
{
    ListNode* pst_temp = pst_head;

    while (NULL != pst_temp)
    {
        cout << pst_temp->value_s32 << ", ";
        pst_temp = pst_temp->pst_next;
    }

    cout << "\n";
}

static int insertNode(ListNode** pst_head, int value_s32)
{
    int ret_s32 = 0;
    ListNode* pst_tempNode = (ListNode*)malloc(sizeof(ListNode));

    if (NULL == pst_tempNode)
    {
        ret_s32 = -1;
    }
    else
    {
        pst_tempNode->value_s32 = value_s32;
        pst_tempNode->pst_next = *pst_head;
        *pst_head = pst_tempNode;

        ret_s32 = 1;
    }

    return ret_s32;
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
