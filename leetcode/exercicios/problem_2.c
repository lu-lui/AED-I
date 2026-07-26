/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 #include <stdio.h>
 #include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next;
 };

void print_result(struct ListNode *result); 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(){
    struct ListNode *result;
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l2->val = 5;

    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->next->val = 4;
    l2->next->val = 6;

    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->next->next->val = 3;
    l2->next->next->val = 4;

    l1->next->next->next = NULL;
    l1->next->next->next = NULL;

    result = addTwoNumbers(l1, l2);
    
    print_result(result);
    

    return 0;
}

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     struct ListNode p;
//     p.next = NULL;
    
// }

void print_result(struct ListNode *result) {
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
}