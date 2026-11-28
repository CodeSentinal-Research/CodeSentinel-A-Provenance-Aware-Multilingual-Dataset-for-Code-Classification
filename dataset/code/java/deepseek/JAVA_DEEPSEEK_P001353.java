import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        int k = scanner.nextInt();
        long result = countSplits(input, k);
        System.out.println(result);
    }

    private static long countSplits(String input, int k) {
        long count = 0;
        long currentNumber = 0;
        for (char c : input.toCharArray()) {
            currentNumber = currentNumber * 10 + (c - '0');
            if (currentNumber < k) {
                count += currentNumber;
            } else {
                count += k;
                currentNumber -= k;
            }
        }
        return count;
    }
}
