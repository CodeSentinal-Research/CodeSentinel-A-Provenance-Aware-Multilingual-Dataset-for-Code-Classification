import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> trains = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String no = sc.next();
            String station = sc.next();
            trains.add(new String[]{no, station});
        }
        String searchStation = sc.next();
        for(String[] t : trains) {
            if(t[1].equals(searchStation)) System.out.println(t[0]);
        }
    }
}
