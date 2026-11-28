import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();
        for(int i=2*n-1; i>=0; i--) {
            while(!stack.isEmpty() && stack.peek() <= nums[i%n]) stack.pop();
            if(i < n) res[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(nums[i%n]);
        }
        for(int x : res) System.out.print(x + " ");
    }
}
