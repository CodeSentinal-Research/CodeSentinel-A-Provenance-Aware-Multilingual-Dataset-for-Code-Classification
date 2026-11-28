import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                int ast = scanner.nextInt();
                boolean alive = true;
                while (alive && ast < 0 && !st.isEmpty() && st.peek() > 0) {
                    if (st.peek() < -ast) {
                        st.pop();
                    } else if (st.peek() == -ast) {
                        st.pop();
                        alive = false;
                    } else {
                        alive = false;
                    }
                }
                if (alive) st.push(ast);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < st.size(); i++) {
                sb.append(st.get(i)).append(i + 1 == st.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}