#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int i = 0, j = S.size() - 1;
    while(i < j) {
        if(S[i] != 'a' && S[i] != 'A' && S[i] != 'e' && S[i] != 'E' && S[i] != 'i' && S[i] != 'I' && S[i] != 'o' && S[i] != 'O' && S[i] != 'u' && S[i] != 'U') i++;
        else if(S[j] != 'a' && S[j] != 'A' && S[j] != 'e' && S[j] != 'E' && S[j] != 'i' && S[j] != 'I' && S[j] != 'o' && S[j] != 'O' && S[j] != 'u' && S[j] != 'U') j--;
        else if(S[i] == S[j] && (S[i] == 'a' || S[i] == 'A' || S[i] == 'e' || S[i] == 'E' || S[i] == 'i' || S[i] == 'I' || S[i] == 'o' || S[i] == 'O' || S[i] == 'u' || S[i] == 'U')) {
            i++;
            j--;
        } else {
            swap(S[i], S[j]);
            i++;
            j--;
        }
    }
    
    cout << S;
    return 0;
}