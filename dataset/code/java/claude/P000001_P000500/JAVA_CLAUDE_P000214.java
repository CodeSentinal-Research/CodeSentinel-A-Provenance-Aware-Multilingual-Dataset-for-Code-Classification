import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        boolean[] seen=new boolean[n+1];
        for(int i=0;i<n;i++) seen[sc.nextInt()]=true;
        StringBuilder sb=new StringBuilder();
        for(int i=1;i<=n;i++) if(!seen[i]){if(sb.length()>0)sb.append(' ');sb.append(i);}
        System.out.println(sb);
    }
}
