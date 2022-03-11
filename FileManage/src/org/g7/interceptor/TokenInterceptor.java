package org.g7.interceptor;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.g7.domin.JwtService;
import org.g7.domin.Login;
import org.g7.domin.ResponseData;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

public class TokenInterceptor implements HandlerInterceptor{

    public void afterCompletion(HttpServletRequest request,
            HttpServletResponse response, Object handler, Exception arg3)
            throws Exception {
    }

    public void postHandle(HttpServletRequest request, HttpServletResponse response,
            Object handler, ModelAndView model) throws Exception {
    }

    //拦截每个请求
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response,
            Object handler) throws Exception {
        response.setCharacterEncoding("utf-8");
        String token = request.getHeader("Authorization");
        System.out.println(token);
        ResponseData responseData = ResponseData.ok();
        //token不存在
        if(null != token) {
            Login login = JwtService.unsign(token, Login.class);
            String loginId = request.getParameter("loginId");
            //解密token后的loginId与用户传来的loginId不一致，一般都是token过期
            if(null != loginId && null != login) {
                if(loginId == login.getLoginid()) {
                    return true;
                } else {
                    responseData = ResponseData.forbidden();
                    responseMessage(response, response.getWriter(), responseData);
                    return false;
                }
            } else {
                responseData = ResponseData.forbidden();
                responseMessage(response, response.getWriter(), responseData);
                return false;
            }
        } else {
            responseData = ResponseData.forbidden();
            responseMessage(response, response.getWriter(), responseData);
            return false;
        }
    }

    //请求不通过，返回错误信息给客户端
    private void responseMessage(HttpServletResponse response, PrintWriter out, ResponseData responseData) throws IOException {
        response.sendRedirect("/index"); 
    }

}