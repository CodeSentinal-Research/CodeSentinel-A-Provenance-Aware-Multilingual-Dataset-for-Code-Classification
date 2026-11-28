import java.util.*;
public class Solution{
static long hist(int[]h){int n=h.length;int[]hh=Arrays.copyOf(h,n+1);Deque<Integer>stk=new ArrayDeque<>();long mx=0;for(int i=0;i<=n;i++){while(!stk.isEmpty()&&hh[stk.peek()]>hh[i]){int ht=hh[stk.pop()];int w=stk.isEmpty()?i:i-stk.peek()-1;mx=Math.max(mx,(long)ht*w);}stk.push(i);}return mx;}
public static void main(String[]a){Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();int[]h=new int[c];long ans=0;for(int i=0;i<r;i++){for(int j=0;j<c;j++){String cell=sc.next();h[j]=cell.equals("1")?h[j]+1:0;}ans=Math.max(ans,hist(h));}System.out.println(ans);}}
