import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for(int i=0; i<n; i++) heights[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        for(int i=0; i<=n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while(!stack.isEmpty() && h < heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, height * width);
            }
            stack.push(i);
        }
        System.out.println(maxArea);
    }
}
