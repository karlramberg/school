package hibernate.demo;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entity.Employee;

public class DeleteEmployeeDemo {
	public static void main(String[] args) {
		SessionFactory factory = new Configuration()
				.configure("hibernate.cfg.xml")
				.addAnnotatedClass(Employee.class)
				.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		// Demo deleting an employee by there primary key (empId)
		try {
			session.beginTransaction();
		
			// Grab the employee whose ID is 1
			int id = 1;
			Employee employee = session.get(Employee.class, id);
			
			// Delete that employee
			session.delete(employee);
			session.getTransaction().commit();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			session.close();
			factory.close();
		}
	}
}