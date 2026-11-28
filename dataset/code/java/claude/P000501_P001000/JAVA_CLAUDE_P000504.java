import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);int n=sc.nextInt();sc.nextLine();
    int[]res=new int[n];Deque<Integer>stk=new ArrayDeque<>();int prev=0;
    for(int i=0;i<n;i++){String log=sc.nextLine().trim();String[]parts=log.split(":");
        int fid=Integer.parseInt(parts[0]),t=Integer.parseInt(parts[2]);
        if(parts[1].equals("start")){if(!stk.isEmpty())res[stk.peek()]+=t-prev;stk.push(fid);prev=t;}
        else{res[stk.pop()]+=t-prev+1;prev=t+1;}
    }StringJoiner sj=new StringJoiner(" ");for(int v:res)sj.add(String.valueOf(v));System.out.println(sj);}}
