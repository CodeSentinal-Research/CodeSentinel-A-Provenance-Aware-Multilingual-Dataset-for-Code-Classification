import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();Arrays.sort(arr);
    int ans=Math.min(arr[n-1]-arr[2],Math.min(arr[n-2]-arr[1],arr[n-3]-arr[0]));
    System.out.println(Math.max(0,ans));}}
