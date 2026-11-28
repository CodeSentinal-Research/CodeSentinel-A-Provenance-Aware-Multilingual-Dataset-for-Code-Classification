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

        @Override
        public String toString() {
            return "Product{name=" + name + ", price=" + price + "}";
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Product> products = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ", 2);
            products.add(new Product(parts[1], Double.parseDouble(parts[0])));
        }
        String suffix = br.readLine();
        for (Product product : products) {
            if (product.name.endsWith(suffix)) {
                System.out.println(product);
            }
        }
    }
}
