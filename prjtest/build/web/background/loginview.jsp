<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'loginview.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
    <form action="<%=request.getContextPath() %>/background/login.jsp" method="post">
      <table width="400" align="center" bgcolor="#cccccc" border="0" cellspacing="1" cellpadding="1">
         <tr bgcolor="#FFFFFF">
            <td>用户名：</td>
            <td><input type="text" name="userName" style="width: 150px"/> </td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td>密码：</td>
            <td><input type="password" name="password" style="width: 150px"/> </td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td><input type="submit" value="登录"> </td>
            <td><input type="reset" name="重写" /> </td>
         </tr>
      </table>
    </form>
  </body>
</html>
