#include<string>

using namespace std;

class Coin
{
private:
    string sideUp;
    
public:
    // default constructor, assigns a random side up
    Coin()
    {
	this->toss();
    }
    
    // accesses sideUp member data
    // return: the side facing up on the coin
    string getSideUp() const
    {
	return this->sideUp; 
    }
    
    // randomly sets sideUp to heads or tails
    void toss()
    {
	int side = static_cast<double>(rand() % (2- 1 + 1) + 1); 
	if(side == 1)
	{
	    this->sideUp = "heads";
	}
	else
	{
	    this->sideUp = "tails";
	}
    }
};
