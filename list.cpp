#include "comm.h"

using namespace std;
//81
ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    unordered_map<int, int> freq;
    auto prev = &dummy, curr = dummy.next;
    while(curr != nullptr){
        freq[curr->val]++;
        curr = curr->next;
    }

    curr = dummy.next;
    while(curr != nullptr){
        auto next = curr->next;
        if(freq[curr->val] > 1){
            prev->next = next;
            delete curr;
        }else{
            prev = curr;
        }
        curr = next;
    }
    return dummy.next;       
}

//143. Reorder List
// void reorderList(ListNode* head) {
//     auto reverseList = [](ListNode* head){
//         ListNode *prev = nullptr, *curr = head, *next = nullptr;
//         while(curr != nullptr){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     };

//     int len = 0;
//     auto cur = head;
//     // get the length of list
//     while(cur != nullptr){
//         len++;
//         cur = cur->next;
//     }

//     // split the list into two
//     int left_len = len % 2 ? len/2 + 1 : len/2;
//     auto left = head, right = head;
//     while(left_len--){
//         right = right->next;
//     }
//     // reverse the second list
//     right = reverseList(right);

//     //combine the two lists
//     ListNode dummy(0);
//     dummy.next = left;
//     dummy.next->next = right;
//     left = left->next;
//     right = right->next;
//     auto prev = dummy.next->next;
//     while(left && right){
//         prev->next = left;
//         prev->next->next = right;
//         left = left->next;
//         right = right->next;
//         prev = prev->next->next;    
//     }

//     prev->next = left != nullptr ? left : right;
//     head = dummy.next;
// }

void reorderList(ListNode* head){
    auto reverseList = [](ListNode* head){
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    };    

    if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return;
    }
    ListNode *fast = head, *slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    auto mid = slow->next;
    slow->next = nullptr;
    mid = reverseList(mid);
    while(head && mid){
        auto next = head->next;
        head->next = mid;
        mid = mid->next;
        head->next->next = next;
        head = next;
    }
}