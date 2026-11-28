import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        System.out.println(maximumScore(A, B, C));
    }

    public static int maximumScore(int A, int B, int C) {
        int max = Math.max(A, B);
        int maxAB = Math.max(max, C);
        int sum = A + B + C;
        int sumAB = A + B;
        int sumAC = A + C;
        int sumBC = B + C;
        int score = sum - maxAB;
        if (maxAB == max) {
            score += Math.max(sumAB - max, sumAC - maxAB);
        } else if (maxAB == sumAB) {
            score += Math.max(sumAB - max, sumBC - maxAB);
        } else {
            score += Math.max(sumAC - max, sumBC - maxAB);
        }
        return score;
    }
}
