import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    final long MOD=1000000007L;int n=sc.nextInt();long[]arr=new long[n];for(int i=0;i<n;i++)arr[i]=sc.nextLong();
    long[]pre=new long[n+1],pp=new long[n+2];for(int i=0;i<n;i++)pre[i+1]=(pre[i]+arr[i])%MOD;
    for(int i=0;i<=n;i++)pp[i+1]=(pp[i]+pre[i+1])%MOD;
    int[]left=new int[n],right=new int[n];Deque<Integer>stk=new ArrayDeque<>();
    for(int i=0;i<n;i++){while(!stk.isEmpty()&&arr[stk.peek()]>=arr[i])stk.pop();left[i]=stk.isEmpty()?-1:stk.peek();stk.push(i);}
    stk.clear();
    for(int i=n-1;i>=0;i--){while(!stk.isEmpty()&&arr[stk.peek()]>arr[i])stk.pop();right[i]=stk.isEmpty()?n:stk.peek();stk.push(i);}
    long ans=0;
    for(int i=0;i<n;i++){int l=left[i]+1,r=right[i]-1;long cl=i-l+1,cr=r-i;
    long tot=((pp[r+2]-pp[i+1]+MOD)%MOD*cl%MOD-(pp[i+1]-pp[l]+MOD)%MOD*cr%MOD+2*MOD)%MOD;
    ans=(ans+arr[i]%MOD*tot)%MOD;}System.out.println(ans);}}
