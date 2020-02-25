<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- saved from url=(0043)https://console.cloud.tencent.com/developer -->
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">

<meta name="viewport"
	content="width=device-width, initial-scale=1.0, maximum-scale=2">
<meta name="format-detection" content="telephone=no">
<title>账号信息</title>
<script src="./js/jquery-3.3.1.js"></script>
<script src="./js/base.js"></script>
<script type="text/javascript">
        var speedMark = _speedMark = new Date();
        window._enableReport = true;
        window.serverTimeForPlatformUsageOnly = (function (s, c) {
            return function () {
                return +new Date() + s - c;
            }
        })(1563025308256, +new Date());
        window.lifeId = "SJlNiyPwbB";
        window.lifeStart = serverTimeForPlatformUsageOnly();
        window.LOGIN_INFO = {
            "loginUin": 100000619591,
            "ownerUin": 100000619591,
            "appId": 1257362351,
            "identity": {"subjectType": 0, "authType": 4, "authArea": 0},
            "area": 1,
            "countryName": "CN",
            "countryCode": "86"
        };
    </script>
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
                url : "http://localhost:8080/FileManage/api/getuserinfo?",
                dataType : "json",
                data : {
                    loginid: loginid,
                    token: sessionStorage.getItem("token")},
                async : false,
                success:function(result){
                    
                    $.each(result.data.list,function(i,val){
                        var list="<li class=\"J-qcTopNavSearchItem menu-search-select\"><a href=\"#\" data-event=\"nav\">"+val["title"]+"</a></li>";
                        $("#productService > div > div.menu-list-search.J-headerProductSearchBar > ul").append(list);
                    })
                },
                error: function (result) {
                    console.log("error: " + JSON.stringify(result));
                }
            });
        }
    </script>
<link href="./css/global-201905061503.css" rel="stylesheet"
	data-role="global">
<link href="./css/bee.css" rel="stylesheet" data-role="global">
<link href="./css/break.css" rel="stylesheet" data-role="global">
<link href="./css/monitor-sdk.css" rel="stylesheet" data-role="global">
<link href="./css/tea-0.0.7.min.css" rel="stylesheet" data-role="global">

<link href="./images/favicon.png" rel="icon" type="image/x-icon">
<style>
.onfocus-item {
	border: 1px solid #a5c7fe !important;
}

