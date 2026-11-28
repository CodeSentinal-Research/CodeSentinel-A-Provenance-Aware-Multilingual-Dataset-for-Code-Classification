#include <stdio.h>
#include <string.h>
int main() {
    char s[200001], t[200001]; scanf("%s %s", s, t);
    char ps[200001], pt[200001]; int ps_idx=0, pt_idx=0;
    for(int i=0; s[i]; i++) {
        if(s[i]=='#') { if(ps_idx>0) ps_idx--; }
        else ps[ps_idx++]=s[i];
    }
    for(int i=0; t[i]; i++) {
        if(t[i]=='#') { if(pt_idx>0) pt_idx--; }
        else pt[pt_idx++]=t[i];
    }
    ps[ps_idx]='\0'; pt[pt_idx]='\0';
    printf("%s\n", strcmp(ps, pt)==0 ? "true" : "false");
    return 0;
}
