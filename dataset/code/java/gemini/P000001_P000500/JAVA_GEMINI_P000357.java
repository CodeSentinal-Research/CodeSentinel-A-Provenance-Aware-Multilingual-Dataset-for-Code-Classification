import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            char c = scanner.next().charAt(0);
            int count = 0;
            for (int i = 0; i < s.length(); i++) if (s.charAt(i) == c) count++;
            System.out.println(count);
        }
    }
}