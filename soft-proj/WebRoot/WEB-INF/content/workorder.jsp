<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">

    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=2">
    <meta name="format-detection" content="telephone=no">
    <title>工单系统</title>
    <script src="./js/jquery-3.3.1.js"></script>
    <script src="./js/base.js"></script>
    <script src="./css/aq_common.js.下载"></script>
    <script src="./css/stats"></script>
    <script type="text/javascript">
        var speedMark = _speedMark = new Date();
        window._enableReport = true;
        window.serverTimeForPlatformUsageOnly = (function (s, c) {
            return function () {
                return +new Date() + s - c;
            }
        })(1563092780785, +new Date());
        window.lifeId = "ryH4wwubB";
        window.lifeStart = serverTimeForPlatformUsageOnly();
        window.qcLoginSdkUrl = "https://imgcache.qq.com/qcloud/main/scripts/release/common/login/api.bfc27ab1bd1911b65056.js?max_age=31536000";
        // window._cosdp = /^(https?:)?\/\/(img\.qcloud\.com|imgcache\.qq\.com)/; // 支持跨域脚本协议的域名
        window._cosdp = /$.^/; // 禁用跨域头
        window.LOGIN_INFO = {
            "loginUin": 100006710252,
            "ownerUin": 100006710252,
            "appId": 1257210837,
            "identity": {"subjectType": 0, "authType": 4, "authArea": 0},
            "area": 1,
            "countryName": "CN",
            "countryCode": "86"
        };
    </script>
    <link href="./css/global-201905061503.css" rel="stylesheet" data-role="global">
    <link href="./css/bee.css" rel="stylesheet" data-role="global">
    <link href="./css/break.css" rel="stylesheet" data-role="global">
    <link href="./css/monitor-sdk.css" rel="stylesheet" data-role="global">
    <link href="./css/tea-0.0.7.min.css" rel="stylesheet" data-role="global">
    <link href="./images/favicon.png" rel="icon" type="image/x-icon">
    <script type="text/javascript">
        
    function getCookieValue(name){ /**获取cookie的值，根据cookie的键获取值**/
        //用处理字符串的方式查找到key对应value
    var name = escape(name);
        //读cookie属性，这将返回文档的所有cookie
        var allcookies = document.cookie;
        //查找名为name的cookie的开始位置
        name += "=";
        var pos = allcookies.indexOf(name);
        //如果找到了具有该名字的cookie，那么提取并使用它的值
        if (pos != -1){                       //如果pos值为-1则说明搜索"version="失败
            var start = pos + name.length;         //cookie值开始的位置
            var end = allcookies.indexOf(";",start);    //从cookie值开始的位置起搜索第一个";"的位置,即cookie值结尾的位置
            if (end == -1) end = allcookies.length;    //如果end值为-1说明cookie列表里只有一个cookie
            var value = allcookies.substring(start,end); //提取cookie的值
            return (value);              //对它解码
        }else{ //搜索失败，返回空字符串
            return "";
        }
    }
	window.onload = function(){
        var loginid = getCookieValue("loginid");
        if(loginid=="")
        {
            window.location.href = "http://localhost:8080/FileManage/login";
        }
        else
        {
            $(".qc-user-name").html(loginid);
            $(".qc-user-name").css("title",loginid);
        }
        $.ajax({
            type : "GET",
            url : "http://localhost:8080/FileManage/api/UnConfirmedNoteQuery?",
            dataType : "json",
            data : {
                ClerkID: loginid,
                IsEstablished:'n',
                IsClerkDeal:'n',
                token: sessionStorage.getItem("token")},
            async : false,
            success:function(result){
            $("#appArea > div > div.manage-area-main > div.main-body > div:nth-child(1) > div > div.tc-15-table-fixed-body > table").html("");
                $.each(result.data,function(i,val){
                    var list="<tbody><tr data-tips=\"\">\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["type"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["id"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["experimentID"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["inputTime"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["headID"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["headName"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                            <td colspan=\"1\" >\n" +
                        "                                                <div>"+val["isEstablished"]+"</div>\n" +
                        "                                            </td>\n" +
                        "                                        </tr></tbody>";
                    $("#appArea > div > div.manage-area-main > div.main-body > div:nth-child(1) > div > div.tc-15-table-fixed-body > table").append(list);
                })
            },
            error: function (result) {
                console.log("error: " + JSON.stringify(result));
            }
        });
    }
    </script>
    <style>
        .onfocus-item {
            border: 1px solid #a5c7fe !important;
        }

        .container
         {
            transform: none;
            transition: none;
            height: auto;
        }

        .container.animate {
            transition: left 0.3s;
            transform: translate3d(0, 0, 0);
        }

        [data-region-selector].tc-15-dropdown-in-hd .tc-15-dropdown-menu {
            max-height: none;
        }


    </style>
    <link charset="utf-8" rel="stylesheet" href="./css/account-center.css"
          class="developer-css developer_index-css" disabled="">
    <link charset="utf-8" rel="stylesheet" href="./css/global-mobile.import.css"
          class="developer-css developer_index-css" disabled="">
    <style type="text/css">@keyframes fade-in {
                               0% {
                                   opacity: 0
                               }
                               100% {
                               }
                           }

    @-webkit-keyframes fade-in {
        0% {
            opacity: 0
        }
        100% {
        }
    }

    @keyframes fade-out {
        0% {
        }
        100% {
            opacity: 0
        }
    }

    @-webkit-keyframes fade-out {
        0% {
        }
        100% {
            opacity: 0
        }
    }

    @keyframes modal-in {
        0% {
            opacity: 0;
            transform: scale(0.8, 0.8);
            -moz-transform: scale(0.8, 0.8);
            -webkit-transform: scale(0.8, 0.8);
            -ms-transform: scale(0.8, 0.8);
        }
        100% {
        }
    }

    @-webkit-keyframes modal-in {
        0% {
            opacity: 0;
            transform: scale(0.8, 0.8);
            -moz-transform: scale(0.8, 0.8);
            -webkit-transform: scale(0.8, 0.8);
            -ms-transform: scale(0.8, 0.8);
        }
        100% {
        }
    }

    @keyframes modal-out {
        0% {
        }
        100% {
            transform: scale(0.8, 0.8);
            -moz-transform: scale(0.8, 0.8);
            -webkit-transform: scale(0.8, 0.8);
            -ms-transform: scale(0.8, 0.8);
            opacity: 0
        }
    }

    @-webkit-keyframes modal-out {
        0% {
        }
        100% {
            transform: scale(0.8, 0.8);
            -moz-transform: scale(0.8, 0.8);
            -webkit-transform: scale(0.8, 0.8);
            -ms-transform: scale(0.8, 0.8);
            opacity: 0
        }
    }

    .mask-in {
        animation: fade-in 0.2s;
        -webkit-animation: fade-in 0.2s;
    }

    .mask-out {
        animation: fade-out 0.2s;
        -webkit-animation: fade-out 0.2s;
    }

    .modal-in {
        animation: modal-in 0.15s;
        -webkit-animation: modal-in 0.15s;
    }

    .modal-out {
        animation: modal-out 0.15s;
        -webkit-animation: modal-out 0.15s;
    }

    .fade-in {
        animation: fade-in 0.3s;
        -webkit-animation: fade-in 0.3s;
    }

    .fade-out {
        animation: fade-out 0.3s;
        -webkit-animation: fade-out 0.3s;
    }

    .error-page {
        width: 800px;
        text-align: center;
        margin: 100px auto 0;
        padding: 50px;
        font-size: 18px;
        line-height: 1.5;
        color: #999;
        border: 1px solid #e0e0e0;
        background-color: #fff;
    }

    .error-page h2 {
        font-size: 40px;
        font-weight: bold
    }</style>
    <link charset="utf-8" rel="stylesheet" href="./css/auth.css" class="developer_index-css" disabled="">
    <link charset="utf-8" rel="stylesheet" href="./css/msg-center.css"
          class="message-css message_index-css" disabled="">
    <style id="dynamic-inserted-css-tea-transition-scale150181594">
        .tea-transition-scale150181594-enter {
            opacity: 0 !important;
            transform: scale3d(0.5, 0.5, 0.5);
            transform-origin: center;
        }

        .tea-transition-scale150181594-enter-active {
            opacity: 1 !important;
            transform: scale3d(1, 1, 1);
            transition: opacity 300ms ease,
            transform 300ms ease;
            transform-origin: center;
        }

        .tea-transition-scale150181594-exit {
            opacity: 1 !important;
            transform: scale3d(1, 1, 1);
            transform-origin: center;
        }

        .tea-transition-scale150181594-exit-active {
            opacity: 0 !important;
            transform: scale3d(0.5, 0.5, 0.5);
            transition: opacity 300ms ease,
            transform 300ms ease;
            transform-origin: center;
        }
    </style>
    <style id="dynamic-inserted-css-tea-transition-slide-2068824837">
        .tea-transition-slide-2068824837-enter {
            opacity: 0 !important;
            transform: translate3d(0px, -30px, 0);
        }

        .tea-transition-slide-2068824837-enter-active {
            opacity: 1 !important;
            transform: translate3d(0, 0, 0);
            transition: opacity 300ms ease,
            transform 300ms ease;
        }

        .tea-transition-slide-2068824837-exit {
            opacity: 1 !important;
            transform: translate3d(0, 0, 0);
        }

        .tea-transition-slide-2068824837-exit-active {
            opacity: 0 !important;
            transform: translate3d(0px, -30px, 0);
            transition: opacity 300ms ease,
            transform 300ms ease;
        }
    </style>
    <link charset="utf-8" rel="stylesheet" href="./css/work-order.css" class="workorder-css">
    <style type="text/css">
        .tc-15-table-panel .text-center a {
            vertical-align: baseline;
        }
    </style>
