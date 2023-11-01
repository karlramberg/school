<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<!DOCTYPE html>
<html>
<head>
<title>Add/Edit Student</title>
<link
	href="${pageContext.request.contextPath}/resources/studentForm.css"
	rel="stylesheet" />
</head>
<body>
	<h2>Add/Edit Student</h2>
	<form:form action="saveStudent" method="post"
		modelAttribute="student">
		<table>
			<form:hidden path="id" />
			<tr>
				<td>Name:</td>
				<td><form:input path="name" /></td>
			</tr>
			<tr>
				<td>Punch line:</td>
				<td><form:input path="detail.punchLine" /></td>
			</tr>
			<tr>
				<td>Hobby:</td>
				<td><form:input path="detail.hobby" /></td>
			</tr>
			<tr>
				<td colspan="2" align="center"><input type="submit"
					value="Save"></td>
			</tr>
		</table>
	</form:form>
</body>
</html>