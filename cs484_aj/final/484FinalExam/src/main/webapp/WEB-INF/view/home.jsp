<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<title>Student Database</title>
<link href="${pageContext.request.contextPath}/resources/home.css"
	rel="stylesheet" />
</head>
<body>
	<h2>Students</h2>
	<table>
		<tr>
			<th>Name</th>
			<th>Punch line</th>
			<th>Hobby</th>
		</tr>
		<c:forEach var="student" items="${list}">
			<tr>
				<td>${student.name}</td>
				<td>${student.detail.punchLine}</td>
				<td>${student.detail.hobby}</td>
				<td><em><a href="editStudent?id=${student.id}">Edit</a></em></td>
				<td><em><a href="deleteStudent?id=${student.id}"
						onclick="return confirm('Are you sure want to delete this student?')">Delete</a></em></td>
			</tr>
		</c:forEach>
	</table>
	<br>
	<em><a href="newStudent">Add New Student</a></em>
</body>
</html>