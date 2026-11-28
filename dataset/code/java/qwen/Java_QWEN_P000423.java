import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> orders = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String id = sc.next();
            String status = sc.next();
            int days = sc.nextInt();
            orders.add(new String[]{id, status, String.valueOf(days)});
        }
        int nDays = sc.nextInt();
        for(String[] o : orders) {
            if(o[1].equals("pending") && Integer.parseInt(o[2]) > nDays)
                System.out.println(o[0]);
        }
    }
}
