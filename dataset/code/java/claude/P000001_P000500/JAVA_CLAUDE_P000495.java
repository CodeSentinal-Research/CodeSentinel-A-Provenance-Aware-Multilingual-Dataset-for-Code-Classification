import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();Deque<int[]>stk=new ArrayDeque<>();while(n-->0){int p=sc.nextInt();int span=1;while(!stk.isEmpty()&&stk.peek()[0]<=p){span+=stk.pop()[1];}stk.push(new int[]{p,span});System.out.println(span);}}}
