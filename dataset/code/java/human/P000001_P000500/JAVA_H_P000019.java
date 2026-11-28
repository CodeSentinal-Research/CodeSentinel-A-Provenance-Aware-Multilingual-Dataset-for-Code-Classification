/*
Input Format :
A single integer, n
Output Format :
First 10 multiples of n each printed in new line

*/


import java.util.Scanner;
class Main {
	
	public static void main(String[] args) {
		// Write your code here

        int n,b;
   Scanner sc=new Scanner(System.in);
   n=sc.nextInt();
   for(b=1; b<=10; b++)
   System.out.println(n*b);
	}
}