.container {
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

<style type="text/css">
@
keyframes fade-in { 0% {
	opacity: 0
}

100%
{
}
}
@
-webkit-keyframes fade-in { 0% {
	opacity: 0
}

100%
{
}
}
@
keyframes fade-out { 0% {
	
}

100%
{
opacity
:
 
0
}
}
@
-webkit-keyframes fade-out { 0% {
	
}

100%
{
opacity
:
 
0
}
}
@
keyframes modal-in { 0% {
	opacity: 0;
	transform: scale(0.8, 0.8);
	-moz-transform: scale(0.8, 0.8);
	-webkit-transform: scale(0.8, 0.8);
	-ms-transform: scale(0.8, 0.8);
}

100%
{
}
}
@
-webkit-keyframes modal-in { 0% {
	opacity: 0;
	transform: scale(0.8, 0.8);
	-moz-transform: scale(0.8, 0.8);
	-webkit-transform: scale(0.8, 0.8);
	-ms-transform: scale(0.8, 0.8);
}

100%
{
}
}
@
keyframes modal-out { 0% {
	
}

100%
{
transform
:
 
scale
(0
.8
,
0
.8
);

            
-moz-transform
:
 
scale
(0
.8
,
0
.8
);

            
-webkit-transform
:
 
scale
(0
.8
,
0
.8
);

            
-ms-transform
:
 
scale
(0
.8
,
0
.8
);

            
opacity
:
 
0
}
}
@
-webkit-keyframes modal-out { 0% {
	
}

100%
{
transform
:
 
scale
(0
.8
,
0
.8
);

            
-moz-transform
:
 
scale
(0
.8
,
0
.8
);

            
-webkit-transform
:
 
scale
(0
.8
,
0
.8
);

            
-ms-transform
:
 
scale
(0
.8
,
0
.8
);

            
opacity
:
 
0
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
}
</style>
<link charset="utf-8" rel="stylesheet" href="./css/cvm.css"
	class="cvm-css" disabled="">
<link charset="utf-8" rel="stylesheet" href="./css/firewall.css"
	class="cvm-css" disabled="">
<link charset="utf-8" rel="stylesheet" href="./css/cdh.css"
	class="cvm-css" disabled="">
<style id="dynamic-inserted-css-batch-operation-dialog">
.tc-15-batch-operation-dialog {
	font-size: 14px
}

.tc-15-batch-operation-dialog .delete-text {
	margin-top: 20px
}

.tc-15-batch-operation-dialog .delete-text p {
	font-weight: 700;
	margin-bottom: 4px
}

.tc-15-batch-operation-dialog .selection-list {
	margin-top: 10px;
	font-size: 14px;
	max-height: 130px;
	overflow-y: auto;
	border: 1px solid #dadde0
}

.tc-15-batch-operation-dialog .selection-list li {
	padding-left: 0;
	line-height: 32px;
	height: 32px;
	border-bottom: 1px solid #dadde0
}

.tc-15-batch-operation-dialog .selection-list li:last-child {
	border-bottom: 0
}

.tc-15-batch-operation-dialog .selection-list .number-text {
	color: #ed711f
}

.tc-15-batch-operation-dialog .selection-list .detail-msg {
	float: right;
	color: #ed711f;
	margin-right: 30px
}

.tc-15-batch-operation-dialog .selection-list .detail-msg i {
	vertical-align: text-bottom;
	margin-right: 8px
}

.tc-15-batch-operation-dialog .selection-list .selection-name {
	width: 270px;
	overflow: hidden;
	text-overflow: ellipsis;
	float: left
}

.tc-15-batch-operation-dialog .selection-list .order-number {
	width: 34px;
	overflow: hidden;
	text-align: center;
	float: left;
	border-right: 1px solid #dadde0;
	margin-right: 20px
}

.tc-15-batch-operation-dialog .fail-list {
	max-height: 130px
}
</style>
<style id="dynamic-inserted-css-tea-china-map">
.tea-china-map .province {
	transition: fill .3s ease;
}

.tea-china-map .province:hover {
	fill: yellow;
}
</style>
<style id="dynamic-inserted-css-RangeSlider">
.shop-ui-progress, .btn-drag, .shop-input-num .num {
	-webkit-user-select: none;
	-moz-user-select: none;
	-ms-user-select: none;
	user-select: none;
}

.shop-ui-progress .progress-area {
	height: 35px
}

.shop-ui-progress .progress-area .progress-bar {
	width: 600px;
	height: 15px;
	float: left;
	margin-right: 10px;
	padding-top: 10px;
	cursor: pointer;
	margin-top: 5px
}

.shop-ui-progress .progress-area .progress-bar .progress-bg {
	background: #ebeef5;
	width: 100%;
	height: 5px;
	position: relative;
	z-index: 5;
	border-radius: 4px
}

.shop-ui-progress .progress-area .progress-bar .progress-in {
	position: absolute;
	top: 0;
	left: 0;
	height: 5px;
	background: #2277da;
	border-radius: 4px
}

.shop-ui-progress .progress-area .progress-bar .btn-drag {
	position: absolute;
	width: 19px;
	height: 35px;
	background-image:
		url(//imgcache.qq.com/open_proj/proj_qcloud_v2/gateway/shopcart/css/sprite/shopcart-201611100942.png);
	top: -15px;
	margin-left: -3px;
	background-position: -274px -37px
}

.shop-ui-progress .progress-area .progress-bar .btn-drag:hover {
	background-image:
		url(//imgcache.qq.com/open_proj/proj_qcloud_v2/gateway/shopcart/css/sprite/shopcart-201611100942.png);
	background-position: -274px 0px
}

.shop-ui-progress .progress-area .progress-bar .scale {
	position: relative;
	width: 100%
}

.shop-ui-progress .progress-area .progress-bar .scale .scale-dot {
	position: absolute;
	height: 8px;
	width: 0;
	border-right: 1px solid #b4b7be;
	top: 0
}

.shop-ui-progress .progress-area .progress-bar .scale .dot-pass {
	border-right: 1px solid #72ade8
}

.shop-ui-progress .progress-area .input-area {
	color: #404a58
}

.shop-ui-progress .progress-area .input-area input {
	color: #2a87e4;
	font-weight: 700;
	width: 80px
}

.shop-ui-progress .text-area {
	color: #999;
	position: relative;
	top: 0;
	float: left;
	width: 100%
}

.shop-ui-progress .text-area .text {
	color: #999 !important;
	position: relative;
	top: 0;
	float: left;
	font-size: 12px;
}

.shop-ui-progress .text-area .text {
	position: absolute;
}

.shop-ui-progress .progress-area .shop-input-num-inner {
	margin-left: 10px;
}
</style>
<style type="text/css">
.qdp-container {
	position: absolute;
	width: 211px;
	min-height: 183px;
	font-size: 12px;
	font-family: Tahoma;
	border: 1px solid #D1D1D1;
	padding: 1px;
	z-index: 9999;
	user-select: none;
	-webkit-user-select: none;
	background: #fff;
}

.qdp-container ul, .qdp-container li {
	list-style: none;
	padding: 0px;
	margin: 0px;
}

.qdp-arrow {
	position: absolute;
	display: block;
	width: 0;
	height: 0;
	border-color: transparent;
	border-style: solid;
	border-width: 11px;
	left: 50%;
	margin-left: -11px;
	border-top-width: 0;
	border-bottom-color: #D1D1D1;
	top: -12px
}

.qdp-bar {
	height: 20px;
	background: #f7f7f7;
	color: #404a58;
	font-weight: bold;
	width: 201px;
	position: relative;
	padding: 10px 5px;
}

.qdp-bar select {
	width: 72px;
	margin: 0px 5px;
	height: 18px;
	vertical-align: middle;
	outline: none;
}

.qdp-prev, .qdp-next {
	display: block;
	cursor: pointer;
	margin: 1px;
	color: #ababab;
	font-family: Menlo, "Courier New", Courier, monospace;
}

.qdp-prev {
	float: left;
}

.qdp-next {
	float: right;
}

.qdp-bar ul {
	position: absolute;
}

.qdp-year {
	margin-left: 24px;
	position: relative;
	top: 1px;
}

.qdp-days {
	margin-top: 6px;
	color: #91959c;
}

.qdp-days li {
	float: left;
	height: 22px;
	width: 30px;
	text-align: center;
	font-weight: bold;
	margin-top: 6px;
}

.qdp-dates {
	clear: both;
}

.qdp-dates li {
	float: left;
	width: 19px;
	height: 18px;
	padding: 1px;
	margin: 3px;
	text-align: center;
	line-height: 19px;
	padding-right: 2px;
}

.qdp-date-item {
	border: 1px solid #fff;
	cursor: pointer;
	color: #171d25;
}

.qdp-empty {
	border: 1px solid #fff;
}

.qdp-date-item:hover {
	background: #f7f7f7;
	color: #171d25;
}

.qdp-disable {
	border: 1px solid #fff;
	cursor: not-allowed;
	color: #a2a2a2;
}

.qdp-today {
	border: 1px solid #0071ce;
	color: #0071ce;
}

.qdp-selected, .qdp-selected:hover {
	border: 1px solid #0071ce;
	background: #0071ce;
	color: #fff;
}
</style>
<link charset="utf-8" rel="stylesheet" href="./css/account-center.css"
	class="developer-css developer_index-css">
<link charset="utf-8" rel="stylesheet"
	href="./css/global-mobile.import.css"
	class="developer-css developer_index-css">
<link charset="utf-8" rel="stylesheet" href="./css/auth.css"
	class="developer_index-css">
</head>
<body style="">


	<div id="pageWrapper">
		<div class="qc-header-nav" id="topnav">
			<div class="qc-header-inner">
				<div class="qc-header-unit qc-header-logo">
					<div class="qc-nav-logo">
						<a target="_blank" class="qc-logo-inner"
							href="http://localhost:8080/FileManage" title="返回首页"
							data-hot="header.qcloudid" data-event="hot_tag_link"> <span
							class="qc-logo-icon">腾讯云</span>
						</a>
					</div>
					<div class="qc-nav-mobile-user" data-event="top_user_mobile">
						<a class="qc-mobile-user-inner" href="javascript:void(0);"
							data-hot="m.header.user"> <i></i>
						</a>
					</div>
					<div class="qc-nav-mobile-menu" data-event="top_submenu_mobile"
						data-hot="m.header.product">
						<div class="qc-mobile-menu-inner">
							<span></span>
						</div>
					</div>
				</div>

				<div class="qc-nav-service" data-event="top_submenu"
					data-menu-type="product" data-menu-inited="true" id="J-top_submenu">
					<div class="qc-service-inner">
						<div class="qc-service-tool">
							<span style="cursor:default" class="qc-service-text"
								id="t_product">系统功能</span> <i class="qc-nav-arrows" style=""></i>
						</div>
						<div class="qc-service-menu" id="productService"
							style="height: 800px;">
							<div class="qc-service-menu-inner">
								<i class="qc-service-icon J-headerProductClose"
									id="J-headerProductClose"></i>
								<div class="menu-list-search J-headerProductSearchBar">
									<div class="menu-search-tool">
										<input type="text"
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
											<div id="product_list_title_0" class="menu-area-tit">
												<em>Group 1</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_0" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_1"
															data-event="nav" title="基础数据维护"
															data-hot="header.navigation.internal.cvm"><span
															class="menu-item-text">基础数据维护</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_1" class="menu-area-tit">
												<em>Group 6</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_1" tabindex="0"
												role="list">
												<div class="menu-item" data-nav="nav_CMQ_WHITELIST" style="">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_6"
															data-event="nav" title="实验方案处理"
															data-hot="header.navigation.internal.mq"><span
															class="menu-item-text">实验方案处理</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_11" class="menu-area-tit">
												<em>Group 11</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_1" tabindex="0"
												role="list">
												<div class="menu-item" data-nav="nav_CMQ_WHITELIST" style="">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_01"
															data-event="nav" title="核算管理"
															data-hot="header.navigation.internal.mq"><span
															class="menu-item-text">核算管理</span></a>
													</div>
												</div>
											</div>
										</div>
									</div>
									<div class="menu-list-col">
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_6" class="menu-area-tit">
												<em>Group 2</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_6" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_02"
															data-event="nav" title="编码体系管理"
															data-hot="header.navigation.internal.cos"><span
															class="menu-item-text">编码体系管理</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_7" class="menu-area-tit">
												<em>Group 7</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_7" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/cvm"
															data-event="nav" title="实验动物档案管理"
															data-hot="header.navigation.internal.cdb"><span
															class="menu-item-text">实验动物档案管理</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_12" class="menu-area-tit">
												<em>Group 12</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_7" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_10"
															data-event="nav" title="猪场环境管理"
															data-hot="header.navigation.internal.cdb"><span
															class="menu-item-text">猪场环境管理</span></a>
													</div>
												</div>
											</div>
										</div>
									</div>
									<div class="menu-list-col">
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_3" class="menu-area-tit">
												<em>Group 3</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_12" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_1"
															data-event="nav" title="用户管理"
															data-hot="header.navigation.internal.clb"><span
															class="menu-item-text">用户管理</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_13" class="menu-area-tit">
												<em>Group 8</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_13" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_6"
															data-event="nav" title="仪器设备管理"
															data-hot="header.navigation.internal.cdn"><span
															class="menu-item-text">仪器设备管理</span></a>
													</div>
												</div>
											</div>
										</div>
									</div>
									<div class="menu-list-col">
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_22" class="menu-area-tit">
												<em>Group 4</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_22" tabindex="0"
												role="list">
												<div class="menu-item"
													data-nav="nav_ai_image_face_recognition" style="">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_2"
															data-event="nav" title="试剂药品耗材管理"
															data-hot="header.navigation.internal.aiface"><span
															class="menu-item-text">试剂药品耗材管理</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_23" class="menu-area-tit">
												<em>Group 9</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_23" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_7"
															data-event="nav" title="质量管控"
															data-hot="header.navigation.internal.ai"><span
															class="menu-item-text">质量管控</span></a>
													</div>
												</div>
											</div>
										</div>
									</div>
									<div class="menu-list-col">
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_32" class="menu-area-tit">
												<em>Group 5</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_32" tabindex="0"
												role="list">
												<div class="menu-item">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_3"
															data-event="nav" title="动物转平台出设施"
															data-hot="header.navigation.internal.mgobe"><span
															class="menu-item-text">动物转平台出设施</span></a>
													</div>
												</div>
											</div>
										</div>
										<div class="menu-area J-headerProductGroup">
											<div id="product_list_title_33" class="menu-area-tit">
												<em>Group 10</em>
											</div>
											<div class="menu-area-con"
												aria-labelledby="product_list_title_33" tabindex="0"
												role="list">
												<div class="menu-item" data-nav="nav_qcloudpay_whitelist"
													style="">
													<div class="menu-item-tit">
														<a href="http://localhost:8080/FileManage/homepage_8"
															data-event="nav" title="核算管理"
															data-hot="header.navigation.internal.cpay"><span
															class="menu-item-text">核算管理</span></a>
													</div>
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
					<div class="qc-nav-user" data-event="top_submenu"
						data-menu-type="user" id="userInfo" data-menu-inited="true">
						<div class="qc-user-inner">
							<i class="qc-user-icon"></i><span class="qc-user-name"
								data-hot="header.user.center" title="g7">g7</span><i
								class="qc-nav-arrows"></i>
							<div class="qc-user-info qc-user-panel">
								<div class="qc-user-panel-inner J-dropdownPanel">
									<a href="http://localhost:8080/FileManage/developer"
										data-event="nav" data-hot="header.user.developer">账号信息</a> <a
										href="http://localhost:8080/FileManage/security"
										data-event="nav" data-hot="header.user.security">安全设置</a> <a
										href="http://localhost:8080/FileManage/overview"
										data-event="nav" data-hot="header.user.permission">访问管理</a> <a
										href="http://localhost:8080/FileManage/project" style=""
										data-auth="project" data-event="nav"
										data-hot="header.user.project">项目管理</a> <a
										href="http://localhost:8080/FileManage/partners"
										style="display:none" data-auth="returnAmount" data-event="nav"
										data-hot="header.user.agent">渠道管理</a> <span
										class="qc-user-info-line"></span> <a href="javascript:void(0)"
										style="display: none;" data-event="changeAccount">切换用户身份</a> <a
										href="javascript:void(0)" data-event="logout">退出</a>
								</div>
							</div>
						</div>
					</div>
					<!--user end-->
				</div>

				<div class="qc-header-unit  qc-header-account">
					<!--account start-->
					<div class="qc-nav-account" data-event="top_submenu"
						data-menu-type="cost" data-menu-inited="true">
						<!--mobile account start-->
						<div class="qc-nav-mobile-account">
							<a href="http://localhost:8080/FileManage/account"
								data-event="nav" class="J-feeLink">费用</a>
						</div>

						<div class="qc-account-inner">
							<a href="http://localhost:8080/FileManage/account"
								data-event="nav" data-hot="header.fee.center"
								class="qc-account-text J-feeLink" id="t_cost">费用</a><i
								class="qc-nav-arrows" style=""></i>
							<div class="qc-account-info qc-user-panel">
								<div class="qc-user-panel-inner J-dropdownPanel">
									<div class="qc-user-balance">
										<span> 账户余额 <span
											class="unauth tc-15-bubble-icon tc-15-triangle-align-start"
											style="display: none;"> <i class="plaint-icon"></i>
												<div class="tc-15-bubble tc-15-bubble-top">
													<div class="tc-15-bubble-inner">您暂无财务权限，请联系开发商负责人或有财务权限的协作者了解账户余额</div>
												</div>
										</span>
										</span> <span class="J-costRecharge"><a
											href="http://localhost:8080/FileManage/account/recharge"
											style="" data-event="nav" data-auth="account"
											data-hot="header.user.rechage">立即充值</a></span>
										<div class="qc-balance-num">
											<span data-field="balance" data-event="nav" href="/account">0.00</span>
											<strong class="currency-unit">元</strong>
										</div>
									</div>
									<ul class="qc-user-voucher">
										<li><a
											href="http://localhost:8080/FileManage/account/voucher"
											data-event="nav" data-field="voucher"
											data-hot="header.user.voucher">代金券</a></li>
										<li><a
											href="http://localhost:8080/FileManage/account/renewal"
											data-event="nav" data-field="renewal"
											data-hot="header.user.renewal">续费</a></li>
										<li><a
											href="http://localhost:8080/FileManage/account/invoice"
											data-event="nav" data-field="invoice"
											data-hot="header.user.invoice" data-auth="checkPassState">发票</a></li>
									</ul>
									<div class="qc-user-list">
										<a href="http://localhost:8080/FileManage/deal"
											data-field="deal" data-event="nav"
											data-hot="header.user.deal">我的订单</a> <a style=""
											data-auth="account"
											href="http://localhost:8080/FileManage/account/fee"
											data-event="nav" data-hot="header.user.account">收支明细</a> <a
											style="" data-auth="account"
											href="http://localhost:8080/FileManage/expense/bill/overview"
											data-event="nav" data-hot="header.user.account">资源账单</a> <a
											style="" data-field="contract" data-auth="account"
											href="http://localhost:8080/FileManage/account/contract"
											data-event="nav" data-hot="header.user.account.contract">合同管理</a>
									</div>
									<div class="qc-account-center">
										<a style="" data-auth="account"
											href="http://localhost:8080/FileManage/account"
											data-event="nav" data-hot="header.user.account">费用中心</a>
									</div>
								</div>
							</div>
						</div>
					</div>
					<!--account end-->

					<!--workorder start-->
					<div class="qc-nav-workorder" data-event="nav-workorder">
						<a href="http://localhost:8080/FileManage/workorder"
							data-event="nav" class="qc-workorder-inner"
							data-hot="header.workorder"> <span class="qc-workorder-text"
							id="t_workorder">工单</span>
						</a>
					</div>
					<!--workorder end-->
				</div>
				<div class="qc-header-unit  qc-header-tool">
					<!--message start-->
					<div class="qc-nav-message" data-event="top_submenu"
						id="message_trigger" data-menu-inited="true">
						<!--mobile message start-->
						<div class="qc-nav-mobile-message">
							<a href="https://console.cloud.tencent.com/message"
								data-event="nav" data-hot="m.header.message" class="J-msgLink">消息中心</a>
						</div>
						<!--mobile message- end-->
						<div class="qc-message-inner">
							<i class="qc-message-icon J-headerMsgIcon"><em
								style="visibility: hidden">0</em></i>
							<div class="qc-tool-message qc-tool-panel J-dropdownPanel"
								style="height: 750px;">
								<div class="qc-tool-inner" id="thisIsMsgCenter">
									<div class="qc-tool-head J-message-head">
										<h3 class="qc-tool-head-title">消息中心</h3>
										<a class="qc-tool-more"
											href="https://console.cloud.tencent.com/message"
											data-event="nav" data-hot="header.message.more">查看更多</a><a
											class="qc-tool-head-close J-closeMsgIcon"><i
											class="qc-close-panel"></i></a>
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
					<div class="qc-nav-log" data-event="top_submenu"
						id="operatelog_trigger" data-menu-inited="true">
						<!--mobile log start-->
						<div class="qc-nav-mobile-log">
							<a href="https://console.cloud.tencent.com/operatelog"
								data-event="nav" data-hot="m.header.operatelog">操作日志</a>
						</div>
						<!--mobile log end-->
						<div class="qc-log-inner">
							<i class="qc-log-icon J-headerLogIcon"></i>
							<div class="qc-tool-log qc-tool-panel J-dropdownPanel"
								style="height: 750px;">
								<div class="qc-tool-inner">
									<div class="qc-tool-head J-tool-head">
										<h3 class="qc-tool-head-title">最近操作</h3>
										<a class="qc-tool-more"
											href="https://console.cloud.tencent.com/cloudaudit"
											data-event="nav" data-hot="header.operatelog.more">查看更多</a><a
											class="qc-tool-head-close J-closeLogIcon" href="javascript:;"><i
											class="qc-close-panel"></i></a>
									</div>
									<div class="qc-tool-body J-operatelogList"
										style="height: 699px;">
										<div class="qc-tool-info">暂无操作日志</div>
									</div>
								</div>
							</div>
						</div>
						<div class="tip-msg-win floattips-container"></div>
					</div>
					<!--log end-->

					<!--help start-->
					<div class="qc-nav-help" data-event="top_submenu" id="help_trigger"
						data-menu-type="help" data-menu-inited="true">
						<!--mobile help start-->
						<div class="qc-nav-mobile-help">
							<a href="http://localhost:8080/FileManage/document/product"
								data-hot="m.header.document" target="_blank">帮助与文档<i
								class="menu-external-link"></i></a>
						</div>
						<!--mobile help end-->
						<div class="qc-help-inner">
							<i class="qc-help-icon J-headerHelpIcon"></i>
							<div class="qc-tool-help qc-tool-panel J-dropdownPanel"
								style="height: 750px;">
								<div class="qc-tool-inner J-headerHelpWrapper">
									<div class="qc-tool-head J-helper-head">
										<h3 class="qc-tool-head-title">帮助中心</h3>
										<a class="qc-tool-head-close J-close-help-icon"
											href="javascript:;"><i class="qc-close-panel"></i></a>
									</div>
									<div class="qc-tool-body J-helper-body" style="height: 729px;">
										<div class="qc-help-search-box">
											<input type="text" id="input_search_cont_help"
												class="qc-help-search-cont" placeholder="请输入您想了解或感兴趣的问题">
											<button type="button" class="qc-help-search-btn"></button>
										</div>
										<div class="qc-question-list-wrap J-question-list">
											<dl class="qc-question-list">
												<dt>您可能需要</dt>
												<dd>
													<a class="external-link-help" data-type="2" target="_blank"
														href="#">常见操作指南</a>
												</dd>
												<dd>
													<a class="external-link-help" data-type="2" target="_blank"
														href="#">登陆注册指引</a>
												</dd>
												<dd>
													<a class="external-link-help" data-type="2" target="_blank"
														href="#">产品文档</a>
												</dd>
												<dd>
													<a class="external-link-help" data-type="2" target="_blank"
														href="#">API文档</a>
												</dd>
											</dl>
										</div>
										<!-- <div class="qc-doc-video">      <ul class="J-video-list">          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80" data-video="//imgcache.qq.com/open_proj/proj_qcloud_v2/gateway/product/ugsv/css/img/demo/demo-1.mp4">                  <div class="qc-doc-video-title">云服务器配置介绍云服务器配置介绍</div>              </a>          </li>          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80">                  <div class="qc-doc-video-title">云服务器配置介绍</div>              </a>          </li>          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80">                  <div class="qc-doc-video-title">云服务器配置介绍</div>              </a>          </li>          <li class="J-video-item">              <a class="qc-doc-video-box" href="https://www.qcloud.com/document/product" target="_blank">                  <img class="qc-doc-video-img" src="https://ask.qcloudimg.com/raw/qctrain/yehe-1932762cc356320/9xg6x4ak38.jpg?imageView2/format/jpg/q/80">                  <div class="qc-doc-video-title">云服务器配置介绍</div>              </a>          </li>      </ul>      <a href="javascript:;" class="qc-doc-video-more">更多视频</a>  </div> -->
									</div>
									<div class="qc-tool-foot qc-doc-video-foot J-helper-footer">
										<a class="qc-help-service" target="_blank"
											href="http://localhost:8080/FileManage/marty?from=helpcenter"><i></i>智能客服</a>
									</div>
								</div>
							</div>
						</div>
					</div>
					<!--help end-->
				</div>
			</div>
		</div>
		<div class="container container-developer" id="container"
			style="left: 0px;">
			<div class="aside qc-aside-new" id="sidebar">
				<div class="qc-aside-area">
					<div class="qc-aside-area-main">
						<h2 class="qc-aside-headline">
							<img class="qc-aside-service-icon" src="./images/user.svg"><span>账号中心</span>
						</h2>
						<ul class="qc-aside-list def-scroll keyboard-focus-obj">
							<li><a class="qc-aside-level-1 qc-aside-select"
								data-event="nav"
								href="https://console.cloud.tencent.com/developer"
								target="_self"><img class="qc-aside-icon"
									src="./images/developer.svg"><img
									class="qc-aside-icon qc-aside-icon-select"
									src="./images/developer(1).svg"><span>账号信息</span></a></li>
							<li><a class="qc-aside-level-1" data-event="nav"
								href="https://console.cloud.tencent.com/developer/security"
								target="_self"><img class="qc-aside-icon"
									src="./images/security.svg"><img
									class="qc-aside-icon qc-aside-icon-select"
									src="./images/security(1).svg"><span>安全设置</span></a></li>
							<li><a class="qc-aside-level-1" data-event="nav"
								href="https://console.cloud.tencent.com/project" target="_self"><img
									class="qc-aside-icon" src="./images/project.svg"><img
									class="qc-aside-icon qc-aside-icon-select"
									src="./images/project(1).svg"><span>项目管理</span></a></li>
							<li data-nav="nav_CLOUD_OPEN_AUTH" style="display:none"><a
								class="qc-aside-level-1" data-event="nav"
								href="https://console.cloud.tencent.com/grant" target="_self"><img
									class="qc-aside-icon" src="./images/grant.svg"><img
									class="qc-aside-icon qc-aside-icon-select"
									src="./images/grant(1).svg"><span>应用服务授权</span></a></li>
							<li><a class="qc-aside-level-1"
								href="https://console.cloud.tencent.com/cam/overview"
								target="_blank"><img class="qc-aside-icon"
									src="./images/cam.svg"><img
									class="qc-aside-icon qc-aside-icon-select"
									src="./images/cam(1).svg"><span>访问管理<em
										class="qc-menu-link"></em></span></a></li>
						</ul>
					</div>
				</div>
				<div class="qc-menu-fold" data-event="toggle_sidebar"
					data-hot="sidebar.toggle.new">
					<i></i>
				</div>
				<div
					class="tc-15-bubble tc-15-bubble-bottom qc-menu-tip J-newSidebarToggleTip"
					style="display: none">
					<div class="tc-15-bubble-inner">
						点击收起侧导航<a href="javascript:;" data-event="hideNewSidebarToggleTip"
							class="qc-menu-tip-close"></a>
					</div>
				</div>
			</div>
			<div class="main" id="appArea">
				<div id="developer-index" class="tea-page-root">
					<div class="manage-area auth-info-page">
						<div class="manage-area-title">
							<h2>账号信息</h2>
						</div>
						<div class="manage-area-main">
							<div class="manage-area-main-inner">
								<div class="tc-g panelgroup">
									<div class="tc-g-u-1-1">
										<div class="tc-panel">
											<div class="tc-panel-hd">
												<div class="col">
													<h3 class="title">基本信息</h3>
												</div>
												<div class="col">
													<a href="javascript:;" target="_self" class="tc-link-btn">帮助指引</a>
												</div>
											</div>
											<div class="tc-panel-bd">
												<div class="tc-g with-divider">
													<div class="tc-g-u-1-3 border-right">
														<div class="param-box ">
															<div class="param-bd">
																<ul class="form-list">
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>账号昵称</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					Galaxy<a href="javascript:;" class="ml-5"><i
																						class="pencil-icon"></i></a>
																				</div>
																				<input class="tea-input" value="Galaxy"
																					style="display: none; width: 128px;"><a
																					href="javascript:;" class="tc-link-btn"
																					style="display: none;">保存</a><a href="javascript:;"
																					class="tc-link-btn" style="display: none;">取消</a>
																				<p class="form-input-help" style="display: none;"></p>
																			</div>
																		</div>
																	</li>
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>账号ID</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">100000619591</div>
																			</div>
																		</div>
																	</li>
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>APPID</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">1257362351</div>
																			</div>
																		</div>
																	</li>
																</ul>
															</div>
														</div>
													</div>
													<div class="tc-g-u-2-3 matchheight">
														<div class="param-box ">
															<div class="param-bd">
																<ul class="form-list">
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>认证状态</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					<span class="text-success">已认证</span><a
																						href="javascript:;" class="tc-link-btn">查看或修改认证</a>
																				</div>
																			</div>
																		</div>
																	</li>
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>所属行业</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					<span>其他 - 其他</span><a href="javascript:;"
																						class="ml-5"><i class="pencil-icon"></i></a>
																					<p class="form-input-help" style="display: none;"></p>
																				</div>
																			</div>
																		</div>
																	</li>
																</ul>
															</div>
														</div>
													</div>
												</div>
											</div>
										</div>
									</div>
								</div>
								<div class="tc-g panelgroup">
									<div class="tc-g-u-2-3">
										<div class="tc-panel">
											<div class="tc-panel-hd">
												<div class="col">
													<h3 class="title">登录方式</h3>
												</div>
												<div class="col">
													<a href="javascript:;" target="_self" class="tc-link-btn">帮助指引</a>
												</div>
											</div>
											<div class="tc-panel-bd">
												<p class="text-label mb-20">账号支持多种登录方式，便捷管理云账号</p>
												<div class="tc-g with-divider">
													<div class="tc-g-u-1-2">
														<div class="param-box qq-box">
															<div class="param-bd">
																<ul class="form-list">
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>微信(注册方式)</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					<span>Galaxy</span>
																				</div>
																			</div>
																		</div>
																	</li>
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>QQ</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					无<a href="javascript:;" class="tc-link-btn">绑定</a>
																				</div>
																			</div>
																		</div>
																	</li>
																</ul>
															</div>
														</div>
													</div>
													<div class="tc-g-u-1-2">
														<div class="param-box ">
															<div class="param-bd">
																<ul class="form-list">
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>邮箱</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					无<a href="javascript:;" class="tc-link-btn">绑定</a>
																				</div>
																			</div>
																		</div>
																	</li>
																	<li class="pure-text-row pure-text-row">
																		<div class="form-label">
																			<label>微信公众平台</label>
																		</div>
																		<div class="form-input">
																			<div class="form-unit">
																				<div class="form-text">
																					无<a href="javascript:;" class="tc-link-btn">绑定</a>
																				</div>
																			</div>
																		</div>
																	</li>
																</ul>
															</div>
														</div>
													</div>
												</div>
											</div>
										</div>
									</div>
									<div class="tc-g-u-1-3">
										<div class="tc-panel">
											<div class="tc-panel-hd">
												<div class="col">
													<h3 class="title">账号权限</h3>
												</div>
											</div>
											<div class="tc-panel-bd">
												<p class="text-label mb-20">帮助用户管理账号的访问权限，资源管理和使用权限</p>
												<div class="param-box ">
													<div class="param-bd">
														<ul class="form-list">
															<li class="pure-text-row pure-text-row">
																<div class="form-label">
																	<label>账号身份</label>
																</div>
																<div class="form-input">
																	<div class="form-unit">
																		<div class="form-text">主账号</div>
																	</div>
																</div>
															</li>
															<li class="pure-text-row pure-text-row">
																<div class="form-label">
																	<label>账号权限</label>
																</div>
																<div class="form-input">
																	<div class="form-unit">
																		<div class="form-text">
																			腾讯云所有权限<a
																				href="https://console.cloud.tencent.com/cam/overview"
																				class="tc-link-btn" target="_blank">权限设置</a>
																		</div>
																	</div>
																</div>
															</li>
														</ul>
													</div>
												</div>
											</div>
										</div>
									</div>
								</div>
								<div class="tc-g panelgroup">
									<div class="tc-g-u-1-3">
										<div class="tc-panel">
											<div class="tc-panel-hd">
												<div class="col">
													<h3 class="title">服务商</h3>
												</div>
											</div>
											<div class="tc-panel-bd">
												<li class="pure-text-row pure-text-row">
													<div class="form-label">
														<label>我的服务商</label>
													</div>
													<div class="form-input">
														<div class="form-unit">
															<div class="form-text">
																<a data-event="nav"
																	href="https://console.cloud.tencent.com/mypartner/info"
																	class="tc-link-btn">进入</a>
															</div>
														</div>
													</div>
												</li>
											</div>
										</div>
									</div>
								</div>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>

</body>
</html>