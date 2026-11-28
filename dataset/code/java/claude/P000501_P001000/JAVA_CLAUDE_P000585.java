import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();
    int lo=0,hi=n-1;StringBuilder sb=new StringBuilder();
    while(lo<=hi){sb.append(arr[lo++]).append(' ');if(lo<=hi)sb.append(arr[hi--]).append(' ');}
    System.out.println(sb.toString().trim());}}
