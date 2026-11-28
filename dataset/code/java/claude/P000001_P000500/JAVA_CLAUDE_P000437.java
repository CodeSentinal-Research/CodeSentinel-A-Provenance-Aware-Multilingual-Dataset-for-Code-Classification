import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),x=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int lo=0,hi=n-1,res=-1;while(lo<=hi){int m=(lo+hi)/2;if(arr[m]<=x){res=arr[m];lo=m+1;}else hi=m-1;}System.out.println(res);}}
