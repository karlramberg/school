package part_2;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class TestApp {
	public static void main(String[] args) {
		// Start the bean factory
		AnnotationConfigApplicationContext context 
			= new AnnotationConfigApplicationContext(Config.class);
		
		// Create a test person
		Person person = context.getBean("person", Person.class);
		
		// Test the new person
		System.out.println("Award name: " + person.getAwardName());
		System.out.println("Award prize money: " + person.getAwardPrizeMoney());
		System.out.println("Yearly expenses: " + person.getExpenses());
		
		// Shut down the bean factory
		context.close();
	}
}
