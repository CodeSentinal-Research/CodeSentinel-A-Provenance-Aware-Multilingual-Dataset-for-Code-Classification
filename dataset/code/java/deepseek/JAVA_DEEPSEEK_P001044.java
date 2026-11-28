import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] heap = new int[N];
        for (int i = 0; i < N; i++) {
            heap[i] = scanner.nextInt();
        }

        int i = scanner.nextInt();
        int level = getLevel(heap, i, 0, 1);
        System.out.println(level);
    }

    private static int getLevel(int[] heap, int index, int currentLevel, int targetIndex) {
        if (index == targetIndex) {
            return currentLevel;
        }

        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < heap.length) {
            return getLevel(heap, leftIndex, currentLevel + 1, targetIndex);
        }

        if (rightIndex < heap.length) {
            return getLevel(heap, rightIndex, currentLevel + 1, targetIndex);
        }

        return -1; // if the index is not in the heap
    }
}
