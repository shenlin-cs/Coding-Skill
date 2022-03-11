package org.g7.controller;
import org.g7.domin.Application_Information;
import org.g7.service.Application_InformationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * 处理图书请求控制�?
 * */
@Controller
public class  Application_InformationController{
	
	/**
	 * 自动注入BookService
	 * */
	@Autowired
	@Qualifier("Application_InformationService")
	private Application_InformationService application_InformationService;

	/**
	 * 处理/main请求
	 * */
	@RequestMapping(value="/dealauditrequest")
	 public String auditdone(String id,Model model){
		// 获得�?有图书集�?
		System.out.println("����id:"+id);
		Application_Information Application_Information_content = application_InformationService.getUserById(id);
		// 将图书集合添加到model当中
		model.addAttribute("Application_Information_content", Application_Information_content);
		System.out.println(Application_Information_content);		
		// 跳转到main页面
		return "audit_3";
	}
	
	//�鿴���������
	@RequestMapping(value="/lookup")
	public String lookup(String id,Model model){
		Application_Information Application_Information_content = application_InformationService.getUserById(id);
		// 将图书集合添加到model当中
		model.addAttribute("Application_Information_content", Application_Information_content);
		System.out.println(Application_Information_content);
		return "audit_4";
	}	
	
	//�鿴���������
	@RequestMapping(value="/lookuplist")
	public String lookuplist(String id,Model model){
		Application_Information Application_Information_content = application_InformationService.getUserById(id);
		// 将图书集合添加到model当中
		model.addAttribute("Application_Information_content", Application_Information_content);
		System.out.println(Application_Information_content);
		return "lookupauditlist";
	}	
	
	@RequestMapping(value="/printpreview")
	public String printview(String id,Model model){
		Application_Information Application_Information_content = application_InformationService.getUserById(id);
		// 将图书集合添加到model当中
		model.addAttribute("Application_Information_content", Application_Information_content);
		System.out.println(Application_Information_content);
		return "printpreview";
	}	
	
	
	
}
