import java.util.*;
public class Main {
    static int N;
    static int[] parent;
    static int regions;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        parent = new int[4 * N * N];
        for (int i = 0; i < parent.length; i++) parent[i] = i;
        regions = parent.length;
        
        for (int i = 0; i < N; i++) {
            String line = sc.next();
            for (int j = 0; j < N; j++) {
                char c = line.charAt(j);
                int base = 4 * (i * N + j);
                if (c == '/') {
                    union(base, base + 1);
                    union(base + 2, base + 3);
                } else if (c == '\\') {
                    union(base, base + 3);
                    union(base + 1, base + 2);
                } else {
                    union(base, base + 1);
                    union(base + 1, base + 2);
                    union(base + 2, base + 3);
                }
                
                if (j > 0) union(base + 1, 4 * (i * N + j - 1) + 3);
                if (i > 0) union(base, 4 * ((i - 1) * N + j) + 2);
            }
        }
        System.out.println(regions);
    }
    
    static int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    static void union(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) {
            parent[pi] = pj;
            regions--;
        }
    }
}
