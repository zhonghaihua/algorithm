/*
	[从尾到头打印链表]
	输入一个链表，从尾到头打印链表每个节点的值。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        // vector<int> ans;
        // printListFromTailToHeadRecursive(head, ans);
        // return ans;

        return printListFromTailToHeadIterate(head);
    }

    vector<int> printListFromTailToHeadIterate(ListNode* head){
        vector<int> ans;
        stack<int> sNotes;
        ListNode* p = head;
        while(p){
            sNotes.push(p->val);
            p = p->next;
        }

        while(!sNotes.empty()){
            ans.push_back(sNotes.top());
            sNotes.pop();
        }

        return ans;
    }

    void printListFromTailToHeadRecursive(ListNode* head, vector<int>& ans){
        if(head == NULL)
            return;
        printListFromTailToHeadRecursive(head->next, ans);
        ans.push_back(head->val);
    }
};

int main()
{
    return 0;
}