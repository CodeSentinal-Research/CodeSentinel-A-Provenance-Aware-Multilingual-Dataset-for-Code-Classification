#include<iostream>
using namespace std;
int main(){int n;cin>>n;string res="";while(n){n--;res=(char)('A'+n%26)+res;n/=26;}cout<<res<<"\n";}
