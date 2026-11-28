import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String columnTitle = scanner.next();
        System.out.println(titleToNumber(columnTitle));
    }

    public static int titleToNumber(String s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result = result * 26 + (s.charAt(i) - 'A' + 1);
       }
        return result;
    }
}
