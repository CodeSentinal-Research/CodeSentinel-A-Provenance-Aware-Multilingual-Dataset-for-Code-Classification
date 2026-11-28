import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        System.out.println(removeDuplicates(input));
    }

    public static String removeDuplicates(String s) {
        StringBuilder sb = new StringBuilder();
        char last = '\0';
        for (char c : s.toCharArray()) {
            if (c != last) {
                sb.append(c);
                last = c;
            }
        }
        String result = sb.toString();
        if (result.equals(s)) {
            return result;
        } else {
            return removeDuplicates(result);
        }
    }
}
