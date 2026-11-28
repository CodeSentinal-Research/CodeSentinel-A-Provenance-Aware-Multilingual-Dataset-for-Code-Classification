import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0; i<n; i++) {
            String username = sc.next();
            String status = sc.next();
            if(status.equals("active")) System.out.println(username);
        }
    }
}
