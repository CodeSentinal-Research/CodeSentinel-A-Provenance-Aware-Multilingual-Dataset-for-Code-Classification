import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int threshold = scanner.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
       }
        System.out.println(findSmallestDivisor(numbers, threshold));
    }

    private static int findSmallestDivisor(int[] numbers, int threshold) {
        int max = Arrays.stream(numbers).max().getAsInt();
        for (int i = 1; i <= max; i++) {
            int sum = 0;
            for (int number : numbers) {
                sum += number / i;
            }
            if (sum <= threshold) {
                return i;
            }
        }
        return max;
    }
}
