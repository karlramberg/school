<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<!DOCTYPE html>
<html>
<head>
<title>New/Edit Contact</title>
<link
	href="${pageContext.request.contextPath}/resources/customerForm.css"
	rel="stylesheet" />
</head>
<body>
	<h2>Add/Edit Customer</h2>
	<form:form action="saveCustomer" method="post"
		modelAttribute="customer">
		<table>
			<form:hidden path="id" />
			<tr>
				<td>First name:</td>
				<td><form:input path="firstName" /></td>
				<td><form:errors path="firstName" cssClass="error" /></td>
			</tr>
			<tr>
				<td>Last name:</td>
				<td><form:input path="lastName" /></td>
				<td><form:errors path="lastName" cssClass="error" /></td>
			</tr>
			<tr>
				<td>E-mail:</td>
				<td><form:input path="email" /></td>
				<td><form:errors path="email" cssClass="error" /></td>
			</tr>
			<tr>
				<td colspan="2" align="center"><input type="submit"
					value="Save"></td>
			</tr>
		</table>
	</form:form>
</body>
</html>