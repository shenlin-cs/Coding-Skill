package org.g7.controller;
import org.g7.domin.*;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.HttpSession;
import org.g7.domin.JwtService;
import org.g7.service.QueryService;
import org.g7.service.UserService;
import org.g7.service.NoteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;


@Controller
public class QueryController {
	@Autowired
	@Qualifier("queryService")
	private QueryService queryService;
	
	@Autowired
	@Qualifier("userService")
	private UserService userService;
	
	@Autowired
	@Qualifier("noteService")
	private NoteService noteService;
	
    @RequestMapping("/testMap")
    @ResponseBody
    public Map test2(@RequestParam("name") String name) {
        Map<String, Object> map = new HashMap<>();
        map.put("name", name);
        map.put("test", 123);
        map.put("array", new String[]{"a", "b", "c"});
        return map;
    }
	
	@RequestMapping(value="/query")
	@ResponseBody
	 public APIResult login(@RequestParam(name="loginid",required=true) String loginid, @RequestParam(name="password",required=true) String password){
		APIResult resultdata = queryService.query(loginid, password);
		return resultdata;
	}
	
	@RequestMapping(value="/api/getuserinfo")
	@ResponseBody
	 public APIResult getuserinfo(@RequestParam(name="loginid",required=true) String loginid,@RequestParam(name="token",required=true) String token){
		APIResult resultdata = queryService.getuserinfo(loginid);
		return resultdata;
	}
	
	public String calTime(Date date, int dayNum) {
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date); //��Ҫ��date����ת�Ƶ�Calender�����в���
		calendar.add(calendar.DATE, dayNum);//��������������n��.����������,������ǰ�ƶ�
		date=calendar.getTime();//���ʱ��������������ƻ���ǰ��n��Ľ��
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		return df.format(date);
	}
	
	@RequestMapping(value = "/api/UnConfirmedNoteQuery")
	@ResponseBody
	public APIResult UnConfirmedNoteQuery(
			@RequestParam(name="ClerkID",required=true) String ClerkID,
			@RequestParam(name="IsEstablished",required=true) String IsEstablished,
			@RequestParam(name="IsClerkDeal",required=true) String IsClerkDeal,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(ClerkID, "Applicant");
		if(user.getCode()==0) {
			String startTime=calTime(new Date(),-10);
			String endTime=calTime(new Date(),-5);
			APIResult result=noteService.UnConfirmedNoteQuery(IsEstablished,IsEstablished,startTime, endTime);
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/api/getsigninfbyAnimalID")
	@ResponseBody
	public APIResult SigninfoQuerybyAnimalID(
			@RequestParam(name="LoginID",required=true) String LoginID,
			@RequestParam(name="AnimalID",required=true) String AnimalID,
			@RequestParam(name="token",required=true) String token) {
			APIResult result=queryService.SigninfoQuerybyAnimalID(AnimalID);
			return result;
	}
	
	@RequestMapping(value = "/api/getsigninfbyExperimentID")
	@ResponseBody
	public APIResult SigninfoQuerybyExperimentID(
			@RequestParam(name="LoginID",required=true) String LoginID,
			@RequestParam(name="ExperimentID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult user = userService.StaffIDQuery(LoginID, "Applicant");
		if(user.getCode()==0) {
			APIResult result=queryService.SigninfoQuerybyExperimentID(ExperimentID);
			return result;
		}
		else {
			return APIResult.failure(ResultCode.USER_NOT_LOGGED_IN);
		}
	}
	
	@RequestMapping(value = "/api/getanimalinfo")
	@ResponseBody
	public APIResult AnimalQuery(
			@RequestParam(name="AnimalID",required=true) String AnimalID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.AnimalQuery(AnimalID);
		return result;
	}
	
	@RequestMapping(value = "/api/getexpelist")
	@ResponseBody
	public APIResult getexpelist(
			@RequestParam(name="PIID",required=true) String PIID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.getexpelist(PIID);
		return result;
	}
	
	@RequestMapping(value = "/api/getnotelisrt")
	@ResponseBody
	public APIResult getnotelisrt(
			@RequestParam(name="ExperimentID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.getnotelisrt(ExperimentID);
		return result;
	}
	
	@RequestMapping(value = "/api/getexperinfo")
	@ResponseBody
	public APIResult getexperinfo(
			@RequestParam(name="ExperimentID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.getexperinfo(ExperimentID);
		return result;
	}
	
	@RequestMapping(value = "/api/gettfinote")
	@ResponseBody
	public APIResult showtfinote(
			@RequestParam(name="NoteID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.showtfinote(ExperimentID);
		return result;
	}
	
	@RequestMapping(value = "/api/gettfonote")
	@ResponseBody
	public APIResult showtfonote(
			@RequestParam(name="NoteID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.showtfonote(ExperimentID);
		return result;
	}
	@RequestMapping(value = "/api/getchknote")
	@ResponseBody
	public APIResult showchknote(
			@RequestParam(name="NoteID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.showchknote(ExperimentID);
		return result;
	}
	@RequestMapping(value = "/api/getdisnote")
	@ResponseBody
	public APIResult showdisnote(
			@RequestParam(name="NoteID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.showdisnote(ExperimentID);
		return result;
	}
	@RequestMapping(value = "/api/getoptnote")
	@ResponseBody
	public APIResult showoptnote(
			@RequestParam(name="NoteID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		APIResult result=queryService.showoptnote(ExperimentID);
		return result;
	}
}
