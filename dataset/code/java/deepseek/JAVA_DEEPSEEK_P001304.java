import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int R = scanner.nextInt();
        int[] horizontalCuts = new int[R - 1];
        for (int i = 0; i < R - 1; i++) {
            horizontalCuts[i] = scanner.nextInt();
        }

        int C = scanner.nextInt();
        int[] verticalCuts = new int[C - 1];
        for (int i = 0; i < C - 1; i++) {
            verticalCuts[i] = scanner.nextInt();
        }

        int minHorizontalCost = Integer.MAX_VALUE;
        int minVerticalCost = Integer.MAX_VALUE;

        for (int i = 0; i < R - 1; i++) {
            minHorizontalCost = Math.min(minHorizontalCost, horizontalCuts[i]);
        }

        for (int i = 0; i < C - 1; i++) {
            minVerticalCost = Math.min(minVerticalCost, verticalCuts[i]);
        }

        int totalCost = minHorizontalCost + minVerticalCost;

        System.out.println(totalCost);
    }
}
