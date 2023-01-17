#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

void shuffle(int* const randNoArr, int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		int r = i + (rand() % (size - i));
		int temp = randNoArr[i];
		randNoArr[i] = randNoArr[r];
		randNoArr[r] = temp;
	}
}
void numberguess(int* const answer, int size)
{
	//count the steps
	int round = 1;
	int check = 0;

	//array for the result
	char* checking = new char[size];

	//array for user input guess
	int* guess = new int[size];

	double epsilon = numeric_limits<double>::epsilon();

	//while the user guess the wrong number ,program keeps running
	while (check == 0){
		cout << "Round " << round << endl;
		cout << "Enter Guess: ";

		//store input to array
		for (int i = 0; i < size; i++)
			cin >> guess[i];

		//checking for the input which is correct number or not
		for (int i = 0; i < size; i++){
			if (abs(guess[i] - answer[i]) < epsilon)

				checking[i] = 'O';

			// wrong guess
			else
				checking[i] = 'X';
		}

		//display the checking of numbers
		cout << "             ";
		for (int i = 0; i < size; i++)
			cout << checking[i] << " ";
		cout << endl;
		cout << "-----------------------------------------------------------";
		cout << endl;

		//all numbers are correct
		for (int i = 0; i < size; i++)
		{
			//if one of the guess is wrong, return false
			if (checking[i] != 'O')
			{
				check = 0;
				round++;
				break;
			}

			//all guess are correct
			else
			{
				check = 1;
			}
		}
		if (check)
			cout << "Congratulations! You win in " << round << " steps" << endl;
	}
	delete[]guess;
	delete[]checking;
}

int main()
{

	//initialize the answer
	int random = 1;

	cout << "Enter total number : ";

	//the size of array
	int n;
	cin >> n;

	// array for the answer
	int* answer = new int[n];

	//initialize the answer
	for (int i = 0; i < n; i++)
	{
		answer[i] = random;
		random++;
	}

	//call function shuffle
	shuffle(answer, n);

	//title
	cout << "Number Guessing" << endl;
	cout << " Enter " << n << " digits (1- " << n << ") separated by a space" << endl;
	cout << "---------------------------------------------------" << endl;

	//call function number guess
	numberguess(answer, n);

	//delete the array
	delete[]answer;
	system("pause");
	return 0;
}
