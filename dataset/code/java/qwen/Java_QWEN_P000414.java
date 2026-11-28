import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> flights = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String no = sc.next();
            double price = sc.nextDouble();
            String avail = sc.next();
            flights.add(new String[]{no, String.valueOf(price), avail});
        }
        double budget = sc.nextDouble();
        for(String[] f : flights) {
            if(Double.parseDouble(f[1]) <= budget && f[2].equals("available")) 
                System.out.println(f[0]);
        }
    }
}
