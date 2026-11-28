import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Stack<int[]> st = new Stack<>();
            while (q-- > 0) {
                int price = scanner.nextInt();
                int span = 1;
                while (!st.isEmpty() && st.peek()[0] <= price) {
                    span += st.pop()[1];
                }
                st.push(new int[]{price, span});
                System.out.println(span);
            }
        }
    }
}