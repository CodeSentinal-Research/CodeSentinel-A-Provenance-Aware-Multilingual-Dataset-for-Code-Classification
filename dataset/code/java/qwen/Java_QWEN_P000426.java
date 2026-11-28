import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> restaurants = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            double rating = sc.nextDouble();
            restaurants.add(new String[]{name, String.valueOf(rating)});
        }
        double minRating = sc.nextDouble();
        for(String[] r : restaurants) {
            if(Double.parseDouble(r[1]) >= minRating) System.out.println(r[0]);
        }
    }
}
