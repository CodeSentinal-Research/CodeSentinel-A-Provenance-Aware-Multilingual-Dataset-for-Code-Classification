import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();
    int q=sc.nextInt();while(q-->0){int l=sc.nextInt(),r=sc.nextInt(),cnt=0;
        for(int v:arr)if(v>=l&&v<=r)cnt++;System.out.println(cnt);}}}
