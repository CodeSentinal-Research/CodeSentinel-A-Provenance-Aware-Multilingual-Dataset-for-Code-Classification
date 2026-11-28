import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        Item[] items = new Item[n];
        for(int i=0; i<n; i++) {
            items[i] = new Item(sc.nextInt(), sc.nextInt());
        }
        
        Arrays.sort(items, (a, b) -> Double.compare(b.value/b.weight, a.value/a.weight));
        
        double totalValue = 0;
        int remaining = w;
        for(Item item : items) {
            if(remaining == 0) break;
            if(item.weight <= remaining) {
                totalValue += item.value;
                remaining -= item.weight;
            } else {
                totalValue += item.value * ((double)remaining / item.weight);
                remaining = 0;
            }
        }
        System.out.printf("%.2f
", totalValue);
    }
}
class Item {
    int weight, value;
    Item(int w, int v) { weight = w; value = v; }
}
