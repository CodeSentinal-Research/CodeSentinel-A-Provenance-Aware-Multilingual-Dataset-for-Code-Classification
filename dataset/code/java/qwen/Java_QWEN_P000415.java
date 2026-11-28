import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> patients = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String bg = sc.next();
            patients.add(new String[]{name, bg});
        }
        String bg = sc.next();
        for(String[] p : patients) {
            if(p[1].equals(bg)) System.out.println(p[0]);
        }
    }
}
