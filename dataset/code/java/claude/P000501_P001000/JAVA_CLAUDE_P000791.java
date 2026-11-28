/* P000791: Longest Subarray with Sum K */
import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long[]arr=new long[n];for(int i=0;i<n;i++)arr[i]=sc.nextLong();long k=sc.nextLong();
    Map<Long,Integer>pre=new HashMap<>();pre.put(0L,-1);long s=0;int best=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(pre.containsKey(s-k)) best=Math.max(best,i-pre.get(s-k));
        if(!pre.containsKey(s)) pre.put(s,i);
    }
    System.out.println(best);
}}
