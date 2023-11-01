package com.hibernate;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.entity.Customer;

@Service
@Transactional
public class CustomerService {
	@Autowired
	CustomerDAO dao;
	
	@Transactional
	public void addCustomer(Customer customer) {
		dao.addCustomer(customer);
	}

	@Transactional
	public List<Customer> getCustomers() {
		return dao.getCustomers();
	}

	public Customer getCustomer(int id) {
		return dao.getCustomer(id);
	}

	public Customer updateCustomer(Customer customer) {
		return dao.updateCustomer(customer);
	}

	@Transactional
	public void deleteCustomer(int id) {
		dao.deleteCustomer(id);
	}

	public CustomerDAO getCustomerDAO() {
		return dao;
	}

	public void setCustomerDAO(CustomerDAO dao) {
		this.dao = dao;
	}
}
