import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String mobile = sc.next();
            String name = sc.next();
            map.put(mobile, name);
        }
        String searchMobile = sc.next();
        if(map.containsKey(searchMobile)) System.out.println(map.get(searchMobile));
        else System.out.println("Customer Not Found");
    }
}
