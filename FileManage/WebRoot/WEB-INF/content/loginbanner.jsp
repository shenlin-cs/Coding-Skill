<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="cache-control" content="no-cache">
<meta http-equiv="expires" content="0">
<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
<meta http-equiv="description" content="This is my page">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
<title>登录 - 模式动物研究中心</title>
<link rel="icon" href="./images/favicon.png" type="image/x-icon">
<meta name="keywords" content="登录模式动物研究中心,模式动物研究中心用户登录">
<meta name="description" content="">
    <style>
        html {
            font-family: 'pingfang SC', 'helvetica neue', arial, 'hiragino sans gb', 'microsoft yahei ui', 'microsoft yahei', simsun, sans-serif;
            font-size: 14px;
            color: #333
        }

        body, button, dd, div, dl, dt, form, h1, h2, h3, h4, h5, h6, hr, input, li, ol, p, td, textarea, th, ul {
            margin: 0;
            padding: 0
        }

        .h_panel, .login_banner {
            height: 40px;
            background-color: #2b303b;
            padding: 0 20px;
            min-width: 980px
        }

        .h_logo {
            width: 300px;
            height: 40px;
            background-image: url(./images/logo.svg);
            margin-top: 0px;
            background-position: 0% 0%;
            background-size: 100% 100%;;
            background-repeat: no-repeat

        }

        .h_logo a {
            display: block;
            overflow: hidden;
            text-indent: -10000px;
            outline: 0;
            width: 100%;
            height: 100%
        }

        .login_banner_panel {
            width: 100%;
            height: 588px;
            background-image: url(./images/7.png);
            position: absolute;
            left: 0px;
            top: 98px;
            padding: 0px -20px;
            background-repeat: no-repeat;
            background-position: 0% 0%;
            background-size: 100% 100%;;
        }

        .login_banner_panel a {
            display: block;
            height: 588px;
            padding: 0px 0px;
            text-indent: -10000px;
        }
    </style>
</head>
<body>
<div class="h_panel">
    <div class="h_logo">
        <a href="http://localhost:8080/FileManage" target="_parent">模式动物研究中心</a>
    </div>
</div>
<div class="login_banner_panel" id="J_panel">
    <!-- 底部定位的bg -->
    <a href="http://localhost:8080/FileManage" target="_parent" id="J_link">模式动物研究中心</a>
</div>
</body>
</html>
