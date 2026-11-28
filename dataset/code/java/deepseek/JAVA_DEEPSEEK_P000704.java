import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        generateSubsequences(s, "");
    }

    private static void generateSubsequences(String s, String current) {
        if (s.isEmpty()) {
            System.out.println(current);
        } else {
            generateSubsequences(s.substring(1), current);
            generateSubsequences(s.substring(1), current + s.charAt(0));
        }
    }
}
