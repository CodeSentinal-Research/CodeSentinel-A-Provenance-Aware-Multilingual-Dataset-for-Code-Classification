import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long[]pre=new long[n+1];
    for(int i=0;i<n;i++)pre[i+1]=pre[i]+sc.nextInt();
    int q=sc.nextInt();while(q-->0){int l=sc.nextInt(),r=sc.nextInt();System.out.println(pre[r+1]-pre[l]);}}}
