import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),x=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();for(int i=n-1;i>=0;i--)if(arr[i]==x){System.out.println(i);return;}System.out.println(-1);}}
