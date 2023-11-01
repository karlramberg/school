package q2;

/**
 * Invoice class represents an invoice of a purchase
 * @author karl
 */
public class Invoice
{
	
	static final String DEFAULTPARTNUMBER = "0";
	static final String DEFAULTDESCRIPTION = "No description provided";
	static final int DEFAULTQUANTITY = 0;
	static final double DEFAULTPRICE = 0.00;
	
	String partNumber;
	String description;
	int quantity;
	double price;
	
	/**
	 * Invoice() is the default constructor for the Invoice class
	 */
	public Invoice()
	{
		this.partNumber = DEFAULTPARTNUMBER;
		this.description = DEFAULTDESCRIPTION;
		this.quantity = DEFAULTQUANTITY;
		this.price = DEFAULTPRICE;
	}
	
	/**
	 * Invoice() is the full argument constructor for the Invoice class
	 * @param partNumber - a String for the part number of the item purchased
	 * @param description - a String to describe the item purchased
	 * @param quantity - an int for the unit amount purchased
	 * @param price - a double for the price of an individual unit
	 */
	public Invoice(String partNumber, String description, int quantity, double price)
	{
		this.partNumber = partNumber;
		this.description = description;
		this.quantity = quantity;
		this.price = price;
	}

	/**
	 * getInvoiceAmount() calculate the current invoice amount
	 * @return the current invoice amount, from quantity * price
	 */
	public double getInvoiceAmount()
	{
		return this.quantity * this.price;
	}
	
	/**
	 * getPartNumber() is the accessor for partNumber
	 * @return the current partNumber
	 */
	public String getPartNumber()
	{
		return partNumber;
	}

	/**
	 * setPartNumber() is the mutator for partNumber
	 * @param partNumber - a String for the new value of partNumber
	 */
	public void setPartNumber(String partNumber)
	{
		this.partNumber = partNumber;
	}

	/**
	 * getDescription() is the accessor for description
	 * @return the current description
	 */
	public String getDescription()
	{
		return description;
	}

	/**
	 * setDescription() is the mutator for description
	 * @param description - a String for the new description
	 */
	public void setDescription(String description)
	{
		this.description = description;
	}

	/**
	 * getQuantity() is the accessor for quantity
	 * @return the current quantity
	 */
	public int getQuantity()
	{
		return quantity;
	}

	/**
	 * setQuantity() is the mutator for quantity
	 * It does not let quantity be less than 0
	 * @param quantity - an int for the new quantity
	 */
	public void setQuantity(int quantity)
	{
		if (quantity < 0)
		{
			this.quantity = 0;
		} 
		else
		{
			this.quantity = quantity;
		}
	}

	/**
	 * getPrice() is the accessor for price
	 * @return the current price
	 */
	public double getPrice()
	{
		return price;
	}

	/**
	 * setPrice() is the mutator for price
	 * It does not let price be less than 0
	 * @param price - a double for the new price
	 */
	public void setPrice(double price)
	{
		if (price < 0.00)
		{
			this.price = 0.00;
		}
		else
		{
			this.price = price;
		}
	}
}
