import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ratings = new int[n];
        for(int i=0; i<n; i++) ratings[i] = sc.nextInt();
        
        int[] candies = new int[n];
        Arrays.fill(candies, 1);
        
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        }
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) candies[i] = Math.max(candies[i], candies[i+1] + 1);
        }
        
        long sum = 0;
        for(int c : candies) sum += c;
        System.out.println(sum);
    }
}
