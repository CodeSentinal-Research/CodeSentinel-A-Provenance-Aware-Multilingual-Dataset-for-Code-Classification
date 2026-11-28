import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            int invNo = sc.nextInt();
            String desc = sc.next();
            map.put(invNo, desc);
        }
        int searchInv = sc.nextInt();
        if(map.containsKey(searchInv)) System.out.println(map.get(searchInv));
        else System.out.println("Invoice Not Found");
    }
}
