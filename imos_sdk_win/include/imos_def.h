/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_def.h

  Project Code: IMOS PLAT
   Module Name: PUBLIC
  Date Created: 2009-03-16
        Author: lilunyi/03464
   Description: 基础平台公共头文件

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_DEF_H_
#define _IMOS_DEF_H_

#ifdef  __cplusplus
extern "C"{
#endif

/* 相同类型服务使用相同的ProcID。1-99给服务进程使用 */
#define IMOS_PROCID_VMSERVER            0x1
#define IMOS_PROCID_ISCSERVER           0x1
#define IMOS_PROCID_SDKSERVER           0x2
#define IMOS_PROCID_MCSERVER            0x3
#define IMOS_PROCID_MPSERVER            0x4
#define IMOS_PROCID_MSSERVER            0x4
#define IMOS_PROCID_DMSERVER            0x4
#define IMOS_PROCID_VXSERVER            0x4
#define IMOS_PROCID_SGSERVER            0x5
#define IMOS_PROCID_BMSERVER            0x6
#define IMOS_PROCID_BWSERVER            0x7
#define IMOS_PROCID_NDSERVER            0x8
#define IMOS_PROCID_IMPSERVER           0x9
#define IMOS_PROCID_UNPSERVER           0xA

#define IMOS_PROCID_TMSSERVER           0xB
#define IMOS_PROCID_TMSCOMBINE          0xC
#define IMOS_PROCID_TMSWS               0xD
#define IMOS_PROCID_TMSRECORD           0xE
#define IMOS_PROCID_TSSERVER            0xF

#define IMOS_PROCID_DRSERVER            0x10
#define IMOS_PROCID_MDSERVER            0x11
#define IMOS_PROCID_TMSNDSERVER         0x12
#define IMOS_PROCID_UVWSSERVER          0x13
#define IMOS_PROCID_MAPMSERVER          0x14

/* SDK client和第三方SDK程序使用100 */
#define IMOS_PROCID_SDKCLIENT           0x64

/* TP进程保持现有值不变，从101开始 */
#define IMOS_PROCID_MW_CTRL             0x65
#define IMOS_PROCID_MW_STOR_MCP         0x66
#define IMOS_PROCID_MW_PTZ              0x67
#define IMOS_PROCID_MW_SNMP             0x68
#define IMOS_PROCID_MW_ALM              0x69
#define IMOS_PROCID_MW_CAPI             0x6A
#define IMOS_PROCID_MW_SDK              0x6B

/* 调试工具以及其它工具程序使用257 */
#define IMOS_PROCID_DT                  0x101
/* IMOS健康检测程序 */
#define IMOS_PROCID_WATCHDOG                  0x102

/** @brief 权限最大配置粒度数量 */
#define IMOS_AUTHORITY_MAX_NUM                  128

/** 内部权限最大配置粒度数量 */
#define IMOS_AUTHORITY_MAX_NUM_EX               1024

/** 存储权限字段最大个数 */
#define IMOS_AUTHORITY_MAX_FIELD_COUNT          32

/*@brief IMOS系统参数长度*/
#define IMOS_SYS_PARAM_LEN                      128             /**< 平台支持的系统参数长度, 有效最大位数为127位 */

/*@brief 通用CODE长度*/
#define IMOS_CODE_LEN                           48             /**< 平台支持的有效最大位数为47位 */

/*@brief 通用名称字符串长度 */
#define IMOS_NAME_LEN                           64             /**< 平台支持的有效最大位数为63位 */

/*@brief URL地址长度 */
#define IMOS_URL_LEN                            512
/*@brief 最大图层数 */
#define MAX_LAYER_NUM                           6              /**< 平台支持的有效最大图层数 */
/////////////////////

/*@brief 资源编码信息字符串长度*/
#define IMOS_RES_CODE_LEN                       IMOS_CODE_LEN

/*@brief 设备编码信息字符串长度*/
#define IMOS_DEVICE_CODE_LEN                    IMOS_CODE_LEN

/*@brief 用户编码信息字符串长度*/
#define IMOS_USER_CODE_LEN                      IMOS_CODE_LEN

/*@brief 域编码信息字符串长度*/
#define IMOS_DOMAIN_CODE_LEN                    IMOS_CODE_LEN

/*@brief 域名称信息字符串长度 */
#define IMOS_DOMAIN_NAME_LEN                    IMOS_NAME_LEN

/*@brief 权限编码信息字符串长度*/
#define IMOS_AUTH_CODE_LEN                      IMOS_CODE_LEN

/*@brief 呼叫过程中UA ID的字符数组长度*/
#define IMOS_UAID_LEN                           64             /**< 平台支持的有效最大位数为63位 */

/*@brief UA编码信息字符串长度*/
#define IMOS_UA_CODE_LEN                        IMOS_UAID_LEN

/*@brief 视频标签信息字符串长度*/
#define IMOS_RECORD_LABEL_LEN                   256

/*@brief 服务协商会话ID长度*/
#define IMOS_SSN_ID_LEN                         IMOS_STRING_LEN_32

/*@brief MP能力描述长度 */
#define IMOS_MP_ABILITY_LEN                     IMOS_STRING_LEN_256

/*@brief DecoderTag的长度 */
#define IMOS_DECODERTAG_LEN                     IMOS_STRING_LEN_32

/*@brief SG编码头长度*/
#define IMOS_SG_HEAD_CODE_LEN                       2

//////////////


/*@brief MAI/AOI消息中通信模块名称的字符串长度 MODULENAME@DEVCODE */
#define IMOS_MODULE_NAME_LEN                    64 /**< 平台支持的有效最大位数为63位 */

/*@brief mac地址字符串长度 "AA-BB-CC-DD-EE-FF" */
#define IMOS_MAC_ADDR_LEN                       20

/*@brief imos_addr IP地址信息字符串长度
 * IPV4: "192.168.0.102"
 * IPV6: "A1:0:8:100:200:0:0:321A"
 * 域名: "AS_server_hangzhou" */
#define IMOS_IPADDR_LEN                         64

/*@brief 无效的IP地址类型 */
#define IMOS_IPADDR_TYPE_INVALID                (0xFFFFFFFF)

/*====== BEGIN: Added by shendongchun 00400 for 用户登录功能增强, 2012年11月14日 17:56:58 =====*/
/*@brief MAC地址类型 */
#define IMOS_IPADDR_TYPE_MAC                    0
/*====== END  : Added by shendongchun 00400 for 用户登录功能增强, 2012年11月14日 17:56:58 =====*/

/*@brief IPV4地址类型 */
#define IMOS_IPADDR_TYPE_IPV4                   1

/*@brief IPV6地址类型 */
#define IMOS_IPADDR_TYPE_IPV6                   2

/*@brief 域名地址类型 */
#define IMOS_IPADDR_TYPE_DOMAINNAME             16

/*@brief 密码信息字符串长度 */
#define IMOS_PASSWD_LEN                         16

/*@brief 密文口令（加密后）字符串长度 */
#define IMOS_PASSWD_ENCRYPT_LEN                 64  /**< 平台支持的有效最大位数为63位 */

/*@brief imos_time 时间信息字符串长度 "2008-10-02 09:25:33.001 GMT" */
#define IMOS_TIME_LEN                           32

/*@brief imos_simple_time 时间信息字符串长度 "hh:mm:ss" */
#define IMOS_SIMPLE_TIME_LEN                    12

/*@brief imos_simple_date 日期信息字符串长度 "YYYY-MM-DD"*/
#define IMOS_SIMPLE_DATE_LEN                    12

/*@brief imos_description 描述信息字符串长度 */
#define IMOS_DESC_LEN                           (128 * 3)

/*@brief 固定电话号码字符串长度 */
#define IMOS_PHONE_LEN                          32

/*@brief 移动电话号码字符串长度 */
#define IMOS_MOBILE_LEN                         32

/*@brief 移动电话号码字符串长度12*256 */
#define IMOS_SMS_LEN_3072                       3072

/*@brief E-Mail字符串长度 */
#define IMOS_MAIL_LEN                           64

/*@brief 邮政编码符串长度 */
#define IMOS_MAIL_CODE_LEN                      8

/*@brief 通信地址字符串长度 */
#define IMOS_CONTACT_ADDRESS_LEN                64

/*@brief 产品名称字符串长度 */
#define IMOS_PRODUCTNAME_LEN                    32

/*@brief 版本信息字符串长度 */
#define IMOS_VERSION_INFO_LEN                   64

/*====== BEGIN: Added by shendongchun 00400 for VVD75808, 2012年11月15日 10:41:45 =====*/
/*@brief 新版本信息字符串长度 */
#define IMOS_NEW_VERSION_INFO_LEN               256
/*====== END  : Added by shendongchun 00400 for VVD75808, 2012年11月15日 10:41:45 =====*/

/*@brief 文件名长度 */
#define IMOS_FILE_NAME_LEN                      64

/*@brief 文件名长度(V2) */
#define IMOS_FILE_NAME_LEN_V2                   256

/** @brief 错误码字符串长度(按ULONG最大值计算,4字节FFFFFFFF,十进制为4294967295,补1位'\0',共11位) */
#define IMOS_ERR_CODE_LEN                       11

/* Begin Added by wuchengping02739, 2011-07-19 of VVD57853 */
/** @brief XML字段 - 成功响应 */
#define IMOS_XML_KEY_RSP_OK "Rsp_Ok"

/** @brief XML字段值通用长度(使用时,注意长度是否够用) */
#define IMOS_XML_KEY_LEN                        64
/* End Added by wuchengping02739, 2011-07-19 of VVD57853 */

/*@brief 文件绝对路径(路径+文件名)长度 */
#define IMOS_FILE_PATH_LEN                      256

/*@brief 文件绝对路径(不带文件名)长度 */
#define IMOS_FILE_PATH_WITHOUT_FILENAME_LEN     128

/** @brief 地点度量长度 */
#define IMOS_MEASUREMENT_LEN                    16

/** @brief 数据字典Key字段长度 */
#define IMOS_DICTIONARY_KEY_LEN                 8

/** @brief 经纬度字符串长度 */
#define IMOS_COORDINATE_LEN                     32

/*@brief 资源所在组织路径长度 */
#define IMOS_RES_PATH_LEN                       1024

/*@brief XP窗格布局描述字符串长度 */
#define IMOS_XP_LAYOUT_DESC_LEN                 256

/*@brief 扩展字段长度 */
#define IMOS_RESERVED_LEN                       64

/*@brief 通用16位字符串 */
#define IMOS_STRING_LEN_14                      14

/*@brief 通用32位字符串 */
#define IMOS_STRING_LEN_32                      32

/*@brief 通用64位字符串 */
#define IMOS_STRING_LEN_64                      64

/*@brief 通用128位字符串 */
#define IMOS_STRING_LEN_128                     128

/*@brief 通用256位字符串 */
#define IMOS_STRING_LEN_256                     256

/*@brief 通用512位字符串 */
#define IMOS_STRING_LEN_512                     512

/*@brief 通用1024位字符串 */
#define IMOS_STRING_LEN_1024                    1024

/*@brief 通用2048位字符串 */
#define IMOS_STRING_LEN_2048                    2048

/*@brief SN长度 */
#define IMOS_SN_LEN                             24

/*@brief 资源树深度 */
#define IMOS_RES_TREE_LEVEL                     26

/*@brief 设备在线状态 */
#define IMOS_DEV_STATUS_ONLINE                  1

/*@brief 设备离线状态 */
#define IMOS_DEV_STATUS_OFFLINE         2

/*@brief 设备正常状态 */
#define IMOS_DEV_STATUS_NORMAL          3

/*@brief 设备故障状态 */
#define IMOS_DEV_STATUS_FAULT           4

/*@brief 设备禁用 */
#define IMOS_DEV_UNABLE                 0

/*@brief 设备启用 */
#define IMOS_DEV_ENABLE                 1

/*@brief 二进制，IMOS_ltoa函数中使用 */
#define  IMOS_Radix_2                   2

/*@brief 八进制，IMOS_ltoa函数中使用 */
#define  IMOS_Radix_8                   8

/*@brief 十进制，IMOS_ltoa函数中使用 */
#define  IMOS_Radix_10                  10

/*@brief 十六进制，IMOS_ltoa函数中使用 */
#define  IMOS_Radix_16                  16


/*@brief IMOS_ID 对应字符串的长度（64位整型ID转换后的最大有效字符长度为20） */
#define  IMOS_ID_STRING_LEN             24

/*@brief 备份录像案例长度 */
#define  IMOS_BAK_CASE_LEN              128

/*@brief 案件描述信息字符串长度 */
#define IMOS_CASE_DESC_LEN                      (1024 * 3)

/*@brief 备注信息字符串长度 */
#define IMOS_NOTE_LEN                           (256 * 3)

/* Begin added by t00977, 2013-1-25 of MPPD00420 */

/** @brief 车辆轨迹碰撞通过地点最大数量 */
#define IMOS_VEHICLE_TRACK_PLACE_MAX_NUM             16

/** @brief 车辆轨迹碰撞最大资源数量 */
#define IMOS_VEHICLE_TRACK_COLLISION_RES_MAX_NUM     200

/** @brief 车辆首次出现最大分析的资源数量 */
#define IMOS_VEHICLE_FIRST_APPEAR_RES_MAX_NUM        200

/** @brief 车辆高危时段最大分析的资源数量 */
#define IMOS_VEHICLE_PERIL_TIME_RES_MAX_NUM          200

/** @brief 车辆频繁夜出最大分析的资源数量 */
#define IMOS_VEHICLE_FREQUENT_NIGHT_OUT_RES_MAX_NUM  200

/** @brief 车辆昼伏夜出最大分析的资源数量 */
#define IMOS_VEHICLE_NOCTURNAL_RES_MAX_NUM           200

/** @brief 车辆多次进城不出城最大分析的资源数量 */
#define IMOS_VEHICLE_ONLY_INTO_CITY_RES_MAX_NUM      200

/** @brief 车辆研判最大分析的资源数量 */
#define IMOS_VEHICLE_OPERATION_ANALYSE_RES_MAX_NUM   200

/** @brief 地图防区布控最大资源数量 */
#define IMOS_MAP_AREA_DISPOSE_RES_MAX_NUM            200
/* End added by bt00977, 2013-1-25 of MPPD00420 */

/** @brief TMS多地址转发最大资源数量 */
#define IMOS_TMS_MULTI_FORWARD_RES_MAX_NUM            200

/** @brief 卡口组配置最大资源数量 */
#define IMOS_TOLLGATE_GROUP_RES_MAX_NUM            200


/** @brief 卡口平均速度无效值 */
#define IMOS_TOLLGATE_INVALID_AVERAGE_SPEED          (0XFFFE)

/*@brief 一天内的秒数 */
#define IMOS_SECS_PER_DAY	            86400

/*@brief 一小时内的秒数 */
#define IMOS_SECS_PER_HOUR	            3600

/*@brief 一分钟内的秒数 */
#define IMOS_SECS_PER_MINUTE            60

/*@brief 一小时内的分钟数 */
#define IMOS_MINS_PER_HOUR	            60


/*@brief 星期日 */
#define IMOS_SUN            0

/*@brief 星期一 */
#define IMOS_MON            1

/*@brief 星期二 */
#define IMOS_TUE            2

/*@brief 星期三 */
#define IMOS_WED            3

/*@brief 星期四 */
#define IMOS_THU            4

/*@brief 星期五 */
#define IMOS_FRI            5

/*@brief 星期六 */
#define IMOS_SAT            6

/*@brief 一月 */
#define IMOS_JAN            0

/*@brief 二月 */
#define IMOS_FEB            1

/*@brief 三月 */
#define IMOS_MAR            2

/*@brief 四月 */
#define IMOS_APR            3

/*@brief 五月 */
#define IMOS_MAY            4

/*@brief 六月 */
#define IMOS_JUN            5

/*@brief 七月 */
#define IMOS_JUL            6

/*@brief 八月 */
#define IMOS_AUG            7

/*@brief 九月 */
#define IMOS_SEP            8

/*@brief 十月 */
#define IMOS_OCT            9

/*@brief 十一月 */
#define IMOS_NOV            10

/*@brief 十二月 */
#define IMOS_DEC            11

/* @brief SG ID信息字符串长度, SG ID生成规则：SG编码&5位随机数 */
#define IMOS_SG_ID_LEN   (IMOS_DEVICE_CODE_LEN + 6)

/*@brief 每个视频通道支持的最大流数目  */
#define IMOS_STREAM_MAXNUM                  2

/*@brief 每个视频通道支持的最大流数目,目前各种类型的EC以此标准  */
#define IMOS_STREAM_MAXNUM_II                  3

/*@brief 每个视频通道支持的最大区域数目  */
#define IMOS_AREA_MAXNUM                    12

/*@brief 单通道遮盖区域的最大数目 */
#define IMOS_MASK_AREA_MAXNUM               4

/*@brief 单通道遮盖区域的最大数目(8) */
#define IMOS_MASK_AREA_MAXNUM_VIII          8

/*@brief 单通道检测区域的最大数目 */
#define IMOS_DETECT_AREA_MAXNUM             4

/*@brief 每个视频通道支持的最大OSD数目 场名osd + 图片osd  */
#define IMOS_OSD_NAME_MAXNUM                1

/*@brief 每个视频通道支持的最大OSD数目 场名osd + 图片osd 目前仅有EC2004-HF和EC2016-HC以此标准 */
#define IMOS_OSD_NAME_MAXNUM_II             2

/*@brief 每个视频通道支持的最大OSD数目 场名osd + 图片osd 目前各种类型的DC以此标准 */
#define IMOS_OSD_NAME_MAXNUM_I              1

/*@brief 每个视频通道支持的最大OSD数目 场名osd + 图片osd 目前除EC2004-HF和EC2016-HC以外的EC设备以此标准 */
#define IMOS_OSD_NAME_MAXNUM_IV             4

/*@brief 每个视频通道支持的最大OSD数目 场名osd + 图片osd 目前EC1001以此标准 */
#define IMOS_OSD_NAME_MAXNUM_VIII             8

/* Modified by wuchengping02739, 2011-12-16 of VVD63549 */
/*@brief 场名OSD的最大个数  */
#define IMOS_OSD_NAME_MAX                     9

/*@brief 时间OSD的最大个数  */
#define IMOS_OSD_TIME_MAX                   1

/** @brief 场名OSD缺省值 */
#define IMOS_NAME_OSD_DEFAULT_VALUE        "H3C"

/** @brief 切换时间间隔缺省值 */
#define IMOS_INTERVAL_DEFAULT_VALUE         0

/*@brief 每个通道中能选择的MS的最大数量  */
#define IMOS_MS_MAX_NUM_PER_CHANNEL         1


/*@brief 计划中每天的时间片数量  */
#define IMOS_MAX_TIME_SLICE_NUM             4

/*@brief 计划中每天的时间片数量V2版本  */
#define IMOS_MAX_TIME_SLICE_NUM_V2          16

/*@brief 计划中每周的天数  */
#define IMOS_WEEK_DAYS                      7

/*@brief 计划中例外的天数  */
#define IMOS_EXCP_DAYS                      16

/*@brief 注册/注销业务编码 */
#define  IMOS_SRV_CODE_REGISTER             1001

/*@brief 配置下发业务编码 */
#define  IMOS_SRV_CODE_CONFIG               1002

/*@brief 文件下载/升级业务编码 */
#define  IMOS_SRV_CODE_FILE                 1003

/*@brief 巡检业务编码 */
#define  IMOS_SRV_CODE_CHECK                1004

/*@brief 实时视频业务编码 */
#define  IMOS_SRV_CODE_MONITOR              2001

/*@brief 语音对讲业务编码 */
#define  IMOS_SRV_CODE_VOICE_TALKBACK       2011

/*@brief 语音广播业务编码 */
#define  IMOS_SRV_CODE_VOICE_BROADCAST      2012

/*@brief 音视频对讲业务编码 */
#define  IMOS_SRV_CODE_MON_TALKBACK         2013

/*@brief 音视频广播业务编码 */
#define  IMOS_SRV_CODE_MON_BROADCAST        2014

/*@brief 录像查询业务编码 */
#define  IMOS_SRV_CODE_REC_QUERY            3001

/*@brief 录像下载业务编码 */
#define  IMOS_SRV_CODE_REC_DOWNLOAD         3002

/*@brief 录像回放业务编码 */
#define  IMOS_SRV_CODE_REC_VOD              3003

/*@brief 录像备份业务编码 */
#define  IMOS_SRV_CODE_REC_BACKUP           3004

/* added by z06806 for vodwall prj 20101220 begin */
/*@brief 回放上墙业务编码 */
#define  IMOS_SRV_CODE_VODWALL              3005
/* added by z06806 for vodwall prj 20101220 end */

/*@brief 录像获取URL业务编码 */
#define  IMOS_SRV_CODE_REC_URL              3006

/*@brief 录像查询结果推送业务编码 */
#define  IMOS_SRV_CODE_REC_QUERY_PUSH       3007

/* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
/*@brief 录像锁定业务编码 */
#define  IMOS_SRV_CODE_LOCK_RECORD       3008
/* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */

/*@brief 前端录像检索业务编码 */
#define IMOS_SRV_CODE_DEVICE_REC_QUERY     3009         /* Add by zhengyibing(01306), 2014-04-19 for 新国标修订*/
/*@brief 直接存储业务编码 */
#define  IMOS_SRV_CODE_DIR_STROE            4001

/*@brief 收流存储业务编码 */
#define  IMOS_SRV_CODE_STR_STORE            4002

/*@brief 前端存储业务编码 */
#define  IMOS_SRV_CODE_TP_STORE             4003

/*@brief 刷新存储索引编码 */
#define  IMOS_SRV_CODE_REFRESH_STORE_IDX    4004

/*@brief 获取Initiator业务编码 */
#define  IMOS_SRV_CODE_GET_INITIATOR        4010

/*@brief 配置中心存储资源业务编码 */
#define  IMOS_SRV_CODE_CENT_STORE_RES_CFG   4011

/*@brief 配置中心存储计划业务编码 */
#define  IMOS_SRV_CODE_CENT_STORE_PLAN_CFG  4012

/*@brief 配置中心告警联动存储业务编码 */
#define  IMOS_SRV_CODE_CENT_ALARM_STORE_CFG 4013

/*@brief 中心触发告警存储业务编码 */
#define  IMOS_SRV_CODE_CENT_TRIGGER_ALARM_STORE   4020

/*@brief 中心触发手动存储业务编码 */
#define  IMOS_SRV_CODE_CENT_TRIGGER_MANUAL_STORE  4021

/*@brief 云台控制业务编码 */
#define  IMOS_SRV_CODE_PTZ                  5001

/*@brief 开关量控制业务编码 */
#define  IMOS_SRV_CODE_SWITCH               5002

/*@brief 预置位列表查询业务编码 */
#define  IMOS_SRV_CODE_PRESETLIST_QUERY     5003

/*@brief 云台锁定、解锁业务编码 */
#define  IMOS_SRV_CODE_PTZ_LOCK_UNLOCK     5004

/*@brief 云台被解锁通知业务编码 */
#define  IMOS_SRV_CODE_PTZ_UNLOCK_NOTIFY     5005

/*@brief 透明通道业务编码 */
#define  IMOS_SRV_CODE_TRANS_CHANNEL        6001

/*@brief 透明数据传输业务编码 */
#define  IMOS_SRV_CODE_TRANS_DATA           6002

/*@brief 告警发送业务编码 */
#define  IMOS_SRV_CODE_ALARM                7001

/*@brief 布/撤防业务编码 */
#define  IMOS_SRV_CODE_ALARM_CTRL           7002

/*@brief 告警查询业务编码 */
#define  IMOS_SRV_CODE_ALARM_QUERY          7003

/*@brief 摄像机信息查询业务编码 */
#define  IMOS_SRV_CODE_CAM_INFO_QUERY       7004

/*@brief 查询设备信息请求 */
#define  IMOS_SRV_CODE_DEV_INFO_QUERY     7005

/*@brief 查询设备信息请求的响应 */
#define  IMOS_SRV_CODE_DEV_INFO_RES       7006

/*@brief 查询设备状态请求 */
#define  IMOS_SRV_CODE_DEV_STATIC_QUERY       7007

/*@brief 查询设备状态请求的响应 */
#define  IMOS_SRV_CODE_DEV_STATIC_RES       7008

/*@brief 设备共享业务编码 */
#define  IMOS_SRV_CODE_DEVICE_SHARE         8001 /* Added by MultiDomain */

/*@brief 场景推送业务编码 */
#define IMOS_SRV_CODE_LAYOUT_RES_SHARE      8002

/*@brief 外域资源查询业务编码 */
#define  IMOS_SRV_CODE_RESOURCE_QUERY       8100

/*@brief 目录订阅上报业务编码 */
#define IMOS_SRV_CODE_SUB_CATALOG           8101

/*Begin added by zhuhongyan 00342 2013-1-23 for 国电B二期 */
/*@brief 设备校时参数设置业务编码 */
#define IMOS_SRV_CODE_SET_DATETIME          8101

/*@brief 视频编码参数设置业务编码 */
#define IMOS_SRV_CODE_SET_VIDEOCODE         8102

/*@brief 设备资源参数设置业务编码 */
#define IMOS_SRV_CODE_SET_RESOURCE          8103

/*@brief 预置点参数设置业务编码 */
#define IMOS_SRV_CODE_SET_PRESET            8104

/*@brief OSD参数设置业务编码 */
#define IMOS_SRV_CODE_SET_OSD               8105

/*@brief 视频遮档参数设置业务编码 */
#define IMOS_SRV_CODE_SET_VIDEOHIDE         8106

/*@brief 遮档告警参数设置业务编码 */
#define IMOS_SRV_CODE_SET_COVERALARM         8107

/*@brief 移动侦测告警参数设置业务编码 */
#define IMOS_SRV_CODE_SET_MOTIONALARM       8108

/*@brief 设备时钟参数查询业务编码 */
#define IMOS_SRV_CODE_QUERY_DATETIME        8151

/*@brief 视频编码参数查询业务编码 */
#define IMOS_SRV_CODE_QUERY_VIDEOCODE       8152

/*@brief 设备资源参数查询业务编码 */
#define IMOS_SRV_CODE_QUERY_RESOURCE        8153

/*@brief 预置点参数查询业务编码 */
#define IMOS_SRV_CODE_QUERY_PRESET          8154

/*@brief OSD参数查询业务编码 */
#define IMOS_SRV_CODE_QUERY_OSD             8155

/*@brief 查询遮盖编码 */
#define  IMOS_SRV_CODE_QUERY_VIDEOMASK          8156

/*@brief遮挡告警查询业务编码 */
#define  IMOS_SRV_CODE_QUERY_COVERDETECT          8157

/*@brief 移动侦测 告警查询业务编码 */
#define  IMOS_SRV_CODE_QUERY_MOTIONDETECT         8158

/*@brief 三维定焦 业务编码 */
#define IMOS_SRV_CODE_3DCONTROLCAMERA             8159
/*End added by zhuhongyan 00342 2013-1-23 for 国电B二期 远程参数配置*/

/*@brief 订阅上报业务编码 */
#define IMOS_SRV_CODE_SUBSCRIBE             9001

/*@brief 域间数据同步业务编码 */
#define IMOS_SRV_CODE_DOMAIN_DATASYN        9002

/*@brief 资源查询业务编码 */
#define IMOS_SRV_CODE_QUERY_RES             9003
/*@brief 设备远程启动 */
#define  IMOS_SRV_CODE_TEL_REBOOT           9600

/*@brief 布防业务编码 */
#define IMOS_SRV_CODE_SETGUARD              9601

/*@brief 撤防业务编码 */
#define IMOS_SRV_CODE_RESETGUARD            9602

/*@brief 报警复位业务编码 */
#define IMOS_SRV_CODE_ALARM_RESET           9603

/*@brief 国标卡口业务编码 */
#define IMOS_SRV_CODE_TG_DISPOSE            9701

/*@brief 定义授权码的长度 */
#define IMOS_LICENSE_AUTHORITY_CODE_LENGTH (32 + 4)

/*@brief 区域类型：遮盖区域 */
#define IMOS_VIDEO_AREA_TYPE_MASK           0

/*@brief 区域类型：遮挡区域 */
#define IMOS_VIDEO_AREA_TYPE_COVER_DETECT   1

/*@brief 区域类型：移动侦测区域 */
#define IMOS_VIDEO_AREA_TYPE_MOTION_DETECT  2

/*@brief 视频输出虚拟通道最大数量 */
#define IMOS_VOUT_CHANNEL_MAXNUM            4

/*@brief 视频输出虚拟通道缺省数量 */
#define IMOS_VOUT_CHANNEL_DEFAULT_NUM       1

/*@brief BP支持的预定义命令中每个命令参数的最大长度 */
#define IMOS_MAX_CMD_PARAM_LEN              512

/*@brief BP支持的预定义命令中支持的最大参数个数 */
#define IMOS_MAX_CMD_PARAM_NUM              6

/*@brief gb2312编码名称 */
#define IMOS_CODE_TYPE_GB2312 "gb2312"

/*@brief utf-8编码名称 */
#define IMOS_CODE_TYPE_UTF8 "utf-8"

/*@brief gbk编码名称 */
#define IMOS_CODE_TYPE_GBK "gbk"

/*@brief IMOS默认设备类型 */
#define IMOS_DEVICE_TYPE_DESC_DEFAULT       "defaultType"

/*@brief IMOS支持的设备类型个数(EC/DC/MS/TS/DM/VX500/摄像头/监视器/ECR/BM/IPSAN/TMS/卡口/卡口相机) */
#define IMOS_DEVICE_TYPE_NUM                14/* Modified by b00103, 2013-04-01 of MPPD01243 */

/*@brief NTP服务器同步信息宏长度 */
#define IMOS_NTP_SYNC_STATUS_LEN            32

/*@brief 第三方厂商的类型ID最小值 */
#define IMOS_MIN_THIRD_MANUFACTURERID        1

/*@brief 第三方厂商的类型ID最大值(用户可配置) */
#define IMOS_MAX_THIRD_MANUFACTURER_ID       60000

/*@brief 第三方设备类型的类型ID最小值 */
#define IMOS_MIN_THIRD_DEV_TYPE_ID           20000

/*@brief 第三方设备类型的类型ID最大值(用户可配置) */
#define IMOS_MAX_THIRD_DEV_TYPE_ID           40000

/*@brief 第三方告警类型的类型ID最小值 */
#define IMOS_MIN_THIRD_EVT_TYPE_ID           20000

/*@brief 第三方告警类型的类型ID最大值(用户可配置) */
#define IMOS_MAX_THIRD_EVT_TYPE_ID           40000

/*@brief 第三方告警类型在数据库中不存在 */
#define IMOS_NO_EXIST_EVENT_TYPE_ID          0

/*@brief 任意设备类型 */
#define IMOS_DEVICE_TYPE_ALL                 65535

/*@brief 第三方厂商的类型ID最大值(包括内置厂商类型) */
#define IMOS_MAX_THIRD_MANUFACTURER_ID_ALL   65535

/*@brief 第三方设备类型的类型ID最大值(包括内置设备类型) */
#define IMOS_MAX_THIRD_DEV_TYPE_ID_ALL       50000

/*@brief 第三方告警类型的类型ID最大值(包括内置告警类型) */
#define IMOS_MAX_THIRD_EVT_TYPE_ID_ALL       50000

/*@brief 订阅过滤条件最大个数 */
#define IMOS_SUBSC_ITEM_MAX_NUM             8

/* Begin added by baoyihui02795, 2011-04-28 of 卡口项目 */
/** @brief 车辆信息最大图片数量 */
#define IMOS_MAX_VEHICLE_IMG_NUM            4

/** @brief 汽车号牌最大数量 */
#define IMOS_MAX_LICENSE_PLATE_NUM          2

/** @brief 一个相机对应的最大车道数量 */
#define IMOS_MAX_CAMERA_LANE_NUM                      8

/** @brief 最大车道方向数量 */
#define IMOS_MAX_LANE_DIRECTION_NUM                   200

/** @brief 缺省车道方向数量 */
#define IMOS_DEFAULT_LANE_DIRECTION_NUM               2

/** @brief 最大车辆类型数量 */
#define IMOS_MAX_VEHICLE_TYPE_NUM                     5
/* End added by baoyihui02795, 2011-04-28 of 卡口项目 */

/* Begin added by b00103, 2012-04-17 of 卡口D006 */
/** @brief 最大卡口图片留存期数量  */
#define IMOS_MAX_TOLLGATE_PHOTO_STOR_SLICE_NUM       16

/** @brief 最大卡口图片生命周期配置数量  */
#define IMOS_MAX_TOLLGATE_PHOTO_LIFT_CYCLE_NUM       16
/* End added by b00103, 2012-04-17 of 卡口D006 */

/** @brief 日期时间字符串标准长度 */
#define IMOS_DATE_TIME_FORMAT_LEN                    (19)

/*@brief 查询项最大个数 */
#define IMOS_QUERY_ITEM_MAX_NUM2            200

/** @brief 最大计划参数长度  */
#define IMOS_MAX_PLAN_PARAM_LEN             128

/*@brief 1分钟的秒数 */
#define IMOS_SECOND_IN_MIN                  60

/*@brief 1个小时的秒数 */
#define IMOS_SECOND_IN_HOUR                 3600

/** @brief 一条告警订阅规则支持的用户最大数量 */
#define IMOS_ALARM_SEND_USER_MAXNUM         256

/** @brief 一条告警订阅规则支持的第三方系统最大数量 */
#define IMOS_ALARM_SEND_THD_SYS_MAXNUM         256

/** @brief 一条告警订阅规则支持的告警源最大数量 */
#define IMOS_ALARM_SEND_SRC_MAXNUM          2000

/** @brief 系统支持的告警订阅规则最大数量 */
#define IMOS_ALARM_SEND_RULE_MAXNUM         3000

/** @brief 行为分析规则最大数量 */
#define IMOS_BEHAVIOR_RULE_MAX  8

/** @brief 坐标字符串长度 16 */
#define IMOS_COORDINATE_STR_LEN_16  16

/** @brief 坐标字符串长度 56 */
#define IMOS_COORDINATE_STR_LEN_56  56

/* Added by wuchengping02739, 2011-12-16 of VVD63517 */
/** @brief 资源组扩展信息长度 1024 */
#define IMOS_RES_GROUP_EXT_LEN 1024

/*@brief WebGis图层名称名长度 */
#define IMOS_WEBGIS_LAYER_NAME_LEN                   256

/** @brief 空字符串 */
#define IMOS_NULL_STRING  ""

/* Begin Added by ykf0030, 2012-2-27 of 网络适应性 */
/** @brief EC实况网络适应开关默认值 */
#define IMOS_MON_NETWORK_ADAPT_ENABLE_DEFAULT    2

/** @brief EC存储网络适应开关默认值 */
#define IMOS_STORE_NETWORK_ADAPT_ENABLE_DEFAULT  2

/* Begin Modified by shaoyili(KF0094), 2012-12-5 of VVD69387 */
/** @brief EC网络适应模式默认值 */
#define IMOS_NETWORK_ADAPT_MODE_DEFAULT  0
/* End Modified by shaoyili(KF0094), 2012-12-5 of VVD69387 */

/** @brief EC实况网络自适应恢复时间默认值 */
#define IMOS_NETWORK_ADAPT_COUNT_DEFAULT  30
/* End Added by ykf0030, 2012-2-27 of 网络适应性 */

/** @brief 记录onvif错误模块注册名称 */
#define AS_RTDE_MODULE_NAME "AS_RTDE_MOUDLE"

/** @brief 记录onvif错误模块 */
#define AS_RTDE_MODULE_CMD_ID 0x07140000

#define IMOS_MAX_WINDOW_NUMBER              256                  /**<人机单个输出端口预览窗格最大数量*/

/*@brief EC下摄像机个数最大值*/
#define IMOS_CAM_MAX_NUM                    16

/*@brief 共享摄像机扩展字段长度 */
#define IMOS_CAM_SHARE_RESERVED_LEN             32  /* added by tangxiaobin00764,2012-10-25 of 资源互联编码可配置*/

/* Begin: added by zkf0134, 2013.11.22 for 分屏切换支持主辅流自适应*/
/* 分屏切换支持主辅流自适应关闭临界值*/
#define IMOS_SPLIT_SCREEN_SWITCH_CLOSE            0
/* End: added by zkf0134, 2013.11.22 for 分屏切换支持主辅流自适应*/

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
*@enum tagUMUsbDirType
*@brief USB目录类型
*/
typedef enum tagUMUsbDirType
{
    UM_USB_DIR_TYPE_FILE,                      /* 文件 */
    UM_USB_DIR_TYPE_DIR,                       /* 目录 */
}UM_USB_DIR_TYPE_E;

#define USB_FILE_NAME_LEN               64
#define USB_DIR_NUM                     100
#define USB_DISK_MAX_NUMBER             2         /* U盘个数，目前为2个 */
/* End Added by lw0581,2013-11-6 for  VVD06374*/
/** @brief 根据rgb,计算颜色值 */
#define COLOR(r, g, b)  ((ULONG_32) (((UCHAR) (r) | ((USHORT) ((UCHAR) (g)) << 8)) | (((ULONG_32) (UCHAR) (b)) << 16)))

/*====== BEGIN: Added by shendongchun 00400 for 用户登录功能增强, 2012年11月13日 19:06:00 =====*/
/*@brief 用户登录时最大地址数量 */
#define IMOS_MAX_LOGIN_ADDRESS_NUM               (20)

/*@brief 绑定用户登录信息最大地址数量 */
#define IMOS_MAX_BINDING_ADDRESS_NUM             (50)
/*====== END  : Added by shendongchun 00400 for 用户登录功能增强, 2012年11月13日 19:06:00 =====*/
/* Begin Added by w00523, 2012-11-06 for SDC-OSD */
#define MAX_OTHER_HEADER_NUM                                5
#define MAX_EXT_INFO_ATTRIBUTE_NUM                          20
#define MAX_EXT_INFO_ATTR_KEY_LEN                           32
#define MAX_EXT_INFO_ATTR_VALUE_LEN                         128
#define MAX_EXT_INFO_TOTOL_LEN                              512
/* End Added by w00523, 2012-11-06 for SDC-OSD */

#define IMOS_POLYGON_GEO_LEN   1024
#define IMOS_POINT_GEO_LEN   128

/** @brief IMOS全能力表述:IMOS-ALL */
#define IMOS_ALL_DESC "IMOS-ALL"

/** @brief IMOS全能力表述IMOS-ALL长度 */
#define IMOS_ALL_DESC_LEN 8

/** @brief IMOS全能力表述VFA=长度 */
#define IMOS_VFA_LEN 4

/* Begin: Added by tangxiaobin00764, 2013.3.5  for IVSD00576 of 第三方IPC优化 组内review */
#define IMOS_IPC_CAM_INFO_REVERSED_LEN   512
/* End: Added by tangxiaobin00764, 2013.3.5  for IVSD00576 of 第三方IPC优化 组内review */

/* 录像空洞时间容差(单位:秒) */
#define IMOS_REC_TIME_TOLERANCE_DIFF        1

/* 从mw_webapi_pub.h中移植过来的宏 */
/* 网卡名称的长度 */
#define IMOS_NETWORK_CARD_NAME_LEN_FOR_ECR          16
/* 单个网卡的物理接口数量 最大值为16 */
#define IMOS_NETWORK_CARD_PHY_MAXNUM_FOR_ECR        16
/* 单个网卡的IP地址数量 最大值为4 */
#define IMOS_NETWORK_CARD_IP_ADDR_MAXNUM_FOR_ECR    4
/** 版本号长度 */
#define IMOS_VERSION_LENTH                          64
/** ip 地址最大长度 */
#define IMOS_IPADDR_LENTH                           40

/* begin added by suzhijie 00294 for NVRV3R1 20130411 */
/*@brief 卡口地点名称字符串长度 */
#define IMOS_PLACE_NAME_LEN                           256

/*@brief 卡口过车记录表特殊字符串长度 实际记录整形数值*/
#define IMOS_TOLLGATE_SPECIAL_LEN                           4

/*@brief 卡口过车记录表特殊名字字符串长度 */
#define IMOS_TOLLGATE_SPECIAL_NAME_LEN                           68

/*@brief 卡口过车记录表特殊ID字符串长度 */
#define IMOS_TOLLGATE_SPECIAL_ID_LEN                           20

/*@brief 卡口过车记录表普通编码长度*/
#define IMOS_TOLLGATE_CODE_LEN                           36

/*@brief UM 查询U盘文件夹目录最大个数*/
#define UM_USB_DIR_NUM                     100
/* end added by suzhijie 00294 for NVRV3R1 20130411 */

/* begin added by suzhijie 00294 for NVRV3R1 20130329 */
/** @brief 车辆信息最大图片数量 */
#define IMOS_MAX_VEHICLE_IMG_NUM_FOR_ECR    6

/*@brief 车辆信息最大图片名称长度 */
#define IMOS_MAX_VEHICLE_IMG_NAME_LEN       260
/* end added by suzhijie 00294 for NVRV3R1 20130329 */

/* Begin: added by liuhongjieKF0170, 2013-9-4 of IPC支持区块OSD */
#define IMOS_IPC_SERIAL_PORT_MAX_NUM       5
#define IMOS_XML_EXPAND_DESC_LEN           IMOS_STRING_LEN_32
#define IMOS_IPC_OSD_MAXNUM                8
#define IMOS_IPC_OSD_BLOCK_MAXNUM   8
#define IMOS_IPC_OSD_BLOCK_MAXNUM_III   3
#define IMOS_IPC_OSD_VERSSION_ONE     "VersionV01"
#define IMOS_IPC_MAX_ROI_NUM               4
/* End: added by liuhongjieKF0170, 2013-9-4 of IPC支持区块OSD */

/* Begin: addedBy liuhongjieKF0170, 2013-9-27  IPC支持区块OSD */
#define IMOS_IPC_OSD_SUPPORT_MIB_FLG  ";17.1.2.1"
/* End: addedBy liuhongjieKF0170, 2013-9-27  IPC支持区块OSD */

/* Begin Add by zhouquanwei/z01364 2013-11-08 of onvif支持多profile */
/*@brief onvif profile 最大数目 */
#define IMOS_ONVIF_PROFILE_MAX   8

/*@brief onvif profile 流个数:目前包含主流辅流*/
#define IMOS_ONVIF_STREAM_MAX    2
/* End Add by zhouquanwei/z01364 2013-11-08 of onvif支持多profile */

/**
 * @enum tagIMOSBehaviorType
 * @brief 行为类型
 * @attention
 */
typedef enum tagIMOSBehaviorType
{
    IMOS_BEHAVIOR_TYPE_THRU_LINE    = 0,    /**< 绊线 */
    IMOS_BEHAVIOR_TYPE_INOUT_AREA   = 1,    /**< 进出区域 */

    IMOS_BEHAVIOR_TYPE_MAX,
    IMOS_BEHAVIOR_TYPE_INVALID      = 0XFFFFFFFF
} IMOS_BEHAVIOR_TYPE_E;

/** 设备额外状态枚举 */
typedef enum tagIMOSDevExtStatus
{
    IMOS_EXT_STATUS_NORMAL   = 0,                /**< 正常状态 */
    IMOS_EXT_STATUS_VIDEO_LOST_RESUME = 1,       /**< 视频恢复 */
    IMOS_EXT_STATUS_VIDEO_LOST = 2,              /**< 视频丢失 */
    IMOS_EXT_STATUS_MAX,                         /**< 最大值 */
    IMOS_EXT_STATUS_INVALID    = 0xFFFFFFFF      /**< 无效值 */
}IMOS_DEV_EXT_STATUS_E;

/**
* @enum tagIMOSDevBelongAttr
* @brief  设备归属属性枚举
* @attention 无
*/
typedef enum tagIMOSDevBelongAttr
{
    IMOS_DEV_LOCAL = 0,                        /**< 属于本域的设备 */
    IMOS_DEV_FOREIGN = 1,                      /**< 属于外域的设备 */
    IMOS_DEV_BELONG_ALL = 2,                   /**< 所有设备 */
    IMOS_DEV_BELONG_MAX,                       /**< 最大值 */
    IMOS_DEV_BELONG_INVALID = 0xFFFFFFFF       /**< 无效值 */
}IMOS_DEV_BELONG_ATTR;

/**
* @enum tagIMOSFaultDevStatus
* @brief  设备故障状态枚举选项
* @attention 无
*/
typedef enum tagIMOSFaultDevStatus
{
    IMOS_DEV_FAULT_STATUS_ONLINE = 0,          /**< 设备正常在线 */
    IMOS_DEV_FAULT_STATUS_FAULT = 1,           /**< 设备在线故障 */
    IMOS_DEV_FAULT_STATUS_OFFLINE = 2,         /**< 设备离线 */
    IMOS_DEV_FAULT_STATUS_ALL = 3,             /**< 设备所有状态 */
    IMOS_DEV_FAULT_STATUS_MAX,                 /**< 最大值 */
    IMOS_DEV_FAULT_STATUS_INVALID = 0xFFFFFFFF /**< 无效值 */
}IMOS_DEV_FAULT_STATUS_E;

/**
* @enum tagIMOSDomainDevType
* @brief 域设备类型(产品化配置数据,即从产品角度所能看到的域设备类型)
* @attention
*/
typedef enum tagIMOSDomainDevType
{
    IMOS_DOMAIN_DEV_TYPE_DA          = 0,        /**< DA */
    IMOS_DOMAIN_DEV_TYPE_DVR         = 1,        /**< DVR */
    IMOS_DOMAIN_DEV_TYPE_NVR         = 2,        /**< NVR */
    IMOS_DOMAIN_DEV_TYPE_PLS         = 3,        /**< PL-S */
    IMOS_DOMAIN_DEV_TYPE_V3VM        = 4,        /**< V3VM */
    IMOS_DOMAIN_DEV_TYPE_ISC3000E    = 5,        /**< ISC3000-E */

    IMOS_DOMAIN_DEV_TYPE_MAX,                    /**< 最大值 */
    IMOS_DOMAIN_DEV_TYPE_INVALID     = 0xFFFF    /**< 无效值 */
} IMOS_DOMAIN_DEV_TYPE_E;

/**
* @enum tagIMOSDBConnectionNum
* @brief 数据库连接号码
* @attention 无
*/
typedef enum tagIMOSDBConnectionNum
{
    IMOS_DB_CONNECTION_CM = 1,                  /**< 配置模块数据库连接号码 */
    IMOS_DB_CONNECTION_RS = 2,                  /**< 配置模块数据库连接号码 */
    IMOS_DB_CONNECTION_SM = 3,                  /**< 配置模块数据库连接号码 */
    IMOS_DB_CONNECTION_MAX,                     /**< 最大值 */
    IMOS_DB_CONNECTION_INVALID = 0xFFFFFFFF     /**< 无效值 */
}IMOS_DB_CONNECTION_NUM_E;

/**
* @enum tagIMOSDomainDeviceType
* @brief 域设备类型(对于VM设备,为产品化配置数据)
* @attention
*/
typedef enum tagIMOSDomainDeviceType
{
    /* VM设备(即在"IMOS平台一套代码"基础上,产品化形成的设备)的类型:0～99 */
    IMOS_DOMAIN_DEVICE_TYPE_VM8500      = 0,       /**< VM8500 */
    IMOS_DOMAIN_DEVICE_TYPE_VM5500      = 1,       /**< VM5500 */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3308HF   = 2,       /**< ECR3308-HF */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HF   = 3,       /**< ECR3316-HF */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3000E    = 4,       /**< ISC3000-E */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3000S    = 5,       /**< ISC3000-S */
    IMOS_DOMAIN_DEVICE_TYPE_PL          = 6,       /**< PL */
    IMOS_DOMAIN_DEVICE_TYPE_PLS         = 7,       /**< PL-S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC6000     = 8,       /**< ISC6000 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC3500E    = 9,       /**< ISC3500-E */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500S    = 10,       /**< ISC3500-S */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3308HFE   = 11,       /**< ECR3308-HF-E */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HFE   = 12,       /**< ECR3316-HF-E */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3308HFS   = 13,       /**< ECR3308-HF-S */
    IMOS_DOMAIN_DEVICE_TYPE_ECR3316HFS   = 14,       /**< ECR3316-HF-S */
    /* Begin: added by lw0581, 2013.12.19 for  MPPD06992 */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000_S    = 27,          /**< ISC5000_S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000_E    = 28,          /**< ISC5000_E */
    /* End: added by lw0581, 2013.12.19 for  MPPD06992 */
    
    IMOS_DOMAIN_DEVICE_TYPE_VM9500   = 29,          /**< VM9500 */

    /* H3C其它域设备:100～ */
    IMOS_DOMAIN_DEVICE_TYPE_DA8500      = 100,     /**< DA8500 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC3500ET    = 1020,       /**< ISC3500-ET */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500EL    = 1021,       /**< ISC3500-EL */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500ST    = 1022,       /**< ISC3500-ST */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500SL    = 1023,       /**< ISC3500-SL */

    IMOS_DOMAIN_DEVICE_TYPE_ECR2104HF    = 7001,       /**< ECR2108-HF */
    IMOS_DOMAIN_DEVICE_TYPE_ECR2108HF    = 7002,       /**< ECR2108-HF */

    /* Begin: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR大类 */
    IMOS_DOMAIN_DEVICE_TYPE_ECR_ALL    = 7000,       /**< ECR大类 */
    IMOS_DOMAIN_DEVICE_TYPE_NVR_ALL    = 8000,       /**< NVR大类 */
    /* End: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR大类 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC2500SP    = 8001,       /**< ISC2500-SP */
    IMOS_DOMAIN_DEVICE_TYPE_ISC2500EP    = 8002,       /**< ISC2500-EP */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000S     = 8003,       /**< ISC5000-S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC5000E     = 8004,       /**< ISC5000-E */
    IMOS_DOMAIN_DEVICE_TYPE_ISC2500S     = 8005,       /**< ISC2500-S */
    IMOS_DOMAIN_DEVICE_TYPE_ISC2500E     = 8006,       /**< ISC2500-E */

    IMOS_DOMAIN_DEVICE_TYPE_ISC3500E_B05     = 8007,     /**< ISC3500-E_B05 */
    IMOS_DOMAIN_DEVICE_TYPE_ISC3500S_B05     = 8008,     /**< ISC3500-S_B05 */

    IMOS_DOMAIN_DEVICE_TYPE_ISC2500SCT    = 8100,     /**<ISC2500-SCT */

    IMOS_DOMAIN_DEVICE_TYPE_MAX,                   /**< 最大值 */
    IMOS_DOMAIN_DEVICE_TYPE_INVALID     = 0xFFFF   /**< 无效值 */
} IMOS_DOMAIN_DEVICE_TYPE_E;

/**
* @enum tagIMOSBooleanType
* @brief 开关量类型
* @attention 无
*/
typedef enum tagIMOSBooleanType
{
    IMOS_BOOLEAN_TYPE_IN = 0,                   /**< 输入开关量 */
    IMOS_BOOLEAN_TYPE_OUT = 1,                  /**< 输出开关量 */
    IMOS_BOOLEAN_TYPE_NONE = 2,                 /**< 所有开关量类型 */

    IMOS_BOOLEAN_TYPE_MAX,                      /**< 最大值 */
    IMOS_BOOLEAN_TYPE_INVALID = 0xFFFFFFFF      /**< 无效值 */
}IMOS_BOOLEAN_TYPE_E;

/**
* @name 域设备类型(字符串值)
* @{
*/
/* Begin: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR大类 */
/** @brief ECR大类*/
#define IMOS_DOMAIN_DEV_TYPE_ECR_ALL        "ECR_ALL"

/** @brief NVR大类*/
#define IMOS_DOMAIN_DEV_TYPE_NVR_ALL        "ISC_ALL"
/* End: Added by mozhanfei(kf0149) 2013-7-18 for ECR NVR大类 */

/** @brief H3C ISC6000 */
#define IMOS_DOMAIN_DEV_TYPE_ISC6000_STR        "H3C-ISC6000"

/** @brief H3C VM8500 */
#define IMOS_DOMAIN_DEV_TYPE_VM8500_STR         "H3C-VM8500"

/** @brief H3C VM9500 */
#define IMOS_DOMAIN_DEV_TYPE_VM9500_STR         "H3C-VM9500"

/** @brief H3C VM5500 */
#define IMOS_DOMAIN_DEV_TYPE_VM5500_STR         "H3C-VM5500"

/** @brief H3C ECR3308HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR3308HF_STR      "H3C-ECR3308HF"

/** @brief H3C ECR3316HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_STR      "H3C-ECR3316HF"

/** @brief H3C ECR3308HF_E */
#define IMOS_DOMAIN_DEV_TYPE_ECR3308HF_E_STR    "H3C-ECR3308HF-E"

/** @brief H3C ECR3316HF_E */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_E_STR    "H3C-ECR3316HF-E"

/** @brief H3C ECR3308HF_S */
#define IMOS_DOMAIN_DEV_TYPE_ECR3308HF_S_STR    "H3C-ECR3308HF-S"

/** @brief H3C ECR3316HF_S */
#define IMOS_DOMAIN_DEV_TYPE_ECR3316HF_S_STR    "H3C-ECR3316HF-S"

/** @brief ECR2108HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR2108HF_STR      "ECR2108_HF"

/** @brief ECR2104HF */
#define IMOS_DOMAIN_DEV_TYPE_ECR2104HF_STR      "ECR2104_HF"

/** @brief ISC3500_ET */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500ET          "ISC3500_ET"

/** @brief ISC3500_EL */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500EL          "ISC3500_EL"

/** @brief ISC3500_ST */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500ST          "ISC3500_ST"

/** @brief ISC3500_SL */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500SL          "ISC3500_SL"

/** @brief ISC3500-E_B05 */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500E_B05       "ISC3500-E_B05"

/** @brief ISC3500-S_B05 */
#define IMOS_DOMAIN_DEV_TYPE_ISC3500S_B05       "ISC3500-S_B05"

/** @brief ISC2500_SP */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500SP          "ISC2500_SP"

/** @brief ISC2500_EP */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500EP          "ISC2500_EP"

/** @brief ISC2500_S */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500S           "ISC2500_S"

/** @brief ISC2500_E */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500E           "ISC2500_E"

/** @brief ISC5000_S */
#define IMOS_DOMAIN_DEV_TYPE_ISC5000S           "ISC5000_S"

/** @brief ISC5000_E */
#define IMOS_DOMAIN_DEV_TYPE_ISC5000E           "ISC5000_E"

/** @brief ISC2500-SCT */
#define IMOS_DOMAIN_DEV_TYPE_ISC2500SCT         "ISC2500-SCT"

/** @brief H3C VM8000 */
#define IMOS_DOMAIN_DEV_TYPE_VM8000_STR         "H3C-VM8000"

/** @brief H3C VM5000 */
#define IMOS_DOMAIN_DEV_TYPE_VM5000_STR         "H3C-VM5000"

/** @brief H3C ISC3000 */
#define IMOS_DOMAIN_DEV_TYPE_ISC3000_STR        "H3C-ISC3000"

/** @brief H3C ISC3000-E */
#define IMOS_DOMAIN_DEV_TYPE_ISC3000E_STR       "H3C-ISC3000-E"

/** @brief H3C ISC3000-S */
#define IMOS_DOMAIN_DEV_TYPE_ISC3000S_STR       "H3C-ISC3000-S"

/** @brief H3C DA8500 */
#define IMOS_DOMAIN_DEV_TYPE_DA8500_STR         "H3C-DA8500"

/** @brief Aproud PL */
#define IMOS_DOMAIN_DEV_TYPE_PL_STR             "Aproud-PL"

/** @brief Aproud PL-S */
#define IMOS_DOMAIN_DEV_TYPE_PLS_STR            "Aproud-PL-S"

/** @brief Aproud ONU */
#define IMOS_DOMAIN_DEV_TYPE_ONU_STR            "Aproud-ONU"

/** @brief 非H3C外域 */
#define IMOS_DOMAIN_DEV_TYPE_OTHER_STR          "Other"
/** @} */

/* Added by MultiDomain */
/** @brief SG默认编码 */
#define IMOS_AS_DEFAULT_SG_CODE                   "SG0000"

/** @brief ECPAGGUOBIAO默认编码 */
#define IMOS_DEFAULT_PAG_GB_CODE                "ECPAGGUOBIAO"

/** @brief ECPAGIMOSCODE默认编码 */
#define IMOS_DEFAULT_PAG_IMOS_CODE              "ECPAGIMOSCODE"

/* Begin added by j00350 for MPPD08948, 20140120 */
/** @brief ECPAGMOBILE默认编码 */
#define IMOS_DEFAULT_PAG_MOBILE_CODE            "ECPAGMOBILE"          /* MOBILE */
/* End added by j00350 for MPPD08948, 20140120 */

/* add by g00351, 2013-04-22 for 第三方license特性 */

/** @brief 推送消息中Manufacturer字段的uniview字符串 */
#define  IMOS_MANUFACTURER_UNIVIEW_SRT     "uniview"

/** @brief 推送消息中Manufacturer字段的h3c字符串 */
#define  IMOS_MANUFACTURER_H3C_SRT          "h3c"

/** @brief 推送消息中Manufacturer字段的other字符串 */
#define  IMOS_MANUFACTURER_OTHER_SRT     "other"

/** @brief 推送消息中Manufacturer字段的unknow字符串 */
#define  IMOS_MANUFACTURER_UNKNOW_SRT     "unknow"

/* begin added by suzhijie 00294 for NVRV3R1 20130410 */
#define IMOS_NVR_TOLLGATE_CAMERA_CODE        "specialCodeForPictureStore"
#define IMOS_NVR_EXPORT_VEDIO_TO_USB_HASH        "specialCodeExportVedioToUSB"
#define IMOS_NVR_EXPORT_PIC_TO_USB_HASH        "specialCodeExportPicToUSB"
#define IMOS_NVR_CAMERA_QUERY_USB_DISK         "cameraforqueryusbdisk"
#define IMOS_NVR_CAMERA_QUERY_USB_DIR           "cameraforqueryusbdir"
/* end added by suzhijie 00294 for NVRV3R1 20130410 */

/* Begin modified by j00350 for MPPD08948, 20140120 */
/* 判断是否是PAG设备，包括国标和ONVIF */
#define IMOS_IS_PAG(devCode) \
    ((0 == IMOS_strncmp(devCode, IMOS_DEFAULT_PAG_GB_CODE, IMOS_CODE_LEN)) || \
     (0 == IMOS_strncmp(devCode, IMOS_DEFAULT_PAG_IMOS_CODE, IMOS_CODE_LEN)) || \
     (0 == IMOS_strncmp(devCode, IMOS_DEFAULT_PAG_MOBILE_CODE, IMOS_CODE_LEN)))
/* End modified by j00350 for MPPD08948, 20140120 */


/**
* @enum tagIMOSPhyOutChnlWorkingMode
* @brief 物理输出通道的工作模式
* @attention
*/
typedef enum tagIMOSPhyOutChnlWorkingMode
{
    IMOS_PCWM_1_SPLIT   = 1,    /**< 1分屏 */
    IMOS_PCWM_4_SPLIT   = 4,    /**< 4分屏 */
    IMOS_PCWM_6_SPLIT   = 6,    /**< 6分屏 */
    IMOS_PCWM_8_SPLIT   = 8,    /**< 8分屏 */
    IMOS_PCWM_9_SPLIT   = 9,    /**< 9分屏 */
    IMOS_PCWM_10_SPLIT  = 10,   /**< 10分屏 */
    IMOS_PCWM_13_SPLIT  = 13,   /**< 13分屏 */
    IMOS_PCWM_16_SPLIT  = 16,   /**< 16分屏 */

    IMOS_PCWM_BUTT
} IMOS_PHY_OUT_CHNL_WORKING_MODE_E;

/** @brief 低温告警温度上限 - 最小 */
#define IMOS_LOW_TEMPERATURE_ALARM_MIN -100

/** @brief 低温告警温度上限 - 最大 */
#define IMOS_LOW_TEMPERATURE_ALARM_MAX 49

/** @brief 高温告警温度下限 - 最小 */
#define IMOS_HIGH_TEMPERATURE_ALARM_MIN 50

/** @brief 高温告警温度下限 - 最大 */
#define IMOS_HIGH_TEMPERATURE_ALARM_MAX 104

/* @brief 无效的域级别计数 */
#define IMOS_INVALID_DOMAIN_LEVEL (0xFFFF)

#define MAX_MMI_NUM_PER_SLOT                    8             /* added by lw0581, 2013.12.19 for  MPPD06992 */

/**
* @enum tagIMOSNatLevel
* @brief Nat级别
* @attention 无
*/
typedef enum tagIMOSNatLevel
{
    IMOS_NAT_LEVEL_LOWER = 1,                   /**< nat级别较低，即相比本域，被比较方在nat内 */
    IMOS_NAT_LEVEL_EQUAL = 2,                   /**< 同级别，即相比本域没有经过nat */
    IMOS_NAT_LEVEL_UPPER = 3,                   /**< nat级别较高，即相比本域，本域在nat内，被比较方在公网 */

    IMOS_NAT_LEVEL_INVALID = 0xFFFFFFFF         /**< 无效值 */
}IMOS_NAT_LEVEL_E;

/**
* @enum tagIMOSStorStatus
* @brief 存储状态
* @attention 无
*/
typedef enum tagIMOSStorStatus
{
    IMOS_STOR_ABNORMAL = 0,                         /**< 存储异常 */
    IMOS_STOR_NORMAL = 1,                           /**< 存储正常 */
    IMOS_STOR_UNALLOC_RES = 2,                      /**< 未配置存储资源 */

    IMOS_STOR_STATUS_INVALID = 0xFFFFFFFF           /**< 无效值 */
}IMOS_STOR_STATUS_E;

/**
* @enum tagIMOSDeviceRegProtocolType
* @brief 设备注册协议类型
* @attention
*/
typedef enum tagIMOSDeviceRegProtocolType
{
    DEVICE_REG_PROTOCOL_UNKNOWN = 0,
    DEVICE_REG_PROTOCOL_IMOS    = 1,
    DEVICE_REG_PROTOCOL_GB      = 2,

    DEVICE_REG_PROTOCOL_MAX,
    DEVICE_REG_PROTOCOL_INVALID = 0xFFFFFFFF

}IMOS_DEVICE_REG_PROTOCOL_TYPE_E;
/**
* @enum tagASSUBModeType
* @brief SUB模块角色枚举
* @attention 需要和DAO_DOMAIN_TYPE_E同步
*/
/*Added by y00104 for Alarm Optimization 2013-01-30*/
typedef enum tagASSUBModeType
{
    AS_SUB_DOMAIN_TYPE_REQUEST = 0,           /**< 订阅发起域 */
    AS_SUB_DOMAIN_TYPE_MID,                   /**< 订阅中间域 */
    AS_SUB_DOMAIN_TYPE_RESPOND,               /**< 订阅通知者 */

    AS_SUB_DOMAIN_TYPE_MAX,                   /**< 最大值 */
    AS_SUB_DOMAIN_TYPE_INVALID = 0xFF         /**< 无效值 */
}AS_SUB_DOMAIN_TYPE_E;

/*Begin added by zhangzeyao zKF0189,2013.8.22 查询设备相关信息 */
/**
*@enum tagDevieTypeForECR
*@brief 设备类型
*/
typedef enum tagDevieTypeForECR
{
    IMOS_EC1001_HF = 0,
    IMOS_EC1002_HD,
    IMOS_EC1004_HC,
    IMOS_EC2004_HF,
    IMOS_DC1001_FF = 7,
    IMOS_EC3016_HC,
    IMOS_ISC3100,
    IMOS_EC1001_EF = 10,
    IMOS_EC3004_HF,
    IMOS_EC3008_HD,
    IMOS_ER3316_HC_8CH,
    IMOS_ER3316_HC_4CH,
    IMOS_ER3308_HD_4CH,
    IMOS_ISC3000,

    IMOS_EC2016_HC = 200,
    IMOS_EC2016_HC_8CH = 201,
    IMOS_EC2016_HC_4CH = 202,
    IMOS_EC1501_HF = 203,

    IMOS_ECR3316_HC = 300,
    IMOS_ECR3316_HC_8CH,
    IMOS_ECR3316_HC_4CH,
    IMOS_ECR3308_HD,
    IMOS_ECR3308_HD_4CH,

    IMOS_DC2004_FF_R5 = 503,

    IMOS_EC1001 = 1000,
    IMOS_DC1001 = 1001,
    IMOS_EC1101_HF = 1002,
    IMOS_EC1102_HF = 1003,
    IMOS_EC1801_HH = 1004,
    IMOS_DC1801_FH = 1005,
    IMOS_ECR3308_HF = 1006,                  /* ECR3308-HF */
    IMOS_ECR3316_HF = 1007,                  /* ECR3316-HF */

    /* OEM产品型号 */
    IMOS_VR2004 = 10003,
    IMOS_VL2004 = 10503,
    IMOS_VR1102 = 11003,

    /* IPC产品型号 */
    IMOS_HIC5201 = 12001,
    IMOS_HIC5221 = 12002,
    IMOS_DEV_TYPE_BUTT
}DEVICE_TYPE_FOR_ECR_E;

/**
*@enum tagNetLinkModeForECR
*@brief 链路模式选择枚举
*/
typedef enum tagNetLinkModeForECR
{
    IMOS_NET_LINK_MODE_ELEC = 0,                  /* 链路选择电口 */
    IMOS_NET_LINK_MODE_RAY,                       /* 链路选择光口 */
    IMOS_NET_LINK_MODE_AUTO,                      /* 链路选择自适应 */
    IMOS_NET_LINK_MODE_BUTT
}NET_LINK_MODE_FOR_ECR_E;

/**
* @enum tagDevFansStatusForECR
* @brief  设备风扇状态
* @attention
*/
typedef enum tagDevFansStatusForECR
{
    IMOS_SPEED_LOW   = 0,
    IMOS_SPEED_HIGH  = 1,
    IMOS_SPEED_FAULT = 2,
    IMOS_SPEED_NULL  = 3,
    IMOS_FAN_TYPE_BUTT
}DEV_FANS_STATUS_FOR_ECR_E;

/**
*@enum tagIpGetTypeForECR
*@brief 获取ip地址类型
*/
typedef enum tagIpGetTypeForECR
{
    IMOS_IP_GET_STATICIP = 0,             /* 静态配置 */
    IMOS_IP_GET_PPPOE,                    /* pppoe模式 */
    IMOS_IP_GET_DHCP,                     /* 动态获取 */
    IMOS_IP_GET_UNP,                      /* UNP拨号方式获取 */
    IMOS_IP_GET_NULL,                     /* 没有配置 */
    IMOS_IP_GET_BUTT                      /* 其他模式 */
}IP_GET_TYPE_FOR_ECR_E;

/**
* @enum tagConnectStatusForECR
* @brief  连接状态 未连接后面的参数无意义
* @attention
*/
typedef enum tagConnectStatusForECR
{
    IMOS_NOT_CONNECTED         = 0,        /* 未连接 */
    IMOS_IS_CONNECTED           = 1,  /* 已连接 */
    IMOS_CONNECT_TYPE_BUTT
}CONNECTION_STATUS_FOR_ECR_E;

/**
*@enum tagETHSpeedForECR
*@brief 网口速率
*/
typedef enum tagETHSpeedForECR
{
    IMOS_ETH_SPEED_AUTO   = 0,                     /* 网口速率为自协商 */
    IMOS_ETH_SPEED_10M    = 1,                     /* 网口速率为10M */
    IMOS_ETH_SPEED_100M   = 2,                     /* 网口速率为100M */
    IMOS_ETH_SPEED_1000M  = 3,                     /* 网口速率为1000M */
    IMOS_ETH_SPEED_BUTT
}ETH_SPEED_FOR_ECR_E;

/**
*@enum tagETHDuplexForECR
*@brief 网口工作模式
*/
typedef enum tagETHDuplexForECR
{
    IMOS_ETH_DUPLEX_AUTO   = 0,                    /* 网口双工模式为自协商 */
    IMOS_ETH_DUPLEX_FULL   = 1,                    /* 网口双工模式为全双工 */
    IMOS_ETH_DUPLEX_HALF   = 2,                    /* 网口双工模式为半双工 */
    IMOS_ETH_DUPLEX_BUTT
}ETH_DUPLEX_FOR_ECR_E;

/*End:add by zhangzeyao zKF0189,2013.8.22 查询设备相关信息*/

/* Begin added by g00351,2013-09-09 of 支持区块OSD*/
/**
* @enum tagDevNewOsdType
* @brief 区块OSD类型
* @attention 无
*/
typedef enum tagDevNewOsdType
{
    DEV_NEW_OSD_WORD = 1,                   /**< 自定义(场名) */
    DEV_NEW_OSD_TIME = 2,                   /**< 时间 */
    DEV_NEW_OSD_PTZ_COORDINAT  = 3,         /**< 云台坐标 */
    DEV_NEW_OSD_MULTIPLE = 4,               /**< 变倍 */
    DEV_NEW_OSD_GUARDPOSITION = 5,          /**< 预置位 */
    DEV_NEW_OSD_SERIAL_INFO = 6,            /**< 串口信息 */

    DEV_NEW_OSD_MAX,
    DEV_NEW_OSD_PTZ_USER = 100,             /**< 云台用户，定义成较大值，避免IPC扩展OSD类型时出现冲突 */
    DEV_NEW_OSD_INVALID  = 0xFFFF           /**< 无效值 */

} DEV_NEW_OSD_TYPE_E;

/* End added by g00351,2013-09-09 of 支持区块OSD*/

/* Begin Added by shendongchun 2014-02-26 for 大数据数据库管理服务器 */
/**
* @struct tagDRType
* @brief DR类型枚举
* @attention 无
*/
typedef enum tagDRType
{
    DR8500_M = 0,                                  /**< DR8500主服务器 */
    DR8500_N = 1,                                  /**< DR8500非主服务器 */
    DR9500_M = 2,                                  /**< DR9500主服务器 */
    DR9500_N = 3,                                  /**< DR9500非主服务器 */
    DR_MAX,                                    /**< DR服务器类型最大值 */
    DR_INVALID = 0XFFFFFFFF                    /**< DR服务器类型无效值 */
} DR_TYPE_E;
/* End Added by shendongchun 2014-02-26 for 大数据数据库管理服务器 */

/**
* @struct tagTMSSubType
* @brief TMS子类型枚举
* @attention 无
*/
typedef enum tagTMSSubType
{
    TMS8500_SUB_TYPE = 0,                                   /**< TMS8500服务器 */
    TMS9500_SUB_TYPE = 2,                                   /**< TMS9500服务器 */

    TMS_SUB_TYPE_MAX,                                       /**< TMS子类型最大值 */
    TMS_SUB_TYPE_INVALID = 0XFFFFFFFF                       /**< TMS子类型无效值 */
} TMS_SUB_TYPE_E;

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_DEF_H_ */

