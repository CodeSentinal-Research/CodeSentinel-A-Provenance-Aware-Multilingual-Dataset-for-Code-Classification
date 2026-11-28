import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        Stack<int[]> stack = new Stack<>();
        for(int i=0; i<q; i++) {
            int price = sc.nextInt();
            int span = 1;
            while(!stack.isEmpty() && stack.peek()[0] <= price) {
                span += stack.pop()[1];
            }
            stack.push(new int[]{price, span});
            System.out.print(span + " ");
        }
    }
}
