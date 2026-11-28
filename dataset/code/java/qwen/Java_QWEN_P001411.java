import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int[][] matches = new int[m][2];
        for(int i=0; i<m; i++) {
            matches[i][0] = sc.nextInt();
            matches[i][1] = sc.nextInt();
        }
        
        Set<Integer> players = new HashSet<>();
        Map<Integer, Integer> losses = new HashMap<>();
        
        for(int[] match : matches) {
            players.add(match[0]);
            players.add(match[1]);
            losses.put(match[1], losses.getOrDefault(match[1], 0) + 1);
        }
        
        List<Integer> zeroLoss = new ArrayList<>();
        List<Integer> oneLoss = new ArrayList<>();
        
        for(int p : players) {
            int l = losses.getOrDefault(p, 0);
            if(l == 0) zeroLoss.add(p);
            else if(l == 1) oneLoss.add(p);
        }
        
        Collections.sort(zeroLoss);
        Collections.sort(oneLoss);
        
        System.out.println(zeroLoss);
        System.out.println(oneLoss);
    }
}
