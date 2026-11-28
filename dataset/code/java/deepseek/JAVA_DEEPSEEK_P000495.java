import java.util.Stack;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        calculateSpan(prices, n);
    }

    public static void calculateSpan(int price[], int n) {
        int S[] = new int[n];
        Stack<Integer> st = new Stack<>();
        st.push(0);
        S[0] = 1;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && price[st.peek()] <= price[i]) {
                st.pop();
            }
            S[i] = (st.empty()) ? (i + 1) : (i - st.peek());
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            System.out.println(S[i]);
        }
    }
}
