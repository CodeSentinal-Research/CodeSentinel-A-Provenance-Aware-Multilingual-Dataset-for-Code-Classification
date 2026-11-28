#include <iostream>
using namespace std;

bool isInterleave(string A, string B, string C) {
    int i = 0, j = 0, k = 0;
    int m = A.length();
    int n = B.length();
    int o = C.length();
    
    while(i < m && j < n && k < o) {
        if(A[i] == C[k]) {
            k++;
        }
        else if(B[j] == C[k]) {
            j++;
            k++;
        }
        else if(A[i] != C[k]) {
            return false;
        }
    }

    while(i < m && A[i] == C[i]) {
        i++;
    }
    
    while(j < n && B[j] == C[j]) {
        j++;
    }
    
    if(i < m || j < n) {
        return false;
    }
    
    return true;
}

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    if(isInterleave(A, B, C)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}