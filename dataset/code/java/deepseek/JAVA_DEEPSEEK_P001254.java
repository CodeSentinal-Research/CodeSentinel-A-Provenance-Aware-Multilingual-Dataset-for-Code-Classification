import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] numbers = new long[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextLong();
        }
        scanner.close();
        Arrays.sort(numbers);
        StringBuilder sb = new StringBuilder();
        for (long number : numbers) {
            sb.append(number);
        }
        System.out.println(sb.toString());
    }
}
