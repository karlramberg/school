package com.hibernate;

import java.util.List;

import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.entity.Student;
import com.entity.StudentDetail;

@Repository
public class StudentDAO {
	@Autowired
	private SessionFactory factory;

	public void addStudent(Student student) {
		factory.getCurrentSession().saveOrUpdate(student);
	}

	@SuppressWarnings("unchecked")
	public List<Student> getStudents() {
		return factory.getCurrentSession().createQuery("from Student").list();
	}

	public Student getStudent(int id) {
		return factory.getCurrentSession().get(Student.class, id);
	}

	public Student updateStudent(Student student) {
		factory.getCurrentSession().update(student);
		return student;
	}

	public void deleteStudent(int id) {
		Student student = factory.getCurrentSession().load(Student.class, id);
		if (null != student) {
			this.factory.getCurrentSession().delete(student);
		}
	}
}
