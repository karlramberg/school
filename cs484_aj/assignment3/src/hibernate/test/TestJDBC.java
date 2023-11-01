package hibernate.test;

import java.sql.Connection;
import java.sql.DriverManager;

public class TestJDBC {
	public static void main(String[] args) {
		String jdbcUrl = "jdbc:mysql://localhost:3306/assignment3";
		String user = "hbstudent";
		String pass = "hbstudent";
		try {
			Connection connection = DriverManager.getConnection(jdbcUrl, user, pass);
			System.out.println("Connected");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}