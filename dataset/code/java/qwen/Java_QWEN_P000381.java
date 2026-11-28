import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String phone = sc.next();
            map.put(name, phone);
        }
        String searchName = sc.next();
        if(map.containsKey(searchName)) System.out.println(map.get(searchName));
        else System.out.println("Contact Not Found");
    }
}
