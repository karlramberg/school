package hibernate.demo;

import java.text.SimpleDateFormat;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entity.Employee;

public class CreateEmployeeDemo {

	public static void main(String[] args) {
		SessionFactory factory = new Configuration()
				.configure("hibernate.cfg.xml")
				.addAnnotatedClass(Employee.class)
				.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		SimpleDateFormat dateFormatter = new SimpleDateFormat("yyyy-MM-dd");
		
		// Demo saving new employees to the table
		try {
			// Create a new Employees
			Employee employee1 = new Employee("Karl", "Ramberg", "Google", dateFormatter.parse("2021-07-11"), 80000.0);
			Employee employee2 = new Employee("Bob", "Grensbie", "Amazon", dateFormatter.parse("2009-02-14"), 120000.0);
			Employee employee3 = new Employee("Paul", "Atreides", "Google", dateFormatter.parse("2018-06-09"), 84000.0);
			Employee employee4 = new Employee("Sam", "Slater", "Apple", dateFormatter.parse("2010-04-30"), 96000.0);
			
			// Save the employee to the database
			session.beginTransaction();
			session.save(employee1);
			session.save(employee2);
			session.save(employee3);
			session.save(employee4);
			session.getTransaction().commit();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			session.close();
			factory.close();
		}
	}
}