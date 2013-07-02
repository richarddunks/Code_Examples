//Lab exercise from Programming Scala class taught by Venkat Subramaniam
//Attended at Gilt Groupe 1 July 2013
//Code was developed by pair coding and then refactored
//based on input from other members of the class

object Guess {
	val number = (math.random * 100).toInt
	 
	def guessNumber( guessCount: Int = 1 ) {
		print("Enter your guess:")
		val guess = Console.readInt
		val compare = guess compare number

		val (response, playAgain) = 
			compare match {
				case -1 => ("Aim higher", true)
				case 1 => ("Aim lower", true)
				case 0 => ("You got it in " + guessCount + " attempts!", false)	
			}

		println(response)
		if (playAgain) guessNumber(guessCount + 1)
	} 
}

println("I've selected a number, can you guess it!")
Guess.guessNumber()

