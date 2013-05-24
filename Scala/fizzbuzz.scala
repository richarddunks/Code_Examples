//FIZZBUZZ implementation in SCALA
for (i <- 1 to 100) {
	if (i % 3 == 0 && i % 5 != 0) println("FIZZ")
	else if (i % 5 == 0 && i % 3 != 0) println("BUZZ")
	else if (i % 3 == 0 && i % 5 == 0) println("FIZZBUZZ")
	else println(i)
}