import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();
    Map<Integer,Integer>pre=new HashMap<>();pre.put(0,-1);int s=0,best=0;
    for(int i=0;i<n;i++){s+=(arr[i]==1?1:-1);if(pre.containsKey(s))best=Math.max(best,i-pre.get(s));else pre.put(s,i);}System.out.println(best);}}
