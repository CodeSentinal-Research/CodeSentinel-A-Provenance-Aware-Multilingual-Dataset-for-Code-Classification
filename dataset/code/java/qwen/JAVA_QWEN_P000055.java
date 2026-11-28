public class Main {
    public static void main(String[] args) {
        for (char c = 'Z'; c >= 'A'; c--) {
            System.out.print(c + (c == 'A' ? "" : " "));
        }
        System.out.println();
    }
}
