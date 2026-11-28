import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int p=sc.nextInt();
    long tot=0;for(int v:arr)tot+=v;int r=(int)(tot%p);if(r==0){System.out.println(0);return;}
    Map<Integer,Integer>pre=new HashMap<>();pre.put(0,-1);int s=0,best=n;
    for(int i=0;i<n;i++){s=(s+arr[i])%p;int t=((s-r)%p+p)%p;if(pre.containsKey(t)){int len=i-pre.get(t);if(len<n&&len<best)best=len;}if(!pre.containsKey(s))pre.put(s,i);}
    System.out.println(best==n?-1:best);}}
