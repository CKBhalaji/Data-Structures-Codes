/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *slot,*k,*h2 = list2,*h1 = list1,*d = NULL;
    slot = h1;
     if(h2==NULL)
        return h1;
    if(h1==NULL)
        return h2;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->val > h2->val)
        {
            k = h2;
            h2 = h2->next;
            if(d == NULL)
            {
                k->next = list1;
                slot = k;
            }
            else
            {
                d->next = k;
                k->next = h1;
            }
            d = k;
        }
        else{
        d = h1;
        h1 = h1->next;
        }
    }
   
    if(h2!=NULL)
        d->next = h2;
    return slot;
}
