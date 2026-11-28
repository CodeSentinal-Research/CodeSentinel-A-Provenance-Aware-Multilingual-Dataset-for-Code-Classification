#include<stdio.h>
int main(){int n;scanf("%d",&n);int vals[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};char*sym[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};for(int i=0;i<13;i++)while(n>=vals[i]){printf("%s",sym[i]);n-=vals[i];}printf("\n");}
