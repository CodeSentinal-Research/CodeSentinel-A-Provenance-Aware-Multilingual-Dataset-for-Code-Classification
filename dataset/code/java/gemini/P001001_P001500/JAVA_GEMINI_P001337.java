public class Solution {
    private int backtrack(int pos, int n, boolean[] visited) {
        if (pos > n) return 1;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                count += backtrack(pos + 1, n, visited);
                visited[i] = false;
            }
        }
        return count;
    }

    public int countArrangement(int n) {
        return backtrack(1, n, new boolean[n + 1]);
    }
}