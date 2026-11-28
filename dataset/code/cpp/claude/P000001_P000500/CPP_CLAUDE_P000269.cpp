#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){string line;getline(cin,line);istringstream iss(line);vector<string>words;string w;while(iss>>w)words.push_back(w);for(int i=words.size()-1;i>=0;i--)cout<<words[i]<<(i?" ":"\n");}
