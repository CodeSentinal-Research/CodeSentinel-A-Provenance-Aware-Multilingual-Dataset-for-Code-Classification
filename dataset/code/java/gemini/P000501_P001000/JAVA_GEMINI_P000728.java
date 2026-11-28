import java.util.*;
public class Solution {
    static boolean isValid(String s) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') cnt++;
            else if (c == ')') {
                cnt--;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Set<String> level = new HashSet<>();
            level.add(s);
            while (!level.isEmpty()) {
                List<String> valid = new ArrayList<>();
                for (String item : level) {
                    if (isValid(item)) valid.add(item);
                }
                if (!valid.isEmpty()) {
                    Collections.sort(valid);
                    for (String ans : valid) System.out.println(ans);
                    return;
                }
                Set<String> nextLevel = new HashSet<>();
                for (String item : level) {
                    for (int i = 0; i < item.length(); i++) {
                        char c = item.charAt(i);
                        if (c == '(' || c == ')') {
                            nextLevel.add(item.substring(0, i) + item.substring(i + 1));
                        }
                    }
                }
                level = nextLevel;
            }
        }
    }
}