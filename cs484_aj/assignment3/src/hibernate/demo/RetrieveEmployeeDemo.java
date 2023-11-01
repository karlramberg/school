package hibernate.demo;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entity.Employee;

public class RetrieveEmployeeDemo {

	public static void main(String[] args) {

		SessionFactory factory = new Configuration()
				.configure("hibernate.cfg.xml")
				.addAnnotatedClass(Employee.class)
				.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		// Demo retrieving an employee by there primary key (empId)
		try {
			session.beginTransaction();
		
			// Retrieve the employee whose ID is 4
			int id = 4;
			Employee employee = session.get(Employee.class, id);
			
			// Print the found employee
			System.out.println(employee);
			
			session.getTransaction().commit();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			session.close();
			factory.close();
		}
	}

}
