package org.g7.controller;

import java.util.ArrayList;
import java.util.List;

import org.g7.domin.Audit;
import org.g7.domin.Page;
import org.g7.service.AuditDoneService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * 处理图书请求控制�?
 * */
@Controller
public class AuditDoneController {
	
	/**
	 * 自动注入BookService
	 * */
	@Autowired
	@Qualifier("auditDoneService")
	private AuditDoneService auditDoneService;

	/**
	 * 处理/main请求
	 * */
	@RequestMapping(value="/audit_2")
	 public String auditdone(String intpage,String select,Model model){
		// 获得�?有图书集�?
		List<Audit> auditDone_list = auditDoneService.getAll();		
		// 将图书集合添加到model当中
		model.addAttribute("auditDone_list", auditDone_list);
		model.addAttribute("listsize", auditDone_list.size());
		// 跳转到main页面
		return "audit_2";
	}
	
}
