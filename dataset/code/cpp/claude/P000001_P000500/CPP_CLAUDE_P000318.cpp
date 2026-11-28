#include<iostream>
using namespace std;
int main(){string word,abbr;cin>>word>>abbr;int i=0,j=0,n=word.size(),m=abbr.size();while(i<n&&j<m){if(isdigit(abbr[j])){if(abbr[j]=='0'){cout<<"No\n";return 0;}int num=0;while(j<m&&isdigit(abbr[j]))num=num*10+(abbr[j++]-'0');i+=num;}else{if(word[i]!=abbr[j]){cout<<"No\n";return 0;}i++;j++;}}cout<<(i==n&&j==m?"Yes":"No")<<"\n";}
