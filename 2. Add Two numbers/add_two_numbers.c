// My Solution //
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *res= NULL;
    struct ListNode *start = NULL;
    int x, y, c = 0;
    
    if(!l1 && !l2) return NULL;
    else if (!l1) return l2; 
    else if (!l2) return l1;
    
    while (l1 || l2 || c)
    {
        x = l1 ? l1->val : 0;
        y = l2 ? l2->val : 0;
        
        if (!res)
        {
            res = malloc(sizeof(struct ListNode));
            start = res;
        }
        else
        {
            res->next = malloc(sizeof(struct ListNode));
            res = res->next;
        }
        res->next = NULL;
        res->val = (x+y+c)%10;
        c = (x+y+c)/10;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return start;
}

//Nico solution/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* longSum(struct ListNode* l1, struct ListNode* l2, int carry){
    struct ListNode* nextDigit = malloc(sizeof(struct ListNode));
    nextDigit->val = 0;
    nextDigit->next = NULL;
    if(!l1 && !l2 && !carry){
        return NULL;
    }
    
    else if(!l1 && !l2 && carry){
        nextDigit->val = carry;
    }
    
    else if(l1 && !l2){
        if(l1->val + carry >= 10){
            nextDigit->val = l1->val + carry - 10;
            carry = 1;
        }
        else{
            nextDigit->val = l1->val + carry;
            carry = 0;
        }
        nextDigit->next = longSum(l1->next, NULL, carry);
    }
    
    else if(!l1 && l2){
        if(l2->val + carry >= 10){
            nextDigit->val = l2->val + carry - 10;
            carry = 1;
        }
        else{
            nextDigit->val = l2->val + carry;
            carry = 0;
        }
        nextDigit->next = longSum(NULL, l2->next, carry);
    }
    
    else if(l1 && l2){
        if(l1->val + l2->val + carry >= 10){
            nextDigit->val = l1->val + l2->val + carry - 10;
            carry = 1;
            nextDigit->next = longSum(l1->next, l2->next, carry);
        }

        else{
            nextDigit->val = l1->val + l2->val + carry;
            carry = 0;
            nextDigit->next = longSum(l1->next, l2->next, carry);
        }
    }
    return  nextDigit;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = longSum(l1, l2, 0);
    return result;
}

