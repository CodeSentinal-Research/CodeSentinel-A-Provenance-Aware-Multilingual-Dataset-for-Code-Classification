import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);String s=sc.nextLine().trim();
    Set<String>ws=new HashSet<>(Arrays.asList(sc.nextLine().trim().split(" ")));
    int n=s.length();boolean[]dp=new boolean[n+1];dp[0]=true;
    for(int i=1;i<=n;i++)for(int j=0;j<i;j++)if(dp[j]&&ws.contains(s.substring(j,i))){dp[i]=true;break;}
    System.out.println(dp[n]?"Yes":"No");}}
