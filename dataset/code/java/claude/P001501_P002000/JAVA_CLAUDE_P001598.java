import java.util.*;
public class Solution {
    public long[] buildPrefix(long[] arr){
        long[] p=new long[arr.length+1];
        for(int i=0;i<arr.length;i++) p[i+1]=p[i]+arr[i]; return p;
    }
    public long query(long[] p,int l,int r){return p[r+1]-p[l];}
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); long[] arr=new long[n];
        for(int i=0;i<n;i++) arr[i]=sc.nextLong();
        Solution sol=new Solution(); long[] p=sol.buildPrefix(arr);
        int q=sc.nextInt(); while(q-->0) System.out.println(sol.query(p,sc.nextInt(),sc.nextInt()));
    }
}
