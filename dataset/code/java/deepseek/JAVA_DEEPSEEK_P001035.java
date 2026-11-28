import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int N;
    static int[][] matrix;
    static int[] dir = {-1, 0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        matrix = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        int K = scanner.nextInt();
        System.out.println(kthSmallest(K));
    }

    static int kthSmallest(int K) {
        PriorityQueue<Node> queue = new PriorityQueue<>((a, b) -> a.val - b.val);
        boolean[][] visited = new boolean[N][N];
        queue.offer(new Node(0, 0, matrix[0][0]));
        visited[0][0] = true;
        while (!queue.isEmpty() && K > 0) {
            Node node = queue.poll();
            K--;
            for (int i = 0; i < 4; i++) {
                int newX = node.x + dir[i], newY = node.y + dir[i + 1];
                if (isValid(newX, newY) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    queue.offer(new Node(newX, newY, matrix[newX][newY]));
                }
            }
        }
        return -1;
    }

    static boolean isValid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    static class Node {
        int x, y, val;

        public Node(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }
}
