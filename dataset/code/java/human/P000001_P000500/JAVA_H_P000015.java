package object;

class Shape {


    

    public void perimeterCalculator ( int width, int length   ){

        int perimeter  = 2 * ( width + length);

        System.out.println("The perimeter of rectangle is: " + perimeter);

    }

    
    
    public void areaCalculator( double base, double height    ){

        double area = (base * height) /2;

        System.out.println(area + " is the area of triangle");

    }











}
