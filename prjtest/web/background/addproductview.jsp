<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'addproductview.jsp' starting page</title>
    
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
    <p align="center">添加商品</p>
    <form action="<%=request.getContextPath() %>/background/addproduct.jsp" method="post">
      <table width="400" align="center" bgcolor="#cccccc" border="0" cellspacing="1" cellpadding="1">
         <tr bgcolor="#FFFFFF">
            <td>商品名称：</td>
            <td><input type="text" name="proName" style="width: 150px"/><%
                String proname=request.getParameter("proname");
            
            %> <span style="color: red"><%="fail".equals(proname)?"商品名称不能为空":"" %></span></td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td>价格：</td>
            <td><input type="text" name="proPrice" style="width: 150px"/><%
                String price=request.getParameter("price");
            %> <span style="color: red"><%="fail1".equals(price)?"价格不能为空":"" %>  <%="fail2".equals(price)?"价格只能是数字":"" %></span></td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td>图片：</td>
            <td><input type="text" name="proPicture" style="width: 200px"/> </td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td><input type="submit" value="添加"> </td>
            <td><input type="reset" name="重写" /> </td>
         </tr>
      </table>
    </form>
    
  </body>
</html>
