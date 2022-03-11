package org.apache.jsp.background;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.util.*;
import com.phome.vo.ProductVo;
import com.phome.db.ProductDAO;

public final class addproduct_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=ISO-8859-1");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");

    String proName=request.getParameter("proName");
    String proPrice=request.getParameter("proPrice");
    String proPicture=request.getParameter("proPicture");
    //éç©ºå¤ç
    if (proName==null || "".equals(proName))
    {
    	response.sendRedirect(request.getContextPath()+"/background/addproductview.jsp?proname=fail");
    	return;
    }
    if (proPicture==null )
    {
    	proPicture="";
    }
    
    if (proPrice==null || "".equals(proPrice) )
    {
    	response.sendRedirect(request.getContextPath()+"/background/addproductview.jsp?price=fail1");
    	return;
    }
    
    double price=0;
    try{
    	price=Double.parseDouble(proPrice);
    }
    catch(Exception e)
    {
    	response.sendRedirect(request.getContextPath()+"/background/addproductview.jsp?price=fail2");
    	return;
    }
    
    
    //æ·»å å°æ°æ®åº
    
    ProductVo pro=new ProductVo();
    pro.setProName(proName);
    pro.setPrice(price);
    pro.setPicture(proPicture);
    
    ProductDAO dao=new ProductDAO();
    int rows=dao.saveProduct(pro);
    if (rows>0)
    {
    	response.sendRedirect(request.getContextPath()+"/background/success.jsp");
    	return;
    }
    else
    {
    	
    }
    
    

    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
