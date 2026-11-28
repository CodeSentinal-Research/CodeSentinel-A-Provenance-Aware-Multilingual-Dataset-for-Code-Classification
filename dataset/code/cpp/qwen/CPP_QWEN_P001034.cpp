#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{int val;Node*next;};
int main(){int k;cin>>k;priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<>>pq;for(int i=0;i<k;i++){int sz;cin>>sz;Node*head=nullptr,*tail=nullptr;for(int j=0;j<sz;j++){int x;cin>>x;Node*nd=new Node{x,nullptr};if(!head)head=tail=nd;else{tail->next=nd;tail=nd;}}if(head)pq.push({head->val,head});}Node*res=nullptr,*tail=nullptr;while(!pq.empty()){auto[v,nd]=pq.top();pq.pop();if(!res)res=tail=nd;else{tail->next=nd;tail=nd;}if(nd->next)pq.push({nd->next->val,nd->next});}while(res){cout<<res->val<<" ";res=res->next;}cout<<endl;return 0;}
