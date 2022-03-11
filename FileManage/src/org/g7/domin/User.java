package org.g7.domin;
import java.io.Serializable;
public class User implements Serializable{
	private String StaffID;	
	private String StaffName;
	private String StaffGender;
	private String StaffPosition;
	private String StaffAddress;
	private String StaffPhone;
	private String StaffIDCard;
	private String Staffcount;
	private String E_mail;
	private String Department;
	private String LengthOfService;
	private String LoginTime;
	private String LoginID;
	private String LoginPassword;
	private String monthsalary;
	private String power;
	private String RegiTime;
	private String StaffAccoountNo;
	private String Country;
	private String PassportNo;
	private String MontheTransportLimit;
	public String getStaffID() {
		return StaffID;
	}
	public void setStaffID(String staffID) {
		StaffID = staffID;
	}
	public String getStaffName() {
		return StaffName;
	}
	public void setStaffName(String staffName) {
		StaffName = staffName;
	}
	public String getStaffGender() {
		return StaffGender;
	}
	public void setStaffGender(String staffGender) {
		StaffGender = staffGender;
	}
	public String getStaffPosition() {
		return StaffPosition;
	}
	public void setStaffPosition(String staffPosition) {
		StaffPosition = staffPosition;
	}
	public String getStaffAddress() {
		return StaffAddress;
	}
	public void setStaffAddress(String staffAddress) {
		StaffAddress = staffAddress;
	}
	public String getStaffPhone() {
		return StaffPhone;
	}
	public void setStaffPhone(String staffPhone) {
		StaffPhone = staffPhone;
	}
	public String getStaffIDCard() {
		return StaffIDCard;
	}
	public void setStaffIDCard(String staffIDCard) {
		StaffIDCard = staffIDCard;
	}
	public String getStaffcount() {
		return Staffcount;
	}
	public void setStaffcount(String staffcount) {
		Staffcount = staffcount;
	}
	public String getE_mail() {
		return E_mail;
	}
	public void setE_mail(String e_mail) {
		E_mail = e_mail;
	}
	public String getDepartment() {
		return Department;
	}
	public void setDepartment(String department) {
		Department = department;
	}
	public String getLengthOfService() {
		return LengthOfService;
	}
	public void setLengthOfService(String lengthOfService) {
		LengthOfService = lengthOfService;
	}
	public String getLoginTime() {
		return LoginTime;
	}
	public void setLoginTime(String loginTime) {
		LoginTime = loginTime;
	}
	public String getLoginID() {
		return LoginID;
	}
	public void setLoginID(String loginID) {
		LoginID = loginID;
	}
	public String getLoginPassword() {
		return LoginPassword;
	}
	public void setLoginPassword(String loginPassword) {
		LoginPassword = loginPassword;
	}
	public String getMonthsalary() {
		return monthsalary;
	}
	public void setMonthsalary(String monthsalary) {
		this.monthsalary = monthsalary;
	}
	public String getPower() {
		return power;
	}
	public void setPower(String power) {
		this.power = power;
	}
	public String getRegiTime() {
		return RegiTime;
	}
	public void setRegiTime(String regiTime) {
		RegiTime = regiTime;
	}
	public String getStaffAccoountNo() {
		return StaffAccoountNo;
	}
	public void setStaffAccoountNo(String staffAccoountNo) {
		StaffAccoountNo = staffAccoountNo;
	}
	public String getCountry() {
		return Country;
	}
	public void setCountry(String country) {
		Country = country;
	}
	public String getPassportNo() {
		return PassportNo;
	}
	public void setPassportNo(String passportNo) {
		PassportNo = passportNo;
	}
	public String getMontheTransportLimit() {
		return MontheTransportLimit;
	}
	public void setMontheTransportLimit(String montheTransportLimit) {
		MontheTransportLimit = montheTransportLimit;
	}
	@Override
	public String toString() {
		return "User [StaffID=" + StaffID + ", StaffName=" + StaffName + ", StaffGender=" + StaffGender
				+ ", StaffPosition=" + StaffPosition + ", StaffAddress=" + StaffAddress + ", StaffPhone=" + StaffPhone
				+ ", StaffIDCard=" + StaffIDCard + ", Staffcount=" + Staffcount + ", E_mail=" + E_mail + ", Department="
				+ Department + ", LengthOfService=" + LengthOfService + ", LoginTime=" + LoginTime + ", LoginID="
				+ LoginID + ", LoginPassword=" + LoginPassword + ", monthsalary=" + monthsalary + ", power=" + power
				+ ", RegiTime=" + RegiTime + ", StaffAccoountNo=" + StaffAccoountNo + ", Country=" + Country
				+ ", PassportNo=" + PassportNo + ", MontheTransportLimit=" + MontheTransportLimit + "]";
	}
	
}
