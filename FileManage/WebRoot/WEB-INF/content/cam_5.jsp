<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- saved from url=(0043)http://localhost:8080/FileManage/developer -->
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">

    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=2">
    <meta name="format-detection" content="telephone=no">
    <title>查询系统-绘制曲线图</title>
    <script src="./js/jquery-3.3.1.js"></script>
    <script src="./js/base.js"></script>
    <link href="./css/global-201905061503.css" rel="stylesheet" data-role="global">
    <link href="./css/bee.css" rel="stylesheet" data-role="global">
    <link href="./css/break.css" rel="stylesheet" data-role="global">
    <link href="./css/monitor-sdk.css" rel="stylesheet" data-role="global">
    <link href="./css/tea-0.0.7.min.css" rel="stylesheet" data-role="global">
    <link href="./images/favicon.png" rel="icon" type="image/x-icon">
    <link charset="utf-8" rel="stylesheet" href="./css/account-center.css"
          class="developer-css developer_index-css">
    <link charset="utf-8" rel="stylesheet" href="./css/global-mobile.import.css"
          class="developer-css developer_index-css">
    <link charset="utf-8" rel="stylesheet" href="./css/work-order.css" class="workorder-css">
    <style type="text/css">@keyframes fade-in {
                               0% {
                                   opacity: 0
                               }
                               100% {
                               }
                           }

    .error-page h2 {
        font-size: 40px;
        font-weight: bold
    }</style>

    <style type="text/css">
        .form-text > em {
            font-size: 12px;
            color: #888;
            margin-left: 5px;
        }
    </style>
    <link charset="utf-8" rel="stylesheet" href="./css/auth.css" class="developer_index-css">
    <link charset="utf-8" rel="stylesheet" href="./css/resource.css" class="expense-css">
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
                                                                                 title="用户信息"></span><i
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
                                <div class="qc-tool-foot qc-doc-video-foot J-helper-footer"><a class="qc-help-service"
                                                                                               target="_blank"
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
    <div class="qc-animation-empty container container-developer" id="container" style="left: 0px;">
        <div class="aside qc-aside-new" id="sidebar">
            <div class="qc-aside-area">
                <div class="qc-aside-area-main"><h2 class="qc-aside-headline"><img class="qc-aside-service-icon"
                                                                                   src="./images/user.svg"><span>实验动物档案管理</span>
                </h2>
                    <ul class="qc-aside-list def-scroll keyboard-focus-obj">
                        <li tabindex="0" data-nav-dropdown="1" data-nav="nav_serviceMigrate" style=""><a
                                class="qc-aside-level-1" href="javascript:;"
                                data-event="sidebar_accordion"><img
                                class="qc-aside-icon" src="./images/developer.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/developer(1).svg"><span>柜员系统</span><i
                                class="qc-aside-up-icon">开</i></a>
                            <ul class="qc-aside-subitem" id="clerk">
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/developer/cvm"
                                                                              target="_self"><span>接受申请</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/developer/cbs"
                                                                              target="_self"><span>反馈处理</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/developer/cvm"
                                                                              target="_self"><span>实验进程跟踪</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/developer/cvm"
                                                                              target="_self"><span>申请记录统计</span></a>
                                </li>
                            </ul>
                        </li>

                        <li tabindex="0" data-nav-dropdown="1" data-nav="nav_serviceMigrate" style=""><a
                                class="qc-aside-level-1" href="javascript:;" data-event="sidebar_accordion"><img
                                class="qc-aside-icon" src="./images/security.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/security(1).svg"><span>审核系统</span><i
                                class="qc-aside-up-icon">开</i></a>
                            <ul class="qc-aside-subitem" id="audit">
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/security/cvm"
                                                                              target="_self"><span>待审核</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/security/cbs"
                                                                              target="_self"><span>已审核</span></a>
                                </li>
                            </ul>
                        </li>

                        <li tabindex="0" data-nav-dropdown="1" data-nav="nav_serviceMigrate" style=""><a
                                class="qc-aside-level-1" href="javascript:;" data-event="sidebar_accordion"><img
                                class="qc-aside-icon" src="./images/cvm.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/cvm(1).svg"><span>录入系统</span><i
                                class="qc-aside-up-icon">开</i></a>
                            <ul class="qc-aside-subitem" id="insert">
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/csm/cvm"
                                                                              target="_self"><span>转入/转出记录录入</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/csm/cvm"
                                                                              target="_self"><span>实验记录录入</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/csm/cvm"
                                                                              target="_self"><span>手术记录录入</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/csm/cvm"
                                                                              target="_self"><span>检查/讨论记录录入</span></a>
                                </li>
                            </ul>
                        </li>

                        <li tabindex="0" data-nav-dropdown="1" data-nav="nav_serviceMigrate" style=""><a
                                class="qc-aside-level-1" href="javascript:;" data-event="sidebar_accordion"><img
                                class="qc-aside-icon" src="./images/project.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/project(1).svg"><span>档案管理</span><i
                                class="qc-aside-up-icon">开</i></a>
                            <ul class="qc-aside-subitem" id="file">
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/project/cvm"
                                                                              target="_self"><span>修改实验记录</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/project/cbs"
                                                                              target="_self"><span>删除实验记录</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/project/cbs"
                                                                              target="_self"><span>档案打印列表</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/project/cbs"
                                                                              target="_self"><span>纸质档案管理</span></a>
                                </li>
                            </ul>
                        </li>

                        <li tabindex="0" data-nav-dropdown="1" data-nav="nav_serviceMigrate" style=""><a
                                class="qc-aside-level-1 qc-aside-select" href="javascript:;"
                                data-event="sidebar_accordion"><img
                                class="qc-aside-icon" src="./images/cam.svg"><img
                                class="qc-aside-icon qc-aside-icon-select"
                                src="./images/cam(1).svg"><span>查询系统</span><i
                                class="qc-aside-up-icon">开</i></a>
                            <ul class="qc-aside-subitem" id="search" style="display: block;">
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2"
                                                                              data-event="nav"
                                                                              href="http://localhost:8080/FileManage/cam_1"
                                                                              target="_self"><span>显示实验时间轴</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2"
                                                                              data-event="nav"
                                                                              href="http://localhost:8080/FileManage/cam_2"
                                                                              target="_self"><span>显示历次实验信息</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/cam_3"
                                                                              target="_self"><span>查看某次实验信息</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/cam_4"
                                                                              target="_self"><span>显示个体相关信息</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2 qc-aside-select"
                                                                              data-event="nav"
                                                                              href="http://localhost:8080/FileManage/cam_5"
                                                                              target="_self"><span>绘制曲线图</span></a>
                                </li>
                                <li data-nav="nav_serviceMigrate" style=""><a class="qc-aside-level-2" data-event="nav"
                                                                              href="http://localhost:8080/FileManage/cam_6"
                                                                              target="_self"><span>实验记录打印</span></a>
                                </li>
                            </ul>
                        </li>

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
            <div id="developer-index" class="tea-page-root">
                <div class="manage-area auth-info-page">
                    <div class="manage-area-title"><h2>查询系统</h2></div>
                    <div class="manage-area-main">
                        <div class="manage-area-main-inner">
                            <!--body start-->
                            <div class="tc-panel panel-resource-cost">
                                <div class="panel-resource-cost-main">
                                    <div class="tc-panel-hd">
                                        <div class="col"><h3 class="title">费用趋势<em>（单位：元）</em></h3></div>
                                        <div class="col">
                                            <div class="tc-15-rich-radio" role="radiogroup">
                                                <button role="radio" aria-checked="true" class="tc-15-btn m checked">
                                                    近半年
                                                </button>
                                                <button role="radio" aria-checked="true" class="tc-15-btn m">近一年
                                                </button>
                                            </div>
                                            <div class="tc-15-dropdown tc-15-dropdown-btn-style ml-5 tc-15-dropdown-btn-style">
                                                <a href="javascript:" class="tc-15-dropdown-link">总费用<i
                                                        class="caret"></i></a>
                                                <div class="dropdown-list-wrap">
                                                    <ul class="tc-15-dropdown-menu" role="menu">
                                                        <li class="selected"><a role="menuitem" href="#">总费用</a></li>
                                                        <li class=""><a role="menuitem" href="#">现金支付</a></li>
                                                        <li class=""><a role="menuitem" href="#">赠送金支付</a></li>
                                                        <li class=""><a role="menuitem" href="#">代金券支付</a></li>
                                                    </ul>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="tc-panel-hd">
                                        <div style="height: 200px; -webkit-tap-highlight-color: transparent; user-select: none; position: relative;"
                                             _echarts_instance_="ec_1563135616372">
                                            <div style="position: relative; overflow: hidden; width: 909px; height: 200px; padding: 0px; margin: 0px; border-width: 0px; cursor: default;">
                                                <canvas data-zr-dom-id="zr_0" width="1136" height="250"
                                                        style="position: absolute; left: 0px; top: 0px; width: 909px; height: 200px; user-select: none; -webkit-tap-highlight-color: rgba(0, 0, 0, 0); padding: 0px; margin: 0px; border-width: 0px;"></canvas>
                                            </div>
                                            <div style="position: absolute; display: none; border-style: solid; white-space: nowrap; z-index: 9999999; transition: left 0.4s cubic-bezier(0.23, 1, 0.32, 1) 0s, top 0.4s cubic-bezier(0.23, 1, 0.32, 1) 0s; background-color: rgba(50, 50, 50, 0.7); border-width: 0px; border-color: rgb(51, 51, 51); border-radius: 4px; color: rgb(255, 255, 255); font: 14px/21px &quot;Microsoft YaHei&quot;; padding: 5px; left: 179px; top: 102px;">
                                                2018年11月及之前的账单费用请查看资源账单1.0
                                            </div>
                                        </div>
                                        <p class="text mt-5">2018-12 ~ 2019-02 月均总费用 21.33 元</p></div>
                                </div>
                                <div class="panel-resource-cost-aside">
                                    <div class="resource-cost-details mr-10">
                                        <div class="details-title">2019年2月</div>
                                        <div class="details-list">
                                            <div class="details-item">
                                                <div class="details-label">统计周期</div>
                                                <div class="details-con">按扣费周期</div>
                                            </div>
                                            <div class="details-item total">
                                                <div class="details-label">总费用</div>
                                                <div class="details-con"><em>0.00</em>元</div>
                                                <div class="details-slice">=</div>
                                            </div>
                                            <div class="details-item">
                                                <div class="details-label">现金支付</div>
                                                <div class="details-con"><em>0.00</em>元</div>
                                                <div class="details-slice">+</div>
                                            </div>
                                            <div class="details-item">
                                                <div class="details-label">赠送金支付</div>
                                                <div class="details-con"><em>0.00</em>元</div>
                                                <div class="details-slice">+</div>
                                            </div>
                                            <div class="details-item">
                                                <div class="details-label">代金券支付</div>
                                                <div class="details-con"><em>0.00</em>元</div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="arrows"></div>
                                </div>
                            </div>
                            <div class="tc-panel">
                                <div class="tc-panel-hd">
                                    <div class="col"><h3 class="title">2019年2月账单汇总<em>（单位：元）</em></h3></div>
                                    <div class="col"><a href="javascript:void(0);" class="tc-link-btn text"><i
                                            class="download-icon"></i>下载账单汇总</a></div>
                                </div>
                                <div class="tab-full">
                                    <ul role="tablist" class="tablist">
                                        <li class="current"><a href="javascript:;" role="tab">按产品汇总</a></li>
                                        <li class=""><a href="javascript:;" role="tab">按项目（组）汇总</a></li>
                                        <li class=""><a href="javascript:;" role="tab">按地域汇总</a></li>
                                        <li class=""><a href="javascript:;" role="tab">按计费模式汇总</a></li>
                                    </ul>
                                    <div class="tab-panel">
                                        <div class="resource-chart resource-chart-pie">
                                            <div class="resource-chart-hint">
                                                <div class="resource-chart-hint-ctn"><i
                                                        class="resource-chart-hint-icon"></i>
                                                    <p class="resource-chart-hint-info">您本月没有产生费用</p></div>
                                            </div>
                                        </div>
                                        <div class="tc-action-grid mt-20"></div>
                                        <div class="tc-15-table-panel resource-table-collapse">
                                            <div class="tc-15-table-fixed-head">
                                                <table class="tc-15-table-box">
                                                    <colgroup>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                    </colgroup>
                                                    <thead>
                                                    <tr>
                                                        <th>
                                                            <div><span class="text-overflow">产品名称</span></div>
                                                        </th>
                                                        <th class="text-right">
                                                            <div><span class="text-overflow">现金支付</span></div>
                                                        </th>
                                                        <th class="text-right">
                                                            <div><span class="text-overflow">赠送金支付</span></div>
                                                        </th>
                                                        <th class="text-right">
                                                            <div><span class="text-overflow">代金券支付</span></div>
                                                        </th>
                                                        <th colspan="2">
                                                            <div class="align-center"><span
                                                                    class="text-overflow">总费用</span>
                                                                <div class="tc-15-bubble-icon"><i
                                                                        class="tc-icon icon-what"></i>
                                                                    <div class="tc-15-bubble tc-15-bubble-left">
                                                                        <div class="tc-15-bubble-inner"><p>折后总费用</p>
                                                                        </div>
                                                                    </div>
                                                                </div>
                                                            </div>
                                                        </th>
                                                        <th class="text-center">
                                                            <div><span class="text-overflow">费用趋势</span></div>
                                                        </th>
                                                    </tr>
                                                    </thead>
                                                </table>
                                            </div>
                                            <div class="tc-15-table-fixed-body" style="overflow: visible;">
                                                <table class="tc-15-table-box tc-15-table-rowhover">
                                                    <colgroup>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                        <col>
                                                    </colgroup>
                                                    <tbody>
                                                    <tr>
                                                        <td colspan="7">
                                                            <div class="text-center"><span
                                                                    class="text-label">暂无数据</span></div>
                                                        </td>
                                                    </tr>
                                                    </tbody>
                                                </table>
                                            </div>
                                        </div>
                                        <div class="tc-15-page">
                                            <div class="tc-15-page-state"><span
                                                    class="tc-15-page-text"><span>共 0 项</span></span></div>
                                            <div class="tc-15-page-operate"><span class="tc-15-page-text">每页显示行</span>
                                                <div class="tc-15-page-select"><a href="javascript:"
                                                                                  class="indent">20<span
                                                        class="ico-arrow"></span></a>
                                                    <ul class="tc-15-simulate-option tc-15-def-scroll">
                                                        <li class="selected" tabindex="0">20</li>
                                                        <li class="" tabindex="0">50</li>
                                                        <li class="" tabindex="0">100</li>
                                                    </ul>
                                                </div>
                                                <a href="javascript:" title="第一页"
                                                   class="tc-15-page-first disable"></a><a href="javascript:"
                                                                                           title="上一页"
                                                                                           class="tc-15-page-pre disable"></a>
                                                <div class="tc-15-page-select"><input type="text"
                                                                                      class="tc-15-input-text page-num"
                                                                                      value="1"
                                                                                      style="text-align: center; z-index: 2; width: 42px;"><span
                                                        class="tc-15-page-num">/0页</span></div>
                                                <a href="javascript:" title="下一页" class="tc-15-page-next disable"></a><a
                                                        href="javascript:" title="最后一页"
                                                        class="tc-15-page-last disable"></a></div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <!--body end-->
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

</body>
</html>