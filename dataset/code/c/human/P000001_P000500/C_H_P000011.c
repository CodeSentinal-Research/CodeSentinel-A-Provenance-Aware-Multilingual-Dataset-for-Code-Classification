// Program to find maximum of three numbers using nested switch
#include <stdio.h>

void main()
{
int a, b,c;
clrscr();
printf("Enter three numbers: ");
scanf("%d %d %d", &a, &b, &c);

switch (a > b)
{ case 1:
  switch (a > c)
  { case 1:
       printf("Maximum is %d\n", a);
       break;
    case 0:
       printf("Maximum is %d\n", c);
       break;
  }
    break;
  case 0:
  switch (b > c)
  { case 1:
       printf("Maximum is %d\n", b);
       break;
    case 0:
       printf("Maximum is %d\n", c);
       break;
  }
    break;
}

getch();
}

