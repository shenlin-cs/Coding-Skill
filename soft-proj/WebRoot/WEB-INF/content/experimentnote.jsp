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
    <title>实验记录</title>    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  
  <body>
    <h3 style="text-align:center">实验记录</h3>    
    <form action="insertExperimentNote" method="post">
    <div style="text-align:center">
    	<span ><font color="red">${requestScope.feedback}</font></span>
    </div>
	    <table style="margin-left:10px;width:98%" border='1' class="table table-striped">
	    	<div>
	    		<tr>
		    		<th>负责人姓名</th><td><input id="Name" name="Name"/></td>
		    		<th>实验编号</th><td><input id="ExperimentID" name="ExperimentID"/></td>
		    		<th>负责人编号</th><td><input id="EmployeeID" name="EmployeeID"/></td>
		    		<th>联系方式</th><td><input id="Contact" name="Contact"/></td>
	    		</tr>
	    	</div>
	    	<div>
	    		<tr>
		    		<th>PI姓名</th><td><input id="PIName" name="PIName"/></td>
		    		<th>PI-ID</th><td><input id="PIID" name="PIID"/></td>
		    		<th>部门名称</th><td><input id="Department" name="Department"/></td>
		    		<th>分平台名称</th><td><input id="BranchName" name="BranchName"/></td>
	    		</tr>    		
	    	</div>    	
	    	<div>
	    		<tr>
		    		<th>实验动物编号</th><td><input id="AnimalID" name="AnimalID"/></td>
		    		<th>实验动物种类</th><td><input id="AnimalSpecies" name="AnimalSpecies"/></td>
		    		<th>实验房间</th><td><input id="ExperimentRoom" name="ExperimentRoom"/></td>
		    		<th>实验时间</th><td><input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="ExperimentDate" name="ExperimentDate" style="height:28px"></td>
	    		</tr>    		
	    	</div>
	    	<div>
	    		<tr>
		    		<th>开始时间</th><td>
		    		<input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="ExperimentStartTime" name="ExperimentStartTime" style="height:28px"></td>
		    		<th>结束时间</th><td>
		    		<input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="ExperimentEndTime" name="ExperimentEndTime" style="height:28px"></td>
		    		<th>录入时间</th><td>
		    		<input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="ExperimentNoteTime" name="ExperimentNoteTime" style="height:28px"></td>
		    		<th>备注</th><td><input id="ExperimentNote" name="ExperimentNote"/></td>
	    		</tr>    		
	    	</div>
	  
	    	<tr>  	
	    		<th>实验目的</th>
	    		<td colspan=7><textarea style="width:100%;height:40px" id="ExperimentPurpose" name="ExperimentPurpose"></textarea></td>
	    	</tr>
	    	<tr>
		    	<th>实验内容</th>
		    	<td colspan=7><textarea style="width:100%;height:80px" id="ExperimentContent" name="ExperimentContent"></textarea></td>
		    </tr>
	   		<tr>
	    		<th>实验步骤</th>
	    		<td colspan=7><textarea style="width:100%;height:80px id="ExperimentStep" name="ExperimentStep"></textarea></td>
	    	</tr>	   		
	    	<tr>
	    		<th>实验结论</th>
	    		<td colspan=7><textarea style="width:100%;height:50px id="ExperimentConclusion" name="ExperimentConclusion"></textarea></td>
	    	</tr>    	
	    </table>
	    <div  style="text-align:center">
		    <Button >提交</Button>
		    <Button  type="reset">重置</Button>
	    </div>
    </form> 
  </body>
</html>
