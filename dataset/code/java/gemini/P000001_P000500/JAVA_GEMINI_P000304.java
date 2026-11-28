import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String path = scanner.next();
            String[] parts = path.split("/");
            Deque<String> stack = new ArrayDeque<>();
            for (String p : parts) {
                if (p.isEmpty() || p.equals(".")) continue;
                if (p.equals("..")) {
                    if (!stack.isEmpty()) stack.pop();
                } else {
                    stack.push(p);
                }
            }
            List<String> list = new ArrayList<>(stack);
            Collections.reverse(list);
            StringBuilder sb = new StringBuilder();
            for (String s : list) {
                sb.append("/").append(s);
            }
            System.out.println(sb.length() == 0 ? "/" : sb.toString());
        }
    }
}