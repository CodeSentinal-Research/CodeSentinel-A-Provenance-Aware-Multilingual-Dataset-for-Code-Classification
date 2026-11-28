import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0; i<n; i++) {
            String roomId = sc.next();
            String status = sc.next();
            if(status.equals("available")) System.out.println(roomId);
        }
    }
}
