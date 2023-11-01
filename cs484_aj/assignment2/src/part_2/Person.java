package part_2;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;

public class Person {
	@Autowired
	@Qualifier("nebulaAward")
	private Award award;
	
	private Expenses expenses;

	public String getAwardName() {
		return award.getAwardName();
	}
	
	public String getAwardPrizeMoney() {
		return award.getAwardPrizeMoney();
	}

	public String getExpenses() {
		return expenses.getExpenses();
	}
	
	@Autowired
	@Qualifier("yearlyExpenses")
	public void setExpenses(Expenses expenses) {
		this.expenses = expenses;
	}
}
