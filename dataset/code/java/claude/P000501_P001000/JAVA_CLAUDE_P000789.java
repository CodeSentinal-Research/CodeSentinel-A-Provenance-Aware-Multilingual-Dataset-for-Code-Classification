import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long[]arr=new long[n];for(int i=0;i<n;i++)arr[i]=sc.nextLong();long k=sc.nextLong();
    Map<Long,Integer>cnt=new HashMap<>();cnt.put(0L,1);long s=0,ans=0;
    for(long v:arr){s+=v;ans+=cnt.getOrDefault(s-k,0);cnt.merge(s,1,Integer::sum);}System.out.println(ans);}}
