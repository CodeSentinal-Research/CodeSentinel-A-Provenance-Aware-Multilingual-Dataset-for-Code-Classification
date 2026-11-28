import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] heap1 = new int[N];
        for (int i = 0; i < N; i++) {
            heap1[i] = scanner.nextInt();
        }

        int M = scanner.nextInt();
        int[] heap2 = new int[M];
        for (int i = 0; i < M; i++) {
            heap2[i] = scanner.nextInt();
        }

        if (isIdentical(heap1, 0, heap1.length, heap2, 0, heap2.length)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean isIdentical(int[] heap1, int start1, int end1, int[] heap2, int start2, int end2) {
        if (start1 == end1 && start2 == end2) {
            return true;
        }

        if (start1 == end1 || start2 == end2) {
            return false;
        }

        if (heap1[start1] != heap2[start2]) {
            return false;
        }

        return isIdentical(heap1, start1 + 1, end1, heap2, start2 + 1, end2);
    }
}
