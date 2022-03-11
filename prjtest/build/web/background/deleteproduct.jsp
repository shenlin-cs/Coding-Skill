<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="com.phome.db.ProductDAO"%>
<%
     String proid=request.getParameter("proid");
     ProductDAO dao=new ProductDAO();
     int rows=dao.deleteProduct(Integer.parseInt(proid));
     if (rows>0)
     {
    	 response.sendRedirect(request.getContextPath()+"/background/prolistview.jsp");
    	 return;
     }
     else
     {
    	 
     }
%>