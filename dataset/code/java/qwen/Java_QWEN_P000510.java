import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prices = new int[n];
        for(int i=0; i<n; i++) prices[i] = sc.nextInt();
        
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<n; i++) {
            while(!stack.isEmpty() && prices[stack.peek()] >= prices[i]) {
                res[stack.pop()] -= prices[i];
            }
            stack.push(i);
            res[i] = prices[i];
        }
        for(int x : res) System.out.print(x + " ");
    }
}
