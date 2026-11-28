import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Power = scanner.nextInt();
        int[] tokens = new int[N];
        for (int i = 0; i < N; i++) {
            tokens[i] = scanner.nextInt();
        }
        System.out.println(maxScore(N, Power, tokens));
    }

    public static int maxScore(int N, int Power, int[] tokens) {
        int left = 0;
        int right = N - 1;
        int score = 0;
        int maxScore = 0;
        while (left <= right) {
            if (Power >= tokens[left]) {
                score += tokens[left];
                Power -= tokens[left];
                left++;
            } else if (Power >= tokens[right]) {
                score += tokens[right];
                Power -= tokens[right];
                right--;
            } else {
                if (left == 0 || right == N - 1) {
                    break;
                }
                if (tokens[left - 1] < tokens[left + 1]) {
                    left++;
                } else {
                    right--;
                }
            }
            maxScore = Math.max(maxScore, score);
        }
        return maxScore;
    }
}
