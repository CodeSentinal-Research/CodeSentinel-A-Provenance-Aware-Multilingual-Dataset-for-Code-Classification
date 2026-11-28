import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]t=new int[n],ans=new int[n];for(int i=0;i<n;i++)t[i]=sc.nextInt();
    Deque<Integer>stk=new ArrayDeque<>();
    for(int i=0;i<n;i++){while(!stk.isEmpty()&&t[stk.peek()]<t[i]){int j=stk.pop();ans[j]=i-j;}stk.push(i);}
    StringJoiner sj=new StringJoiner(" ");for(int v:ans)sj.add(String.valueOf(v));System.out.println(sj);}}
