#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int i;cin>>i;if(i==0)cout<<-1<<endl;else cout<<a[(i-1)/2]<<endl;return 0;}
