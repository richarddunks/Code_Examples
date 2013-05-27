/*	This is an implementation of FIZZBUZZ in Java
*/

public class fizzbuzz {
	public static void main(String[] args) {
		for ( int i = 1; i <= 100; i++) {
			if (i%15 == 0) {
				System.out.print("FIZZBUZZ\n");
			} else if (i%3 == 0) {
				System.out.print("FIZZ\n");
			} else if (i%5 == 0) {
				System.out.print("BUZZ\n");
			} else {
				System.out.print(i + "\n");
			}
		}
	}
}
