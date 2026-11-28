import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int k=sc.nextInt();
    for(int i=0;i+k<=n;i+=k){int lo=i,hi=i+k-1;while(lo<hi){int t=arr[lo];arr[lo]=arr[hi];arr[hi]=t;lo++;hi--;}}
    StringJoiner sj=new StringJoiner(" ");for(int v:arr)sj.add(String.valueOf(v));System.out.println(sj);}}
