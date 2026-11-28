//Q4. Problem: Print the average of every window of size k.
// Input: arr = [1, 3, 5, 7, 9], k = 3
// Output: 3.0, 5.0, 7.0
//Explanation : Use a window sum and divide by k each time after sliding.

import java.util.*;
class DS4{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter Array Size");
		int n = sc.nextInt();
		
		int a[] = new int[n];
		System.out.println("Enter Array");
		
		for(int i=0; i<a.length; i++){
			a[i] = sc.nextInt();
		}
		
		System.out.println("Enter Window of Size K");
		int k = sc.nextInt();
		
		double sum = 0;
		
		for(int i=0; i<k; i++){
			sum = sum + a[i];
		}
		System.out.print(sum / k + " ");

		for(int i= k; i<a.length; i++){
			
			sum = sum + a[i] - a[i-k];
			
		    System.out.print(sum / k + " ");
		}
	}
}