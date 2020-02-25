package org.g7.domin;

import java.io.Serializable;

/**
    CREATE TABLE tb_user(
	id INT PRIMARY KEY AUTO_INCREMENT,
	loginname VARCHAR(50) UNIQUE,
	PASSWORD VARCHAR(18),
	username VARCHAR(18),
	phone VARCHAR(18),
	address VARCHAR(255)
);
 * */
public class Login implements Serializable{

	private String userid;			//user id
	private String loginid;			// 登录名
	private String loginpassword;	// 密码
	private String username;		// 用户名
	private String gender;			// 性别
	private String phone;			// 电话
	private String email;			// 邮件
	
	public Login() {
		super();
		// TODO Auto-generated constructor stub
	}

	public String getUserid() {
		return userid;
	}

	public void setUserid(String userid) {
		this.userid = userid;
	}

	public String getLoginid() {
		return loginid;
	}

	public void setLoginid(String loginid) {
		this.loginid = loginid;
	}

	public String getLoginpassword() {
		return loginpassword;
	}

	public void setLoginpassword(String loginpassword) {
		this.loginpassword = loginpassword;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	@Override
	public String toString() {
		return "Login [userid=" + userid + ", loginid=" + loginid + ", loginpassword=" + loginpassword + ", username="
				+ username + ", gender=" + gender + ", phone=" + phone + ", email=" + email + "]";
	}

	
	
	
	
}
