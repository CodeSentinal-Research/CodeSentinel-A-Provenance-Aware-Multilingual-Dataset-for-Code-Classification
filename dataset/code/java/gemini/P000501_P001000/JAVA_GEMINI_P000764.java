import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            long k = scanner.nextLong();
            long size = 0;
            for (char c : s.toCharArray()) {
                if (Character.isDigit(c)) size *= (c - '0');
                else size++;
            }
            for (int i = s.length() - 1; i >= 0; i--) {
                char c = s.charAt(i);
                k %= size;
                if (k == 0 && Character.isLetter(c)) {
                    System.out.println(c);
                    return;
                }
                if (Character.isDigit(c)) size /= (c - '0');
                else size--;
            }
        }
    }
}