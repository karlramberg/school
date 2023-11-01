package com.hibernate;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.entity.Student;
import com.entity.StudentDetail;

@Service
@Transactional
public class StudentService {
	@Autowired
	StudentDAO dao;
	
	@Transactional
	public void addStudent(Student student) {
		dao.addStudent(student);
	}

	@Transactional
	public List<Student> getStudents() {
		return dao.getStudents();
	}

	public Student getStudent(int id) {
		return dao.getStudent(id);
	}

	public Student updateStudent(Student student) {
		return dao.updateStudent(student);
	}

	@Transactional
	public void deleteStudent(int id) {
		dao.deleteStudent(id);
	}

	public StudentDAO getStudentDAO() {
		return dao;
	}

	public void setStudentDAO(StudentDAO dao) {
		this.dao = dao;
	}
}
