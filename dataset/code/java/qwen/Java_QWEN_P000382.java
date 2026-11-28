import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String user = sc.next();
            String email = sc.next();
            map.put(user, email);
        }
        String searchUser = sc.next();
        if(map.containsKey(searchUser)) System.out.println(map.get(searchUser));
        else System.out.println("User Not Found");
    }
}
