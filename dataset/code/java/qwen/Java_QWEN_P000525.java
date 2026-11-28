import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] maxHeights = new int[n];
        for(int i=0; i<n; i++) maxHeights[i] = sc.nextInt();
        
        long[] prefix = new long[n];
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<n; i++) {
            while(!stack.isEmpty() && maxHeights[stack.peek()] > maxHeights[i]) stack.pop();
            if(stack.isEmpty()) {
                prefix[i] = (long)maxHeights[i] * (i + 1);
            } else {
                prefix[i] = prefix[stack.peek()] + (long)maxHeights[i] * (i - stack.peek());
            }
            stack.push(i);
        }
        
        long[] suffix = new long[n];
        stack.clear();
        for(int i=n-1; i>=0; i--) {
            while(!stack.isEmpty() && maxHeights[stack.peek()] > maxHeights[i]) stack.pop();
            if(stack.isEmpty()) {
                suffix[i] = (long)maxHeights[i] * (n - i);
            } else {
                suffix[i] = suffix[stack.peek()] + (long)maxHeights[i] * (stack.peek() - i);
            }
            stack.push(i);
        }
        
        long maxSum = 0;
        for(int i=0; i<n; i++) {
            maxSum = Math.max(maxSum, prefix[i] + suffix[i] - maxHeights[i]);
        }
        System.out.println(maxSum);
    }
}
