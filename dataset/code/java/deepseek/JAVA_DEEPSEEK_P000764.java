import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        long k = scanner.nextLong();
        System.out.println(decodeAtIndex(s, k));
    }

    public static char decodeAtIndex(String s, long k) {
        long size = 0;
        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                size = size * (s.charAt(i) - '0');
            } else {
                size++;
            }
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            k = k % size;
            if (k == 0 && Character.isLetter(s.charAt(i))) {
                return s.charAt(i);
            }

            if (Character.isDigit(s.charAt(i))) {
                size = size / (s.charAt(i) - '0');
            } else {
                size--;
            }
        }

        return ' ';
    }
}