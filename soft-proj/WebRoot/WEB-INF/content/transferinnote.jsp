<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<link href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
<script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>
<script src="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/js/bootstrap.min.js"></script>
<script src="./My97DatePicker/WdatePicker.js"></script>
<html>
  <head>
    <base href="<%=basePath%>">    
    <title>转入记录</title>    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  
  <body>
    <h3 style="text-align:center">转入记录</h3>
    <form action="insertTransferinNote" method="post">
    <div style="text-align:center">
    	<span ><font color="red">${requestScope.feedback}</font></span>
    </div>
	    <table style="margin-left:10px;width:98%" border='1' class="table table-striped">
	    	<div>
	    		<tr>	    		
		    		<th>转入编号</th><td><input id="TransferinID" name="TransferinID"/></td>
	    		</tr>
	    	</div>
	    	<div>
	    		<tr>	    		
		    		<th>研究员姓名</th><td><input id="researcher_name" name="researcher_name"/></td>
		    		<th>研究人员编号</th><td><input id="researcher_ID" name="researcher_ID"/></td>
		    		<th>负责人姓名</th><td><input id="in_charge_person_name" name="in_charge_person_name"/></td>
		    		<th>负责人编号</th><td><input id="in_charge_person_ID" name="in_charge_person_ID"/></td>
	    		</tr>
	    	</div>
	    	<div>
	    		<tr>
		    		<th>实验对象名称</th><td><input id="experimental_object" name="experimental_object"/></td>
		    		<th>实验对象编号</th><td><input id="object_number" name="object_number"/></td>
		    		<th>项目编号</th><td><input id="item_number" name="item_number"/></td>
		    		<th>项目名称</th><td><input id="item_name" name="item_name"/></td>
	    		</tr>    		
	    	</div>    	
	    	<div>
	    		<tr>
		    		<th>转入来源</th><td><input id="transferfromobject" name="transferfromobject"/></td>
		    		<th>转入时间</th><td>
		    		<input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="time" name="time" style="height:28px"></td>
					<th>文书类型</th>
		    		<td>	    			    		
		    		<select id="IsEstablished" name="IsEstablished" ">
                	<option value="是">终稿</option>
                	<option value="否">待修改</option>
                	</select>
                	</td>
	    		</tr>    		
	    	</div>    	
	    </table>
	    <div  style="text-align:center">
		    <Button >提交</Button>
		    <Button type="reset">重置</Button>
	    </div>
    </form> 
  </body>
</html>
