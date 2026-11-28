#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n; cin>>n;
    unordered_map<int,int> freq;
    int best_val=0,best_cnt=0,x;
    for(int i=0;i<n;i++){cin>>x;freq[x]++;if(freq[x]>best_cnt){best_cnt=freq[x];best_val=x;}}
    cout<<best_val<<"\n";
}
