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
import org.g7.domin.ExperimentNote;
import org.g7.domin.Page;
import org.g7.domin.filelocation;
import org.g7.service.Application_InformationService;
import org.g7.service.AuditService;
import org.g7.service.NoteService;
import org.g7.service.PrintFileService;
import org.g7.service.UpdateFileService;
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class PrintFileController {
	
	@Autowired
	@Qualifier("PrintFileService")
	private PrintFileService printFileService;
	
	@Autowired
	@Qualifier("noteService")
	private NoteService noteService;

	@RequestMapping(value="/printfile")
	 public String audit(String intpage,String select,Model model){	
		List<ExperimentNote> printfile_list = printFileService.getAll();
		model.addAttribute("listsize", printfile_list.size());
		model.addAttribute("printfile_list", printfile_list);	
		for(int i=0;i<printfile_list.size();i++) {
			System.out.println(printfile_list.get(i));
		}
		return "printfile";
	}	
	
	@RequestMapping(value="/printlist")
	 public String printlist(String intpage,String select,Model model){	
		List<filelocation> printfile_list = printFileService.getAllprintlist();
		model.addAttribute("listsize", printfile_list.size());
		model.addAttribute("printfile_list", printfile_list);	
		for(int i=0;i<printfile_list.size();i++) {
			System.out.println(printfile_list.get(i));
		}
		return "printlist";
	}	
	
	@RequestMapping(value = "/api/isprintquery")
	@ResponseBody
	public APIResult ApplicationIDAuditedQuery(
			@RequestParam(name="isprint",required=true) String isprint,
			@RequestParam(name="token",required=true) String token) {
		return printFileService.Isprintlist(isprint);
	}
	
	@RequestMapping(value = "/updatefilelocation")
	public ModelAndView updatefilelocation(String ExperimentID, ModelAndView mv) {	
		String ShelfLocation = ExperimentID.substring(0,ExperimentID.length()-3);
		String LayLocation = ExperimentID.substring(ExperimentID.length()-3,ExperimentID.length());
		int res = noteService.updatefilelocation(ShelfLocation, LayLocation, ExperimentID);
		if (res != 0) {
			mv.addObject("message", "更新成功!");
			mv.setViewName("updatefile");
			System.out.print("updatesuccess");
		} else {
			mv.addObject("message", "更新失败!");
			mv.setViewName("updatefile");
			System.out.print("updatefail");
		}
		return mv;
	}
	
	
	
}
