import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int lo=0,hi=n-1;while(hi-lo>2){int m1=lo+(hi-lo)/3,m2=hi-(hi-lo)/3;if(arr[m1]<arr[m2])lo=m1+1;else hi=m2-1;}int mx=arr[lo];for(int i=lo+1;i<=hi;i++)if(arr[i]>mx)mx=arr[i];System.out.println(mx);}}
