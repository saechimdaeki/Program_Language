/******************************************************/
/********************PL HW2 ISORT**********************/
/*******************HEADER FILE***********************/
#include<stdio.h> 
#include<stdlib.h> 
//////////////////////////////////////////////////////

/******************Used function*********************/
/****************************************************/
void sortedInsert(struct Node**, struct Node*); 
void insertionSort(struct Node **head_ref);
void sortedInsert(struct Node** head_ref, struct Node* new_node);
void printList(struct Node *head);
void push(struct Node** head_ref, int new_data); //LIKE STACK CONCEPT
/*******************************************************************/
/*
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
*/

///////////		방식을  변경합니다. ///////// 
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
// Function to insert a given node in a sorted linked list 
void sortedInsert(struct Node**, struct Node*); 
  
// function to sort a singly linked list using insertion sort 
void insertionSort(struct Node **head_ref) 
{ 
    // Initialize sorted linked list 
    struct Node *sorted = NULL; 
  
    // Traverse the given linked list and insert every 
    // node to sorted 
    struct Node *current = *head_ref; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
        struct Node *next = current->next; 
  
        // insert current in sorted linked list 
        sortedInsert(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
    *head_ref = sorted; 
} 
  
void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
} 

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
int main() 
{ 
    struct Node *a = NULL;
	int n,i; 
    printf("How many numbers do you want to sort?: ");
    scanf("%d",&n);
    printf("Now enter as many numbers as you want before : ");
    int arr[n];
	for(i=0; i<n; i++)
    {
    	scanf("%d",&arr[i]);
    	push(&a,arr[i]);
	}
    printf("Linked List before sorting \n"); printf("[");
    printList(a); printf("]");
  
    insertionSort(&a); 
  
    printf("\nLinked List after sorting \n"); 
    printf("[");
	printList(a);
	printf("]"); 
  
    return 0; 
} 
