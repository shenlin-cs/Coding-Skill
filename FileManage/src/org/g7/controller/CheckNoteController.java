package org.g7.controller;

import org.g7.domin.APIResult;
import org.g7.domin.CheckNote;
import org.g7.service.CheckNoteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;

@Controller
public class CheckNoteController {
	
	@Autowired
	@Qualifier("checknoteService")
	private CheckNoteService checknoteService;
	
	@RequestMapping(value = "/checknoteupdate")
	public String checknoteupdate(String CheckID, Model model) {
		CheckNote checknote = checknoteService.CheckNoteInfo(CheckID);
		System.out.println("start");
		if(checknote!=null) {
			model.addAttribute("checknote", checknote);
			System.out.println("success");
		}
		else {
			System.out.println("fail");
		}
		return "checknoteupdate";
	}
	
	@RequestMapping(value = "/UpdateCheckNote")
	public ModelAndView UpdateCheckNote(String CheckRoomID,
			String CheckHeadID,
			String CheckHeadName,
			String PIID,
			String PIName,
			String PIPhoneNumber,
			String PITeamName,
			String ExperimentID,
			String ExperimentName,
			String AnimalID,
			String ParticipantsNumber,
			String CheckAim,
			String CheckResult,
			String CheckExcuter,
			String CheckEquipment,
			String CheckMedicament,
			String CheckTime,
			String IsEstablished,
			String CheckID, ModelAndView mv) {		
		int res = checknoteService.UpdateCheckNote(CheckRoomID, CheckHeadID, CheckHeadName, 
				PIID, PIName, PIPhoneNumber, PITeamName, ExperimentID, ExperimentName, 
				AnimalID, ParticipantsNumber, CheckAim, CheckResult, CheckExcuter, 
				CheckEquipment, CheckMedicament, CheckTime, IsEstablished, CheckID);
		if (res != 0) {
			mv.addObject("message", "更新成功!");
			mv.setView(new RedirectView("/FileManage/updatefile"));
			System.out.print("updatesuccess");
		} else {
			mv.addObject("message", "更新失败!");
			mv.setView(new RedirectView("/FileManage/updatefile"));
			System.out.print("updatefail");
		}
		return mv;
	}
	
	@RequestMapping(value = "/DeleteCheckNote")
	public ModelAndView DeleteCheckNote(String CheckID, ModelAndView mv) {
		int res = checknoteService.DeleteCheckNote(CheckID);
		if (res != 0) {
			mv.addObject("message", "删除成功!");
			mv.setView(new RedirectView("/FileManage/deletefile"));
		} else {
			mv.addObject("message", "删除失败!");
			mv.setView(new RedirectView("/FileManage/deletefile"));
		}
		return mv;
	}
	
	@RequestMapping(value = "/api/GetCheckNote")
	@ResponseBody
	public APIResult GetCheckNote(
			@RequestParam(name="CheckID",required=true) String CheckID,
			@RequestParam(name="token",required=true) String token) {
		return checknoteService.GetCheckNote(CheckID);
	}

}
