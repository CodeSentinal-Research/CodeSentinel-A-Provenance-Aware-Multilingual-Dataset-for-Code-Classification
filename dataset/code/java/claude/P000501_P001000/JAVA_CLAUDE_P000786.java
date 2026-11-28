import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long[]arr=new long[n],pre=new long[n+1],suf=new long[n+1];
    for(int i=0;i<n;i++)arr[i]=sc.nextLong();
    for(int i=0;i<n;i++)pre[i+1]=pre[i]+arr[i];for(int i=n-1;i>=0;i--)suf[i]=suf[i+1]+arr[i];
    StringJoiner sj=new StringJoiner(" ");for(int i=0;i<n;i++)sj.add(String.valueOf(Math.abs(pre[i]-suf[i+1])));System.out.println(sj);}}
