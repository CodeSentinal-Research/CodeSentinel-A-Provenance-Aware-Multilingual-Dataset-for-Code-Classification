import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for(int i=0; i<n; i++) heights[i] = sc.nextInt();
        
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();
        for(int i=n-1; i>=0; i--) {
            int count = 0;
            while(!stack.isEmpty() && heights[stack.peek()] < heights[i]) {
                stack.pop();
                count++;
            }
            if(!stack.isEmpty()) count++;
            res[i] = count;
            stack.push(i);
        }
        for(int x : res) System.out.print(x + " ");
    }
}
