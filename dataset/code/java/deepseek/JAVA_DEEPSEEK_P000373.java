import java.io.*;
import java.util.*;

class Product {
    String productCode;
    String productName;
    double productPrice;

    Product(String productCode, String productName, double productPrice) {
        this.productCode = productCode;
        this.productName = productName;
        this.productPrice = productPrice;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        List<Product> products = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] inputs = br.readLine().trim().split(" ");
            products.add(new Product(inputs[0], inputs[1], Double.parseDouble(inputs[2])));
        }
        String productCodeToSearch = br.readLine().trim();
        boolean found = false;
        for (Product product : products) {
            if (product.productCode.equals(productCodeToSearch)) {
                System.out.println(product.productCode + " " + product.productName + " " + product.productPrice);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Product Not Found");
        }
    }
}
