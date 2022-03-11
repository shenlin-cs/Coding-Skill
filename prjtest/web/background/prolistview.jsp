<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="com.phome.db.ProductDAO"%>
<%@page import="com.phome.vo.ProductVo"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'prolistview.jsp' starting page</title>
    
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
       ProductDAO dao=new ProductDAO();
       ArrayList list=dao.getAllProduct();
  %>
  <body>
      <table width="800" align="center" bgcolor="#cccccc" border="0" cellspacing="1" cellpadding="1">
         <tr bgcolor="#FFFFFF">
            <td>id</td>
            <td>名称</td>
            <td>价钱</td>
            <td>图片</td>
            <td>删除</td>
            <td>修改</td>
            
         </tr>
         <%for(int i=0;i<list.size();i++){
        	 ProductVo pro=(ProductVo)list.get(i);
          %>
           <tr bgcolor="#FFFFFF">
            <td><%=pro.getProid() %></td>
            <td><%=pro.getProName() %></td>
            <td><%=pro.getPrice() %></td>
            <td><img alt="<%=pro.getProName() %>" src="<%=request.getContextPath() %><%=pro.getPicture() %>" width="80" height="100"/> </td>
            <td><a href="<%=request.getContextPath() %>/background/deleteproduct.jsp?proid=<%=pro.getProid() %>">删除</a></td>
            <td><a href="<%=request.getContextPath() %>/background/updateview.jsp?proid=<%=pro.getProid() %>">修改</a></td>
           </tr>
          <%
         } %>
      </table>
   
  </body>
</html>
