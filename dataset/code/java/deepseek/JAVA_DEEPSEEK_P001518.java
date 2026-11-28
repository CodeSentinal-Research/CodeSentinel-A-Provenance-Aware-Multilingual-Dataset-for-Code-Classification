import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int Success = scanner.nextInt();

        int[] spells = new int[N];
        for (int i = 0; i < N; i++) {
            spells[i] = scanner.nextInt();
        }

        int[] potions = new int[M];
        for (int i = 0; i < M; i++) {
            potions[i] = scanner.nextInt();
        }

        Arrays.sort(spells);
        Arrays.sort(potions);

        int successfulPairs = 0;
        for (int spell : spells) {
            int left = 0;
            int right = M - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (spell + potions[mid] >= Success) {
                    successfulPairs += right - mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        System.out.println(successfulPairs);
    }
}
