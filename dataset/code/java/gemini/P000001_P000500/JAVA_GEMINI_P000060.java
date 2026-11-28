import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int count = 0;
            for (char c : s.toCharArray()) {
                if (Character.isDigit(c) && (c - '0') % 2 == 0) count++;
            }
            System.out.println(count);
        }
    }
}