import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int depth = 0;
        for(int i=0; i<n; i++) {
            String op = sc.next();
            if(op.equals("../")) {
                if(depth > 0) depth--;
            } else if(!op.equals("./")) {
                depth++;
            }
        }
        System.out.println(depth);
    }
}
