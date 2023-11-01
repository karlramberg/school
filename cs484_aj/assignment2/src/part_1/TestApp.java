package part_1;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestApp {
	public static void main(String[] args) {
		// Create the bean factory
		ClassPathXmlApplicationContext context 
			= new ClassPathXmlApplicationContext("context.xml");
		
		// Create a test person
		Person person = context.getBean("person", Person.class);
		
		// Test the new person
		System.out.println("Award name: " + person.getAwardName());
		System.out.println("Award prize money:" + person.getAwardPrizeMoney());
		System.out.println("Monthly expenses:" + person.getExpenses());
		
		// Shut down the bean factory
		context.close();
	}
}
