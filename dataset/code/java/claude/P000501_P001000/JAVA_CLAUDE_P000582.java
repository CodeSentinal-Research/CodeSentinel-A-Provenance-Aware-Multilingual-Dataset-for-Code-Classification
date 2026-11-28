import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int prev=Integer.MIN_VALUE;StringBuilder sb=new StringBuilder();
    for(int i=0;i<n;i++){int v=sc.nextInt();if(v!=prev){sb.append(v).append(' ');prev=v;}}
    System.out.println(sb.toString().trim());}}
