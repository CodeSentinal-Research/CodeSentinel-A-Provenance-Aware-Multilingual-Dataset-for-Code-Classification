import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long[]arr=new long[n];long tot=0;for(int i=0;i<n;i++){arr[i]=sc.nextLong();tot+=arr[i];}
    long left=0;for(int i=0;i<n;i++){if(left==tot-left-arr[i]){System.out.println(i);return;}left+=arr[i];}System.out.println(-1);}}
