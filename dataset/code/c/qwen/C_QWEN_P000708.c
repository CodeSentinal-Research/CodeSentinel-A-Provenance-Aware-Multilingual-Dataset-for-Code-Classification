#include <stdio.h>
int moves=0;
void hanoi(int n, char s, char d, char a) { if(n==0) return; hanoi(n-1,s,a,d); printf("Move disk %d from %c to %c\n",n,s,d); moves++; hanoi(n-1,a,d,s); }
int main() { int n; scanf("%d",&n); hanoi(n,'A','C','B'); printf("Total moves: %d\n",moves); return 0; }
