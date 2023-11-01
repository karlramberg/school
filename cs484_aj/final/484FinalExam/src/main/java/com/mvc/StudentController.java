package com.mvc;

import java.io.IOException;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import com.entity.Student;
import com.entity.StudentDetail;
import com.hibernate.StudentService;

@Controller
public class StudentController {
	@Autowired
	public StudentService studentService;

	@RequestMapping(value = "/")
	public ModelAndView listStudents(ModelAndView model) throws IOException {
		List<Student> list = studentService.getStudents();
		model.addObject("list", list);
		model.setViewName("home");
		return model;
	}

	@RequestMapping(value = "/newStudent", method = RequestMethod.GET)
	public ModelAndView newStudent(ModelAndView model) {
		Student student = new Student();
		model.addObject("student", student);
		model.setViewName("student-form");
		return model;
	}

	@RequestMapping(value = "/saveStudent", method = RequestMethod.POST)
	public ModelAndView saveStudent(@ModelAttribute Student student) {
		if (student.getId() == 0) {
			studentService.addStudent(student);
		} else {
			studentService.updateStudent(student);
		}
		return new ModelAndView("redirect:/");
	}

	@RequestMapping(value = "/deleteStudent", method = RequestMethod.GET)
	public ModelAndView deleteStudent(HttpServletRequest request) {
		int id = Integer.parseInt(request.getParameter("id"));
		studentService.deleteStudent(id);
		return new ModelAndView("redirect:/");
	}

	@RequestMapping(value = "/editStudent", method = RequestMethod.GET)
	public ModelAndView editStudent(HttpServletRequest request) {
		int id = Integer.parseInt(request.getParameter("id"));
		Student student = studentService.getStudent(id);
		ModelAndView model = new ModelAndView("student-form");
		model.addObject("student", student);

		return model;
	}
}
