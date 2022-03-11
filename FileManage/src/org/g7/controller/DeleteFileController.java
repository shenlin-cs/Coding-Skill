package org.g7.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.g7.domin.Audit;
import org.g7.service.DeleteFileService;
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
public class DeleteFileController {
	
	/**
	 * 自动注入updateFileService
	 * */
	@Autowired
	@Qualifier("deleteFileService")
	private DeleteFileService deleteFileService;

	/**
	 * 处理/main请求
	 * */
	@RequestMapping(value="/deletefile")
	 public String audit(String intpage,String select,Model model){	
		// 获得�?有图书集�?
		List<Audit> deletefile_list = deleteFileService.getDelete();
		model.addAttribute("listsize", deletefile_list.size());
		model.addAttribute("deletefile_list", deletefile_list);	
		return "deletefile";
	}			
	
}
