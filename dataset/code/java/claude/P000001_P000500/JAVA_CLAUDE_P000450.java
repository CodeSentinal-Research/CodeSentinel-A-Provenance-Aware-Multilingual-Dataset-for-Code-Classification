import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),k=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int lo=0,hi=n;while(lo<hi){int m=(lo+hi)/2;if(arr[m]-(m+1)>=k)hi=m;else lo=m+1;}System.out.println(lo+k);}}
