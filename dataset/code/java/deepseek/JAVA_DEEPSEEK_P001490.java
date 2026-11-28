import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String binaryString = scanner.nextLine();
        System.out.println(countBinarySubstrings(binaryString));
    }

    public static int countBinarySubstrings(String s) {
        int prev = 0, curr = 1, count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                curr++;
            } else {
                count += Math.min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        count += Math.min(prev, curr);
        return count;
    }
}
