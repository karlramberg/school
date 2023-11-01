package part_1;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class Person {
	@Autowired
	private Awards award;
	
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
	public void setExpenses(Expenses expenses) {
		this.expenses = expenses;
	}
}
