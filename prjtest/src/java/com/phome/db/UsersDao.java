package com.phome.db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.phome.vo.UsersVo;

public class UsersDao {
	public UsersVo getUsersByNameAndPwd(String name,String pwd)
	{
		String sql="select * from users where uname=? and upass=?";
		DbHelper dbhelp=new DbHelper();
		Connection conn=null;
		PreparedStatement pst=null;
		try {
			conn=dbhelp.getConnect();
			pst=conn.prepareStatement(sql);
			pst.setString(1, name);
			pst.setString(2, pwd);
			ResultSet rs=pst.executeQuery();
			if (rs.next())
			{
				UsersVo user = new UsersVo();
				user.setId(rs.getInt("id"));
				user.setName(rs.getString("uname"));
				user.setPwd(rs.getString("upass"));
				user.setSex(rs.getInt("sex"));
				user.setFavs(rs.getString("favs"));
				user.setCity(rs.getString("city"));
				user.setJianjie(rs.getString("jianjie"));
				return user;
			
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			try {
				if (pst!=null)
				{
					pst.close();
				}
				if (conn!=null && !conn.isClosed())
				{
					conn.close();
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		return null;
	}
}
