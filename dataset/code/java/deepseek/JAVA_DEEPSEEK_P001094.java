import java.util.*;

public class Main {
    static int L, R, M;
    static int[][] edges;
    static int[] matchR;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        L = sc.nextInt();
        R = sc.nextInt();
        M = sc.nextInt();
        edges = new int[M][2];
        matchR = new int[R + 1];
        visited = new boolean[L + 1];

        for (int i = 0; i < M; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
        }

        int maxMatching = 0;
        for (int i = 1; i <= L; i++) {
            if (matchR[i] == 0 && dfs(i)) {
                maxMatching++;
            }
        }

        System.out.println(maxMatching);
    }

    static boolean dfs(int left) {
        if (visited[left]) {
            return false;
        }
        visited[left] = true;

        for (int i = 0; i < M; i++) {
            if (edges[i][0] == left && matchR[edges[i][1]] == 0 && dfs(matchR[edges[i][1]])) {
                matchR[left] = edges[i][1];
                matchR[edges[i][1]] = left;
                return true;
            }
        }

        for (int i = 1; i <= R; i++) {
            if (matchR[i] == 0 && dfs(i)) {
                matchR[left] = i;
                matchR[i] = left;
                return true;
            }
        }

        return false;
    }
}
