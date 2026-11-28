public class Solution {
    private int check(int x, int[] tops, int[] bottoms) {
        int rotA = 0, rotB = 0;
        for (int i = 0; i < tops.length; i++) {
            if (tops[i] != x && bottoms[i] != x) return -1;
            else if (tops[i] != x) rotA++;
            else if (bottoms[i] != x) rotB++;
        }
        return Math.min(rotA, rotB);
    }

    public int minDominoRotations(int[] tops, int[] bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1 || tops[0] == bottoms[0]) return rotations;
        return check(bottoms[0], tops, bottoms);
    }
}