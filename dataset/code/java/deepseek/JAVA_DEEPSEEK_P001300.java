import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] people = new int[N];
        for (int i = 0; i < N; i++) {
            people[i] = scanner.nextInt();
        }
        int M = scanner.nextInt();
        int[] boats = new int[M];
        for (int i = 0; i < M; i++) {
            boats[i] = scanner.nextInt();
        }
        System.out.println(minBoats(people, boats));
    }

    public static int minBoats(int[] people, int[] boats) {
        Arrays.sort(people);
        Arrays.sort(boats);
        int boatsCount = 0;
        int i = 0;
        int j = boats.length - 1;
        while (i < people.length) {
            if (people[i] <= boats[j]) {
                boatsCount++;
                i++;
                j--;
            } else {
                boatsCount++;
                j--;
            }
            if (j < 0) {
                break;
            }
        }
        if (i == people.length) {
            return boatsCount;
        } else {
            return -1;
        }
    }
}
