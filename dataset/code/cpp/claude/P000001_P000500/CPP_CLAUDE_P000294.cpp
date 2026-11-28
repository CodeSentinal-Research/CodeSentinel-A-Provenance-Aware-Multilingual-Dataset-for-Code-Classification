#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){string s;int rows;cin>>s>>rows;if(rows==1){cout<<s<<"\n";return 0;}vector<string>v(rows);int row=0;bool down=true;for(char c:s){v[row]+=c;if(row==rows-1)down=false;else if(row==0)down=true;row+=down?1:-1;}string r="";for(auto&x:v)r+=x;cout<<r<<"\n";}
