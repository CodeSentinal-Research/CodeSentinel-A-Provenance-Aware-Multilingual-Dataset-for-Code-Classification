import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        generateCombinations(n, k, 1, new int[k]);
    }

    private static void generateCombinations(int n, int k, int start, int[] combination) {
        if (k == 0) {
            for (int i : combination) {
                System.out.println(i);
            }
            return;
        }
        for (int i = start; i <= n - k + 1; i++) {
            combination[combination.length - k] = i;
            generateCombinations(n, k - 1, i + 1, combination);
        }
    }
}
