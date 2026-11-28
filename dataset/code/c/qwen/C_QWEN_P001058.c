#include <stdio.h>
int main() {
    int q; scanf("%d", &q);
    int stack[200001], freq[200001], max_freq = 0, sz = 0;
    int count[100001] = {0};
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0] == 'p') {
            int x; scanf("%d", &x);
            count[x]++;
            if(count[x] > max_freq) max_freq = count[x];
            stack[sz++] = x;
            freq[sz-1] = count[x];
        } else {
            int val = -1, idx = -1;
            for(int i=sz-1; i>=0; i--) {
                if(freq[i] == max_freq) { val = stack[i]; idx = i; break; }
            }
            printf("%d\n", val);
            if(idx != -1) {
                for(int i=idx; i<sz-1; i++) { stack[i] = stack[i+1]; freq[i] = freq[i+1]; }
                sz--;
                count[val]--;
                if(count[val] == 0) max_freq--;
            }
        }
    }
    return 0;
}
