import java.util.*;

public class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> losses = new HashMap<>();
        Set<Integer> players = new HashSet<>();

        for (int[] m : matches) {
            players.add(m[0]);
            players.add(m[1]);
            losses.put(m[1], losses.getOrDefault(m[1], 0) + 1);
        }

        List<Integer> zeroLoss = new ArrayList<>();
        List<Integer> oneLoss = new ArrayList<>();

        for (int p : players) {
            int l = losses.getOrDefault(p, 0);
            if (l == 0) zeroLoss.add(p);
            else if (l == 1) oneLoss.add(p);
        }

        Collections.sort(zeroLoss);
        Collections.sort(oneLoss);
        return Arrays.asList(zeroLoss, oneLoss);
    }
}