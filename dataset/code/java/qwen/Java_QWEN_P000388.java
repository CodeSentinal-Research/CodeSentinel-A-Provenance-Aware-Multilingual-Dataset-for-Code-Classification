import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String passport = sc.next();
            String name = sc.next();
            map.put(passport, name);
        }
        String searchPassport = sc.next();
        if(map.containsKey(searchPassport)) System.out.println(map.get(searchPassport));
        else System.out.println("Passport Not Found");
    }
}
