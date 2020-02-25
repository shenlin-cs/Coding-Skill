package org.g7.controller;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.servlet.http.HttpServletResponse;
import javax.ws.rs.core.Response;

import org.g7.domin.Application_Information;
import org.g7.domin.User;
import org.g7.service.Application_InformationService;
import org.g7.service.AuditService;
import org.g7.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;
/**
 * 处理图书请求控制�?
 * */
@Controller
public class AppendixController {
	
	/**
	 * 自动注入BookService
	 * */
	@Autowired
	@Qualifier("Application_InformationService")
	private Application_InformationService application_InformationService1;
	
	@Autowired
	@Qualifier("userService")
	private UserService userService;
	
	@Autowired
	@Qualifier("AuditService")
	private AuditService auditService;

	/**
	 * 处理/main请求
	 * */
	@RequestMapping(value="/appendixrequest")
	 public void appendix(String ApplicationID,Model model,ModelAndView mv,HttpServletResponse response){		
		System.out.println(ApplicationID);
		Application_Information Application_Information_content = application_InformationService1.getUserById(ApplicationID);
		//���ص�pdf�ļ�·��
		String FilePath=Application_Information_content.applicationOperateContent;
		System.out.println(FilePath);
		try {      		
           showPdf(response,FilePath);
        }catch (Exception e) {
           mv.addObject("message", "δ�ҵ��ļ�");
           mv.setViewName("dealaudit");
           e.printStackTrace();
        }		
	}	
	public static void showPdf( HttpServletResponse response, String fileName) throws IOException{
        response.setContentType("application/pdf");
        FileInputStream in = new FileInputStream(new File(fileName));
        OutputStream out = response.getOutputStream();
        byte[] b = new byte[1024];
        while ((in.read(b))!=-1) {
            out.write(b);
        }
        out.flush();
        in.close();
        out.close();
    }		
	
