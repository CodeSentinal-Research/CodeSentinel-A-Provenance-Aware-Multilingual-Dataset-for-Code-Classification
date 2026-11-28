import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),x=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int lo=0,hi=n-1;while(lo<hi){if(Math.abs(arr[lo]-x)<=Math.abs(arr[hi]-x))hi--;else lo++;}System.out.println(arr[lo]);}}
