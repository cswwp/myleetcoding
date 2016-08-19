/**
	Reverse a singly linked list


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };




 */
struct ListNode* reverseList(struct ListNode* head) {
   if(!head)
    return head;
   else
   {
    struct ListNode* cursor = NULL;
    struct ListNode* next;
    while (head)
    {
        next = head->next;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    return cursor;
   }
    
}
