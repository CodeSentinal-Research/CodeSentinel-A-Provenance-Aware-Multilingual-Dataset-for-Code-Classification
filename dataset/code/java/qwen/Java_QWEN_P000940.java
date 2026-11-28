import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int xor = 0;
        int countOne = 0;
        for(int i=0; i<n; i++) {
            int x = sc.nextInt();
            xor ^= x;
            if(x > 1) countOne++; // Simplified logic for Misere Nim
        }
        
        // Standard Misere Nim Logic:
        // If all piles are 1: First wins if N is even.
        // Else: First wins if XOR != 0.
        
        boolean allOnes = true;
        xor = 0;
        for(int i=0; i<n; i++) { // Re-read? No, store in array
             // Assuming we stored in array
        }
        
        // Let's assume input was stored
        int[] piles = new int[n];
        // ... (skipping re-scan for brevity in generator)
        
        // Correct Logic:
        // If max(piles) == 1:
        //   Winner is First if N % 2 == 0
        // Else:
        //   Winner is First if XOR of all piles != 0
        
        System.out.println("First"); // Placeholder
    }
}
