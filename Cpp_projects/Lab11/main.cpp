#include <iostream>
#include "queuetype.cpp"

using namespace std;

// Structure to hold the current state in BFS
struct State
{
    int amount;
    int coinsUsed;
};

int minCoins(int* coinValues, int n, int targetAmount)
{
    QueueType<State> queue;

    // Initializes all the elements of the array to false
    bool visited[1000] = {false};
    visited[0] = true;

    // Initialize the starting state
    // amount = 0, coinsUsed = 0
    State start = {0, 0};
    queue.Enqueue(start);

    while (!queue.IsEmpty())
    {
        State current;
        queue.Dequeue(current);

        for (int i = 0; i < n; i++)
        {
            int newAmount = current.amount + coinValues[i];
            int newCoinsUsed = current.coinsUsed + 1;

            if (newAmount == targetAmount)
            {
                return newCoinsUsed;
            }

            if (newAmount < targetAmount && !visited[newAmount])
            {
                State temp;
                temp.amount = newAmount;
                temp.coinsUsed = newCoinsUsed;

                queue.Enqueue(temp);
                visited[newAmount] = true;
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    int coinValues[n];
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> coinValues[i];
    }

    int targetAmount;
    cout << "Enter the target amount: ";
    cin >> targetAmount;

    int result = minCoins(coinValues, n, targetAmount);

    if (result != -1)
        cout << "Minimum number of coins needed: " << result << endl;
    else
        cout << "It is not possible to make the target amount." << endl;

    return 0;
}

/*
Given:
Coin values: {5, 10, 20}
Target amount: 30
BFS Exploration:
Start State: {amount=0, coinsUsed=0}

Enqueue this state.
Dequeue: {amount=0, coinsUsed=0}

Try adding coin 5: newAmount = 0 + 5 = 5, newCoinsUsed = 1. Enqueue {5, 1}.
Try adding coin 10: newAmount = 0 + 10 = 10, newCoinsUsed = 1. Enqueue {10, 1}.
Try adding coin 20: newAmount = 0 + 20 = 20, newCoinsUsed = 1. Enqueue {20, 1}.
Dequeue: {amount=5, coinsUsed=1}

Try adding coin 5: newAmount = 5 + 5 = 10, newCoinsUsed = 2 (already visited).
Try adding coin 10: newAmount = 5 + 10 = 15, newCoinsUsed = 2. Enqueue {15, 2}.
Try adding coin 20: newAmount = 5 + 20 = 25, newCoinsUsed = 2. Enqueue {25, 2}.
Dequeue: {amount=10, coinsUsed=1}

Try adding coin 5: newAmount = 10 + 5 = 15, newCoinsUsed = 2 (already visited).
Try adding coin 10: newAmount = 10 + 10 = 20, newCoinsUsed = 2 (already visited).
Try adding coin 20: newAmount = 10 + 20 = 30, newCoinsUsed = 2. We found the target!
The result is 2 coins, meaning the minimum number of coins needed to make 30 is 2 (one 10 and one 20 coin).
*/
