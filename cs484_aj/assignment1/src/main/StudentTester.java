package main;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class StudentTester {
	public static void main(String[] args) {
		// Set up the Spring object factory
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		
		// Set up the student objects using Spring
		Student student = context.getBean("highSchoolStudent", Student.class);
		Student student2 = context.getBean("collegeStudent", Student.class);

		// Test the student's functionality
		System.out.println(student.getDailyTips());
		System.out.println(student2.getDailyTips());
		
		// Shut down the Spring object factory
		context.close();
	}
}