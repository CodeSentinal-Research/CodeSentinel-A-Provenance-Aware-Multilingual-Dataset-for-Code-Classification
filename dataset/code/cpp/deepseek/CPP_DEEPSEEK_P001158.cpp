#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int* arr = new int[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    int maxProduct = 0;
    for(int i=0; i<N; i++) {
        int product = arr[i];
        for(int j=i+1; j<N; j++) {
            product *= arr[j];
        }
        if(product > maxProduct) {
            maxProduct = product;
        }
    }
    
    cout << maxProduct;
    
    delete[] arr;
    return 0;
}