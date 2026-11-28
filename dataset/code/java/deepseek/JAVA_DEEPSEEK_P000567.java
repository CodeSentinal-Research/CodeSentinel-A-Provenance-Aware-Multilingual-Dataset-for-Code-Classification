import java.util.*;

public class Main {
    private static final int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    private static int m, n;
    private static int[][] forest;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        forest = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                forest[i][j] = scanner.nextInt();
            }
        }
        System.out.println(cutOffTrees());
    }

    private static int cutOffTrees() {
        List<int[]> trees = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.add(new int[]{forest[i][j], i, j});
                }
            }
        }
        trees.sort(Comparator.comparingInt(a -> a[0]));
        int[] start = new int[]{1, 0, 0};
        int totalSteps = 0;
        for (int[] tree : trees) {
            int steps = minSteps(start, tree);
            if (steps == -1) {
                return -1;
            }
            totalSteps += steps;
            start = tree;
       }
        return totalSteps;
    }

    private static int minSteps(int[] start, int[] end) {
        Queue<int[]> queue = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        queue.offer(start);
        Set<String> visited = new HashSet<>();
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                int[] cur = queue.poll();
                if (Arrays.equals(cur, end)) {
                    return cur[0];
                }
                for (int[] dir : dirs) {
                    int x = cur[1] + dir[0], y = cur[2] + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] > 0 && !visited.contains(x + "," + y)) {
                        queue.offer(new int[]{cur[0] + 1, x, y});
                        visited.add(x + "," + y);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}
