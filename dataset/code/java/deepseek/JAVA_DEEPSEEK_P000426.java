import java.io.*;
import java.util.*;

public class Main {
    static class Restaurant {
        String name;
        int rating;

        Restaurant(String name, int rating) {
            this.name = name;
            this.rating = rating;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Restaurant> restaurants = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            String name = input[0];
            int rating = Integer.parseInt(input[1]);
            restaurants.add(new Restaurant(name, rating));
        }
        int minRating = Integer.parseInt(br.readLine());
        for (Restaurant restaurant : restaurants) {
            if (restaurant.rating >= minRating) {
                System.out.println(restaurant.name);
            }
        }
    }
}
