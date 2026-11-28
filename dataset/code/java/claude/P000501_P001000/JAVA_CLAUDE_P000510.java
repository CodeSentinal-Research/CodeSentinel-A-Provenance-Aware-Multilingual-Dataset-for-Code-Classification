import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]p=new int[n],res=new int[n];
    for(int i=0;i<n;i++){p[i]=sc.nextInt();res[i]=p[i];}
    Deque<Integer>stk=new ArrayDeque<>();
    for(int i=0;i<n;i++){while(!stk.isEmpty()&&p[stk.peek()]>=p[i])res[stk.pop()]-=p[i];stk.push(i);}
    StringJoiner sj=new StringJoiner(" ");for(int v:res)sj.add(String.valueOf(v));System.out.println(sj);}}
