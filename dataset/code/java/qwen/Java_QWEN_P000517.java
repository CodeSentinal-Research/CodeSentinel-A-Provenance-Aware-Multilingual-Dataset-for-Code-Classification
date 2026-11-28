import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<n; i++) {
            while(!stack.isEmpty() && nums[stack.peek()] > nums[i]) stack.pop();
            stack.push(i);
        }
        int maxWidth = 0;
        for(int i=n-1; i>=0; i--) {
            while(!stack.isEmpty() && nums[stack.peek()] <= nums[i]) {
                maxWidth = Math.max(maxWidth, i - stack.pop());
            }
        }
        System.out.println(maxWidth);
    }
}
