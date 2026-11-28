#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
class Solution {
public:
    ListNode* insert(ListNode* head, int val) {
        ListNode* nd=new ListNode(val);
        if(!head) return nd;
        ListNode* cur=head;
        while(cur->next) cur=cur->next;
        cur->next=nd; return head;
    }
};
int main(){
    int n; cin>>n;
    ListNode* head=nullptr;
    Solution sol;
    for(int i=0;i<n;i++){int v;cin>>v;head=sol.insert(head,v);}
    while(head){cout<<head->val;if(head->next)cout<<" -> ";head=head->next;}
    cout<<"\n";
}
