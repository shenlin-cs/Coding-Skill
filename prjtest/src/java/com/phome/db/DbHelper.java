package com.phome.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DbHelper {
	static{
		//1.加载驱动
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public Connection getConnect() throws SQLException
	{
		//2.建立连接
		String url="jdbc:mysql://localhost:3306/mydb?characterEncoding=UTF-8";
		Connection conn=DriverManager.getConnection(url, "root", "root");
		return conn;
	}
	
	public int executeUpdate(String sql,Object[] args)
	{
		Connection conn=null;
		PreparedStatement pst=null;
		try {
			conn=this.getConnect();
			pst=conn.prepareStatement(sql);
			if (args!=null)
			{
				for (int i = 0; i < args.length; i++) {
					pst.setObject(i+1, args[i]);
				}
			}
			int rows=pst.executeUpdate();
			return rows;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally{
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
		return -1;
	}
	
	public static void main(String[] args) {
		Connection conn=null;
		PreparedStatement pst=null;
		try {
			//1.加载驱动
			Class.forName("com.mysql.jdbc.Driver");
			//2.建立连接
			String url="jdbc:mysql://localhost:3306/mydb?characterEncoding=UTF-8";
			 conn=DriverManager.getConnection(url, "root", "root");
			//3.执行sql语句
			String sql="insert into product values (default,?,?,?)";
			
			 pst=conn.prepareStatement(sql);
			pst.setObject(1, "c++新品");
			pst.setObject(2, 59.3);
			pst.setString(3, "/images/indexbanner_02.gif");
			int result=pst.executeUpdate();
			
			//4.处理执行结果
			if (result>0)
			{
				System.out.println("插入数据库成功");
			}
			else
			{
				System.out.println("插入数据库失败");
			}
			//5.关闭
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally{
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
		
	}
}
