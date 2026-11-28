import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            int roll = sc.nextInt();
            String name = sc.next();
            map.put(roll, name);
        }
        int searchRoll = sc.nextInt();
        if(map.containsKey(searchRoll)) System.out.println(map.get(searchRoll));
        else System.out.println("Record Not Found");
    }
}
