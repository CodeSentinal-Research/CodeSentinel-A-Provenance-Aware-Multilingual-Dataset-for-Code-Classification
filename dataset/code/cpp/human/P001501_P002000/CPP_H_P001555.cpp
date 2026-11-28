#include<bits/stdc++.h>
using namespace std;
int maxNumberOfVowels(string s,int k){
    int count = 0;
    for(int i = 0;i<k;i++){
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
            count++;
        }
    }
    int maxx = count;
    for(int i = 1;i<=s.length()-k;i++){
        if(s[i-1] == 'a' or s[i-1] == 'e' or s[i-1] == 'i' or s[i-1] == 'o' or s[i-1] == 'u'){
            count--;
        }
        if(s[i+k-1] == 'a' or s[i+k-1] == 'e' or s[i+k-1] == 'i' or s[i+k-1] == 'o' or s[i+k-1] == 'u'){
            count++;
        }
        if(maxx<count){
            maxx = count; 
        }
    }
    return maxx;
}

int main(){
   string s;
   cout<<"Enter a String: ";
   getline(cin,s);
     int k;
    cout << "Enter Window Size: ";
    cin >> k;
    cout << "Maximum Number Of Vowels in a Substring is ";
    int ans = maxNumberOfVowels(s,k);
    cout<<ans<<" ";
}