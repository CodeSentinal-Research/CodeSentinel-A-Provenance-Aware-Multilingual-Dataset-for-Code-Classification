import java.util.*;
public class Main {
    static int[] parent;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        int[] redundant = null;
        for (int i = 0; i < n; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            if (find(u) == find(v)) {
                redundant = new int[]{u, v};
            } else {
                union(u, v);
            }
        }
        System.out.println(redundant[0] + " " + redundant[1]);
    }
    static int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    static void union(int i, int j) {
        parent[find(i)] = find(j);
    }
}
