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
    <title>讨论记录</title>    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  
  <body>
    <h3 style="text-align:center">讨论记录</h3>
    <form action="insertDiscussionNote" method="post">
    <div style="text-align:center">
    	<span ><font color="red">${requestScope.feedback}</font></span>
    </div>
	    <table style="margin-left:10px;width:98%" border='1' class="table table-striped">
	    	<div>
	    		<tr>
		    		<th>讨论编号</th><td><input id="DiscussionID" name="DiscussionID"/></td>
		    		<th>讨论室</th><td><input id="DiscussionRoomID" name="DiscussionRoomID"/></td>
		    		<th>讨论室负责人编号</th><td><input id="DiscussionHeadID" name="DiscussionHeadID"/></td>
		    		<th>讨论室负责人姓名</th><td><input id="DiscussionHeadName" name="DiscussionHeadName"/></td>
	    		</tr>
	    	</div>
	    	<div>
	    		<tr>
		    		<th>PI姓名</th><td><input id="PIName" name="PIName"/></td>
		    		<th>PIID</th><td><input id="PIID" name="PIID"/></td>
		    		<th>联系方式</th><td><input id="PIPhoneNumber" name="PIPhoneNumber"/></td>
		    		<th>PI所属团队</th><td><input id="PITeamName" name="PITeamName"/></td>
	    		</tr>    		
	    	</div>    	
	    	<div>
	    		<tr>
		    		<th>所属实验编号</th><td><input id="ExperimentID" name="ExperimentID"/></td>
		    		<th>所属实验名称</th><td><input id="ExperimentName" name="ExperimentName"/></td>
		    		<th>实验动物</th><td><input id="AnimalID" name="AnimalID"/></td>
		    		<th>讨论时间</th><td>
		    		<input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="DiscussionTime" name="DiscussionTime" style="height:28px"></td>
	    		</tr>    		
	    	</div>
	    	<div>
	    		<tr>
		    		<th>讨论名称</th><td><input id="DiscussionName" name="DiscussionName"/></td>
		    		<th>讨论执行人</th><td><input id="DiscussionExcuter" name="DiscussionExcuter"/></td>
		    		<th>讨论设备</th><td><input id="DiscussionEquipment" name="DiscussionEquipment"/></td>
		    		<th>讨论药剂</th><td><input id="DiscussionMedicament" name="DiscussionMedicament"/></td>
	    		</tr>    		
	    	</div>
	    	<div>
	    		<tr>
		    		<th>文书类别</th>
		    		<td>	    			    		
		    		<select id="IsEstablished" name="IsEstablished" ">
                	<option value="是">终稿</option>
                	<option value="否">待修改</option>
                	</select>
                	</td>
	    		</tr>    
	    	</div>
	    	
	    	<tr>  	
	    		<th>讨论目的</th>
	    		<td colspan=7><textarea style="width:100%;height:40px" id="DiscussionAim" name="DiscussionAim"></textarea></td>
	    	</tr>
	    	<tr>
		    	<th>讨论结果</th>
		    	<td colspan=7><textarea style="width:100%;height:80px" id="DiscussionResult" name="DiscussionResult"></textarea></td>
		    </tr>
	    </table>
	    <div  style="text-align:center">
		    <Button >提交</Button>
		    <Button type="reset">重置</Button>
	    </div>
    </form> 
  </body>
</html>
