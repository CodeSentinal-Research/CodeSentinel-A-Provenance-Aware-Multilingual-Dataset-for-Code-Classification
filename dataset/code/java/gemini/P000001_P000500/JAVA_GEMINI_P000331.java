import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] res = new int[n];
            Deque<Integer> stack = new ArrayDeque<>();
            int prevTime = 0;
            while (scanner.hasNext()) {
                String log = scanner.next();
                String[] parts = log.split(":");
                int fnId = Integer.parseInt(parts[0]);
                String action = parts[1];
                int timestamp = Integer.parseInt(parts[2]);
                if (action.equals("start")) {
                    if (!stack.isEmpty()) {
                        res[stack.peek()] += timestamp - prevTime;
                    }
                    stack.push(fnId);
                    prevTime = timestamp;
                } else {
                    res[stack.pop()] += timestamp - prevTime + 1;
                    prevTime = timestamp + 1;
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.print(res[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
    }
}