//problem
//Count the number of consecutive 0s starting from the most significant bit

#include<iostream>
using namespace std;
int zeros(int n){
    if(n==0){
        return 32;
    }
    int count=0;
    for(int i=31;i>=0;i--){
        if(((n>>i)&1)==0){
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<zeros(n);
    return 0;
}