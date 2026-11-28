#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;
int main(){string line,w;getline(cin,line);istringstream iss(line);bool f=true;string r="";for(char&c:line){if(c==" "){r+=c;f=true;}else{r+=f?toupper(c):tolower(c);f=false;}}cout<<r<<"\n";}
