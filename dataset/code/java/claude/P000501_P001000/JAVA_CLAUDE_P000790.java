import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int k=sc.nextInt();
    Map<Integer,Integer>seen=new HashMap<>();seen.put(0,-1);int s=0;
    for(int i=0;i<n;i++){s=((s+arr[i])%k+k)%k;if(seen.containsKey(s)&&i-seen.get(s)>=2){System.out.println("true");return;}if(!seen.containsKey(s))seen.put(s,i);}
    System.out.println("false");}}
