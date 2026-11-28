import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] pushed = new int[n];
        for(int i=0; i<n; i++) pushed[i] = sc.nextInt();
        int[] popped = new int[n];
        for(int i=0; i<n; i++) popped[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        int j = 0;
        for(int x : pushed) {
            stack.push(x);
            while(!stack.isEmpty() && j < n && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }
        System.out.println(stack.isEmpty() ? "true" : "false");
    }
}
