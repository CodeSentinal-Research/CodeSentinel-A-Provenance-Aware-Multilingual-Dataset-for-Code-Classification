Here is the C++ code for generating N-bit Gray codes using the recursive construction:

#include <iostream>
using namespace std;

void GrayCode(int n)
{
    if (n == 0)
        return;
    
    GrayCode(n-1);

    cout<<((1<<(n-1))<<endl);
}

int main()
{
    int N;
    cout<<"Enter the value of N: ";
    cin>>N;

    if (N < 1 || N > 16)
    {
        cout<<"Invalid input";
        return 0;
    }

    cout<<"2^"<<N<<" Gray codes are: "<<endl;
    GrayCode(N);

    return 0;
}
This program will prompt the user to enter the value of N, then print the 2^N Gray codes in order. The recursive Gray code construction is implemented by calling the GrayCode function recursively for n-1, then print the 2^(n-1) Gray code, which is the next Gray code after the previous Gray code.