#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head) {
    struct ListNode sorted;
    struct ListNode *cur = head;
    
    sorted.next = NULL;
    
    while (cur) {
        struct ListNode *next = cur->next;
        struct ListNode *sorted_cur = &sorted;
        while (1) {
            if (!sorted_cur->next || sorted_cur->next->val > cur->val) {
                cur->next = sorted_cur->next;
                sorted_cur->next = cur;
                break;
            }
            
            sorted_cur = sorted_cur->next;
        }
        cur = next;
    }
    return sorted.next;
}

int main()
{
	ListNode node;
	node->val=3; node->next->val=1;
}
