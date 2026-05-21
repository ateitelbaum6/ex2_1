/******************
Name: Atara Teitelbaum
ID: 671938245
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int x = 0;

	while (x != 7) {
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. Festival Of Laughter\n\t7. Exit\n");
		scanf("%d", &x);

	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/
		if (x == 1) {
			char e, n, m;
			int faceSize;
			printf("\nEnter symbols for the eyes, nose, and mouth:\n");
			scanf(" %c %c %c",&e, &n, &m);

			printf("\nEnter face size:\n");
			scanf("%d",&faceSize);
			while ((faceSize / 2)*2 == faceSize || faceSize < 0) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d",&faceSize);
			}
			
			printf("%c", e);
			for (int i = 0; i < faceSize; i++) {
				printf(" ");
			}
			printf("%c\n", e);
			
			for(int i = 0; i < (faceSize + 2) / 2; i++) {
				printf(" ");
			}
			printf("%c\n", n);

			printf("\\");
			for (int i = 0; i < faceSize; i++) {
				printf("%c", m);
			}
			printf("/\n");
				
		}


	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/
		else if (x == 2) {
			int num;
			printf("Enter a number:\n");
			scanf("%d", &num);
			while (num <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num);
			}
			int temp = num, z = 0;
			while (temp > 0) {
				z++;
				temp /= 10;
			}

			int leftSum = 0, rightSum =0;
			int left, right;

			if((z & 1) == 0) {
				left = z / 2;
				right = (z / 2) -1;
			}
			else {
				left = z / 2;
				right = z / 2;
			}

			temp = num;
			for (int i = 0; i < z; i++) {
				int digit = temp - ((temp / 10)*10);
				temp /= 10;
				int place = z - 1 - i;

				if (place < left) {
					leftSum += digit;
				}
				else if (place > right) {
					rightSum += digit;
				}
			}

			if (leftSum == rightSum) {
				printf("This number is balanced and brings harmony!\n");
			}
			else {
				printf("This number isn't balanced and destroys harmony.\n");
			}
			
		}

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

		else if (x == 3) {
			int num;
			printf("Enter a number:\n");
			scanf("%d", &num);

			while (num < 0) {
				printf("Only positive number is allowed, please try again:");
				scanf("%d", &num);
			}

			int divSum = 0;
			for (int i = 1; i < num; i++) {
				if ((num / i) * i == num) {
					divSum += i;
				}
			}

			if (divSum > num) {
				printf("This number is generous!\n");
			}
			else {
				printf("This number does not share.\n");
			}
		}
			
	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    	else if (x == 4){
			int num;
			printf("Enter a number:\n");
			scanf("%d", &num);

			while (num < 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num);
			}

			int primeChecker;
			if (num > 1) {
				primeChecker = 1;
			}
			else {
				primeChecker = 0;
			}
			
			for (int i = 2; i*i <= num; i++) {
				if ((num / i) * i == num) {
					primeChecker = 0;
					break;
				}
			}
			
			int reverseNum = 0, temp = num;
			while (temp > 0) {
				int dig = temp - ((temp / 10)*10);
				reverseNum = (reverseNum*10) + dig;
				temp /= 10;
			}

			int revPrimeChecker;
			if (reverseNum > 1){
				revPrimeChecker = 1;
			}
			else {
				revPrimeChecker = 0;
			}
			
			for (int i = 2; i*i <= reverseNum; i++) {
				if ((reverseNum / i)*i == reverseNum) {
					revPrimeChecker = 0;
					break;
				}
			}

			if (primeChecker == 1 && revPrimeChecker == 1) {
				printf("This number completes the circle of joy!\n");
			}
			else {
				printf("The circle remains incomplete\n");
			}

		}
			

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

		else if (x == 5) {
			int num;
			printf("Enter a number:\n");
			scanf("%d", &num);

			while (num <= 0) {
				printf("Only positive number is allowed, please try again:");
				scanf("%d", &num);
			}
			printf("Between 1 and %d only these numbers bring happiness: ", num);
			for (int i = 1; i <= num; i++) {
				int currNum = i;
				for (int j = 0; j < 100; j++) {
					int sum = 0, temp = currNum;
					while (temp > 0) {
						int digit = temp - ((temp / 10)*10);
						sum += (digit*digit);
						temp /= 10;
					}

					currNum = sum;
					if (currNum == 1 || currNum == 4) {
						break;
					}
				}

				if (currNum == 1) {
					printf("%d ", i);
				}
			}
			printf("\n");
		}
				
					
			
			
	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
		else if (x == 6) {
			int smile = -1, cheer = -1;
			int valid = 0;

			while (valid == 0) {
				printf("Enter a smile and cheer number:\n");
				int c = scanf(" smile: %d , cheer: %d", &smile, &cheer);

				if (c == 2 && smile > 0 && cheer > 0 && smile != cheer) {
					valid = 1;
				}
				else {
					char clean;
					do {
						scanf("%c", &clean);
					} while (clean != '\n');
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				}
			}

			int max= -1;
			while (max <= 0) {
				printf("Enter max number for the festival:\n");
				if (scanf("%d", &max) != 1) {
					char clean;
					do {
						scanf("%c", &clean);
					} while (clean != '\n');
					max = -1;
				}
				if (max <= 0) {
					printf("Only positive max number is allowed, please try again:\n");
				}
			}

			for (int i = 1; i <= max; i++) {
				int divSmile = ((i / smile)*smile == i);
				int divCheer = ((i / cheer)*cheer == i);

				if (divSmile && divCheer) {
					printf("Festival!\n");
				}
				else if (divSmile) {
					printf("Smile!\n");
				}
				else if (divCheer) {
					printf("Cheer!\n");
				}
				else {
					printf("%d\n", i);
				}
			}
		}

		else {
			printf("\nThis option is not available, please try again.");
			}
		} 
			
	printf("\nThank you for your journey through Numeria!");
	return 0;
}
