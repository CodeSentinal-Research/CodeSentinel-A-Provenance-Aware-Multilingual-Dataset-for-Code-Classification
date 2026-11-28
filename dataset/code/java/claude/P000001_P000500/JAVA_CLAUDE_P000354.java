import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),x,cnt=0;int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();x=sc.nextInt();for(int v:arr)if(v==x)cnt++;System.out.println(cnt);}}
