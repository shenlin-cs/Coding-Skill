package org.g7.controller;

import org.g7.domin.APIResult;
import org.g7.domin.ExperimentNote;
import org.g7.service.ExperimentNoteService;
import org.g7.service.NoteService;
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
public class ExperimentNoteController {
	
	@Autowired
	@Qualifier("experimentnoteService")
	private ExperimentNoteService experimentnoteService;
	
	@Autowired
	@Qualifier("noteService")
	private NoteService noteService;
	
	@RequestMapping(value = "/experimentnoteupdate")
	public String experimentnoteupdate(String ExperimentID, Model model) {
		ExperimentNote experimentnote = experimentnoteService.ExperimentNoteInfo(ExperimentID);
		System.out.println("start");
		if(experimentnote!=null) {
			model.addAttribute("experimentnote", experimentnote);
			System.out.println("success");
		}
		else {
			System.out.println("fail");
		}
		return "experimentnoteupdate";
	}
	
	@RequestMapping(value = "/experimentnoteprint")
	public String experimentnoteprint(String ExperimentID, Model model) {
		ExperimentNote experimentnote = experimentnoteService.ExperimentNoteInfo(ExperimentID);
		System.out.println("print start");
		if(experimentnote!=null) {
			model.addAttribute("experimentnote", experimentnote);
			System.out.println("print success");
			String ShelfLocation = ExperimentID.substring(0, ExperimentID.length()-3);
			String LayLocation = ExperimentID.substring(ExperimentID.length()-3,ExperimentID.length());
			int res = noteService.updatefilelocation(ShelfLocation, LayLocation, ExperimentID);
			System.out.println(res);
		}
		else {
			System.out.println("print fail");
		}
		return "printfileview";
	}
	
	@RequestMapping(value = "/UpdateExperimentNote")
	public ModelAndView UpdateExperimentNote(String Name,
			String ExperimentID,
			String EmployeeID,
			String Contact,
			String PIName,
			String PIID,
			String Department,
			String BranchName,
			String AnimalID,
			String AnimalSpecies,
			String ExperimentRoom,
			String ExperimentStartTime,
			String ExperimentEndTime,
			String ExperimentPurpose,
			String ExperimentContent,
			String ExperimentStep,
			String ExperimentConclusion,
			String ExperimentNote, ModelAndView mv) {		
		int res = experimentnoteService.UpdateExperimentNote(Name, ExperimentID, EmployeeID, Contact, PIName, PIID, Department, BranchName, AnimalID, AnimalSpecies, ExperimentRoom, ExperimentStartTime, ExperimentEndTime, ExperimentPurpose, ExperimentContent, ExperimentStep, ExperimentConclusion, ExperimentNote);
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
	
	@RequestMapping(value = "/DeleteExperimentNote")
	public ModelAndView DeleteExperimentNote(String ExperimentID, ModelAndView mv) {
		int res = experimentnoteService.DeleteExperimentNote(ExperimentID);
		if (res != 0) {
			mv.addObject("message", "删除成功!");
			mv.setView(new RedirectView("/FileManage/deletefile"));
		} else {
			mv.addObject("message", "删除失败!");
			mv.setView(new RedirectView("/FileManage/deletefile"));
		}
		return mv;
	}
	
	@RequestMapping(value = "/api/GetExperimentNote")
	@ResponseBody
	public APIResult GetExperimentNote(
			@RequestParam(name="ExperimentID",required=true) String ExperimentID,
			@RequestParam(name="token",required=true) String token) {
		return experimentnoteService.GetExperimentNote(ExperimentID);
	}

}
