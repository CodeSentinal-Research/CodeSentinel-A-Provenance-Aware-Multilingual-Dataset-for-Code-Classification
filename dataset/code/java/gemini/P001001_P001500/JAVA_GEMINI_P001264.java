import java.util.Arrays;

public class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> (b[1] - b[0]) - (a[1] - a[0]));
        int curEnergy = 0, reqEnergy = 0;

        for (int[] task : tasks) {
            int actual = task[0], min = task[1];
            if (curEnergy < min) {
                reqEnergy += min - curEnergy;
                curEnergy = min;
            }
            curEnergy -= actual;
        }
        return reqEnergy;
    }
}