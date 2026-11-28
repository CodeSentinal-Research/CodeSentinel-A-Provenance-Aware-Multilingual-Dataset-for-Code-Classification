#include <iostream>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int v):val(v),next(nullptr){}};
class Solution{
public:
    ListNode* middleNode(ListNode* head){
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}
        return slow;
    }
};
int main(){
    int n;cin>>n;ListNode*h=nullptr,*t=nullptr;
    for(int i=0;i<n;i++){int v;cin>>v;ListNode*nd=new ListNode(v);if(!h)h=t=nd;else{t->next=nd;t=nd;}}
    cout<<Solution().middleNode(h)->val<<"\n";
}
