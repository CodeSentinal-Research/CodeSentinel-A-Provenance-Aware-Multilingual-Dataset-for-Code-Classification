#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){string w;cin>>w;bool allU=true,allL=true;for(char c:w){if(!isupper(c))allU=false;if(!islower(c))allL=false;}bool camel=isupper(w[0]);if(camel)for(int i=1;i<(int)w.size();i++)if(!islower(w[i])){camel=false;break;}cout<<(allU||allL||camel?"Yes":"No")<<"\n";}
