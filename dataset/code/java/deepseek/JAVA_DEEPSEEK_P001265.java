import java.util.*;

public class Main {
    static class Engineer implements Comparable<Engineer> {
        int speed, efficiency;

        Engineer(int speed, int efficiency) {
            this.speed = speed;
            this.efficiency = efficiency;
        }

        @Override
        public int compareTo(Engineer o) {
            return o.efficiency - this.efficiency;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        List<Engineer> engineers = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            engineers.add(new Engineer(sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(engineers);
        int max = 0;
        for (int i = 0; i < K; i++) {
            max += engineers.get(i).speed;
        }
        System.out.println(max);
    }
}
