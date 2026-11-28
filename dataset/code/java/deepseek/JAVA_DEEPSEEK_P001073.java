import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] parent;
    static int[] size;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N + 1];
        size = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            union(u, v, w);
        }
        int minWeight = Integer.MAX_VALUE;
        for (int i = 1; i <= N; i++) {
            minWeight = Math.min(minWeight, findWeight(i));
        }
        System.out.println(minWeight);
    }

    static int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    static void union(int x, int y, int w) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[y] = x;
            size[x] += size[y];
        }
    }

    static int findWeight(int x) {
        return size[find(x)];
    }
}
