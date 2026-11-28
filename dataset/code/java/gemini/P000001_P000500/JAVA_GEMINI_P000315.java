import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            long res = 0;
            for (char c : s.toCharArray()) {
                res = res * 26 + (c - 'A' + 1);
            }
            System.out.println(res);
        }
    }
}