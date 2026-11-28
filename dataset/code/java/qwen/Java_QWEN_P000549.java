import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] input = new int[n];
        for(int i=0; i<n; i++) input[i] = sc.nextInt();
        int[] output = new int[n];
        for(int i=0; i<n; i++) output[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        int j = 0;
        for(int x : input) {
            stack.push(x);
            while(!stack.isEmpty() && j < n && stack.peek() == output[j]) {
                stack.pop();
                j++;
            }
        }
        System.out.println(stack.isEmpty() ? "true" : "false");
    }
}
