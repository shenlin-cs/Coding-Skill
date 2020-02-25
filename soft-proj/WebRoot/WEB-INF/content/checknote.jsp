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
    <title>检查记录</title>    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  
  <body>
    <h3 style="text-align:center">检查记录</h3>
    <form action="insertCheckNote" method="post">
    <div style="text-align:center">
    <span ><font color="red">${requestScope.feedback}</font></span>
    </div>
	    <table style="margin-left:10px;width:98%" border='1' class="table table-striped">
	    	<div>
	    		<tr>
		    		<th>检查编号</th><td><input id="CheckID" name="CheckID"/></td>
		    		<th>检查室</th><td><input id="CheckRoomID" name="CheckRoomID"/></td>
		    		<th>检查室负责人编号</th><td><input id="CheckHeadID" name="CheckHeadID"/></td>
		    		<th>检查室负责人姓名</th><td><input id="CheckHeadName" name="CheckHeadName"/></td>
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
		    		<th>检查时间</th><td>
		    		<input type="text" class="Wdate"
						onClick="WdatePicker({lang:'zh-cn',dateFmt:'yyyy-MM-dd HH:mm',minDate:new Date(),})"
						id="CheckTime" name="CheckTime" style="height:28px"></td>
	    		</tr>    		
	    	</div>
	    	<div>
	    		<tr>
		    		<th>参与人数</th><td><input id="ParticipantsNumber" name="ParticipantsNumber"/></td>
		    		<th>检查执行人</th><td><input id="CheckExcuter" name="CheckExcuter"/></td>
		    		<th>检查设备</th><td><input id="CheckEquipment" name="CheckEquipment"/></td>
		    		<th>检查药剂</th><td><input id="CheckMedicament" name="CheckMedicament"/></td>
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
	    		<th>检查目的</th>
	    		<td colspan=7><textarea style="width:100%;height:40px" id="CheckAim" name="CheckAim"></textarea></td>
	    	</tr>
	    	<tr>
		    	<th>检查结果</th>
		    	<td colspan=7><textarea style="width:100%;height:80px" id="CheckResult" name="CheckResult"></textarea></td>
		    </tr>
	    </table>
	  
	    <div  style="text-align:center">
		    <Button >提交</Button>
		    <Button type="reset">重置</Button>
	    </div>
    </form> 
  </body>
</html>
