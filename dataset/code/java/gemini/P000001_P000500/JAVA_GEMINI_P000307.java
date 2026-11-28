import java.util.*;

public class Solution {
    private static boolean isValid(String s) {
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
            Set<String> visited = new HashSet<>();
            Queue<String> queue = new LinkedList<>();
            List<String> res = new ArrayList<>();
            queue.add(s);
            visited.add(s);
            boolean found = false;
            while (!queue.isEmpty()) {
                int sz = queue.size();
                for (int i = 0; i < sz; i++) {
                    String curr = queue.poll();
                    if (isValid(curr)) {
                        res.add(curr);
                        found = true;
                    }
                    if (!found) {
                        for (int j = 0; j < curr.length(); j++) {
                            if (curr.charAt(j) == '(' || curr.charAt(j) == ')') {
                                String nextStr = curr.substring(0, j) + curr.substring(j + 1);
                                if (!visited.contains(nextStr)) {
                                    visited.add(nextStr);
                                    queue.add(nextStr);
                                }
                            }
                        }
                    }
                }
                if (found) break;
            }
            for (String str : res) {
                System.out.println(str);
            }
        }
    }
}