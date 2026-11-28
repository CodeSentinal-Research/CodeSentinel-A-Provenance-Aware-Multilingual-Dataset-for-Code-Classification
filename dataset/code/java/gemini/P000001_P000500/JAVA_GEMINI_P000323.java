import java.util.*;

public class Solution {
    public static boolean checkRecord(String s) {
        int aCount = 0;
        for (char c : s.toCharArray()) {
            if (c == 'A') {
                aCount++;
                if (aCount >= 2) return false;
            }
        }
        return !s.contains("LLL");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(checkRecord(scanner.next()) ? "Yes" : "No");
        }
    }
}