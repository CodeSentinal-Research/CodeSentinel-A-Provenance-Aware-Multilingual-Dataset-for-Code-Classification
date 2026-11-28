#include <stdio.h>
int main(){double a,b;char op;scanf("%lf %c %lf",&a,&op,&b);switch(op){case '+':printf("%.2f\n",a+b);break;case '-':printf("%.2f\n",a-b);break;case '*':printf("%.2f\n",a*b);break;case '/':if(b==0)printf("Division by zero\n");else printf("%.2f\n",a/b);break;default:printf("Invalid\n");}return 0;}
