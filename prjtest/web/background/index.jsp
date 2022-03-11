<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="com.phome.vo.UsersVo"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  <%
  //登录验证，如果没有登录，需要先进行登录操作
      UsersVo user=(UsersVo)session.getAttribute("usersLogined");
      if (user==null)
      {
    	  response.sendRedirect(request.getContextPath()+"/background/loginview.jsp");
    	  return;
      }
  %>
  <frameset rows="100,*">
      <frame name="topFrame" src="<%=request.getContextPath() %>/background/top.jsp"/>
      <frameset cols="200,*">
          <frame name="leftFrame" src="<%=request.getContextPath() %>/background/left.jsp"/>
          <frame name="mainFrame" src="<%=request.getContextPath() %>/background/main.jsp"/>
          
      </frameset>
  </frameset>
</html>
