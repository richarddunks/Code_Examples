package BookExample;

/**This generates a random number between 1 and 10 and then has the user guess the random number.
 * All code was self-generated following the suggestion of a project outlined in 
 * Java Programs to Accompany Programming Logic and Design, second edition by Joyce Farrell.
 */

import java.util.Random;
import java.util.ArrayList;
import javax.swing.JOptionPane;

public class GuessNumberList {

    public static void main(String[] args) {
      int randomInt;
        String userInputString;
        int userInput = 0;
        Random randomNumber = new Random();
        int guessCount = 0;
        boolean stringException;
        ArrayList userList = new ArrayList();
        int arrayIndex;
        long timeStart, timeEnd;
        double timePlayed;
        
        //Generate random number 
        randomInt = randomNumber.nextInt(9) + 1;
        //Set start time of guessing
        timeStart = System.currentTimeMillis();
        //Comparison loop
        while(userInput < 1 || userInput > 10 || userInput != randomInt)
        {
            stringException = false;
            //User input guess
            userInputString = JOptionPane.showInputDialog("Enter guess (1-10):");       
            //Verify user input       
            try   
            {     
                //Convert user input string to integer            
                userInput = Integer.parseInt(userInputString);
            }      
            catch(NumberFormatException e1)
            {           
                //Catch a non-integer user input
                System.out.println("Please enter a number between 1 and 10");
                userInput = 0;
                stringException = true;
            }
            if((userInput < 1 || userInput > 10) && stringException == false)
            {
                System.out.println("Please enter a number between 1 and 10");
                userInput = 0;
            }    
            else if(userInput != randomInt && stringException == false)     
            {
                //Check for user input in user array list
                arrayIndex = userList.indexOf(userInput);
                if(arrayIndex != -1)
                {
                    System.out.println("You've already guessed " + userInput + "! Guess Again!");
                
                }
                else
                {
                    userList.add(userInput);
                    System.out.println("Sorry! Guess again");
                }
                
            }
            guessCount++;
        }
        //Calcuate end time of guessing
        timeEnd = System.currentTimeMillis();
        //Calculate the total time of guessing
        timePlayed = (timeEnd - timeStart)/1000;
        //Output results
        System.out.println("Congratulations! You guessed the random number " + randomInt + " in " + guessCount + " guesses!");
        System.out.println("You took " + timePlayed + " seconds to guess the number.");
        
        System.exit(0);       
    }

}
