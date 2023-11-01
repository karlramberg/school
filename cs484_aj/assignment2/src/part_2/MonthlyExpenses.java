package part_2;

import org.springframework.stereotype.Component;

@Component
public class MonthlyExpenses implements Expenses {

	@Override
	public String getExpenses() {
		return "$100";
	}

}
