import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String code = sc.next();
            String name = sc.next();
            map.put(code, name);
        }
        String searchCode = sc.next();
        if(map.containsKey(searchCode)) System.out.println(map.get(searchCode));
        else System.out.println("Product Not Found");
    }
}
