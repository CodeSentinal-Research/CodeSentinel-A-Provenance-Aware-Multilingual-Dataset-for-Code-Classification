import java.util.TreeMap;

public class Main {
    TreeMap<Integer, Integer> tree;

    public Main() {
        tree = new TreeMap<>();
    }

    public void addNum(int val) {
        Integer floorKey = tree.floorKey(val);
        Integer ceilingKey = tree.ceilingKey(val);

        if (floorKey != null && ceilingKey != null && floorKey == ceilingKey) {
            return;
        }

        if (floorKey != null && val <= floorKey + 1) {
            tree.put(floorKey, Math.max(val, tree.get(floorKey)));
        } else if (ceilingKey != null && ceilingKey - 1 == val) {
            tree.put(val, Math.max(ceilingKey, tree.get(ceilingKey)));
        } else {
            tree.put(val, val);
        }

        if (floorKey != null && floorKey + 1 == ceilingKey) {
            tree.put(floorKey, tree.get(ceilingKey));
            tree.remove(ceilingKey);
        }
    }

    public int[][] getIntervals() {
        int[][] res = new int[tree.size()][2];
        int i = 0;
        for (int key : tree.keySet()) {
            res[i][0] = key;
            res[i][1] = tree.get(key);
            i++;
        }
        return res;
    }

    public static void main(String[] args) {
        Main dataStream = new Main();
        dataStream.addNum(1);
        dataStream.addNum(3);
        dataStream.addNum(7);
        dataStream.addNum(2);
        dataStream.addNum(6);
        int[][] intervals = dataStream.getIntervals();
        for (int[] interval : intervals) {
            System.out.println(interval[0] + " " + interval[1]);
        }
    }
}
