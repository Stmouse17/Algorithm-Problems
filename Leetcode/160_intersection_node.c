#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 typedef struct ListNode
 {
    int val;
    struct ListNode* next;
 }ListNode;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int length_A = 0, length_B = 0;
    int gap;
    ListNode* pa = headA, * pb = headB;
    while (pa)
    {
        pa = pa->next;
        length_A++;
    }
    while (pb)
    {
        pb = pb->next;
        length_B++;
    }
    gap = abs(length_A - length_B);
    pa = headA;
    pb = headB;
    if (length_A > length_B)
        for (int i = 0; i < gap; i++)
            pa = pa->next;
    else
        for (int i = 0; i < gap; i++)
            pb = pb->next;
    while (pa != NULL && pb != NULL && pa != pb)
    {
        pa = pa->next;
        pb = pb->next;
    }
    return pa;
}

ListNode *createNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    node->val = val;
    node->next = NULL;

    return node;
}

void printResult(ListNode *node)
{
    if (node == NULL)
        printf("No intersection\n");
    else
        printf("Intersected at:%d\n", node->val);
}


int main()
{
    /*
        construct：
        A: 1 → 2 → 3
                    \
                     7 → 8 → 9 → NULL
                    /
        B:     4 → 5
    */

    ListNode *A1 = createNode(1);
    ListNode *A2 = createNode(2);
    ListNode *A3 = createNode(3);

    ListNode *B1 = createNode(4);
    ListNode *B2 = createNode(5);

    ListNode *C1 = createNode(7);
    ListNode *C2 = createNode(8);
    ListNode *C3 = createNode(9);

    A1->next = A2;
    A2->next = A3;
    A3->next = C1;
    B1->next = B2;
    B2->next = C1;
    C1->next = C2;
    C2->next = C3;

    ListNode *result = getIntersectionNode(A1, B1);
    printResult(result);
    return 0;
}