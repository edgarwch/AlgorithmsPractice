//
//  swap.h
//  coding_pac
//
//  Created by Edgar Wong on 13/08/2022.
//
//Linked List!
#ifndef swap_h
#define swap_h
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push(struct ListNode** head, int node_data)
{
   /* 1. create and allocate node */
   struct ListNode* newNode = new ListNode;
 
   /* 2. assign data to node */
   newNode->val = node_data;
 
   /* 3. set next of new node as head */
   newNode->next = (*head);
 
   /* 4. move the head to point to the new node */
   (*head) = newNode;
}

void append(struct ListNode** head, int node_data)
{
    /* 1. create and allocate node */
    struct ListNode* newNode = new ListNode;
     
    struct ListNode *last = *head; /* used in step 5*/
     
    /* 2. assign data to the node */
    newNode->val = node_data;
     
    /* 3. set next pointer of new node to null as its the last node*/
    newNode->next = NULL;
     
    /* 4. if list is empty, new node becomes first node */
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
     
    /* 6. Change the next of last node */
    last->next = newNode;
    return;
}
 
#endif /* swap_h */
