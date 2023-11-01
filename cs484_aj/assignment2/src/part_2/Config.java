package part_2;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class Config {
	@Bean
	public Award nebulaAward() {
		return new NebulaAward();
	}
	
	@Bean
	public Expenses yearlyExpenses() {
		return new YearlyExpenses();
	}
	
	@Bean
	public Person person() {
		return new Person();
	}
}
