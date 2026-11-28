import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> doctors = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String spec = sc.next();
            doctors.add(new String[]{name, spec});
        }
        String searchSpec = sc.next();
        for(String[] d : doctors) {
            if(d[1].equals(searchSpec)) System.out.println(d[0]);
        }
    }
}
