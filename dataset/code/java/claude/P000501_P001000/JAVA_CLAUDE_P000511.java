import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();
    long tot=0;
    for(int i=0;i<n;i++){int mn=arr[i],mx=arr[i];for(int j=i;j<n;j++){mn=Math.min(mn,arr[j]);mx=Math.max(mx,arr[j]);tot+=mx-mn;}}
    System.out.println(tot);}}
