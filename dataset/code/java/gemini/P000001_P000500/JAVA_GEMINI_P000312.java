import java.util.*;

public class Solution {
    public static int compareVersion(String v1, String v2) {
        String[] p1 = v1.split("\\.");
        String[] p2 = v2.split("\\.");
        int maxLen = Math.max(p1.length, p2.length);
        for (int i = 0; i < maxLen; i++) {
            int num1 = i < p1.length ? Integer.parseInt(p1[i]) : 0;
            int num2 = i < p2.length ? Integer.parseInt(p2[i]) : 0;
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String v1 = scanner.next();
            String v2 = scanner.next();
            System.out.println(compareVersion(v1, v2));
        }
    }
}