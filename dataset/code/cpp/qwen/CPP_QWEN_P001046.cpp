#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int c=0;for(int i=1;i<n;i++)if(a[i]>a[0])c++;cout<<c<<endl;return 0;}
