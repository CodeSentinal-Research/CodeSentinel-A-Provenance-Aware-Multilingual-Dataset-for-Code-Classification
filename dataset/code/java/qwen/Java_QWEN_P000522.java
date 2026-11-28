import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String homepage = sc.next();
        int q = sc.nextInt();
        
        Stack<String> backStack = new Stack<>();
        Stack<String> forwardStack = new Stack<>();
        String current = homepage;
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("visit")) {
                String url = sc.next();
                backStack.push(current);
                current = url;
                forwardStack.clear();
            } else if(op.equals("back")) {
                int steps = sc.nextInt();
                while(steps > 0 && !backStack.isEmpty()) {
                    forwardStack.push(current);
                    current = backStack.pop();
                    steps--;
                }
                System.out.println(current);
            } else if(op.equals("forward")) {
                int steps = sc.nextInt();
                while(steps > 0 && !forwardStack.isEmpty()) {
                    backStack.push(current);
                    current = forwardStack.pop();
                    steps--;
                }
                System.out.println(current);
            }
        }
    }
}
