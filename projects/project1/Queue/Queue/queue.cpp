#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	// Create a queue of floats, named transactions
	queue<float> transactions;

	// Push some + and - floats into the transactions queue.
	transactions.push(10.00);
	transactions.push(50.00);
	transactions.push(-18.00);
	transactions.push(25.00);
	transactions.push(-40.00);

	// Loop through all the transactions - while the queue is empty.
	while (!transactions.empty())
	{
		float amount = transactions.front();
		cout << amount << " pushed to account" << endl;
		balance += amount;
		transactions.pop();
	}
	// Within the loop, whatever amount is at the front of the queue,
	
	// add it to the balance and then pop it off the queue.

	cout << "Final balance: $" << balance << endl;

	return 0;
}