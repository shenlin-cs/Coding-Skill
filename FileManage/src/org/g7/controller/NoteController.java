package org.g7.controller;

import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.g7.domin.APIResult;
import org.g7.domin.JwtService;
import org.g7.domin.Login;
import org.g7.domin.ResponseData;
import org.g7.domin.User;
import org.g7.service.NoteService;
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;

@Controller
public class NoteController {
	
	@Autowired
	@Qualifier("noteService")
	private NoteService noteService;
	
	@RequestMapping(value = "/IsClerkDealUpdate")
	public ModelAndView IsClerkDealUpdate(String type, String recoderId, 
			String IsClerkDeal, ModelAndView mv) {
		int res = 0;
		if(type.equals("转入记录")) {
			res = noteService.UpdateTransferinNoteIsClerkDeal(IsClerkDeal, recoderId);
		}
		else if(type.equals("转出记录")) {
			res = noteService.UpdateTransferoutNoteIsClerkDeal(IsClerkDeal, recoderId);
		}
		else if(type.equals("讨论记录")) {
			res = noteService.UpdateDiscussionNoteIsClerkDeal(IsClerkDeal, recoderId);
		}
		else if(type.equals("检查记录")) {
			res = noteService.UpdateCheckNoteIsClerkDeal(IsClerkDeal, recoderId);
		}
		else if(type.equals("手术记录")) {
			res = noteService.UpdateOperationNoteIsClerkDeal(IsClerkDeal, recoderId);
		}
		else {
			mv.addObject("message", "记录类型有误！");
			System.out.println("类型有误！");
		}
		if (res != 0) {
			mv.addObject("message", "更新成功!");
			mv.setViewName("clerk_1");
		} else {
			mv.addObject("message", "更新失败!");
			mv.setViewName("clerk_1");
		}
		return mv;
	}

}
