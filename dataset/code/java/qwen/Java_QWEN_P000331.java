import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] logs = new String[m];
        sc.nextLine(); 
        for(int i=0; i<m; i++) logs[i] = sc.nextLine();
        
        int[] res = new int[n];
        Stack<int[]> stack = new Stack<>();
        for (String log : logs) {
            String[] parts = log.split(":");
            int id = Integer.parseInt(parts[0]);
            boolean isStart = parts[1].equals("start");
            int time = Integer.parseInt(parts[2]);
            
            if (isStart) {
                if (!stack.isEmpty()) {
                    res[stack.peek()[0]] += time - stack.peek()[1];
                }
                stack.push(new int[]{id, time});
            } else {
                int[] top = stack.pop();
                res[top[0]] += time - top[1] + 1;
                if (!stack.isEmpty()) {
                    stack.peek()[1] = time + 1;
                }
            }
        }
        for (int x : res) System.out.print(x + " ");
    }
}