	@RequestMapping(value="/autoaudit")
	 public String autoaudit(String ApplicationID,Model model,ModelAndView mv,HttpServletResponse response){		
		Application_Information Application_Information_content = application_InformationService1.getUserById(ApplicationID);
		//���ص�pdf�ļ�·��
		model.addAttribute("Application_Information_content", Application_Information_content);
		String feedbackmessage="";
		//��������Ϣ������
		if(Application_Information_content.applicationID.equals("")) {
			feedbackmessage+="��������Ϊ��,";
		}
		if(Application_Information_content.applicationName.equals("")) {
			feedbackmessage+="����������Ϊ��,";
		}
		if(Application_Information_content.applicationOperateType.equals("")) {
			feedbackmessage+="��������Ϊ��,";
		}
		if(Application_Information_content.applicationOperateContent.equals("")) {
			feedbackmessage+="��������Ϊ��,";
		}
		if(Application_Information_content.recordtype.equals("")) {
			feedbackmessage+="��¼����Ϊ��,";
		}
		if(Application_Information_content.experimentID.equals("")) {
			feedbackmessage+="ʵ����Ϊ��,";
		}
		if(Application_Information_content.applicantID.equals("")) {
			feedbackmessage+="�����߱��Ϊ��,";
		}
		if(Application_Information_content.applicantName.equals("")) {
			feedbackmessage+="����������Ϊ��,";
		}
		if(Application_Information_content.applicantPhoneNumber.equals("")) {
			feedbackmessage+="��������ϵ��ʽΪ��,";
		}
		if(Application_Information_content.departmentID.equals("")) {
			feedbackmessage+="�����߲��ű��Ϊ��,";
		}
		if(Application_Information_content.departmentName.equals("")) {
			feedbackmessage+="�����߲�����Ϊ��,";
		}
		if(Application_Information_content.applicationTime.equals("")) {
			feedbackmessage+="����ʱ��Ϊ��,";
		}
		if(Application_Information_content.clerkID.equals("")) {
			feedbackmessage+="��Ա���Ϊ��,";
		}
		if(Application_Information_content.clerkName.equals("")) {
			feedbackmessage+="��Ա����Ϊ��,";
		}
		//��Ϣ������
		//����������ID��g3_staff��Ա����Ϣ
		User user = userService.findInfo(Application_Information_content.applicantID);
		if(user==null) {
			feedbackmessage+="�����߲�����,";
		}else {
			if(Application_Information_content.applicationID.equals(user.getLoginID())) {
				if(!Application_Information_content.applicantName.equals(user.getStaffName())) {
					feedbackmessage+="�����߱�ź�������һ��,";
				}
			}
			if(!Application_Information_content.applicantPhoneNumber.equals(user.getStaffPhone())) {
				feedbackmessage+="��������ϵ��ʽ����,";
			}
			if(!Application_Information_content.departmentName.equals(user.getDepartmentName())) {
				feedbackmessage+="�����߲�����������,";
			}
			if(!Application_Information_content.departmentID.equals(user.getDepartmentID())) {
				feedbackmessage+="�����߲���ID����,";
			}			
		}	
		//���ݹ�Ա��ID��g3_staff��Ա����Ϣ
		User clerk = userService.findInfo(Application_Information_content.clerkID);
		if(clerk==null) {
			feedbackmessage+="��Ա������,";
		}else {
			if(Application_Information_content.clerkID.equals(clerk.getLoginID())) {
				if(!Application_Information_content.clerkName.equals(clerk.getStaffName())) {
					feedbackmessage+="��Ա������Ա������һ��,";
				}
			}
		}	
		//�ж���������
		Date getDate = Calendar.getInstance().getTime();
		String date = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(getDate);
		System.out.println("���ڼ�ʱ��:" + date);
		if(Application_Information_content.applicationTime.compareTo(date)>0) {
			feedbackmessage+="������������,";
		}
		if(Application_Information_content.applicationOperateType.contains("��")) {
			if(Application_Information_content.applicationOperateType.contains("ɾ")
					||Application_Information_content.applicationOperateType.contains("��")) {
				feedbackmessage+="�������Ͳ���ͬʱ��������ɾ��,";
			}
		}else if(Application_Information_content.applicationOperateType.contains("ɾ")||
				Application_Information_content.applicationOperateType.contains("��")) {
			if(Application_Information_content.recordtype.contains("ʵ���¼")) {
				if(Application_Information_content.experimentID.equals("")) {
					feedbackmessage+="��¼�����е�ʵ���¼���Ϊ��,";
				}else {//��ʵ��Ĵ�����
					ExperimentNote note=auditService.ExperimentExists(Application_Information_content.experimentID);
					if(note==null) {
						feedbackmessage+="ʵ���¼������,";
					}
				}
			}			
			if(Application_Information_content.recordtype.contains("������¼")){
				if(Application_Information_content.operationID.equals("")) {
					feedbackmessage+="��¼�����е�������¼���Ϊ��,";
				}else {//��ʵ��Ĵ�����
					OperationNote note=auditService.OperationExists(Application_Information_content.operationID);
					if(note==null) {
						feedbackmessage+="������¼������,";
					}else if(!note.getOperationID().equals(Application_Information_content.operationID)) {
						feedbackmessage+="ʵ��ID��������¼ID��ƥ��,";
					}
				}
			}
			if(Application_Information_content.recordtype.contains("����¼")) {
				if(Application_Information_content.inspectID.equals("")) {
					feedbackmessage+="��¼�����еļ���¼���Ϊ��,";
				}else {//��ʵ��Ĵ�����
					CheckNote note=auditService.InspectExists(Application_Information_content.inspectID);
					if(note==null) {
						feedbackmessage+="����¼������,";
					}else if(!note.getCheckID().equals(Application_Information_content.inspectID)) {
						feedbackmessage+="ʵ��ID�����¼ID��ƥ��,";
					}
				}
			}
			if(Application_Information_content.recordtype.contains("���ۼ�¼")) {
				if(Application_Information_content.discussionID.equals("")) {
					feedbackmessage+="��¼�����е����ۼ�¼���Ϊ��,";
				}else {//��ʵ��Ĵ�����
					DiscussionNote note=auditService.DiscussionExists(Application_Information_content.discussionID);
					if(note==null) {
						feedbackmessage+="���ۼ�¼������,";
					}else if(!note.getDiscussionID().equals(Application_Information_content.discussionID)) {
						feedbackmessage+="ʵ��ID�����ۼ�¼ID��ƥ��,";
					}					
				}
			}
			if(Application_Information_content.recordtype.contains("ת���¼")) {
				if(Application_Information_content.rollinID.equals("")) {
					feedbackmessage+="��¼�����е�ת���¼���Ϊ��,";
				}else {//��ʵ��Ĵ�����
					TransferinNote note=auditService.RollInExists(Application_Information_content.rollinID);
					if(note==null) {
						feedbackmessage+="ת���¼������,";
					}else if(!note.getTransferinID().equals(Application_Information_content.rollinID)) {
						feedbackmessage+="ʵ��ID��ת���¼ID��ƥ��,";
					}
				}
			}
			if(Application_Information_content.recordtype.contains("ת����¼")) {
				if(Application_Information_content.rolloutID.equals("")) {
					feedbackmessage+="��¼�����е�ת����¼���Ϊ��,";
				}else {//��ʵ��Ĵ�����
					TransferoutNote note=auditService.RollOutExists(Application_Information_content.rolloutID);
					if(note==null) {
						feedbackmessage+="ת����¼������,";
					}else if(!note.getTransferoutID().equals(Application_Information_content.rolloutID)) {
						feedbackmessage+="ʵ��ID��ת����¼ID��ƥ��,";
					}
				}
			}

		}		
		model.addAttribute("feedbackmessage", feedbackmessage);
		return "audit_3";			
	}	
}
