import java.util.*;

public class Main {
    public static void main(String[] args) {
        String[] deadends = {"0201", "0101", "0102", "1212", "2002"};
        String target = "0202";
        System.out.println(openLock(deadends, target));
    }

    public static int openLock(String[] deadends, String target) {
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer("0000");
        visited.add("0000");
        int step = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String cur = queue.poll();
                if (Arrays.asList(deadends).contains(cur))
                    continue;
                if (cur.equals(target))
                    return step;
                for (int j = 0; j < 4; j++) {
                    StringBuilder sb = new StringBuilder(cur);
                    char ch = cur.charAt(j);
                    if (ch == '9') {
                        sb.setCharAt(j, '0');
                    } else {
                        sb.setCharAt(j, (char) (ch + 1));
                    }
                    String next = sb.toString();
                    if (!visited.contains(next)) {
                        queue.offer(next);
                        visited.add(next);
                    }
                    sb.setCharAt(j, (char) (ch - 1 >= 0 ? ch - 1 : 9));
                    next = sb.toString();
                    if (!visited.contains(next)) {
                        queue.offer(next);
                        visited.add(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
}
