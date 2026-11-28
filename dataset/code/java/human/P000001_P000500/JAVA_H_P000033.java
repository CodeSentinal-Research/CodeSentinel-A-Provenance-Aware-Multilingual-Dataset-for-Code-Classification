//Write a program to find the sum of even numbers up to n using recursion.
import java.util.*;
class sumEven
{
	public static void main(String x[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of n");
		int n = sc.nextInt();
		int res = sumOfEven(n, 0);
		System.out.println(res);
	}
	public static int sumOfEven(int n, int sum)
	{
		if (n <= 1)
			return sum;
		if(n % 2 ==0)
		{
			sum += n;
		}
		return sumOfEven(n-1, sum);
	}
}