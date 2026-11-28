import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(minLength(s));
    }

    public static int minLength(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right && s.charAt(left) == s.charAt(right)) {
            char c = s.charAt(left);
            while (left < right && s.charAt(left) == c) {
                left++;
            }
            while (left < right && s.charAt(right) == c) {
                right--;
            }
        }
        return right - left + 1;
    }
}
