#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];if(n>1)cout<<a[n/2-1]<<endl;else cout<<-1<<endl;return 0;}
