import java.util.*;
public class Main {
    static int[] parent;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int provinces = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int conn = sc.nextInt();
                if (conn == 1 && find(i) != find(j)) {
                    union(i, j);
                    provinces--;
                }
            }
        }
        System.out.println(provinces);
    }
    
    static int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    static void union(int i, int j) {
        parent[find(i)] = find(j);
    }
}
