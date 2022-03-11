package com.phome.db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import com.phome.vo.ProductVo;
import com.phome.vo.UsersVo;

public class ProductDAO {
	/**
	 * 根据商品id查询商品信息
	 * @param proid
	 * @return
	 */
	public ProductVo getProductById(int proid)
	{
		String sql="select * from product where proid=?";
		DbHelper dbhelp=new DbHelper();
		Connection conn=null;
		PreparedStatement pst=null;
		try {
			conn=dbhelp.getConnect();
			pst=conn.prepareStatement(sql);
			pst.setInt(1, proid);
			ResultSet rs=pst.executeQuery();
			while (rs.next())
			{
				ProductVo pro=new ProductVo();
				pro.setProid(rs.getInt("proid"));
				pro.setProName(rs.getString("proName"));
				pro.setPrice(rs.getDouble("proprice"));
				pro.setPicture(rs.getString("propicture"));
				return pro;
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
	/**
	 * 查询所有商品信息，放入ArrayList集合中
	 * @return
	 */
	//ArrayList就是可变数组，可以保持任何数据
	public ArrayList<ProductVo> getAllProduct()
	{
		ArrayList<ProductVo> list=new ArrayList<ProductVo>();
		String sql="select * from product";
		DbHelper dbhelp=new DbHelper();
		Connection conn=null;
		PreparedStatement pst=null;
		try {
			conn=dbhelp.getConnect();
			pst=conn.prepareStatement(sql);
			ResultSet rs=pst.executeQuery();
			while (rs.next())
			{
				ProductVo pro=new ProductVo();
				pro.setProid(rs.getInt("proid"));
				pro.setProName(rs.getString("proName"));
				pro.setPrice(rs.getDouble("proprice"));
				pro.setPicture(rs.getString("propicture"));
				list.add(pro);//把数据对象放入ArrayList集合中。
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
		return list;
	}
	/**
	 * 添加商品信息到数据库
	 * @param product
	 * @return
	 */
	public int saveProduct(ProductVo product)
	{
		String sql="insert into product values (default,?,?,?)";
		Object[] args=new Object[]{product.getProName(),product.getPrice(),product.getPicture()};
		DbHelper dbHelper=new DbHelper();
		int rows=dbHelper.executeUpdate(sql, args);
		return rows;
	}
	/**
	 * 根据商品信息修改对应的数据库数据
	 * @param product
	 * @return
	 */
	public int updateProduct(ProductVo product)
	{
		String sql="update product set proName=?,proprice=?,propicture=? where proid=?";
		Object[] args=new Object[]{product.getProName(),product.getPrice(),product.getPicture(),product.getProid()};
		
		DbHelper dbHelper=new DbHelper();
		int rows=dbHelper.executeUpdate(sql, args);
		return rows;
	}
	/**
	 * 根据商品Id在数据库中删除该商品信息
	 * @param id
	 * @return
	 */
	public int deleteProduct(int id)
	{
		String sql="delete from product where proid=?";
		Object[] args=new Object[]{id};
		DbHelper dbHelper=new DbHelper();
		int rows=dbHelper.executeUpdate(sql, args);
		return rows;
	}

	
}
