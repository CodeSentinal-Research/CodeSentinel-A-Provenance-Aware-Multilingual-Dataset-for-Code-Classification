import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long s=0;StringBuilder sb=new StringBuilder();
    for(int i=0;i<n;i++){s+=sc.nextInt();sb.append(s);if(i<n-1)sb.append(' ');}System.out.println(sb);}}
