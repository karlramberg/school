#include<iostream>
#include"Coin.cpp"

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    Coin coin;
    cout << "Initial side up: " << coin.getSideUp() << endl;
 
    unsigned numberOfHeads = 0;
    unsigned numberOfTails = 0; 
    for(int index = 0; index < 20; index++)
    {
	coin.toss();
	cout << "Toss " << index + 1 << ": " << coin.getSideUp() << endl;

	if(coin.getSideUp() == "heads")
	{
	    numberOfHeads++;
	}
	else
	{
	    numberOfTails++;
	}
    }	

    cout << "Number of heads: " << numberOfHeads << endl;
    cout << "Number of tails: " << numberOfTails << endl;
}
