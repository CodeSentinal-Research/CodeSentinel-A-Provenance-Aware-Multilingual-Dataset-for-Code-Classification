import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();
        scanner.close();

        if (isSubsequence(s1, s2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static boolean isSubsequence(String s1, String s2) {
        int i = 0;
        int j = 0;

        while (i < s1.length() && j < s2.length()) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i++;
            }
            j++;
       }

        return i == s1.length();
    }
}
