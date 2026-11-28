#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<string,string,string>>book;for(int i=0;i<n;i++){string isbn,title,author;cin>>isbn>>title>>author;book.push_back({isbn,title,author});}string tisbn;cin>>tisbn;for(auto&[isbn,title,author]:book)if(isbn==tisbn){cout<<isbn<<" "<<title<<" "<<author<<endl;return 0;}cout<<"Book Not Found"<<endl;return 0;}
