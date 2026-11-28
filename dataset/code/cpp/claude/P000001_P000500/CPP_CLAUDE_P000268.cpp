#include<iostream>
#include<sstream>
using namespace std;
int main(){string line;getline(cin,line);istringstream iss(line);string w;int cnt=0;while(iss>>w)cnt++;cout<<cnt<<"\n";}
