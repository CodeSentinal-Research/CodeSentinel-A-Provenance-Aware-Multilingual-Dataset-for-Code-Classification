import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String t = scanner.hasNext() ? scanner.next() : "";
            char res = 0;
            for (char c : s.toCharArray()) res ^= c;
            for (char c : t.toCharArray()) res ^= c;
            System.out.println(res);
        }
    }
}