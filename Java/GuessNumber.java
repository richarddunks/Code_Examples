package BookExample;

/**This generates a random number between 1 and 10 and then has the user guess the random number.
 * All code was self-generated following the suggestion of a project outlined in 
 * Java Programs to Accompany Programming Logic and Design, second edition by Joyce Farrell.
 * 
 */
import java.util.Random;
import javax.swing.JOptionPane;


public class GuessNumber {

    public static void main(String[] args) {
        int randomInt;
        String userInputString;
        int userInput = 0;
        Random randomNumber = new Random();
        int guessCount = 0;
        boolean stringException;
        
        //Generate random number 
        randomInt = randomNumber.nextInt(9) + 1;
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
                System.out.println("Sorry! Guess again");
            }
            guessCount++;
        }
        System.out.println("Congratulations! You guessed the random number " + randomInt + " in " + guessCount + " guesses!");
        System.exit(0);     
    }
}
