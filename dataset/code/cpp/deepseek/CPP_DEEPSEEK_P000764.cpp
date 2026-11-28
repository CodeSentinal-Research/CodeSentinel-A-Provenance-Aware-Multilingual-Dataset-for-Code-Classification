#include <iostream>
#include <sstream>

using namespace std;

int KthChar(string s, long long K) {
    int n = s.size();
    if(K == 1) return s[0];
    if(K == 2) return s[1];

    long long totalChars = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            totalChars++;
        }
    }

    if(K > totalChars) {
        K = K % totalChars;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            count++;
            if(count == K) {
                return s[i];
            }
        } else {
            long long nextK = K;
            while(s[i] >= '0' && s[i] <= '9') {
                long long num = s[i] - '0';
                K = K / 10 + num;
                s.erase(s.begin() + i);
                if(K > totalChars) {
                    K = K % totalChars;
                }
                if(nextK == K) {
                    return s[i];
                }
            }
        }
    }

    return -1;
}

int main() {
    long long K = 1;
    string s = "3abc4def";
    cout << KthChar(s, K) << endl;
    return 0;
}