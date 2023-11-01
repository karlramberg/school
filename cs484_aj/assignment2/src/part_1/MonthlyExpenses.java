package part_1;

import org.springframework.stereotype.Component;

@Component
public class MonthlyExpenses implements Expenses {
	@Override
	public String getExpenses() {
		return "$100";
	}
}
