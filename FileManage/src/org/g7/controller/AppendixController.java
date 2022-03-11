package org.g7.controller;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.servlet.http.HttpServletResponse;
import javax.ws.rs.core.Response;

import org.g7.domin.Application_Information;
import org.g7.domin.User;
import org.g7.service.Application_InformationService;
import org.g7.service.AuditService;
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;
/**
 * 澶勭悊鍥句功璇锋眰鎺у埗鍣?
 * */
@Controller
public class AppendixController {
	
	/**
	 * 鑷姩娉ㄥ叆BookService
	 * */
	@Autowired
	@Qualifier("Application_InformationService")
	private Application_InformationService application_InformationService1;
	
	@Autowired
	@Qualifier("userService")
	private UserService userService;
	
	@Autowired
	@Qualifier("AuditService")
	private AuditService auditService;

	/**
	 * 澶勭悊/main璇锋眰
	 * */
	@RequestMapping(value="/appendixrequest")
	 public void appendix(String ApplicationID,Model model,ModelAndView mv,HttpServletResponse response){		
		System.out.println(ApplicationID);
		Application_Information Application_Information_content = application_InformationService1.getUserById(ApplicationID);
		//本地的pdf文件路径
		String FilePath=Application_Information_content.applicationOperateContent;
		System.out.println(FilePath);
		try {      		
           showPdf(response,FilePath);
        }catch (Exception e) {
           mv.addObject("message", "未找到文件");
           mv.setViewName("dealaudit");
           e.printStackTrace();
        }		
	}	
	public static void showPdf( HttpServletResponse response, String fileName) throws IOException{
        response.setContentType("application/pdf");
        FileInputStream in = new FileInputStream(new File(fileName));
        OutputStream out = response.getOutputStream();
        byte[] b = new byte[1024];
        while ((in.read(b))!=-1) {
            out.write(b);
        }
        out.flush();
        in.close();
        out.close();
    }		
	
