package hibernate.demo;

import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import hibernate.entity.Employee;

public class CompanyQueryEmployeeDemo {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		SessionFactory factory = new Configuration()
				.configure("hibernate.cfg.xml")
				.addAnnotatedClass(Employee.class)
				.buildSessionFactory();
		
		Session session = factory.getCurrentSession();
		
		// Demo retrieving all employees with a company 
		try {
			session.beginTransaction();
			// Query all employees whose company is Google
			List<Employee> employees = session.createQuery("from Employee e where e.company='Google'").getResultList();
			
			// Print out the employees
			for (Employee employee : employees) {
				System.out.println(employee);
			}
			
			session.getTransaction().commit();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			session.close();
			factory.close();
		}
	}

}
