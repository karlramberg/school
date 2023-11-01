package com.hibernate;

import java.util.List;

import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.entity.Customer;

@Repository
public class CustomerDAO {
	@Autowired
	private SessionFactory factory;

	public void addCustomer(Customer customer) {
		factory.getCurrentSession().saveOrUpdate(customer);
	}

	@SuppressWarnings("unchecked")
	public List<Customer> getCustomers() {
		return factory.getCurrentSession().createQuery("from Customer").list();
	}

	public Customer getCustomer(int id) {
		return factory.getCurrentSession().get(Customer.class, id);
	}

	public Customer updateCustomer(Customer customer) {
		factory.getCurrentSession().update(customer);
		return customer;
	}

	public void deleteCustomer(int id) {
		Customer customer = factory.getCurrentSession().load(Customer.class, id);
		if (null != customer) {
			this.factory.getCurrentSession().delete(customer);
		}
	}
}
