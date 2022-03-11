package org.g7.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.g7.domin.APIResult;
import org.g7.domin.Application_Information;
import org.g7.domin.Audit;
import org.g7.domin.Page;
import org.g7.service.Application_InformationService;
import org.g7.service.AuditService;
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

/**
 * 澶勭悊鍥句功璇锋眰鎺у埗鍣?
 * */
@Controller
public class AuditController {
	
	/**
	 * 鑷姩娉ㄥ叆BookService
	 * */
	@Autowired
	@Qualifier("AuditService")
	private AuditService auditService;

	/**
	 * 澶勭悊/main璇锋眰
	 * */
	@RequestMapping(value="/audit_1")
	 public String audit(String intpage,String select,Model model){	
		// 鑾峰緱鎵?鏈夊浘涔﹂泦鍚?
		List<Audit> audit_list = auditService.getAll();
		model.addAttribute("audit_list", audit_list);
		// 璺宠浆鍒癿ain椤甸潰
		return "audit_1";
	}			
	
	@Autowired
	@Qualifier("Application_InformationService")
	private Application_InformationService application_InformationService;	
	//审核通过与不通过的处理
	@RequestMapping(value="/auditpass")
	 public ModelAndView auditpass(String ApplicationID,String AuditorID,
			 String AuditorName,String AuditTime,
			 String AuditResult,String Feedback,
			 Model model,ModelAndView mv,HttpServletResponse response) throws IOException{		
		System.out.println(ApplicationID);
		System.out.println(AuditorID);
		System.out.println(AuditorName);
		System.out.println(AuditTime);
		System.out.println(AuditResult);
		System.out.println(Feedback);	
		Application_Information Application_Information_content = application_InformationService.getUserById(ApplicationID);
		// 灏嗗浘涔﹂泦鍚堟坊鍔犲埌model褰撲腑
		model.addAttribute("Application_Information_content", Application_Information_content);
		if(AuditorID.equals("")) {
			mv.addObject("auditmessage", "审核人员编号不能为空");
			mv.setViewName("audit_3");
		}else if(AuditorName.equals("")) {
			mv.addObject("auditmessage", "审核人员姓名不能为空");
			mv.setViewName("audit_3");
		}else if(AuditTime.equals("")) {
			mv.addObject("auditmessage", "审核时间不能为空");
			mv.setViewName("audit_3");
		}else if(AuditResult.equals("")) {
			mv.addObject("auditmessage", "审核结果不能为空");
			mv.setViewName("audit_3");
		}else if(Feedback.equals("")) {
			mv.addObject("auditmessage", "反馈不能为空");
			mv.setViewName("audit_3");
		}else{
			
			//插入审核的信息并更新审核状态
			int status=auditService.UpdateAuditMessage(ApplicationID, AuditorID, AuditorName, AuditTime, AuditResult, Feedback);
			System.out.println(status);
			if(status==0) {
				mv.addObject("auditmessage", "提交审核信息不通过");
				mv.setViewName("audit_3");
			}else{
				//插入到audit_note表中
				auditService.InsertAuditNote(ApplicationID, AuditorID, AuditTime, Feedback, AuditResult);
				response.setContentType("text/html");
				response.setCharacterEncoding("utf-8");
				PrintWriter out =response.getWriter();
				out.print("<script type='text/javascript' charset='utf-8'>alert('提交审核信息通过!');window.location='audit_1'</script>");
				out.flush();		
				out.close();
				mv.setViewName("audit_1");
			}
		}
		return mv;
	}	
}
