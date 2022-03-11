<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="com.phome.vo.ProductVo"%>
<%@page import="com.phome.db.ProductDAO"%>
<%
request.setCharacterEncoding("UTF-8");
String proName=request.getParameter("proName");
String proPrice=request.getParameter("proPrice");
String proPicture=request.getParameter("proPicture");
int proid=Integer.parseInt(request.getParameter("proid"));
//非空处理
if (proName==null || "".equals(proName))
{
	response.sendRedirect(request.getContextPath()+"/background/updateview.jsp?proname=fail");
	return;
}
if (proPicture==null )
{
	proPicture="";
}

if (proPrice==null || "".equals(proPrice) )
{
	response.sendRedirect(request.getContextPath()+"/background/updateview.jsp?price=fail1");
	return;
}

double price=0;
try{
	price=Double.parseDouble(proPrice);
}
catch(Exception e)
{
	response.sendRedirect(request.getContextPath()+"/background/updateview.jsp?price=fail2");
	return;
}


//添加到数据库

ProductVo pro=new ProductVo();
pro.setProName(proName);
pro.setPrice(price);
pro.setPicture(proPicture);
pro.setProid(proid);

ProductDAO dao=new ProductDAO();
int rows=dao.updateProduct(pro);
if (rows>0)
{
	response.sendRedirect(request.getContextPath()+"/background/prolistview.jsp");
	return;
}
else
{
	
}
%>
