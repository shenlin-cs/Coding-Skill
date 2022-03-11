package org.apache.jsp.background;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.util.*;

public final class loginview_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write('\r');
      out.write('\n');

String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

      out.write("\r\n");
      out.write("\r\n");
      out.write("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\r\n");
      out.write("<html>\r\n");
      out.write("  <head>\r\n");
      out.write("    <base href=\"");
      out.print(basePath);
      out.write("\">\r\n");
      out.write("    \r\n");
      out.write("    <title>My JSP 'loginview.jsp' starting page</title>\r\n");
      out.write("    \r\n");
      out.write("\t<meta http-equiv=\"pragma\" content=\"no-cache\">\r\n");
      out.write("\t<meta http-equiv=\"cache-control\" content=\"no-cache\">\r\n");
      out.write("\t<meta http-equiv=\"expires\" content=\"0\">    \r\n");
      out.write("\t<meta http-equiv=\"keywords\" content=\"keyword1,keyword2,keyword3\">\r\n");
      out.write("\t<meta http-equiv=\"description\" content=\"This is my page\">\r\n");
      out.write("\t<!--\r\n");
      out.write("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"styles.css\">\r\n");
      out.write("\t-->\r\n");
      out.write("\r\n");
      out.write("  </head>\r\n");
      out.write("  \r\n");
      out.write("  <body>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("  <br/>\r\n");
      out.write("    <form action=\"");
      out.print(request.getContextPath() );
      out.write("/background/login.jsp\" method=\"post\">\r\n");
      out.write("      <table width=\"400\" align=\"center\" bgcolor=\"#cccccc\" border=\"0\" cellspacing=\"1\" cellpadding=\"1\">\r\n");
      out.write("         <tr bgcolor=\"#FFFFFF\">\r\n");
      out.write("            <td>用户名：</td>\r\n");
      out.write("            <td><input type=\"text\" name=\"userName\" style=\"width: 150px\"/> </td>\r\n");
      out.write("         </tr>\r\n");
      out.write("         <tr bgcolor=\"#FFFFFF\">\r\n");
      out.write("            <td>密码：</td>\r\n");
      out.write("            <td><input type=\"password\" name=\"password\" style=\"width: 150px\"/> </td>\r\n");
      out.write("         </tr>\r\n");
      out.write("         <tr bgcolor=\"#FFFFFF\">\r\n");
      out.write("            <td><input type=\"submit\" value=\"登录\"> </td>\r\n");
      out.write("            <td><input type=\"reset\" name=\"重写\" /> </td>\r\n");
      out.write("         </tr>\r\n");
      out.write("      </table>\r\n");
      out.write("    </form>\r\n");
      out.write("  </body>\r\n");
      out.write("</html>\r\n");
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
