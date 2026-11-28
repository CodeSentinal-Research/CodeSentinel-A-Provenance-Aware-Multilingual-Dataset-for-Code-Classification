import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static class Item {
        double value;
        double weight;

        Item(double value, double weight) {
            this.value = value;
            this.weight = weight;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int W = scanner.nextInt();
        ArrayList<Item> items = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            items.add(new Item(scanner.nextDouble(), scanner.nextDouble()));
        }
        scanner.close();

        double result = getMaxValue(items, W);
        System.out.printf("%.2f", result);
    }

    private static double getMaxValue(ArrayList<Item> items, int W) {
        double result = 0.0;
        Collections.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                return Double.compare(b.value, a.value);
            }
        });
        for (Item item : items) {
            if (item.weight <= W) {
                result += item.value;
                W -= item.weight;
            } else if (W > 0) {
                result += item.value * (W / item.weight);
                W = 0;
            }
        }
        return result;
    }
}
