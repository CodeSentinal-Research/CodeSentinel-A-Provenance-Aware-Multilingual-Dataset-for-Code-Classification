import java.util.*;
public class Solution{
static int mh(int[]h,int n){Deque<Integer>st=new ArrayDeque<>();int mx=0;for(int i=0;i<=n;i++){int v=i==n?0:h[i];while(!st.isEmpty()&&h[st.peek()]>=v){int ht=h[st.pop()];int w=st.isEmpty()?i:i-st.peek()-1;mx=Math.max(mx,ht*w);}st.push(i);}return mx;}
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[]h=new int[c];int ans=0;
for(int i=0;i<r;i++){for(int j=0;j<c;j++){int v=sc.nextInt();h[j]=v==1?h[j]+1:0;}ans=Math.max(ans,mh(h,c));}
System.out.println(ans);}}
