import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        int k = scanner.nextInt();
        System.out.println(maxConsecutiveChars(input, k));
    }

    public static int maxConsecutiveChars(String s, int k) {
        int max = 0;
        int count = 1;
        char last = s.charAt(0);

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == last) {
                count++;
            } else {
                if (count <= k) {
                    max = Math.max(max, count);
                }
                last = s.charAt(i);
                count = 1;
            }
        }

        if (count <= k) {
            max = Math.max(max, count);
        }

        return max;
    }
}
