import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] top = new int[n];
        int[] bottom = new int[n];

        for (int i = 0; i < n; i++) {
            top[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            bottom[i] = scanner.nextInt();
        }

        System.out.println(minDominoRotations(top, bottom, n));
    }

    private static int minDominoRotations(int[] a, int[] b, int n) {
        int rotationsA = rotations(a, b, n);
        if (rotationsA != -1) {
            return rotationsA;
        }
        int rotationsB = rotations(b, a, n);
        if (rotationsB != -1) {
            return rotationsB;
        }
        return -1;
    }

    private static int rotations(int[] a, int[] b, int n) {
        int rotations = 0;
        int i = 0;
        while (i < n && a[i] == b[i]) {
            i++;
        }
        if (i == n) {
            return rotations;
        }
        int target = a[i];
        while (i < n && b[i] == target) {
            rotations++;
            i++;
        }
        if (i == n) {
            return rotations;
        }
        return -1;
    }
}
