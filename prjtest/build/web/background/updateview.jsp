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
    
    <title>My JSP 'updateview.jsp' starting page</title>
    
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
  	String proid=request.getParameter("proid");
     ProductDAO dao=new ProductDAO();
     ProductVo pro=dao.getProductById(Integer.parseInt(proid));
     
  %>
  <body>
    <p align="center">修改商品</p>
    <form action="<%=request.getContextPath() %>/background/update.jsp" method="post">
       <input type="hidden" name="proid" value="<%=pro.getProid() %>"><!-- hidden是隐藏表单，是为了界面传值而设置的 -->
      <table width="400" align="center" bgcolor="#cccccc" border="0" cellspacing="1" cellpadding="1">
         <tr bgcolor="#FFFFFF">
            <td>商品名称：</td>
            <td><input type="text" name="proName" value="<%=pro.getProName() %>" style="width: 150px"/><%
                String proname=request.getParameter("proname");
            
            %> <span style="color: red"><%="fail".equals(proname)?"商品名称不能为空":"" %></span></td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td>价格：</td>
            <td><input type="text" name="proPrice" value="<%=pro.getPrice() %>" style="width: 150px"/><%
                String price=request.getParameter("price");
            %> <span style="color: red"><%="fail1".equals(price)?"价格不能为空":"" %>  <%="fail2".equals(price)?"价格只能是数字":"" %></span></td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td>图片：</td>
            <td><img alt="<%=pro.getProName() %>" src="<%=request.getContextPath() %><%=pro.getPicture() %>" width="80" height="100"/>
            <input type="text" name="proPicture" value="<%=pro.getPicture() %>" style="width: 200px"/> </td>
         </tr>
         <tr bgcolor="#FFFFFF">
            <td><input type="submit" value="修改"> </td>
            <td><input type="reset" name="重写" /> </td>
         </tr>
      </table>
    </form>
  </body>
</html>
