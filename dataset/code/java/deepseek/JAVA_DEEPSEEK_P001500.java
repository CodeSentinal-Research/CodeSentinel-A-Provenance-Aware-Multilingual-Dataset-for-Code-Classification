import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(canBePalindrome(s) ? "YES" : "NO");
    }

    private static boolean canBePalindrome(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        int oddCount = 0;
        for (int cnt : count) {
            if (cnt % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }
}
