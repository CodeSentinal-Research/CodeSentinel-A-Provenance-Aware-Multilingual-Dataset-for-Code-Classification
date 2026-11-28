import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> records = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String dept = sc.next();
            records.add(new String[]{name, dept});
        }
        String searchDept = sc.next();
        boolean found = false;
        for(String[] rec : records) {
            if(rec[1].equals(searchDept)) {
                System.out.println(rec[0]);
                found = true;
            }
        }
        if(!found) System.out.println("No Records Found");
    }
}
