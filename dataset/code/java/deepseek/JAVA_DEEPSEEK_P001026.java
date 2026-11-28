import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] parentIndices = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parentIndices[i] = scanner.nextInt();
        }
        scanner.close();

        if (isCompleteBinaryHeap(parentIndices, 1, N)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean isCompleteBinaryHeap(int[] parentIndices, int start, int end) {
        if (start > end) {
            return true;
        }
        if (parentIndices[start] != start) {
            return false;
        }
        if (2 * start <= end) {
            return isCompleteBinaryHeap(parentIndices, 2 * start, end) &&
                    isCompleteBinaryHeap(parentIndices, 2 * start + 1, end);
        }
        return true;
    }
}
