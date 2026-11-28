import java.io.*;
import java.util.*;

public class Main {
    static class Product {
        String name;
        double price;

        Product(String name, double price) {
            this.name = name;
            this.price = price;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        List<Product> products = new ArrayList<>();

        while ((line = br.readLine()) != null && !line.isEmpty()) {
            String[] parts = line.split(" ");
            String name = parts[0];
            double price = Double.parseDouble(parts[1]);
            products.add(new Product(name, price));
        }

        double minPrice = Double.parseDouble(br.readLine());

        for (Product product : products) {
            if (product.price >= minPrice) {
                System.out.println(product.name);
            }
        }
    }
}
