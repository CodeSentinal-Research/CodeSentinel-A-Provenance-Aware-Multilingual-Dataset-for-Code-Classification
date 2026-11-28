/* P000574: Binary Tree Right Side View */
import java.util.*;
public class Solution{public static void main(String[]a){
    String[]toks=new Scanner(System.in).nextLine().trim().split(" ");
    int n=toks.length;int[]val=new int[n];boolean[]has=new boolean[n];
    for(int i=0;i<n;i++){if(!toks[i].equals("null")){has[i]=true;val[i]=Integer.parseInt(toks[i]);}}
    if(n==0||!has[0])return;
    Queue<int[]>q=new LinkedList<>();q.add(new int[]{0,0});TreeMap<Integer,Integer>rv=new TreeMap<>();
    while(!q.isEmpty()){int[]cur=q.poll();int idx=cur[0],lev=cur[1];
        if(idx>=n||!has[idx])continue;
        rv.put(lev,val[idx]);
        if(2*idx+1<n)q.add(new int[]{2*idx+1,lev+1});
        if(2*idx+2<n)q.add(new int[]{2*idx+2,lev+1});}
    StringJoiner sj=new StringJoiner(" ");for(int v:rv.values())sj.add(String.valueOf(v));System.out.println(sj);}}
