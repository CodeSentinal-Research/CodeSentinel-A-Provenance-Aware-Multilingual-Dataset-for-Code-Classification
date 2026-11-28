#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){string s;getline(cin,s);istringstream iss(s);string tok;int slots=1;
while(getline(iss,tok,',')){if(slots==0){cout<<"false\n";return 0;}slots--;if(tok!="#")slots+=2;}
cout<<(slots==0?"true":"false")<<"\n";}
