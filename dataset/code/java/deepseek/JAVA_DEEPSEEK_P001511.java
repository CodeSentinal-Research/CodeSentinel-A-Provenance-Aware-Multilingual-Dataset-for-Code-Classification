import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String answer = scanner.next();
        int k = scanner.nextInt();
        System.out.println(maxConsecutiveAnswers(answer, k));
    }

    public static int maxConsecutiveAnswers(String answer, int k) {
        int max = 0;
        int count = 1;
        char prev = answer.charAt(0);

        for (int i = 1; i < answer.length(); i++) {
            char current = answer.charAt(i);
            if (current == prev) {
                count++;
            } else {
                if (count > max) {
                    max = count;
                }
                count = 1;
           
                if (k == 0) {
                    return max;
                }
            }
            prev = current;
        }

        if (count > max) {
            max = count;
        }

        return max;
    }
}
