import java.util.*;

public class Solution {
    public static int shortestWay(String source, String target) {
        int i = 0, count = 0;
        while (i < target.length()) {
            int initialI = i;
            for (int j = 0; j < source.length(); j++) {
                if (i < target.length() && source.charAt(j) == target.charAt(i)) {
                    i++;
                }
            }
            if (i == initialI) return -1;
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String t = scanner.next();
            System.out.println(shortestWay(s, t));
        }
    }
}