	@RequestMapping(value="/autoaudit")
	 public String autoaudit(String ApplicationID,Model model,ModelAndView mv,HttpServletResponse response){		
		Application_Information Application_Information_content = application_InformationService1.getUserById(ApplicationID);
		//本地的pdf文件路径
		model.addAttribute("Application_Information_content", Application_Information_content);
		String feedbackmessage="";
		//申请书信息完整性
		if(Application_Information_content.applicationID.equals("")) {
			feedbackmessage+="申请书编号为空,";
		}
		if(Application_Information_content.applicationName.equals("")) {
			feedbackmessage+="申请书名称为空,";
		}
		if(Application_Information_content.applicationOperateType.equals("")) {
			feedbackmessage+="操作类型为空,";
		}
		if(Application_Information_content.applicationOperateContent.equals("")) {
			feedbackmessage+="操作内容为空,";
		}
		if(Application_Information_content.recordtype.equals("")) {
			feedbackmessage+="记录类型为空,";
		}
		if(Application_Information_content.experimentID.equals("")) {
			feedbackmessage+="实验编号为空,";
		}
		if(Application_Information_content.applicantID.equals("")) {
			feedbackmessage+="申请者编号为空,";
		}
		if(Application_Information_content.applicantName.equals("")) {
			feedbackmessage+="申请者姓名为空,";
		}
		if(Application_Information_content.applicantPhoneNumber.equals("")) {
			feedbackmessage+="申请者联系方式为空,";
		}
		if(Application_Information_content.departmentID.equals("")) {
			feedbackmessage+="申请者部门编号为空,";
		}
		if(Application_Information_content.departmentName.equals("")) {
			feedbackmessage+="申请者部门名为空,";
		}
		if(Application_Information_content.applicationTime.equals("")) {
			feedbackmessage+="申请时间为空,";
		}
		if(Application_Information_content.clerkID.equals("")) {
			feedbackmessage+="柜员编号为空,";
		}
		if(Application_Information_content.clerkName.equals("")) {
			feedbackmessage+="柜员姓名为空,";
		}
		//信息无误性
		//根据申请者ID查g3_staff的员工信息
		User user = userService.findInfo(Application_Information_content.applicantID);
		if(user==null) {
			feedbackmessage+="申请者不存在,";
		}else {
			if(Application_Information_content.applicationID.equals(user.getLoginID())) {
				if(!Application_Information_content.applicantName.equals(user.getStaffName())) {
					feedbackmessage+="申请者编号和姓名不一致,";
				}
			}
			if(!Application_Information_content.applicantPhoneNumber.equals(user.getStaffPhone())) {
				feedbackmessage+="申请者联系方式有误,";
			}
			if(!Application_Information_content.departmentName.equals(user.getDepartmentName())) {
				feedbackmessage+="申请者部门名称有误,";
			}
			if(!Application_Information_content.departmentID.equals(user.getDepartmentID())) {
				feedbackmessage+="申请者部门ID有误,";
			}			
		}	
		//根据柜员的ID查g3_staff的员工信息
		User clerk = userService.findInfo(Application_Information_content.clerkID);
		if(clerk==null) {
			feedbackmessage+="柜员不存在,";
		}else {
			if(Application_Information_content.clerkID.equals(clerk.getLoginID())) {
				if(!Application_Information_content.clerkName.equals(clerk.getStaffName())) {
					feedbackmessage+="柜员编号与柜员姓名不一致,";
				}
			}
		}	
		//判断申请日期
		Date getDate = Calendar.getInstance().getTime();
		String date = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(getDate);
		System.out.println("日期加时间:" + date);
		if(Application_Information_content.applicationTime.compareTo(date)>0) {
			feedbackmessage+="申请日期有误,";
		}
		if(Application_Information_content.applicationOperateType.contains("增")) {
			if(Application_Information_content.applicationOperateType.contains("删")
					||Application_Information_content.applicationOperateType.contains("改")) {
				feedbackmessage+="操作类型不能同时出现增与删改,";
			}
		}else if(Application_Information_content.applicationOperateType.contains("删")||
				Application_Information_content.applicationOperateType.contains("改")) {
			if(Application_Information_content.recordtype.contains("实验记录")) {
				if(Application_Information_content.experimentID.equals("")) {
					feedbackmessage+="记录类型中的实验记录编号为空,";
				}else {//查实验的存在性
					ExperimentNote note=auditService.ExperimentExists(Application_Information_content.experimentID);
					if(note==null) {
						feedbackmessage+="实验记录不存在,";
					}
				}
			}			
			if(Application_Information_content.recordtype.contains("手术记录")){
				if(Application_Information_content.operationID.equals("")) {
					feedbackmessage+="记录类型中的手术记录编号为空,";
				}else {//查实验的存在性
					OperationNote note=auditService.OperationExists(Application_Information_content.operationID);
					if(note==null) {
						feedbackmessage+="手术记录不存在,";
					}else if(!note.getOperationID().equals(Application_Information_content.operationID)) {
						feedbackmessage+="实验ID与手术记录ID不匹配,";
					}
				}
			}
			if(Application_Information_content.recordtype.contains("检查记录")) {
				if(Application_Information_content.inspectID.equals("")) {
					feedbackmessage+="记录类型中的检查记录编号为空,";
				}else {//查实验的存在性
					CheckNote note=auditService.InspectExists(Application_Information_content.inspectID);
					if(note==null) {
						feedbackmessage+="检查记录不存在,";
					}else if(!note.getCheckID().equals(Application_Information_content.inspectID)) {
						feedbackmessage+="实验ID与检查记录ID不匹配,";
					}
				}
			}
			if(Application_Information_content.recordtype.contains("讨论记录")) {
				if(Application_Information_content.discussionID.equals("")) {
					feedbackmessage+="记录类型中的讨论记录编号为空,";
				}else {//查实验的存在性
					DiscussionNote note=auditService.DiscussionExists(Application_Information_content.discussionID);
					if(note==null) {
						feedbackmessage+="讨论记录不存在,";
					}else if(!note.getDiscussionID().equals(Application_Information_content.discussionID)) {
						feedbackmessage+="实验ID与讨论记录ID不匹配,";
					}					
				}
			}
			if(Application_Information_content.recordtype.contains("转入记录")) {
				if(Application_Information_content.rollinID.equals("")) {
					feedbackmessage+="记录类型中的转入记录编号为空,";
				}else {//查实验的存在性
					TransferinNote note=auditService.RollInExists(Application_Information_content.rollinID);
					if(note==null) {
						feedbackmessage+="转入记录不存在,";
					}else if(!note.getTransferinID().equals(Application_Information_content.rollinID)) {
						feedbackmessage+="实验ID与转入记录ID不匹配,";
					}
				}
			}
			if(Application_Information_content.recordtype.contains("转出记录")) {
				if(Application_Information_content.rolloutID.equals("")) {
					feedbackmessage+="记录类型中的转出记录编号为空,";
				}else {//查实验的存在性
					TransferoutNote note=auditService.RollOutExists(Application_Information_content.rolloutID);
					if(note==null) {
						feedbackmessage+="转出记录不存在,";
					}else if(!note.getTransferoutID().equals(Application_Information_content.rolloutID)) {
						feedbackmessage+="实验ID与转出记录ID不匹配,";
					}
				}
			}

		}		
		model.addAttribute("feedbackmessage", feedbackmessage);
		return "audit_3";			
	}	
}
