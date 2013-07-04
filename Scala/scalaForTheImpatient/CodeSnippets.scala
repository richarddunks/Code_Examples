/**	Cool snippets of Scala code from Scala
*	for the Impatient
*/

//creates a random string of letters from a random BigInt number
//that is most likely prime
BigInt.apply(128, util.Random).toString(36)

//factorial non-recursively
def fac(n:Int) = {
	var r = 1
	for (i <- 1 to n) r = r * i
	r
}

//factorial recursively
def fac(n:Int): Int = if (n <= 0) 1 else n * fac(n-1)

//decorate text with start and end characters
def decorate(str: String, left:String = "[", right: String = "]") =
	left + str + right

//sum function non-recursively
def sum( args: Int* ) = {
	var result = 0
	for (arg <- args) result += arg
	result
}

//sum function recursively
def recursiveSum( args: Int*) : Int = {
	if (args.length == 0) 0
	else args.head + recursiveSum(args.tail : _*)
}

//procedure to draw a box around a string
def box(s: String) {
	val border = "-" * s.length + "--\n"
	println(border + "|" + s + "|\n" + border)
}

//signum function to test input for positive or negative
def signum(n:Int): Int = if (n > 0) 1 else if (n == 0) 0 else -1

//decreasing for loop Exercise 2.4
for (i <- 10 to 0 by -1) println(i)

//function to countdown from n to 0 Exercise 2.5
def countdown(n:Int) : Unit = {
	for (i <- n to 0 by -1) println(i)
	println("Countdown complete")
}

//function to compute product of Unicode characters for given string Exercise 2.6
def codeProduct(str: String) : Unit = {
	var sum = BigInt(1)
	for (i <- 0 until str.length) sum *= str.codePointAt(i)
	println(sum)
}

//his answer to Exercise 2.9
def product(str:String) : BigInt = {
	var prod = BigInt(1)
	str.foreach(prod *= _.toInt)
	prod
}

//my test to answer to Excercise 2.9
def printRecu(str: String) : Unit = {
	if (str.length == 0) println(1)
	else {
		printRecu(str.takeRight(str.length-1))
		println(str.codePointAt(0))
	}
}

//my kickass recursive answer to 2.9
def productRecursive(str: String) : BigInt = {
	if (str.length == 0) 1
	else productRecursive(str.takeRight(str.length-1)) * str.codePointAt(0)
}

//exercise 2.10
def exponent( x:Int, n:Int ) : Float = {
	//n positive and even
	if ( n%2 == 0 && n > 0 ) exponent( x, (n/2) ) * exponent( x, (n/2) )
	//n positive and odd
	else if ( n%2 != 0 && n > 0 ) x * exponent( x, (n-1) ) 
	//n negative
	else if ( n < 0 ) 1 / exponent( x , (-1 * n) )
	//n == 0
	else 1
}

