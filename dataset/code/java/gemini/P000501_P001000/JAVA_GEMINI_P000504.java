import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), m = scanner.nextInt();
            int[] res = new int[n];
            Stack<Integer> st = new Stack<>();
            int prevTime = 0;
            for (int i = 0; i < m; i++) {
                String[] parts = scanner.next().split(":");
                int fid = Integer.parseInt(parts[0]);
                String typ = parts[1];
                int time = Integer.parseInt(parts[2]);
                if (typ.equals("start")) {
                    if (!st.isEmpty()) res[st.peek()] += time - prevTime;
                    st.push(fid);
                    prevTime = time;
                } else {
                    res[st.pop()] += time - prevTime + 1;
                    prevTime = time + 1;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(res[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}