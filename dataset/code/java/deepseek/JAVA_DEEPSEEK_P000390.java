import java.util.*;

public class Main {
    public static class Product {
        String name;
        double price;

        public Product(String name, double price) {
            this.name = name;
            this.price = price;
        }

        @Override
        public String toString() {
            return "Product{" +
                    "name='" + name + '\'' +
                    ", price=" + price +
                    '}';
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<Product> products = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            double price = scanner.nextDouble();
            products.add(new Product(name, price));
        }

        double minPrice = scanner.nextDouble();
        double maxPrice = scanner.nextDouble();

        for (Product product : products) {
            if (product.price >= minPrice && product.price <= maxPrice) {
                System.out.println(product);
            }
        }
    }
}
