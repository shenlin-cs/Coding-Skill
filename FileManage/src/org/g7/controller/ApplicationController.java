package org.g7.controller;

import java.io.File;
import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.apache.commons.io.FileUtils;
import org.g7.domin.APIResult;
import org.g7.domin.Application;
import org.g7.domin.Application_Information;
import org.g7.domin.ResultCode;
import org.g7.service.ApplicationService;
import org.g7.service.Application_InformationService;
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.commons.CommonsMultipartFile;
import org.springframework.web.servlet.ModelAndView;

import java.util.Date;
import java.util.List;


@Controller
public class ApplicationController {

	@Autowired
	@Qualifier("applicationService")
	private ApplicationService applicationService;
	
	@Autowired
	@Qualifier("userService")
	private UserService userService;
	
	@Autowired
	@Qualifier("Application_InformationService")
	private Application_InformationService application_InformationService;

	@RequestMapping(value = "/applicationSubmit")
	public ModelAndView applicationSubmit(String ApplicationID, String ApplicationName, String ApplicationOperateType,
			String RecordType, String ExperimentID, String OperationID,
			String InspectID, String DiscussionID, String RollinID, String RolloutID, String ApplicantID,
			String ApplicantName, String ApplicantPhoneNumber, String DepartmentID, String DepartmentName,
			String ApplicationTime, String ClerkID, String ClerkName, ModelAndView mv, HttpSession session,
			@RequestParam("ApplicationOperateContent") CommonsMultipartFile file,
            HttpServletRequest request) throws Exception{
		System.out.println("start");
		String ApplicationOperateContent="";
		// MultipartFile是对当前上传的文件的封装，当要同时上传多个文件时，可以给定多个MultipartFile参数(数组)
        if (!file.isEmpty()) {
            String type = file.getOriginalFilename().substring(file.getOriginalFilename().indexOf("."));// 取文件格式后缀名
            String filename = ApplicationID + type;// 取当前时间戳作为文件名
            String path = request.getSession().getServletContext().getRealPath("./Application/" + filename);// 存放位置
            ApplicationOperateContent = path;
            File destFile = new File(path);
            try {
                // FileUtils.copyInputStreamToFile()这个方法里对IO进行了自动操作，不需要额外的再去关闭IO流
                FileUtils.copyInputStreamToFile(file.getInputStream(), destFile);// 复制临时文件到指定目录下
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
        	mv.addObject("message", "插入失败!");
    		mv.setViewName("ApplicationAccept");
    		return mv;
        }
		String AuditStatus = "未审";
		int temp = applicationService.Insert(ApplicationID, ApplicationName, ApplicationOperateType,
				ApplicationOperateContent, RecordType, ExperimentID, OperationID, InspectID, DiscussionID, RollinID,
				RolloutID, ApplicantID, ApplicantName, ApplicantPhoneNumber, DepartmentID, DepartmentName,
				ApplicationTime, ClerkID, ClerkName, AuditStatus);
		if (temp != 0) {
			mv.addObject("message", "插入成功!");
			mv.setViewName("clerk_1");
		} else {
			mv.addObject("message", "插入失败!");
			mv.setViewName("clerk_1");
		}
		return mv;
	}
	
	@RequestMapping(value = "/api/AuditFeedback")
	@ResponseBody
	public APIResult AuditFeedback(
			@RequestParam(name="loginid",required=true) String loginid,
			@RequestParam(name="power",required=true) String power,
			@RequestParam(name="AuditStatus",required=true) String AuditStatus,
			@RequestParam(name="FeedbackStatus",required=true) String FeedbackStatus,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(loginid, power);
		if(user.getCode()==0) {
			APIResult result=applicationService.findAllExaminedApplication(AuditStatus,FeedbackStatus);
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/api/ApplicationInfo")
	@ResponseBody
	public APIResult ApplicationInfo(
			@RequestParam(name="loginid",required=true) String loginid,
			@RequestParam(name="power",required=true) String power,
			@RequestParam(name="ApplicationID",required=true) String ApplicationID,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(loginid, power);
		if(user.getCode()==0) {
			APIResult result=applicationService.getApplicationInfo(ApplicationID);
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/api/findApplication")
	@ResponseBody
	public APIResult findApplication(
			@RequestParam(name="loginid",required=true) String loginid,
			@RequestParam(name="power",required=true) String power,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(loginid, power);
		if(user.getCode()==0) {
			APIResult result=applicationService.findApplication();
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/api/findApplicationByTime")
	@ResponseBody
	public APIResult findApplicationByTime(
			@RequestParam(name="loginid",required=true) String loginid,
			@RequestParam(name="power",required=true) String power,
			@RequestParam(name="startTime",required=true) String startTime,
			@RequestParam(name="endTime",required=true) String endTime,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(loginid, power);
		if(user.getCode()==0) {
			APIResult result=applicationService.findApplicationByTime(startTime, endTime);
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/api/findApplicationByDepartment")
	@ResponseBody
	public APIResult findApplicationByDepartment(
			@RequestParam(name="loginid",required=true) String loginid,
			@RequestParam(name="power",required=true) String power,
			@RequestParam(name="DepartmentID",required=true) String DepartmentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(loginid, power);
		if(user.getCode()==0) {
			APIResult result=applicationService.findApplicationByDepartment(DepartmentID);
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/GetApplicationInfo")
	public String GetApplicationInfo(String ApplicationID, Model model) {
		Application_Information Application_Information_content = application_InformationService.getUserById(ApplicationID);
		model.addAttribute("Application_Information_content", Application_Information_content);
		return "clerkApplicationInfo";
	}
	
	
	@RequestMapping(value = "/updateApplicationFeedbackStatus")
	public String updateApplicationFeedbackStatus(String ApplicationID,String FeedbackStatus, Model model) {
		int res = applicationService.updateApplicationFeedbackStatus(FeedbackStatus, ApplicationID);
		if(res==1) {
			model.addAttribute("message", "更新成功!");
		}
		else {
			model.addAttribute("message", "更新失败!");
		}
		return "clerk_2";
	}
}
