import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] vals = new int[n];
        for(int i=0; i<n; i++) vals[i] = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        for(int i=n-1; i>=0; i--) {
            while(!stack.isEmpty() && stack.peek() <= vals[i]) stack.pop();
            stack.push(vals[i]);
        }
        // Outputting the remaining stack in reverse order to represent the linked list
        List<Integer> res = new ArrayList<>(stack);
        Collections.reverse(res);
        for(int x : res) System.out.print(x + " ");
    }
}
