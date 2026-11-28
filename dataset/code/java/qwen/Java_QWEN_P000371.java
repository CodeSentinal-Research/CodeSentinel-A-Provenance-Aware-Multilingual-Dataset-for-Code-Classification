import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            int id = sc.nextInt();
            String name = sc.next();
            map.put(id, name);
        }
        int searchId = sc.nextInt();
        if(map.containsKey(searchId)) System.out.println(map.get(searchId));
        else System.out.println("Record Not Found");
    }
}
