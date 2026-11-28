import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]pre=new int[n+1];
    for(int i=0;i<n;i++)pre[i+1]=pre[i]+(sc.nextInt()%2!=0?1:0);
    int q=sc.nextInt();while(q-->0){int l=sc.nextInt(),r=sc.nextInt();System.out.println(pre[r+1]-pre[l]);}}}
