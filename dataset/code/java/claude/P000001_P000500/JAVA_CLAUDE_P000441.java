import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi+1)/2;if(arr[m]>=arr[lo])lo=m;else hi=m-1;}System.out.println(arr[lo]);}}