</head>
<body style="">


<div id="pageWrapper">
    <div class="qc-header-nav" id="topnav">
        <div class="qc-header-inner">
            <div class="qc-header-unit qc-header-logo">
                <div class="qc-nav-logo">
                    <a target="_blank" class="qc-logo-inner" href="http://localhost:8080/FileManage" title="返回首页"
                       data-hot="header.qcloudid" data-event="hot_tag_link">
                        <span class="qc-logo-icon">返回首页</span>
                    </a>
                </div>
                <div class="qc-nav-mobile-user" data-event="top_user_mobile">
                    <a class="qc-mobile-user-inner" href="javascript:void(0);" data-hot="m.header.user">
                        <i></i>
                    </a>
                </div>
                <div class="qc-nav-mobile-menu" data-event="top_submenu_mobile" data-hot="m.header.product">
                    <div class="qc-mobile-menu-inner">
                        <span></span>
                    </div>
                </div>
            </div>

            <div class="qc-nav-service" data-event="top_submenu" data-menu-type="product" data-menu-inited="true"
                 id="J-top_submenu">
                <div class="qc-service-inner">
                    <div class="qc-service-tool">
                        <span style="cursor:default" class="qc-service-text" id="t_product">系统功能</span>
                        <i class="qc-nav-arrows" style=""></i>
                    </div>
                    <div class="qc-service-menu" id="productService" style="height: 800px;">
                        <div class="qc-service-menu-inner"><i class="qc-service-icon J-headerProductClose"
                                                              id="J-headerProductClose"></i>
                            <div class="menu-list-search J-headerProductSearchBar">
                                <div class="menu-search-tool"><input type="text"
                                                                     class="menu-search-input J-productSearchInput"
                                                                     id="menu-search"
                                                                     placeholder="通过名称/关键字查找（例如：Group 7  实验动物档案管理等）">
                                    <button type="button" class="menu-search-btn"></button>
                                </div>
                                <ul class="menu-search-result J-searchList" style=""></ul>
                            </div>
                            <div class="menu-list-all J-headerProductList">
                                <div class="menu-list-col">
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_0" class="menu-area-tit"><em>Group 1</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_0"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_1"
                                                        data-event="nav" title="基础数据维护"
                                                        data-hot="header.navigation.internal.cvm"><span
                                                        class="menu-item-text">基础数据维护</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_1" class="menu-area-tit"><em>Group 6</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_1"
                                             tabindex="0" role="list">
                                            <div class="menu-item" data-nav="nav_CMQ_WHITELIST" style="">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_6"
                                                        data-event="nav"
                                                        title="实验方案处理"
                                                        data-hot="header.navigation.internal.mq"><span
                                                        class="menu-item-text">实验方案处理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_11" class="menu-area-tit"><em>Group 11</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_1"
                                             tabindex="0" role="list">
                                            <div class="menu-item" data-nav="nav_CMQ_WHITELIST" style="">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_01"
                                                        data-event="nav"
                                                        title="核算管理"
                                                        data-hot="header.navigation.internal.mq"><span
                                                        class="menu-item-text">核算管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="menu-list-col">
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_6" class="menu-area-tit"><em>Group 2</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_6"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_02"
                                                        data-event="nav" title="编码体系管理"
                                                        data-hot="header.navigation.internal.cos"><span
                                                        class="menu-item-text">编码体系管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_7" class="menu-area-tit"><em>Group 7</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_7"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_5"
                                                        data-event="nav" title="实验动物档案管理"
                                                        data-hot="header.navigation.internal.cdb"><span
                                                        class="menu-item-text">实验动物档案管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_12" class="menu-area-tit"><em>Group 12</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_7"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_10"
                                                        data-event="nav" title="猪场环境管理"
                                                        data-hot="header.navigation.internal.cdb"><span
                                                        class="menu-item-text">猪场环境管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="menu-list-col">
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_3" class="menu-area-tit"><em>Group 3</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_12"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_1"
                                                        data-event="nav" title="用户管理"
                                                        data-hot="header.navigation.internal.clb"><span
                                                        class="menu-item-text">用户管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_13" class="menu-area-tit"><em>Group 8</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_13"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_6"
                                                        data-event="nav" title="仪器设备管理"
                                                        data-hot="header.navigation.internal.cdn"><span
                                                        class="menu-item-text">仪器设备管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="menu-list-col">
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_22" class="menu-area-tit"><em>Group 4</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_22"
                                             tabindex="0" role="list">
                                            <div class="menu-item" data-nav="nav_ai_image_face_recognition"
                                                 style="">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_2"
                                                        data-event="nav" title="试剂药品耗材管理"
                                                        data-hot="header.navigation.internal.aiface"><span
                                                        class="menu-item-text">试剂药品耗材管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_23" class="menu-area-tit"><em>Group 9</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_23"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_7"
                                                        data-event="nav"
                                                        title="质量管控" data-hot="header.navigation.internal.ai"><span
                                                        class="menu-item-text">质量管控</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="menu-list-col">
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_32" class="menu-area-tit"><em>Group 5</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_32"
                                             tabindex="0" role="list">
                                            <div class="menu-item">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_3"
                                                        data-event="nav" title="动物转平台出设施"
                                                        data-hot="header.navigation.internal.mgobe"><span
                                                        class="menu-item-text">动物转平台出设施</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="menu-area J-headerProductGroup">
                                        <div id="product_list_title_33" class="menu-area-tit"><em>Group 10</em></div>
                                        <div class="menu-area-con" aria-labelledby="product_list_title_33"
                                             tabindex="0" role="list">
                                            <div class="menu-item" data-nav="nav_qcloudpay_whitelist" style="">
                                                <div class="menu-item-tit"><a
                                                        href="http://localhost:8080/FileManage/homepage_8"
                                                        data-event="nav" title="核算管理"
                                                        data-hot="header.navigation.internal.cpay"><span
                                                        class="menu-item-text">核算管理</span></a></div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <div class="qc-header-unit qc-header-user">
                <!--user start-->
                <div class="qc-nav-user" data-event="top_submenu" data-menu-type="user" id="userInfo"
                     data-menu-inited="true">
                    <div class="qc-user-inner"><i class="qc-user-icon"></i><span class="qc-user-name"
                                                                                 data-hot="header.user.center"
                                                                                 title="g7">g7</span><i
                            class="qc-nav-arrows"></i>
                        <div class="qc-user-info qc-user-panel">
                            <div class="qc-user-panel-inner J-dropdownPanel"><a
                                    href="http://localhost:8080/FileManage/developer" data-event="nav"
                                    data-hot="header.user.developer">账号信息</a> <a
                                    href="http://localhost:8080/FileManage/security" data-event="nav"
                                    data-hot="header.user.security">安全设置</a> <a
                                    href="http://localhost:8080/FileManage/overview" data-event="nav"
                                    data-hot="header.user.permission">访问管理</a> <a
                                    href="http://localhost:8080/FileManage/project" style="" data-auth="project"
                                    data-event="nav" data-hot="header.user.project">项目管理</a> <a
                                    href="http://localhost:8080/FileManage/partners" style="display:none"
                                    data-auth="returnAmount" data-event="nav" data-hot="header.user.agent">渠道管理</a>
                                <span
                                        class="qc-user-info-line"></span> <a href="javascript:void(0)"
                                                                             style="display: none;"
                                                                             data-event="changeAccount">切换用户身份</a> <a
                                        href="javascript:void(0)" data-event="logout">退出</a></div>
                        </div>
                    </div>
                </div>
                <!--user end-->
            </div>

            <div class="qc-header-unit  qc-header-account">
                <!--account start-->
                <div class="qc-nav-account" data-event="top_submenu" data-menu-type="cost" data-menu-inited="true">
                    <!--mobile account start-->
                    <div class="qc-nav-mobile-account">
                        <a href="http://localhost:8080/FileManage/account" data-event="nav" class="J-feeLink">费用</a>
                    </div>

                    <div class="qc-account-inner">
                        <a href="http://localhost:8080/FileManage/account" data-event="nav"
                           data-hot="header.fee.center" class="qc-account-text J-feeLink" id="t_cost">费用</a><i
                            class="qc-nav-arrows" style=""></i>
                        <div class="qc-account-info qc-user-panel">
                            <div class="qc-user-panel-inner J-dropdownPanel">
                                <div class="qc-user-balance"><span>            账户余额            <span
                                        class="unauth tc-15-bubble-icon tc-15-triangle-align-start"
                                        style="display: none;">                <i class="plaint-icon"></i>                <div
                                        class="tc-15-bubble tc-15-bubble-top">                    <div
                                        class="tc-15-bubble-inner">您暂无财务权限，请联系开发商负责人或有财务权限的协作者了解账户余额</div>                </div>            </span>        </span>
                                    <span class="J-costRecharge"><a
                                            href="http://localhost:8080/FileManage/account/recharge" style=""
                                            data-event="nav" data-auth="account" data-hot="header.user.rechage">立即充值</a></span>
                                    <div class="qc-balance-num"><span data-field="balance" data-event="nav"
                                                                      href="/account">0.00</span> <strong
                                            class="currency-unit">元</strong></div>
                                </div>
                                <ul class="qc-user-voucher">
                                    <li><a href="http://localhost:8080/FileManage/account/voucher" data-event="nav"
                                           data-field="voucher" data-hot="header.user.voucher">代金券</a></li>
                                    <li><a href="http://localhost:8080/FileManage/account/renewal" data-event="nav"
                                           data-field="renewal" data-hot="header.user.renewal">续费</a></li>
                                    <li><a href="http://localhost:8080/FileManage/account/invoice" data-event="nav"
                                           data-field="invoice" data-hot="header.user.invoice"
                                           data-auth="checkPassState">发票</a></li>
                                </ul>
                                <div class="qc-user-list"><a href="http://localhost:8080/FileManage/deal"
                                                             data-field="deal" data-event="nav"
                                                             data-hot="header.user.deal">我的订单</a> <a style=""
                                                                                                     data-auth="account"
                                                                                                     href="http://localhost:8080/FileManage/account/fee"
                                                                                                     data-event="nav"
                                                                                                     data-hot="header.user.account">收支明细</a>
                                    <a style="" data-auth="account"
                                       href="http://localhost:8080/FileManage/expense/bill/overview" data-event="nav"
                                       data-hot="header.user.account">资源账单</a> <a style="" data-field="contract"
                                                                                  data-auth="account"
                                                                                  href="http://localhost:8080/FileManage/account/contract"
                                                                                  data-event="nav"
                                                                                  data-hot="header.user.account.contract">合同管理</a>
                                </div>
                                <div class="qc-account-center"><a style="" data-auth="account"
                                                                  href="http://localhost:8080/FileManage/account"
                                                                  data-event="nav"
                                                                  data-hot="header.user.account">费用中心</a></div>
                            </div>
                        </div>
                    </div>
                </div>
                <!--account end-->

                <!--workorder start-->
                <div class="qc-nav-workorder" data-event="nav-workorder">
                    <a href="http://localhost:8080/FileManage/workorder" data-event="nav" class="qc-workorder-inner"
                       data-hot="header.workorder">
                        <span class="qc-workorder-text" id="t_workorder">工单</span>
                    </a>
                </div>
                <!--workorder end-->
            </div>
            <div class="qc-header-unit  qc-header-tool">
                <!--message start-->
                <div class="qc-nav-message" data-event="top_submenu" id="message_trigger" data-menu-inited="true">
                    <!--mobile message start-->
                    <div class="qc-nav-mobile-message">
                        <a href="http://localhost:8080/FileManage/message" data-event="nav" data-hot="m.header.message"
                           class="J-msgLink">消息中心</a>
                    </div>
                    <!--mobile message- end-->
                    <div class="qc-message-inner">
                        <i class="qc-message-icon J-headerMsgIcon"><em style="visibility: hidden">0</em></i>
                        <div class="qc-tool-message qc-tool-panel J-dropdownPanel" style="height: 750px;">
                            <div class="qc-tool-inner" id="thisIsMsgCenter">
                                <div class="qc-tool-head J-message-head"><h3 class="qc-tool-head-title">消息中心</h3><a
                                        class="qc-tool-more" href="http://localhost:8080/FileManage/message"
                                        data-event="nav" data-hot="header.message.more">查看更多</a><a
                                        class="qc-tool-head-close J-closeMsgIcon"><i class="qc-close-panel"></i></a>
                                </div>
                                <div class="qc-tool-body J-message-body" style="height: 749px;">
                                    <div class="qc-nav-message-list" id="message_list">
                                        <div class="qc-tool-info">暂无未读消息</div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <!--message end-->

                <!--log start-->
                <div class="qc-nav-log" data-event="top_submenu" id="operatelog_trigger"
                     data-menu-inited="true">
                    <!--mobile log start-->
                    <div class="qc-nav-mobile-log">
                        <a href="http://localhost:8080/FileManage/operatelog" data-event="nav"
                           data-hot="m.header.operatelog">操作日志</a>
                    </div>
                    <!--mobile log end-->
                    <div class="qc-log-inner">
                        <i class="qc-log-icon J-headerLogIcon"></i>
                        <div class="qc-tool-log qc-tool-panel J-dropdownPanel" style="height: 750px;">
                            <div class="qc-tool-inner">
                                <div class="qc-tool-head J-tool-head"><h3 class="qc-tool-head-title">最近操作</h3>        <a
                                        class="qc-tool-more" href="http://localhost:8080/FileManage/cloudaudit"
                                        data-event="nav" data-hot="header.operatelog.more">查看更多</a><a
                                        class="qc-tool-head-close J-closeLogIcon" href="javascript:;"><i
                                        class="qc-close-panel"></i></a></div>
                                <div class="qc-tool-body J-operatelogList" style="height: 699px;">
                                    <div class="qc-tool-info">暂无操作日志</div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="tip-msg-win floattips-container"></div>
                </div>
                <!--log end-->

                <!--help start-->
                <div class="qc-nav-help" data-event="top_submenu" id="help_trigger" data-menu-type="help"
                     data-menu-inited="true">
                    <!--mobile help start-->
                    <div class="qc-nav-mobile-help">
                        <a href="http://localhost:8080/FileManage/document/product" data-hot="m.header.document"
                           target="_blank">帮助与文档<i class="menu-external-link"></i></a>
                    </div>
                    <!--mobile help end-->
                    <div class="qc-help-inner">
                        <i class="qc-help-icon J-headerHelpIcon"></i>
                        <div class="qc-tool-help qc-tool-panel J-dropdownPanel" style="height: 750px;">
                            <div class="qc-tool-inner J-headerHelpWrapper">
                                <div class="qc-tool-head J-helper-head"><h3 class="qc-tool-head-title">帮助中心</h3>
                                    <a class="qc-tool-head-close J-close-help-icon" href="javascript:;"><i
                                            class="qc-close-panel"></i></a></div>
                                <div class="qc-tool-body J-helper-body" style="height: 729px;">
                                    <div class="qc-help-search-box"><input type="text" id="input_search_cont_help"
                                                                           class="qc-help-search-cont"
                                                                           placeholder="请输入您想了解或感兴趣的问题">
                                        <button type="button" class="qc-help-search-btn"></button>
                                    </div>
                                    <div class="qc-question-list-wrap J-question-list">
                                        <dl class="qc-question-list">
                                            <dt>您可能需要</dt>
                                            <dd><a class="external-link-help" data-type="2" target="_blank"
                                                   href="#">常见操作指南</a>
                                            </dd>
                                            <dd><a class="external-link-help" data-type="2" target="_blank"
                                                   href="#">登陆注册指引</a>
                                            </dd>
                                            <dd><a class="external-link-help" data-type="2" target="_blank"
                                                   href="#">产品文档</a></dd>
                                            <dd><a class="external-link-help" data-type="2" target="_blank"
                                                   href="#">API文档</a>
                                            </dd>
                                        </dl>
                                    </div>
                                    <!-- <div class="qc-doc-video">      <ul class="J-video-list">          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80" data-video="//imgcache.qq.com/open_proj/proj_qcloud_v2/gateway/product/ugsv/css/img/demo/demo-1.mp4">                  <div class="qc-doc-video-title">云服务器配置介绍云服务器配置介绍</div>              </a>          </li>          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80">                  <div class="qc-doc-video-title">云服务器配置介绍</div>              </a>          </li>          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80">                  <div class="qc-doc-video-title">云服务器配置介绍</div>              </a>          </li>          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80">                  <div class="qc-doc-video-title">云服务器配置介绍</div>              </a>          </li>      </ul>      <a href="javascript:;" class="qc-doc-video-more">更多视频</a>  </div> -->
                                </div>

                            </div>
                        </div>
                    </div>
                </div>
                <!--help end-->
            </div>
        </div>
    </div>
    <div class="container container-workorder" id="container" style="left: 0px;">
        <div class="aside qc-aside-new" id="sidebar">
            <div class="qc-aside-area">
                <div class="qc-aside-area-main"><h2 class="qc-aside-headline"><img class="qc-aside-service-icon"
                                                                                   src="./images/user.svg"><span>工单系统</span>
                </h2>
                    <ul class="qc-aside-list def-scroll keyboard-focus-obj">
                        <li><a class="qc-aside-level-1 qc-aside-select" data-event="nav"
                               href="https://console.cloud.tencent.com/developer" target="_self"><img
                                class="qc-aside-icon" src="./images/developer.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/developer(1).svg"><span>工单列表</span></a></li>
                        <li><a class="qc-aside-level-1" data-event="nav"
                               href="https://console.cloud.tencent.com/developer/security" target="_self"><img
                                class="qc-aside-icon" src="./images/security.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/security(1).svg"><span>提交工单</span></a></li>
                        <li><a class="qc-aside-level-1" href="https://console.cloud.tencent.com/cam/overview"
                               target="_blank"><img class="qc-aside-icon" src="./images/cam.svg"><img
                                class="qc-aside-icon qc-aside-icon-select" src="./images/cam(1).svg"><span>自助诊断<em
                                class="qc-menu-link"></em></span></a></li>
                    </ul>
                </div>
            </div>
            <div class="qc-menu-fold" data-event="toggle_sidebar" data-hot="sidebar.toggle.new"><i></i></div>
            <div class="tc-15-bubble tc-15-bubble-bottom qc-menu-tip J-newSidebarToggleTip" style="display: none">
                <div class="tc-15-bubble-inner">点击收起侧导航<a href="javascript:;" data-event="hideNewSidebarToggleTip"
                                                          class="qc-menu-tip-close"></a></div>
            </div>
        </div>
        <div class="main" id="appArea">
            <div class="manage-area">
                <div class="manage-area-title"><!----> <h2>
                    我的工单
                </h2>
                    <div class="manage-area-title-right"><a href="https://cloud.tencent.com/document/product"
                                                            target="_blank" class="wo-link">
                        帮助文档
                    </a> <a href="https://cloud.tencent.com/developer/ask" target="_blank"
                            class="wo-link J-community-link">
                        社区求助
                    </a>
                        <div class="tc-15-bubble-icon work-order-qr-btn"><a href="javascript:;" target="_blank">
                            手机工单
                        </a>
                            <div class="tc-15-bubble  tc-15-bubble-top"
                                 style="top: 20px; right: 0px; left: auto; width: 200px;">
                                <div class="tc-15-bubble-inner" style="left: 150px;">
                                    <div class="work-order-qr-img"><img src="./css/m-qr.jpg" alt="手机管理工单">
                                    </div>
                                    <div class="work-order-qr-txt">
                                        微信扫一扫，移动提交工单<br>随时查看工单进度、接收提醒
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="manage-area-main">
                    <div class="work-order-msg tc-panel">
                        <div class="work-order-status"><a href="javascript:void(0);" class="orderStatus">
                            <div>0</div>
                            <span>待我处理</span></a></div>
                        <div class="work-order-status"><a href="javascript:void(0);" class="orderStatus">
                            <div>0</div>
                            <span>处理中</span></a></div>
                        <div class="work-order-status"><a href="javascript:void(0);" class="orderStatus"
                                                          style="color: rgb(255, 157, 0);">
                            <div>0</div>
                            <span>全部工单提醒</span></a></div>
                    </div>
                    <div class="tc-15-action-panel">
                        <div class="tc-15-calendar-select-wrap tc-15-calendar2-hook">
                            <div role="tablist"><span role="tab" tabindex="0" class="">今天</span><span role="tab"
                                                                                                      tabindex="0"
                                                                                                      class="">昨天</span><span
                                    role="tab" tabindex="0" class="">近7天</span><span role="tab" tabindex="0"
                                                                                     class="current">全部</span></div>
                            <div class="tc-15-calendar-select-wrap tc-15-calendar2-hook">
                                <div class="tc-15-calendar-select">
                                    <button class="tc-15-simulate-select m show">2010-01-01 至 2019-07-14</button>
                                    <div class="tc-15-calendar-triangle-wrap"></div>
                                    <div class="tc-15-calendar-triangle"></div>
                                    <div class="tc-15-calendar tc-15-calendar2">
                                        <div class="tc-15-calendar-cont">
                                            <table cellspacing="0" class="tc-15-calendar-left">
                                                <caption>
                                                    0年0月
                                                </caption>
                                                <thead>
                                                <tr>
                                                    <th>日</th>
                                                    <th>一</th>
                                                    <th>二</th>
                                                    <th>三</th>
                                                    <th>四</th>
                                                    <th>五</th>
                                                    <th>六</th>
                                                </tr>
                                                </thead>
                                                <tbody>
                                                <tr>
                                                    <td colspan="7"><i tabindex="0"
                                                                       class="tc-15-calendar-i-pre-m"><b><span>转到上个月</span></b></i>
                                                    </td>
                                                </tr>
                                                </tbody>
                                            </table>
                                            <table cellspacing="0">
                                                <caption>
                                                    0年0月
                                                </caption>
                                                <thead>
                                                <tr>
                                                    <th class="sun">日</th>
                                                    <th>一</th>
                                                    <th>二</th>
                                                    <th>三</th>
                                                    <th>四</th>
                                                    <th>五</th>
                                                    <th class="sat">六</th>
                                                </tr>
                                                </thead>
                                                <tbody>
                                                <tr>
                                                    <td colspan="7" style="text-align: center;"><i tabindex="0"
                                                                                                   class="tc-15-calendar-i-next-m"><b><span>转到下个月</span></b></i>
                                                    </td>
                                                </tr>
                                                </tbody>
                                            </table>
                                        </div>
                                        <div class="tc-15-calendar-footer">
                                            <div class="tc-15-calendar-input">
                                                <div class="tc-15-input-text-wrap m"><input type="text"
                                                                                            class="tc-15-input-text">
                                                </div>
                                                <span role="separator">至</span>
                                                <div class="tc-15-input-text-wrap m"><input type="text"
                                                                                            class="tc-15-input-text">
                                                </div> <!----></div>
                                            <div class="tc-15-calendar-btns">
                                                <button class="tc-15-btn m">确定</button>
                                                <button class="tc-15-btn m weak">取消</button>
                                            </div>
                                        </div>
                                        <div class="tc-15-calendar-for-style"></div>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div data-role="qc-search" class="search-box tc-15-search m" style="width: 320px;">
                            <div class="search-input-wrap"><input placeholder="请输入工单号或问题描述关键词"
                                                                  class="tc-15-input-text search-input"> <!----> <!---->
                            </div>
                            <input type="button" value="搜索" title="搜索" class="search-btn"></div>
                    </div>
                    <div class="main-body">
                        <div data-role="qc-table">
                            <div class="tc-15-table-panel">
                                <div class="tc-15-table-fixed-head">
                                    <table class="tc-15-table-box">
                                        <colgroup><!----> <!---->
                                            <col style="width: 15%;">
                                            <col style="width: 15%;">
                                            <col style="width: 15%;">
                                            <col style="width: 13%;">
                                            <col style="width: 12%;">
                                            <col style="width: 15%;">
                                            <col style="width: auto;">
                                        </colgroup>
                                        <thead>
                                        <tr><!----> <!---->
                                            <th class="text-left">
                                                <div><!----> <!----> <span title="记录类型"
                                                                           class="text-overflow">记录类型</span></div>
                                                <i data-role="resizer" class="resize-line-icon"></i></th>
                                            <th class="text-left">
                                                <div><!----> <!----> <span title="记录编号"
                                                                           class="text-overflow">记录编号</span></div>
                                                <i data-role="resizer" class="resize-line-icon"></i></th>
                                            <th class="text-left">
                                                <div><!----> <!----> <span title="所属实验编号"
                                                                           class="text-overflow">所属实验编号</span></div>
                                                <i data-role="resizer" class="resize-line-icon"></i></th>
                                            <th class="text-left">
                                                <div><!----> <!----> <span title="录入时间" class="text-overflow">录入时间</span>
                                                </div>
                                                <i data-role="resizer" class="resize-line-icon"></i></th>
                                            <th class="text-left">
                                                <div><!----> <!----> <span title="负责人编号"
                                                                           class="text-overflow">负责人编号</span></div>
                                                <i data-role="resizer" class="resize-line-icon"></i></th>
                                            <th class="text-left">
                                                <div><span class="tc-15-th-sort-btn current"><span title="负责人姓名"
                                                                                                   class="text-overflow">负责人姓名</span> <i
                                                        class="up-sort-icon"></i></span></div>
                                                <i data-role="resizer" class="resize-line-icon"></i></th>
                                            <th class="text-left">
                                                <div><!----> <!----> <span title="文书类别" class="text-overflow">文书类别</span>
                                                </div> <!----></th>
                                        </tr>
                                        </thead>
                                    </table>
                                </div>
                                <div class="tc-15-table-fixed-body"
                                     style="min-height: 320px; height: auto; max-height: 480px;">
                                    <table class="tc-15-table-box tc-15-table-rowhover" style="min-width: 100%;">
                                        <colgroup><!----> <!---->
                                            <col style="width: 15%;">
                                            <col style="width: 15%;">
                                            <col style="width: 15%;">
                                            <col style="width: 13%;">
                                            <col style="width: 12%;">
                                            <col style="width: 15%;">
                                            <col style="width: auto;">
                                        </colgroup>
                                        <tbody>
                                        <tr data-tips="">
                                            <td colspan="7" class="text-center">
                                                <div>当前列表为空</div>
                                            </td>
                                        </tr> <!----></tbody>
                                    </table>
                                </div>
                            </div> <!----></div>
                        <div data-role="qc-pagination" class="tc-15-page">
                            <div class="tc-15-page-state"><span class="tc-15-page-text"><!---->
      共<strong> 0 </strong>项
    </span></div> <!----></div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>


<script>window.Promise = undefined;</script>

<script>

    var bizWhitelist = {"fakeUin": {"console": [], "qcbuy": []}}
</script>

<div class="top-alert" id="topAlert" style="z-index: 1100; margin-left: -200px; display: none;"><span id="flashMsg"
                                                                                                      class="top-alert-icon-doing fade-out"
                                                                                                      style="display: none;"></span>
</div>
</body>
</html>
