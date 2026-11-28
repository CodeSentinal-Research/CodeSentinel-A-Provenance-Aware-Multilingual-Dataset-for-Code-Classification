import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> flights = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String no = sc.next();
            String dest = sc.next();
            flights.add(new String[]{no, dest});
        }
        String searchDest = sc.next();
        for(String[] f : flights) {
            if(f[1].equals(searchDest)) System.out.println(f[0]);
        }
    }
}
