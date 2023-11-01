<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<title>Customer Relationship Manager</title>
<link href="${pageContext.request.contextPath}/resources/home.css"
	rel="stylesheet" />
</head>
<body>
	<h2>Customer Relationship Manager</h2>
	<table>
		<tr>
			<th>First name</th>
			<th>Last name</th>
			<th>E-mail</th>
		</tr>
		<c:forEach var="customer" items="${list}">
			<tr>
				<td>${customer.firstName}</td>
				<td>${customer.lastName}</td>
				<td>${customer.email}</td>
				<td><em><a href="editCustomer?id=${customer.id}">Edit</a></em></td>
				<td><em><a href="deleteCustomer?id=${customer.id}"
						onclick="return confirm('Are you sure want to delete this customer?')">Delete</a></em></td>
			</tr>
		</c:forEach>
	</table>
	<br>
	<em><a href="newCustomer">Add New Customer</a></em>
</body>
</html>