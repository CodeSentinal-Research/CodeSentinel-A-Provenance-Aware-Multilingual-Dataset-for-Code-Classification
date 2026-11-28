import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] asteroids = new int[n];
        for(int i=0; i<n; i++) asteroids[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        for(int ast : asteroids) {
            if(ast > 0) stack.push(ast);
            else {
                while(!stack.isEmpty() && stack.peek() > 0 && stack.peek() < -ast) {
                    stack.pop();
                }
                if(stack.isEmpty() || stack.peek() < 0) stack.push(ast);
                else if(stack.peek() == -ast) stack.pop();
            }
        }
        int[] res = new int[stack.size()];
        for(int i=res.length-1; i>=0; i--) res[i] = stack.pop();
        for(int x : res) System.out.print(x + " ");
    }
}
