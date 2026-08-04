#include <stdio.h>
#include <stdlib.h>
#define SIZE 10007  //prime number

//chaining for collision handling
typedef struct Node
{
    int key;    //num[i]
    int value;  //index of num[i]
    struct Node* next;
}Node;

Node* hashTable[SIZE];

int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % SIZE;
}

Node* find(int key)
{
    int h = hash(key);
    Node* p = hashTable[h]; //link entry
    while (p != NULL)
    {
        if (p->key == key)
            return p;
        p = p->next;
    }
    return NULL;
}

void insert(int key, int value)
{
    int h = hash(key);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = hashTable[h];  //headinsert
    hashTable[h] = node;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    //initialize hashTable
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        int need = target - nums[i];
        Node* p = find(need);
        if (p != NULL)                  //possible hit
        {
            int *ans = (int*)malloc(sizeof(int) * 2);   //return array
            ans[0] = p->value;
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[] = {3, 2, 95, 4, -3};
    int returnSize;
    int* ans = twoSum(nums, 5, 92, &returnSize);
    if (ans !=  NULL)
    {
        printf("%d %d\n", ans[0], ans[1]);
        free(ans);
    }
    return 0;
}


