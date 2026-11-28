import java.util.*;

public class Main {
    public static int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        Deque<Integer> stack = new ArrayDeque<>();
        int prevTime = 0;
        for (String log : logs) {
            String[] parts = log.split(":");
            int id = Integer.parseInt(parts[0]);
            int time = Integer.parseInt(parts[2]);
            if (!stack.isEmpty()) {
                res[stack.peek()] += time - prevTime;
            }
            prevTime = time;
            if ("start".equals(parts[1])) {
                stack.push(id);
            } else {
                res[stack.pop()]++;
                prevTime++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        List<String> logs = Arrays.asList("0:start:0", "1:start:2", "1:end:5", "0:end:6");
        int[] res = exclusiveTime(2, logs);
        for (int time : res) {
            System.out.print(time + " ");
        }
    }
}
