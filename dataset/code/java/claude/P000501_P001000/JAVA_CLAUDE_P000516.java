import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n],s=new int[n];for(int i=0;i<n;i++){arr[i]=sc.nextInt();s[i]=arr[i];}Arrays.sort(s);
    int l=0,r=n-1;while(l<n&&arr[l]==s[l])l++;while(r>=0&&arr[r]==s[r])r--;
    System.out.println(l>r?0:r-l+1);}}
