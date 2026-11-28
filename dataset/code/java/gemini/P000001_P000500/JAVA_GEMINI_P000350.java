import java.util.*;

public class Solution {
    static class Node {
        char c;
        int count;
        Node(char c, int count) { this.c = c; this.count = count; }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int k = scanner.nextInt();
            Deque<Node> stack = new ArrayDeque<>();
            for (char c : s.toCharArray()) {
                if (!stack.isEmpty() && stack.peek().c == c) {
                    stack.peek().count++;
                    if (stack.peek().count == k) stack.pop();
                } else {
                    stack.push(new Node(c, 1));
                }
            }
            List<Node> list = new ArrayList<>(stack);
            Collections.reverse(list);
            StringBuilder sb = new StringBuilder();
            for (Node n : list) {
                for (int i = 0; i < n.count; i++) sb.append(n.c);
            }
            System.out.println(sb.toString());
        }
    }
}