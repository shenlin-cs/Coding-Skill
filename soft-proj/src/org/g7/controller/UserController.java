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
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;




@Controller
public class UserController {
	
	@Autowired
	@Qualifier("userService")
	private UserService userService;
//	@RequestMapping(value="dologin", produces = "application/json; charset=utf-8")
//	 public ModelAndView login(
//			 String username,String password,
//			 ModelAndView mv,
//			 HttpSession session){
//		User user = userService.login(username, password);
//		if(user != null){
//			System.out.println(user.toString());
//			session.setAttribute("user", user);
//			mv.setView(new RedirectView("http://localhost:8080/FileManage/main"));
//		}
//		else{
//			mv.setViewName("login");
//			mv.addObject("message", "鐢ㄦ埛鍚嶆垨瀵嗙爜涓嶆纭�");
//		}
//		return mv;
//	}
	@RequestMapping(value="/dologin")
	@ResponseBody
	 public ResponseData login(
			 HttpServletRequest request,
			 HttpServletResponse response,
			 String username,String password,
			 HttpSession session){
		ResponseData responseData = ResponseData.ok();
		User user = userService.login(username, password);
		Login login = new Login();
		if(user != null){
			System.out.println(user.toString());
			login.setUserid(user.getStaffID());
			login.setLoginid(user.getLoginID());
			login.setLoginpassword(user.getLoginPassword());
			login.setUsername(user.getStaffName());
			login.setGender(user.getStaffGender());
			login.setPhone(user.getStaffPhone());
			login.setEmail(user.getE_mail());
			String token = JwtService.sign(login, 30L*60L*1000L);
            responseData.putDataValue("loginId", login.getLoginid());
            responseData.putDataValue("username", login.getUsername());
            responseData.putDataValue("token", token);
            request.getSession().setAttribute("loginId",login.getLoginid());
            request.getSession().setAttribute("username",login.getUsername());
            Cookie cookie = new Cookie("loginid",login.getLoginid());//创建新cookie
            cookie.setMaxAge(24 * 60 * 60);
            cookie.setPath("/");
            response.addCookie(cookie);
	        return responseData;
		}
		else{
			responseData =  ResponseData.customerError();
			return responseData;
		}
	}
	
//	@RequestMapping(value="userinfo", produces = "application/json; charset=utf-8")
//	 public ModelAndView login(
//			 String username,String password,
//			 ModelAndView mv,
//			 HttpSession session){
//		User user = userService.login(username, password);
//		if(user != null){
//			System.out.println(user.toString());
//			session.setAttribute("user", user);
//			mv.setView(new RedirectView("http://localhost:8080/FileManage/main"));
//		}
//		else{
//			mv.setViewName("login");
//			mv.addObject("message", "鐢ㄦ埛鍚嶆垨瀵嗙爜涓嶆纭�");
//		}
//		return mv;
//	}
}
