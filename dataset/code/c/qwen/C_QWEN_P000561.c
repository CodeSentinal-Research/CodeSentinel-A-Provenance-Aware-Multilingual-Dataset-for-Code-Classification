#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; scanf("%s", s);
    int count[256]={0}, queue[100001], front=0, rear=0;
    char res[100001]; int idx=0;
    for(int i=0; s[i]; i++) {
        count[s[i]]++;
        if(count[s[i]]==1) queue[rear++]=s[i];
        while(front<rear && count[queue[front]]>1) front++;
        res[idx++] = front<rear ? queue[front] : '#';
    }
    res[idx]='\0';
    printf("%s\n", res);
    return 0;
}
