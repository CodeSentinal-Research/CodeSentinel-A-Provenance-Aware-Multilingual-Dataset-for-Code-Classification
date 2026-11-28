//factorial using recursion
// #include<stdio.h>
// int factorial(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// }
// int main() {
//     int num;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     printf("Factorial of %d is %d\n", num, factorial(num));
//     return 0;
// }

// print n to 1 using recursion
// #include <stdio.h>
// int decreasing(int n){
//     if(n==0) return 0;{
//     printf("%d ", n);
//     decreasing(n-1);
// }
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     decreasing(n);
//     return 0;          // 5 4 3 2 1 
// }
// print 1 to n using recursion
// #include<stdio.h> 
// void increasing(int x,int n){
//     if (x>n) return ;
//     printf("%d ", x);
//     return increasing(x+1, n);
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     increasing(1, n);   // // 1 2 3 4 5 6 7 8 9 10
//     return 0;
// }

// #include <stdio.h>
// void greeting(int n){
//     if(n==0) return;
//     printf("Good Morning \n");
//     greeting(n-1);
//     return ;
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     greeting(n);
//     return 0;
// }

//increasingaftercall code after call
// #include <stdio.h>
// int increasing(int n){
//     if(n==0) return 0;
//     increasing(n-1);
//     printf("%d ",n);  

// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     increasing(n);
//     return 0;       1 2 3 4 5 6 7 8 9 10
// }

// #include <stdio.h>
// int decreasing(int n){
//     if(n>=1){
//     printf("%d ", n);
//     decreasing(n-1);
//     printf("%d ", n);
// }
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     decreasing(n);    // Enter a number: 4
//     return 0;         // 4 3 2 1 1 2 3 4
// }

// print sum from 1 to n (parameterized recursion)
// #include<Stdio.h>
// void add(int n,int sum){
//     if(n==0) {
//         printf("%d",sum);
//         return;
//     }
//     add(n-1,sum+n);
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     add(n,0);   // Enter a number: 5
//     return 0;   // 15
// }

// print sum from 1 to n (return type recursion)
// #include<stdio.h>
// int add(int n){
//     if(n==0) return 0 ;
//     return n+add(n-1);
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     printf("%d",add(n));   // Enter a number: 5
//     return 0;             // 15
// }

// #include<stdio.h>
// int add(int n){
//     if(n==1 || n==0) return n;
//     int ans = n+add(n-1);
//     return ans;
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     printf("%d",add(n));   // Enter a number: 5
//     return 0;             // 15
// }

// power function using recursion
// #include <stdio.h>  
// int power(int a,int b){
//     if(b==0) return 1;
//     int ans = a*power(a,b-1);
//     return ans;
// }
// int main(){
//     int a,b;
//     printf("Enter a number: ");
//     scanf("%d %d", &a, &b);
//     printf("%d raised to %d is : %d",a,b,power(a,b));   // Enter a number: 2 3
//     return 0;             // 8
// }
 
//fibonacci series using recursion
// #include<stdio.h>
// int fibo(int n){
//     if(n==1 || n==2) return 1;
//     return fibo(n-1)+fibo(n-2);

// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);.0
//     printf("%dth fibonacci number is %d ",n,fibo(n));
//     return 0;
// }

//stair path count using recursion
// #include<stdio.h>
// int stair(int n){
//     if(n==1 || n==2) return n;
//     int totalways = stair(n-1) + stair(n-2);
//     return totalways;
// }
// int main(){
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     printf("Total ways to reach %dth stair is %d ",n,stair(n));
//     return 0;
// }

// power function(logarithmic)
// #include<stdio.h>
// int powerlog(int a,int b){
//     if(b==0) return 1;
//     if(b%2==0) return  powerlog(a,b/2)*powerlog(a,b/2);
//     else return a*powerlog(a,b/2)*powerlog(a,b/2);
// }
// int main(){
//     int a;
//     printf("Enter base : ");
//     scanf("%d",&a);
//     int b;
//     printf("Enter power : ");
//     scanf("%d",&b);
//     printf("%d raised to %d is : %d",a,b,powerlog(a,b));
//     return 0;
// }

// indirect recursion
// #include<stdio.h>
// int func1(int);
// int func2(int);
// int func1(int n){
//     if(n<=1) return 1;
//     else return n*func2(n-1);
// }
// int func2(int n){
//     if(n<=1) return 1;
//     else return n*func1(n-1);
// }
// int main(){
//     int n;
//     printf("Enter n : ");
//     scanf("%d",&n);
//     printf("factorial of %d : %d",n,func1(n));
//}

#include<stdio.h>  
void count(int n){
    static int d=1;
    printf("%d ",n);
    printf("%d ",d);
    d++;
    if(n>1) count(n-1);
    printf("%d ",d);
}
int main(){
    count(3);
}