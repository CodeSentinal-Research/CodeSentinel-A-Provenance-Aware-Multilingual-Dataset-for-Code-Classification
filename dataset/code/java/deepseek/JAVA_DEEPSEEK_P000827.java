import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] houses = {1, 2, 3, 4, 5};
        int[] heaters = {1, 4};
        System.out.println(findRadius(houses, heaters));
    }

    public static int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int radius = 0;

        for (int house : houses) {
            int radiusCur = Integer.MAX_VALUE;
            for (int heater : heaters) {
                radiusCur = Math.min(radiusCur, Math.abs(house - heater));
            }
            radius = Math.max(radius, radiusCur);
        }

        return radius;
    }
}
