package part_1;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Part1Test {
	public static void main(String[] args) {
		// Start the bean factory
		AnnotationConfigApplicationContext context 
			= new AnnotationConfigApplicationContext(Config.class);
		
		// Create a test college
		FourYearCollege college = context.getBean("fourYearCollege", FourYearCollege.class);
		
		// Test the new college
		System.out.println("Name: " + college.getPresidentName());
		System.out.println("College: " + college.getTrumanStateName());
		
		// Shut down the bean factory
		context.close();
	}
}
