import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Long, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            long accNo = sc.nextLong();
            String holder = sc.next();
            map.put(accNo, holder);
        }
        long searchAcc = sc.nextLong();
        if(map.containsKey(searchAcc)) System.out.println(map.get(searchAcc));
        else System.out.println("Account Not Found");
    }
}
