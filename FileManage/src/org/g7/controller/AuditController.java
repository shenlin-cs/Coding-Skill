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
 * 处理图书请求控制�?
 * */
@Controller
public class AuditController {
	
	/**
	 * 自动注入BookService
	 * */
	@Autowired
	@Qualifier("AuditService")
	private AuditService auditService;

	/**
	 * 处理/main请求
	 * */
	@RequestMapping(value="/audit_1")
	 public String audit(String intpage,String select,Model model){	
		// 获得�?有图书集�?
		List<Audit> audit_list = auditService.getAll();
		model.addAttribute("audit_list", audit_list);
		// 跳转到main页面
		return "audit_1";
	}			
	
	@Autowired
	@Qualifier("Application_InformationService")
	private Application_InformationService application_InformationService;	
	//���ͨ���벻ͨ���Ĵ���
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
		// 将图书集合添加到model当中
		model.addAttribute("Application_Information_content", Application_Information_content);
		if(AuditorID.equals("")) {
			mv.addObject("auditmessage", "�����Ա��Ų���Ϊ��");
			mv.setViewName("audit_3");
		}else if(AuditorName.equals("")) {
			mv.addObject("auditmessage", "�����Ա��������Ϊ��");
			mv.setViewName("audit_3");
		}else if(AuditTime.equals("")) {
			mv.addObject("auditmessage", "���ʱ�䲻��Ϊ��");
			mv.setViewName("audit_3");
		}else if(AuditResult.equals("")) {
			mv.addObject("auditmessage", "��˽������Ϊ��");
			mv.setViewName("audit_3");
		}else if(Feedback.equals("")) {
			mv.addObject("auditmessage", "��������Ϊ��");
			mv.setViewName("audit_3");
		}else{
			
			//������˵���Ϣ���������״̬
			int status=auditService.UpdateAuditMessage(ApplicationID, AuditorID, AuditorName, AuditTime, AuditResult, Feedback);
			System.out.println(status);
			if(status==0) {
				mv.addObject("auditmessage", "�ύ�����Ϣ��ͨ��");
				mv.setViewName("audit_3");
			}else{
				//���뵽audit_note����
				auditService.InsertAuditNote(ApplicationID, AuditorID, AuditTime, Feedback, AuditResult);
				response.setContentType("text/html");
				response.setCharacterEncoding("utf-8");
				PrintWriter out =response.getWriter();
				out.print("<script type='text/javascript' charset='utf-8'>alert('�ύ�����Ϣͨ��!');window.location='audit_1'</script>");
				out.flush();		
				out.close();
				mv.setViewName("audit_1");
			}
		}
		return mv;
	}	
}
