import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> employees = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String date = sc.next();
            employees.add(new String[]{name, date});
        }
        String cutoff = sc.next();
        for(String[] e : employees) {
            if(e[1].compareTo(cutoff) < 0) System.out.println(e[0]);
        }
    }
}
