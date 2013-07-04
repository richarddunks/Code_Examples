//Scala for the Impatient Ch. 2

//1. Write a code snippet that sets a to an array of n random integers between 0 (inclusive) and n (exclusive).
import util._

//modified from http://www.smipple.net/snippet/morph/Create%20Array%20filled%20with%20random%20Integers
def randomArrayCreation(n: Int): Array[Int] = {
 	val range = 0 to n-1
 	val a = new Array[Int](n)
 	
 	def getRndInt(range: Range): Int = {
 		val rnd = new scala.util.Random
 	rnd.nextInt(range.length)
 	}
 	
	for (index <- 0 until n) a(index) = (getRndInt(range))
	a
}

//2. Write a loop that swaps adjacent elements of an array of integers. For example, Array(1, 2, 3, 4, 5) 
//becomes Array(2, 1, 4, 3, 5).
def swapAdjacent(a: Array[Int]) {
	for (i <- 0 until a.length-1 by 2) {
		val swap = a(i)
		a(i) = a(i + 1)
		a(i + 1) = swap
	}
}

//3. Repeat the preceding assignment, but produce a new array with the swapped values. Use for/yield.


//4. Given an array of integers, produce a new array that contains all positive values of the original 
//array, in their original order, followed by all values that are zero or negative, in their original order.

//5. How do you compute the average of an Array[Double]?
def arrayAverage(a: Array): Int = { 
	a.sum / a.length
}

//6. How do you rearrange the elements of an Array[Int] so that they appear in
//reverse sorted order? How do you do the same with an ArrayBuffer[Int]?
val a = Array(1,2,3,4,5)
a.sortWith(_>_) //same for ArrayBuffer
a.reverse //same for ArrayBuffer


//7. Write a code snippet that produces all values from an array with duplicates
//removed. (Hint: Look at Scaladoc.)


//8. Rewrite the example at the end of Section 3.4, “Transforming Arrays,” on page 34 using the drop 
//method for dropping the index of the first match. Look the method up in Scaladoc.

//9. Make a collection of all time zones returned by java.util.TimeZone.getAvailableIDs that are in America. 
//Strip off the "America/" prefix and sort the result.

//10. Import java.awt.datatransfer._ and make an object of type SystemFlavorMap with the call
//val flavors = SystemFlavorMap.getDefaultFlavorMap().asInstanceOf[SystemFlavorMap]
//Then call the getNativesForFlavor method with parameter DataFlavor.imageFlavor and get the return value 
//as a Scala buffer. (Why this obscure class? It’s hard to find uses of java.util.List in the standard Java library.)