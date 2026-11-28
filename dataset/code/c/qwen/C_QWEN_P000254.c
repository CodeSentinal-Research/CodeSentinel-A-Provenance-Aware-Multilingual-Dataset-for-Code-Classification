#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int count=0;
    for(int i=0; s[i]; i++) { char c=s[i]; if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) count++; }
    printf("%d\n", count);
    return 0;
}
