import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        long[] prefixSum = new long[s.length()];
        long sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += s.charAt(i) - 'a' + 1;
            prefixSum[i] = sum;
        }
        for (long val : prefixSum) {
            System.out.print(val + " ");
        }
    }
}
