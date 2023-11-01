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

import com.entity.Customer;
import com.hibernate.CustomerService;

@Controller
public class CustomerController {
	@Autowired
	public CustomerService customerService;

	@RequestMapping(value = "/")
	public ModelAndView listCustomer(ModelAndView model) throws IOException {
		List<Customer> list = customerService.getCustomers();
		model.addObject("list", list);
		model.setViewName("home");
		return model;
	}

	@RequestMapping(value = "/newCustomer", method = RequestMethod.GET)
	public ModelAndView newCustomer(ModelAndView model) {
		Customer customer = new Customer();
		model.addObject("customer", customer);
		model.setViewName("customer-form");
		return model;
	}

	@RequestMapping(value = "/saveCustomer", method = RequestMethod.POST)
	public ModelAndView saveCustomer(@Valid @ModelAttribute Customer customer, BindingResult result) {
		if (result.hasErrors()) {
			return new ModelAndView("customer-form");
		} else {
			if (customer.getId() == 0) {
				customerService.addCustomer(customer);
			} else {
				customerService.updateCustomer(customer);
			}
		}
		return new ModelAndView("redirect:/");
	}

	@RequestMapping(value = "/deleteCustomer", method = RequestMethod.GET)
	public ModelAndView deleteCustomer(HttpServletRequest request) {
		int id = Integer.parseInt(request.getParameter("id"));
		customerService.deleteCustomer(id);
		return new ModelAndView("redirect:/");
	}

	@RequestMapping(value = "/editCustomer", method = RequestMethod.GET)
	public ModelAndView editCustomer(HttpServletRequest request) {
		int id = Integer.parseInt(request.getParameter("id"));
		Customer customer = customerService.getCustomer(id);
		ModelAndView model = new ModelAndView("customer-form");
		model.addObject("customer", customer);

		return model;
	}
}
