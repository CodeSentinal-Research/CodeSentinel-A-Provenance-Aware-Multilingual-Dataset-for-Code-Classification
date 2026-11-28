import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] values = new int[n];
        int[] lefts = new int[n];
        int[] rights = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
            lefts[i] = scanner.nextInt() - 1;
            rights[i] = scanner.nextInt() - 1;
        }
        System.out.println(isPossible(n, values, lefts, rights) ? "YES" : "NO");
    }

    private static boolean isPossible(int n, int[] values, int[] lefts, int[] rights) {
        int[] inDegree = new int[n];
        for (int i = 0; i < n; i++) {
            if (lefts[i] != -1) {
                inDegree[lefts[i]]++;
            }
            if (rights[i] != -1) {
                inDegree[rights[i]]++;
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            if (lefts[cur] != -1) {
                if (values[lefts[cur]] >= values[cur]) {
                    return false;
                }
                if (--inDegree[lefts[cur]] == 0) {
                    queue.offer(lefts[cur]);
                }
            }
            if (rights[cur] != -1) {
                if (values[rights[cur]] <= values[cur]) {
                    return false;
                }
                if (--inDegree[rights[cur]] == 0) {
                    queue.offer(rights[cur]);
                }
            }
        }
        return true;
    }
}
