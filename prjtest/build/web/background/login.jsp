<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="com.phome.db.UsersDao"%>
<%@page import="com.phome.vo.UsersVo"%>



<%
	String name="";
	String password="";
	
	
    name=request.getParameter("userName");
    password=request.getParameter("password");
    
    UsersDao userDao=new UsersDao();
    UsersVo user=userDao.getUsersByNameAndPwd(name,password);
    if (user==null)
    {
    	//登录失败
    }
    else
    {
    	//登录成功
    	session.setAttribute("usersLogined",user);
    	response.sendRedirect(request.getContextPath()+"/background/index.jsp");
    	return;
    }
    
%>