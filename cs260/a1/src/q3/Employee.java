package q3;

/**
 * Employee class represents an employee at a company
 * @author karl
 */
public class Employee
{	
	String firstName;
	String lastName;
	double monthlySalary;
	
	/**
	 * Employee() is the full argument constructor for the Employee class
	 * @param firstName - a String for the Employee's firstName
	 * @param lastName - a String for the Employee's lastName
	 * @param monthlySalary - a double for the Employee's monthlySalary
	 */
	public Employee(String firstName, String lastName, double monthlySalary)
	{
		this.firstName = firstName;
		this.lastName = lastName;
		this.monthlySalary = monthlySalary;
	}

	/**
	 * getFirstName() is the accessor for firstName
	 * @return the current firstName
	 */
	public String getFirstName()
	{
		return firstName;
	}

	/**
	 * setFirstName() is the mutator for firstName
	 * @param firstName - a String for the new firstName
	 */
	public void setFirstName(String firstName)
	{
		this.firstName = firstName;
	}

	/**
	 * getLastName() is the accessor for lastName
	 * @return the current lastName
	 */
	public String getLastName()
	{
		return lastName;
	}

	/**
	 * setLastName() is the mutator for lastName
	 * @param lastName - a String for the new lastName
	 */
	public void setLastName(String lastName)
	{
		this.lastName = lastName;
	}

	/**
	 * getMonthlySalary() is the accessor for monthlySalary
	 * @return the current monthlySalary
	 */
	public double getMonthlySalary()
	{
		return monthlySalary;
	}

	/**
	 * setMonthlySalary() is the mutator for monthlySalary
	 * It does not let monthlySalary be less that $0.00
	 * @param monthlySalary - a double for the new monthlySalary
	 */
	public void setMonthlySalary(double monthlySalary)
	{
		if(monthlySalary >= 0.00)
		{
			this.monthlySalary = monthlySalary;
		}
	}
}
