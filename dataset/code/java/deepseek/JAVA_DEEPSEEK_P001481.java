import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int limit = scanner.nextInt();
        int[] weights = new int[N];
        for (int i = 0; i < N; i++) {
            weights[i] = scanner.nextInt();
        }
        Arrays.sort(weights);
        int left = 0;
        int right = N - 1;
        int boats = 0;
        while (left <= right) {
            if (weights[left] + weights[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            boats++;
        }
        System.out.println(boats);
    }
}
