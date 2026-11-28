import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int k=sc.nextInt();
    Map<Integer,Integer>cnt=new HashMap<>();cnt.put(0,1);int odds=0;long ans=0;
    for(int v:arr){odds+=v%2;ans+=cnt.getOrDefault(odds-k,0);cnt.merge(odds,1,Integer::sum);}System.out.println(ans);}}
