#include"CustomerData.cpp"

class PreferredCustomer : public CustomerData
{
private:
    static constexpr double TIER_1_DISCOUNT = 0.05;
    static constexpr double TIER_2_DISCOUNT = 0.06;
    static constexpr double TIER_3_DISCOUNT = 0.07;
    static constexpr double TIER_4_DISCOUNT = 0.10;
    static constexpr int TIER_1_CUTOFF = 500;
    static constexpr int TIER_2_CUTOFF = 1000;
    static constexpr int TIER_3_CUTOFF = 1500;
    static constexpr int TIER_4_CUTOFF = 2000;

    double purchaseAmount;
    double discountLevel;

    // calculate a new discount from the total purchase amount
    // and discount tier levels and cutoffs
    // return : the new discount amount
    double calcDiscountLevel() {
	if(this->purchaseAmount < TIER_1_CUTOFF)
	{
	    return 0.0;
	}
	else if(this->purchaseAmount < TIER_2_CUTOFF)
	{
	    return TIER_1_DISCOUNT;
	}
	else if(this->purchaseAmount < TIER_3_CUTOFF)
	{
	    return TIER_2_DISCOUNT;
	}
	else if(this->purchaseAmount < TIER_4_CUTOFF)
	{
	    return TIER_3_DISCOUNT;
	}
	else
	{
	    return TIER_4_DISCOUNT;
	}
    }

public:
    // argument constexprructor for PreferredCustomer
    // parameter : the customer's last name
    // parameter : the customer's first name
    // parameter : the customer's address
    // parameter : the city where the customer lives
    // parameter : the state where the customer lives
    // parameter : the customer's zip code
    // parameter : the customer's phone number
    // parameter : the customer's uniquie id number
    // parameter : whether or not the customer is on the mailing list
    // parameter : the total of customer purchases to date
    PreferredCustomer(string lastName,
		      string firstName,
		      string address,
		      string city,
		      string state,
		      int zip,
		      long phone,
		      int customerNumber,
		      bool mailingList,
		      double purchaseAmount)
       : CustomerData(lastName,
		      firstName,
		      address,
		      city,
		      state,
		      zip,
		      phone,
		      customerNumber,
		      mailingList)
    {
	this->purchaseAmount = purchaseAmount;
	this->discountLevel = calcDiscountLevel();
    }

    // accessor for purchaseAmount
    // return : the total of customer purchases' to date
    double getPurchaseAmount() const
    {
	return this->purchaseAmount;
    }

    // mutator for purchaseAmount
    // also recalculates the customer's discount
    // parameter : the new total of customer purchases'
    void setPurchaseAmount(double purchaseAmount)
    {
	this->purchaseAmount = purchaseAmount;
	this->discountLevel = calcDiscountLevel();
    }

    // accessor for discountLevel
    // return : the customer's current discount
    double getDiscountLevel() const
    {
	return this->discountLevel;
    }

    // mutator for discountLevel
    // parameter : the customer's new discount
    void setDiscountLevel(double discountLevel)
    {
	this->discountLevel = discountLevel;
    }
};
