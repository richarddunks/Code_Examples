/*
 * This example calculates the largest and smallest integers from a set of three 
 * integers based on an exercise in Java Programs to Accompany Programming Logic 
 * and Design, 2nd Edition by Jo Ann Smith. All code is self-generated to meet
 * parameters outlined in the exercise.
 */
package BookExample;

import javax.swing.JOptionPane;

public class LargeSmall {

    
    public static void main(String[] args) {
        String integerAString, integerBString, integerCString;
        int integerA, integerB, integerC, largeInt, smallInt;
        
        //Prompt for first integer
        integerAString = JOptionPane.showInputDialog("Enter First Integer:");
        //Conversion first integer string to integer
        integerA = Integer.parseInt(integerAString);
        //Prompt for second integer
        integerBString = JOptionPane.showInputDialog("Enter Second Integer:");
        //Conversion second integer string to integer
        integerB = Integer.parseInt(integerBString);
        //Prompt for third integer
        integerCString = JOptionPane.showInputDialog("Enter Third Integer:");
        //Conversion third integer string to integer
        integerC = Integer.parseInt(integerCString);
        //Largest integer test
        if (integerA > integerB && integerA > integerC)
            largeInt = integerA;
        else if (integerB > integerA && integerB > integerC)
            largeInt = integerB;
        else
            largeInt = integerC;
        //Smallest integer test
        if (integerA < integerB && integerA < integerC)
            smallInt = integerA;
        else if (integerB < integerA && integerB < integerC)
            smallInt = integerB;
        else 
            smallInt = integerC;
        //Output result
        System.out.println("The largest value is " + largeInt);
        System.out.println("The smallest value is " + smallInt);
        System.exit(0);
        
        
    }
}
