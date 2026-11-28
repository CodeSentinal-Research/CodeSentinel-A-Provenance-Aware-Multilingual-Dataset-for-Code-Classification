#include <stdio.h>
#include <string.h>
void gen(char *w, int i, char *curr, int ci) { if(w[i]=='\0') { curr[ci]='\0'; printf("%s\n",curr); return; } int j=i; while(w[j] && isdigit(w[j])) j++; if(j>i) { int num=atoi(w+i); sprintf(curr+ci,"%d",num); gen(w,j,curr,ci+strlen(curr+ci)); } else { curr[ci]=w[i]; gen(w,i+1,curr,ci+1); int k=i+1; while(w[k] && !isdigit(w[k])) k++; if(k>i+1) { sprintf(curr+ci,"%d",k-i-1); gen(w,k,curr,ci+strlen(curr+ci)); } } }
int main() { char w[16]; scanf("%s",w); char curr[50]; gen(w,0,curr,0); return 0; }
