package com.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Pattern;

@Entity
@Table(name = "customer")
public class Customer {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private int id;

	// Name format is at least two characters, the first being capital
	@Pattern(regexp = "^[A-Z]{1}[a-z]+", message = "Must start captialized and have 2 or more characters")
	@Column(name = "first_name")
	private String firstName;

	// Name format is at least two characters, the first being capital
	@Pattern(regexp = "^[A-Z]{1}[a-z]+", message = "Must start captialized and have 2 or more characters")
	@Column(name = "last_name")
	private String lastName;
	
	// E-mail format is *@*.*, where * is one or more characters
	@Pattern(regexp = "^[a-zA-Z0-9]+@{1}[a-zA-Z0-9]+\\.{1}[a-zA-Z0-9]+", message = "Must follow e-mail format")
	@Column(name = "email")
	private String email;

	public Customer() {
	}

	public Customer(String firstName, String lastName, String email) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = email;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	@Override
	public String toString() {
		return "Customer [id=" + id + ", firstName=" + firstName + ", lastName=" + lastName + ", email=" + email + "]";
	}
}
