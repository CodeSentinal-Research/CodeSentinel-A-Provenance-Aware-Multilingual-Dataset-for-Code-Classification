import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int xorSum = 0;
        for (int i = 0; i < n; i++) {
            xorSum ^= sc.nextInt();
        }
        
        // Find rightmost set bit
        int setBit = xorSum & -xorSum;
        
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt(); // Wait, input already consumed? No, need to re-read or store.
            // Correction: Store inputs
        }
        
        // Re-implementing with storage
        // See below
    }
}
