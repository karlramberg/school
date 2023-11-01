package q3;

/**
 * EmployeeDriver is an executable class for testing
 * the Employee class
 * @author karl
 */
public class EmployeeDriver
{
	static final int MONTHSINYEAR = 12;
	static final double RAISEAMOUNT = 1.10;
	
	public static void main(String[] args)
	{
		// Create two new employees
		Employee employee1 = new Employee("Karl", "Ramberg", 2000.00);
		Employee employee2 = new Employee("Tyler", "Beauregard", 4000.00);
		
		// Print their current data
		System.out.println("========= Employee 1 ==========");
		System.out.println(employee1.getFirstName() + " " + employee1.getLastName());
		System.out.println("Salary: " + employee1.getMonthlySalary() * MONTHSINYEAR);
		
		System.out.println("========= Employee 2 ==========");
		System.out.println(employee2.getFirstName() + " " + employee2.getLastName());
		System.out.println("Salary: " + employee2.getMonthlySalary() * MONTHSINYEAR);
		
		// Raise their salaries
		employee1.setMonthlySalary(employee1.getMonthlySalary() * RAISEAMOUNT);
		employee2.setMonthlySalary(employee2.getMonthlySalary() * RAISEAMOUNT);
		
		// Print their changed data
		System.out.println("");
		System.out.println("With a 10% raise...");
		System.out.println("========= Employee 1 ==========");
		System.out.println(employee1.getFirstName() + " " + employee1.getLastName());
		System.out.println("Salary: " + employee1.getMonthlySalary() * MONTHSINYEAR);
		
		System.out.println("========= Employee 2 ==========");
		System.out.println(employee2.getFirstName() + " " + employee2.getLastName());
		System.out.println("Salary: " + employee2.getMonthlySalary() * MONTHSINYEAR);

 	}
}
