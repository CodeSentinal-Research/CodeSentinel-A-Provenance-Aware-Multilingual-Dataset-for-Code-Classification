import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> products = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            double price = sc.nextDouble();
            products.add(new String[]{name, String.valueOf(price)});
        }
        double minP = sc.nextDouble();
        double maxP = sc.nextDouble();
        for(String[] p : products) {
            double price = Double.parseDouble(p[1]);
            if(price >= minP && price <= maxP) System.out.println(p[0]);
        }
    }
}
