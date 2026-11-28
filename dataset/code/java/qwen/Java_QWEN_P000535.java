import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] deck = new int[n];
        for(int i=0; i<n; i++) deck[i] = sc.nextInt();
        Arrays.sort(deck);
        
        int[] res = new int[n];
        Queue<Integer> indices = new LinkedList<>();
        for(int i=0; i<n; i++) indices.offer(i);
        
        for(int card : deck) {
            res[indices.poll()] = card;
            if(!indices.isEmpty()) indices.offer(indices.poll());
        }
        for(int x : res) System.out.print(x + " ");
    }
}
