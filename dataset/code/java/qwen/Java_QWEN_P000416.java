import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> vehicles = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String reg = sc.next();
            int year = sc.nextInt();
            vehicles.add(new String[]{reg, String.valueOf(year)});
        }
        int year = sc.nextInt();
        for(String[] v : vehicles) {
            if(Integer.parseInt(v[1]) > year) System.out.println(v[0]);
        }
    }
}
