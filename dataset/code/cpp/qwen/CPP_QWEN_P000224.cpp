#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<tuple<int,int,int>> jobs(n);
    for(int i=0;i<n;i++) { int id, d, p; cin>>id>>d>>p; jobs[i]={p,d,id}; }
    sort(jobs.rbegin(), jobs.rend());
    vector<bool> slot(n+1, false);
    int profit=0, cnt=0;
    for(auto& [p,d,id] : jobs) {
        for(int j=min(n,d);j>0;j--) {
            if(!slot[j]) { slot[j]=true; profit+=p; cnt++; break; }
        }
    }
    cout << cnt << " " << profit << endl;
    return 0;
}
