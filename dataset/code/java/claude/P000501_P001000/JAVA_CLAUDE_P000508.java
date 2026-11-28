import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]h=new int[n],ans=new int[n];
    for(int i=0;i<n;i++)h[i]=sc.nextInt();
    Deque<Integer>stk=new ArrayDeque<>();
    for(int i=n-1;i>=0;i--){int cnt=0;
        while(!stk.isEmpty()&&stk.peek()<h[i]){stk.pop();cnt++;}
        if(!stk.isEmpty())cnt++;ans[i]=cnt;stk.push(h[i]);}
    StringJoiner sj=new StringJoiner(" ");for(int v:ans)sj.add(String.valueOf(v));System.out.println(sj);}}
