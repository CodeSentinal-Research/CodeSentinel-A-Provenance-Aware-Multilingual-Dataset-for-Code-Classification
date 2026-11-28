import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(canBeSplit(input));
    }

    private static String canBeSplit(String input) {
        int length = input.length();
        int[] nums = new int[length];
        for (int i = 0; i < length; i++) {
            nums[i] = input.charAt(i) - '0';
        }
        for (int i = 0; i < length - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                return "NO";
            }
        }
        return "YES";
    }
}
