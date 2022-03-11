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
import org.g7.service.UpdateFileService;
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
public class UpdateFileController {
	
	/**
	 * 自动注入updateFileService
	 * */
	@Autowired
	@Qualifier("updateFileService")
	private UpdateFileService updateFileService;

	/**
	 * 处理/main请求
	 * */
	@RequestMapping(value="/updatefile")
	 public String audit(String intpage,String select,Model model){	
		// 获得�?有图书集�?
		List<Audit> updatefile_list = updateFileService.getUpdate();
		model.addAttribute("listsize", updatefile_list.size());
		model.addAttribute("updatefile_list", updatefile_list);	
		return "updatefile";
	}			
	
}
