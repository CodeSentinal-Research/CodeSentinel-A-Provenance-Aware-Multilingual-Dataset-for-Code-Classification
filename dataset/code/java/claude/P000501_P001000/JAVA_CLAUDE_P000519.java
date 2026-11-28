import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]h=new int[n+1];for(int i=0;i<n;i++)h[i]=sc.nextInt();h[n]=0;
    Deque<Integer>stk=new ArrayDeque<>();long mx=0;
    for(int i=0;i<=n;i++){while(!stk.isEmpty()&&h[stk.peek()]>h[i]){int ht=h[stk.pop()];int w=stk.isEmpty()?i:i-stk.peek()-1;mx=Math.max(mx,(long)ht*w);}stk.push(i);}
    System.out.println(mx);}}
