import java.util.*;
public class Solution {
    public void bfs(List<List<Integer>> adj, int src, int n) {
        boolean[] vis=new boolean[n+1]; Queue<Integer> q=new LinkedList<>();
        vis[src]=true; q.offer(src); StringBuilder sb=new StringBuilder();
        while(!q.isEmpty()){int u=q.poll();sb.append(u).append(" ");for(int v:adj.get(u))if(!vis[v]){vis[v]=true;q.offer(v);}}
        System.out.println(sb.toString().trim());
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(),m=sc.nextInt();
        List<List<Integer>> adj=new ArrayList<>(); for(int i=0;i<=n;i++) adj.add(new ArrayList<>());
        for(int i=0;i<m;i++){int u=sc.nextInt(),v=sc.nextInt();adj.get(u).add(v);adj.get(v).add(u);}
        new Solution().bfs(adj,sc.nextInt(),n);
    }
}
