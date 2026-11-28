import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        int[] energy = new int[n];
        int[] requiredEnergy = new int[n];
        for (int i = 0; i < n; i++) {
            energy[i] = scanner.nextInt();
            requiredEnergy[i] = scanner.nextInt();
        }
        scanner.close();

        int totalEnergy = 0;
        for (int i = 0; i < n; i++) {
            totalEnergy += energy[i];
        }

        int minEnergy = totalEnergy;
        for (int i = 0; i < n; i++) {
            if (minEnergy > requiredEnergy[i]) {
                minEnergy = requiredEnergy[i];
            }
        }

        System.out.println(minEnergy);
    }
}
