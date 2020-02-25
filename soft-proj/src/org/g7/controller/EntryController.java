package org.g7.controller;
import java.text.SimpleDateFormat;

import java.util.Date;
import java.util.List;


import javax.servlet.http.HttpSession;

import org.g7.domin.Audit;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;
import org.g7.service.EntryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@Controller
public class EntryController {
	/**
	 * �Զ�ע��UserService
	 * */
	public boolean Check(String str1,String str2)
	  {
	    Pattern p = Pattern.compile(str1);
	    Matcher m = p.matcher(str2);
	    if (m.matches())
	    {
	        return true;
	    }
	    else return false;
	  }
				
	@Autowired
	@Qualifier("EntryService")
	private EntryService EntryService;
	
	/**
	 * ����/insert����
	 * */
	@RequestMapping(value="/insertCheckNote")
	 public ModelAndView insert_check(
			 String CheckID,String CheckRoomID,String CheckHeadID,String CheckHeadName,String PIID,
			 String PIName,String PIPhoneNumber,String PITeamName,String ExperimentID,String ExperimentName,
			 String AnimalID,String ParticipantsNumber,String CheckAim,String CheckResult,String CheckExcuter,
			 String CheckEquipment,String CheckMedicament,String CheckTime,String IsEstablished,
			 ModelAndView mv,
			 HttpSession session){
			String CheckCheckID="CHI[0-9]+";//��������ʽȥ�淶�ַ���
			String CheckCheckRoomID="R[0-9]+";
			String CheckCheckHeadID="EM[0-9]+";
			String CheckPIID="P[0-9]+";
			String CheckPIPhoneNumber="0?(13|14|15|18)[0-9]{9}";
		// ���ݵ�¼������������û����ж��û���¼
				//����ʵ��ID �ж��Ƿ����
			List<CheckNote> keylist=CheckCheckID();
			for(int i = 0;i<keylist.size();i++) {			
				if(CheckID.equals(keylist.get(i).getCheckID())) {
					mv.addObject("feedback", "�ü�������Ѵ��ڣ������ظ�");
					mv.setViewName("entrychecknote");
					return mv;
				}
			}
			if(CheckID.equals("")) {
				   mv.addObject("feedback", "������Ų���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }
			   else if(!Check(CheckCheckID,CheckID)) {
				   mv.addObject("feedback", "����Ÿ�ʽ���� �����CHI001");
				   mv.setViewName("entrychecknote");
			   }
			   else if(CheckRoomID.equals("")){
				   mv.addObject("feedback", "����Ҳ���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }
			   else if(!Check(CheckCheckRoomID,CheckRoomID)) {
				   mv.addObject("feedback", "����Ҹ�ʽ���� �����R001");
				   mv.setViewName("entrychecknote");
			   }
			   else if(CheckHeadID.equals("")){
				   mv.addObject("feedback", "����Ҹ����˱�Ų���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }
			   else if(!Check(CheckCheckHeadID,CheckHeadID)) {
				   mv.addObject("feedback", "����Ҹ����˸�ʽ���� ����ո�ʽEM001");
				   mv.setViewName("entrychecknote");
			   }
			   else if(CheckHeadName.equals("")){
				   mv.addObject("feedback", "����Ҹ�������������Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(PIName.equals("")){
				   mv.addObject("feedback", "PI��������Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(PIID.equals("")){
				   mv.addObject("feedback", "PI��Ų���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }
			   else if(!Check(CheckPIID,PIID)) {
				   mv.addObject("feedback", "PI��Ÿ�ʽ���� ����ո�ʽP1");
				   mv.setViewName("entrychecknote");
			   }
			   else if(PIPhoneNumber.equals("")){
				   mv.addObject("feedback", "PI��ϵ��ʽ����Ϊ��");
				   mv.setViewName("entrychecknote");
			   }
			   else if(!Check(CheckPIPhoneNumber,PIPhoneNumber)) {
				   mv.addObject("feedback", "��Ч�绰����");
				   mv.setViewName("entrychecknote");
			   }
			   else if(PITeamName.equals("")){
				   mv.addObject("feedback", "PI�����ŶӲ���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }
			  
			   else if(AnimalID.equals("")){
				   mv.addObject("feedback", "ʵ�鶯�ﲻ��Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(ExperimentID.equals("")){
				   mv.addObject("feedback", "����ʵ���Ų���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(ExperimentName.equals("")){
				   mv.addObject("feedback", "����ʵ�����Ʋ���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if((ParticipantsNumber+"").equals("")){
				   mv.addObject("feedback", "������������Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(CheckTime.equals("")){
				   mv.addObject("feedback", "���ʱ�䲻��Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(CheckExcuter.equals("")){
				   mv.addObject("feedback", "���ִ���˲���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(CheckEquipment.equals("")){
				   mv.addObject("feedback", "����豸����Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(CheckMedicament.equals("")){
				   mv.addObject("feedback", "���ҩ������Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(CheckAim.equals("")){
				   mv.addObject("feedback", "���Ŀ�Ĳ���Ϊ��");
				   mv.setViewName("entrychecknote");
			   }else if(CheckResult.equals("")){
				   mv.addObject("feedback", "���������Ϊ��");
				   mv.setViewName("entrychecknote");		   
			   }else {
		// ���ݵ�¼������������û����ж��û���¼
				   Date date = new Date();
				   SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
				   String InputTime=sdf.format(date);
				   
				   int status=EntryService.Insert_check(CheckID,CheckRoomID,CheckHeadID,CheckHeadName,
						   PIID,PIName,PIPhoneNumber,PITeamName,ExperimentID,ExperimentName,
						   AnimalID,ParticipantsNumber,CheckAim,CheckResult,CheckExcuter,
						   CheckEquipment,CheckMedicament,CheckTime,InputTime,IsEstablished);
				   if(status == 1){
					   // ��¼�ɹ�����user�������õ�HttpSession���÷�Χ��
					   System.out.println("�ɹ�");
					   //session.setAttribute("user", user);
					   // ת����audit����
					   mv.setView(new RedirectView("/FileManage/insertlist"));
				   }
				   else{
					   // ��¼ʧ�ܣ�����ʧ����ʾ��Ϣ������ת����¼ҳ��
					   mv.addObject("message", "����ʧ��");
					   mv.setViewName("entrychecknote");
				   }
			   }
			   return mv;
	}
	
	

	
	@RequestMapping(value="/insertDiscussionNote")
	 public ModelAndView insert_discussion(String DiscussionID,String DiscussionName,String DiscussionRoomID,
				String DiscussionHeadID,String DiscussionHeadName,String PIID,String PIName,
				String PIPhoneNumber,String PITeamName,String ExperimentID,String ExperimentName,
				String AnimalID,String DiscussionAim,String DiscussionResult,String DiscussionExcuter,
				String DiscussionEquipment,String DiscussionMedicament,String DiscussionTime,
				String IsEstablished,
			 ModelAndView mv,
			 HttpSession session){

		String CheckDiscussionID="DCI[0-9]+";//��������ʽȥ�淶�ַ���
		String CheckDiscussionRoomID="R[0-9]+";
		String CheckDiscussionHeadID="EM[0-9]+";
		String CheckPIID="P[0-9]+";
		String CheckPIPhoneNumber="0?(13|14|15|18)[0-9]{9}";
		// ���ݵ�¼������������û����ж��û���¼
		List<DiscussionNote> keylist=CheckDiscussionID();
		for(int i = 0;i<keylist.size();i++) {			
			if(DiscussionID.equals(keylist.get(i).getDiscussionID())) {
				mv.addObject("feedback", "�����ۼ�����Ѵ��ڣ������ظ�");
				mv.setViewName("entrydiscussionnote");
				return mv;
			}
		}
		if(DiscussionID.equals("")) {
			   mv.addObject("feedback", "���۱�Ų���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }
		else if(!Check(CheckDiscussionID,DiscussionID)) {
			   mv.addObject("feedback", "���۱�Ÿ�ʽ���� �����DCI001");
			   mv.setViewName("entrydiscussionnote");
		   }
		else if(DiscussionRoomID.equals("")){
			   mv.addObject("feedback", "�����Ҳ���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }
		else if(!Check(CheckDiscussionRoomID,DiscussionRoomID)) {
			   mv.addObject("feedback", "�����Ҹ�ʽ���� �����R001");
			   mv.setViewName("entrydiscussionnote");
		   }
		else if(DiscussionHeadID.equals("")){
			   mv.addObject("feedback", "���۸����˱�Ų���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }
		else if(!Check(CheckDiscussionHeadID,DiscussionHeadID)) {
			   mv.addObject("feedback", "���۸����˱�Ÿ�ʽ���� �����EM001");
			   mv.setViewName("entrydiscussionnote");
		   }
		else if(PIName.equals("")){
			   mv.addObject("feedback", "PI��������Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(PIID.equals("")){
			   mv.addObject("feedback", "PI��Ų���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }
		   else if(!Check(CheckPIID,PIID)) {
			   mv.addObject("feedback", "PI��Ÿ�ʽ���� �����P001");
			   mv.setViewName("entrydiscussionnote");
		   }
		
		   else if(DiscussionHeadName.equals("")){
			   mv.addObject("feedback", "���۸�������������Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(PIPhoneNumber.equals("")){
			   mv.addObject("feedback", "��ϵ��ʽ����Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }
		   else if(!Check(CheckPIPhoneNumber,PIPhoneNumber)) {
			   mv.addObject("feedback", "��Ч�绰����");
			   mv.setViewName("entrydiscussionnote");
		   }
		   else if(AnimalID.equals("")){
			   mv.addObject("feedback", "ʵ�鶯���Ų���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(PITeamName.equals("")){
			   mv.addObject("feedback", "PI�����ŶӲ���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(ExperimentID.equals("")){
			   mv.addObject("feedback", "ʵ���Ų���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(ExperimentName.equals("")){
			   mv.addObject("feedback", "ʵ�����Ʋ���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionTime.equals("")){
			   mv.addObject("feedback", "����ʱ�䲻��Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionName.equals("")){
			   mv.addObject("feedback", "�������Ʋ���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionExcuter.equals("")){
			   mv.addObject("feedback", "����ִ���˲���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionEquipment.equals("")){
			   mv.addObject("feedback", "�����豸����Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionMedicament.equals("")){
			   mv.addObject("feedback", "����ҩ������Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionAim.equals("")){
			   mv.addObject("feedback", "����Ŀ�Ĳ���Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }else if(DiscussionResult.equals("")){
			   mv.addObject("feedback", "���۽������Ϊ��");
			   mv.setViewName("entrydiscussionnote");
		   }
	  else {
		  Date date = new Date();
	      SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
	      String InputTime=sdf.format(date);	  
		  int status=EntryService.Insert_discussion(DiscussionID,DiscussionName,DiscussionRoomID,
					DiscussionHeadID,DiscussionHeadName,PIID,PIName,
					PIPhoneNumber,PITeamName,ExperimentID,ExperimentName,
					AnimalID,DiscussionAim,DiscussionResult,DiscussionExcuter,
					DiscussionEquipment,DiscussionMedicament,DiscussionTime,InputTime,IsEstablished);
			if(status == 1){
				// ��¼�ɹ�����user�������õ�HttpSession���÷�Χ��
				System.out.println("�ɹ�");
				//session.setAttribute("user", user);
				// ת����audit����
				mv.setView(new RedirectView("/FileManage/insertlist"));
			}
			else{
				// ��¼ʧ�ܣ�����ʧ����ʾ��Ϣ������ת����¼ҳ��
				mv.addObject("message", "����ʧ��");
				mv.setViewName("entrydiscussionnote");
			}
	  }
		return mv;
	}
	
	
	/**
	 * ����/login����
	 * */
	@RequestMapping(value="/insertExperimentNote")
	 public ModelAndView insert_experiment(
			 String Name,String ExperimentID,String EmployeeID,String Contact,String PIName,
			 String PIID,String Department,String BranchName,String AnimalID,String AnimalSpecies,
			 String ExperimentRoom,String ExperimentStartTime,String ExperimentEndTime,
			 String ExperimentPurpose,String ExperimentContent,
			 String ExperimentStep,String ExperimentConclusion,String ExperimentNote,
			 ModelAndView mv,
			 HttpSession session){
		// ���ݵ�¼������������û����ж��û���¼
		List<ExperimentNote> keylist=CheckExperimentID();
		for(int i = 0;i<keylist.size();i++) {			
			if(ExperimentID.equals(keylist.get(i).getExperimentID())) {
				mv.addObject("feedback", "��ʵ�����Ѵ��ڣ������ظ�");
				mv.setViewName("entryexperimentnote");
				return mv;
			}
		}
		//����ʵ��ID �ж��Ƿ����
	   if(ExperimentID.equals("")){
		   mv.addObject("feedback", "ʵ���Ų���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(EmployeeID.equals("")){	  
		   mv.addObject("feedback", "�����˹��Ų���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(Contact.equals("")){
		   mv.addObject("feedback", "��ϵ��ʽ����Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(PIName.equals("")){
		   mv.addObject("feedback", "PI��������Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(PIID.equals("")){
		   mv.addObject("feedback", "PI��Ų���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(Department.equals("")){
		   mv.addObject("feedback", "�������Ʋ���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(BranchName.equals("")){
		   mv.addObject("feedback", "��ƽ̨���Ʋ���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(AnimalID.equals("")){
		   mv.addObject("feedback", "ʵ�鶯���Ų���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(AnimalSpecies.equals("")){
		   mv.addObject("feedback", "ʵ�鶯�����ֲ���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentRoom.equals("")){
		   mv.addObject("feedback", "ʵ���ҷ��䲻��Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentStartTime.equals("")){
		   mv.addObject("feedback", "��ʼʱ�䲻��Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentEndTime.equals("")){
		   mv.addObject("feedback", "����ʱ�䲻��Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentNote.equals("")){
		   mv.addObject("feedback", "��ע����Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentPurpose.equals("")){
		   mv.addObject("feedback", "ʵ��Ŀ�Ĳ���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentContent.equals("")){
		   mv.addObject("feedback", "ʵ�����ݲ���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentStep.equals("")){
		   mv.addObject("feedback", "ʵ�鲽�費��Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else if(ExperimentConclusion.equals("")){
		   mv.addObject("feedback", "ʵ����۲���Ϊ��");
		   mv.setViewName("entryexperimentnote");
	   }else {
		   Date date = new Date();
		   SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		   String ExperimentNoteTime=sdf.format(date);
		   int status=EntryService.Insert_experiment(Name, ExperimentID, EmployeeID, Contact, PIName, 
				   PIID, Department, BranchName, AnimalID, AnimalSpecies, ExperimentRoom, 
				   ExperimentStartTime, ExperimentEndTime, ExperimentNoteTime,
				   ExperimentPurpose, ExperimentContent, 
				   ExperimentStep, ExperimentConclusion, ExperimentNote);
			if(status == 1){
				// ��¼�ɹ�����user�������õ�HttpSession���÷�Χ��
				System.out.println("�ɹ�");
				//session.setAttribute("user", user);
				// ת����audit����
				mv.setView(new RedirectView("/FileManage/insertlist"));
			}
			else{
				// ��¼ʧ�ܣ�����ʧ����ʾ��Ϣ������ת����¼ҳ��
				mv.addObject("feedback", "����ʧ��");
				mv.setViewName("entryexperimentnote");
			}
	   }	   
		return mv;
	}
	
	
	@RequestMapping(value="/insertOperationNote")
	 public ModelAndView insert_operation(
			 String OperationID,String OperationName,String OperationRoomID,
			 String OperationHeadID,String OperationHeadName,String PIID,
			 String PIName,String PIPhoneNumber,String PITeamName,String ExperimentID,
			 String ExperimentName,String AnimalID,String OperationAim,
			 String OperationResult,String OperationExcuter,String OperationEquipment,
			 String OperationMedicament,String OperationTime,String IsEstablished,
			 ModelAndView mv,
			 HttpSession session){
		// ���ݵ�¼������������û����ж��û���¼

		String CheckOperationID="OP[0-9]+";//��������ʽȥ�淶�ַ���
		String CheckOperationRoomID="R[0-9]+";
		String CheckOperationHeadID="EM[0-9]+";
		String CheckPIID="P[0-1]+";
		String CheckPIPhoneNumber="0?(13|14|15|18)[0-9]{9}";
		
		List<OperationNote> keylist=CheckOperationID();
		for(int i = 0;i<keylist.size();i++) {			
			if(OperationID.equals(keylist.get(i).getOperationID())) {
				mv.addObject("feedback", "����������Ѵ��ڣ������ظ�");
				mv.setViewName("entryoperationnote");
				return mv;
			}
		}
		//����ʵ��ID �ж��Ƿ����
	   if(OperationID.equals("")) {
		   mv.addObject("feedback", "������Ų���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(!Check(CheckOperationID,OperationID)) {
		   mv.addObject("feedback", "������Ÿ�ʽ���� �����OP001");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(OperationName.equals("")){
		   mv.addObject("feedback", "�������Ʋ���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationRoomID.equals("")){
		   mv.addObject("feedback", "�����Ҳ���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(!Check(CheckOperationRoomID,OperationRoomID)) {
		   mv.addObject("feedback", "�����ұ�Ÿ�ʽ���� �����R001");
		   mv.setViewName("entrychecknote");
	   }
	   else if(OperationHeadID.equals("")){
		   mv.addObject("feedback", "�����Ҹ����˱�Ų���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(!Check(CheckOperationHeadID,OperationHeadID)) {
		   mv.addObject("feedback", "�����Ҹ����˱�Ÿ�ʽ���� �����EM001");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(OperationHeadName.equals("")){
		   mv.addObject("feedback", "�����Ҹ�������������Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(PIID.equals("")){
		   mv.addObject("feedback", "PI��Ų���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(!Check(CheckPIID,PIID)) {
		   mv.addObject("feedback", "PI��Ÿ�ʽ���� �����P001");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(PIName.equals("")){
		   mv.addObject("feedback", "PI��������Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(PIPhoneNumber.equals("")){
		   mv.addObject("feedback", "PI��ϵ��ʽ����Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(!Check(CheckPIPhoneNumber,PIPhoneNumber)) {
		   mv.addObject("feedback", "��Ч�绰����");
		   mv.setViewName("entryoperationnote");
	   }
	   else if(PITeamName.equals("")){
		   mv.addObject("feedback", "PI�����ŶӲ���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(ExperimentID.equals("")){
		   mv.addObject("feedback", "����ʵ���Ų���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(ExperimentName.equals("")){
		   mv.addObject("feedback", "����ʵ�����Ʋ���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(AnimalID.equals("")){
		   mv.addObject("feedback", "ʵ�鶯�ﲻ��Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationAim.equals("")){
		   mv.addObject("feedback", "����Ŀ�Ĳ���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationResult.equals("")){
		   mv.addObject("feedback", "�����������Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationExcuter.equals("")){
		   mv.addObject("feedback", "����ִ���˲���Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationEquipment.equals("")){
		   mv.addObject("feedback", "�����豸����Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationMedicament.equals("")){
		   mv.addObject("feedback", "����ҩ������Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else if(OperationTime.equals("")){
		   mv.addObject("feedback", "��ʱ�䲻��Ϊ��");
		   mv.setViewName("entryoperationnote");
	   }else {
		   Date date = new Date();
		   SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		   String InputTime=sdf.format(date);
		   int status=EntryService.Insert_operation(OperationID,OperationName,OperationRoomID,
					 OperationHeadID,OperationHeadName,PIID,PIName,PIPhoneNumber,PITeamName,ExperimentID,				 
					 ExperimentName,AnimalID,OperationAim,OperationResult,OperationExcuter,
					 OperationEquipment,OperationMedicament,OperationTime,InputTime,IsEstablished);
			if(status == 1){
				// ��¼�ɹ�����user�������õ�HttpSession���÷�Χ��
				System.out.println("�ɹ�");
				//session.setAttribute("user", user);
				// ת����audit����
				mv.setView(new RedirectView("/FileManage/insertlist"));
			}
			else{
				// ��¼ʧ�ܣ�����ʧ����ʾ��Ϣ������ת����¼ҳ��
				mv.addObject("feedback", "����ʧ��");
				mv.setViewName("entryoperationnote");
			}
	   }	   
		return mv;
	}
	


	/**
	 * ����/login����
	 * */
	@RequestMapping(value="/insertTransferinNote")
	 public ModelAndView insert_transferin(
			 String TransferinID,String researcher_name,String researcher_ID,String in_charge_person_name,
			 String in_charge_person_ID,String experimental_object,String object_number,String item_number,
			 String item_name,String time,String transferfromobject,String IsEstablished,
			 ModelAndView mv,
			 HttpSession session){
		// ���ݵ�¼������������û����ж��û���¼
		String CheckTransferinID="TFI[0-9]+";//��������ʽȥ�淶�ַ���
		
		List<TransferinNote> keylist=CheckTransferinID();
		for(int i = 0;i<keylist.size();i++) {			
			if(TransferinID.equals(keylist.get(i).getTransferinID())) {
				mv.addObject("feedback", "��ת�����Ѵ��ڣ������ظ�");
				mv.setViewName("entrytransferinnote");
				return mv;
			}
		}
		//����ʵ��ID �ж��Ƿ����
		if(TransferinID.equals("")) {
			   mv.addObject("feedback", "ת���¼��Ų���Ϊ��");
			   mv.setViewName("entrytransferinnote");
	   }
		else if(!Check(CheckTransferinID,TransferinID)) {
			   mv.addObject("feedback", "ת���¼��Ÿ�ʽ���� �����TFI001");
			   mv.setViewName("entrytransferinnote");
		   }
		else if(researcher_name.equals("")) {
		   mv.addObject("feedback", "�о�Ա��������Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(researcher_ID.equals("")){
		   mv.addObject("feedback", "�о���Ա��Ų���Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(in_charge_person_name.equals("")){
		   mv.addObject("feedback", "��������������Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(in_charge_person_ID.equals("")){
		   mv.addObject("feedback", "�����˱�Ų���Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(experimental_object.equals("")){
		   mv.addObject("feedback", "ʵ��������Ʋ���Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(object_number.equals("")){
		   mv.addObject("feedback", "ʵ������Ų���Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(item_number.equals("")){
		   mv.addObject("feedback", "��Ŀ��Ų���Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(item_name.equals("")){
		   mv.addObject("feedback", "��Ŀ���Ʋ���Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(transferfromobject.equals("")){
		   mv.addObject("feedback", "ת����Դ����Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else if(time.equals("")){
		   mv.addObject("feedback", "ת��ʱ�䲻��Ϊ��");
		   mv.setViewName("entrytransferinnote");
	   }else {
		   Date date = new Date();
		   SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		   String InputTime=sdf.format(date);
		   int status=EntryService.Insert_transferin(TransferinID,researcher_name,researcher_ID,in_charge_person_name,
				   in_charge_person_ID,experimental_object,object_number,item_number,item_name,
				   time,transferfromobject,InputTime,IsEstablished);
			if(status == 1){
				// ��¼�ɹ�����user�������õ�HttpSession���÷�Χ��
				System.out.println("�ɹ�");
				//session.setAttribute("user", user);
				// ת����audit����
				mv.setView(new RedirectView("/FileManage/insertlist"));
			}
			else{
				// ��¼ʧ�ܣ�����ʧ����ʾ��Ϣ������ת����¼ҳ��
				mv.addObject("feedback", "����ʧ��");
				mv.setViewName("entrytransferinnote");
			}
	   }	   
		return mv;
	}
	/**
	 * ����/login����
	 * */
	@RequestMapping(value="/insertTransferoutNote")
	 public ModelAndView insert_transferout(
			 String TransferoutID,String researcher_name,String researcher_ID,String in_charge_person_name,
			 String in_charge_person_ID,String experimental_object,String object_number,String item_number,
			 String item_name,String time,String transferobject,String IsEstablished,
			 ModelAndView mv,
			 HttpSession session){
		// ���ݵ�¼������������û����ж��û���¼
		String CheckTransferoutID="TFO[0-9]+";//��������ʽȥ�淶�ַ���
		
		List<TransferoutNote> keylist=CheckTransferoutID();
		for(int i = 0;i<keylist.size();i++) {			
			if(TransferoutID.equals(keylist.get(i).getTransferoutID())) {
				mv.addObject("feedback", "��ת������Ѵ��ڣ������ظ�");
				mv.setViewName("entrytransferoutnote");
				return mv;
			}
		}
		
		if(TransferoutID.equals("")) {
			   mv.addObject("feedback", "ת����¼��Ų���Ϊ��");
			   mv.setViewName("entrytransferoutnote");
	   }
		else if(!Check(CheckTransferoutID,TransferoutID)) {
			   mv.addObject("feedback", "ת����¼��Ÿ�ʽ���� �����TFO001");
			   mv.setViewName("entrytransferoutnote");
		   }
		else if(researcher_name.equals("")) {
		   mv.addObject("feedback", "�о�Ա��������Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(researcher_ID.equals("")){
		   mv.addObject("feedback", "�о���Ա��Ų���Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(in_charge_person_name.equals("")){
		   mv.addObject("feedback", "��������������Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(in_charge_person_ID.equals("")){
		   mv.addObject("feedback", "�����˱�Ų���Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(experimental_object.equals("")){
		   mv.addObject("feedback", "ʵ��������Ʋ���Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(object_number.equals("")){
		   mv.addObject("feedback", "ʵ������Ų���Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(item_number.equals("")){
		   mv.addObject("feedback", "��Ŀ��Ų���Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(item_name.equals("")){
		   mv.addObject("feedback", "��Ŀ���Ʋ���Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(transferobject.equals("")){
		   mv.addObject("feedback", "ת��������Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else if(time.equals("")){
		   mv.addObject("feedback", "ת��ʱ�䲻��Ϊ��");
		   mv.setViewName("entrytransferoutnote");
	   }else {
		   Date date = new Date();
		   SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		   String InputTime=sdf.format(date);
		   int status=EntryService.Insert_transferout(TransferoutID,researcher_name,researcher_ID,in_charge_person_name,
				   in_charge_person_ID,experimental_object,object_number,item_number,item_name,
					 transferobject,time,InputTime,IsEstablished);
			if(status == 1){
				// ��¼�ɹ�����user�������õ�HttpSession���÷�Χ��
				System.out.println("�ɹ�");
				//session.setAttribute("user", user);
				// ת����audit����
				mv.setView(new RedirectView("/FileManage/insertlist"));
			}
			else{
				// ��¼ʧ�ܣ�����ʧ����ʾ��Ϣ������ת����¼ҳ��
				mv.addObject("feedback", "����ʧ��");
				mv.setViewName("entrytransferoutnote");
			}
	   }	   
		return mv;
	}
	
	@RequestMapping(value="/insertlist")
	 public String insertlist(Model model){	
		
		List<Audit> insertlist = EntryService.InsertList();		
		model.addAttribute("insertlist", insertlist);
		model.addAttribute("listsize", insertlist.size());
		
		return "insertlist";
	}
	
	@RequestMapping(value="/inputdone")
	 public String inputdone(String ApplicationID,Model model){	
		
		//���ݿ�ĸ���
		int status=EntryService.updateApplicationInformation(ApplicationID);
		System.out.println(status);		
		List<Audit> insertlist = EntryService.InsertList();		
		model.addAttribute("insertlist", insertlist);
		model.addAttribute("listsize", insertlist.size());		
		return "insertlist";
	}
	
	public List CheckCheckID(){			
		List<CheckNote> keylist = EntryService.SearchCheckKey();		
		return keylist;
	}
	
	public List CheckDiscussionID(){			
		List<DiscussionNote> keylist = EntryService.SearchDiscussionKey();		
		return keylist;
	}
	
	public List CheckExperimentID(){			
		List<ExperimentNote> keylist = EntryService.SearchExperimentKey();		
		return keylist;
	}
	
	public List CheckOperationID(){			
		List<OperationNote> keylist = EntryService.SearchOperationKey();		
		return keylist;
	}
	
	public List CheckTransferinID(){			
		List<TransferinNote> keylist = EntryService.SearchTransferinKey();		
		return keylist;
	}
	
	public List CheckTransferoutID(){			
		List<TransferoutNote> keylist = EntryService.SearchTransferoutKey();		
		return keylist;
	}
}
