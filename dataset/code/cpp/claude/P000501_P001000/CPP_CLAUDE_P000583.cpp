#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next; fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
int main(){
    int n,cp; cin>>n>>cp;
    vector<ListNode*> nodes(n);
    for(int i=0;i<n;i++){int v;cin>>v;nodes[i]=new ListNode(v);}
    for(int i=0;i<n-1;i++) nodes[i]->next=nodes[i+1];
    if(cp>=0) nodes[n-1]->next=nodes[cp];
    cout<<(Solution().hasCycle(nodes[0])?"Cycle Detected":"No Cycle")<<"\n";
}
