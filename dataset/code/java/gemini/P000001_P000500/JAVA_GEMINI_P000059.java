import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            long prod = 1;
            for (char c : s.toCharArray()) {
                if (Character.isDigit(c)) prod *= (c - '0');
            }
            System.out.println(prod);
        }
    }
}