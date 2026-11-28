import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> employees = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String dept = sc.next();
            String status = sc.next();
            employees.add(new String[]{name, dept, status});
        }
        String dept = sc.next();
        for(String[] e : employees) {
            if(e[1].equals(dept) && e[2].equals("active")) System.out.println(e[0]);
        }
    }
}
