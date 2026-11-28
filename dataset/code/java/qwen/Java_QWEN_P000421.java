import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> memberships = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String id = sc.next();
            String expiry = sc.next();
            memberships.add(new String[]{id, expiry});
        }
        String today = sc.next();
        for(String[] m : memberships) {
            if(m[1].compareTo(today) < 0) System.out.println(m[0]);
        }
    }
}
