import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (s.lastIndexOf(c) > end) {
                end = s.lastIndexOf(c);
            }
            if (i == end) {
                System.out.println(end - start + 1);
                start = end + 1;
            }
        }
    }
}
