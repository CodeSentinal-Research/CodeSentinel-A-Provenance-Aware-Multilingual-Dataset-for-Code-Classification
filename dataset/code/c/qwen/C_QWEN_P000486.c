#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int heights[100000], stack[100000], top=-1;
    long long max_area=0;
    for(int i=0; i<n; i++) scanf("%d", &heights[i]);
    for(int i=0; i<=n; i++) {
        int h = (i==n) ? 0 : heights[i];
        while(top>=0 && heights[stack[top]]>h) {
            int height = heights[stack[top--]];
            int width = (top==-1) ? i : i-stack[top]-1;
            long long area = (long long)height*width;
            if(area>max_area) max_area=area;
        }
        stack[++top]=i;
    }
    printf("%lld\n", max_area);
    return 0;
}
