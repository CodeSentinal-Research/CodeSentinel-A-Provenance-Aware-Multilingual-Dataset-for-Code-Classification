import java.io.*;
import java.util.*;

public class Main {
    static class Product {
        String name;
        String brand;

        Product(String name, String brand) {
            this.name = name;
            this.brand = brand;
        }

        @Override
        public String toString() {
            return "Product Name: " + name + ", Brand: " + brand;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Product> products = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            products.add(new Product(input[0], input[1]));
        }
        String brand = br.readLine();
        for (Product product : products) {
            if (product.brand.equals(brand)) {
                System.out.println(product);
            }
        }
    }
}
