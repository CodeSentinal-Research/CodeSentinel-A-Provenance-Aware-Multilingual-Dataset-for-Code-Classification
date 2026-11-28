import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] leaves = new int[n];
        for(int i=0; i<n; i++) leaves[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        int res = 0;
        for(int leaf : leaves) {
            while(!stack.isEmpty() && stack.peek() <= leaf) {
                int mid = stack.pop();
                int minNeighbor = stack.isEmpty() ? Integer.MAX_VALUE : stack.peek();
                res += mid * Math.min(leaf, minNeighbor);
            }
            stack.push(leaf);
        }
        while(stack.size() > 1) {
            int top = stack.pop();
            res += top * stack.peek();
        }
        System.out.println(res);
    }
}
