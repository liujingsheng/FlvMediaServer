/************************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
-------------------------------------------------------------------------------------
                              sdk_struct.h

  Project Code: SDK
   Module Name: SDK
  Date Created: 2009-02-27
        Author: yangbin (07022)
                sunyifan (s06966)
                zhuyi (KF1397)
   Description: 数据结构定义文档

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_SDK_STRUCT_H_
#define _IMOS_SDK_STRUCT_H_

#ifdef  __cplusplus
extern "C"{
#endif

/***************************************************************************
公用结构
****************************************************************************/

/***************************用户登录后，针对操作时携带的信息******************/
#include "sdk_def.h"
/**
 * @struct tagUserLoginIDInfo
 * @brief 用户登录ID信息结构
 * @attention
 */
typedef struct tagUserLoginIDInfo
{
    /** 用户编码 */
    CHAR szUserCode[IMOS_USER_CODE_LEN];

    /** 用户登录ID，是用户登录后服务器分配的，它是标记一次用户登录的唯一标识 */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

    /** 用户登录的客户端IP地址 */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

} USER_LOGIN_ID_INFO_S;


/************************************时间结构*****************************/

/***********************普通的时间结构，以业务为中心，提供整体时间计划***************************************/



/**
 * @struct tagTimeSlice
 * @brief 基本时间片信息
 * @attention 00:00:00~23:59:59表示一整天的时间片
 */
typedef struct tagTimeSlice
{
    /** 开始时间 格式为"hh:mm:ss"或"YYYY-MM-DD hh:mm:ss", 视使用情况而定 */
    CHAR        szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 格式为"hh:mm:ss"或"YYYY-MM-DD hh:mm:ss", 视使用情况而定 */
    CHAR        szEndTime[IMOS_TIME_LEN];

}TIME_SLICE_S;


/**
 * @struct tagTimeSliceInfo
 * @brief 时间片信息
 * @attention
 */
typedef struct tagTimeSliceInfo
{
    /** 基本时间片信息 */
    TIME_SLICE_S    stTimeSlice;

}TIME_SLICE_INFO_S;

/**
 * @struct tagPlanWeekTime
 * @brief 计划时间信息
 * @attention
 */
typedef struct tagPlanWeekTime
{
    /** 周几 */
    ULONG_32       ulWeekDay;

    /** 时间信息, 其中的开始时间和结束时间格式为"hh:mm:ss" */
    TIME_SLICE_INFO_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];

}PLAN_WEEKTIME_S;


/**
 * @struct tagPlanExtTime
 * @brief 计划例外时间信息, 在配置例外计划时间时使用. 例外计划是在正常计划的基础上配置的特殊执行计划.
 * @attention
 */
typedef struct tagPlanExtTime
{
    /** 例外日期索引, 取值为0~6: 0表示周日, 1~6表示周一至周六 */
    ULONG_32       ulDateIndex;

    /** 具体日期, 格式为"YYYY-MM-DD" */
    CHAR        szExtDate[IMOS_SIMPLE_DATE_LEN];

    /** 时间片数组中时间片的实际数量 */
    ULONG_32       ulTimeSliceNum;

    /** 时间片数组, 其中的开始时间和结束时间的格式为"hh:mm:ss" */
    TIME_SLICE_INFO_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];
}PLAN_EXTTIME_S;

/**
 * @struct tagPlanTime
 * @brief 计划时间信息结构
 * @attention
 */
typedef struct tagPlanTime
{
    /** 周时间计划 */
    PLAN_WEEKTIME_S astPlanTime[IMOS_WEEK_DAYS];

    /** 例外时间数组中例外时间的实际数量, 最大取值为#IMOS_EXCP_DAYS */
    ULONG_32       ulPlanExtTimeNum;

    /** 例外时间数组 */
    PLAN_EXTTIME_S astPlanExtTime[IMOS_EXCP_DAYS];

}PLAN_TIME_S;


/*******************以业务和时间段为中心，每个时间段配置相同业务的不同资源***************************************/

/**
 * @struct tagTimeSliceForRes
 * @brief 包含资源编码和资源名称的时间片信息
 * @attention
 */
typedef struct tagTimeSliceForRes
{
    /** 该时间段的资源编码 */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** 该时间段的资源名称 */
    CHAR        szResName[IMOS_NAME_LEN];

    /** 时间片信息, 其中的开始时间和结束时间的格式为"hh:mm:ss" */
    TIME_SLICE_S    stTimeSlice;

}TIME_SLICE_FOR_RES_S;


/**
 * @struct tagPlanWeekTimeForRes
 * @brief 周时间计划信息
 * @attention
 */
typedef struct tagPlanWeekTimeForRes
{
    /** 周几, 0表示周日, 1~6表示周一到周六 */
    ULONG_32       ulWeekDay;

    /** 时间信息 */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];

}PLAN_WEEKTIME_FOR_RES_S;


/**
 * @struct tagPlanExtTimeForRes
 * @brief 例外时间信息
 * @attention
 */
typedef struct tagPlanExtTimeForRes
{
    /** 例外日期 格式为"YYYY-MM-DD" */
    CHAR        szExtDate[IMOS_TIME_LEN];

    /** 例外时间片数组中例外时间片的实际个数 */
    ULONG_32       ulTimeSliceNum;

    /** 例外时间片数组 */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];
}PLAN_EXTTIME_FOR_RES_S;

/**
 * @struct tagPlanTimeForRes
 * @brief 计划时间信息
 * @attention
 */
typedef struct tagPlanTimeForRes
{
    /** 周时间计划 */
    PLAN_WEEKTIME_FOR_RES_S astPlanTime[IMOS_WEEK_DAYS];

    /** 例外时间计划数组中实际的例外时间计划个数, 最大取值为#IMOS_EXCP_DAYS */
    ULONG_32       ulPlanExtTimeNum;

    /** 例外时间计划数组 */
    PLAN_EXTTIME_FOR_RES_S  astPlanExtTime[IMOS_EXCP_DAYS];

}PLAN_TIME_FOR_RES_S;

#if 0
/**
 * @struct tagPlanWeekTimeForRes
 * @brief 周时间计划信息
 * @attention
 */
typedef struct tagTimeSliceForResV2
{
    /* 是否为周几的标志。如果为BOOL_FALSE，则使用字符串的具体时间 */
    ULONG_32 bWeekDayFlag;

    /** 时间段执行日 \n
     * 对于周计划，为周几 \n
     * 对于天计划，无意义 */
    ULONG_32       ulPlanDay;

    /** 时间段执行日，格式为"YYYY-MM-DD" */
    CHAR        szPlanDay[IMOS_SIMPLE_DATE_LEN];

    /** 时间段索引，标志是当天的第几个时间段 */
    ULONG_32       ulTimeIndex;

    /** 开始时间，格式为"HH:MM:SS" */
    CHAR        szStartTime[IMOS_SIMPLE_TIME_LEN];

    /** 结束时间，格式为"HH:MM:SS" */
    CHAR        szEndTime[IMOS_SIMPLE_TIME_LEN];

    /** 时间段参数 */
    CHAR        szParam[IMOS_STRING_LEN_256];

}TIME_SLICE_FOR_RES_V2_S;

/**
 * @struct tagPlanTimeForResV2
 * @brief 计划时间信息V2版
 * @attention
 */
typedef struct tagPlanTimeForResV2
{
    /** 时间计划个数, 最大取值为# */
    ULONG_32       ulPlanTimeNum;

    /** 例外时间计划数组 */
    TIME_SLICE_FOR_RES_V2_S  astPlanTime[1];

}PLAN_TIME_FOR_RES_V2_S;
#endif

/**
 * @struct tagTimeSliceForRes
 * @brief 包含资源编码和资源名称的时间片信息
 * @attention
 */
typedef struct tagTimeSliceForResV2
{
    /** 该时间段的资源编码 */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** 该时间段的资源名称 */
    CHAR        szResName[IMOS_NAME_LEN];

    /** 时间片信息, 其中的开始时间和结束时间的格式为"hh:mm:ss" */
    TIME_SLICE_S    stTimeSlice;

}TIME_SLICE_FOR_RES_V2_S;


/**
 * @struct tagPlanWeekTimeForRes
 * @brief 周时间计划信息
 * @attention
 */
typedef struct tagPlanWeekTimeForResV2
{
    /** 周几, 0表示周日, 1~6表示周一到周六 */
    ULONG_32       ulWeekDay;

    /** 时间片的实际个数 */
    ULONG_32       ulTimeSliceNum;

    /** 时间信息 */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM_V2];

}PLAN_WEEKTIME_FOR_RES_V2_S;


/**
 * @struct tagPlanExtTimeForRes
 * @brief 例外时间信息
 * @attention
 */
typedef struct tagPlanExtTimeForResV2
{
    /** 例外日期 格式为"YYYY-MM-DD" */
    CHAR        szExtDate[IMOS_TIME_LEN];

    /** 例外时间片数组中例外时间片的实际个数 */
    ULONG_32       ulTimeSliceNum;

    /** 例外时间片数组 */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM_V2];
}PLAN_EXTTIME_FOR_RES_V2_S;

/**
 * @struct tagPlanTimeForRes
 * @brief 计划时间信息
 * @attention
 */
typedef struct tagPlanTimeForRes_V2
{
    /** 周时间计划 */
    PLAN_WEEKTIME_FOR_RES_V2_S astPlanTime[IMOS_WEEK_DAYS];

    /** 例外时间计划数组中实际的例外时间计划个数, 最大取值为#IMOS_EXCP_DAYS */
    ULONG_32       ulPlanExtTimeNum;

    /** 例外时间计划数组 */
    PLAN_EXTTIME_FOR_RES_V2_S  astPlanExtTime[IMOS_EXCP_DAYS];

}PLAN_TIME_FOR_RES_V2_S;



/*******************************上传下载公用信息***************************************/

/**
 * @struct tagFileBasicInfo
 * @brief 文件基本信息
 * @attention
 */
typedef struct tagFileBasicInfo
{
    /** 文件名称, 该名称由用户命名, 用于标识该文件 */
    CHAR            szName[IMOS_NAME_LEN];

    /** 文件的实际名称, 该名称即文件在文件系统中的名称 */
    CHAR            szFileName[IMOS_FILE_NAME_LEN];

    /** 文件上传时间，用于比对客户端文件是否是最新的文件 */
    CHAR            szUploadTime[IMOS_TIME_LEN];
}FILE_BASIC_INFO_S;

/**
 * @struct tagLayerBasicInfo
 * @brief 文件基本信息
 * @attention
 */
typedef struct tagLayerBasicInfo
{
    /** 文件的实际名称, 该名称即文件在文件系统中的名称 */
    CHAR            szLayerName[IMOS_NAME_LEN];

    /** 文件上传时间，用于比对客户端文件是否是最新的文件 */
    CHAR            szUploadTime[IMOS_TIME_LEN];
}LAYER_BASIC_INFO_S;

/**
 * @struct tagFtpInfo
 * @brief FTP服务信息
 * @attention
 */
typedef struct tagFtpInfo
{
    /** FTP用户名 */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** FTP密码 */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** FTP服务器存放文件路径，以形如"/Program_Files/H3C/IMOS"的方式表示 */
    CHAR    szFtpFilePath[IMOS_FILE_PATH_LEN];
}FTP_INFO_S;

/**
 * @struct tagFileOnServerInfo
 * @brief 文件在FTP服务器上的有关信息
 * @attention
 */
typedef struct tagFileOnServerInfo
{
    /** 文件名称，文件实际保存的名字 */
    CHAR            szFileName[IMOS_FILE_PATH_LEN];

    /** FTP服务信息 */
    FTP_INFO_S  stFtpInfo;
}FILE_ON_SERVER_INFO_S;


/*********************************查询条件**********************************/
/**
 * @struct tagQueryPageInfo
 * @brief 分页请求信息
 * @brief 待查询数据的每条数据项对应一个序号。序号从1开始，连续增加。
 * - 查询到的结果以页的形式返回，每次查询只能返回一页。页包含的行数由ulPageRowNum设定，范围为1~200。
 * - 每次查询，可设置从待查询数据中特定序号（ulPageFirstRowNumber）开始
 * @attention
 */
typedef struct tagQueryPageInfo
{
    /** 分页查询中每页的最大条目数, 不能为0, 也不能大于#IMOS_PAGE_QUERY_ROW_MAX_NUM */
    ULONG_32 ulPageRowNum;

    /** 分页查询中第一条数据的序号(即查询从第ulPageFirstRowNumber条数据开始的符合条件的数据), 取值符合ULONG类型的范围即可 */
    ULONG_32 ulPageFirstRowNumber;

    /** 是否查询条目总数, BOOL_TRUE时查询; BOOL_FALSE时不查询 */
    BOOL_T bQueryCount;
}QUERY_PAGE_INFO_S;


/**
 * @struct tagRspPageInfo
 * @brief 分页响应信息
 * @attention
 */
typedef struct tagRspPageInfo
{
    /** 实际返回的条目数 */
    ULONG_32 ulRowNum;

    /** 符合条件的总条目数 */
    ULONG_32 ulTotalRowNum;
}RSP_PAGE_INFO_S;

/**
 * @struct tagRecRspRowInfo
 * @brief  统一录像检索响应信息
 * @attention
 */
typedef struct tagRecRspRowInfo
{
    /** 实际返回的录像段数目 */
    ULONG_32 ulRowNum;

    /** 是否还有数据 */
    ULONG_32 bHasMoreRow;

    /** 本轮录像的总结束时间 */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 保留字段 */
    CHAR  szReserve[32];
}REC_RSP_ROW_INFO_S;

/**
 * @struct tagQueryConditionInfo
 * @brief 计划类查询条件，按名称，按时间查询。
 * @attention
 */
typedef struct tagQueryConditionInfo
{
    /** 名称枚举标记位:#NAME_CODE_FLAG_E */
    ULONG_32   ulNameCodeFlag;

    /** 搜索的模式:#SEARCH_MODE_E */
    ULONG_32   ulSearchMode;

    /** 设备名称或资源名称 */
    CHAR    szNameCode[IMOS_NAME_LEN];

    /** 时间枚举标记位:#TIME_FLAG_E */
    ULONG_32   ulTimeFlag;

    /** 时间段信息, 其中开始时间和结束时间的格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stTimeSlice;

} QUERY_CONDITION_INFO_S;


/**
 * @struct tagQueryByName
 * @brief 按名称进行模糊查询。
 * @attention
 */
typedef struct tagQueryByName
{
    /** 设备名称或资源名称 */
    CHAR    szName[IMOS_NAME_LEN];
} QUERY_BY_NAME_S;


/***************************************************************************************
音频输入管理
***********************************************************************************/


#if 0 /** 音频 */
#endif
/**
 * @struct tagAudioInput
 * @brief 音频输入通道信息
 * @attention
 */
typedef struct tagAudioInput
{
    /** 是否使能 0/1:不使能/使能 */
    ULONG_32       ulAudioEnabled;

    /** 音频编码，取值范围为 #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** 音频声道，取值范围为 #IMOS_AUDIO_CHANNEL_TYPE_E  */
    ULONG_32       ulTrack;

    /** 采样率，取值范围为 #IMOS_AUDIO_SAMPLING_E */
    ULONG_32       ulSamplingRate;

    /** 码率 */
    ULONG_32       ulEncodeRate;

    /** 输入增益值，取值范围为0-255，默认0  */
    ULONG_32       ulIncrement;

    /** 音频输入描述 */
    CHAR        szDesc[IMOS_DESC_LEN];

}AUDIO_INPUT_INFO_S;



/**
 * @struct tagAudioOutput
 * @brief 音频输出通道信息
 * @attention
 */
typedef struct tagAudioOutput
{
    /** 使能标识 */
    ULONG_32       ulAudioEnabled;

    /** 音频编码，取值范围为 #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** 音频声道，取值范围为 #IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32       ulTrack;

    /** 音量值 */
    ULONG_32       ulVolume;

    /** 音频输出描述 */
    CHAR        szDesc[IMOS_DESC_LEN];

}AUDIO_OUTPUT_INFO_S;

/************************************************************************************
用户登录
*************************************************************************************/
#if 0
/**
* @struct  tagLoginInfo
* @brief 用户登录消息结构体
* @attention 无
*/
typedef struct tagLoginInfo
{
    /** 用户登录信息 */
    USER_LOGIN_ID_INFO_S    stUserLoginIDInfo;

    /** 用户所属组织编码 */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 用户所属域名称 */
    CHAR szDomainName[IMOS_NAME_LEN];

    /** 用户所属域类型 */
    ULONG_32 ulDomainType;

    /** XP编码 */
    CHAR szXpCode[IMOS_DEVICE_CODE_LEN];

    /** XP第一窗格编码 */
    CHAR szXpFirstWndCode[IMOS_RES_CODE_LEN];

    /** 语音对讲编码 */
    CHAR szVoiceTalkCode[IMOS_RES_CODE_LEN];

    /** 语音广播编码 */
    CHAR szVoiceBroadcastCode[IMOS_RES_CODE_LEN];

    /** SIP通信地址类型，值为:IMOS_IPADDR_TYPE_IPV4/IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32 ulSipAddrType;

    /** SIP服务器通信IP地址，仅在使用XP的时候有效 */
    CHAR szSipIpAddress[IMOS_IPADDR_LEN];

    /** SIP服务器通信端口号 */
    ULONG_32 ulSipPort;

    /** 本域服务器编码 */
    CHAR szServerCode[IMOS_DEVICE_CODE_LEN];
}LOGIN_INFO_S;

#endif

/**
* @struct tagLoginInfo
* @brief 用户登录信息结构体
* @attention 无
*/
typedef struct tagLoginInfo
{
    /** 用户登录ID信息 */
    USER_LOGIN_ID_INFO_S    stUserLoginIDInfo;

    /** 用户所属组织编码 */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 用户所属域名称 */
    CHAR szDomainName[IMOS_NAME_LEN];

    /** 用户所属域类型, 取值为#MM_DOMAIN_SUBTYPE_LOCAL_PHYSICAL和#MM_DOMAIN_SUBTYPE_LOCAL_VIRTUAL */
    ULONG_32 ulDomainType;
}LOGIN_INFO_S;

/**
* @struct tagXpInfo
* @brief XP信息结构体
* @attention 无
*/
typedef struct tagXpInfo
{
    /** XP编码 */
    CHAR szXpCode[IMOS_DEVICE_CODE_LEN];

    /** 屏号 */
    ULONG_32 ulScreenIndex;

    /** XP第一窗格编码 */
    CHAR szXpFirstWndCode[IMOS_RES_CODE_LEN] ;

    /** 语音对讲编码 */
    CHAR szVoiceTalkCode[IMOS_RES_CODE_LEN] ;

    /** 语音广播编码 */
    CHAR szVoiceBroadcastCode[IMOS_RES_CODE_LEN] ;

    /** SIP通信地址类型，#IMOS_IPADDR_TYPE_IPV4为IPv4类型; #IMOS_IPADDR_TYPE_IPV6为IPv6类型 */
    ULONG_32 ulSipAddrType ;

    /** SIP服务器通信IP地址，仅在使用XP的时候有效 */
    CHAR szSipIpAddress[IMOS_IPADDR_LEN] ;

    /** SIP服务器通信端口号 */
    ULONG_32 ulSipPort;

    /** 本域服务器编码 */
    CHAR szServerCode[IMOS_DEVICE_CODE_LEN] ;

} XP_INFO_S;

/**
 * @struct tagXpStreamInfo
 * @brief XP实时监控流信息结构
 * @attention
 */
typedef struct tagXpStreamInfo
{
    /** 支持的单组播类型，0为仅支持单播，1为既支持单播也支持组播 */
    ULONG_32 ulStreamType;

    /** 支持的流传输协议 参见#IMOS_TRANS_TYPE_E。目前XP只支持自适应和TCP */
    ULONG_32 ulStreamTransProtocol;

    /** 支持的流传输方式 参见#IMOS_STREAM_SERVER_MODE_E。目前XP只支持自适应和直连优先 */
    ULONG_32 ulStreamServerMode;

    /* Begin ModifyBy liuhongjieKF0170,2013-10-22 of 语音对讲经MS */
    /** 支持的语音对讲传输方式 参见#IMOS_STREAM_SERVER_MODE_E。目前XP只支持自适应和不经过MS */
    ULONG_32 ulVoiceCommMode;

    /** 保留字段 */
    CHAR  szReserve[28];
    /* End ModifyBy liuhongjieKF0170,2013-10-22 of 语音对讲经MS */
}XP_STREAM_INFO_S;

/**
* @struct tagUserLoginIDInfo
* @brief 播放器窗格信息结构体
* @attention
*/
typedef struct tagPlayWndInfo
{
    /** 播放窗格资源编码 */
    CHAR szPlayWndCode[IMOS_RES_CODE_LEN];
}PLAY_WND_INFO_S;

/************************************************************************************
角色
*************************************************************************************/
/**
 * @struct tagUserRoleInfo
 * @brief 角色详细信息
 * @attention
 */
typedef struct tagUserRoleInfo
{
    /** 角色名称 */
    CHAR        szRoleName[IMOS_NAME_LEN];

    /** 角色优先级，取值范围为1-9，1的优先级最高，9的优先级最低 */
    ULONG_32       ulRolePriority;

    /** 角色描述，可以不填 */
    CHAR        szRoleDesc[IMOS_DESC_LEN];

    /** 角色所属组织域编码 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 角色类型，在添加本域角色时该值为1 */
    ULONG_32       ulRoleType;

    /** 扩展信息，用户保留字段，可以不填 */
    CHAR        szExternInfo[IMOS_STRING_LEN_32];
}USER_ROLE_INFO_S;

/**
 * @struct tagRoleNameQueryItem
 * @brief 角色编码、名称信息项，可以通过此信息，获得角色的具体信息
 * @attention
 */
typedef struct tagRoleNameQueryItem
{
    /** 角色名称 */
    CHAR        szRoleName[IMOS_NAME_LEN];

    /** 角色编码，角色的唯一标识 */
    CHAR        szRoleCode[IMOS_RES_CODE_LEN];
}ROLE_NAME_QUERY_ITEM_S;

/**
 * @struct tagRoleQueryItem
 * @brief 角色信息项(查询角色列表时返回)
 * @attention
 */
typedef struct tagRoleQueryItem
{
    /** 角色编码、名称信息 */
    ROLE_NAME_QUERY_ITEM_S  stRoleIndexItem;

    /** 角色优先级，取值范围为1-9，1的优先级最高，9的优先级最低 */
    ULONG_32                       ulRolePriority;

    /** 角色描述 */
    CHAR                        szRoleDesc[IMOS_DESC_LEN];

    /** 角色所属组织名称 */
    CHAR                        szOrgName[IMOS_NAME_LEN];

    /** 角色所属组织编码 */
    CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN];
}ROLE_QUERY_ITEM_S;

/**
* @struct tagAuthorityItem
* @brief 普通权限信息
* @attention 无
*/
typedef struct tagAuthorityItem
{
    /** 权限名字（每个取值唯一代表一种权限类型），由产品设定权限时确定 */
    ULONG_32 ulAuthorityName;

    /** 是否具备权限名字对应的权限, BOOL_TRUE为具有该权限, BOOL_FALSE为不具有该权限 */
    BOOL_T bHasAuthority;

} AUTHORITY_ITEM_S;

/**
* @struct tagOrgAuthority
* @brief 组织域的权限信息
* @attention 无
*/
typedef struct tagOrgAuthority
{
    /** 权限信息数组 */
    AUTHORITY_ITEM_S astAuthorities[IMOS_AUTHORITY_MAX_NUM];

    /** 权限信息数组中实际的权限信息个数, 可取的最大值为#IMOS_AUTHORITY_MAX_NUM */
    ULONG_32 ulAuthCount;

} ORG_AUTHORITY_S;

/**
* @struct tagOrgAuthorityV2
* @brief 组织域的权限信息
* @attention 无
*/
typedef struct tagOrgAuthorityV2
{
    /** 权限信息数组 */
    AUTHORITY_ITEM_S astAuthorities[IMOS_AUTHORITY_MAX_NUM_EX];

    /** 权限信息数组中实际的权限信息个数, 可取的最大值为#IMOS_AUTHORITY_MAX_NUM_EX */
    ULONG_32 ulAuthCount;

} ORG_AUTHORITY_V2_S;




/**
 * @struct tagQueryRoleConditionInfo
 * @brief 查询域下的角色列表
 * @attention ROLE_ORDER_INFO_S需要UI提供
*/
typedef struct tagQueryRoleConditionInfo
{
    /** 组织域编码 */
    CHAR    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 角色名称 */
    CHAR    szRoleName[IMOS_NAME_LEN];

}QUERY_ROLE_CONDITION_INFO_S;

/**
* @struct tagResAuthority
* @brief 资源的权限信息
* @attention 无
*/
typedef struct tagResAuthority
{
    /** 权限列表 */
    ORG_AUTHORITY_V2_S  stAuthorities;

    /** 资源ID编码,全局权限为字符串"0" */
    CHAR            szResIdCode[IMOS_CODE_LEN];

} RES_AUTHORITY_S;

/**
* @struct tagResInfo
* @brief 资源信息
* @attention 无
*/
typedef struct tagResInfo
{
    /** 资源ID，字符串"0"表示系统 */
    CHAR    szResIdCode[IMOS_CODE_LEN];

    /** 资源编码 */
    CHAR    szResCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR    szResName[IMOS_NAME_LEN];

    /** 资源类型，取值范围为#IMOS_TYPE_E */
    ULONG_32   ulResType;

    /** 资源子类型,目前资源子类型只对摄像机/组织/组显示/组轮巡有效，对摄像机而言为云台/非云台;
        对组织而言为:1-本物理域，2-本域的虚拟域，3-外域的虚拟域. 4-上级外物理域.
        5-下级外物理域.6-平级外物理域.
        对组显示资源代表组显示类型，取值为#SALVO_TYPE_E
        对组轮巡资源代表组轮巡类型，取值为#GROUP_SWITCH_TYPE_E */
    ULONG_32   ulResSubType;

    /** 所属组织编码 */
    CHAR        szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称 */
    CHAR        szOrgName[IMOS_NAME_LEN];

} RES_INFO_S;

/**
* @struct tagResAuthorityQueryItem
* @brief 资源的权限列表
* @attention 无
*/
typedef struct tagResAuthorityQueryItem
{
    /** 权限列表 */

    ORG_AUTHORITY_V2_S stAuthorities;

    /** 资源信息 */
    RES_INFO_S stResInfo;
} RES_AUTHORITY_QUERY_ITEM_S;


/***************************************************************************************
用户管理
***********************************************************************************/

/**
 * @struct tagUserInfo
 * @brief 用户信息
 * @attention
 */
typedef struct tagUserInfo
{

    /** 用户编码，用户的唯一标识 */
    CHAR szUserCode[IMOS_USER_CODE_LEN];

    /** 用户登录名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户全名，可以不填 */
    CHAR szUserFullName[IMOS_NAME_LEN];

    /** 用户所属组织域名字 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** 用户座机电话号码，可以不填 */
    CHAR    szTelePhone[IMOS_PHONE_LEN];

    /** 用户移动电话号码，可以不填 */
    CHAR    szMobilePhone[IMOS_MOBILE_LEN];

    /** 用户传真号码，可以不填 */
    CHAR    szFax[IMOS_PHONE_LEN];

    /** 用户电子邮件，可以不填 */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** 用户密码是否长期有效标识, 1为长期有效; 0为非长期有效, 目前该字段保留 */
    ULONG_32   ulPasswdPermanetFlag;

    /** 用户密码生效日期, 目前该字段保留, 可以不填 */
    CHAR    szPasswdValidDate[IMOS_TIME_LEN];

    /** 用户密码有效天数, 目前该字段保留 */
    ULONG_32   ulPasswdValidDays;

    /** 用户密码是否有效, 1为有效; 0为无效 */
    ULONG_32   ulPasswdValidFlag;

    /** 用户是否被锁定, 1为被锁定; 0为未被锁定 */
    ULONG_32   ulUserLockFlag;

    /** 用户类型, 目前固定为#MM_USER_TYPE_LOCAL_DOMAIN */
    ULONG_32   ulUserType;

    /** 用户描述，可以不填 */
    CHAR    szUserDes[IMOS_DESC_LEN];

    /** 用户扩展信息，可以不填 */
    CHAR    szReserve[96];
}USER_INFO_S;



/**
 * @struct tagUserPasswordInfo
 * @brief 用户信息(包含用户登录密码)
 * @attention
 */
typedef struct tagUserPasswordInfo
{
    /** 用户信息 */
    USER_INFO_S   stUserInfo;

    /** 用户登录密码,可以为空 */
    CHAR    szPassword[IMOS_PASSWD_ENCRYPT_LEN];
}USER_INFO_PASSWORD_S;


/**
 * @struct  tagUserModifyPassword
 * @brief 用户密码信息
 * @attention
 */
typedef struct tagUserModifyPassword
{
    /** 用户登录名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户旧密码 */
    CHAR    szOldPassword[IMOS_PASSWD_ENCRYPT_LEN];

    /** 用户新密码 */
    CHAR    szNewPassword[IMOS_PASSWD_ENCRYPT_LEN];
}USER_MODIFY_PASSWORD_S;


/**
 * @struct  tagUserQueryItem
 * @brief 用户信息项(查询用户列表时返回)
 * @attention
 */
typedef struct tagUserQueryItem
{
    /** 用户编码 */
    CHAR szUserCode[IMOS_USER_CODE_LEN];

    /** 用户登录ID(由内部生成)，是一次用户登录的唯一标识 */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

    /** 用户登录名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户全名 */
    CHAR szUserFullName[IMOS_NAME_LEN];

    /** 用户所属组织域名字 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** 用户座机电话号码 */
    CHAR    szTelePhone[IMOS_PHONE_LEN];

    /** 用户移动电话号码 */
    CHAR    szMobilePhone[IMOS_MOBILE_LEN];

    /** 用户电子邮件 */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** 用户是否被锁定, 1为锁定; 2为未锁定 */
    ULONG_32   ulUserLockFlag;

    /** 用户登录的客户端地址 */
    CHAR szUserAddr[IMOS_IPADDR_LEN];

    /** 用户扩展信息 */
    CHAR    szExternInfo[IMOS_STRING_LEN_32];

    /** 用户登录时间 */
    CHAR  szUserLoginTime[IMOS_TIME_LEN];

} USER_QUERY_ITEM_S;

/**
 * @struct  tagUserQueryItemV2
 * @brief 用户信息项(查询用户列表V2接口时返回, 扩展返回"用户所属组织的编码")
 * @attention
 */
typedef struct tagUserQueryItemV2
{
    /** V1用户信息项 */
    USER_QUERY_ITEM_S stUserItemInfoV1;

    /** 用户所属组织域编码 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 保留字段 */
    CHAR szReserve[192];
}USER_QUERY_ITEM_V2_S;

/***************************************************************************************
组织，本域，外域管理
***********************************************************************************/

/**
 * @struct tagOrgBasicInfo
 * @brief 组织节点基本信息
 * @attention
 */
typedef struct tagOrgBasicInfo
{
     /** 组织节点编码 */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 组织节点名称 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** 父(上级)组织节点编码 */
    CHAR szOrgParentCode[IMOS_DOMAIN_CODE_LEN];

    /** 组织节点类型 ,取值为 #MM_DOMAINTYPE_E */
    ULONG_32 ulOrgType;

    /** 组织节点是否是本域的, 1为是本域的; 0为不是本域的 */
    ULONG_32 ulIsLocalDomain;

    /** 组织节点描述,可以不填 */
    CHAR szOrgDesc[IMOS_DESC_LEN];

    /** 扩展信息, 可以不填 */
    CHAR szUserInfo[IMOS_STRING_LEN_256];
}ORG_BASIC_S;



/**
 * @struct tagOrgContactInfo
 * @brief 组织节点联系方式信息
 * @attention
 */
typedef struct tagOrgContactInfo
{
    /** 联系人，可以不填 */
    CHAR szOrgContszt[IMOS_NAME_LEN];

    /** 移动电话号码，可以不填 */
    CHAR szOrgMobile[IMOS_MOBILE_LEN];

    /** 联系地址，可以不填 */
    CHAR szOrgAddr[IMOS_STRING_LEN_256];

    /** 传真号码，可以不填 */
    CHAR szOrgFax[IMOS_PHONE_LEN];

    /** 座机号码，可以不填 */
    CHAR szOrgTel[IMOS_PHONE_LEN];

    /** 电子邮件，可以不填 */
    CHAR szOrgEmail[IMOS_MAIL_LEN];

    /** 邮政编码，可以不填 */
    CHAR szOrgPostalCode[IMOS_MAIL_CODE_LEN];
}ORG_CONTACT_INFO_S;



/**
 * @struct tagOrgNodeInfo
 * @brief 组织域节点信息（组织公共信息+联系方式信息）
 * @attention
 */
typedef struct tagOrgNodeInfo
{
    /** 组织节点基本信息 */
    ORG_BASIC_S         stOrgBasicInfo;

    /** 组织节点联系方式信息 */
    ORG_CONTACT_INFO_S  stOrgContactInfo;

}ORG_NODE_INFO_S;



/**
 * @struct tagAuthorizationInfo
 * @brief 权签信息
 * @attention
 */
typedef struct tagAuthorizationInfo
{
    /** 用户名 */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** 密码 */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** 域名 */
    CHAR    szRealm[IMOS_STRING_LEN_64];

}AUTHORIZATION_INFO_S;

/**
 * @struct tagExDomain
 * @brief 外物理域信息
 * @attention
 */
typedef struct tagExDomain
{
    /** 外域编码, 外域唯一标识 */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 外域名称 */
    CHAR    szDomainName[IMOS_NAME_LEN];

    /** 外域类型(上级域/下级域/平级域), 取值为#EX_DOMAIN_TYPE_E */
    ULONG_32   ulOuterDomainType;

    /** 父域节点编码。如果无父节点，则填空串 */
    CHAR    szDomainParentCode[IMOS_DOMAIN_CODE_LEN];

    /** 外域优先级，取值范围为1-9，1的优先级最高，9的优先级最低 */
    ULONG_32   ulPriority;

    /** 引流标记位，取值为#DOMAIN_STREAM_PULL_TYPE  */
    ULONG_32   ulIsSession;

    /** SIP端口，H3C域为5061，其他厂商按需配置 */
    ULONG_32   ulOuterDomainPort;

    /** 域间组播支持策略. 1为支持; 0为不支持, 不可配置 */
    ULONG_32   ulBroadcastStrategy;

    /** 外域地址类型，1-IPv4 2-IPv6 */
    ULONG_32   uladdrtype;

    /** 外域地址 */
    CHAR    szDomainAddr[IMOS_IPADDR_LEN];

     /** 输入干线数量, 取值范围为0~9999 */
    ULONG_32 ulInTrunkNum;

    /** 厂商类型
        对于非OEM版本(VM8500等H3C设备),取值为
            #IMOS_MANUFACTURER_TYPE_VMISC
            #IMOS_MANUFACTURER_TYPE_DA
            #IMOS_MANUFACTURER_TYPE_OTHER
        对于OEM版本(PL/PL-S),取值为
            #IMOS_MANUFACTURER_TYPE_PL
            #IMOS_MANUFACTURER_TYPE_PLS
            #IMOS_MANUFACTURER_TYPE_OTHER */
    CHAR szManufacturerType[IMOS_STRING_LEN_64];

    /** 跨域中的域等级，有效范围为1～7 */
    ULONG_32 ulDomainLevel;

    /** 域间通讯协议类型，取值为#INTERDOMAIN_PROTOCOL_TYPE_E */
    ULONG_32 ulProtocolType;

    /** 主动注册状态，指本域向当前这个外域注册是否成功, 1为成功; 2为失败 */
    ULONG_32                     ulActiveRegSta;

    /** 接收注册状态，指当前这个外域向本域注册是否成功, 1为成功; 2为失败 */
    ULONG_32                     ulRecvRegSta;

    /** 跨域互联域编码，目前只支持DB33标准的域编码，不可修改 */
    CHAR  szInterDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 跨域互联用户编码，需要和外域配置的互联用户编码一致，不可修改 */
    CHAR  szInterUserCode[IMOS_USER_CODE_LEN];

    /** 外域使用MS策略，BOOL_TRUE为自适应，BOOL_FALSE为指定 */
    BOOL_T bIsAutofit;

    /** 外域指定的MS编码 */
    CHAR  szMSCode[IMOS_DEVICE_CODE_LEN];

    /** 域间流媒体的协议类型,取值为#IMOS_TRANS_TYPE_E。目前外域只支持自适应和TCP */
    ULONG_32 ulStreamTransProtocol;

    /** 域间最大直连媒体流数量,取值为（1~2048）缺省为1024 */
    ULONG_32 ulStreamByPassMaxNum;

    /** 域间实况请求主辅流自适应匹配策略,取值参见#MON_STREAM_ANY_MATCH_POLICY_E */
    ULONG_32 ulMonStreamMatchPolicy;

    /** 保留字段 */
    CHAR szReserve[20];
}EX_DOMAIN_S;


/**
 * @struct tagExDomainV2
 * @brief 域设置数据结构，外物理域信息V2
 * @attention
 */
typedef struct tagExDomainV2
{
    EX_DOMAIN_S        stExDomainInfo;

    /** 外域注册是否需要权签，1表示需要，0表示否 */
    BOOL_T             bNeedAuthorize;

    /** 权签信息 */
    AUTHORIZATION_INFO_S    stAuthorization;

    /** DecoderTag信息 */
    CHAR szDecoderTag[IMOS_DECODERTAG_LEN];

    /** 管理模式 普通管理模式（#CTRL_MODE_NORMAL）；强管理模式（#CTRL_MODE_FULL） */
    ULONG_32 ulCtrlMode;

    /** 外域的URL */
    CHAR  szDomainURL[IMOS_URL_LEN];

    /** 回放中继策略#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulPlaybackAutofit;

    /** 音频中继策略#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulVoicecommAutofit;

    /** 设备地址码 */
    ULONG_32 ulSafeDevAddrcode;

    /* Begin:Modified by gaoshufeng(00762),2014-4-21 for MPPD11595 */
    /** ONVIF码流转TS模式 */
    ULONG_32 ulONVIFTransPackMode;

    /** 保留字段 */
    CHAR   szReserve[120];
    /* End:Modified by gaoshufeng(00762),2014-4-21 for MPPD11595 */
}EX_DOMAIN_V2_S;

/**
 * @struct tagExDomainV3
 * @brief 域设置数据结构，外物理域信息V3
 * @attention
 */
typedef struct tagExDomainV3
{
    EX_DOMAIN_V2_S  stExDomainInfoV2;

    /** 外域子类型,如为DVR:[MM_DOMAIN_SUBTYPE_FOREIGN_DVR3308, MM_DOMAIN_SUBTYPE_FOREIGN_DVR_MAX) */
    ULONG_32           ulExDomainSubType;

    /* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */
}EX_DOMAIN_V3_S;

/**
 * @struct tagLoDomain
 * @brief 本域信息
 * @attention
 */
typedef struct tagLoDomain
{
    /** 本域编码, 本域的唯一标识 */
    CHAR  szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 本域名称 */
    CHAR  szDomainName[IMOS_NAME_LEN];

    /** 厂商类型
        对于非OEM版本(VM8500等H3C设备),取值为
            #IMOS_MANUFACTURER_TYPE_VMISC
        对于OEM版本(PL/PL-S),取值为
            #IMOS_MANUFACTURER_TYPE_PL
            #IMOS_MANUFACTURER_TYPE_PLS */
    CHAR szManufacturerType[IMOS_STRING_LEN_64];

    /** NTP服务器地址数组, 支持的最大地址数为#IMOS_NTP_SERVER_MAXNUM */
    CHAR szNTPServerAddr[IMOS_NTP_SERVER_MAXNUM][IMOS_IPADDR_LEN];
}LO_DOMAIN_S;


/**
 * @struct tagOrgResQueryItem
 * @brief 组织节点下资源信息项(查询资源列表时返回)
 * @attention
 */
typedef struct tagOrgResQueryItem
{
    /** 资源编码 */
    CHAR  szResCode[IMOS_RES_CODE_LEN];

    /** 资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 资源类型，取值范围为#IMOS_TYPE_E */
    ULONG_32  ulResType;

    /** 资源子类型,目前资源子类型只对摄像机/组织/组显示/组轮巡有效，对摄像机而言为云台/非云台;
        对组织而言为:1-本物理域，2-本域的虚拟域，3-外域的虚拟域. 4-上级外物理域.
        5-下级外物理域.6-平级外物理域.
        对组显示资源代表组显示类型，取值为#SALVO_TYPE_E
        对组轮巡资源代表组轮巡类型，取值为#GROUP_SWITCH_TYPE_E
        对枪球联动组类型，取值为#BALLLINKAGE_TYPE_E*/
    ULONG_32  ulResSubType;

    /** 资源状态,取值为:#IMOS_DEV_STATUS_ONLINE,#IMOS_DEV_STATUS_OFFLINE
        - 这里的资源,包括物理设备(摄像机/监视器/EC/DC)和外域(对外域来说,该字段代表接收注册状态) */
    ULONG_32  ulResStatus;

    /** 资源额外状态
        - 对于摄像机,此字段在其上线并第一次主动上报其视频状态信息后(或视频丢失告警/或视频恢复告警),才有意义,取值为:#IMOS_DEV_EXT_STATUS_E
        - 对于外域,该字段代表主动注册状态,取值为:#IMOS_DEV_STATUS_ONLINE,#IMOS_DEV_STATUS_OFFLINE */
    ULONG_32  ulResExtStatus;

    /** 该资源是否是被划归的资源, 1为被划归的资源; 0为非划归的资源 */
    ULONG_32  ulResIsBeShare;

    /** 资源所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 支持的流数目，仅当资源类型为摄像机时有效，0:无效值，1:单流，2:双流 3:三流 */
    ULONG_32 ulStreamNum;

    /** 是否为外域资源，1为外域资源; 0为非外域资源 */
    ULONG_32  ulResIsForeign;
}ORG_RES_QUERY_ITEM_S;


/**
 * @struct tagResItemV2
 * @brief 资源信息项(V2,扩展返回"资源所属组织的名称")
 * @attention
 */
typedef struct tagResItemV2
{
    /** V1资源信息项 */
    ORG_RES_QUERY_ITEM_S stResItemV1;

    /** 资源所属组织的名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** 资源属性信息，对于资源类型是摄像机时，取值为#CAMERA_ATTRIBUTE_E，其他资源类型该字段暂未使用 */
    ULONG_32  ulResAttribute;

    /** 本域非ECR HF系列的摄像机或者监视器所在的设备的流套餐，
        其他资源类型,或者通用查询条件IS_QUERY_ENCODESET没有填写, 或者填了"不查询", 该字段均为无效值#IMOS_SR_INVALID
        取值为#IMOS_STREAM_RELATION_SET_E */
    ULONG_32  ulDevEncodeSet;

    /* Begin: Modified by lw0581, 2013.12.19 for  MPPD06992 */
    /** 语音业务状态, 对于资源类型为对讲资源、广播资源或者摄像机时有效;
        0代表普通状态, 1代表正在对讲, 2代表正在广播, 枚举为#VOICE_STATUS_FOR_ECR_E */
    ULONG_32  ulVoiceStatus;

    /** 是否有子资源, 仅当资源类型为广播组时有效 */
    BOOL_T  bHasBrdSubRes;

    /** 是否有资源绑定 BOOL_FALSE--没有绑定, BOOL_TRUE--有绑定*/
    BOOL_T  bIsBind;

    /** 资源绑定对应信息, 当资源类型为摄像机时, 代表对应绑定关系的语音资源编码,
    当资源类型为语音资源时,代码对应绑定关系的摄像机编码, 其他情况无效 */
    CHAR   szResBindCode[IMOS_DEVICE_CODE_LEN];
    /* Begin:Modified by h00275, 2013.4.12 for  of V2R1开发 */
    /* 此字段只在资源类型为组织有效，用于区分虚拟域 */
    ULONG_32 ulSubTypeOfSubType;

    /** 保留字段*/
    CHAR   szReserve[120];
    /* End: Modified by lw0581, 2013.12.19 for  MPPD06992 */
}RES_ITEM_V2_S;


/**
 * @struct tagQueryConditionItem
 * @brief 查询条件项
 * @attention
 */
typedef struct tagQueryConditionItem
{
    /** 查询条件类型: #QUERY_TYPE_E */
    ULONG_32 ulQueryType;

    /** 查询条件逻辑关系类型: #LOGIC_FLAG_E */
    ULONG_32 ulLogicFlag;

    /** 查询条件 */
    CHAR  szQueryData[IMOS_QUERY_DATA_MAX_LEN];
}QUERY_CONDITION_ITEM_S;


/**
 * @struct tagCommonQueryCondition
 * @brief 通用查询条件
 * @attention
 */
typedef struct tagCommonQueryCondition
{
    /** 查询条件数组中查询条件的实际个数, 最大取值为#IMOS_QUERY_ITEM_MAX_NUM */
    ULONG_32 ulItemNum;

    /** 查询条件数组 */
    QUERY_CONDITION_ITEM_S astQueryConditionList[IMOS_QUERY_ITEM_MAX_NUM];

 }COMMON_QUERY_CONDITION_S;



/***************************************************************************************
EC,DC管理
***********************************************************************************/


/**
 * @struct tagDevChannelIndex
 * @brief 通道索引信息
 * @attention
 */
typedef struct tagDevChannelIndex
{
    /** 设备编码 */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备类型，可取值为编码器#IMOS_TYPE_EC; 解码器#IMOS_TYPE_DC; 或带存储功能的编码器#IMOS_TYPE_ECR */
    ULONG_32 ulDevType;

    /** 通道索引号，分为:音频视频通道、串口通道、开关量通道(输入/输出), 取值视具体情况定 */
    ULONG_32   ulChannelIndex;
}DEV_CHANNEL_INDEX_S;



/**
 * @struct tagECInfo
 * @brief EC信息
 * @attention
 */
typedef struct tagECInfo
{
    /** EC编码, EC的唯一标识 */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC名称 */
    CHAR  szECName[IMOS_NAME_LEN];

    /** EC类型，取值为#IMOS_DEVICE_TYPE_E, 合法取值参见#ulChannum参数的说明 */
    ULONG_32 ulECType;

    /** EC通道数量:
        几种常见EC类型对应的通道个数如下:
        EC1101(#IMOS_DT_EC1101_HF)/EC1001(#IMOS_DT_EC1001)/EC1001-HF(#IMOS_DT_EC1001_HF): 1
        EC1501(#IMOS_DT_EC1501_HF)/R1000 (#IMOS_DT_R1000)/#IMOS_DT_EC1501_IHF : 1
        EC2004(#IMOS_DT_EC2004_HF)/VR2004(#IMOS_DT_VR2004): 4
        EC1102(#IMOS_DT_EC1102_HF)/VR1102(#IMOS_DT_VR1102): 2
        EC1801(#IMOS_DT_EC1801_HH): 1
        EC2016(#IMOS_DT_EC2016_HC): 16
        EC2016[8CH](#IMOS_DT_EC2016_HC_8CH): 8
        EC2016[4CH](#IMOS_DT_EC2016_HC_4CH): 4
        HIC5201-H(#IMOS_DT_HIC5201)/HIC5221-H(#IMOS_DT_HIC5221): 1
        ECR3316(#IMOS_DT_ECR3316_HC): 16
        ECR3316[8CH](#IMOS_DT_ECR3316_HC_8CH): 8
        ECR3316[4CH](#IMOS_DT_ECR3316_HC_4CH): 4
        ECR3308(#IMOS_DT_ECR3308_HD): 8
        ECR3308[4CH](#IMOS_DT_ECR3308_HD_4CH): 4
        HIC5421-H(#IMOS_DT_HIC5421)/HIC5401-H(#IMOS_DT_HIC5401)/#IMOS_DT_SIC/#IMOS_DT_HIC: 1
        EC1504(#IMOS_DT_EC1504_HF): 4
        EC2516(#IMOS_DT_EC2516_HF): 16
        EC2508(#IMOS_DT_EC2508_HF): 8
        EC1504(#IMOS_DT_EC1504_HFE): 4
        EC2508(#IMOS_DT_EC2508_HFE): 8
        EC2516(#IMOS_DT_EC2516_HFE): 16
    */
    ULONG_32 ulChannum;

    /** 是否支持组播, 1为支持; 0为不支持 */
    ULONG_32 ulIsMulticast;

    /** 高温告警温度下限, 取值为50~100 */
    LONG_32 lTemperatureMax;

    /** 低温告警温度上限, 取值为-100~49 */
    LONG_32 lTemperatureMin;

    /** 告警使能, 1为使能; 0为不使能 */
    ULONG_32 ulEnableAlarm;

    /** EC所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 时间同步方式，默认为1，表示使用H3C的私有同步方式；2表示NTP的同步方式(目前暂不支持) */
    ULONG_32 ulTimeSyncMode;

    /** 时区, 取值为-12~12 */
    LONG_32 lTimeZone;

    /** 语言设置，由中心服务器来配置，取值为:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** 是否启用本地缓存，1表示启用; 0表示不启动，默认值为0 */
    ULONG_32 ulEnableLocalCache;

    /** 流套餐, 取值为:#IMOS_STREAM_RELATION_SET_E
        0：MPEG4+MPEG4(#IMOS_SR_MPEG4_MPEG4)
        1：H264主码流(#IMOS_SR_H264_SHARE)
        2：MPEG2+MPEG4(#IMOS_SR_MPEG2_MPEG4)
        3：H264+MJPEG(#IMOS_SR_H264_MJPEG)
        4：MPEG4主码流(#IMOS_SR_MPEG4_SHARE)
        5：MPEG2主码流(#IMOS_SR_MPEG2_SHARE)
        8: MPEG4主码流_D1(#IMOS_SR_STREAM_MPEG4_8D1)
        9：MPEG2+MPEG2(#IMOS_SR_MPEG2_MPEG2)
        11：H264+H264(#IMOS_SR_H264_H264)
    */
    ULONG_32 ulEncodeSet;

    /** 制式, 取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 音频输入源，取值为#IMOS_AUDIO_INPUT_SOURCE_E */
    ULONG_32 ulAudioinSource;

    /** 语音对讲资源编码 */
    CHAR szAudioCommCode[IMOS_RES_CODE_LEN];

    /** 语音广播资源编码 */
    CHAR szAudioBroadcastCode[IMOS_RES_CODE_LEN];

    /** 设备访问密码 */
    CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

    /** 设备描述, 目前该字段未使用 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** EC的IP地址, 添加及修改EC不需填写该参数, 查询EC信息时返回该字段 */
    CHAR szECIPAddr[IMOS_IPADDR_LEN];

    /** EC的在线状态,添加及修改EC不需填写该参数, 查询EC信息时返回该字段, 1为在线; 其他为离线 */
    ULONG_32 ulIsECOnline;

    /** 流媒体的协议类型,取值为#IMOS_TRANS_TYPE_E。目前EC只支持UDP和TCP */
    ULONG_32 ulStreamTransProtocol;

    /** 设备型号信息 */
    CHAR szECVer[IMOS_STRING_LEN_64];

    /** 保留字段 */
    CHAR szReserve[28];
}EC_INFO_S;


/**
 * @struct tagECQueryItem
 * @brief 编码器信息项(查询编码器列表时返回)
 * @attention
 */
typedef struct tagECQueryItem
{
    /** EC编码 */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC名称 */
    CHAR  szECName[IMOS_NAME_LEN];

    /** EC类型，取值为#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulECType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** 设备地址 */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** 所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备是否在线取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，取值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** 是否支持组播, 1为支持组播; 0为不支持组播 */
    ULONG_32 ulIsMulticast;

    /** 告警使能, 1为使能告警; 0为不使能告警 */
    ULONG_32 ulEnableAlarm;

    /** 流套餐类型，取值为#IMOS_STREAM_RELATION_SET_E */
    ULONG_32 ulEncodeType;

    /** 制式，取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 保留字段 */
    CHAR szReserve[32];
}EC_QUERY_ITEM_S;


/**
 * @struct tagECAndAudioInfo
 * @brief EC配置信息
 * @attention
 */
typedef struct tagECAndAudioInfo
{
    /**  EC配置信息 */
    EC_INFO_S           stEcInfo;

    /** 独立音频信息 */
    AUDIO_INPUT_INFO_S  stAudioInPutInfo;
}EC_AND_AUDIO_INFO_S;


/**
 * @struct tagCamAndChannelQueryItem
 * @brief 摄像机以及通道信息项(查询摄像机以及通道列表时返回)
 * @attention
 */
typedef struct tagCamAndChannelQueryItem
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32   ulCamType;

    /** 云台控制协议 */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** 云台地址码, 取值为0~255, 具体取值视云台摄像机的实际地址码而定 */
    ULONG_32   ulPtzAddrCode;

    /** 组播地址 */
    CHAR    szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口, 范围为：10002-65534 */
    ULONG_32   ulMulticastPort;

    /** 保留字段 */
    CHAR szReserve[32];
}CAM_AND_CHANNEL_QUERY_ITEM_S;


/**
 * @struct tagCamAndChannelQueryItem
 * @brief 摄像机以及通道信息项(查询摄像机以及通道列表时返回)
 * @attention
 */
typedef struct tagCamAndChannelQueryItemV2
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32   ulCamType;

    /** 云台控制协议 */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** 云台地址码, 取值为0~255, 具体取值视云台摄像机的实际地址码而定 */
    ULONG_32   ulPtzAddrCode;

    /** 组播地址 */
    CHAR    szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口, 范围为：10002-65534 */
    ULONG_32   ulMulticastPort;

    /** 组播地址 */
    CHAR    szSecondMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口, 范围为：10002-65534 */
    ULONG_32   ulSecondMulticastPort;

    /** 保留字段 */
    CHAR szReserve[512];
}CAM_AND_CHANNEL_QUERY_ITEM_V2_S;




/**
 * @struct tagDCInfo
 * @brief DC信息
 * @attention
 */
typedef struct tagDCInfo
{
    /** DC编码 */
    CHAR  szDCCode[IMOS_DEVICE_CODE_LEN];

    /** DC名称 */
    CHAR  szDCName[IMOS_NAME_LEN];

    /** DC类型, 取值为#IMOS_DEVICE_TYPE_E, 合法取值参见#ulChannum参数的说明 */
    ULONG_32 ulDCType;

    /** DC通道数量:
        几种常见DC类型对应的通道个数如下:
        DC1001(#IMOS_DT_DC1001): 1
        DC2004(#IMOS_DT_DC2004_FF)/VL2004(#IMOS_DT_VL2004): 4
        DC1801(#IMOS_DT_DC1801_FH): 1
    */
    ULONG_32 ulChannum;

    /** 是否支持组播, 1为支持组播; 0为不支持组播 */
    ULONG_32 ulIsMulticast;

    /** 高温告警温度下限, 取值为50~100 */
    LONG_32 lTemperatureMax;

    /** 低温告警温度上限, 取值为-100~49 */
    LONG_32 lTemperatureMin;

    /** 告警使能, 1为使能告警; 0为不使能告警 */
    ULONG_32 ulEnableAlarm;

    /** 所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 时间同步方式，默认为1，表示使用H3C的私有同步方式；2表示NTP的同步方式(目前暂不支持) */
    ULONG_32 ulTimeSyncMode;

    /** 时区, 取值为-12~12 */
    LONG_32 lTimeZone;

    /** 语言设置，由中心服务器来配置，取值为:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** 制式, 取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 流套餐，取值为#IMOS_STREAM_RELATION_SET_E
        以下为解码器流套餐值：
        1：H264(#IMOS_SR_H264_SHARE)
        3: MJPEG(#IMOS_SR_H264_MJPEG)
        4：MEPG4(#IMOS_SR_MPEG4_SHARE)
        5：MEPG2(#IMOS_SR_MPEG2_SHARE)
    */
    ULONG_32 ulEncodeSet;

    /** 设备访问密码 */
    CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

    /** 设备描述, 目前该字段未使用 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** DC的IP地址,添加及修改DC不需填写该参数,查询DC信息时会返回该字段 */
    CHAR szDCIPAddr[IMOS_IPADDR_LEN];

    /** DC的在线状态,添加及修改DC该参数无效, 查询DC信息时返回该字段, 1为在线; 其他为离线 */
    ULONG_32 ulIsDCOnline;

    /** 流媒体的协议类型,取值为#IMOS_TRANS_TYPE_E。目前DC只支持自适应和TCP */
    ULONG_32 ulStreamTransProtocol;

    /** 流媒体的方式类型,取值为#IMOS_STREAM_SERVER_MODE_E。目前DC只支持自适应和直连优先 */
    ULONG_32 ulStreamServerMode;

    /** 设备注册协议类型，取值为#IMOS_DEVICE_REG_PROTOCOL_TYPE_E */
    ULONG_32 ulRegProtocol;

    /** 设备注册用户名 */
    CHAR szRegUserName[IMOS_NAME_LEN];

    /** 设备注册明文密码 */
    CHAR szRegUserPasswd[IMOS_PASSWD_LEN];

    /** 保留字段 */
    CHAR szReserve[4];
}DC_INFO_S;


/**
 * @struct tagDCQueryItem
 * @brief 解码器信息项(查询解码器列表时返回)
 * @attention
 */
typedef struct tagDCQueryItem
{
    /** DC编码 */
    CHAR  szDCCode[IMOS_DEVICE_CODE_LEN];

    /** DC名称 */
    CHAR  szDCName[IMOS_NAME_LEN];

    /** DC类型，取值为#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulDCType;

    /** DC设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** DC设备地址 */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** DC所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，枚举值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** 是否支持组播, 1为支持组播; 0为不支持组播 */
    ULONG_32 ulIsMulticast;

    /** 告警使能, 1为使能告警; 0为不使能告警 */
    ULONG_32 ulEnableAlarm;

    /** 流套餐类型，取值为#IMOS_STREAM_RELATION_SET_E */
    ULONG_32 ulEncodeType;

    /** 制式, 取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 注册协议类型,取值为#IMOS_DEVICE_REG_PROTOCOL_TYPE_E */
    ULONG_32 ulRegProtocol;

    /** 保留字段 */
    CHAR szReserve[28];
}DC_QUERY_ITEM_S;


/**
 * @struct tagScrAndChannelQueryItem
 * @brief 监视器以及通道信息项(查询监视器以及通道列表时返回)
 * @attention
 */
typedef struct tagScrAndChannelQueryItem
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stDCChannelIndex;

    /** 监视器编码 */
    CHAR    szScrCode[IMOS_RES_CODE_LEN];

    /** 监视器名称 */
    CHAR    szScrName[IMOS_NAME_LEN];

    /** 分屏数量 */
    ULONG_32 ulSplitScrNum;

    /** 保留字段 */
    CHAR szReserve[28];
}SCR_AND_CHANNEL_QUERY_ITEM_S;

/***************************************************************************************
摄像机管理
***********************************************************************************/

/**
 * @struct tagSCameraInfo
 * @brief 摄像机信息
 * @attention
 */
typedef struct tagSCameraInfo
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** 摄像机描述, 可不填 */
    CHAR    szCameraDesc[IMOS_DESC_LEN];

    /** 云台控制协议, 目前支持的包括:PELCO-D, PELCO-P, ALEC, VISCA, ALEC_PELCO-D, ALEC_PELCO-P, MINKING_PELCO-D, MINKING_PELCO-P */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** 云台地址码, 取值为0~255, 具体取值视云台摄像机的实际地址码而定 */
    ULONG_32   ulPtzAddrCode;

    /** 云台协议翻译模式,具体取值为#PTZ_CMDPARSEMODE_E */
    ULONG_32   ulPtzTranslateMode;

    /** 经度 */
    CHAR szLongitude[IMOS_STRING_LEN_32];

    /** 纬度 */
    CHAR szLatitude[IMOS_STRING_LEN_32];

    /** 看守位，与设定的预置位的编号相对应 */
    ULONG_32   ulGuardPosition;

    /** 自动看守时间, 单位为秒, 最大不超过3600秒, 0表示不看守 */
    ULONG_32   ulAutoGuard;

    /** 设备描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** 对于EC的摄像机是EC的编码, 对于ECR的摄像机是ECR的编码, 对于外域时外域的编码 */
    CHAR    szECCode[IMOS_DEVICE_CODE_LEN];

    /** 在绑定及修改Camera时,不需填写,查询Camera信息时会返回该字段, 对于EC的摄像机是EC的IP, 对于ECR的摄像机是ECR的IP, 对于外域是外域的IP */
    CHAR    szECIPAddr[IMOS_IPADDR_LEN];

    /** 所在EC通道索引号, 视具体情况而定, 对于EC、ECR HC系列的摄像机是具体的通道索引, 对于ECR HF系列和外域的摄像机无效值 */
    ULONG_32   ulChannelIndex;

    /* 拉框放大协议 取值#ZOOM_PROTOCOL_E*/
    ULONG_32   ulZoomProtocol;

    /** 监控目标类型, 取值为#TARGET_TYPE_E中的一个或多个组成的字符串 */
    CHAR    szTargetType[IMOS_STRING_LEN_14];

    /** 监控目标子类型，目前保留，用于日后扩展 */
    CHAR    szTargetSubType[IMOS_STRING_LEN_14];
}CAMERA_INFO_S;

/* Begin Add by zhouquanwei/z01364 2013/12/16 for 国标摄像机属性扩展 */
/**
 * @struct  tagSCameraInfoEX
 * @brief   扩展摄像机信息
 * @attention
 */
typedef struct tagSCameraInfoEX
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** 摄像机描述, 可不填 */
    CHAR    szCameraDesc[IMOS_DESC_LEN];

    /** 云台控制协议, 目前支持的包括:PELCO-D, PELCO-P, ALEC, VISCA, ALEC_PELCO-D, ALEC_PELCO-P, MINKING_PELCO-D, MINKING_PELCO-P */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** 云台地址码, 取值为0~255, 具体取值视云台摄像机的实际地址码而定 */
    ULONG_32   ulPtzAddrCode;

    /** 云台协议翻译模式,具体取值为#PTZ_CMDPARSEMODE_E */
    ULONG_32   ulPtzTranslateMode;

    /** 经度 */
    CHAR szLongitude[IMOS_STRING_LEN_32];

    /** 纬度 */
    CHAR szLatitude[IMOS_STRING_LEN_32];

    /** 看守位，与设定的预置位的编号相对应 */
    ULONG_32   ulGuardPosition;

    /** 自动看守时间, 单位为秒, 最大不超过3600秒, 0表示不看守 */
    ULONG_32   ulAutoGuard;

    /** 设备描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** 对于EC的摄像机是EC的编码, 对于ECR的摄像机是ECR的编码, 对于外域时外域的编码 */
    CHAR    szECCode[IMOS_DEVICE_CODE_LEN];

    /** 在绑定及修改Camera时,不需填写,查询Camera信息时会返回该字段, 对于EC的摄像机是EC的IP, 对于ECR的摄像机是ECR的IP, 对于外域是外域的IP */
    CHAR    szECIPAddr[IMOS_IPADDR_LEN];

    /** 所在EC通道索引号, 视具体情况而定, 对于EC、ECR HC系列的摄像机是具体的通道索引, 对于ECR HF系列和外域的摄像机无效值 */
    ULONG_32   ulChannelIndex;

    /* 拉框放大协议 取值#ZOOM_PROTOCOL_E*/
    ULONG_32   ulZoomProtocol;

    /** 监控目标类型, 取值为#TARGET_TYPE_E中的一个或多个组成的字符串 */
    CHAR    szTargetType[IMOS_STRING_LEN_14];

    /** 监控目标子类型，目前保留，用于日后扩展 */
    CHAR    szTargetSubType[IMOS_STRING_LEN_14];

    /** 摄像机位置类型扩展。1-省际检查站、2-党政机关、3-车站码头、4-中心广场、5-体育场馆、6-商业中心、7-宗教场所、
        8-校园周边、9-治安复杂区域、10-交通干线。 */
    ULONG_32   ulPositionType;

    /** 摄像机安装位置室外、室内属性。1-室外、2-室内。 */
    ULONG_32   ulRoomType;

    /** 摄像机用途属性。1-治安、2-交通、3-重点。 */
    ULONG_32   ulUseType;

    /** 摄像机补光属性。1-无补光、2-红外补光、3-白光补光。 */
    ULONG_32   ulSupplyLightType;

    /** 摄像机监视方位属性。1-东、2-西、3-南、4-北、5-东南、6-东北、7-西南、8-西北。（当目录项为摄像机时可选） */
    ULONG_32   ulDirectionType;
}CAMERA_INFO_EX_S;
/* End Add by zhouquanwei/z01364 2013/12/16 for 国标摄像机属性扩展 */

/**
* @struct tagCameraPtzInfo
* @brief 摄像机云台信息
*/
typedef struct tagCameraPtzInfo
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** 摄像机描述, 可不填 */
    CHAR    szCameraDesc[IMOS_DESC_LEN];

    /** 云台控制协议, 目前支持的包括:#PELCO-D, #PELCO-P, #ALEC, #VISCA, #ALEC_PELCO-D, #ALEC_PELCO-P, #MINKING_PELCO-D, #MINKING_PELCO-P */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** 云台地址码, 取值为0~255, 具体取值视云台摄像机的实际地址码而定 */
    ULONG_32   ulPtzAddrCode;

    /** 云台标识, 用于云台控制器 */
    ULONG_32   ulPtzID;

    /* 保留字段 */
    CHAR    szReserv[128];
}CAMERA_PTZ_INFO_S;


/***************************************************************************************
监视器管理
***********************************************************************************/

/**
 * @struct tagScreenInfo
 * @brief 监视器信息
 * @attention
 */
typedef struct tagScreenInfo
{
    /** 监视器编码 */
    CHAR        szScreenCode[IMOS_RES_CODE_LEN];

    /** 监视器名称 */
    CHAR        szScreenName[IMOS_NAME_LEN];

    /** 监视器描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /**  DC的IP地址, 在绑定及修改Screen时, 不需填写; 查询Screen信息时会返回该字段 */
    CHAR    szDCIPAddr[IMOS_IPADDR_LEN];

    /**  DC设备类型 */
    ULONG_32    ulDCType;

    /** 保留字段 */
    CHAR szReserve[28];
}SCREEN_INFO_S;

/**
 * @struct tagScreenRelatedDC
 * @brief 监视器所对应的解码器信息结构体
 * @attention
 */
typedef struct tagScreenRelatedDC
{
    /** 监视器编码 */
    CHAR szScreenCode[IMOS_CODE_LEN];

    /** 监视器名称 */
    CHAR szScreenName[IMOS_NAME_LEN];

    /** 监视器描述, 可不填 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** DC编码 */
    CHAR szDCCode[IMOS_CODE_LEN];

    /** DC名称 */
    CHAR szDCName[IMOS_NAME_LEN];

    /** DC类型, 取值为#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulDCType;

    /** 所对应DC的IP地址, 在绑定及修改Screen时, 不需填写; 查询Screen信息时会返回该字段 */
    CHAR szDCIPAddr[IMOS_IPADDR_LEN];

    /** 通道索引号，音频视频通道*/
    ULONG_32 ulChannelIndex;

    /** 保留字段 */
    CHAR szReserve[28];
}SCREEN_RELATED_DC_S;

/***************************************************************************
EC,DC视频通道
****************************************************************************/

/**
 * @struct tagVideoInChannel
 * @brief 音视频输入通道信息
 * @attention
 */
typedef struct tagVideoInChannel
{

    /** 视频输入通道描述 */
    CHAR szVinChannelDesc[IMOS_DESC_LEN];

    /** 组播地址 */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口,范围为：10002-65534，且必须为偶数 */
    ULONG_32   ulMulticastPort;

    /** MS选择的适应策略, 1为自适应; 0为指定MS，2为不经过MS, 取值为#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulIsAutofit;

    /** 使用MS数目, 视实际情况而定, 当适应策略#ulIsAutofit为自适应, 该值为0;
        当适应策略#ulIsAutofit为非自适应(即指定), 该值为1 */
    ULONG_32 ulUseMSNum;

    /** MS编码列表 */
    CHAR aszMSCode[IMOS_MS_MAX_NUM_PER_CHANNEL][IMOS_DEVICE_CODE_LEN];

    /** 是否启动图像遮挡检测告警, 1为启动; 0为不启动 */
    ULONG_32 ulEnableKeepout;

    /** 是否启动运动检测告警, 1为启动运动检测告警; 0为不启动运动检测告警 */
    ULONG_32 ulEnableMotionDetect;

    /** 是否启动视频丢失告警, 1为启动视频丢失告警; 0为不启动视频丢失告警 */
    ULONG_32 ulEnableVideoLost;

    /** 绑定的串口编号，如无则填写为无效值(255)#PTZ_INVALID_SERIAL_INDEX_NUM */
    ULONG_32 ulSerialIndex;

    /** 亮度，取值为（0~255） */
    ULONG_32 ulBrightness;

    /** 对比度，取值为（0~255） */
    ULONG_32 ulContrast;

    /** 饱和度，取值为（0~255） */
    ULONG_32 ulSaturation;

    /** 色调，取值为（0~255） */
    ULONG_32 ulTone;

    /** 是否启动静音, 1为不启动静音; 0为启动静音 */
    ULONG_32 ulAudioEnabled;

    /** 音频编码, 取值为#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioCoding;

    /** 音频声道, 取值为#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** 音频采样率, 取值为#IMOS_AUDIO_SAMPLING_E */
    ULONG_32 ulSamplingRate;

    /** 音频码率, 不可配置 */
    ULONG_32 ulAudioCodeRate;

    /** 音频增益值，取值为（0~255） */
    ULONG_32 ulIncrement;
}VIN_CHANNEL_S;

/**
 * @struct tagVideoInChannelExtend
 * @brief 音视频输入通道信息
 * @attention
 */
typedef struct tagVideoInChannelV3
{
    VIN_CHANNEL_S stVinChannel;
    /** 组播地址,双组播时使用*/
    CHAR szExtMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口,双组播时使用*/
    ULONG_32 ulExtMulticastPort;
    
    /** 保留字段 */
    CHAR  szReserve[256];
    
}VIN_CHANNEL_V3_S;


/**
 * @struct tagVideoOutChannel
 * @brief 逻辑输出通道信息
 * @attention
 */
typedef struct tagVideoOutChannel
{
    /** 逻辑输出通道索引, 取值为1~(#SPLIT_SCR_MODE_MAX - 1) */
    ULONG_32   ulVoutChannelindex;

    /** 逻辑输出通道描述, 可不填 */
    CHAR szVoutChannelDesc[IMOS_DESC_LEN];

    /** 是否使能, 1为使能; 0为不使能 */
    ULONG_32 ulEnable;

    /** 码流类型, 取值为#IMOS_STREAM_TYPE_E, 目前仅支持#IMOS_ST_TS */
    ULONG_32 ulStreamType;

    /** 流传输模式, 取值为#IMOS_TRANS_TYPE_E */
    ULONG_32   ulTranType;

    /** 是否启动防抖动, 1为启动; 0为不启动 */
    ULONG_32   ulEnableJitterBuff;

}VOUT_CHANNEL_S;


/**
 * @struct tagPhyOutChannel
 * @brief 物理输出通道信息
 * @attention
 */
typedef struct tagPhyOutChannel
{

    /** 工作模式，取值为1或4，代表BNC口的分屏数 */
    ULONG_32 ulPhyoutMode;

    /** 视频解码格式，取值为#IMOS_VIDEO_FORMAT_E */
    ULONG_32 ulDecodeFormat;

    /** 音频格式，取值为#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioFormat;

    /** 声道设置，取值为#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** 是否启用语音功能, 1为启用; 0为不启用 */
    ULONG_32 ulAudioEnabled;

    /** 输出音量, 取值为1~7 */
    ULONG_32 ulVolume;

    /** 音频输出选择, 视工作模式参数#ulPhyoutMode而定。如果工作模式取值为1, 则该值为1; 如果工作模式取值为4, 则该值取值为1~4 */
    ULONG_32 ulOutputIndex ;

    /** 最多监视器数量, 表示该物理通道最多可绑定的监视器数量, 目前固定为1 */
    ULONG_32 ulMaxScreenNum;
}PHYOUT_CHANNEL_S;



/**
 * @struct tagVideoStream
 * @brief 视频流信息
 * @attention
 */
typedef struct tagVideoStream
{

    /** 码流类型, 取值为#IMOS_STREAM_TYPE_E, 目前仅支持#IMOS_ST_TS */
    ULONG_32       ulStreamType;

    /** 流索引，1为主流，2为副流，3为第三码流 */
    ULONG_32       ulStreamIndex;

    /** 流使能标识, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 流传输方式, 取值为#IMOS_TRANS_TYPE_E */
    ULONG_32       ulTranType;

    /** 编码格式, 取决于具体的流套餐值, 取值为#IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /** 分辨率, 取值为#IMOS_PICTURE_SIZE_E */
    ULONG_32       ulResolution;

    /** 码率 */
    ULONG_32       ulBitRate;

    /** 帧率,可取的值有1, 3, 5, 8, 10, 15, 20, 25, 30, 60
        对于制式#IMOS_PF_720P60HZ,默认值为60 */
    ULONG_32       ulFrameRate;

    /** GOP模式, 取值为#IMOS_GOP_TYPE_E */
    ULONG_32       ulGopMode;

    /** I帧间隔, 取决于GOP模式值, 当GOP模式为#IMOS_GT_I时, I帧间隔为1; 当GOP模式为#IMOS_GT_IP时, I帧间隔为10~60
        对于制式#IMOS_PF_720P60HZ,默认值为60 */
    ULONG_32       ulIFrameInterval;

    /** 图像质量, 取值为#IMOS_VIDEO_QUALITY_E */
    ULONG_32       ulImageQuality;

    /** 流编码模式, 取值为#IMOS_ENC_MODE_E */
    ULONG_32       ulEncodeMode;

    /** 优先级, 仅在编码模式为#IMOS_EM_CBR时可设置该值, 取值为#IMOS_CBR_ENC_MODE_E */
    ULONG_32       ulPriority;

    /** 码流平滑，取值为#IMOS_STREAM_SMOOTH_E */
    ULONG_32       ulSmoothValue;

}VIDEO_STREAM_S;

/**
 * @struct tagAreaScope
 * @brief 区域范围的两个顶点坐标(区域是矩形的)
 * @attention 原则为配置和解析需要统一坐标解析模型
 */
typedef struct tagAreaScope
{
    /** 左上角x坐标 */
    ULONG_32       ulTopLeftX;

    /** 左上角y坐标 */
    ULONG_32       ulTopLeftY;

    /** 右下角x坐标 */
    ULONG_32       ulBottomRightX;

    /** 右下角y坐标 */
    ULONG_32       ulBottomRightY;

}AREA_SCOPE_S;

/**
 * @struct tagVideoArea
 * @brief 视频区域信息
 * @attention
 */
typedef struct tagVideoArea
{
    /** 区域索引, 取值为1~4 */
    ULONG_32       ulAreaIndex;

    /** 是否使能, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 灵敏度, 1～5级，1级灵敏度最高。该值仅对运动检测区域有效 */
    ULONG_32       ulSensitivity;

    /** 区域坐标 */
    AREA_SCOPE_S stAreaScope;

}VIDEO_AREA_S;



/**
 * @struct tagDetectArea
 * @brief 遮挡、运动检测区域
 * @attention
 */
typedef struct tagDetectArea
{
    /** 遮挡检测区域 */
    VIDEO_AREA_S       astCoverDetecArea[IMOS_COVER_AREA_MAXNUM];

    /** 运动检测区域 */
    VIDEO_AREA_S       astMotionDetecArea[IMOS_DETECT_AREA_MAXNUM];
}DETECT_AREA_S;

/**
 * @struct tagOsdMaskArea
 * @brief 遮盖区域
 * @attention
 */
typedef struct tagOsdMaskArea
{
    /** 遮盖区域 */
    VIDEO_AREA_S       astMaskArea[IMOS_MASK_AREA_MAXNUM];
}OSD_MASK_AREA_S;




/**
 * @struct tagOsdTime
 * @brief OSD时间参数
 * @attention
 */
typedef struct tagOsdTime
{
    /** 时间OSD索引, 固定为1 */
    ULONG_32       ulOsdTimeIndex;

    /** 时间OSD使能, 1为使能; 0为非使能 */
    ULONG_32       ulEnableFlag;

    /** 时间OSD时间格式 */
    ULONG_32       ulOsdTimeFormat;

    /** 时间OSD日期格式 */
    ULONG_32       ulOsdDateFormat;

    /** 时间OSD颜色, 取值为#IMOS_OSD_COLOR_E */
    ULONG_32       ulOsdColor;

    /** 时间OSD透明度, 取值为#IMOS_OSD_ALPHA_E */
    ULONG_32       ulTransparence;

    /** 时间OSD区域坐标 */
    AREA_SCOPE_S stAreaScope;

}OSD_TIME_S;

/**
 * @struct tagOsdName
 * @brief OSD场名信息
 * @attention
 */
typedef struct tagOsdName
{
    /** 是否使能场名OSD, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 场名OSD索引, 固定为1 */
    ULONG_32       ulOsdNameIndex;

    /** 场名OSD颜色, 取值为#IMOS_OSD_COLOR_E */
    ULONG_32       ulOsdColor;

    /** 场名OSD透明度, 取值为#IMOS_OSD_ALPHA_E */
    ULONG_32       ulTransparence;

    /** 场名OSD区域坐标 */
    AREA_SCOPE_S stAreaScope;

    /** 第一个(主)场名OSD类型, 取值为#IMOS_INFO_OSD_TYPE_E */
    ULONG_32       ulOsdType1;

    /** 第一个(主)场名OSD内容，对文字，该值为字符串，最长为20字符。对图片，该值为OSD图片编码 */
    CHAR        szOsdString1[IMOS_NAME_LEN];

    /** 第二个(辅)场名OSD类型, 取值为#IMOS_INFO_OSD_TYPE_E */
    ULONG_32       ulOsdType2;

    /** 第二个(辅)场名OSD内容，对文字，该值为字符串，最长为20字符。对图片，该值为OSD图片编码 */
    CHAR        szOsdString2[IMOS_NAME_LEN];

    /** (第一个和第二个)场名OSD之间的切换时间, 单位为秒, 取值为0~300。取值为0, 表示只显示第一个(主)OSD */
    ULONG_32       ulSwitchIntval;

    /** 场名OSD类型,取值为:0 普通场名OSD,1 云台控制用户OSD */
    ULONG_32 ulOsdNameType;

    /** 保留字段 */
    CHAR szReserve[12];
}OSD_NAME_S;


/**
 * @struct tagOsdInfo
 * @brief OSD信息
 * @attention
 */
typedef struct tagOsdInfo
{
    /** 时间OSD */
    OSD_TIME_S      stOSDTime;

    /** 场名OSD */
    OSD_NAME_S      astOSDName[IMOS_OSD_NAME_MAXNUM];

    /** 遮盖区域 */
    OSD_MASK_AREA_S stOSDMaskArea;
}OSD_INFO_S;



/**
 * @struct tagVinChnlBindCamera
 * @brief 摄像机及其绑定通道的信息
 * @attention
 */
typedef struct tagVinChnlBindCamera
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机信息 */
    CAMERA_INFO_S       stCameraInfo;

    /** 视频输入通道信息 */
    VIN_CHANNEL_S       stVinChannel;

    /** OSD信息 */
    OSD_INFO_S          stOSDInfo;

    /** 视频流数组中视频流的实际数目, 最大取值为#IMOS_STREAM_MAXNUM, 视具体流套餐值而定 */
    ULONG_32               ulVideoStreamNum;

    /** 视频流信息数组 */
    VIDEO_STREAM_S      astVideoStream[IMOS_STREAM_MAXNUM];

    /** 检测区域，包含运动检测以及遮挡检测区域 */
    DETECT_AREA_S       stDetectArea;
}VINCHNL_BIND_CAMERA_S;

/**
 * @struct tagMultiOsdInfo
 * @brief OSD信息(支持多行OSD)
 * @attention
 */
typedef struct tagMultiOsdInfo
{
    /** 时间OSD */
    OSD_TIME_S      stOSDTime;

    /** 场名OSD */
    OSD_NAME_S      astOSDName[IMOS_OSD_NAME_MAX];

    /** 遮盖区域 */
    OSD_MASK_AREA_S stOSDMaskArea;
}MULTI_OSD_INFO_S;

/**
* @struct tagOpticsParam
* @brief 光学参数
* @attention
*/
typedef struct tagOpticsParam
{
    /** 光学通道，目前只有一个通道永远是1 */
    ULONG_32 ulOpticsIndex;

    /** 黑白模式，取值为#IMOS_BLACKWHIT_MODE_E 0 自动模式（缺省） */
    ULONG_32 ulBlackWhiteMode;

    /** 黑白模式灵敏度，只有黑白模式在自动模式才设置有效 0(最低) - 2(最高) 默认1 */
    ULONG_32 ulBlackWhiteSense;

    /** 自动曝光，2：关闭自动曝光 1：使能自动曝光（缺省） */
    ULONG_32 ulAutoExposal;

    /** 快门，取值为#IMOS_SHUTTER_E，缺省为50 */
    ULONG_32 ulShutter;

    /** 自动增益控制，范围0-36，缺省0  */
    ULONG_32 ulOpticsAGC;

    /** 测光控制，取值为#IMOS_AEMETERING_E 0 中央权重（缺省） */
    ULONG_32 ulVideoAEMetering;

    /** 锐度，取值为# 范围0-6  默认0 */
    ULONG_32 ulVideoSharpness;

    /** 白平衡，取值为#IMOS_AWB_E 0 自动模式（缺省） */
    ULONG_32 ulWhiteBalance;

    /** 图像镜像，取值为#IMOS_MIRRORTYPE_E 0 正常（缺省） */
    ULONG_32 ulVideoMirror;

    /** 背景频率，取值为#IMOS_FLICKER_MODE_E 0 关闭（缺省） */
    ULONG_32 ulVideoFlicker;

    /** 宽动态(#BOOL_FALSE 关闭, #BOOL_TRUE 开启) */
    BOOL_T bEnableWDR;

    /** 背光补偿(#BOOL_FALSE 关闭, #BOOL_TRUE 开启) */
    BOOL_T bEnableBLC;

    /** 保留字段3， 缺省为0 */
    ULONG_32 ulReserved3;
} OPTICS_PARAM_S;

/**
 * @struct tagPTZParam
 * @brief 云台参数
 * @attention
*/
typedef struct tagPTZParam
{
    /** 横向最大角速度(°/秒),取值范围[30,360] */
    ULONG_32 ulXMaxAngleSpeed;

    /** 纵向最大角速度(°/秒),取值范围[30,360] */
    ULONG_32 ulYMaxAngleSpeed;

    /** 横向最大视角(°),取值范围[30,360] */
    ULONG_32 ulXMaxViewAngle;

    /** 纵向最大视角(°),取值范围[30,360] */
    ULONG_32 ulYMaxViewAngle;

    /** 变倍时间(毫秒),取值范围[100,60000] */
    ULONG_32 ulZoomTime;

    /** 变倍倍数,取值范围[1,35] */
    ULONG_32 ulZoomMultiple;
} PTZ_PARAMETER_S;

/**
 * @struct tagReviseParam
 * @brief 算法校正参数
 * @attention
*/
typedef struct tagReviseParam
{
    /** 横向转动调节系数(%),取值范围[50,200] */
    ULONG_32 ulXTurnCoefficient;

    /** 纵向转动调节系数(%),取值范围[50,200] */
    ULONG_32 ulYTurnCoefficient;

    /** 变焦调节系数(%),取值范围[50,200] */
    ULONG_32 ulFocusCoefficient;
} REVISE_PARAMETER_S;

/**
 * @struct tagLocateInfo
 * @brief 定位信息
 * @attention
*/
typedef struct tagLocateInfo
{
    /** 是否启用(#BOOL_FALSE 不启用,#BOOL_TURE 启用) */
    BOOL_T  bIsEnabled;

    /** 云台参数 */
    PTZ_PARAMETER_S stPTZParam;

    /** 算法校正参数 */
    REVISE_PARAMETER_S  stReviseParam;
} LOCATE_INFO_S;

/**
 * @struct tagIMOSAnalyseSizeFilter
 * @brief 行为分析区域大小过滤信息
 * @attention
 */
typedef struct tagIMOSAnalyseSizeFilter
{
    /** 是否使能(BOOL_FALSE 否,BOOL_TRUE 是) */
    BOOL_T bEnable;

    /** 最小区域,格式为"x1,y1;x2,y2" */
    CHAR szAreaMin[IMOS_COORDINATE_STR_LEN_16];

    /** 最大区域,格式为"x1,y1;x2,y2" */
    CHAR szAreaMax[IMOS_COORDINATE_STR_LEN_16];

    /** 保留字段 */
    CHAR szReserve[128];
} IMOS_ANALYSE_SIZE_FILTER_S;

/**
 * @struct tagIMOSBehaviorThruLine
 * @brief "绊线行为"信息
 * @attention
 */
typedef struct tagIMOSBehaviorThruLine
{
    /** 线,格式为"x1,y1;x2,y2" */
    CHAR szLine[IMOS_COORDINATE_STR_LEN_16];

    /** 方向,取值为#IMOS_THRU_LINE_DIRECTION_E */
    ULONG_32 ulDirection;

    /** 高度 */
    ULONG_32 ulHeight;

    /** 颜色 */
    ULONG_32 ulColor;

    /** 保留字段 */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_THRU_LINE_S;

/**
 * @struct tagIMOSBehaviorArea
 * @brief "区域行为"信息
 * @attention
 */
typedef struct tagIMOSBehaviorArea
{
    /** 区域多边形顶点数量,取值为[3-6] */
    ULONG_32 ulPointNum;

    /** 区域多边形:由顶点坐标组成的字符串,格式为"x1,y1;x2,y2;......" */
    CHAR szAreaPolygon[IMOS_COORDINATE_STR_LEN_56];

    /** 方向,取值为#IMOS_AREA_DIRECTION_E */
    ULONG_32 ulDirection;

    /** 颜色 */
    ULONG_32 ulColor;

    /** 保留字段 */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_AREA_S;

/**
 * @struct tagIMOSBehavior
 * @brief 行为信息
 * @attention
 */
typedef union tagIMOSBehavior
{
    /** 绊线行为 */
    IMOS_BEHAVIOR_THRU_LINE_S stThruLine;

    /** 区域行为 */
    IMOS_BEHAVIOR_AREA_S stArea;
} IMOS_BEHAVIOR_U;

/**
 * @struct tagIMOSBehaviorAnalyseRule
 * @brief 行为分析规则
 * @attention
 */
typedef struct tagIMOSBehaviorAnalyseRule
{
    /** 索引,取值为[1-8] */
    ULONG_32  ulIndex;

    /** 是否使能(BOOL_FALSE 否,BOOL_TRUE 是) */
    BOOL_T bEnable;

    /** 分析区域大小过滤信息 */
    IMOS_ANALYSE_SIZE_FILTER_S  stFilter;

    /** 行为类型,取值为#IMOS_BEHAVIOR_TYPE_E */
    ULONG_32 ulBehaviorType;

    /** 行为信息 */
    IMOS_BEHAVIOR_U unBehavior;

    /** 保留字段 */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_ANALYSE_RULE_S;

/**
 * @struct tagIMOSBehaviorAnalyseArithmetic
 * @brief 行为分析算法信息
 * @attention
 */
typedef struct tagIMOSBehaviorAnalyseArithmetic
{
    /** 帧率,取值为[1-60] */
    ULONG_32  ulFrameRate;

    /** 是否去阴影(BOOL_FALSE 否,BOOL_TRUE 是) */
    BOOL_T bShadow;

    /** 保留字段 */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_ANALYSE_ARITHMETIC_S;

/**
 * @struct tagIMOSBehaviorAnalyseInfo
 * @brief 行为分析信息
 * @attention
 */
typedef struct tagIMOSBehaviorAnalyseInfo
{
    /** 是否使能(BOOL_FALSE 否,BOOL_TRUE 是) */
    BOOL_T bEnable;

    /** 算法 */
    IMOS_BEHAVIOR_ANALYSE_ARITHMETIC_S stArithmetic;

    /** 规则 */
    IMOS_BEHAVIOR_ANALYSE_RULE_S astRule[IMOS_BEHAVIOR_RULE_MAX];

    /** 保留字段 */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_ANALYSE_INFO_S;

/* BEGIN: Added by kf0092 for 安全接入外域, 2013年3月15日 */
/**
 * @struct tagSafeCameraInfo
 * @brief 安全接入摄像机
 * @attention
 */
typedef struct tagSafeCameraInfo
{
    /** 安全接入域名称 */
    CHAR szSafeDomainName[IMOS_NAME_LEN];

    /** 安全接入域编码 */
    CHAR szSafeDomainCode[IMOS_CODE_LEN];

    /** 安全接入监视器编码 */
    CHAR szSafeMonitorCode[IMOS_CODE_LEN];

    /** 设备输出视频通道号 */
    ULONG_32 ulDevOutputChannelIndex;

    /** 独占用户角色组名称 */
    CHAR szSafeRoleName[IMOS_NAME_LEN];

    /** 独占用户角色组编码 */
    CHAR szSafeRoleCode[IMOS_CODE_LEN];
}SAFE_CAMERA_INFO_S;

/* END  : Added by kf0092 for 安全接入外域, 2013年3月15日 */


/**
 * @struct tagVinChnlBindCameraBase
 * @brief 摄像机及其绑定通道的基本信息
 * @attention
 */
typedef struct tagVinChnlBindCameraBase
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机信息 */
    CAMERA_INFO_S       stCameraInfo;

    /** 视频输入通道信息 */
    VIN_CHANNEL_S       stVinChannel;

    /** 时间OSD */
    OSD_TIME_S      stOSDTime;

    /** 光学配置参数 */
    OPTICS_PARAM_S      stOpticsParam;

    /** 定位信息 */
    LOCATE_INFO_S stLocateInfo;

    /** 安全接入摄像机信息 */
    SAFE_CAMERA_INFO_S stSafeCameraInfo;
}VINCHNL_BIND_CAMERA_BASE_S;

/**
 * @struct tagVinChnlBindCameraBase
 * @brief 摄像机及其绑定通道的基本信息
 * @attention
 */
typedef struct tagVinChnlBindCameraBaseV2
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机信息 */
    CAMERA_INFO_S       stCameraInfo;

    /** 视频输入通道信息 */
    VIN_CHANNEL_V3_S       stVinChannel;

    /** 时间OSD */
    OSD_TIME_S      stOSDTime;

    /** 光学配置参数 */
    OPTICS_PARAM_S      stOpticsParam;

    /** 定位信息 */
    LOCATE_INFO_S stLocateInfo;

    /** 安全接入摄像机信息 */
    SAFE_CAMERA_INFO_S stSafeCameraInfo;
}VINCHNL_BIND_CAMERA_BASE_V2_S;


/**
 * @struct tagVinChnlBindCameraElement
 * @brief 视频通道全部变长元素结构体
 * @attention
 */
typedef struct tagVinChnlFullVarietyElement
{
    /** 场名OSD个数 */
    ULONG_32           ulOSDNameNum;

    /** 场名OSD */
    OSD_NAME_S      *pstOSDName;

    /** 遮盖区域个数 */
    ULONG_32           ulMaskAreaNum;

    /** 遮盖区域 */
    VIDEO_AREA_S     *pstMaskArea;

    /** 视频流个数 */
    ULONG_32               ulVideoStreamNum;

    /** 视频流信息数组 */
    VIDEO_STREAM_S      *pstVideoStream;

    /** 遮挡检测区域个数 */
    ULONG_32           ulCoverDetecAreaNum;

    /** 遮挡检测区域 */
    VIDEO_AREA_S       *pstCoverDetecArea;

    /** 运动检测区域个数 */
    ULONG_32           ulMotionDetecAreaNum;

    /** 运动检测区域 */
    VIDEO_AREA_S       *pstMotionDetecArea;
}VINCHNL_FULL_VARIETY_ELEMENT_S;

/**
 * @struct tagVinChnlBindCameraV2
 * @brief 摄像机及其绑定通道的信息(支持多行OSD、光学参数配置)
 * @attention
 */
typedef struct tagVinChnlBindCameraV2
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机信息 */
    CAMERA_INFO_S       stCameraInfo;

    /** 视频输入通道信息 */
    VIN_CHANNEL_S       stVinChannel;

    /** OSD信息 */
    MULTI_OSD_INFO_S    stOSDInfo;

    /** 视频流数组中视频流的实际数目, 最大取值为#IMOS_STREAM_MAXNUM_II, 视具体流套餐值而定 */
    ULONG_32               ulVideoStreamNum;

    /** 视频流信息数组 */
    VIDEO_STREAM_S      astVideoStream[IMOS_STREAM_MAXNUM_II];

    /** 检测区域，包含运动检测以及遮挡检测区域 */
    DETECT_AREA_S       stDetectArea;

    /** 光学配置参数 */
    OPTICS_PARAM_S      stOpticsParam;
}VINCHNL_BIND_CAMERA_V2_S;

/**
 * @struct tagVinChnlBindCameraForECR
 * @brief 摄像机及其绑定通道的信息for ECR&NVR
 * @attention
 */
typedef struct tagVinChnlBindCameraForECR
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** 摄像机信息 */
    CAMERA_INFO_S       stCameraInfo;

    /** 视频输入通道信息 */
    VIN_CHANNEL_S       stVinChannel;

    /** OSD信息 */
    MULTI_OSD_INFO_S    stOSDInfo;

    /** 视频流数组中视频流的实际数目, 最大取值为#IMOS_STREAM_MAXNUM, 视具体流套餐值而定 */
    ULONG_32               ulVideoStreamNum;

    /** 视频流信息数组 */
    VIDEO_STREAM_S      astVideoStream[IMOS_STREAM_MAXNUM];

    /** 检测区域，包含运动检测以及遮挡检测区域 */
    DETECT_AREA_S       stDetectArea;

    /** 光学配置参数 */
    OPTICS_PARAM_S      stOpticsParam;
}VINCHNL_BIND_CAMERA_FOR_ECR_S;

/**
 * @struct tagSemaOutputInfoSdkWithTime
 * @brief 输出开关量信息(  带时间)
 * @attention
 */
typedef struct tagSemaOutputInfoSdkWithTimeForECR
{
    /** 输出开关量描述 */
    CHAR        szSemaDesc[IMOS_DESC_LEN];

     /** 输出开关量告警触发方式, 取值1为常开; 2为常闭 */
    ULONG_32       ulTriggerMode;

    /** 输出开关量告警持续时间，单位为秒 */
    ULONG_32       ulOutPutTime;

} SEMA_OUTPUT_INFO_WITHTIME_FOR_ECR_S;

/**
 * @struct tagVoutChnlBindScreen
 * @brief 监视器及其绑定通道的信息
 * @attention
 */
typedef struct tagVoutChnlBindScreen
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S stDCChannelIndex;

    /** 监视器信息 */
    SCREEN_INFO_S       stScreenInfo;

    /** 逻辑输出通道信息 */
    VOUT_CHANNEL_S      stVoutChannel;

    /** OSD信息 */
    OSD_INFO_S          stOSDInfo;

    /** 物理输出通道信息 */
    PHYOUT_CHANNEL_S    stPhyoutChannel;
}VOUTCHNL_BIND_SCREEN_S;


/***************************************************************************************
串口管理
***********************************************************************************/

/**
 * @struct tagSerialInfo
 * @brief 串口信息
 * @attention
 */
typedef struct tagSerialInfo
{
    /** 串口模式, 取值为#IMOS_SERIAL_MODE_E */
    ULONG_32       ulSerialMode;

    /** 串口类型, 取值为#SERIAL_TYPE_E */
    ULONG_32       ulSerialType;

    /** 波特率, 取值为
        #IMOS_BUADRATE_1200
        #IMOS_BUADRATE_2400
        #IMOS_BUADRATE_4800
        #IMOS_BUADRATE_9600
        #IMOS_BUADRATE_19200
        #IMOS_BUADRATE_38400
        #IMOS_BUADRATE_57600
        #IMOS_BUADRATE_115200
    */
    ULONG_32       ulBaudRate;

    /** 数据位, 取值为5~8 */
    ULONG_32       ulDataBit;

    /** 停止位, 取值为1~2 */
    ULONG_32       ulStopBit;

    /** 校验位, 取值为
        #IMOS_PARITY_NULL
        #IMOS_PARITY_ODD
        #IMOS_PARITY_EVEN
    */
    ULONG_32       ulParityBit;

    /** 流控, 0为无流控; 1为软件控制; 2为硬件控制 */
    ULONG_32       ulFlowControl;

} SERIAL_INFO_S;


/**
 * @struct tagSerialQueryItem
 * @brief 串口查询信息列表单元信息
 * @attention
 */
typedef struct tagSerialQueryItem
{
    /** 串口索引 */
    ULONG_32   ulSerialIndex;

    /** 串口类型 */
    ULONG_32   ulSerialType;

    /* 串口模式 */
    ULONG_32   ulSerialMode;
} SERIAL_QUERY_ITEM_S;


/**
 * @struct tagSerialRelationItem
 * @brief 串口相关资源信息项(查询串口相关资源列表时返回)
 * @attention
 */
typedef struct tagSerialRelationItem
{
    /** 资源编码 */
    CHAR    szResCode[IMOS_RES_CODE_LEN];

    /** 资源名称 */
    CHAR    szResName[IMOS_NAME_LEN];

    /** 资源类型, 取值为#IMOS_TYPE_E*/
    ULONG_32 ulResType;

}SERIAL_RELATION_ITEM_S;


/***************************************************************************************
开关量管理
***********************************************************************************/
/**
 * @struct tagSemaInputInfo
 * @brief 输入开关量信息
 * @attention
 */
typedef struct tagSemaInputInfo
{
    /** 输入开关量描述, 可不填 */
    CHAR        szSemaDesc[IMOS_DESC_LEN];

    /** 输入开关量告警触发方式, 取值1为常开; 2为常闭 */
    ULONG_32       ulTriggerMode;

    /** 是否使能, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 线路检测使能, 1为使能; 0为非使能 */
    ULONG_32       ulEnableDetectFlag;
} SEMA_INPUT_INFO_S;


/**
 * @struct tagSemaOutputInfoSdk
 * @brief 输出开关量信息
 * @attention
 */
typedef struct tagSemaOutputInfoSdk
{
    /** 输出开关量描述 */
    CHAR        szSemaDesc[IMOS_DESC_LEN];

     /** 输出开关量告警触发方式, 取值1为常开; 2为常闭 */
    ULONG_32       ulTriggerMode;

} SEMA_OUTPUT_INFO_S;

/**
 * @struct tagSemaOutputInfoV2
 * @brief 输出开关量信息V2
 * @attention
 */
typedef struct tagSemaOutputInfoV2
{
    /** 输出开关量信息 */
    SEMA_OUTPUT_INFO_S  stBaseOutputInfo;

    /** 输出开关量告警持续时间，单位为秒 */
    ULONG_32               ulOutPutTime;

    /** 输出开关量标识 */
    CHAR             szSwitchToken[IMOS_CODE_LEN];

    /**保留 */
    CHAR                szRetention[128];
}SEMA_OUTPUT_INFO_V2_S;


/**
 * @struct tagSemaQueryItem
 * @brief 开关量查询信息项(查询开关量列表时返回)
 * @attention
 */
typedef struct tagSemaQueryItem
{
    /** 开关量索引, 为开关量的编号 */
    ULONG_32       ulSemaIndex;

    /** 开关量类型, 取值0为输入; 1为输出 */
    ULONG_32       ulSemaType;

    /** 输入开关量告警触发方式, 取值1为常开; 2为常闭 */
    ULONG_32       ulTriggerMode;

    /** 是否使能，1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

} SEMA_QUERY_ITEM_S;

/**
 * @struct tagSemaQueryItemV2
 * @brief 开关量查询信息项V2(查询开关量列表时返回)
 * @attention
 */
typedef struct tagSemaQueryItemV2
{
    /** 开关量查询信息项 */
    SEMA_QUERY_ITEM_S stSemaQueryItemInfo;

    /** 开关量所在设备编码 */
    CHAR    szDevCode[IMOS_CODE_LEN];

    /** 开关量描述 */
    CHAR    szSemaDesc[IMOS_DESC_LEN];

    /** 告警源或者告警输出是否使能, 1为使能, 0为非使能 */
    ULONG_32   ulAlarmIOEnableFlag;

    /** 告警源或者告警输出编码, 告警源或者告警输出非使能时无效 */
    CHAR    szAlarmIOCode[IMOS_CODE_LEN];

    /** 告警源或者告警输出名称, 告警源或者告警输出非使能时无效 */
    CHAR    szAlarmIOName[IMOS_NAME_LEN];

    /** 输入开关量的线路检测使能, 1为使能; 0为非使能. 仅为输入开关量时有效 */
    ULONG_32   ulEnableDetectFlag;

    /** 告警输出打开的时间. 仅告警输出使能时有效 */
    ULONG_32   ulOutputTime;

    /** 保留字段 */
    CHAR    szReserve[64];
} SEMA_QUERY_ITEM_V2_S;


/************************************************************************************************************
OSD
************************************************************************************************************/

/**
 * @struct tagOsdImageListItem
 * @brief OSD图片信息
 * @attention
 */
typedef struct tagOsdImageListItem
{
    /** OSD图片编码 */
    CHAR szOsdImageCode[IMOS_RES_CODE_LEN];

    /** OSD图片名 */
    CHAR    szName[IMOS_NAME_LEN];
}OSD_IMAGE_LIST_ITEM_S;



/*******************************************************************************
模板管理
********************************************************************************/
/**
 * @struct tagVideoInChannelParam
 * @brief 视频输入参数模板
 * @attention
 */
typedef struct tagVideoInChannelParam
{
    /** 组播地址 */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口, 取值为10002-65534, 且必须为偶数 */
    ULONG_32 ulMulticastPort;

    /** MS选择的适应策略, 1为自适应; 0为指定MS，2为不经过MS, 取值为#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulIsAutofit;

    /** 是否启动图像遮挡检测告警, 1为启动; 0为不启动 */
    ULONG_32 ulEnableKeepout;

    /** 是否启动运动检测告警, 1为启动运动检测告警; 0为不启动运动检测告警 */
    ULONG_32 ulEnableMotionDetect;

    /** 是否启动视频丢失告警, 1为启动视频丢失告警; 0为不启动视频丢失告警 */
    ULONG_32 ulEnableVideoLost;

    /** 绑定的串口编号, 如无则填写0 */
    ULONG_32 ulSerialIndex;

    /** 亮度, 取值为（0~255） */
    ULONG_32 ulBrightness;

    /** 对比度, 取值为（0~255） */
    ULONG_32 ulContrast;

    /** 饱和度, 取值为（0~255） */
    ULONG_32 ulSaturation;

    /** 色调, 取值为（0~255） */
    ULONG_32 ulTone;

    /** 是否启动静音, 1为启动静音; 0为不启动静音 */
    ULONG_32 ulIsMute;

    /** 音频编码, 取值为#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioCoding;

    /** 音频声道, 取值为#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** 音频采样率, 取值为#IMOS_AUDIO_SAMPLING_E */
    ULONG_32 ulSamplingRate;

    /** 音频码率, 不可配置 */
    ULONG_32 ulAudioCodeRate;

    /** 音频增益值, 取值为(0-255) */
    ULONG_32 ulIncrement;
}VIN_CHANNEL_PARAM_S;

/**
 * @struct tagVideoStreamParam
 * @brief 视频输入流参数模板
 * @attention
 */
typedef struct tagVideoStreamParam
{
    /** 码流类型 */
    ULONG_32       ulStreamType;

    /** 流索引 */
    ULONG_32       ulStreamIndex;

    /** 流使能标识 */
    ULONG_32       ulEnabledFlag;

    /** 流传输方式 */
    ULONG_32       ulTranType;

    /** 编码格式,枚举值为IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /** 分辨率 */
    ULONG_32       ulResolution;

    /** 码率 */
    ULONG_32       ulBitRate;

    /** 帧率 */
    ULONG_32       ulFrameRate;

    /** GOP模式 */
    ULONG_32       ulGopMode;

    /** I帧间隔 */
    ULONG_32       ulIFrameInterval;

    /** 图像质量 */
    ULONG_32       ulImageQuality;

    /** 流编码模式 CBR VBR */
    ULONG_32       ulEncodeMode;

    /** 优先级，仅在编码模式为CBR时可设置。0-连贯性方式，1-清晰性方式 */
    ULONG_32       ulPriority;

    /** 码流平滑，枚举值为IMOS_STREAM_SMOOTH_E，目前只支持0和5的设置 */
    ULONG_32       ulSmoothValue;

}VIDEO_STREAM_PARAM_S;

/**
 * @struct tagVideoAreaParam
 * @brief 视频输入区域参数
 * @attention
 */
typedef struct tagVideoAreaParam
{
    /** 区域索引 */
    ULONG_32       ulAreaIndex;

    /** 是否使能 */
    ULONG_32       ulEnabledFlag;

    /** 灵敏度 */
    ULONG_32       ulSensitivity;

    /** 区域坐标 */
    AREA_SCOPE_S stAreaScope;

    /** 视频区域类型: 遮挡、移动、遮盖，参见枚举值:#VIDEO_AREA_TYPE_E */
    ULONG_32       ulAreaType;

}VIDEO_AREA_PARAM_S;

/**
 * @struct tagVinChannelTemplet
 * @brief 视频输入通道模板
 * @attention
 */
typedef struct tagVinChannelTemplet
{
    /** 视频输入参数模板 */
    VIN_CHANNEL_PARAM_S stVinChannel;

    /** 设备型号。跟设备类型相关的模板, 需要用到此字段 */
    ULONG_32 ulDevType;

    /** dsp image选择，取值为#IMOS_STREAM_RELATION_SET_E */
    ULONG_32 ulEncodeSet;

    /** 制式 ，取值为IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 视频输入流参数模板 */
    VIDEO_STREAM_PARAM_S astVideoStream[IMOS_STREAM_MAXNUM_II];
}VIN_CHANNEL_TEMPLET_S;


/**
 * @struct tagChannelTempletBasic
 * @brief 通道模板基本信息
 * @attention
 */
typedef struct tagChannelTempletBasic
{
    /** 模板名称 */
    CHAR szTempletName[IMOS_NAME_LEN];

    /** 模板最后更新时间 */
    CHAR  szLastUpdateTime[IMOS_TIME_LEN];
}CHANNEL_TEMPLET_BASIC_S;


/**
 * @struct tagChannelTempQueryItem
 * @brief 通道模板信息项(查询通道模板列表时返回)
 * @attention
 */
typedef struct tagChannelTempQueryItem
{
    /** 模板编码 */
    CHAR        szTempletCode[IMOS_RES_CODE_LEN];

    /** 模板名称 */
    CHAR        szTempletName[IMOS_NAME_LEN];

    /** 模板最后更新时间 */
    CHAR        szLastUpdateTime[IMOS_TIME_LEN];

    /** 设备型号, 取值为#IMOS_DEVICE_TYPE_E */
    ULONG_32       ulDevType;

    /** 流套餐, 取值为#IMOS_STREAM_RELATION_SET_E */
    ULONG_32       ulEncodeSet;

    /** 制式, 取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32       ulStandard;
}CHANNEL_TEMP_QUERY_ITEM_S;


/**
 * @struct tagECChannelTemplet
 * @brief EC通道模板
 * @attention
 */
typedef struct tagECChannelTemplet
{
    /** 模板基本信息 */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

    /** 视频输入参数模板 */
    VIN_CHANNEL_TEMPLET_S       stVinChannelTemp;
}EC_CHANNEL_TEMPLET_S;



/**
 * @struct tagVideoOutChannelParam
 * @brief 视频输出通道信息
 * @attention
 */
typedef struct tagVideoOutChannelParam
{
    /** 码流类型, 取值为#IMOS_STREAM_TYPE_E, 目前仅支持#IMOS_ST_TS */
    ULONG_32 ulStreamType;

    /** 是否启动防抖动, 1为启动; 0为不启动 */
    ULONG_32 ulEnableJitterBuff;
}VOUT_CHANNEL_PARAM_S;


/**
 * @struct tagPhyOutChannelParam
 * @brief 视频输出参数
 * @attention
 */
typedef struct tagPhyOutChannelParam
{
    /** 工作模式，取值为1和4，代表BNC口的分屏数 */
    ULONG_32 ulPhyoutMode;

    /** 解码格式，取值为#IMOS_VIDEO_FORMAT_E */
    ULONG_32 ulDecodeFormat;

    /** 音频格式，取值为#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioFormat;

    /** 声道设置，取值为#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** 是否启用语音功能, 1为启用; 0为不启用 */
    ULONG_32 ulAudioEnabled;

    /** 输出音量, 取值为1~7 */
    ULONG_32 ulVolume;

    /** 音频输出选择, 视工作模式参数#ulPhyoutMode而定。如果工作模式取值为1, 则该值为1; 如果工作模式取值为4, 则该值取值为1~4 */
    ULONG_32 ulOutputIndex ;
}PHYOUT_CHANNEL_PARAM_S;


/**
 * @struct tagVoutChannelTemplet
 * @brief 视频输出通道模板
 * @attention
 */
typedef struct tagVoutChannelTemplet
{

    /** 视频输出通道模板 */
    VOUT_CHANNEL_PARAM_S    stVoutChannel;

    /** 设备型号，取值为#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulDevType;

    /** 流套餐选择，取值为#IMOS_STREAM_RELATION_SET_E, 目前视频输出通道仅支持
        #IMOS_SR_H264_SHARE，
        #IMOS_SR_MPEG4_SHARE
        #IMOS_SR_MPEG2_SHARE
        #IMOS_SR_H264_MJPEG
    */
    ULONG_32 ulEncodeSet;

    /** 制式，取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 视频物理输出通道模板 */
    PHYOUT_CHANNEL_PARAM_S stPhyVoutChannel;
}VOUT_CHANNEL_TEMPLET_S;


/**
 * @struct tagDCChannelTemplet
 * @brief DC通道模板
 * @attention
 */
typedef struct tagDCChannelTemplet
{
    /** 模板基本信息 */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

    /** 视频输出参数模板 */
    VOUT_CHANNEL_TEMPLET_S      stVoutChannelTemp;

}DC_CHANNEL_TEMPLET_S;


/**
 * @struct tagPlanTemplet
 * @brief 时间计划模板
 * @attention
 */
typedef struct tagPlanTemplet
{
    /** 模板基本信息 */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

    /** 日循环或者周循环, 取值为:MM_JOBSCHDTYPE_E */
    ULONG_32                       ulCycleType;

    /** 时间计划结构体 */
    PLAN_TIME_S                 stPlanTimeInfo;
}PLAN_TEMPLET_S;

/*------------------------------------------------------------------------------------------*/

/**
 * @struct tagSnmpV1Special
 * @brief SNMP_V1的特性参数
 * @attention
 */
typedef struct tagSnmpV1Special
{
    /** 读取团体字 */
    CHAR  szRoCommunity[IMOS_STRING_LEN_64];

    /** 写入团体字 */
    CHAR  szRwCommunity[IMOS_STRING_LEN_64];
}SNMPV1_SPECIAL_S;

/**
 * @struct tagSnmpV3Special
 * @brief SNMP_V3的特性参数
 * @attention
 */
typedef struct tagSnmpV3Special
{
    /** 安全级别 */
    ULONG_32 ulSecurityMode;

    /** 认证类型 */
    ULONG_32 ulAuthScheme;

    /** 认证密码 */
    CHAR  szAuthPassword[IMOS_STRING_LEN_64];

    /** 加密类型 */
    ULONG_32 ulPrivScheme;

    /** 加密密码 */
    CHAR  szPrivPassword[IMOS_STRING_LEN_64];

}SNMPV3_SPECIAL_S;

/**
 * @struct tagSnmpSpecial
 * @brief SNMP的特性模板
 * @attention
 */
typedef struct tagSnmpSpecial
{
    /** SNMP_V1的特性参数 */
    SNMPV1_SPECIAL_S stSnmpV1Special;

    /** SNMP_V3的特性参数 */
    SNMPV3_SPECIAL_S stSnmpV3Special;

}SNMP_SPECIAL_S;

/**
 * @struct tagSnmpTemp
 * @brief SNMP模板
 * @attention
 */
typedef struct tagSnmpTemp
{
    /** 协议端口号 */
    ULONG_32 ulSnmpPort;

    /** 报文老化时间 */
    ULONG_32 ulTimeout;

    /** 报文重试次数 */
    ULONG_32 ulRetries;

    /** 报文对应版本号 */
    ULONG_32 ulSnmp_version;

    /** 上下文名称 */
    CHAR  szContextName[IMOS_STRING_LEN_64];

    /** 安全模型名称 */
    CHAR  szSecurityName[IMOS_STRING_LEN_64];

    /** SNMP的特性模板 */
    SNMP_SPECIAL_S              stSnmpSpecial;

    /** 模板基本信息 */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

}SNMP_TEMP_S;


/*******************************************************************************
DM
********************************************************************************/

/**
* @struct tagDMInfo
* @brief DM信息结构体
* @attention 无
*/
typedef struct tagDMInfo
{
    /** DM编码, DM的唯一标识 */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** DM名称 */
    CHAR  szDMName[IMOS_NAME_LEN];

    /** DM类型，目前值为0 */
    ULONG_32 ulDMType;

    /** DM所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** DM描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** 保留字段 */
    CHAR szReserve[32];
}DM_INFO_S;


/**
* @struct tagDMQueryItem
* @brief DM信息项(查询DM列表时返回)
* @attention 无
*/
typedef struct tagDMQueryItem
{
    /** DM编码, DM的唯一标识 */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** DM名称 */
    CHAR  szDMName[IMOS_NAME_LEN];

    /** DM类型, 取值0: DM3.0, 1: DM3.5 */
    ULONG_32 ulDMType;

    /** DM所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** DM所属组织名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /**设备地址 */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，枚举值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** 保留字段 */
    CHAR szReserve[32];
}DM_QUERY_ITEM_S;


/***************************************************************************
设备-存储设备
****************************************************************************/


/**
 * @struct tagStoreDevInfo
 * @brief 存储设备(IPSAN)信息
 * @attention
 */
typedef struct tagStoreDevInfo
{
    /** 存储设备编码 */
    CHAR  szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备名称 */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** IPSAN 存储设备类型 ，1-VX 2-EX */
    ULONG_32 ulStoreDevType;

    /** 存储设备地址 */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** 存储设备所属DM编码 */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备登录用户名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 存储设备登录用户密码 */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** 存储设备描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** IPSAN 存储设备子类型(只有在设备类型为VX的时候才有效) ，0：VX1500，1：VX1500-E，2：VX1600 */
    ULONG_32   ulStoreDevSubType;

    /** 保留字段 */
    CHAR szReserve[60];
}STORE_DEV_INFO_S;


/**
 * @struct tagStoreDevQueryItem
 * @brief 存储设备信息项(查询存储设备列表时返回)
 * @attention
 */
typedef struct tagStoreDevQueryItem
{
    /** 存储设备编码 */
    CHAR    szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备名称 */
    CHAR    szStoreDevName[IMOS_NAME_LEN];

    /** IPSAN 存储设备类型，1-VX; 2-EX */
    ULONG_32   ulStoreDevType;

    /** 所属DM编码 */
    CHAR    szDMCode[IMOS_DEVICE_CODE_LEN];

    /** 所属DM名称 */
    CHAR    szDMName[IMOS_NAME_LEN];

    /** 设备地址类型，1-IPv4; 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** 设备地址 */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** 存储设备总容量,单位:M(兆)  */
    ULONG_32   ulStoreDevTotalSize;

    /** 存储设备已使用容量,单位:M(兆)  */
    ULONG_32   ulStoreDevUsedSize;

    /** 存储运行状态, 参见mp_ism_pub.h中的枚举"设备存储运行状态",
        0-设备无法访问，1-设备存储正常，2-设备衰退(部分资源无法访问，部分资源存储正常) */
    ULONG_32   ulStoreRunStatus;

    /** 设备是否在线, 取值#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，取值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** IPSAN 存储设备子类型(只有在设备类型为VX的时候才有效) ，0：VX1500，1：VX1500-E，2：VX1600 */
    ULONG_32   ulStoreDevSubType;

    /** 保留字段 */
    CHAR szReserve[60];
}STORE_DEV_QUERY_ITEM_S;



/**
 * @struct tagStoreDevSimpleQueryItem
 * @brief 存储设备简单信息项(查询存储设备简单信息时返回)
 * @attention
 */
typedef struct tagStoreDevSimpleQueryItem
{
    /** 存储设备编码 */
    CHAR    szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备类型，取值为#STORE_DEV_TYPE_E */
    ULONG_32       ulStoreDevType;

    /** 存储设备名称 */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** 存储设备总容量,单位:M(兆) */
    ULONG_32       ulStoreDevTotalSize;

    /** 存储设备已用容量容量,单位:M(兆) */
    ULONG_32       ulStoreDevUsedSize;

}STORE_DEV_SIMPLE_QUERY_ITEM_S;

/***************************************************************************
设备-VX500辅机
****************************************************************************/

/**
 * @struct tagVX500Info
 * @brief VX500设备信息
 * @attention
 */
typedef struct tagVX500Info
{
    /** VX500设备编码, VX500的唯一标识 */
    CHAR  szVX500Code[IMOS_DEVICE_CODE_LEN];

    /** VX500设备名称 */
    CHAR  szVX500Name[IMOS_NAME_LEN];

    /** VX500设备类型, 是保留项, 目前默认为0 */
    ULONG_32 ulVX500Type;

    /** VX500所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备描述, 可以不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** 保留字段 */
    CHAR szReserve[32];
}VX500_INFO_S;


/**
 * @struct tagVX500QueryItem
 * @brief VX500信息项(查询VX500列表时返回)
 * @attention
 */
typedef struct tagVX500QueryItem
{
    /** VX500设备编码 */
    CHAR    szVX500Code[IMOS_DEVICE_CODE_LEN];

    /** VX500设备名称 */
    CHAR    szVX500Name[IMOS_NAME_LEN];

    /** VX500设备类型，是保留项，目前默认填写为0 */
    ULONG_32   ulVX500Type;

    /** VX500所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

     /** VX500所属组织名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** 设备地址类型，1-IPv4; 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** 设备地址 */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** VX500设备总容量,单位:M(兆) */
    ULONG_32   ulVX500DevTotalSize;

    /** VX500设备已使用容量,单位:M(兆) */
    ULONG_32   ulVX500DevUsedSize;

    /** 存储运行状态, 参见mp_ism_pub.h中的枚举"设备存储运行状态",
        0-设备无法访问，1-设备存储正常，2-设备衰退(部分资源无法访问，部分资源存储正常) */
    ULONG_32   ulStoreRunStatus;


    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，取值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** 保留字段 */
    CHAR szReserve[32];
}VX500_QUERY_ITEM_S;


/**
 * @struct tagArrayInfo
 * @brief 阵列信息
 * @attention
 */
typedef struct tagArrayInfo
{
    /** 阵列名称 */
    CHAR       szArrayName[IMOS_NAME_LEN];

    /** 槽位号数组中实际的槽位个数, 最大值为#IMOS_ARRAY_SLOT_MAXNUM */
    ULONG_32       ulNumber;

    /** 槽位号数组 */
    ULONG_32       aulSlotNum[IMOS_ARRAY_SLOT_MAXNUM];

    /** 阵列类型，0-JBOD 1-RAID0 2-RAID1 3-RAID5 4-RAID10 */
    ULONG_32       ulArrayType;
} ARRAY_INFO_S;


/**
 * @struct tagArrayStatusInfo
 * @brief 阵列状态信息
 * @attention
 */
typedef struct tagArrayStatusInfo
{
    /** 阵列状态,0-良好 1-重建 2-衰退 3-无法使用 4-初始化 */
    ULONG_32   ulArrayStatus;

    /** 阵列总容量,单位:M(兆) */
    ULONG_32   ulArrayTotleSize;

    /** 已用容量,单位:M(兆) */
    ULONG_32   ulArrayUsedSize;

    /** 是否已经虚拟化 */
    BOOL_T  bisVirtualized;

    /** 阵列信息 */
    ARRAY_INFO_S    stArrayInfo;

    /** 重建进度 */
    ULONG_32   ulRebuildProgress;
} ARRAY_STATUS_INFO_S;


/**
 * @struct tagSlotInfo
 * @brief 磁盘信息
 * @attention
 */
typedef struct tagSlotInfo
{
    /** 槽位号 */
    ULONG_32       ulSlotNum;

    /** 是否已经有硬盘 */
    ULONG_32       ulHasDisk;

    /** 已用容量,单位:M(兆)  */
    ULONG_32       ulUsedSize;

    /** 磁盘总容量,单位:M(兆)  */
    ULONG_32       ulDiskCapacity;

    /** 磁盘状态，枚举值为#SS_DISK_STATE_E */
    ULONG_32       ulStatus;

    /** 磁盘厂商 */
    CHAR        szManufacturer[IMOS_NAME_LEN];
} SLOT_INFO_S;


/*******************************************************************************
MS
********************************************************************************/

/**
 * @struct tagMSInfo
 * @brief MS设备信息
 * @attention
 */
typedef struct tagMSInfo
{
    /** MS设备编码, MS的唯一标识 */
    CHAR  szMSCode[IMOS_DEVICE_CODE_LEN];

    /** MS设备名称 */
    CHAR  szMSName[IMOS_NAME_LEN];

    /** MS所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN - IMOS_STRING_LEN_128];

	/* MS类型，参见枚举MS_DEV_TYPE_E */
	ULONG_32  ulMSType;

	/* 保留字段 */
    CHAR    szReserve[124];


}MS_INFO_S;


/**
 * @struct tagMSQueryItem
 * @brief MS信息项(查询MS列表时返回)
 * @attention
 */
typedef struct tagMSQueryItem
{
    /** MS编码 */
    CHAR    szMSCode[IMOS_DEVICE_CODE_LEN];

    /** MS名称 */
    CHAR    szMSName[IMOS_NAME_LEN];

    /** MS所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

     /** MS所属组织名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** MS设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** 设备地址 */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，取值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

}MS_QUERY_ITEM_S;


/*******************************************************************************
TS
********************************************************************************/

/**
 * @struct tagTSInfo
 * @brief TS设备信息
 * @attention
 */
typedef struct tagTSInfo
{
    /** TS设备编码, TS的唯一标识 */
    CHAR  szTSCode[IMOS_DEVICE_CODE_LEN];

    /** TS设备名称 */
    CHAR  szTSName[IMOS_NAME_LEN];

    /** TS所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备描述, 可不填 */
    CHAR    szDevDesc[IMOS_DESC_LEN - IMOS_STRING_LEN_128];

	/*TS类型，参见枚举TS_DEV_TYPE_E*/
	ULONG_32  ulTSType;

	/* 保留字段 */
    CHAR    szReserve[124];	


}TS_INFO_S;

/**
 * @struct tagTSQueryItem
 * @brief TS信息项(查询TS列表时返回)
 * @attention
 */
typedef struct tagTSQueryItem
{
    /** TS编码 */
    CHAR    szTSCode[IMOS_DEVICE_CODE_LEN];

    /** TS名称 */
    CHAR    szTSName[IMOS_NAME_LEN];

    /** TS所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

     /** TS所属组织名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** TS设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** 设备地址 */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，取值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

}TS_QUERY_ITEM_S;

/* Begin added by l01420, 2014-6-30 for 自定义TS转码策略 */
/**
 * @struct tagTSRuleUAInfo
 * @brief TS规则中的UA信息
 * @attention
 */
typedef struct tagTSRuleUAInfo
{   
    /** UA类型 ，取值范围TS_RULE_SRC_TYPE_E或者TS_RULE_DST_TYPE_E*/
    ULONG_32    ulUAType;

    /** UA描述字段，默认需填写UA的编码*/
    CHAR        szUACode[IMOS_CODE_LEN];

    /** UA名字*/
    CHAR        szUAName[IMOS_NAME_LEN];
}TS_RULE_UA_INFO_S;

/**
 * @struct tagTSRuleInfo
 * @brief TS规则信息
 * @attention
 */
typedef struct tagTSRuleInfo
{
    /* 规则名称*/
    CHAR                szRuleName[IMOS_NAME_LEN];
    
    /* 规则编码 */
    CHAR                szRuleCode[IMOS_CODE_LEN];
    
    /* 是否启用此规则 */
    BOOL_T              bIsEnable;

    /**
       *    需要转到的目标流类型，取值范围IMOS_STREAM_TYPE_E, 
       *    只保留IMOS_ST_TS, IMOS_ST_H3C_ES,IMOS_ST_PS,IMOS_ST_3984四种，其他去掉
       */
    ULONG_32            ulStreamType;

    /* 流传输方式，取值范围IMOS_TRANS_TYPE_E， 目前保留，不填 */
    ULONG_32            ulTransType;

    /* 保留字段 */
    CHAR                szReserved[IMOS_STRING_LEN_512];
}TS_RULE_INFO_S;


/**
 * @struct tagTSRuleQueryInfo
 * @brief TS规则信息(查询接口使用)
 * @attention
 */
typedef struct tagTSRuleQueryInfo
{
    /* 规则名称*/
    CHAR                szRuleName[IMOS_NAME_LEN];
    
    /* 规则编码 */
    CHAR                szRuleCode[IMOS_CODE_LEN];
    
    /* 是否启用此规则 */
    BOOL_T              bIsEnable;

    /**
       *    需要转到的目标流类型，取值范围IMOS_STREAM_TYPE_E, 
       *    只保留IMOS_ST_TS, IMOS_ST_H3C_ES,IMOS_ST_PS,IMOS_ST_3984四种，其他去掉
       */
    ULONG_32            ulStreamType;

    /* 流传输方式，取值范围IMOS_TRANS_TYPE_E， 目前保留，不填 */
    ULONG_32            ulTransType;

    /* 保留字段 */
    CHAR                szReserved[IMOS_STRING_LEN_512];

}TS_RULE_QUERY_ITEM_S;
/* End added by l01420, 2014-6-30 for 自定义TS转码策略 */


/***************************************************************************
共享摄像机
****************************************************************************/

/**
 * @struct tagShareCameraBase
 * @brief 共享摄像机基本信息
 * @attention
 */
typedef struct tagShareCameraBase
{
    /** 摄像机名称 */
    CHAR   szCamName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR   szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机互联编码 */
    CHAR   szCamShareCode[IMOS_RES_CODE_LEN];

    /** 摄像机共享的权限 */
    ORG_AUTHORITY_S             stAuthority;
 }SHARE_CAMERA_BASE_S;

/**
 * @struct tagShareCameraBaseV2
 * @brief 共享摄像机基本信息V2
 * @attention
 */
typedef struct tagShareCameraBaseV2
{
    SHARE_CAMERA_BASE_S   stShareCamera;

    /** 父组织节点编码 */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];
 }SHARE_CAMERA_BASE_V2_S;

/**
* @struct tagShareCamInfo
* @brief 共享摄像机信息项(查询共享摄像机列表时返回)
*/
typedef struct tagShareCamInfo
{

    /** 共享摄像机基本信息 */
    SHARE_CAMERA_BASE_S stShareCamBaseInfo;

    /** 共享摄像机状态,取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE */
    ULONG_32                   ulDevStatus;

    /** 是否为本域设备，1为本域设备，0为非本域设备 */
    BOOL_T                  bIsLocalDev;

    /** 摄像机所属外域编码，摄像机为外域共享来时使用 */
    CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 摄像机所属EC编码 */
    CHAR                    szECCode[IMOS_DEVICE_CODE_LEN];
}SHARE_CAM_INFO_S;
/**
* @struct tagShareCamInfoV2
* @brief 共享摄像机单元信息V2
*/
typedef struct tagShareCamInfoV2
{
    /** 共享摄像机基本信息 */
    SHARE_CAMERA_BASE_V2_S     stShareCamBaseInfo;

    /** 摄像机状态,取值为IMOS_DEV_STATUS_ONLINE/IMOS_DEV_STATUS_OFFLINE */
    ULONG_32                   ulDevStatus;

    /** 是否为本域设备，1表示是，0表示否 */
    BOOL_T                  bIsLocalDev;

    /** 是否已共享给外域，1表示是，0表示否 */
    BOOL_T                  bIsShared;

    /** 摄像机支持的流数目 */
    ULONG_32                   ulStreamNum;

    /** 摄像机所属外域编码，摄像机为外域共享来时使用 */
    CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 摄像机所属EC编码 */
    CHAR                    szECCode[IMOS_DEVICE_CODE_LEN];
}SHARE_CAM_INFO_V2_S;


/**
* @struct tagShareCamList
* @brief 共享摄像机列表信息
*/
typedef struct tagShareCamList
{
    /** 摄像机所属域编码 */
    CHAR                    szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 摄像机所属域名称 */
    CHAR                    szDomainName[IMOS_NAME_LEN];

    /** 操作类型，取值为 AS_DEVSHARE_OPERATION_TYPE_E */
    ULONG_32                   ulOperType;

    /** 本次推送的设备数目 */
    ULONG_32                   ulDevNum;

    /** 共享摄像机信息列表 */
    SHARE_CAM_INFO_S    astCamInfo[IMOS_ONCE_SHARE_RES_MAXNUM];
}SHARE_CAM_LIST_S;


/***************************************************************************
共享组织
****************************************************************************/

/**
 * @struct tagShareOrgBase
 * @brief 共享组织基本信息
 * @attention
 */
typedef struct tagShareOrgBase
{
     /** 组织节点编码 */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 组织节点名称 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** 父组织节点编码 */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 组织共享给外域时的对外编码 */
    CHAR szOrgShareCode[IMOS_RES_CODE_LEN];

    /** 组织状态 */
    ULONG_32 ulStatus;

 }SHARE_ORG_BASE_S;


/**
* @struct tagShareOrgInfo
* @brief 共享组织单元信息
*/
typedef struct tagShareOrgInfo
{
    /** 组织所属外域编码，组织为外域共享来时使用 */
    CHAR                szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 是否已共享给外域，1表示是，0表示否 */
    BOOL_T              bIsShared;

    /** 是否自动共享给外域，#BOOL_TRUE表示自动共享给外域，反之取值为#BOOL_FALSE */
    BOOL_T bIsAutoShare;

    /** 共享组织基本信息 */
    SHARE_ORG_BASE_S    stShareOrgBaseInfo;

}SHARE_ORG_INFO_S;

/***************************************************************************
共享告警源
****************************************************************************/

/**
 * @struct tagShareAlarmSrcBase
 * @brief 共享告警源基本信息
 * @attention
 */
typedef struct tagShareAlarmSrcBase
{
    /** 告警源编码 */
    CHAR        szAlarmSrcCode[IMOS_RES_CODE_LEN];

    /** 告警源的名称 */
    CHAR        szAlarmSrcName[IMOS_NAME_LEN];

    /** 父组织节点编码 */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 告警源共享编码 */
    CHAR   szAlarmSrcShareCode[IMOS_RES_CODE_LEN];

 }SHARE_ALARMSRC_BASE_S;


/**
* @struct tagShareAlarmSrcInfo
* @brief 共享告警源单元信息
*/
typedef struct tagShareAlarmSrcInfo
{
    /** 告警源所属外域编码，告警源为外域共享来时使用 */
    CHAR                szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 是否已共享给外域，1表示是，0表示否 */
    BOOL_T              bIsShared;

    /** 共享告警源基本信息 */
    SHARE_ALARMSRC_BASE_S    stShareAlmSrcBaseInfo;

}SHARE_ALARMSRC_INFO_S;

/***************************************************************************
共享告警输出
****************************************************************************/
/**
 * @struct tagShareAlarmOutBase
 * @brief 共享告警输出基本信息
 * @attention
 */
typedef struct tagShareAlarmOutBase
{
    /** 告警输出编码 */
    CHAR        szAlarmOutCode[IMOS_CODE_LEN];

    /** 告警输出的名称 */
    CHAR        szAlarmOutName[IMOS_NAME_LEN];

    /** 父组织节点编码 */
    CHAR        szParentOrgCode[IMOS_CODE_LEN];

    /** 告警输出共享编码 */
    CHAR        szAlarmOutShareCode[IMOS_CODE_LEN];

 }SHARE_ALARMOUT_BASE_S;

/**
* @struct tagShareAlarmOutInfo
* @brief 共享告警输出单元信息
*/
typedef struct tagShareAlarmOutInfo
{
    /** 告警输出所属外域编码，告警输出为外域共享来时使用 */
    CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 是否已共享给外域，1表示是，0表示否 */
    BOOL_T                      bIsShared;

    /** 共享告警输出基本信息 */
    SHARE_ALARMOUT_BASE_S       stShareAlmOutBaseInfo;

}SHARE_ALARMOUT_INFO_S;

/***************************************************************************
共享地图
****************************************************************************/

/**
 * @struct tagShareMapBase
 * @brief 共享地图基本信息
 * @attention
 */
typedef struct tagShareMapBase
{
     /** 地图编码 */
    CHAR szMapCode[IMOS_CODE_LEN];

    /** 地图名称 */
    CHAR szMapName[IMOS_NAME_LEN];

    /** 父组织节点编码 */
    CHAR szParentOrgCode[IMOS_CODE_LEN];

    /** 地图共享给外域时的对外编码 */
    CHAR szMapShareCode[IMOS_CODE_LEN];

 }SHARE_MAP_BASE_S;


/**
* @struct tagShareMapInfo
* @brief 共享地图信息
*/
typedef struct tagShareMapInfo
{
    /** 地图所属外域编码，地图为外域共享来时使用 */
    CHAR                szExDomainCode[IMOS_CODE_LEN];

    /** 是否已共享给外域，1表示是，0表示否 */
    BOOL_T              bIsShared;

    /** 共享地图基本信息 */
    SHARE_MAP_BASE_S    stShareMapBaseInfo;

}SHARE_MAP_INFO_S;

/***************************************************************************
预置位
****************************************************************************/

/**
 * @struct tagPresetInfo
 * @brief 预置位信息
 * @attention
 */
typedef struct tagPresetInfo
{
    /** 预置位值, 取值范围为#PTZ_PRESET_MINVALUE~服务器配置文件里配置的预置位最大值 */
    ULONG_32       ulPresetValue;

    /** 预置位描述, 需要填写 */
    CHAR        szPresetDesc[IMOS_DESC_LEN];
 }PRESET_INFO_S;


/***************************************************************************
巡航路线
****************************************************************************/

/**
 * @struct tagCruisePathItem
 * @brief 巡航路线中的预置位信息
 * @attention
 */
typedef struct tagCruisePathItem
{
    /** 序号，标识该预置位在巡航路线中的执行顺序 */
    ULONG_32       ulSeqID;

    /** 摄像机预置位值，如1、2等，取值范围为#PTZ_PRESET_MINVALUE~服务器配置文件里配置的预置位最大值
        扩展支持轨迹巡航
            901～909,向上运动,速度为1～9
            911～919,向下运动,速度为1～9
            921～929,向左运动,速度为1～9
            931～939,向右运动,速度为1～9 */
    ULONG_32       ulPresetValue;

    /** 预置位描述 */
    CHAR        szPresetDesc[IMOS_DESC_LEN];

    /** 预置位停留时间, 最大值为64 */
    ULONG_32       ulPreSetStopTime;
}CRUISE_PATH_ITEM_S;

/**
 * @struct tagCruisePathInfo
 * @brief 巡航路线信息
 * @attention
 */
typedef struct tagCruisePathInfo
{
    /** 摄像机名称 */
    CHAR                        szCamName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR                        szCamCode[IMOS_RES_CODE_LEN];

    /** 巡航路线名称 */
    CHAR                        szCruisePathName[IMOS_NAME_LEN];

    /** 巡航路线预置位数组中预置位的实际数目, 取值不超过#IMOS_CRUISE_PATH_PRESET_MAX_COUNT */
    ULONG_32                       ulCruisePathItemNum;

    /** 巡航路线预置位数组 */
    CRUISE_PATH_ITEM_S          astCruisePathItemList[IMOS_CRUISE_PATH_PRESET_MAX_COUNT];

    /** 保留字段 */
    CHAR szReserve[8];
}CRUISE_PATH_INFO_S;

/**
 * @struct tagCruisePathQueryItem
 * @brief 巡航路线信息项(查询巡航路线列表时返回)
 * @attention
 */
typedef struct tagCruisePathQueryItem
{
   /** 巡航路线编码 */
   CHAR     szCruisePathCode[IMOS_RES_CODE_LEN];

   /** 巡航路线名称 */
   CHAR     szCruisePathName[IMOS_NAME_LEN];
}CRUISE_PATH_QUERY_ITEM_S;


/***************************************************************************
巡航计划
****************************************************************************/

/**
 * @struct tagCruisePlanBase
 * @brief 巡航计划基本信息
 * @attention
 */
typedef struct tagCruisePlanBase
{
    /** 计划名称 */
    CHAR        szCruisePlanName[IMOS_NAME_LEN];

    /** 计划创建者名称 */
    CHAR        szCreatorName[IMOS_NAME_LEN];

    /** 计划创建日期 */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 巡航计划所属组织编码 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 计划类型, 取值为#PLAN_TYPE_E */
    ULONG_32       ulPlanType;

    /** 计划描述, 可不填 */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}CRUISE_PLAN_BASE_S;

/**
 * @struct tagCruisePlanInfo
 * @brief 巡航计划完整信息
 * @attention
 */
typedef struct tagCruisePlanInfo
{
    /** 巡航计划基本信息 */
    CRUISE_PLAN_BASE_S  stCruiseBaseInfo;

    /** 巡航计划时间信息 */
    PLAN_TIME_FOR_RES_S stCruiseTimeInfo;
}CRUISE_PLAN_INFO_S;

/**
 * @struct tagCruisePlanQueryItem
 * @brief 巡航计划信息项(查询巡航计划列表时返回)
 * @attention
 */
typedef struct tagCruisePlanQueryItem
{
    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 巡航计划名称 */
    CHAR        szCruisePlanName[IMOS_NAME_LEN];

    /** 巡航计划编码 */
    CHAR        szCruisePlanCode[IMOS_RES_CODE_LEN];

    /** 巡航计划创建者名称 */
    CHAR        szCreatorName[IMOS_NAME_LEN];

    /** 巡航计划创建日期 */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** 巡航计划状态, BOOL_TRUE为计划已经启动; BOOL_FALSE为计划未启动 */
    ULONG_32       ulPlanStatus;

     /** 保留字段 */
     CHAR szReserve[8];
 }CRUISE_PLAN_QUERY_ITEM;



/***************************************************************************
 存储资源
****************************************************************************/

/**
 * @struct taAlarmStorageTime
 * @brief 警前警后存储时间
 * @attention
 */
typedef struct taAlarmStorageTime
{
    /** 警前录像时间, 该值不可配置, 可填写任意ULONG值 */
    ULONG_32       ulPreAlarmTime;

    /** 警后录像时间, 取值范围为30~1800 */
    ULONG_32       ulAfterAlarmTime;

}ALARM_STORAGE_TIME_S;


/**
 * @struct tagStorageInfo
 * @brief 通道存储信息
 * @attention
 */
typedef struct tagStorageInfo
{
    /** 存储类型,枚举值为AS_DEVCM_STORAGE_TYPE_E, 0-IPSAN, 1-NAS, 2-本地存储 */
    ULONG_32       ulStorageType;

    /** 存储介质类型, 取值范围(0-2), 0表示ipsan存储, 1表示nas存储, 2表示local存储 */
    ULONG_32       ulStorageMedium;

    /** 存储模式,用3个bit表示：
        第0位：计划
        第1位：手动
        第2位：告警
    */
    ULONG_32       ulStorageMode;

    /** 计划流索引 */
    ULONG_32       ulPlanStreamType;

    /** 手工流索引 */
    ULONG_32       ulManualStreamType;

    /** 事件流索引 */
    ULONG_32       ulEventStreamType;

    /** 磁盘满处理策略，取值0或1, 0表示满停止,1覆盖  */
    ULONG_32       ulDiskFullPolicy;

}STORAGE_INFO_S;

/**
 * @struct tagStoreResInfo
 * @brief 存储资源信息
 * @attention 在IMOS_ExpandStoreRes中: 不带存储设备信息,即ulStoreDevType, szStoreDevCode, szStoreDevName不填.
 */
typedef struct tagStoreResInfo
{

    /** 存储类型, 取值为#AS_DEVCM_STORAGE_TYPE_E */
    ULONG_32       ulStorageType;

    /** 存储设备类型, 取值为#STORE_DEV_TYPE_E */
    ULONG_32       ulStoreDevType;

    /** 存储设备编码 */
    CHAR        szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备名称 */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** 指定存储设备空间不足时,是否支持自动选择存储设备(BOOL_TRUE为支持; BOOL_FALSE为不支持) */
    BOOL_T  bStoreDevAutoSelect;

    /** 计划流索引, 该值与摄像机所属EC选择的流套餐值有关, 当流套餐值为单流套餐时, 流索引最大值为1; 当流套餐值为双流套餐时, 流索引最大值为2 */
    ULONG_32       ulPlanStreamType;

    /** 手工流索引, 取值参见#ulPlanStreamType的说明 */
    ULONG_32       ulManualStreamType;

    /** 事件流索引, 取值参见#ulPlanStreamType的说明 */
    ULONG_32       ulEventStreamType;

    /** 磁盘满处理策略，取值为#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32       ulDiskFullPolicy;

    /** 存储空间(在IMOS_AssignStoreRes中,指第一次分配的存储空间; 在IMOS_ExpandStoreRes中,指扩展空间[含已分配空间]), 该值取值无上限, 单位为MB */
    ULONG_32       ulStoreSize;

    /** 警前警后录像时间 */
    ALARM_STORAGE_TIME_S stAlarmStorageTime;

}STORE_RES_INFO_S;

/**
 * @struct tagStoreResInfoV2
 * @brief 存储资源信息
 * @attention 在IMOS_ExpandStoreRes中: 不带存储设备信息,即ulStoreDevType, szStoreDevCode, szStoreDevName不填.
 */
typedef struct tagStoreResInfoV2
{
    /**存储信息*/
    STORE_RES_INFO_S        stStoreResInfo;

    /**DM 设备编码*/
    CHAR        szDMDevCode[IMOS_CODE_LEN];

    /**DM 设备名称*/
    CHAR        szDMDevName[IMOS_NAME_LEN];

}STORE_RES_INFO_V2_S;

/**
 * @struct tagStoreResQueryItem
 * @brief 存储资源信息项(查询存储资源列表时返回)
 * @attention 以存储设备名称来判断是否分配了存储资源, 即如果存储设备名称为空, 表明没有分配存储资源。
 */
typedef struct tagStoreResQueryItem
{

    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_CODE_LEN];

    /** 存储设备名称 */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** 存储设备的DM名称 */
    CHAR        szDMName[IMOS_NAME_LEN];

    /** 是否制定存储计划, BOOL_TRUE为制定存储计划; BOOL_FALSE为未制定存储计划 */
    BOOL_T      bHasStorePlan;

    /** 存储计划编码 */
    CHAR        szStorePlanCode[IMOS_CODE_LEN];

    /** 计划状态, BOOL_TRUE为计划启动; BOOL_FALSE为计划未启动 */
    BOOL_T      bPlanStatus;

    /** 存储资源状态(#ISM_RES_FAILURE为故障,1 正常,2 未知) */
    ULONG_32   ulResStatus;

    /** "计划存储"状态(0 未按计划存储,1 按计划存储,2 未知) */
    ULONG_32   ulPlanStoreStatus;
}STORE_RES_QUERY_ITEM_S;

/**
 * @struct tagStoreResExtInfo
 * @brief 存储资源扩展信息
 * @attention
 */
typedef struct tagStoreResExtInfo
{
    /** 所属父设备编码 */
    CHAR    szParentDevCode[IMOS_DEVICE_CODE_LEN];

    /** 所属父设备类型,取值范围为 #IMOS_TYPE_EC或#IMOS_TYPE_ECR */
    ULONG_32   ulParentDevType;

    /** 所属父设备子类型,可取值类型为#IMOS_DEVICE_TYPE_E中的编码器或带存储功能的编码器类型 */
    ULONG_32   ulParentSubDevType;

    /* 存储空间模式: 取值范围为 #AS_DEVCM_STORAGE_TYPE_E  */
    ULONG_32   ulStorageType;

    /** 中心录像状态: 取值范围为 MANUAL_STORE_STATUS_E */
    ULONG_32   ulManStoStatus;

    /** 保留字段1 */
    CHAR    szReserved[IMOS_STRING_LEN_32 - 4];
}STORE_RES_EXT_INFO_S;

/**
 * @struct tagStoreResQueryItemV2
 * @brief 存储资源信息项V2(查询存储资源列表时返回)
 * @attention
 */
typedef struct tagStoreResQueryItemV2
{
    /** 存储资源信息 */
    STORE_RES_QUERY_ITEM_S stStoreResQryItem;

    /** 存储资源扩展信息 */
    STORE_RES_EXT_INFO_S   stStoreResExtInfo;
}STORE_RES_QUERY_ITEM_V2_S;

/**
 * @struct tagDMShareResInfo
 * @brief 共享存储资源的信息结构体
 * @attention
 */
typedef struct tagDMShareResInfo
{
    /** 共享资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 容量大小，以MB为单位 */
    ULONG_32  ulCapacity;

    /** 存储设备类型, 取值为#STORE_DEV_TYPE_E */
    ULONG_32  ulStoreDevType;

    /** 存储设备编码 */
    CHAR  szStoreDevCode[IMOS_CODE_LEN];

    /** 存储设备名称 */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /**DM 设备编码*/
    CHAR  szDMDevCode[IMOS_CODE_LEN];

    /**DM 设备名称*/
    CHAR  szDMDevName[IMOS_NAME_LEN];

    /** 保留字段 */
    CHAR  szReserve[32];
}DM_SHARE_RES_INFO_S;

/**
 * @struct tagDmShareResQueryItem
 * @brief共享资源查询信息项(查询共享资源列表时返回)
 */
typedef struct tagDmShareResQueryItem
{
    /** 共享资源编码 */
    CHAR  szShareResCode[IMOS_CODE_LEN];

    /** 共享资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 存储设备名称 */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** 存储设备的DM名称 */
    CHAR  szDMName[IMOS_NAME_LEN];

    /** 容量大小，以MB为单位 */
    ULONG_32  ulCapacity;

    /** 共享资源状态(#ISM_RES_FAILURE 无法访问 1 正常, 2 未知) */
    ULONG_32  ulResStatus;

    /** 保留字段 */
    CHAR  szReserve[32];
}DM_SHARE_RES_QUERY_ITEM_S;

/**
 * @struct tagShareStorageDeviceInfo
 * @brief 共享资源可存储信息
 */
typedef struct tagShareStorageDeviceInfo
{
    /** 存储设备编码 */
    CHAR  szStoreDevCode[IMOS_CODE_LEN];

    /** 存储设备名称 */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /* 总容量 */
    ULONG_32 ulTotalCapacity;

    /* 剩余容量 */
    ULONG_32 ulSpareCapacity;

    /* 共享资源总容量 */
    ULONG_32 ulTotalShareCapacity;

    /* 可存储小时数(共享资源总容量 / (此设备上配置存储摄像机码率之和 + 需要配置摄像机码率)) */
    ULONG_32 ulStorageHours;

    /** 保留字段 */
    CHAR  szReserve[32];
}SHARE_STORAGE_DEVICE_INFO_S;


/**
 * @struct tagShareStorageDeviceInfo
 * @brief DM 共享资源可存储信息
 */
typedef struct tagDMShareStorageDeviceInfo
{
    /** DM 设备编码*/
    CHAR  szStoreDevCode[IMOS_CODE_LEN];

    /** DM 设备名称*/
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /* 共享资源总容量 */
    ULONG_32 ulTotalShareCapacity;

    /* 可存储小时数(共享资源总容量 / (此设备上配置存储摄像机码率之和 + 需要配置摄像机码率)) */
    ULONG_32 ulStorageHours;

    /** 保留字段 */
    CHAR  szReserve[32];
}DM_SHARE_STORAGE_DEVICE_INFO_S;

/***************************************************************************
存储计划
****************************************************************************/
/**
 * @struct tagStorePlanBase
 * @brief 存储计划基本信息
 * @attention
 */
typedef struct tagStorePlanBase
{
    /** 存储计划名称 */
    CHAR    szStorePlanName[IMOS_NAME_LEN];

    /** 计划创建时间 */
    CHAR    szPlanCreateTime[IMOS_TIME_LEN];

    /** 计划类型, 取值为#PLAN_TYPE_E */
    ULONG_32   ulPlanType;

    /** 组织编码 */
    CHAR    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 计划描述, 可不填 */
    CHAR    szPlanDesc[IMOS_DESC_LEN];

    /** 是否按天存储, BOOL_TRUE为按天存储; BOOL_FALSE为非按天存储 */
    BOOL_T  bIsDayStore;

    /** 按天存储的天数(暂不使用) */
    ULONG_32   ulStoreDays;
 }STORY_PLAN_BASE_S;


/**
 * @struct tagStoragePlan
 * @brief 存储计划信息
 * @attention
 */
typedef struct tagStoragePlan
{
    /** 存储计划基本信息 */
    STORY_PLAN_BASE_S   stStorageBasicInfo;

    /** 存储计划时间信息 */
    PLAN_TIME_S         stStorageTimeInfo;

}STORAGE_PLAN_INFO_S;


/**
 * @struct tagStoryPlanQueryItem
 * @brief 查询存储计划时用的信息，存储计划基本信息和摄像机名字关联信息，用于界面查询显示
 * @attention
 */
typedef struct tagStoryPlanQueryItem
{

    /** 存储计划编码 */
    CHAR        szStorePlanCode[IMOS_RES_CODE_LEN];

    /** 存储计划名称 */
    CHAR    szStorePlanName[IMOS_NAME_LEN];

    /** 计划创建时间 */
    CHAR    szPlanCreateTime[IMOS_TIME_LEN];

    /** 计划状态，BOOL_TRUE 表示计划已经启动 */
    ULONG_32       ulPlanStatus;

    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 摄像机所属组织名称 */
    CHAR        szOrgName[IMOS_NAME_LEN];

 }STORY_PLAN_QUERY_ITEM;


/***************************************************************************
轮切资源管理
****************************************************************************/
/**
 * @struct tagSwitchBase
 * @brief 轮切资源基本信息
 * @attention
 */
typedef struct tagSwitchBase
{
    /** 轮切名称 */
    CHAR                szSwitchName[IMOS_NAME_LEN];

    /** 组织编码 */
    /* CHAR                szOrgCode[IMOS_DOMAIN_CODE_LEN]; */

    /** 轮切描述, 可不填 */
    CHAR                szSwitchDesc[IMOS_DESC_LEN];
}SWITCH_BASE_S;


/**
 * @struct tagSwitchUnit
 * @brief 轮切资源中的摄像机信息
 * @attention
 */
typedef struct tagSwitchUnit
{
    /** 摄像机编码 */
    CHAR        szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR        szCameraName[IMOS_NAME_LEN];

    /** 序号 */
    ULONG_32       ulSequence;

     /** 切换时间 */
    ULONG_32       ulInterval;
}SWITCH_UNIT_S;

/**
 * @struct tagSwitchResoure
 * @brief 轮切资源信息
 * @attention
 */
typedef struct tagSwitchResoure
{
    /** 轮切基本信息 */
    SWITCH_BASE_S   stSwitchBaseInfo;

    /** 轮切资源数组中轮切资源的实际数目, 最大取值为#IMOS_SWITCH_CAM_MAXNUM */
    ULONG_32               ulSwitchResNum;

    /** 轮切资源数组 */
    SWITCH_UNIT_S    astSwitchUnitList[IMOS_SWITCH_CAM_MAXNUM];
}SWITCH_RESOURE_S;

/**
 * @struct tagSwitchUnitV2
 * @brief 轮切资源项V2
 * @attention 无
 */
typedef struct tagSwitchUnitV2
{
    /** 轮切资源项V1 */
    SWITCH_UNIT_S stSwitchUnitV1;

    /** 流类型,取值为#IMOS_FAVORITE_STREAM_E */
    ULONG_32 ulStreamType;

    /** 保留字段 */
    CHAR szReserve[128];
} SWITCH_UNIT_V2_S;

/**
 * @struct tagSwitchResoureV2
 * @brief 轮切资源V2
 * @attention 无
 */
typedef struct tagSwitchResoureV2
{
    /** 轮切资源基本信息 */
    SWITCH_BASE_S stSwitchBaseInfo;

    /** 轮切资源项数目,最大取值为#IMOS_SWITCH_CAM_MAXNUM_V2 */
    ULONG_32 ulSwitchResNum;

    /** 轮切资源项列表 */
    SWITCH_UNIT_V2_S astSwitchUnitList[IMOS_SWITCH_CAM_MAXNUM_V2];
} SWITCH_RESOURE_V2_S;

/**
 * @struct tagSwitchResQueryItem
 * @brief 轮切资源信息项(查询轮切资源列表时返回)
 * @attention
 */
typedef struct tagSwitchResQueryItem
{
    /** 轮切资源编码 */
    CHAR                szSwitchResCode[IMOS_RES_CODE_LEN];

    /** 轮切资源名称 */
    CHAR                szSwitchName[IMOS_NAME_LEN];

    /** 轮切资源所属组织编码 */
    CHAR                szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 轮切资源所属组织名称 */
    CHAR                szOrgName[IMOS_NAME_LEN];

}SWITCH_RES_QUERY_ITEM_S;

/* Begin Added by dengshuhua00673, 2012-12-15 of 自动布局轮巡 */
/**
 * @struct tagSwitchResQueryItemV2
 * @brief 轮切资源列表信息单元信息
 * @attention
 */
typedef struct tagSwitchResQueryItemV2
{
    /** 轮切信息编码 */
    CHAR                szSwitchResCode[IMOS_CODE_LEN];

    /** 轮切名称 */
    CHAR                szSwitchName[IMOS_NAME_LEN];

    /** 所属组织编码 */
    CHAR                szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 所属组织名称 */
    CHAR                szOrgName[IMOS_NAME_LEN];

	/** 通用轮切资源类型，取值为#COMMON_SWITCH_TYPE_E */
	ULONG_32               ulSwitchType;

}SWITCH_RES_QUERY_ITEM_V2_S;
/* End Added by dengshuhua00673, 2012-12-15 of 自动布局轮巡 */

/**
 * @struct tagSwitchRecord
 * @brief 轮切记录
 * @attention
 */
typedef struct tagSwitchRecord
{
    /** 轮切资源编码 */
    CHAR                szSwitchResCode[IMOS_RES_CODE_LEN];

    /** 显示屏编码 */
    CHAR                szScreenCode[IMOS_CODE_LEN];

    /** 显示屏名称 */
    CHAR                szScreenName[IMOS_NAME_LEN];

    /** 轮切用户编码 */
    CHAR                szUserCode[IMOS_CODE_LEN];

    /** 用户登录ID */
    CHAR                szUserLoginCode[IMOS_RES_CODE_LEN];

    /** 用户地址 */
    CHAR                szUserAddr[IMOS_IPADDR_LEN];

    /* 当前轮切状态 */
    ULONG_32               ulState;
}SWITCH_RECORD_S;

/***************************************************************************
轮切计划
****************************************************************************/

/**
 * @struct tagSwitchPlanBase
 * @brief 轮切计划基本信息
 * @attention
 */
typedef struct tagSwitchPlanBase
{
    /** 轮切计划名称 */
    CHAR        szPlanName[IMOS_NAME_LEN];

    /** 轮切计划创建日期 */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** 监视器编码 */
    CHAR        szScrCode[IMOS_RES_CODE_LEN];

    /** 监视器名称 */
    CHAR        szScrName[IMOS_NAME_LEN];

    /** 计划类型, 取值为#PLAN_TYPE_E */
    ULONG_32       ulPlanType;

    /** 轮切计划所属组织编码 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 计划描述, 可不填 */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}SWITCH_PLAN_BASE_S;


/**
 * @struct tagSwitchPlanInfo
 * @brief 轮切计划信息
 * @attention
 */
typedef struct tagSwitchPlanInfo
{
    /** 轮切计划基本信息 */
    SWITCH_PLAN_BASE_S  stSwitchBaseInfo;

    /** 轮切计划时间信息 */
    PLAN_TIME_FOR_RES_S stSwitchTimeInfo;
}SWITCH_PLAN_INFO_S;

/**
 * @struct tagSwitchPlanInfo
 * @brief 轮切计划信息
 * @attention
 */
typedef struct tagSwitchPlanInfoV2
{
    /** 轮切计划基本信息 */
    SWITCH_PLAN_BASE_S  stSwitchBaseInfo;

    /** 轮切计划时间信息 */
    PLAN_TIME_FOR_RES_V2_S stSwitchTimeInfo;
}SWITCH_PLAN_INFO_V2_S;


/**
 * @struct tagSwitchPlanQueryItem
 * @brief 轮切计划信息项(查询轮切计划列表时返回)
 * @attention
 */
typedef struct tagSwitchPlanQueryItem
{
    /** 轮切计划编码 */
    CHAR            szSwitchPlanCode[IMOS_RES_CODE_LEN];

    /** 轮切计划名称 */
    CHAR            szPlanName[IMOS_NAME_LEN];

    /** 轮切计划创建日期 */
    CHAR            szCreatTime[IMOS_TIME_LEN];

    /** 监视器名称 */
    CHAR            szScrName[IMOS_NAME_LEN];

    /** 计划状态，BOOL_TRUE为计划已经启动, BOOL_FALSE为计划未启动 */
    ULONG_32           ulPlanStatus;

}SWITCH_PLAN_QUERY_ITEM_S;




/***************************************************************************
告警
****************************************************************************/

/**
 * @struct tagAlarmSrc
 * @brief 告警源信息
 * @attention
 */
typedef struct tagAlarmSrc
{

    /** 告警源的名称 */
    CHAR        szAlarmSrcName[IMOS_NAME_LEN];

    /** 告警源的类型, 取值为#ALARM_DEV_TYPE_E */
    ULONG_32       ulAlarmSrcType;

    /** 连接了告警源的通道所属设备的编码 */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 连接了告警源的通道所属设备的名称 */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** 告警源绑定的通道索引, 取值视告警源所属设备类型而定 */
    ULONG_32       ulChannelIndex;
}ALARM_SRC_S;

/**
 * @struct tagAlarmSrcQueryItem
 * @brief 告警源查询信息列表单元信息
 * @attention
 */
typedef struct tagAlarmSrcQueryItem
{

    /** 告警源的名称 */
    CHAR        szAlarmSrcName[IMOS_NAME_LEN];

    /** 告警源的编码 */
    CHAR        szAlarmSrcCode[IMOS_RES_CODE_LEN];

    /** 设备类型（具体枚举取值参见#IMOS_TYPE_E） */
    ULONG_32       ulDevType;

    /** 设备子类型（具体枚举取值参见#IMOS_DEVICE_TYPE_E） */
    ULONG_32       ulDevSubType;

    /** 告警源所属组织编码(目前不返回,保留使用) */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 告警源所属组织名称(目前不返回,保留使用) */
    CHAR        szOrgName[IMOS_NAME_LEN];

    /* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */
    /** NVR、ECR大类设备类型 */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2012-7-18 for ECR NVR大类 */

}ALARM_SRC_QUERY_ITEM_S;

/**
* @struct tagAlarmSrcQueryItemEx
* @brief 告警源查询信息列表单元扩展信息
* @attention
*/
typedef struct tagAlarmSrcQueryItemEx
{
    /* 告警源查询信息列表单元信息 */
    ALARM_SRC_QUERY_ITEM_S stAlarmSrcQueryItem;

    /** 父设备类型（具体枚举取值参见#IMOS_TYPE_E） */
    ULONG_32 ulParentDevType;

    /** 父设备子类型（具体枚举取值参见#IMOS_DEVICE_TYPE_E） */
    ULONG_32 ulParentSubDevType;

    /* 是否支持联动 */
    BOOL_T bHasLinkage;

    /* 是否支持布防 */
    BOOL_T bHasGuard;

    /* 是否存在告警类型自定义 */
    BOOL_T bHasAlarmEnabled;

}ALARM_SRC_QUERY_ITEM_EX_S;

/**
 * @struct tagAlarmExporter
 * @brief 告警输出设备信息
 * @attention
 */
typedef struct tagAlarmExporter
{

    /** 告警输出设备的名称 */
    CHAR        szAlarmExporterName[IMOS_NAME_LEN];

    /** 告警输出设备的类型, 取值为#ALARM_DEV_TYPE_E */
    ULONG_32       ulAlarmExporterType;

    /** 告警输出设备绑定的通道所属设备的编码 */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 告警输出设备绑定的通道所属设备的名称 */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** 告警输出设备绑定的通道索引, 取值视告警源所属设备类型而定 */
    ULONG_32       ulChannelIndex;
}ALARM_EXPORTER_S;

/**
 * @struct tagAlarmExporterQueryItem
 * @brief 告警输出设备查询信息列表单元信息
 * @attention
 */
typedef struct tagAlarmExporterQueryItem
{

    /** 告警输出设备的名称 */
    CHAR        szAlarmExporterName[IMOS_NAME_LEN];

    /** 告警输出设备的编码 */
    CHAR        szAlarmExporterCode[IMOS_RES_CODE_LEN];

    /** 告警输出设备的类型,枚举类型为:ALARM_DEV_TYPE_E */
    ULONG_32       ulAlarmExporterType;

    /** 告警源所属组织 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 所属组织名称 */
    CHAR        szOrgName[IMOS_NAME_LEN];

}ALARM_EXPORTER_QUERY_ITEM_S;

/**
 * @struct tagEventRecord
 * @brief 告警记录信息
 * @attention
 */
typedef struct tagEventRecord
{
    /** 告警编码*/
    CHAR szEventRecordCode[IMOS_RES_CODE_LEN];

    /** 告警类型, 取值为#AlARM_TYPE_E */
    ULONG_32 ulEventType;

    /** 设备编码*/
    CHAR szDeviceCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称*/
    CHAR  szDeviceName[IMOS_NAME_LEN];

    /** 告警名称*/
    CHAR szActiveName[IMOS_NAME_LEN];

    /** 告警级别, 取值为#ALARM_SEVERITY_LEVEL_E */
    ULONG_32 ulEventSecurity;

    /** 告警触发时间*/
    CHAR szEventTime[IMOS_TIME_LEN];

    /** 告警状态, 取值为#ALARM_STATUS_E */
    ULONG_32 ulAlarmStatus;

    /** 事件级别名称 */
    CHAR   szSecurityName[IMOS_NAME_LEN];

    /** 事件级别显示颜色 */
    CHAR   szSecurityColor[IMOS_STRING_LEN_14];

    /** 告警核警时间*/
    CHAR szCheckTime[IMOS_TIME_LEN];

    /** 告警核警用户*/
    CHAR szCheckUser[IMOS_NAME_LEN];

    /** 告警确认时间*/
    CHAR szAckTime[IMOS_TIME_LEN];

    /** 告警确认用户*/
    CHAR szAckUser[IMOS_NAME_LEN];

    /** 参数名值对*/
    CHAR szKeyValue[IMOS_STRING_LEN_128];

    /** 告警描述信息*/
    CHAR szEventDesc[IMOS_DESC_LEN];

    /** 告警确认描述*/
    CHAR szAckSuggestion[IMOS_DESC_LEN];

    /** 是否误报 */
    ULONG_32 ulIsMisinform;

    /** 是否预案告警 */
    ULONG_32 ulIsPlanAlarm;

    /** 是否启动过预案（查询告警处理流程记录用） */
    ULONG_32 ulIsOncePlanAlarm;

    /** 是否有需要手工处理任务*/
    ULONG_32 ulIsManualTask;
}EVENT_RECORD_S;

/**
 * @struct tagStoreAction
 * @brief 联动存储
 * @attention
 */
typedef struct tagStoreAction
{

    /** 联动摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 联动摄像机名称（只用于告警联动策略查询接口） */
    CHAR        szCamName[IMOS_NAME_LEN];

}STORE_ACTION_S;


/**
 * @struct tagPresetAction
 * @brief 联动预置位
 * @attention
 */
typedef struct tagPresetAction
{

    /** 联动摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 联动摄像机名称（只用于告警联动策略查询接口） */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 预置位值, 取值范围为#PTZ_PRESET_MINVALUE~服务器配置文件里配置的预置位最大值 */
    ULONG_32       ulPresetValue;

    /** 预置位描述（只用于告警联动策略查询接口） */
    CHAR        szPresetDesc[IMOS_DESC_LEN];
}PRESET_ACTION_S;


/**
 * @struct tagScreenLiveAction
 * @brief 联动实况到窗格
 * @attention
 */
typedef struct tagScreenLiveAction
{

    /** 联动摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 联动摄像机名称（只用于告警联动策略查询接口）*/
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 联动到用户窗格时的用户编码 */
    CHAR        szUserCode[IMOS_USER_CODE_LEN];

    /** 联动到用户窗格时的用户名称（只用于告警联动策略查询接口） */
    CHAR        szUserName[IMOS_NAME_LEN];

    /** 联动到用户的屏幕序号, 取值为1 */
    ULONG_32       ulScreenIndex ;

    /** 联动到用户的窗格编码 */
    CHAR        szXPPaneCode[IMOS_RES_CODE_LEN];

    /** 是否抓拍, 取值为0或1 */
    ULONG_32       ulSnatchImage;

    /** 抓拍间隔，取值单位毫秒 */
    ULONG_32       ulInterval;

    /** 抓拍张数 */
    ULONG_32       ulSnatchCounter;

    /** 是否启用警前录像，取值0：否，1：是 */
    ULONG_32       ulIsBefAlarmReplay;

    /** 警前录像时间间隔，取值单位秒 */
    ULONG_32       ulBefAlarmRepInterval;

    /** 联动警前录像的用户屏幕序号, 取值为1 */
    ULONG_32       ulBefAlarmRepScreenIndex;

    /** 联动到用户的窗格编码 */
    CHAR        szBefAlarmRepXPPaneCode[IMOS_CODE_LEN];

}SCREENLIVE_ACTION_S;

/**
 * @struct tagScreenLiveActionForECR
 * @brief 联动实况到窗格
 * @attention
 */
typedef struct tagScreenLiveActionForECR
{

    /** 联动摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 联动摄像机名称（只用于告警联动策略查询接口）*/
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 联动到用户窗格时的用户编码 */
    CHAR        szUserCode[IMOS_USER_CODE_LEN];

    /** 联动到用户窗格时的用户名称（只用于告警联动策略查询接口） */
    CHAR        szUserName[IMOS_NAME_LEN];

    /** 联动到用户的屏幕序号, 取值为1 */
    ULONG_32       ulScreenIndex ;

    /** 联动到用户的窗格编码 */
    CHAR        szXPPaneCode[IMOS_RES_CODE_LEN];

}SCREENLIVE_ACTION_FOR_ECR_S;


/**
 * @struct tagMonitorLiveAction
 * @brief 联动实况到监视器
 * @attention
 */
typedef struct tagMonitorLiveAction
{

    /** 联动摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 联动摄像机名称（只用于告警联动策略查询接口） */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 联动摄像机所在设备的编码流套餐, 只用于查询, 配置时无效, 取值为#IMOS_STREAM_RELATION_SET_E */
    ULONG_32       ulEncodeSet;

    /** 联动摄像机实况时的流类型, 取值为#IMOS_FAVORITE_STREAM_E */
    ULONG_32       ulStreamType;

    /** 联动监视器编码 */
    CHAR        szSrcCode[IMOS_RES_CODE_LEN];

    /** 联动监视器名称（只用于告警联动策略查询接口） */
    CHAR        szSrcName[IMOS_NAME_LEN];

    /** 联动监视器所在设备的解码流套餐, 只用于查询, 配置时无效, 取值为#IMOS_STREAM_RELATION_SET_E中的
        以下值为解码器流套餐：
        1：H264(#IMOS_SR_H264_SHARE)
        3: MJPEG(#IMOS_SR_H264_MJPEG)
        4：MEPG4(#IMOS_SR_MPEG4_SHARE)
        5：MEPG2(#IMOS_SR_MPEG2_SHARE)
    若取值为#IMOS_SR_INVALID, 即非法值, 则说明不支持的查询: 如监视器已被删除、外域或ECR HF摄像机等 */
    ULONG_32       ulDecodeSet;

    /* 分屏号,0为无效值 */
    ULONG_32      ulScreenIndex;


}MONITORLIVE_ACTION_S;

/**
 * @struct tagMonitorLiveActionForECR
 * @brief 联动实况到监视器
 * @attention
 */
typedef struct tagMonitorLiveActionForECR
{

    /** 联动摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 联动摄像机名称（只用于告警联动策略查询接口） */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 联动监视器编码 */
    CHAR        szSrcCode[IMOS_RES_CODE_LEN];

    /** 联动监视器名称（只用于告警联动策略查询接口） */
    CHAR        szSrcName[IMOS_NAME_LEN];

}MONITORLIVE_ACTION_FOR_ECR_S;

/**
 * @struct tagGISAction
 * @brief 联动地图闪烁
 * @attention
 */
typedef struct tagGISAction
{
    /** 闪烁使能标记, BOOL_TRUE为使能; BOOL_FALSE为非使能 */
    BOOL_T  bIsEnabled;

}GIS_ACTION_S;


/**
 * @struct tagSwitchOUTAction
 * @brief 联动开关量输出
 * @attention
 */
typedef struct tagSwitchOUTAction
{

    /** 设备编码 */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称（只用于告警联动策略查询接口） */
    CHAR        szDevName[IMOS_NAME_LEN];
}SWITCHOUT_ACTION_S;


/**
 * @struct tagBackupAction
 * @brief 联动备份
 * @attention
 */
typedef struct tagBackupAction
{

    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称（只用于告警联动策略查询接口） */
    CHAR        szCamName[IMOS_NAME_LEN];
}BACKUP_ACTION_S;

/**
* @struct tagReceiverAction
* @brief 联动短信邮件
* @attention 无
*/
typedef struct tagReceiverAction
{
    /** 接收人实际数目 */
    ULONG_32 ulReceiverNum;

    /** 接收人信息(增改时用户编码有效，其他无效；查询时用户登录ID、用户登录地址、用户登陆时间、用户是否被锁定无效，其他有效) */
    USER_QUERY_ITEM_S astReceiver[IMOS_ALARM_ACTION_RECEIVER_MAXNUM];

    /** 邮件标题（短信的话此字段无效） */
    CHAR        szTitle[IMOS_NAME_LEN];

    /** 内容 */
    CHAR        szContent[IMOS_DESC_LEN];

}RECEIVER_ACTION_S;

/**
 * @struct tagBuzzerAction
 * @brief 联动蜂鸣器告警
 * @attention
 */
typedef struct tagBuzzerAction
{

    /** 蜂鸣器所在设备编码 */
    CHAR        szDevCode[IMOS_CODE_LEN];

    /** 蜂鸣器参数， 预留用于扩展:蜂鸣时间与频率等 */
    CHAR        szParam[IMOS_STRING_LEN_64];
}BUZZER_ACTION_S;

/* Begin added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */
/**
* @struct tagVocTalkAction
* @brief 联动到语音对讲动作
* @attention
*/
typedef struct tagVocTalkAction
{
    /* 摄像机编码 */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /* 摄像机名称，只用于告警联动策略查询接口 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /* 用户编码 */
    CHAR    szUserCode[IMOS_CODE_LEN];

    /** 用户名称，只用于告警联动策略查询接口*/
    CHAR    szUserName[IMOS_NAME_LEN];
}VOCTALK_ACTION_S;
/* End added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */

/**
* @struct tagActionPlanBaseInfo
* @brief 预案基本信息
* @attention
*/
typedef struct tagActionPlanBaseInfo
{
    /** 预案编码 */
    CHAR szActionPlanCode[IMOS_CODE_LEN];

    /** 预案名称 */
    CHAR szActionPlanName[IMOS_NAME_LEN];

    /** 预案描述 */
    CHAR szActionPlanDesc[IMOS_DESC_LEN];

    /** 预案类型，取值为#ACTION_PLAN_TYPE_E */
    ULONG_32 ulActionPlanType;
}ACTION_PLAN_BASE_INFO_S;

/**
 * @struct tagAlarmAction
 * @brief 告警联动动作
 * @attention
 */
typedef struct tagAlarmAction
{

    /** 存储动作数组中存储动作的实际数目, 取值最大值为#IMOS_ALARM_STORE_ACTION_MAXNUM */
    ULONG_32                       ulStoreActionNum;

    /** 存储动作数组 */
    STORE_ACTION_S          astStoreAction[IMOS_ALARM_STORE_ACTION_MAXNUM];

    /** 预置位动作数组中预置位动作的实际数目, 取值最大值为#IMOS_ALARM_PRESET_ACTION_MAXNUM */
    ULONG_32                       ulPresetActionNum;

    /** 预置位动作数组 */
    PRESET_ACTION_S         astPresetAction[IMOS_ALARM_PRESET_ACTION_MAXNUM];

    /** 联动实况到窗格动作数组中联动实况到窗格动作的实际数目, 取值最大值为#IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM */
    ULONG_32                       ulScreenLiveActionNum;

    /** 联动实况到窗格动作数组 */
    SCREENLIVE_ACTION_S     astScreenLiveAction[IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM];

    /** 联动实况到监视器动作数组中联动实况到监视器动作的实际数目, 取值最大值为#IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM */
    ULONG_32                       ulMonitorLiveActionNum;

    /** 联动实况到监视器动作数组 */
    MONITORLIVE_ACTION_S    astMonitorLiveAction[IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM];

    /** 联动地图闪烁动作数组中联动地图闪烁动作的实际数目, 取值最大值为#IMOS_ALARM_GIS_ACTION_MAXNUM */
    ULONG_32                       ulGISActionNum;

    /** 联动地图闪烁动作数组 */
    GIS_ACTION_S            astGISAction[IMOS_ALARM_GIS_ACTION_MAXNUM];

    /** 联动开关量输出动作数组中联动开关量输出动作的实际数目, 取值最大值为#IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM */
    ULONG_32                       ulSwitchOUTActionNum;

    /** 联动开关量输出动作数组 */
    SWITCHOUT_ACTION_S      astSwitchOUTAction[IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM];

    /** 联动备份动作数组中联动备份动作的实际数目, 取值最大值为#IMOS_ALARM_BACKUP_ACTION_MAXNUM */
    ULONG_32                       ulBackupActionNum;

    /** 联动备份动作数组 */
    BACKUP_ACTION_S         astBackupAction[IMOS_ALARM_BACKUP_ACTION_MAXNUM];

    /** 短信 */
    RECEIVER_ACTION_S        stReceiverSMSAction;

    /** 邮件 */
    RECEIVER_ACTION_S        stReceiverEmailAction;

    /** 联动到预案实际数目, 取值最大值为#IMOS_ALARM_ACTION_PLAN_MAXNUM */
    ULONG_32 ulActionPlanBaseNum;

    /** 预案信息 */
    ACTION_PLAN_BASE_INFO_S  astActionPlanBaseInfo[IMOS_ALARM_ACTION_PLAN_MAXNUM];

    /** 中心域存储动作数组中存储动作的实际数目, 取值最大值为#IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM */
    ULONG_32                    ulCenterStoreActionNum;

    /** 中心域存储动作数组 */
    STORE_ACTION_S           astCenterStoreAction[IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM];

    /* Begin added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */
    /** 语音对讲动作数目 */
    ULONG_32                   ulVocTalkActionNum;

    /** 语音对讲动作 */
    VOCTALK_ACTION_S        astVocTalkAction[IMOS_ALARM_VOCTALK_ACTION_MAXNUM];
    /* End added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */

}ALARM_ACTION_S;

/**
 * @struct tagAlarmActionForECR
 * @brief 告警联动动作(for ECR&NVR buzzer)
 * @attention
 */
typedef struct tagAlarmActionForECR
{

    /** 存储动作数组中存储动作的实际数目, 取值最大值为#IMOS_ALARM_STORE_ACTION_MAXNUM */
    ULONG_32                       ulStoreActionNum;

    /** 存储动作数组 */
    STORE_ACTION_S          astStoreAction[IMOS_ALARM_STORE_ACTION_MAXNUM];

    /** 预置位动作数组中预置位动作的实际数目, 取值最大值为#IMOS_ALARM_PRESET_ACTION_MAXNUM */
    ULONG_32                       ulPresetActionNum;

    /** 预置位动作数组 */
    PRESET_ACTION_S         astPresetAction[IMOS_ALARM_PRESET_ACTION_MAXNUM];

    /** 联动实况到窗格动作数组中联动实况到窗格动作的实际数目, 取值最大值为#IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM */
    ULONG_32                       ulScreenLiveActionNum;

    /** 联动实况到窗格动作数组 */
    SCREENLIVE_ACTION_FOR_ECR_S     astScreenLiveAction[IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM];

    /** 联动实况到监视器动作数组中联动实况到监视器动作的实际数目, 取值最大值为#IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM */
    ULONG_32                       ulMonitorLiveActionNum;

    /** 联动实况到监视器动作数组 */
    MONITORLIVE_ACTION_FOR_ECR_S    astMonitorLiveAction[IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM];

    /** 联动地图闪烁动作数组中联动地图闪烁动作的实际数目, 取值最大值为#IMOS_ALARM_GIS_ACTION_MAXNUM */
    ULONG_32                       ulGISActionNum;

    /** 联动地图闪烁动作数组 */
    GIS_ACTION_S            astGISAction[IMOS_ALARM_GIS_ACTION_MAXNUM];

    /** 联动开关量输出动作数组中联动开关量输出动作的实际数目, 取值最大值为#IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM */
    ULONG_32                       ulSwitchOUTActionNum;

    /** 联动开关量输出动作数组 */
    SWITCHOUT_ACTION_S      astSwitchOUTAction[IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM];

    /** 联动备份动作数组中联动备份动作的实际数目, 取值最大值为#IMOS_ALARM_BACKUP_ACTION_MAXNUM */
    ULONG_32                       ulBackupActionNum;

    /** 联动备份动作数组 */
    BACKUP_ACTION_S         astBackupAction[IMOS_ALARM_BACKUP_ACTION_MAXNUM];

	/** 联动蜂鸣器告警动作数目 */
    ULONG_32                   ulBuzzerActionNum;

    /** 联动蜂鸣器告警动作列表 */
    BUZZER_ACTION_S      	astBuzzerAction[IMOS_ALARM_BUZZER_ACTION_MAXNUM];

}ALARM_ACTION_FOR_ECR_S;



/**
 * @struct tagAlarmLinkageInfo
 * @brief 告警联动信息结构体
 * @attention
 */
typedef struct tagAlarmLinkageInfo
{

    /** 告警源的编码 */
    CHAR                    szAlarmSrcCode[IMOS_RES_CODE_LEN];


    /** 告警类型 */
    ULONG_32                   ulAlarmType;

    /** 告警源对应告警类型所联动的动作 */
    ALARM_ACTION_S      stAction;

}ALARM_LIKNAGE_INFO_S;

/**
* @struct tagAlarmEventQueryCondition
* @brief 告警事件查询条件
*/
typedef struct tagAlarmEventQueryCondition
{
    /** 摄像机编码*/
    CHAR                szCamCode[IMOS_CODE_LEN];

    /** 检索的起始/结束时间 */
    TIME_SLICE_S    stQueryTimeSlice;

    /** 保留字段 */
    CHAR szReserve[64];
}ALARM_EVENT_QUERY_CONDITION_S;


/**
* @struct tagAlarmEventInfo
* @brief 告警事件信息(查询告警事件信息列表时返回)
*/
typedef struct tagAlarmEventInfo
{
    /** 告警类型 */
    ULONG_32 ulAlarmType;

    /** 告警源名称 */
    CHAR szAlarmSrcName[IMOS_NAME_LEN];

    /** 告警发生时间, 满足"%Y-%m-%d %H:%M:%S"格式, 长度限定为24字符 */
    CHAR szAlarmTime[IMOS_TIME_LEN];

    /** 存储关联摄像机编码 */
    CHAR szCameraCode[IMOS_CODE_LEN];

}ALARM_EVENT_INFO_S;



/*******************************************************************************
布防计划 GuardPlan , Edited By sunyifan(06966) Completed
********************************************************************************/
/**
 * @struct tagGuardStratageBasicInfo
 * @brief 布防策略基本信息
 * @attention
 */
typedef struct tagGuardStratageBasicInfo
{

    /** 布防策略名称 */
    CHAR        szPolicyName[IMOS_NAME_LEN];

    /** 计划创建日期 */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** 是否使能, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 按照日循环或者按照周循环, 取值为#MM_JOBSCHDTYPE_E */
    ULONG_32       ulCycleType;

    /** 布防策略组织编码 */
    CHAR    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 计划描述, 可不填 */
    CHAR        szPlanDesc[IMOS_DESC_LEN];

}GUARD_STRATAGE_BASIC_INFO_S;


/**
 * @struct tagGuardPlanInfo
 * @brief 布防计划信息
 * @attention
 */
typedef struct tagGuardPlanInfo
{
    /** 布防策略基本信息 */
    GUARD_STRATAGE_BASIC_INFO_S stGuardStratageBasicInfo;

    /** 布防计划时间信息 */
    PLAN_TIME_S     stGuardTimeInfo;

}GUARD_PLAN_INFO_S;

/**
 * @struct tagGuardPlanQueryItem
 * @brief 布防策略计划信息项(查询布防策略计划列表时返回)
 * @attention
 */
typedef struct tagGuardPlanQueryItem
{

    /** 告警源名称 */
    CHAR            szAlarmSrcName[IMOS_NAME_LEN];

    /** 告警类型, 取值为#AlARM_TYPE_E */
    ULONG_32           ulAlarmType;

    /** 告警源所属组织名称 */
    CHAR            szOrgName[IMOS_NAME_LEN];

    /** 布防计划名称 */
    CHAR        szPlanName[IMOS_NAME_LEN];

    /** 布防计划创建日期 */
    CHAR            szCreatTime[IMOS_TIME_LEN];

    /** 布防计划状态, 1为计划已经启动; 0为计划未启动 */
    ULONG_32           ulPlanStatus;

    /** 布防计划编码 */
    CHAR            szGuardPlanCode[IMOS_RES_CODE_LEN];

}GUARD_PLAN_QUERY_ITEM_S;


/***************************************************************************
GIS
****************************************************************************/

/**
 * @struct tagFileGISInfo
 * @brief GIS图片信息
 * @attention
 */
typedef struct tagFileGISInfo
{
    /** 地图类型(即地图文件扩展名)取值参加#MAP_TYPE_E */
    ULONG_32                   ulGISMapType;

    /** 地图所属组织编码 */
    CHAR                    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** GIS文件基本信息 */
    FILE_BASIC_INFO_S   stFileBasicInfo;
}FILE_GIS_INFO_S;



/**
 * @struct tagGISQueryItem
 * @brief GIS图片信息项(用于查询时返回)
 * @attention
 */
typedef struct tagGISQueryItem
{
    /** 地图编码 */
    CHAR        szGISMapCode[IMOS_RES_CODE_LEN];

    /** 地图名称, 为增加地图时用户指定的名称 */
    CHAR        szName[IMOS_NAME_LEN];

    /** GIS地图所属组织编码 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

}GIS_QUERY_ITEM_S;


/**
 * @struct tagGisHotZone
 * @brief GIS热区信息
 * @attention
 */
typedef struct tagGisHotZone
{
    /** 热区名称 */
    CHAR        szHotZoneName[IMOS_NAME_LEN];

    /** 热区链接的地图编码 */
    CHAR        szGISMapCode[IMOS_RES_CODE_LEN];

    /** 热区图形边界字符串，支持点和多边形 */
    CHAR        szBorderline[IMOS_POLYGON_GEO_LEN];

    /** 热区描述, 可不填 */
    CHAR        szHotZoneDesc[IMOS_DESC_LEN];

}GIS_HOTZONE_S;

/**
 * @struct tagGisHotZoneWithCode
 * @brief 含有热区编码的GIS热区图形信息(用于查询时返回)
 * @attention
 */
typedef struct tagGisHotZoneWithCode
{
    /** 热区编码 */
    CHAR            szHotZoneCode[IMOS_RES_CODE_LEN];

    /** 热区其他信息 */
    GIS_HOTZONE_S   stHotZoneInfo;

}GIS_HOTZONE_WITH_CODE_S;

/**
 * @struct tagGisHotSPOT
 * @brief GIS热点信息
 * @attention
 */
typedef struct tagGisHotSPOT
{
    /** 热点链接到的组织编码 */
    CHAR            szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 热点位置信息描述, 可以不填 */
    CHAR            szSiteDesc[IMOS_POINT_GEO_LEN];

}GIS_HOTSPOT_S;

/**
 * @struct tagGisHotSpotWithCode
 * @brief 含有热点编码的GIS热点图形(用于查询时返回)
 * @attention
 */
typedef struct tagGisHotSpotWithCode
{
    /** 热点编码 */
    CHAR            szHotSpotCode[IMOS_RES_CODE_LEN];

    /** 热点链接到的组织名称 */
    CHAR            szOrgName[IMOS_NAME_LEN];

    /** 热点其他信息 */
    GIS_HOTSPOT_S   stHotSpotInfo;

}GIS_HOTSPOT_WITH_CODE_S;

/**
 * @struct tagGisTextbox
 * @brief GIS文本框
 * @attention
 */
typedef struct tagGisTextbox
{
    /** 文本信息 */
    CHAR    szTextInfo[IMOS_DESC_LEN];

    /** 文本框位置信息描述 */
    CHAR    szSiteDesc[IMOS_POINT_GEO_LEN];

    /** 文字字体, 具体的取值视使用情况而定 */
    ULONG_32   ulTextType;

    /** 文字大小, 具体的取值视使用情况而定 */
    ULONG_32   ulTextSize;

    /** 文字颜色, 具体的取值视使用情况而定 */
    ULONG_32   ulTextColor;

    /** 文字是否加粗, 1为加粗; 0为不加粗 */
    ULONG_32   ulBoldFlag;

}GIS_TEXTBOX_S;


/**
 * @struct tagGisTextBoxWithCode
 * @brief 包含了文本框编码的GIS文本框信息
 * @attention
 */
typedef struct tagGisTextBoxWithCode
{
    /** 文本框编码 */
    CHAR            szTextBoxCode[IMOS_RES_CODE_LEN];

    /** 文本框其他信息 */
    GIS_TEXTBOX_S   stTextBoxInfo;

}GIS_TEXTBOX_WITH_CODE_S;


/**
 * @struct tagGisCamIcon
 * @brief GIS摄像机图标信息
 * @attention
 */
typedef struct tagGisCamIcon
{
    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机图标位置信息描述, 可不填 */
    CHAR        szSiteDesc[IMOS_POINT_GEO_LEN];

}GIS_CAM_ICON_S;


/**
 * @struct tagGisCamIconWithCode
 * @brief 包含了图标编码的GIS摄像机图标信息
 * @attention
 */
typedef struct tagGisCamIconWithCode
{
    /** 摄像机图标编码 */
    CHAR            szCamIconCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR            szCamName[IMOS_NAME_LEN];

    /** 摄像机的状态, 取值为#AS_CAMERA_STATUS_E */
    ULONG_32           ulCamState;

    /** 摄像机的额外状态, 取值为#DEV_EXT_STATUS_E */
    ULONG_32           ulCamExtState;

    /** 摄像机的告警严重程度, 取值为#ALARM_SEVERITY_LEVEL_E */
    ULONG_32           ulCamAlarmLevel;

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32           ulCameraType;

    /** 摄像机是否属于外域: 1 是,0 否 */
    ULONG_32           ulIsForeign;

    /** 摄像机图标其他信息 */
    GIS_CAM_ICON_S  stCamIconInfo;

    /** 摄像机所属父设备的类型,取值为#IMOS_TYPE_E */
    ULONG_32 ulParentType;

}GIS_CAM_ICON_WITH_CODE_S;


/**
 * @struct tagGisAlarmSrcIcon
 * @brief GIS告警源图标信息
 * @attention
 */
typedef struct tagGisAlarmSrcIcon
{
    /** 告警源编码 */
    CHAR        szAlarmSrcCode[IMOS_DEVICE_CODE_LEN];

    /** 告警源图标位置信息描述, 可不填 */
    CHAR        szSiteDesc[IMOS_POINT_GEO_LEN];



}GIS_ALARM_SRC_ICON_S;


/**
 * @struct tagGisAlarmSrcIconWithCode
 * @brief 包含告警源图标编码的GIS告警源图标信息
 * @attention
 */
typedef struct tagGisAlarmSrcIconWithCode
{
    /** 告警源图标编码 */
    CHAR                    szAlarmSrcIconCode[IMOS_RES_CODE_LEN];

    /** 告警源名称 */
    CHAR                    szAlarmSrcName[IMOS_NAME_LEN];

    /** 告警严重程度, 取值为#ALARM_SEVERITY_LEVEL_E */
    ULONG_32                   ulAlarmLevel;

    /** 告警源图标其他信息 */
    GIS_ALARM_SRC_ICON_S    stAlarmSrcIconInfo;

}GIS_ALARM_SRC_ICON_WITH_CODE_S;


/**
 * @struct tagGisAlarmDstIcon
 * @brief GIS告警输出图标信息
 * @attention
 */
typedef struct tagGisAlarmDstIcon
{
    /** 告警输出编码 */
    CHAR        szAlarmDstCode[IMOS_DEVICE_CODE_LEN];

    /** 告警输出图标位置信息描述, 可不填 */
    CHAR        szSiteDesc[ IMOS_POINT_GEO_LEN];

}GIS_ALARM_DST_ICON_S;


/**
 * @struct tagGisAlarmDstIconWithCode
 * @brief 包含告警输出图标编码的GIS告警输出图标信息
 * @attention
 */
typedef struct tagGisAlarmDstIconWithCode
{
    /** 告警输出图标编码 */
    CHAR                    szAlarmDstIconCode[IMOS_RES_CODE_LEN];

    /** 告警输出名称 */
    CHAR                    szAlarmDstName[IMOS_NAME_LEN];

    /** 告警输出图标其他信息 */
    GIS_ALARM_DST_ICON_S    stAlarmDstIconInfo;

}GIS_ALARM_DST_ICON_WITH_CODE_S;


/***************************************************************************************************
透明通道
****************************************************************************************************/
/**
 * @struct tagTransparentChannel
 * @brief 透明通道基本信息
 * @attention
 */
typedef struct tagTransparentChannel
{
    /** 透明通道名称 */
    CHAR        szTransChnlName[IMOS_NAME_LEN];

    /** 透明通道类型，不可更改,取值为#TL_CHANNEL_MODE_E */
    ULONG_32       ulTransChnlType;

    /** 透明通道数据承载方式(UDP/TCP/SIP) **/
    ULONG_32       ulDataTransType;

}TRANSPARENT_CHANNEL_S;

/**
 * @struct tagTransparentSerial
 * @brief 透明通道串口信息
 * @attention
 */
typedef struct tagTransparentSerial
{

    /** 设备编码 */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** 设备类型, 取值为#IMOS_TYPE_EC和#IMOS_TYPE_DC */
    ULONG_32       ulDevType;

    /** 串口索引, 取值从1开始, 最大值为#IMOS_TRANSPARENT_SERIAL_NUM */
    ULONG_32       ulSerialIndex;

}TRANSPARENT_SERIAL_S;

/**
 * @struct tagTransparentIP
 * @brief 透明通道的IP地址信息
 * @attention
 */
typedef struct tagTransparentIP
{
    /** 通道端描述(第三方),可更改 */
    CHAR szChannelDesc[IMOS_DESC_LEN];

    /** IP地址 */
    CHAR szTCIPAddress[IMOS_IPADDR_LEN];

    /** 透明通道端口号 */
    ULONG_32 ulTCPort;
}TRANSPARENT_IP_S;



/**
 * @struct tagTransparentInfo
 * @brief 透明通道信息
 * @attention
 */
typedef struct tagTransparentInfo
{
    /** 透明通道基本信息 */
    TRANSPARENT_CHANNEL_S   stTransparentChannel;

    /** 透明通道串口数组中串口的实际数目, 最大取值为#IMOS_TRANSPARENT_SERIAL_NUM */
    ULONG_32                   ulSerialNum;

    /** 透明通道串口数组 */
    TRANSPARENT_SERIAL_S    astTransparentSerial[IMOS_TRANSPARENT_SERIAL_NUM];

    /** 透明通道的IP地址信息数组中IP地址信息的实际数目, 最大取值为#IMOS_TRANSPARENT_IP_NUM */
    ULONG_32                   ulIPNum;

    /** 透明通道的IP地址信息数组 */
    TRANSPARENT_IP_S        astTransparentIP[IMOS_TRANSPARENT_IP_NUM];

}TRANSPARENT_INFO_S;


/**
 * @struct tagTransparentQueryItem
 * @brief 透明通道信息项(查询透明通道列表时返回)
 * @attention
 */
typedef struct tagTransparentQueryItem
{
    /** 透明通道编码 */
    CHAR                    szTransChnlCode[IMOS_RES_CODE_LEN];

    /** 使能状态, 取值为#TL_TRANS_CHANNEL_STATUS_E */
    ULONG_32                   ulEnabledFlag;

    /** 透明通道信息 */
    TRANSPARENT_INFO_S  stTransparentInfo;

}TRANSPARENT_QUERY_ITEM_S;




/***************************************************************************************************
云台控制
****************************************************************************************************/
/**
 * @struct tagPTZCtrlCommand
 * @brief 云台控制指令
 * @attention
 */
typedef struct  tagPTZCtrlCommand
{
    /** 云台控制命令类型, 取值为#MW_PTZ_CMD_E */
    ULONG_32    ulPTZCmdID ;

    /** 控制命令的参数值1, 当该参数含义为云台转速时取值不能超过#MAX_PTZ_SPEED */
    ULONG_32   ulPTZCmdPara1;

    /** 控制命令的参数值2, 当该参数含义为云台转速时取值不能超过#MAX_PTZ_SPEED */
    ULONG_32   ulPTZCmdPara2;

    /** 控制命令的参数值3,保留字段 */
    ULONG_32   ulPTZCmdPara3;

}PTZ_CTRL_COMMAND_S;



/**************************************************************************************************************
检索回放 Record Retrieval, Edited by sunyifan (06966) 13.Mar.2009 Complete
************************************************************************************************************/

/**
* @struct tagRecQueryInfo
* @brief 回放相关检索消息数据结构
*/
typedef struct tagRecQueryInfo
{
    /** 摄像头编码 */
    CHAR                szCamCode[IMOS_RES_CODE_LEN];

    /** 检索的起始/结束时间 */
    TIME_SLICE_S        stQueryTimeSlice;

    /* 录像的域级别计数: 用于国标协议跨域回放 */
    ULONG_32               ulDomainLevel;

    /* Begin add by zhengyibing(01306), 2014-04-19 for 新国标修订*/
    /* 新增模糊查询类型  #INDISTINCT_QUERY_TYPE_E */
    ULONG_32                ulIndistinctQuery;

    /* 新增录像检索类型  #RECORD_QUERY_TYPE_E */
    ULONG_32                ulType;
    /* End add by zhengyibing(01306), 2014-04-19 for 新国标修订*/

    /** 保留字段 */
    CHAR szReserve[20];
}REC_QUERY_INFO_S;


/**
* @struct tagRecordFileInfo
* @brief 录像文件信息(查询录像文件列表时返回)
*/
typedef struct tagRecordFileInfo
{
    /** 文件名 */
    CHAR szFileName[IMOS_FILE_NAME_LEN];

    /** 文件起始时间, 满足"%Y-%m-%d %H:%M:%S"格式, 长度限定为24字符 */
    CHAR szStartTime[IMOS_TIME_LEN];

    /** 文件结束时间, 满足"%Y-%m-%d %H:%M:%S"格式, 长度限定为24字符 */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** 文件大小, 目前暂不使用 */
    ULONG_32 ulSize;

    /** 描述信息, 可不填 */
    CHAR szSpec[IMOS_DESC_LEN];

}RECORD_FILE_INFO_S;

/**
* @struct tagRecordFileInfoV2
* @brief 录像文件信息(查询录像文件列表时返回)(V2)
*/
typedef struct tagRecordFileInfoV2
{
    /** 文件名 */
    CHAR szFileName[IMOS_FILE_NAME_LEN_V2];

    /** 文件起始时间, 满足"%Y-%m-%d %H:%M:%S"格式, 长度限定为24字符 */
    CHAR szStartTime[IMOS_TIME_LEN];

    /** 文件结束时间, 满足"%Y-%m-%d %H:%M:%S"格式, 长度限定为24字符 */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** 文件大小, 目前暂不使用 */
    ULONG_32 ulSize;

    /** 描述信息, 可不填 */
    CHAR szSpec[IMOS_DESC_LEN];
}RECORD_FILE_INFO_V2_S;

/**
 * @struct tagUnitedRecFileInfo
 * @brief  录像段信息结构
 * @attention
 */
typedef struct tagUnitedRecFileInfo
{
    /** 文件名 */
    CHAR  szFileName[IMOS_FILE_NAME_LEN_V2];

    /** 文件起始时间*/
    CHAR  szStartTime[IMOS_TIME_LEN];

    /** 文件结束时间 */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 文件大小, 目前暂不使用 */
    ULONG_32 ulSize;

    /** 域级别计数，本域录像为0，低级别录像段依次累加 */
    ULONG_32 ulDomainLevel;

    /** 描述信息, 可不填 */
    CHAR  szSpec[IMOS_DESC_LEN];

    /* 预留字段 */
    CHAR  szReserved[128];
}UNITED_REC_FILE_INFO_S;

/**
* @struct tagGetUrlInfo
* @brief 获取录像文件URL的请求结构
*/
typedef struct tagGetUrlInfo
{
    /** 摄像机编码 */
    CHAR            szCamCode[IMOS_RES_CODE_LEN];

    /** 录像文件名 */
    CHAR            szFileName[IMOS_FILE_NAME_LEN];

    /** 录像的起始/结束时间, 其中的时间格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stRecTimeSlice;

    /** 客户端IP地址 */
    CHAR            szClientIp[IMOS_IPADDR_LEN];

}GET_URL_INFO_S;

/**
* @struct tagGetUrlInfoV2
* @brief 获取录像文件URL的请求结构(V2)
*/
typedef struct tagGetUrlInfoV2
{
    /** 摄像机编码 */
    CHAR            szCamCode[IMOS_RES_CODE_LEN];

    /** 录像文件名 */
    CHAR            szFileName[IMOS_FILE_NAME_LEN_V2];

    /** 录像的起始/结束时间, 其中的时间格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stRecTimeSlice;

    /** 客户端IP地址 */
    CHAR            szClientIp[IMOS_IPADDR_LEN];

}GET_URL_INFO_V2_S;

/**
* @struct tagGetUrlInfoV3
* @brief 获取录像文件URL的请求结构(V3)
*/
typedef struct tagGetUrlInfoV3
{
    /** 获取录像文件URL请求V2 */
    GET_URL_INFO_V2_S stGetUrlInfo;

    /** 回放中继策略#IMOS_VOD_STREAM_SERVER_MODE_E */
    ULONG_32 ulPlaybackAutofit;

    /** 保留字段 */
    CHAR   szReserve[128];

}GET_URL_INFO_V3_S;

/**
* @struct tagUnitedGetUrlInfo
* @brief 获取云录像URL的请求结构
*/
typedef struct tagUnitedGetUrlInfo
{
    /** 摄像机编码 */
    CHAR szCamCode[IMOS_CODE_LEN];

    /** 录像文件名 */
    CHAR szFileName[IMOS_FILE_NAME_LEN_V2];

    /** 录像的起始/结束时间, 其中的时间格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S stRecTimeSlice;

    /** 客户端IP地址 */
    CHAR szClientIp[IMOS_IPADDR_LEN];

    /** 回放中继策略#IMOS_VOD_STREAM_SERVER_MODE_E */
    ULONG_32 ulPlaybackAutofit;

    /** 域级别计数: 0xFFFF为无效的域级别计数 */
    ULONG_32 ulDomainLevel;

    /** 备份业务类型，取值#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32           ulBakSrvType;

    /** 案件录像编码，备份业务类型为案件备份时有效 */
    CHAR            szCaseRecCode[IMOS_CODE_LEN];

    /** 保留字段 */
    CHAR   szReserve[76];
}UNITED_GET_URL_INFO_S;

/**
* @struct tagAddTagInfo
* @brief 录像标签信息
*/
typedef struct tagAddTagInfo
{

    /** 摄像机编码 */
    CHAR                szCamCode[IMOS_RES_CODE_LEN];

    /** 标签的时间段, 其中的开始时间和结束时间的格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stTagTime;

    /** 标签内容 */
    CHAR                szTag[IMOS_RECORD_LABEL_LEN];

}ADD_TAG_INFO_S;


/**
* @struct tagTagQueryCondition
* @brief 标签检索条件
*/
typedef struct tagTagQueryCondition
{
    /** 摄像机编码 */
    CHAR                szCamCode[IMOS_RES_CODE_LEN];

    /** 检索的起始/结束时间, 时间格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S        stQueryTimeSlice;

    /** 查询条件是否包含标签内容, BOOL_TRUE为包含标签内容; BOOL_FALSE为不包含标签内容 */
    BOOL_T  bUseTag;

    /** 标签内容 */
    CHAR                szTag[IMOS_RECORD_LABEL_LEN];

}TAG_QUERY_CONDITION_S;


/**
* @struct tagTagQueryItem
* @brief 标签查询信息列表单元信息
*/
typedef struct tagTagQueryItem
{
    /** 标签编码 */
    CHAR            szTagCode[IMOS_RES_CODE_LEN];

    /** 标签时间点 */
    CHAR            szTagTime[IMOS_TIME_LEN];

    /** 标签字符串*/
    CHAR            szTag[IMOS_RECORD_LABEL_LEN];

}TAG_QUERY_ITEM_S;

/**
* @struct tagVODSeverIpAddr
* @brief 点播服务器的IP地址和端口
*/
typedef struct tagVODSeverIpAddr
{
    /** RTSP服务器IP地址 */
    CHAR   szServerIp[IMOS_IPADDR_LEN];

    /** RTSP服务器端口 */
    USHORT  usServerPort;

    /** 补齐位, 用于字节对齐, 无实际含义 */
    CHAR    acReserved[2];
}VOD_SEVER_IPADDR_S;


/**
* @struct tagURLInfo
* @brief URL信息数据结构
*/
typedef struct tagURLInfo
{
    /** URL地址*/
    CHAR                        szURL[IMOS_IE_URL_LEN];

    /** 点播服务器的IP地址和端口 */
    VOD_SEVER_IPADDR_S      stVodSeverIP;

    /** 解码插件类型 */
    CHAR szDecoderTag[IMOS_STRING_LEN_64];

}URL_INFO_S;



/***************************************************************************
CS业务
****************************************************************************/

/**
 * @struct tagMonitorUnit
 * @brief 实时监控记录
 * @attention
 */
typedef struct tagMonitorUnit
{
    /** 监控关系所属的顶层业务类型: 实时 轮切 计划轮切, 取值为#SRV_TYPE_E */
    ULONG_32 ulTopSrvType;

    /** 监视器编码 */
    CHAR  szMonitorCode[IMOS_RES_CODE_LEN];

    /** 监视器类型#IMOS_TYPE_XP_WIN代表窗格, #IMOS_TYPE_MONITOR代表监视器 */
    ULONG_32 ulMonitorType;

    /** 监视器名称, 当为XP窗格时, 提供窗格编码 */
    CHAR  szMonitorName[IMOS_NAME_LEN];

    /** 监视器所属域编码 */
    CHAR  szMonitorDomain[IMOS_DOMAIN_CODE_LEN];

    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 摄像机所属域 */
    CHAR  szCameraDomain[IMOS_DOMAIN_CODE_LEN];

    /** 用户名称 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户登录IP地址 */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

    /** 监控关系状态, 取值为#SRV_STATE_E */
    ULONG_32 ulSrvState;
}MONITOR_UNIT_S;

/**
 * @struct tagMonitorRec
 * @brief 实时监控记录
 * @attention
 */
typedef struct tagMonitorRec
{
    /** 监视器编码 */
    CHAR  szMonitorCode[IMOS_RES_CODE_LEN];

    /** 监视器名称, 当为XP窗格时, 提供窗格编码 */
    CHAR  szMonitorName[IMOS_NAME_LEN];

    /** 监视器所属域编码 */
    CHAR  szMonitorDomain[IMOS_DOMAIN_CODE_LEN];

    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 摄像机所属域 */
    CHAR  szCameraDomain[IMOS_DOMAIN_CODE_LEN];

    /** 用户名称 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户登录IP地址 */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

    /** 监控关系状态, 取值为#SRV_STATE_E */
    ULONG_32 ulSrvState;

    /** 流类型 */
    ULONG_32 ulStreamType;
}MONITOR_REC_S;

/**
 * @struct tagSrvStateInfo
 * @brief 业务状态信息
 * @attention 状态范围#SRV_STATE_E
 */
typedef struct tagSrvStateInfo
{
    /** 实况业务状态, 取值为#SRV_STATE_E */
    ULONG_32 ulMonitorState;

    /** 轮切业务状态, 取值为#SRV_STATE_E */
    ULONG_32 ulSwitchState;

    /** 计划轮切状态, 取值为#SRV_STATE_E */
    ULONG_32 ulPlanSwitchState;

    /** 语音对讲状态, 取值为#SRV_STATE_E */
    ULONG_32 ulVocTalkState;

    /** 语音广播状态, 取值为#SRV_STATE_E */
    ULONG_32 ulVocBrdState;

    /* added by z06806 for vodwall prj 20101215 begin */
    /** 回放上墙状态，取值为#SRV_STATE_E */
    ULONG_32 ulVod2TVState;
    /* added by z06806 for vodwall prj 20101215 end */
}SRV_STATE_INFO_S;

/**
 * @struct tagResSrvStateInfo
 * @brief 资源上业务状态信息
 * @attention 状态范围#SRV_STATE_E
 */
typedef struct tagResSrvStateInfo
{
    /** 组显示状态, 取值为#SRV_STATE_E */
    ULONG_32 ulSalvoState;

    /** 组轮巡状态, 取值为#SRV_STATE_E */
    ULONG_32 ulGroupsalvoState;

/* Begin Added by dengshuhua00673, 2012-12-26 of 自动布局轮巡 */
	/** 自动布局组轮巡状态, 取值为#SRV_STATE_E */
    ULONG_32 ulAutosalvoState;
/* End Added by dengshuhua00673, 2012-12-26 of 自动布局轮巡 */

}RES_SRV_STATE_INFO_S;

/**
 * @struct tagSwitchResUnit
 * @brief 轮切资源单元信息
 * @attention
 */
typedef struct tagSwitchResUnit
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** 轮切时长, 取值范围为#MIN_TIME_SWITCH_INTERVAL~#MAX_TIME_SWITCH_INTERVAL */
    ULONG_32   ulSwitchTime;
}SWITCH_RES_UNIT_S;

/**
 * @struct tagSwitchResBase
 * @brief 轮切资源基本信息
 * @attention
 */
typedef struct tagSwitchResBase
{
    /** 轮切资源编码 */
    CHAR    szSwitchResCode[IMOS_RES_CODE_LEN];

    /** 轮切资源名称 */
    CHAR       szSwitchResName[IMOS_NAME_LEN];

    /** 用户名称 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户登录IP地址 */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

}SWITCH_RES_BASE_S;

/**
 * @struct tagVocBrdUnit
 * @brief 语音广播单元信息
 * @attention
 */
typedef struct tagVocBrdUnit
{
    /** 摄像机编码 */
    CHAR        szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR        szCameraName[IMOS_NAME_LEN];

    /** 广播状态, 取值为#VOCBRD_STATUS_E */
    ULONG_32       ulState;
}VOC_BRD_UNIT_S;





/***************************************************************************************
日志管理
—***********************************************************************************/

/**
 * @struct tagOperateLogInfo
 * @brief 操作日志信息
 * @attention
 */
typedef struct tagOperateLogInfo
{
    /** 操作者名 */
    CHAR    szOperatorName[IMOS_NAME_LEN];

    /** 操作时间 */
    CHAR    szTime[IMOS_TIME_LEN];

    /** 操作者IP地址 */
    CHAR    szIpAddress[IMOS_IPADDR_LEN];

    /** 操作类型, 取值为#OPERATE_TYPE_E */
    ULONG_32   ulOperateType;

    /** 操作结果, 取值为该操作返回的错误码 */
    ULONG_32   ulResult;

    /** 操作描述 */
    CHAR    szOperateDesc[IMOS_STRING_LEN_512];

    /** 操作失败原因 */
    CHAR    szCause[IMOS_STRING_LEN_128];

    /** 业务类型, 取值为#SRV_TYPE_E */
    ULONG_32   ulOperationType;

    /** 操作对象 */
    CHAR         szOperateObject[IMOS_STRING_LEN_512];
 }OPERATE_LOG_S;


/***************************************************************************
 推送给UI的信息数据结构
****************************************************************************/

/**
* @struct tagASStaPushUI
* @brief 推送给UI的设备状态信息数据结构
*/
typedef struct tagASStaPushUI
{
    /** 父设备类型 见IMOS_TYPE_E,在sdk_def.h中定义 */
    ULONG_32      ulParDevType;
    /** 父设备编码 */
    CHAR    szParDevCode[IMOS_DEVICE_CODE_LEN];
    /** 设备状态 1-#IMOS_DEV_STATUS_ONLINE和2-#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义
                 如果父设备类型为"摄像机",则设备状态取值为#AS_CAMERA_STATUS_E */
    ULONG_32   ulDevSta;
    /* 是否有子设备 */
    BOOL_T  bHasSubDev;
    /** 子设备类型 */
    ULONG_32      ulSubDevType;
    /** 子设备编码 */
    CHAR    szSubDevCode[IMOS_DEVICE_CODE_LEN];
}AS_STAPUSH_UI_S;


/**
* @struct tagASAlarmPushUI
* @brief 推送给UI的告警信息数据结构
*/
typedef struct tagASAlarmPushUI
{
    /** 告警事件编码 */
    CHAR  szAlarmEventCode[IMOS_RES_CODE_LEN];
    /** 告警源编码 */
    CHAR  szAlarmSrcCode[IMOS_DEVICE_CODE_LEN];
    /** 告警源名称 */
    CHAR  szAlarmSrcName[IMOS_NAME_LEN];
    /** 使能后名字*/
    CHAR  szActiveName[IMOS_NAME_LEN];
    /** 告警类型 AlARM_TYPE_E 在sdk_def.h中定义 */
    ULONG_32  ulAlarmType;
    /** 告警级别 ALARM_SEVERITY_LEVEL_E 在sdk_def.h中定义 */
    ULONG_32  ulAlarmLevel;
    /** 告警触发时间 */
    CHAR   szAlarmTime[IMOS_TIME_LEN];
    /** 告警描述信息 */
    CHAR  szAlarmDesc[IMOS_DESC_LEN];
}AS_ALARMPUSH_UI_S;


/**
* @struct tagASDelExdomainPushUI
* @brief 推送给UI的外域(组织)删除结果数据结构
*/
typedef struct tagASDelExdomainPushUI
{
    /** 被删除域(组织)编码 */
    CHAR  szOrgCode[IMOS_CODE_LEN];

    /** 被删除域(组织)名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** 删除结果，返回错误码*/
    ULONG_32  ulDelResult;

}AS_DEL_EXDOMAIN_PUSH_UI_S;

/* added by z06806 for vodwall prj 20101203 begin */
/**
* @struct tagCSVodwallReaveNotify
* @brief SOI 实时被抢占信息 结构
* @attention 无
*/
typedef struct tagCSVodwallReaveNotify
{
    ULONG_32   ulDeviceType;                             /* 被抢占的设备类型 */
    CHAR    szMonitorCode[IMOS_CODE_LEN];             /* 监视器编码 */
    CHAR    szMonitorName[IMOS_NAME_LEN];             /* 监视器名称 */
    CHAR    szXPCode[IMOS_CODE_LEN];                  /* XP编码 */
    CHAR    szXPName[IMOS_NAME_LEN];                  /* XP名称 */
    CHAR    szDomainCode[IMOS_CODE_LEN];              /* 监视器所在域编码 */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* 监视器所在域名称 */
    CHAR    szUserName[IMOS_NAME_LEN];                /* 抢占操作的用户名 */
    CHAR    szUserLoginCode[IMOS_CODE_LEN];           /* 抢占操作用户登录编码 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* 抢占操作用户的登录IP */
}CS_VODWALL_REAVE_NOTIFY_S;
/* added by z06806 for vodwall prj 20101203 end */

/**
* @struct tagASShareDevBasicInfo
* @brief 推送给UI的共享设备基本信息数据结构
*/
typedef struct tagASShareDevBasicInfo
{
    /** 设备编码 */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR    szDevName[IMOS_NAME_LEN];

    /** 设备状态 1在线，2离线 */
    ULONG_32             ulDevStatus;

    /** 设备额外状态  DEV_EXT_STATUS_E 在sdk_def.h中定义 */
    ULONG_32             ulDevExtStatus;

    /** 设备类型，取值IMOS_TYPE_E */
    ULONG_32   ulDevType;

    /** 设备子类型，目前只有摄像机取CAMERA_TYPE_E 在sdk_def.h中定义 */
    ULONG_32   ulDevSubType;

    /** 支持的流数目，只对摄像机类型有效，0:无效值，1:单流，2:双流 */
    ULONG_32  ulStreamNum;              /* Added for DoubleStream */
}AS_SHAREDEV_BASIC_INFO_S;


/**
* @struct tagASDevPushUI
* @brief 推送给UI的共享设备信息数据结构
*/
typedef struct tagASDevPushUI
{
    /** 设备所属域编码 */
    CHAR   szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备所属域名称 */
    CHAR   szDomainName[IMOS_NAME_LEN];

    /** 操作类型，取值为 AS_DEVSHARE_OPERATION_TYPE_E */
    ULONG_32                       ulOperType;

    /** 共享设备基本信息 */
    AS_SHAREDEV_BASIC_INFO_S    stDevContent;
}AS_DEVPUSH_UI_S;


/* Begin: Added by MultiDomain */
/**
* @struct tagASExdomainStaPushUI
* @brief 推送给UI的外域状态信息数据结构
*/
typedef struct tagASExdomainStaPushUI
{
    /** 外域编码 */
    CHAR   szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** 外域名称 */
    CHAR   szDomainName[IMOS_NAME_LEN];

    /** 主动注册状态，指本域向此外域注册是否成功 */
    ULONG_32                     ulActiveRegSta;

    /** 接收注册状态，指此外域向本域注册是否成功 */
    ULONG_32                     ulRecvRegSta;
}AS_EXDOMAIN_STAPUSH_UI_S;
/* End: Added by MultiDomain */


/**
* @struct tagCSMonitorReaveNotify
* @brief SOI 实时被抢占信息 结构
* @attention 无
*/
typedef struct tagCSMonitorReaveNotify
{
    ULONG_32   ulDeviceType;                             /* 被抢占的设备类型 */
    CHAR    szMonitorCode[IMOS_DEVICE_CODE_LEN];      /* 监视器/XP窗格编码 */
    CHAR    szMonitorName[IMOS_NAME_LEN];             /* 监视器/XP窗格名称 */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];       /* 摄像机编码 */
    CHAR    szCameraName[IMOS_NAME_LEN];              /* 摄像机名称 */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];       /* 监视器/XP窗格所在域编码 */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* 监视器/XP窗格所在域名称 */
    CHAR    szUserName[IMOS_NAME_LEN];                /* 抢占操作的用户名 */
    CHAR    szUserLoginCode[IMOS_RES_CODE_LEN];       /* 抢占操作用户登录编码 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* 抢占操作用户的登录IP */
}CS_MONITOR_REAVE_NOTIFY_S;


/**
* @struct tagCSSwitchReaveNotify
* @brief SOI 轮切被抢占信息 结构
* @attention 无
*/
typedef struct tagCSSwitchReaveNotify
{
    ULONG_32   ulDeviceType;                             /* 被抢占的设备类型 */
    CHAR    szMonitorCode[IMOS_DEVICE_CODE_LEN];      /* 监视器/XP窗格编码 */
    CHAR    szMonitorName[IMOS_NAME_LEN];             /* 监视器/XP窗格名称 */
    CHAR    szSwitchResCode[IMOS_RES_CODE_LEN];       /* 轮切资源编码 */
    CHAR    szSwitchResName[IMOS_RES_CODE_LEN];       /* 轮切资源名称 */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];       /* 监视器/XP窗格所在域编码 */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* 监视器/XP窗格所在域名称 */
    CHAR    szUserName[IMOS_NAME_LEN];                /* 抢占操作的用户名 */
    CHAR    szUserLoginCode[IMOS_RES_CODE_LEN];       /* 抢占操作用户登录编码 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* 抢占操作用户的登录IP */
}CS_SWITCH_REAVE_NOTIFY_S;

/**
* @struct tagCSVocSrvReaveNotify
* @brief SOI 语音业务被抢占信息 结构
* @attention 无
*/
typedef struct tagCSVocSrvReaveNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                /* 用户名 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* 抢占操作用户的登录IP */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];       /* 摄像机编码 */
    CHAR    szCameraName[IMOS_NAME_LEN];              /* 摄像机名 */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];       /* 域编码 */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* 域名 */
    ULONG_32   ulPreSrvType;                             /* 抢占前的类型（对讲或广播），枚举值为:SRV_TYPE_E */
    ULONG_32   ulCurSrvType;                             /* 抢占后的类型（对讲或广播），枚举值为:SRV_TYPE_E */
}CS_VOCSRV_REAVE_NOTIFY_S;


/**
* @struct tagCSPtzReaveNotify
* @brief SOI 云台业务被抢占信息 结构
* @attention 无
*/
typedef struct tagCSPtzReaveNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                  /* 用户名称 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];           /* 抢占操作用户的登录IP */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];         /* 摄像机编码 */
    CHAR    szCameraName[IMOS_NAME_LEN];                /* 摄像机名称 */
    ULONG_32   ulNotifyType;                               /* 通知类型 对应枚举:PTZ_NOTIFY_UI_EVENT_TYPE */
}CS_PTZ_REAVE_NOTIFY_S;

/**
* @struct tagCSNotifyUITrbEventProc
* @brief 通知UI故障处理事件处理
* @attention 实况、轮切、语音业务释放复用结构，摄像机编码只提供给语音使用
*/
typedef struct tagCSNotifyUITrbEventProc
{
    /** XP窗格编码 */
    CHAR szXPWinCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机编码 语音业务使用 */
    CHAR szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 业务类型 */
    ULONG_32 ulServiceType;

}CS_NOTIFY_UI_TRB_EVENT_PROC_S;

/**
* @struct tagCSNotifyCameraInfo
* @brief 业务建立消息通知摄像机信息结构
* @attention 无
*/
typedef struct tagCSNotifyCameraInfo
{
    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 摄像机类型 */
    ULONG_32 ulCameraType;

}CS_NOTIFY_CAMERA_INFO_S;

/**
* @struct tagCSNotifySwitchResInfo
* @brief 业务建立消息通知轮切资源信息结构
* @attention 无
*/
typedef struct tagCSNotifySwitchResInfo
{
    /** 轮切资源编码 */
    CHAR  szSwitchResCode[IMOS_RES_CODE_LEN];

    /** 轮切资源名称 */
    CHAR szSwitchResName[IMOS_NAME_LEN];

}CS_NOTIFY_SWITCH_RES_INFO_S;

/**
* @struct tagCSNotifyReplayActionInfo
* @brief 业务建立消息通知联动警前录像结构
* @attention 无
*/
typedef struct tagCSNotifyReplayActionInfo
{
    /** 是否启用警前录像，取值0：否，1：是 */
    ULONG_32  ulIsBefAlarmReplay;

    /** 警前录像时间间隔，取值单位秒 */
    ULONG_32  ulBefAlarmRepInterval;

     /** 告警时间 格式为 "YYYY-MM-DD hh:mm:ss" */
    CHAR   szAlarmTime[IMOS_TIME_LEN];

    /** 联动警前录像的XP窗格编码 */
    CHAR   szRepXPWinCode[IMOS_CODE_LEN];

}CS_NOTIFY_REPLAY_ACTION_INFO_S;


/**
* @struct tagCSNotifyScreenActionInfo
* @brief 业务建立消息通知联动抓拍信息结构
* @attention 无
*/
typedef struct tagCSNotifyScreenActionInfo
{
    /** 是否抓拍, 取值为0或1 */
    ULONG_32    ulSnatchImage;

    /** 抓拍间隔，取值单位毫秒 */
    ULONG_32    ulInterval;

    /** 抓拍张数 */
    ULONG_32    ulSnatchCounter;
    /* 联动警前录像结构 */
    CS_NOTIFY_REPLAY_ACTION_INFO_S  stReplayActInfo;

    /* 保留字段 */
    CHAR     szParam[IMOS_IDLE_LEN];

}CS_NOTIFY_SCREEN_ACTION_INFO_S;


/**
* @struct tagCSNotifyUISrvSetup
* @brief 通知UI业务建立（实时监控，轮切）
* @attention 业务恢复，告警联动复用结构；设备信息结构用于实况恢复，轮切资源信息用于轮切恢复
*/
typedef struct tagCSNotifyUISrvSetup
{
    /** XP窗格编码 */
    CHAR                        szXPWinCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机信息 */
    CS_NOTIFY_CAMERA_INFO_S     stCameraInfo;

    /** 轮切资源信息 */
    CS_NOTIFY_SWITCH_RES_INFO_S stSwitchResInfo;

    /** 业务类型 */
    ULONG_32                       ulServiceType;

}CS_NOTIFY_UI_SRV_SETUP_S;

/***************************************************************************************
LICENCE
—***********************************************************************************/

/**
* @struct tagContactInfo
* @brief 联系人信息结构
* @attention 无
*/
typedef struct tagContactInfo
{
    /** 联系人姓名 */
    CHAR szName[IMOS_NAME_LEN];

    /** 联系人所在公司 */
    CHAR szCompany[IMOS_NAME_LEN];

    /** 联系人email地址 */
    CHAR szEmail[IMOS_MAIL_LEN];

    /** 联系人电话 */
    CHAR szPhone[IMOS_PHONE_LEN];

    /** 联系人邮编 */
    CHAR szZipcode[IMOS_MAIL_CODE_LEN];

    /** 联系人地址 */
    CHAR szAddress[IMOS_CONTACT_ADDRESS_LEN];

} CONTACTINFO_S;

/**
* @struct tagClientInformation
* @brief 客户信息结构
* @attention 无
*/
typedef struct tagClientInformation
{
    /** 客户名称，一般同公司名称 */
    CHAR szClientName[IMOS_NAME_LEN];

    /** 国家 */
    CHAR szCountry[IMOS_NAME_LEN];

    /** 省 */
    CHAR szProvince[IMOS_NAME_LEN];

    /** 县市 */
    CHAR szCity[IMOS_NAME_LEN];

    /** 公司 */
    CHAR szCompany[IMOS_NAME_LEN];

    /** 邮编 */
    CHAR szZipcode[IMOS_MAIL_CODE_LEN];

    /** 地址 */
    CHAR szAddress[IMOS_CONTACT_ADDRESS_LEN];

    /** email地址 */
    CHAR szEmail[IMOS_MAIL_LEN];

    /** 电话 */
    CHAR szPhone[IMOS_PHONE_LEN];

    /** 联系人信息 */
    CONTACTINFO_S stContactInfo;

} CLIENTINFO_S;

/**
* @struct tagLicenseAuthorityInfo
* @brief 业务规格信息(查询License业务规格信息或列表时返回)
* @attention 无
*/
typedef struct tagLicenseAuthorityInfo
{
    /** 业务类型, 取值为#LICENSE_TYPE_E */
    ULONG_32 ulServiceType;

    /** 授权规格, 依据查询时的返回结果 */
    ULONG_32 ulServiceValue;

} LICENSE_AUTHORITYINFO_S;


/**
* @struct tagTimeLimit
* @brief 有效期限信息(查询License时间信息时返回)
* @attention 无
*/
typedef struct tagTimeLimit
{
    /** License创建日期 */
    CHAR szCreateDay[IMOS_TIME_LEN];

    /** License的有效天数 */
    ULONG_32 ulTotalDay;

    /** 已使用天数 */
    ULONG_32 ulUsedDay;

}TIMELIMIT_S;


/***************************************************************************************************
升级管理
****************************************************************************************************/
/**
* @struct tagUpgTaskInfo
* @brief  升级任务信息
* @attention 无
*/
typedef struct tagUpgTaskInfo
{
    /** 是否立即执行, BOOL_TRUE为立即执行; BOOL_FALSE为非立即执行 */
    BOOL_T bIsImmediateExe;

    /** 升级任务名 */
    CHAR szUpgJobName[IMOS_NAME_LEN];

    /** 升级任务描述, 可不填 */
    CHAR szUpgJobDesc[IMOS_DESC_LEN];

    /** 升级任务创建者, 为当前操作用户名 */
    CHAR szUpgJobCreator[IMOS_NAME_LEN];

    /** 升级任务调度时间（具体时分秒）, 格式为"YYYY-MM-DD HH:MM:SS" */
    CHAR szUpgJobSchdTime[IMOS_TIME_LEN];

    /** 升级任务完成时间, 格式为"YYYY-MM-DD HH:MM:SS", 该值在查询升级任务信息时有效, 其它情况不填写 */
    CHAR szUpgJobFinishTime[IMOS_TIME_LEN];

    /** 升级任务制定时间, 增加升级任务的时候不必填写 */
    CHAR szUpgJobEstablishTime[IMOS_TIME_LEN];
} UPG_TASK_INFO_S;


/**
* @struct  tagUpgDevInfo
* @brief 升级设备信息结构
* @attention 无
*/
typedef struct tagUpgDevInfo
{
    /** 设备编码 */
    CHAR szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR szDevName[IMOS_NAME_LEN];

    /** 设备升级前版本号 */
    CHAR szDevOldVersion[IMOS_STRING_LEN_256];

    /** 设备待升级版本号 */
    CHAR szDevUpgVersion[IMOS_STRING_LEN_256];

    /** 设备升级状态，查询时有效，取值为#MM_JOBDEVSTATUS_E */
    ULONG_32 ulDevUpgStatus;

    /** 设备升级结果，查询时有效，取值为#MM_JOBDEVRESULT_E */
    ULONG_32 ulUpgResult;

    /** 设备升级扩展结果，反映具体升级结果，查询时有效，取值为#MM_UPGDEVEXTRESULT_E */
    ULONG_32 ulDevUpgExtResult;
} UPG_DEV_INFO_S;


/**
* @struct tagUpgTaskQueryItem
* @brief  升级任务信息项(查询升级任务列表时返回)
* @attention 无
*/
typedef struct tagUpgTaskQueryItem
{
    /** 升级任务编码 */
    CHAR szUpgTaskCode[IMOS_RES_CODE_LEN];

    /** 升级任务名 */
    CHAR szUpgJobName[IMOS_NAME_LEN];

    /** 升级任务创建者 */
    CHAR szUpgJobCreator[IMOS_NAME_LEN];

    /** 升级任务调度时间（具体时分秒），格式为"YYYY-MM-DD HH:MM:SS" */
    CHAR szUpgJobSchdTime[IMOS_TIME_LEN];

    /** 升级任务完成时间 */
    CHAR szUpgJobFinishTime[IMOS_TIME_LEN];

    /** 升级任务制定时间 */
    CHAR szUpgJobEstablishTime[IMOS_TIME_LEN];

    /** 升级任务状态, 取值为#MM_JOBDEVSTATUS_E  */
    ULONG_32 ulUpgJobStatus;

    /** 升级任务结果, 取值为#MM_JOBDEVRESULT_E*/
    ULONG_32 ulUpgJobResult;
} UPG_TASK_QUERY_ITEM_S;


/**
* @struct tagUpgAdviceInfo
* @brief 定义一个设备升级建议信息结构
* @attention 无
*/
typedef struct tagUpgAdviceInfo
{
    /** 设备编码 */
    CHAR szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR szDevName[IMOS_NAME_LEN];

    /** 设备类型描述 */
    CHAR szDevTypeDesc[IMOS_DESC_LEN];

    /** 设备当前版本号 */
    CHAR szDevCurVersion[IMOS_STRING_LEN_256];

    /** 设备待升级版本号 */
    CHAR szDevUpgVersion[IMOS_STRING_LEN_256];

    /** 设备升级建议
    * - 0 UPG_ADVICE_UNINITIAL 包括所有升级建议情况
    * - 1 UPG_ADVICE_NEED      需要升级
    * - 2 UPG_ADVICE_NONEED    不需升级*/
    ULONG_32  ulUpgAdvice;

    /** 设备在线状态 */
    ULONG_32 ulDevOnlineStatus;
} UPG_ADVICE_INFO_S;

/*******************************************************************************
信息统计
*******************************************************************************/

/**
* @struct tagSrvStatInfo
* @brief 业务信息数据统计结构
* @attention 无
*/
typedef struct tagSrvStatInfo
{
    /** 当前实况业务建立数量统计 */
    ULONG_32    ulMonitorNum;

    /** 当前轮切业务建立数量统计 */
    ULONG_32    ulSwitchNum;

    /** 当前语音业务建立数量统计 */
    ULONG_32    ulVoiceNum;

    /** 当前在线设备数量统计 */
    ULONG_32    ulDevOnlineNum;

    /** 当前在线用户数量统计 */
    ULONG_32    ulUserOnlineNum;

    /** 当前手动存储业务数量统计 */
    ULONG_32    ulManualRecordNum;
} SRV_STAT_INFO_S;

/**
 * @struct tagAlarmOutputDevQueryItem
 * @brief 告警输出设备查询信息列表单元信息
 * @attention
 */
typedef struct tagAlarmOutputDevQueryItem
{

    /** 告警输出设备的名称 */
    CHAR        szAlarmOutputDevName[IMOS_NAME_LEN];

    /** 告警输出设备的编码 */
    CHAR        szAlarmOutputDevCode[IMOS_RES_CODE_LEN];

    /** 告警输出设备的类型,枚举类型为:ALARM_OUTPUT_DEV_TYPE_E */
    ULONG_32       ulAlarmOutputDevType;

    /** 告警输出设备所属组织 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 所属组织名称 */
    CHAR        szOrgName[IMOS_NAME_LEN];

}ALARM_OUTPUT_DEV_QUERY_ITEM_S;

/**
 * @struct tagAlarmOutputDev
 * @brief 告警输出设备信息
 * @attention
 */
typedef struct tagAlarmOutputDev
{

    /** 告警输出设备的名称 */
    CHAR        szAlarmOutputDevName[IMOS_NAME_LEN];

    /** 告警输出设备的类型,枚举类型为:ALARM_OUTPUT_DEV_TYPE_E */
    ULONG_32       ulAlarmOutputDevType;

    /**告警输出设备需要绑定的通道所属设备的编码 */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /**告警输出设备需要绑定的通道所属设备的名称 */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** 告警输出设备需要绑定的通道索引 */
    ULONG_32       ulChannelIndex;
}ALARM_OUTPUT_DEV_S;


/**
* @struct tagSDKCmdInfo
* @brief 命令行执行参数
* @attention 无
*/
typedef struct tagSDKCmdInfo
{
    /** 命令ID */
    ULONG_32 ulCmdId;

    /** 命令参数列表，每个参数最大128字节，目前支持到6个参数，中间没有的参数填为空串即可 */
    CHAR szParamList[IMOS_MAX_CMD_PARAM_NUM][IMOS_MAX_CMD_PARAM_LEN];

}SDK_CMD_INFO_S;

/**
* @struct tagCSNotifyUIMediaParamChangeProc
* @brief 通知UI媒体参数改变处理结构
* @attention XPWinCode用于UI释放使用
*/
typedef struct tagCSNotifyUIMediaParamChangeProc
{
    /** 媒体改变类型 0:单/组播修改 1:MS选择策略(自适应/指定)修改 2:MS选择修改 3: 组播配置(地址/端口)修改 */
    ULONG_32 ulMediaParamChangeType;

    /** 设备类型 具体值含义详见#IMOS_TYPE_E */
    ULONG_32 ulDevType;

    /** 改变媒体参数的设备编码(可能是DC/EC/XP/CAMERA编码) */
    CHAR szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR szDevName[IMOS_NAME_LEN];

    /* XP窗格编码数 */
    ULONG_32 ulXPWinCount;

    /** XP窗格编码 */
    CHAR aszXPWinCode[IMOS_XP_WIN_MAX_NUM][IMOS_DEVICE_CODE_LEN];
}CS_NOTIFY_UI_MEDIA_PARAM_CHANGE_PROC_S;

/*******************************************************************************
电视墙
*******************************************************************************/
/**
* @struct tagScreenUnitInfo
* @brief 监视器单元信息
* @attention
*/
typedef struct tagScreenUnitInfo
{
    /** 监视器名称 */
    CHAR szScreenName[IMOS_NAME_LEN];

    /** 监视器编码 */
    CHAR szScreenCode[IMOS_CODE_LEN];

    /** 状态信息:在线为#IMOS_DEV_STATUS_ONLINE，离线为#IMOS_DEV_STATUS_OFFLINE，添加修改时状态信息无须填写 */
    ULONG_32 ulStatus;

    /** 监视器分屏数目，该值仅在查询时有效 */
    ULONG_32 ulSplitScreenNum;

    /** 扩展状态信息:0表示为监视器，1表示为DC */
    ULONG_32 ulExtStatus;
}SCREEN_UNIT_INFO_S;


/**
* @struct tagScreenLayoutInfo
* @brief 监视器布局信息
* @attention
*/
typedef struct tagScreenLayoutInfo
{
    /** 每个监视器的单元信息 */
    SCREEN_UNIT_INFO_S stScreenUnitInfo;

    /** 监视器布局信息 */
    AREA_SCOPE_S stScreenLayout;
}SCREEN_LAYOUT_INFO_S;

/**
* @struct tagTVWallInfo
* @brief 电视墙信息
* @attention 电视墙基本信息以及监视器数量、布局信息
*/
typedef struct tagTVWallInfo
{
    /** 电视墙名称 */
    CHAR szTVWallName[IMOS_NAME_LEN];

    /** 电视墙编码，增加电视墙时填写为空则平台自己生成，增加电视墙成功后返回; 若填写则按照填写的编码增加 */
    CHAR szTVWallCode[IMOS_CODE_LEN];

    /** 所属组织域编码，增加修改时需要填写，平台返回不处理该值 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 电视墙背景文件名 */
    CHAR szBackGroundFileName[IMOS_FILE_NAME_LEN];

    /** 布局编码，无需填写，查询电视墙时由平台返回 */
    CHAR szLayoutCode[IMOS_CODE_LEN];

    /** 电视墙包含的监视器实际数量, 取值最大值为#IMOS_MONITOR_MAXNUM_PER_WALL */
    ULONG_32 ulScreenCount;

    /** 电视墙分辨率, 取值为#TW_RESOLUTION_E */
    ULONG_32 ulResolution;

    /** 监视器布局信息数组 */
    SCREEN_LAYOUT_INFO_S astTVWallLayoutList[IMOS_MONITOR_MAXNUM_PER_WALL];
}TV_WALL_INFO_S;

/**
* @struct tagTVWallQueryItem
* @brief 电视墙信息项(查询电视墙列表时返回)
* @attention
*/
typedef struct tagTVWallQueryItem
{
    /** 电视墙名称 */
    CHAR szTVWallName[IMOS_NAME_LEN];

    /** 电视墙编码，若添加时填写为空则是平台自己生成的编码; 若填写则查询到的是添加时填写编码 */
    CHAR szTVWallCode[IMOS_CODE_LEN];

    /** 所属组织域编码,用于查询域以及子域下的电视墙列表，平台返回不处理该值 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 电视墙分辨率, 取值为#TW_RESOLUTION_E */
    ULONG_32 ulResolution;

    /** 电视墙包含的监视器数量 */
    ULONG_32 ulScreenCount;
}TV_WALL_QUERY_ITEM_S;

/**
* @struct tagDevStatusStatistic
* @brief 设备状态统计(查询设备故障统计的时候返回)
* @attention
*/
typedef struct tagDevStatusStatistic
{
    /** 设备类型，取值参见#IMOS_TYPE_E */
    ULONG_32  ulDevType;

    /** 在线数量 */
    ULONG_32  ulOnlineNum;

    /** 故障数量 */
    ULONG_32 ulFaultNum;

    /** 离线数量 */
    ULONG_32 ulOfflineNum;
}DEV_STATUS_STATISTIC_S;

/**
* @struct tagDevBaseInfo
* @brief 抽象设备基本信息
* @attention
*/
typedef struct tagDevBaseInfo
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备类型，取值为#IMOS_TYPE_DM, #IMOS_TYPE_MS, #IMOS_TYPE_TS, #IMOS_TYPE_VX500, #IMOS_TYPE_MONITOR, #IMOS_TYPE_EC, #IMOS_TYPE_DC, #IMOS_TYPE_CAMERA */
    ULONG_32  ulDevType;

    /** 设备子类型, 对摄像机取值见#CAMERA_TYPE_E; 对监视器无意义;
    对物理设备(EC/DC/MS/DM/VX500)取值见#IMOS_DEVICE_TYPE_E. */
    ULONG_32  ulDevSubType;

    /** 设备状态，取值为#IMOS_DEV_FAULT_STATUS_E */
    ULONG_32  ulDevStatus;

    /** 设备IP地址, 对物理设备(EC/DC/MS/DM/VX500)有效 */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** 域编码 */
    CHAR  szDomainCode[IMOS_CODE_LEN];

    /* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR大类 */
    /** NVR、ECR大类设备类型 */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2012-7-18 for ECR NVR大类 */
}DEV_BASIC_INFO_S;


/**
* @struct tagCSBackupFinishInfo
* @brief 备份完成通知
*/
typedef struct tagCSBackupFinishInfo
{
    /** 备份类型,取值范围见#BP_BACKUPTYPE_E */
    ULONG_32   ulBackupType;

    /** 备份结果: 0为备份成功; 其他为备份失败。*/
    ULONG_32   ulResult;
}CS_BACKUP_FINISH_INFO_S;


/**
 * @struct tagGeneralDevInfo
 * @brief 通用设备配置信息
 * @attention
 */
typedef struct tagGeneralDevInfo
{
    /** 通用设备编码，由用户输入，非平台生成 */
    CHAR  szGeneralDevCode[IMOS_DEVICE_CODE_LEN];

    /** 通用设备名称 */
    CHAR  szGeneralDevName[IMOS_NAME_LEN];

     /** 设备类型 */
    ULONG_32 ulDevType;

    /** 设备子类型 */
    ULONG_32 ulDevSubType;

    /** 设备类型描述 */
    CHAR szDevTypeDesc[IMOS_DESC_LEN];

    /** 地址类型，1-IPV4 2-IPV6 */
    ULONG_32 ulAddrType;

    /** 地址 */
    CHAR  szAddress[IMOS_IPADDR_LEN];

    /** 端口 */
    ULONG_32 ulAddrPort;

    /** 所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 设备描述 , 现在只能填写为空字符串*/
    CHAR  szDevDesc[IMOS_DESC_LEN];

    /** 设备扩展信息 */
    CHAR  szDevReserved[IMOS_RESERVED_LEN];

    /** 设备管理业务URL, 可选字段, 可修改 */
    CHAR  szSvcURL[IMOS_URL_LEN];

    /** 设备状态信息, 不可以修改赋值, 只用于查询显示, #IMOS_DEV_STATUS_ONLINE表示上线, #IMOS_DEV_STATUS_OFFLINE表示离线 */
    ULONG_32 ulStatus;
}GENERAL_DEV_INFO_S;

/**
 * @struct tagThdDevPollCfg
 * @brief 第三方设备轮询配置参数
 * @attention
 */
typedef struct tagThdDevPollCfg
{
    /** 轮询间隔, 单位分钟, 默认30分钟, 值应该大于等于1 */
    ULONG_32 ulPollInterval;

    /** 轮询超时时间, 单位秒, 默认2s, 范围: 1s-60s */
    ULONG_32 ulPollTimeOut;

    /** 单个设备一次轮询最大尝试次数, 默认3次, 范围: 1-20 */
    ULONG_32 ulPollTimes;
}THD_DEV_POLL_CFG_S;

/**
 * @struct tagInterconnectInfo
 * @brief 互联信息
 * @attention
 */
typedef struct tagInterconnectInfo
{
    /** 互联信息所属资源编码 */
    CHAR  szResCode[IMOS_RES_CODE_LEN];

    /** 互联信息类型，取值为#INTERCONNECT_INFO_TYPE_E */
    ULONG_32       ulInterInfoType;

    /** 互联协议类型，取值为#INTERDOMAIN_PROTOCOL_TYPE_E */
    ULONG_32      ulProtocolType;

    /** 域等级, 目前取值为1~7 */
    ULONG_32    ulDomainLevel;

    /** 跨域互联资源编码 */
    CHAR  szInterResCode[IMOS_RES_CODE_LEN];

    /** 跨域互联用户编码 */
    CHAR  szInterUserCode[IMOS_USER_CODE_LEN];

 }INTERCONNECT_INFO_S;


/**
 * @struct tagResourceGroupUnit
 * @brief 资源组单元信息
 * @attention
 */
typedef struct tagResourceGroupUnit
{
    /** 资源编码 */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** 资源名称 */
    CHAR        szResName[IMOS_NAME_LEN];

    /** 中心录像状态, 取值为#MANUAL_STORE_STATUS_E */
    ULONG_32 ulManualStorStatus;

    /** 操作错误码 */
    ULONG_32 ulOperateRet;

    /** 保留字段 */
    CHAR szReserve[120];
}RESOURCE_GROUP_UNIT_S;

/**
 * @struct tagResourceGroupInfo
 * @brief 资源组信息
 * @attention
 */
typedef struct tagResourceGroupInfo
{
    /** 资源组编码 */
    CHAR        szResGroupCode[IMOS_RES_CODE_LEN];

    /** 资源组名称 */
    CHAR        szResGroupName[IMOS_NAME_LEN];

    /** 资源组类型 */
    ULONG_32       ulGroupResType;

    /** 组内的资源数目 */
    ULONG_32       ulResNum;

}RESOURCE_GROUP_INFO_S;


/**
 * @struct tagLayoutInfo
 * @brief 布局信息
 * @attention
 */
typedef struct tagLayoutInfo
{
    /** 布局编码 */
    CHAR        szLayoutCode[IMOS_CODE_LEN];

    /** 布局名称 */
    CHAR        szLayoutName[IMOS_NAME_LEN];

    /** 布局描述，可不填 */
    CHAR        szLayoutDes[IMOS_DESC_LEN];

    /** 布局类型，取值为#LAYOUT_TYPE_E */
    ULONG_32       ulLayoutType;

    /** 屏幕布局时为屏幕分屏数，监视器布局时为监视器数目 */
    ULONG_32       ulScreenCount;

    /** 监视器布局信息数组，监视器布局时使用 */
    AREA_SCOPE_S astScreenLayoutList[IMOS_DISPLAY_MAXNUM_PER_LAYOUT];
}LAYOUT_INFO_S;

/**
* @struct tagLayoutInfoQueryItem
* @brief 布局信息项(查询布局列表时返回)
* @attention
*/
typedef struct tagLayoutInfoQueryItem
{
    /** 布局名称 */
    CHAR szLayoutName[IMOS_NAME_LEN];

    /** 布局编码 */
    CHAR szLayoutCode[IMOS_CODE_LEN];

    /** 布局类型，取值为#LAYOUT_TYPE_E */
    ULONG_32       ulLayoutType;
}LAYOUT_INFO_QUERY_ITEM_S;


/**
 * @struct tagSalvoUnit
 * @brief 组显示单元信息
 * @attention
 */
typedef struct tagSalvoUnit
{
    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 参数1:监视器组显示代表监视器编码 */
    CHAR        szParam1[IMOS_STRING_LEN_128];

    /** 参数2:监视器组显示代表监视器名称 */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** 参数3:屏幕组显示代表屏幕序号, 取值为1 */
    ULONG_32       ulParam3;

    /** 参数4:屏幕组显示代表窗格号 */
    ULONG_32       ulParam4;

    /** 参数5:保留 */
    ULONG_32       ulParam5;

    /** 监视器的分屏数目，仅在查询时有效 */
    ULONG_32       ulSplitScreenNum;
}SALVO_UNIT_S;

/**
 * @struct tagSalvoInfo
 * @brief 组显示信息
 * @attention
 */
typedef struct tagSalvoInfo
{
    /** 组显示类型，取值为#SALVO_TYPE_E */
    ULONG_32       ulSalvoType;

    /** 组显示编码 */
    CHAR        szSalvoCode[IMOS_CODE_LEN];

    /** 组显示名称 */
    CHAR        szSalvoName[IMOS_NAME_LEN];

    /** 布局编码，可选 */
    CHAR        szLayoutCode[IMOS_CODE_LEN];

    /** 组显示包含的显示单元实际数量, 最大值为#IMOS_DISPLAY_MAXNUM_PER_SALVO */
    ULONG_32       ulSalvoUnitNum;

    /** 组显示单元数组 */
    SALVO_UNIT_S astSalvoUnitList[IMOS_DISPLAY_MAXNUM_PER_SALVO];
}SALVO_INFO_S;

/**
 * @struct tagSalvoInfo
 * @brief 组显示信息
 * @attention
 */
typedef struct tagSalvoInfoV2
{
    /** 组显示类型，取值为#SALVO_TYPE_E */
    ULONG_32       ulSalvoType;

    /** 组显示编码 */
    CHAR        szSalvoCode[IMOS_CODE_LEN];

    /** 组显示名称 */
    CHAR        szSalvoName[IMOS_NAME_LEN];

    /** 布局编码，可选 */
    CHAR        szLayoutCode[IMOS_CODE_LEN];

    /** 组显示包含的显示单元实际数量 */
    ULONG_32       ulSalvoUnitNum;

    /** 组显示单元数组 */
    SALVO_UNIT_S astSalvoUnitList[1];
}SALVO_INFO_V2_S;

/**
* @struct tagSalvoQueryItem
* @brief 组显示信息项(查询组显示列表时返回)
* @attention
*/
typedef struct tagSalvoQueryItem
{
    /** 组显示名称 */
    CHAR szSalvoName[IMOS_NAME_LEN];

    /** 组显示编码，若添加时填写为空则是平台自己生成的编码; 若填写则查询到的是添加时填写编码 */
    CHAR szSalvoCode[IMOS_CODE_LEN];

    /** 所属组织域编码,用于查询域以及子域下的组显示列表，平台返回不处理该值 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 组显示包含的显示单元数量 */
    ULONG_32 ulSalvoUnitNum;

    /** 组显示类型，取值为#SALVO_TYPE_E */
    ULONG_32       ulSalvoType;

}SALVO_QUERY_ITEM_S;


/**
 * @struct tagCommonSwitchUnit
 * @brief 通用轮切资源中的资源信息
 * @attention
 */
typedef struct tagCommonSwitchUnit
{
    /** 资源编码 */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** 资源名称 */
    CHAR        szResName[IMOS_NAME_LEN];

    /** 资源类型 */
    ULONG_32       ulResType;

    /** 序号 */
    ULONG_32       ulSequence;

     /** 切换时间 */
    ULONG_32       ulInterval;
}COMMON_SWITCH_UNIT_S;

/**
 * @struct tagCommonSwitchResource
 * @brief 通用轮切资源信息
 * @attention
 */
typedef struct tagCommonSwitchResource
{
    /** 通用轮切类型，取值为#COMMON_SWITCH_TYPE_E */
    ULONG_32                   ulSwitchType;

    /** 通用轮切子类型，对于组轮巡代表组轮巡类型，取值为#GROUP_SWITCH_TYPE_E */
    ULONG_32                   ulSwitchSubType;

    /** 轮切基本信息 */
    SWITCH_BASE_S           stSwitchBaseInfo;

    /** 通用轮切资源数组中轮切资源的实际数目, 最大取值为#IMOS_COMMON_SWITCH_RES_MAXNUM */
    ULONG_32                   ulSwitchResNum;

    /** 通用轮切资源数组 */
    COMMON_SWITCH_UNIT_S    astSwitchUnitList[IMOS_COMMON_SWITCH_RES_MAXNUM];
}COMMON_SWITCH_RESOURCE_S;

/* Begin Added by gKF0090, 2012-12-27 of 查询摄像机组轮巡信息 */
/**
 * @struct tagGroupSwitchResList
 * @brief 组轮巡列表记录
 * @attention
 */
typedef struct tagGroupSwitchResList
{
    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 摄像机所在域 */
    CHAR  szCameraDomain[IMOS_CODE_LEN];

	/** 组轮巡ID */
	CHAR  szGroupSwitchResCode[IMOS_CODE_LEN];

	/** 组轮巡名称 */
	CHAR  szGroupSwitchResName[IMOS_NAME_LEN];

    /** 组轮巡类型*/
	ULONG_32  ulGroupSwitchResType;

	/** 组轮巡数量*/
	ULONG_32  ulGroupSwitchResNum;
}GROUP_SWITCH_RES_LIST_S;
/* End Added by gKF0090, 2012-12-27 of 查询摄像机组轮巡信息 */

/* Begin Added by dengshuhua00673, 2012-11-24 of 自动布局轮巡 */
/**
 * @struct tagCommonSwitchUnitV2
 * @brief 通用轮切资源中的资源信息V2
 * @attention
 */
typedef struct tagCommonSwitchUnitV2
{
    /** 资源编码 */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** 资源名称 */
    CHAR        szResName[IMOS_NAME_LEN];

    /** 资源类型 */
    ULONG_32       ulResType;

    /** 序号 */
    ULONG_32       ulSequence;

    /** 切换时间 */
    ULONG_32       ulInterval;

	/** 摄像机的流类型(通用轮切资源为自动布局组轮巡资源时有效) */
    ULONG_32       ulStreamType;
}COMMON_SWITCH_UNIT_V2_S;

/**
 * @struct tagCommonSwitchResourceV2
 * @brief 通用轮切资源信息V2
 * @attention
 */
typedef struct tagCommonSwitchResourceV2
{
    /** 通用轮切类型，取值为#COMMON_SWITCH_TYPE_E */
    ULONG_32	ulSwitchType;

    /** 通用轮切子类型，对于组轮巡代表组轮巡类型，取值为#GROUP_SWITCH_TYPE_E */
    ULONG_32                   ulSwitchSubType;

    /** 轮切基本信息 */
    SWITCH_BASE_S           stSwitchBaseInfo;

    /** 通用轮切资源数组中轮切资源的实际数目, 最大取值为#IMOS_COMMON_SWITCH_RES_MAXNUM */
    ULONG_32                   ulSwitchResNum;

    /** 通用轮切资源数组 */
    COMMON_SWITCH_UNIT_V2_S  astSwitchUnitList[IMOS_COMMON_SWITCH_RES_MAXNUM];

    /** 电视墙资源编码 */
    CHAR szTVWallCode[IMOS_CODE_LEN];

    /** 客户端分屏数 */
    ULONG_32 ulScrNum;

    /** 实况抢占策略(不抢占、抢占)，取值为#AUTOSALVO_REAVE_TYPE_E */
    ULONG_32 ulReaveType;

    /** 自动布局组轮巡间隔时间 */
    ULONG_32 ulNolayoutInterval;
}COMMON_SWITCH_RESOURCE_V2_S;
/* End Added by dengshuhua00673, 2012-11-24 of 自动布局轮巡 */

/**
 * @struct tagCommonSwitchPlanBase
 * @brief 通用轮切计划基本信息
 * @attention
 */
typedef struct tagCommonSwitchPlanBase
{
    /** 通用轮切计划类型，取值为#COMMON_SWITCH_PLANTYPE_E */
    ULONG_32       ulSwitchPlanType;

    /** 轮切计划名称 */
    CHAR        szPlanName[IMOS_NAME_LEN];

    /** 轮切计划创建日期 */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** 参数1，对软解轮切为用户编码 */
    CHAR        szParam1[IMOS_STRING_LEN_128];

    /** 参数2，对软解轮切为用户名称 */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** 参数3: 对软解轮切代表屏幕序号, 取值为1 */
    ULONG_32       ulParam3;

    /** 参数4，对软解轮切为窗格号 */
    ULONG_32       ulParam4;

    /** 计划类型, 取值为#PLAN_TYPE_E */
    ULONG_32       ulPlanType;

    /** 轮切计划所属组织编码 */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 计划描述, 可不填 */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}COMMON_SWITCH_PLAN_BASE_S;

/**
 * @struct tagSwitchPlanInfo
 * @brief 通用轮切计划信息
 * @attention
 */
typedef struct tagCommonSwitchPlanInfo
{
    /** 轮切计划基本信息 */
    COMMON_SWITCH_PLAN_BASE_S   stSwitchBaseInfo;

    /** 轮切计划时间信息 */
    PLAN_TIME_FOR_RES_S         stSwitchTimeInfo;
}COMMON_SWITCH_PLAN_INFO_S;


/**
 * @struct tagCommonSwitchPlanQueryItem
 * @brief 通用轮切计划信息项(查询通用轮切计划列表时返回)
 * @attention
 */
typedef struct tagCommonSwitchPlanQueryItem
{
    /** 通用轮切计划编码 */
    CHAR            szSwitchPlanCode[IMOS_RES_CODE_LEN];

    /** 通用轮切计划名称 */
    CHAR            szPlanName[IMOS_NAME_LEN];

    /** 通用轮切计划创建日期 */
    CHAR            szCreatTime[IMOS_TIME_LEN];

    /** 通用轮切计划类型，取值为#COMMON_SWITCH_PLANTYPE_E */
    ULONG_32       ulSwitchPlanType;

    /** 参数1，对软解轮切为用户编码 */
    CHAR        szParam1[IMOS_STRING_LEN_128];

    /** 参数2，对软解轮切为用户名称 */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** 参数3: 对软解轮切代表屏幕序号, 取值为1 */
    ULONG_32       ulParam3;

    /** 参数4，对软解轮切为窗格号 */
    ULONG_32       ulParam4;

    /** 计划状态，BOOL_TRUE为计划已经启动, BOOL_FALSE为计划未启动 */
    ULONG_32           ulPlanStatus;

}COMMONSWITCH_PLAN_QUERY_ITEM_S;

/*******************************************************************************
组显示
*******************************************************************************/

typedef struct tagCSSalvoStartSalvoUnit
{
    /** 监视器编码/XP窗格编码 */
    CHAR szScreenCode[IMOS_DEVICE_CODE_LEN];

    /** 监视器名称/XP窗格号 */
    CHAR szScreenName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR szCameraName[IMOS_NAME_LEN];

    /** 摄像机类型 */
    ULONG_32 ulCameraType;

    /** 实况建立结果 */
    ULONG_32 ulResultCode;

}CS_SALVO_START_SALVO_UNIT_S;

/**
* @struct tagCSNofityScreenInfo
* @brief 业务建立消息通知摄像机信息结构
* @attention 无
*/
typedef struct tagCSNofityScreenInfo
{
    /** 显示器编码 */
    CHAR  szScreenCode[IMOS_DEVICE_CODE_LEN];

    /** 显示器名称, 如果是XP窗格, 填写窗格号 */
    CHAR  szScreenName[IMOS_NAME_LEN];

    /** 显示器类型 */
    ULONG_32 ulScreenType;

}CS_NOTIFY_SCREEN_INFO_S;

/* 组显示单元信息 */
/**
* @struct tagCSNotifySalvoUnitItem
* @brief 通知UI组显示单元实况建立结果的组显示单元信息
* @attention
*/
typedef struct tagCSNotifySalvoUnitItem
{
    /** 显示器信息 */
    CS_NOTIFY_SCREEN_INFO_S stScreenInfo;

    /** 摄像机信息 */
    CS_NOTIFY_CAMERA_INFO_S stCameraInfo;

}CS_NOTIFY_SALVO_UNIT_ITEM_S;

typedef struct tagCSNotifySalvoInfo
{
    /** 组显示编码 */
    CHAR szSalvoCode[IMOS_RES_CODE_LEN];

    /** 组显示名称 */
    CHAR szSalvoName[IMOS_NAME_LEN];

    /** 组显示单元数量 */
    ULONG_32 ulSalvoUnitNum;

    /** 组显示单元列表 */
    CS_NOTIFY_SALVO_UNIT_ITEM_S astNotifySalvoUnitItem[IMOS_DISPLAY_MAXNUM_PER_SALVO];

}CS_NOTIFY_SALVO_INFO_S;

typedef struct tagCSNotifyGroupsalvoInfo
{
    /** 组轮巡句柄 */
    ULONG_32 ulGroupsalvoHandle;

    /** 组轮巡控制块唯一性序号 */
    ULONG_32 ulGroupsalvoCBUniqSeq;

    /** 组轮巡时UI启动组显示的消息系列号 */
    ULONG_32 ulGroupsalvoNotifyUISeq;

    /** 组轮巡资源编码 */
    CHAR szGroupsalvoCode[IMOS_RES_CODE_LEN];

    /** 组轮巡资源名称 */
    CHAR szGroupsalvoName[IMOS_NAME_LEN];

}CS_NOTIFY_GROUPSALVO_INFO_S;

/* Begin Added by dengshuhua00673, 2013-01-06 of 自动布局轮巡 */
typedef struct tagCSNotifyAutoSalvoInfo
{
    /** 自动布局组轮巡句柄 */
    ULONG_32 ulAutoSalvoHandle;

    /** 自动布局组轮巡控制块唯一性序号 */
    ULONG_32 ulAutoSalvoCBUniqSeq;

    /** 自动布局组轮巡资源编码 */
    CHAR szAutoSalvoCode[IMOS_RES_CODE_LEN];

    /** 自动布局组轮巡资源名称 */
    CHAR szAutoSalvoName[IMOS_NAME_LEN];

}CS_NOTIFY_AUTOSALVO_INFO_S;
/* End Added by dengshuhua00673, 2013-01-06 of 自动布局轮巡 */

typedef struct tagCSNotifyGroupsalvoPlanInfo
{
    /** 组轮巡计划编码 */
    CHAR szGroupsalvoPlanCode[IMOS_RES_CODE_LEN];

    /** 组轮巡计划名称 */
    CHAR szGroupsalvoPlanName[IMOS_NAME_LEN];

}CS_NOTIFY_GROUPSALVO_PLAN_INFO_S;

typedef struct tagCSNotifyOperateUserInfo
{
    /* 抢占操作的用户名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /* 抢占操作用户登录编码 */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

    /* 抢占操作用户的登录IP */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

}CS_NOTIFY_OPERATE_USER_INFO_S;

/**
* @struct tagCSNotifySalvoUnitEvent
* @brief 通知UI组显示单元事件
* @attention
*   组显示单元的顶层业务可以是组显示/组轮巡/组轮巡计划, 通过结构中顶层业务类型区分
*/
typedef struct tagCSNotifySalvoUnitEvent
{
    /** 组显示编码 */
    CHAR szSalvoCode[IMOS_RES_CODE_LEN];

    /** 组显示单元信息 */
    CS_NOTIFY_SALVO_UNIT_ITEM_S stNotifySalvoUnitItem;

    /** 操作用户信息 */
    CS_NOTIFY_OPERATE_USER_INFO_S stOperUserInfo;

    /** 顶层业务类型 */
    ULONG_32 ulTopServiceType;

    /** 通知消息类型: SALVO_UNIT_NOTIFY_UI_EVENT_TYPE_E */
    ULONG_32 ulNotifyType;

}CS_NOTIFY_SALVO_UNIT_EVENT_S;

/**
* @struct tagCSNotifyUISalvoEvent
* @brief 通知UI组切业务操作(组显示/组轮巡/组轮巡计划)
* @attention
*   根据顶层业务类型和子业务类型来唯一确定当前业务
*/
typedef struct tagCSNotifyUISalvoEvent
{
    /** 组显示信息, 子业务类型是组显示时有效 */
    CS_NOTIFY_SALVO_INFO_S stSalvoInfo;

    /** 组轮巡信息, 顶层业务类型或子业务类型是组轮巡时有效 */
    CS_NOTIFY_GROUPSALVO_INFO_S stGroupsalvoInfo;

    /* Begin Added by dengshuhua00673, 2013-01-06 of 自动布局轮巡 */
	/** 自动布局轮巡信息, 顶层业务或子业务类型是自动布局轮巡时有效 */
    CS_NOTIFY_AUTOSALVO_INFO_S stAutoSalvoInfo;
    /* End Added by dengshuhua00673, 2013-01-06 of 自动布局轮巡 */

    /** 组轮巡计划信息, 顶层业务类型是组轮巡计划时有效 */
    CS_NOTIFY_GROUPSALVO_PLAN_INFO_S stGroupsalvoPlanInfo;

    /** 操作用户信息 */
    CS_NOTIFY_OPERATE_USER_INFO_S stOperUserInfo;

    /** 布局编码, 子业务类型是组显示时有效 */
    CHAR szLayoutCode[IMOS_CODE_LEN];

    /** 顶层业务类型 */
    ULONG_32 ulTopServiceType;

    /** 子业务类型 */
    ULONG_32 ulSubServiceType;

    /** 通知消息类型: SALVO_NOTIFY_EVENT_TYPE_E */
    ULONG_32 ulNotifyType;

}CS_NOTIFY_UI_SALVO_EVENT_S;

/**
* @struct tagCSNotifyStartXPSalvo
* @brief 通知UI启动屏幕组显示
* @attention
*/
typedef struct tagCSNotifyStartXPSalvo
{
    /** 组轮巡编码 */
    CHAR szGroupsalvoCode[IMOS_RES_CODE_LEN];

    /** 组显示编码 */
    CHAR szSalvoCode[IMOS_RES_CODE_LEN];

    /** 布局编码 */
    CHAR szLayoutCode[IMOS_RES_CODE_LEN];

    /** 通知方句柄 */
    ULONG_32 ulSrcHandle;

    /** 消息序列号 */
    ULONG_32 ulMsgSequence;

    /** 操作原因码: #CS_OPERATE_CODE_E */
    ULONG_32 ulOperateCode;

}CS_NOTIFY_START_XP_SALVO_S;

/* Begin Added by dengshuhua00673, 2013-01-06 of 自动布局轮巡 */
/**
* @struct tagCSNotifyStartXPAutoSalvo
* @brief  通知UI启动屏幕自动布局组轮巡
* @attention
*/
typedef struct tagCSNotifyStartXPAutoSalvo
{
    /** 组轮巡编码 */
    CHAR szAutoSalvoCode[IMOS_RES_CODE_LEN];

    /** 通知方句柄 */
    ULONG_32 ulSrcHandle;

    /** 消息序列号 */
    ULONG_32 ulMsgSequence;

    /** 操作原因码: #CS_OPERATE_CODE_E */
    ULONG_32 ulOperateCode;

}CS_NOTIFY_START_XP_AUTOSALVO_S;
/* End Added by dengshuhua00673, 2013-01-06 of 自动布局轮巡 */

/**
* @struct tagCSTLReaveNotify
* @brief  透明通道业务被抢占信息结构
* @attention 无
*/
typedef struct tagCSTLReaveNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                  /* 抢占操作用户名称 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];           /* 抢占操作用户的登录IP */
    CHAR    szChannelCode[IMOS_RES_CODE_LEN];           /* 透明通道编码 */
    CHAR    szChannelName[IMOS_NAME_LEN];               /* 透明通道名称 */
    ULONG_32   ulNotifyType;                               /* 通知类型 对应枚举:TL_NOTIFY_UI_EVENT_TYPE */
}CS_TL_REAVE_NOTIFY_S;

/*******************************************************************************
                                         第三方设备接入
*******************************************************************************/

/**
 * @struct tagFactoryTypeInfo
 * @brief 厂商信息
 * @attention
 */
typedef struct tagFactoryTypeInfo
{
    /** 厂商类型ID, 取值范围是1到65535 */
    ULONG_32 ulTypeId;

    /** 厂商名称 */
    CHAR  szTypeName[IMOS_NAME_LEN];

    /** 厂商描述 */
    CHAR  szDesc[IMOS_DESC_LEN];

    /** 保留字段，暂时不用 */
    CHAR  szReserved[IMOS_STRING_LEN_64];
}MANUFACTURER_TYPE_INFO_S;

/**
 * @struct tagDevTypeInfo
 * @brief 设备类型信息
 * @attention
 */
typedef struct tagDevTypeInfo
{
    /** 设备类型 */
    ULONG_32 ulDevType;

    /** 设备子类型 */
    ULONG_32 ulDevSubType;

    /** 厂商类型 */
    ULONG_32 ulManuFactureType;

    /** 类型描述 */
    CHAR szTypeDesc[IMOS_DESC_LEN];

}DEV_TYPE_INFO_S;

/**
 * @struct tagEventTypeInfo
 * @brief 事件类型，对应表tbl_eventtype
 * @attention
 */
typedef struct tagEventTypeInfo
{
    /** 事件类型，取值为#AlARM_TYPE_E */
    ULONG_32 ulEventType;

    /** 事件名称 */
    CHAR    szEventName[IMOS_NAME_LEN];

    /** 事件级别 */
    ULONG_32   ulEventSecurity;

    /** 事件分类 */
    ULONG_32   ulEventCategory;

    /** 处理建议 */
    CHAR    szEventSuggestion[IMOS_STRING_LEN_256];

    /** 维护经验 */
    CHAR    szEventExperience[IMOS_STRING_LEN_256];
}EVENT_TYPE_INFO_S;

/**
* @struct tagEventTypeExtInfo
* @brief 事件类型，对应表tbl_eventtype,tbl_event_enable
* @attention
*/
typedef struct tagEventTypeExtInfo
{
    /** 事件显示信息 */
    EVENT_TYPE_INFO_S  stEventTypeInfo;

    /** 系统默认事件名称 */
    CHAR    szPreEventName[IMOS_NAME_LEN];

    /** 系统默认事件级别 */
    ULONG_32   ulPreEventSecurity;

    /** 系统自定义事件名称 */
    CHAR    szSysEventName[IMOS_NAME_LEN];

    /** 系统自定义事件级别 */
    ULONG_32   ulSysEventSecurity;

    /* 是否是系统预定义告警类型 */
    BOOL_T  bSysEventType;

}EVENT_TYPE_EXT_INFO_S;

/**
* @struct tagEventTypeInfo
* @brief 事件类型与设备类型关联关系
* @attention
*/
typedef struct tagEventTypeRel
{
    /** 事件类型 */
    ULONG_32  ulEventType;

    /** 设备类型 */
    DEV_TYPE_INFO_S stDevTypeInfo;
}EVENT_TYPE_REL_S;

/**
* @struct tagEventTypeInfo
* @brief 事件综合信息
* @attention
*/
typedef struct tagEventType
{
    /** 事件类型 */
    EVENT_TYPE_INFO_S  stEventTypeInfo;

    /** 事件关联类型数量 */
    ULONG_32              ulEventTypeRelInfoNum;

    /** 事件关联类型信息 */
    EVENT_TYPE_REL_S   astEventTypeRelInfo[IMOS_EVENT_TYPE_REL_MAX_NUM];

    /** 事件类型是否存在标记位,存在就为1，不存在就为0 */
    BOOL_T  bEventTypeIsExist;
}EVENT_TYPE_S;
/***************************************************************************
 订阅
****************************************************************************/
/**
 * @struct tagConditionItem
 * @brief 订阅条件选项
 * @attention
 */
typedef struct tagSubscConditionItem
{
    /** 订阅过滤条件类型，和订阅类型有关，对应枚举参见订阅类型说明 */
    ULONG_32 ulSubscConType;

    /** 过滤条件逻辑关系类型: LOGIC_FLAG_E，目前只支持等于 */
    ULONG_32 ulLogicFlag;

    /** 过滤内容，如果为数值，则通过标准转换函数转换成字符串 */
    CHAR  szConData[IMOS_STRING_LEN_64];
}SUBSC_CONDITION_ITEM_S;

/**
 * @struct tagSubscCondition
 * @brief 订阅过滤条件
 * @attention
 */
typedef struct tagSubscscCondition
{
    /** 条件个数 */
    ULONG_32 ulItemNum;

    /** 订阅过滤条件列表 */
    SUBSC_CONDITION_ITEM_S astQueryConditionList[IMOS_SUBSC_ITEM_MAX_NUM];

 }SUBSC_CONDITION_S;

/**
* @struct tagSubscBaseInfo
* @brief 订阅告警的基本信息
*/
typedef struct tagSubscBaseInfo
{
    CHAR                szResCode[IMOS_RES_CODE_LEN];       /** 订阅的资源编码 */
    ULONG_32               ulResType;                          /** 资源类型:枚举值为: #IMOS_TYPE_E.目前支持:IMOS_TYPE_CAMERA，IMOS_TYPE_ALARM_SOURCE，IMOS_TYPE_ORG资源类型 */
    ULONG_32               ulSubscType;                        /** 订阅类型，枚举值为:#SUBSC_TYPE_E */
    SUBSC_CONDITION_S   stSubscCon;                         /** 订阅过滤条件，根据订阅类型不同而不同，参见枚举值#SUBSC_TYPE_E中的描述。 */
    ULONG_32               ulSubscExpires;                     /** 订阅时长，以秒为单位，建议最小时长1小时以上，最长为8760个小时 */
}SUBSC_BASE_INFO_S;


/**
* @struct tagSubscFullInfo
* @brief 订阅的全部信息
*/
typedef struct tagSubscFullInfo
{
    SUBSC_BASE_INFO_S   stSubscBaseInfo;            /** 订阅基本信息 */
    CHAR    szSubscResName[IMOS_NAME_LEN];          /** 订阅的资源名称 */
    CHAR    szSessionID[IMOS_SSN_ID_LEN];           /** 订阅业务ID */
    CHAR    szEndTime[IMOS_TIME_LEN];               /** 订阅结束时间 */
}SUBSC_FULL_INFO_S;

/**
* @struct tagTrunkInfo
* @brief 干线信息
*/
typedef struct tagTrunkInfo
{
    /** 干线编码，新增时无效 */
    CHAR    szTrunkCode[IMOS_RES_CODE_LEN];

    /** 干线名称 */
    CHAR    szTrunkName[IMOS_NAME_LEN];

    /** 干线管理类型，取值范围详见:TRUNK_TYPE_E */
    ULONG_32   ulTrunkType;

    /** 干线数量最大值 */
    ULONG_32   ulTrunkMaxNum;

    /** 干线已使用数量，查询时有效 */
    ULONG_32   ulTrunkUsedNum;

    /** 干线带宽最大值(单位K) */
    ULONG_32   ulTrunkMaxBandWidth;

    /** 干线已使用带宽，查询时有效 */
    ULONG_32   ulTrunkUsedBandWidth;

    /** 干线是否启用，查询时有效 */
    BOOL_T  bTrunkEnable;

}TRUNK_INFO_S;

/**
* @struct tagTrunkContentInfo
* @brief 干线内容信息
*/
typedef struct tagTrunkContentInfo
{
    /** 干线内容编码，新增时无效 */
    CHAR    szTrunkContentCode[IMOS_RES_CODE_LEN];

    /** 干线内容类型，取值范围详见:TRUNK_CONTENT_TYPE_E */
    ULONG_32   ulTrunkContentType;

    /** 具体资源编码 */
    CHAR    szPhyResCode[IMOS_RES_CODE_LEN];

    /** 增加具体资源名称，新增时无效 */
    CHAR    szPhyResName[IMOS_NAME_LEN];

    /** 管理范围标志，取值范围详见:TRUNK_CONTENT_RANGE_TYPE_E */
    ULONG_32   ulTrunkRangeType;

}TRUNK_CONTENT_INFO_S;

/**
* @struct tagSysStreamFormat
* @brief 系统封装流格式
* @attention
*/
typedef struct tagSysStreamFormat
{
    /** 流传输方式#IMOS_TRANS_TYPE_E */
    ULONG_32 ulTransType;

    /** 码流类型#IMOS_STREAM_TYPE_E */
    ULONG_32 ulStreamType;
}SYS_STREAM_FORMAT_S;
/**
 * @struct tagDevStatusInfo
 * @brief 设备告警状态信息
 * @attention
 */
typedef struct tagDevStatusInfo
{
    /** 设备编码 */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR szDevName[IMOS_NAME_LEN];

    /** 设备类型 取值参见#IMOS_TYPE_E */
    ULONG_32 ulDevType;

    /** 设备子类型, 对摄像机取值见#CAMERA_TYPE_E; 对监视器无意义;
    对物理设备(EC/DC/MS/DM/VX500)取值见#IMOS_DEVICE_TYPE_E. */
    ULONG_32 ulDevSubType;

    /** 设备状态，4个ULONG字段，每个比特位表示一个设备状态(按位取顺序从低位开始);
    总共暂支持128位设备状态, 各比特位具体对应的设备状态定义见#DEV_STATUS_BIT_E */
    ULONG_32 aulDevStatus[IMOS_DEV_STATUS_MAX_NUM];

}DEV_STATUS_INFO_S;


/*******************************************************************************
BM
********************************************************************************/

/**
* @struct tagBMInfo
* @brief BM信息结构体
* @attention 修改BM信息时，只允许修改BM名称，满处理策略，备份时间窗口，BM描述，是否案件管理服务器
*/
typedef struct tagBMInfo
{
    /** BM编码, BM的唯一标识 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 -- 可修改 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** BM类型，值为0，表示BM8500 */
    ULONG_32 ulBMType;

    /** BM所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 满处理策略，0-满停止、1-满覆盖 -- 可修改 */
    ULONG_32 ulFullPolicy;

    /** 备份开始时间 -- 可修改 */
    CHAR  szBkStartTime[IMOS_SIMPLE_TIME_LEN];

    /** 备份结束时间 -- 可修改 */
    CHAR  szBkEndTime[IMOS_SIMPLE_TIME_LEN];

    /** BM描述, 可不填 -- 可修改 */
    CHAR  szDevDesc[IMOS_DESC_LEN];

    /** 流转存媒体服务策略，见IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulStreamStorSvrPolicy;

    /** 是否案件管理服务器标识， 0-不是、1-是 -- 可修改 */
    ULONG_32 ulIsCaseServer;

    /** 保留字段 */
    CHAR  szReserve[32];
}BM_INFO_S;

/**
* @struct tagBMQueryItem
* @brief BM的信息项(查询BM列表时返回)
* @attention 无
*/
typedef struct tagBMQueryItem
{
    /** BM编码, BM的唯一标识 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** BM类型, 此字段无效, 缺省值为0 */
    ULONG_32 ulBMType;

    /** BM所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** BM所属组织名称 */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** 设备地址类型，1-IPv4、2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** 设备地址 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，枚举值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** 满处理策略，0-满停止、1-满覆盖 */
    ULONG_32 ulFullPolicy;

    /** 备份开始时间 */
    CHAR  szBkStartTime[IMOS_SIMPLE_TIME_LEN];

    /** 备份结束时间 */
    CHAR  szBkEndTime[IMOS_SIMPLE_TIME_LEN];

    /* 流转存媒体服务策略，0 自适应  1 直连优先 */
    ULONG_32  ulStreamStorSvrPolicy;

    /** 是否案件管理服务器标识， 0-不是、1-是 */
    ULONG_32 ulIsCaseServer;

    /** 保留字段 */
    CHAR  szReserve[32];
}BM_QUERY_ITEM_S;

/**
* @struct tagDMResForBMInfo
* @brief 为BM分配的DM资源的信息结构体
* @attention
*/
typedef struct tagDMResForBMInfo
{
    /** BM编码, BM的唯一标识 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** 资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 容量大小，以MB为单位 */
    ULONG_32 ulCapacity;

    /** DM编码, DM的唯一标识 */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备编码 */
    CHAR  szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** 资源业务类型，枚举值为#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;

    /** 保留字段 */
    CHAR  szReserve[32];
}DM_RES_FOR_BM_INFO_S;

/**
* @struct tagThirdResForBMInfo
* @brief 为BM分配的第三方资源的信息结构体
* @attention
*/
typedef struct tagThirdResForBMInfo
{
    /** BM编码, BM的唯一标识 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** 资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 第三方资源全路径 */
    CHAR  szLocalPath[IMOS_FILE_PATH_LEN];

    /** 资源业务类型，枚举值为#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;

    /** 保留字段 */
    CHAR  szReserve[32];
} THIRD_RES_FOR_BM_INFO_S;



/**
* @struct tagThirdResForBMInfo
* @brief 为BM分配的第三方资源的信息结构体V2
* @attention
*/
typedef struct tagThirdResForBMInfoV2
{

	THIRD_RES_FOR_BM_INFO_S stBMResInfo;

	ULONG_32  ulLunId;                        /* LUN ID */
	
	CHAR    szBmTarget[IMOS_STRING_LEN_64];    /* Target名 */
	
	CHAR    szInitiator[IMOS_STRING_LEN_64];   /* Initiator名 */
	
	CHAR    szDevAddress[IMOS_IPADDR_LEN];     /* IPSAN设备地址 */

    CHAR  szReserve[256];      /** 保留字段 */
} THIRD_RES_FOR_BM_INFO_S_V2;


/**
* @struct tagBMResQueryItem
* @brief BM备份资源的信息项(查询BM备份资源列表时返回)
* @attention 无
*/
typedef struct tagBMResQueryItem
{
    /** 备份资源编码 */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** BM编码, BM的唯一标识 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 备份资源类型#BAK_RES_TYPE_E */
    ULONG_32 ulResType;

    /** 存储设备名称 */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** 备份资源状态#BAK_RES_STATUS_E */
    ULONG_32 ulResStatus;

    /** 总容量大小，以MB为单位 */
    ULONG_32 ulTotalCapacity;

    /** 剩余容量大小，以MB为单位 */
    ULONG_32 ulSpareCapacity;

    /** 备份资源全路径-第三方资源才有效 */
    CHAR  szResPath[IMOS_FILE_PATH_LEN];

    /** 资源业务类型，枚举值为#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;
} BM_RES_QUERY_ITEM_S;

/**
* @struct tagCamBakResInfo
* @brief 为摄像机分配BM资源的信息结构体(查询摄像机备份资源时返回的信息项)
* @attention
*/
typedef struct tagCamBakResInfo
{
    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM编码 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 备份告警前一段录像的时间, 取值范围[0~15分钟] -- 可修改 */
    ULONG_32 ulAlarmPreRecLen;

    /** 备份告警后一段录像的时间, 取值范围[1~30分钟] -- 可修改 */
    ULONG_32 ulAlarmPostRecLen;

    /** 独享模式标志位#BAK_MODE_E */
    ULONG_32 ulCamOwnFlag;

    /** 独享容量大小，以MB为单位(共享此字段无效) -- 可修改 */
    ULONG_32 ulCapacity;

    /** 独享剩余容量大小，以MB为单位(共享此字段无效)-查询时候有效 */
    ULONG_32 ulSpareCapacity;

    /** 满处理策略(共享此字段无效)，0-满停止、1-满覆盖 -- 可修改 */
    ULONG_32 ulFullPolicy;

    /** 备份资源编码(共享此字段无效) */
    CHAR szBakResCode[IMOS_CODE_LEN];

    /** 备份资源名称(共享此字段无效) */
    CHAR szBakResName[IMOS_NAME_LEN];

    /*转存模式：0 不支持（默认值）  1 流转存*/
    ULONG_32    ulBkMode;

    /** 保留字段 */
    CHAR  szReserve[32];
}CAM_BAK_RES_INFO_S;

/**
* @struct tagCamBakResQueryItem
* @brief 摄像机备份资源分配情况的信息项(查询摄像机备份资源分配情况列表时返回)
* @attention 无
*/
typedef struct tagCamBakResQueryItem
{
    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM编码 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 独享模式标志位#BAK_MODE_E */
    ULONG_32 ulCamOwnFlag;

    /** 是否已经制定了备份计划,#BOOL_TRUE表示制定，BOOL_FALSE表示未指定 */
    BOOL_T bPlanFlag;

    /** 备份计划编码 */
    CHAR szPlanCode[IMOS_RES_CODE_LEN];

    /** 备份计划状态 */
    ULONG_32 ulPlanStatus;

    /*转存模式：0 不支持（默认值）  1 流转存*/
    ULONG_32    ulBkMode;

    /** 保留字段 */
    CHAR  szReserve[32];
} CAM_BAK_RES_QUERY_ITEM_S;

/**
* @struct tagBakTaskInfo
* @brief 备份任务的信息结构体
* @attention 无
*/
typedef struct tagManulBakInfo
{
    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 备份策略#BAK_POLICY_E */
    ULONG_32 ulBakPolicy;

    /** 备份时间:开始、结束 */
    TIME_SLICE_S stBakTime;

    /** 备份路径(配置DVR的时候使用) */
    CHAR szBakPath[IMOS_FILE_PATH_LEN];

    /** 案例描述 */
    CHAR szCaseDesc[IMOS_BAK_CASE_LEN];

    /** 保留字段 */
    CHAR  szReserve[32];
} MANUL_BAK_INFO_S;

/**
* @struct tagBakTaskQueryItem
* @brief 备份任务的信息项(查询备份任务时返回)
* @attention 无
*/
typedef struct tagBakTaskQueryItem
{
    /** 备份任务编码 */
    CHAR  szBakTaskCode[IMOS_CODE_LEN];

    /** 备份任务类型#BAK_TYPE_E */
    ULONG_32 ulBakType;

    /** 备份任务状态#BAK_TASK_STATUS_E */
    ULONG_32 ulBakTaskStatus;

    /** 备份策略#BAK_POLICY_E */
    ULONG_32 ulBakPolicy;

    /** 任务最后一次挂起时间 */
    CHAR  szLastHangupTime[IMOS_TIME_LEN];

    /** 任务时间:提交、结束 */
    TIME_SLICE_S stTaskTime;

    /** BM编码 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 录像时间:开始、结束 */
    TIME_SLICE_S stRecTime;

    /** 备份时间:开始、结束，暂不使用 */
    TIME_SLICE_S stBakTime;

    /** 备份目的路径，手动任务才有效 */
    CHAR szBakPath[IMOS_FILE_PATH_LEN];

    /** 用户编码 */
    CHAR  szUserCode[IMOS_USER_CODE_LEN];

    /** 用户名称 */
    CHAR  szUserName[IMOS_NAME_LEN];

    /** 案例描述-手动备份任务才有效 */
    CHAR szCaseDesc[IMOS_BAK_CASE_LEN];

    /** 任务业务类型#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32 ulTaskServiceType;
} BAK_TASK_QUERY_ITEM_S;

/**
* @struct tagBakFileHandleInfo
* @brief 备份文件的操作信息结构体
* @attention 无
*/
typedef struct tagBakFileHandleInfo
{
    /** 备份文件存储路径 */
    CHAR szBakFilePath[IMOS_FILE_PATH_LEN];

    /** BM编码 */
    CHAR szBMCode[IMOS_DEVICE_CODE_LEN];

    /** 备份文件操作类型#BAK_FILE_OPER_E */
    ULONG_32 ulHandleType;
} BAK_FILE_HANDLE_INFO_S;
/* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
/**
* @struct tagLockedRecordInfo
* @brief 录像锁定信息
* @attention 无
*/
typedef struct tagLockedRecordInfo
{
    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 录像起始时间*/
    CHAR  szStartTime[IMOS_TIME_LEN];

    /** 录像结束时间*/
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 锁定描述信息 */
    CHAR  szDesc[IMOS_STRING_LEN_128];
}LOCK_RECORD_INFO_S;

/**
* @struct tagLockedRecordInfo
* @brief 录像解锁信息
* @attention 无
*/
typedef struct tagUnlockedRecordInfo
{
    /** 录像解锁类型*/
    IN  ULONG_32   ulUnlockType;

    /** 摄像机编码或者解锁录像段ID */
    IN  CHAR    szUnlockKeyStr[IMOS_STRING_LEN_256];

}UNLOCK_RECORD_INFO_S;

/**
* @struct tagLockedRecordQueryItem
* @brief 锁定摄像机信息
* @attention 无
*/
typedef struct tagLockedCameraQueryItem
{
    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** 摄像机所属组织名称 */
    CHAR    szOrgName[IMOS_NAME_LEN];

    /** 录像留存期（天） */
    ULONG_32   ulRecStorageDay;

    /** 已锁录像段数 */
    ULONG_32   ulLockRecCnt;

    /** 状态为"待锁定"或者"待解锁"的录像段总数 */
    ULONG_32   ulUnhandledRecCnt;

}LOCKED_CAMERA_QUERY_ITEM_S;

/**
* @struct tagLockedRecordQueryItem
* @brief 锁定录像段信息
* @attention 无
*/
typedef struct tagLockedRecordQueryItem
{
    /** 锁定录像段编码 */
    CHAR  szRecLockCode[IMOS_CODE_LEN];

    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 录像起始时间*/
    CHAR  szStartTime[IMOS_TIME_LEN];

    /** 录像结束时间*/
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** 状态 */
    ULONG_32  ulStatus;

    /** 错误码，只对状态为"待锁定"、"待解锁"的录像段有效 */
    ULONG_32  ulErrCode;

    /** 备注信息 */
    CHAR  szDesc[IMOS_STRING_LEN_128];
}LOCKED_RECORD_QUERY_ITEM_S;

/**
* @struct tagASSMLockSpaceNotify
* @brief SOI 录像锁定空间信息 结构
* @attention 无
*/
typedef struct tagASSMLockSpaceNotify
{
    /** 用户编码 */
    CHAR    szUserCode[IMOS_CODE_LEN];

    /** 用户登录ID，是用户登录后服务器分配的，它是标记一次用户登录的唯一标识 */
    CHAR szUserLoginID[IMOS_USER_CODE_LEN];

    /** 用户登录名 */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** 用户登录IP地址*/
    CHAR szSrcIpAddress[IMOS_IPADDR_LEN];
}AS_SM_LOCK_SPACE_NOTIFY_S;

/**
* @struct tagASSMLockFailureNotify
* @brief SOI 录像上线锁定结果信息 结构
* @attention 无
*/
typedef struct tagASSMLockFailureNotify
{
    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** 锁定解锁动作类型，见AS_SM_STORE_ACTION_E */
    ULONG_32   ulActionType;
}AS_SM_LOCK_FAILURE_NOTIFY_S;
/* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */


/**
* @struct tagBakFileQueryItem
* @brief 备份文件的信息项(查询摄像机备份文件时返回)
* @attention 无
*/
typedef struct tagBakFileQueryItem
{
    /** 备份文件编码 */
    CHAR  szBakFileCode[IMOS_RES_CODE_LEN];

    /** BM编码 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32 ulCameraType;

    /** 备份文件存储路径 */
    CHAR szBakFilePath[IMOS_FILE_PATH_LEN];

    /** 文件生成时间 */
    CHAR  szFileCreateTime[IMOS_TIME_LEN];

    /** 备份时间:开始、结束 */
    TIME_SLICE_S stBakTime;

    /** 文件容量，以MB为单位 */
    ULONG_32 ulFileCapacity;

    /** 备份资源编码 */
    CHAR  szBakResCode[IMOS_CODE_LEN];

    /** 文件类型#BAK_TYPE_E */
    ULONG_32 ulFileType;

    /** 文件保存格式，0-TS、1-h3crd */
    ULONG_32 ulFileFormat;

    /** 备份文件状态标识，0-过程文件、1-最终文件 */
    ULONG_32 ulFileStatus;

    /** 是否锁定标识，0-未锁定、1-锁定 */
    ULONG_32 ulLockFlag;

    /** 案例描述 */
    CHAR szCaseDesc[IMOS_BAK_CASE_LEN];
} CAM_BAK_FILE_QUERY_ITEM_S;


/**
 * @struct tagBackupBase
 * @brief 备份计划基本信息
 * @attention
 */
typedef struct tagBackupBase
{
    /** 备份计划编码，服务器分配 */
    CHAR    szBakPlanCode[IMOS_RES_CODE_LEN];

    /** 备份计划名称 */
    CHAR    szBakPlanName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称，查询计划信息时返回 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 用户编码 */
    CHAR    szUserCode[IMOS_USER_CODE_LEN];

    /** 计划创建时间 */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** 备份几天前的数据 */
    ULONG_32   ulBeforeDays;

    /** 计划周期，0-日计划、1-周计划 */
    ULONG_32   ulPlanCycle;

    /** 备份开始时间，此字段保留，暂不使用 */
    CHAR    szBakStartTime[IMOS_TIME_LEN];

    /** 备份结束时间，此字段保留，暂不使用 */
    CHAR    szBakEndTime[IMOS_TIME_LEN];

    /** 备份策略#BAK_POLICY_E */
    ULONG_32   ulBakPolicy;

    /** 计划状态#PLAN_OPER_MODE_E，修改计划时此字段无效 */
    ULONG_32   ulPlanStatus;
}BAK_PLAN_BASE_S;

/**
 * @struct tagBackupPlan
 * @brief 备份计划信息
 * @attention
 */
typedef struct tagBackupPlan
{
    /** 备份计划基本信息 */
    BAK_PLAN_BASE_S   stBakPlanBasicInfo;

    /** 备份计划时间信息，周时间计划 */
    PLAN_WEEKTIME_S   astPlanTime[IMOS_WEEK_DAYS];
}BAK_PLAN_INFO_S;

/**
* @struct tagGetBakUrlInfo
* @brief 获取备份录像文件URL的请求结构
*/
typedef struct tagGetBakUrlInfo
{
    /** 摄像机编码 */
    CHAR            szCamCode[IMOS_DEVICE_CODE_LEN];

    /** 录像文件名 */
    CHAR            szFileName[IMOS_FILE_PATH_LEN];

    /** 录像的起始/结束时间, 其中的时间格式为"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stRecTimeSlice;

    /** 客户端IP地址 */
    CHAR            szClientIp[IMOS_IPADDR_LEN];

    /** 备份业务类型，取值#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32           ulBakSrvType;

    /** 案件录像编码，备份业务类型为案件备份时有效 */
    CHAR            szCaseRecCode[IMOS_CODE_LEN];
}GET_BAK_URL_INFO_S;

/************************************************************************/
/* 流转存                                                             */
/************************************************************************/
/**
* @struct tagCamStreamStorInfo
* @brief 摄像机流转存配置信息结构体
* @attention */
typedef struct tagCamStreamStorInfo
{
    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM编码 */
    CHAR  szBMCode[IMOS_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 备份资源编码*/
    CHAR szBakResCode[IMOS_CODE_LEN];

    /** 备份资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 占用容量大小，以MB为单位 */
    ULONG_32 ulCapacity;

    /** 满处理策略(共享此字段无效)，0-满停止、1-满覆盖 */
    ULONG_32 ulFullPolicy;

    /* 码流类型：1 主码流  2 辅码流 */
    ULONG_32   ulStreamType;

    /** 保留字段 */
    CHAR  szReserve[32];
}CAM_STREAM_STOR_INFO_S;

/**
* @struct tagCamStreamStorQueryItem
* @brief 摄像机流转存配置情况的信息项
* @attention 无
*/
typedef struct tagCamStreamStorQueryItem
{
    /** 摄像机编码 */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM编码 */
    CHAR  szBMCode[IMOS_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 备份资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 占用容量 以MB为单位 */
    ULONG_32 ulCapacity;

    /** 是否已经制定了转存计划,#BOOL_TRUE表示制定，BOOL_FALSE表示未指定 */
    BOOL_T bPlanFlag;

    /** 转存计划编码 */
    CHAR szPlanCode[IMOS_CODE_LEN];

    /** 转存计划状态 */
    ULONG_32 ulPlanStatus;

    /** 资源属性信息，0代表本域摄像机，2代码DVR推送上来的摄像机 */
    ULONG_32 ulResAttribute;

	/** 资源是否属于外域 */
    ULONG_32   ulIsForeign;

    /** 保留字段 */
    CHAR  szReserve[28];
} CAM_STREAM_STOR_QUERY_ITEM_S;

 /**
 * @struct tagStreamStorBase
 * @brief 流转存计划基本信息
 * @attention
 */
typedef struct tagStreamStorBase
{
    /** 流转存计划编码，服务器分配 */
    CHAR    szStreamStorPlanCode[IMOS_CODE_LEN];

    /** 流转存计划名称 */
    CHAR    szStreamStorPlanName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /** 摄像机名称，查询计划信息时返回 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 用户编码 */
    CHAR    szUserCode[IMOS_CODE_LEN];

    /** 计划创建时间 */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** 计划周期，0-日计划、1-周计划 */
    ULONG_32   ulPlanCycle;

    /** 是否按天存储(1 是,0 否) */
    BOOL_T  bIsDayStore;

    /** 按天存储的天数 */
    ULONG_32   ulStoreDays;

    /** 计划状态#PLAN_OPER_MODE_E，修改计划时此字段无效 */
    ULONG_32   ulPlanStatus;
}STREAM_STOR_PLAN_BASE_S;

/**
 * @struct tagStreamStorPlan
 * @brief 流转存计划信息
 * @attention
 */
typedef struct tagStreamStorPlan
{
    /** 流转存计划基本信息 */
    STREAM_STOR_PLAN_BASE_S   stStreamStorPlanBasicInfo;

    /** 流转存计划时间信息，周时间计划 */
    PLAN_WEEKTIME_S   astPlanTime[IMOS_WEEK_DAYS];
}STREAM_STOR_PLAN_INFO_S;

/************************************************************************/
/* 告警订阅                                                             */
/************************************************************************/
/**
* @struct tagAlarmSendingRuleBaseInfo
* @brief 告警订阅规则基本信息
* @attention
*/
typedef struct tagAlarmSendingRuleBaseInfo
{
    /** 编码 */
    CHAR                   szRuleCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR                   szRuleName[IMOS_NAME_LEN];

    /** 是否系统预定义规则：BOOL_TRUE表示系统预定义规则，BOOL_FALSE非系统预定义规则 */
    BOOL_T                 bSystemRule;

    /** 告警分类：目前暂未使用，填0 */
    ULONG_32                  ulEventCategory;

    /** 告警级别：第0位表示紧急，第1位表示重要，第2位表示次要，第3位表示警告，第4位表示提示 */
    ULONG_32                  ulEventLevel;

    /** 告警推送方式：第0位表示UI，第1位表示Email，第2位表示SMS, 第3位表示第三方系统订阅 */
    ULONG_32                  ulSendEventMode;
}ALARM_SENDING_RULE_BASE_INFO_S;

/**
* @struct tagAlarmSendingRuleThdSys
* @brief 告警订阅规则第三方系统订阅信息
* @attention
*/
typedef struct tagAlarmSendingRuleThdSys
{
    /** 第三方系统编码 */
    CHAR                    szThdSysCode[IMOS_CODE_LEN];

    /** 第三方系统名称 */
    CHAR                    szThdSysName[IMOS_NAME_LEN];

    /** 第三方系统地址 */
    CHAR                    szAddr[IMOS_IPADDR_LEN];

    /** 第三方系统端口 */
    USHORT                  usPort;

    /** 保留字段 */
    USHORT                  usReserved;

    /** 协议类型, 具体见#ALARM_SEND_TO_THD_SYS_PROC_TYPE_E */
    ULONG_32                   ulProcType;
}ALARM_SENDING_RULE_THD_SYS_S;

/**
* @struct tagAlarmSendingRule
* @brief 告警订阅规则
* @attention
*/
typedef struct tagAlarmSendingRule
{
    /** 告警订阅规则基本信息 */
    ALARM_SENDING_RULE_BASE_INFO_S stBaseInfo;

    /** 告警源数目 */
    ULONG_32                           ulAlarmSrcNum;

    /** 告警源编码列表, 以#IMOS_CODE_LEN为单位 */
    CHAR                            *pcAlarmSrcList;

    /** 订阅该规则的 用户数 */
    ULONG_32                           ulUserNum;

    /** 用户列表, 以#IMOS_CODE_LEN为单位 */
    CHAR                            *pcUserList;

    /** 订阅该规则的 第三方系统数 */
    ULONG_32                           ulThdSysNum;

    /** 第三方系统列表 */
    ALARM_SENDING_RULE_THD_SYS_S    *pstThdList;
}ALARM_SENDING_RULE_S;

/**
* @struct tagSDKInit
* @brief SDK 初始化时用的结构
*/
typedef struct tagSDKInit
{
    /** 进程名称 */
    CHAR szProcName[IMOS_PROC_NAME_MAX_LEN];

    /** 进程procID（IMOS系统内统一分配，相同类型进程使用相同的procID） */
    USHORT usProcID;

    /** 是否UI侧的标记 */
    BOOL_T bUIFlag;

    /** 是否包含XP标记 */
    BOOL_T bXPFlag;

    ULONG_32  ulSDKInitFlag;

    /** 回调函数指针 */
    SDK_CALL_BACK_PROC_PF pfnCallBackProc;

    /** 回调函数参数，用于回调函数出入参赋值 */
    VOID *pParam;

}SDK_INIT_S;

/**
* @struct tagPortRange
* @brief 端口范围
* @attention
*/
typedef struct tagPortRange
{
    /** 端口起始范围 */
    ULONG_32  ulPortBegin;

    /** 端口结束范围 */
    ULONG_32  ulPortEnd;

    /** 为类型预留 */
    ULONG_32 ulType;
}PORT_RANGE_S;

/**
* @struct tagUniversalPage
* @brief 通用分页信息
* @attention
*/
typedef struct tagUniversalPage
{
    ULONG_32 ulFirstRow;               /**< 本页从第几行开始查询 */
    ULONG_32 ulPageRowNum;             /**< 本页要查询的行数 */
    BOOL_T bQueryCount;             /**< 是否查询总行数 */
    ULONG_32 ulActualRowCount;         /**< 实际返回的行数 */
    ULONG_32 ulTotalRowCount;          /**< 符合条件的行数总计 */
}UNI_PAGE_S;
/**
* @struct tagUniversalLogicPiece
* @brief 通用约束逻辑项
* @attention
*/
typedef struct tagUniversalLogicPiece
{
    ULONG_32 ulPiece;                  /**< 条件项 */
    LOGIC_FLAG_E enLogic;           /**< 条件逻辑#LOGIC_FLAG_E */
    CHAR szValues[64];              /**< 条件值 */
}UNI_LOGIC_PIECE_S;

/**
* @struct tagUniversalOrder
* @brief 通用排序项
* @attention
*/
typedef struct tagUniversalOrder
{
    ULONG_32 ulPiece;
    LOGIC_FLAG_E enLogic;           /**< 升序还是降序#LOGIC_FLAG_E */
}UNI_ORDER_S;
/**
* @struct tagUniversalConditon
* @brief 通用约束条件
* @attention
*/
typedef struct tagUniversalConditon
{
    ULONG_32 ulFlag;                                   /**< 查询逻辑标志位#UNI_CONDITION_FLAG_E */
    ULONG_32 ulOrderNum;                               /**< 排序条件的个数 */
    UNI_ORDER_S *pstOrderPiece;                     /**< 排序项 */
    ULONG_32 ulANDCondNum;                             /**< AND约束条件的个数 */
    UNI_LOGIC_PIECE_S *pstANDCondtion;              /**< AND约束条件列表 */
    ULONG_32 ulORCondNum;                              /**< OR约束条件的个数 */
    UNI_LOGIC_PIECE_S *pstORCondtion;               /**< OR约束条件列表 */
}UNI_CONDITION_S;

/**
 * @struct tagOutChannelInfo
 * @brief 输出通道信息
 * @attention
 */
typedef struct tagOutChannelInfo
{
    /** 输出通道类型,取值为#OUT_CHANNEL_TYPE_E */
    ULONG_32 ulOutType;

    /** 输出通道模式,取值为#OUT_CHANNEL_MODE_E */
    ULONG_32 ulOutMode;
} OUT_CHANNEL_INFO_S;

/**
 * @struct tagOutChannelSplitScrInfo
 * @brief 输出通道分屏信息
 * @attention
 */
typedef struct tagOutChannelSplitScrInfo
{
    /** 分屏模式,取值为#OUT_CHANNEL_MODE_E */
    ULONG_32 ulSplitScrMode;

    /** 视频输出通道号(分屏模式为"全屏"时有效) */
    ULONG_32 ulVideoOutChannelNo;

    /** 保留字段 */
    CHAR szReserve[128];
} OUT_CHANNEL_SPLIT_SCR_INFO_S;

/**
 * @struct tagSplitScrInfo
 * @brief 监视器分屏信息
 * @attention
 */
typedef struct tagSplitScrInfo
{
    /** 分屏模式,取值为#SPLIT_SCR_MODE_E */
    ULONG_32 ulSplitScrMode;

    /** 分屏编码(全屏时有效) */
    CHAR szSplitScrCode[IMOS_CODE_LEN];

    /** 是否"自动切换主辅流"(#BOOL_TRUE 是,#BOOL_FALSE 否) */
    BOOL_T bSwitchStream;

    /** 预留字段 */
    CHAR szReserve[128];
} SPLIT_SCR_INFO_S;

/*******************************************************************************
ECR33**-HF
********************************************************************************/

/**
 * @struct tagECRBasicInfo
 * @brief ECR,NVR基本信息
 * @attention
 */
typedef struct tagECRBasicInfo
{
    /** ECR,NVR设备编码 */
    CHAR    szECRCode[IMOS_ECR_CODE_LEN];

    /** ECR,NVR名称 */
    CHAR    szECRName[IMOS_NAME_LEN];

    /** 组织域编码 */
    CHAR    szOrgCode[IMOS_CODE_LEN];

    /** ECR设备型号, 取值为#IMOS_DEVICE_TYPE_E中的#IMOS_DT_ECR3308_HF, #IMOS_DT_ECR3316_HF #IMOS_DT_ECR3308_HF_E,
        #IMOS_DT_ECR3316_HF_E #IMOS_DT_ECR3308_HF_S, #IMOS_DT_ECR3316_HF_S, #IMOS_DT_ECR_MIN至#IMOS_DT_ECR_MAX,
        #IMOS_DT_ISC_MIN至#IMOS_DT_ISC_MAX.
        当添加设备传入类型为#IMOS_DT_ISC_MIN时，所添加设备为NVR */
    ULONG_32   ulECRDevType;

    /** IP地址类型:IPV4取值为#IMOS_IPADDR_TYPE_IPV4, IPV6取值为#IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32   ulIPAddrType;

    /** IP地址 */
    CHAR    szIPAddress[IMOS_IPADDR_LEN];

    /** ECR在线状态, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE. 用于查询ECR信息 */
    ULONG_32   ulOnlineStatus;

    /** 引流标记位，取值为#DOMAIN_STREAM_PULL_TYPE  */
    ULONG_32 ulIsSession;

    /* Begin: Added by mozhanfei(kf0149) ,2013-7-18 for ECR NVR大类 */
    /** 设备类型 */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2012-7-18 for ECR NVR大类 */


    /** 保留字段 */
    CHAR szReserve[252];

}ECR_BASIC_INFO_S;

/**
 * @struct tagECRCameraInfo
 * @brief ECR Camera列表查询返回信息
 * @attention
 */
typedef struct tagECRCamInfo
{
    /** Camera编码*/
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** Camera名称 */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** 保留字段 */
    CHAR szReserve[128];
}ECR_CAM_INFO_S;

/**
* @struct tagECRAlarmSrcInfo
* @brief ECR告警源列表查询返回的单元信息
*/
typedef struct tagECRAlarmSrcInfo
{
    /** 告警源编码*/
    CHAR  szAlarmSrcCode[IMOS_CODE_LEN];

    /** 告警源名称 */
    CHAR  szAlarmSrcName[IMOS_NAME_LEN];

    /** 保留字段 */
    CHAR szReserve[128];

}ECR_ALARMSRC_INFO_S;

/**
 * @struct tagECRDeviceBasicInfo
 * @brief ECR本机设备基本信息
 * @attention
 */
typedef struct tagECRDeviceBasicInfo
{
    /** 是否支持组播, 1为支持; 0为不支持 */
    ULONG_32 ulIsMulticast;

    /** 告警使能, 1为使能; 0为不使能 */
    ULONG_32 ulEnableAlarm;

    /** 高温告警温度下限, 取值为65~100 */
    LONG_32 lTemperatureMax;

    /** 低温告警温度上限, 取值为-100~49 */
    LONG_32 lTemperatureMin;

    /** 流套餐, 取值为:#IMOS_STREAM_RELATION_SET_E,
        目前ECR支持的有:
        1：H264主码流(#IMOS_SR_H264_SHARE)
        11：H264+H264(#IMOS_SR_H264_H264)
    */
    ULONG_32 ulEncodeSet;

    /** 制式, 取值为#IMOS_PICTURE_FORMAT_E, 目前仅支持#IMOS_PF_PAL */
    ULONG_32 ulStandard;

    /** 音频输入源，取值为#IMOS_AUDIO_INPUT_SOURCE_E, 目前仅支持#IMOS_AI_LR */
    ULONG_32 ulAudioinSource;

    /** 流媒体的协议类型,取值为#IMOS_TRANS_TYPE_E。目前EC只支持UDP和TCP */
    ULONG_32 ulStreamTransProtocol;

    /* Begin Added by chenyongfa for IVSD01065 2013.05.28 */
    /** 视频编码标准，取值为#IMOS_ENCODE_STANDARD_E。 */
    ULONG_32 ulEncodeStandard;
    /* End Added by chenyongfa for IVSD01065 2013.05.28 */

    /** 保留字段 */
    CHAR szReserve[504];
}ECR_DEVICE_BASIC_INFO_S;

/**
 * @struct tagECRVMServerInfo
 * @brief ECR设备的服务器信息
 * @attention
 */
typedef struct tagECRVMServerInfo
{
    /** 服务器地址类型, 1-IPv4 2-IPv6 */
    ULONG_32   ulServerAddrType;

    /** 服务器地址 */
    CHAR    szServerAddr[IMOS_IPADDR_LEN];

    /** 服务器在线状态, 指本摄像向当前这个服务器注册是否成功, 1为成功; 0或者2为失败, 配置时无效, 仅用户查询 */
    ULONG_32   ulServerRegStatus;

    /** 服务器互联通信协议, 取值为#INTERDOMAIN_PROTOCOL_TYPE_E, 目前只支持IMOS标准 */
    ULONG_32   ulInterProtocolType;

    /** 服务器跨域互联域编码, 需要和服务器配置的互联域编码一致, 目前只支持IMOS标准的域编码 */
    CHAR    szInterDomainCode[IMOS_CODE_LEN];

    /** 跨域互联用户编码, 需要和服务器配置的互联用户编码一致 */
    CHAR    szInterUserCode[IMOS_CODE_LEN];

    /* Begin added by zhuhongyan 00342 2013-3-18 for IVSD01426国标完善性特性 */
    /** 鉴权域名 */
    CHAR    szDigestRealm[IMOS_DOMAIN_NAME_LEN];

    /** 鉴权用户名 */
    CHAR    szDigestUser[IMOS_NAME_LEN];

    /** 鉴权密码 */
    CHAR    szDigestPassword[IMOS_PASSWD_LEN];

    /** 服务器端口 */
    ULONG_32   ulServerPort;
    /* End added by zhuhongyan 00342 2013-3-18 for IVSD01426国标完善性特性 */

    /** 保留字段 */
    CHAR    szReserve[364];
}ECR_VMSERVER_INFO_S;

/**
 * @struct tagECRServerMgrInfo
 * @brief ECR设备服务器管理信息
 * @attention
 */
typedef struct tagECRServerMgrInfo
{
    /** ECR设备编码, 互联唯一标识 */
    CHAR  szECRDevCode[IMOS_ECR_CODE_LEN];

    /** NVR互联用户编码, 互联唯一标识；ECR无效，为0即可 */
    CHAR  szECRInterUserCode[IMOS_CODE_LEN];

    /** ECR设备名称, 用于表示ECR本机设备, 以区别IPC等 */
    CHAR  szECRDevName[IMOS_NAME_LEN];

    /** 服务器管理模式类型, 取值为#ECR_SERVER_MODE_TYPE_E */
    ULONG_32 ulServerModeType;

    /** 服务器信息, 当为独立运行模式时无需填写 */
    ECR_VMSERVER_INFO_S stVMserverInfo;

    /** 保留字段 */
    CHAR szReserve[64];
}ECR_SERVER_MGR_INFO_S;

/**
 * @struct tagRevStrategyInfo
 * @brief 抢占策略信息结构
 * @attention
 */
typedef struct tagRevStrategyInfo
{
    /** 抢占业务类型, 取值为# REAVE_SRV_TYPE_E  */
    ULONG_32 ulRevSrvType;

    /** 抢占策略类型, 取值为# REAVE_STRATEGY_E */
    ULONG_32 ulRevStrategy;
}REV_STRATEGY_INFO_S;

/**
 * @struct tagSrvRevStrategy
 * @brief 业务抢占策略结构
 * @attention
 */
typedef struct tagSrvRevStrategy
{
    /** 抢占策略数，最大值不能超过REV_SRV_MAX */
    ULONG_32 ulRevStrategyNum;

    /** 抢占策略信息*/
    REV_STRATEGY_INFO_S astRevStrategyInfo[REV_SRV_MAX];
}SRV_REV_STRATEGY_S;

/**
* @struct tagCSVodReaveNotify
* @brief SOI 回放被抢占信息 结构
* @attention 无
*/
typedef struct tagCSVodReaveNotify
{
    CHAR    szSessionId[IMOS_SSN_ID_LEN];        /* 回放业务会话ID，与干线申请时返回的SessionId匹对 */
    CHAR    szUserName[IMOS_NAME_LEN];           /* 抢占操作的用户名 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];    /* 抢占操作用户的登录IP */
}CS_VOD_REAVE_NOTIFY_S;
/**
 * @struct tagSceneUnit
 * @brief 场景单元信息
 * @attention
 */
typedef struct tagSceneUnit
{
    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 摄像机类型，查询时有效 */
    ULONG_32       ulCamType;

    /** 云台预置位 */
    ULONG_32       ulPresetValue;

    /** 参数:保留 */
    ULONG_32       ulParam1;

    /** 参数:保留 */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** 参数:保留 */
    CHAR        szParam3[IMOS_STRING_LEN_128];
}SCENE_UNIT_S;

/**
 * @struct tagSceneInfo
 * @brief 场景信息
 * @attention
 */
typedef struct tagSceneInfo
{
    /** 场景监控类型，目前为保留字段 */
    ULONG_32       ulSceneType;

    /** 场景监控编码 */
    CHAR        szSceneCode[IMOS_CODE_LEN];

    /** 场景监控名称 */
    CHAR        szSceneName[IMOS_NAME_LEN];

    /** 场景监控包含的单元实际数量, 最大值为#IMOS_DISPLAY_MAXNUM_PER_SALVO */
    ULONG_32       ulSceneUnitNum;

    /** 组显示单元数组 */
    SCENE_UNIT_S astSceneUnitList[IMOS_SCENE_MAXNUM_RES];
}SCENE_INFO_S;

/**
* @struct tagSceneQueryItem
* @brief 场景信息项(查询场景列表时返回)
* @attention
*/
typedef struct tagSceneQueryItem
{
    /** 场景监控编码 */
    CHAR        szSceneCode[IMOS_CODE_LEN];

    /** 场景监控名称 */
    CHAR        szSceneName[IMOS_NAME_LEN];

    /** 所属组织域编码,用于查询域以及子域下的组显示列表，平台返回不处理该值 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 场景监控包含的单元实际数量, 最大值为#IMOS_DISPLAY_MAXNUM_PER_SCENE */
    ULONG_32       ulSceneUnitNum;

}SCENE_QUERY_ITEM_S;

/**
 * @struct tagShareSceneBase
 * @brief 共享场景基本信息
 * @attention
 */
typedef struct tagShareSceneBase
{
     /** 场景编码 */
    CHAR szSceneCode[IMOS_CODE_LEN];

    /** 场景名称 */
    CHAR szSceneName[IMOS_NAME_LEN];

    /** 父组织节点编码 */
    CHAR szParentOrgCode[IMOS_CODE_LEN];

    /** 场景共享给外域时的对外编码 */
    CHAR szSceneShareCode[IMOS_CODE_LEN];

 }SHARE_SCENE_BASE_S;

/**
* @struct tagShareMapInfo
* @brief 共享场景信息
*/
typedef struct tagShareSceneInfo
{
    /** 场景所属外域编码，场景为外域共享来时使用 */
    CHAR                szExDomainCode[IMOS_CODE_LEN];

    /** 是否已共享给外域，1表示是，0表示否 */
    BOOL_T              bIsShared;

    /** 共享场景基本信息 */
    SHARE_SCENE_BASE_S    stShareSceneBaseInfo;

}SHARE_SCENE_INFO_S;

/**
* @struct tagEmailSendingConfig
* @brief 邮件发送相关的配置
* @attention
*/
typedef struct tagEmailSendingConfig
{
    /** 邮件的发送人 */
    CHAR    szSenderName[IMOS_NAME_LEN];

    /** 用户电子邮件 */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** SMTP邮件服务器地址 */
    CHAR    szSMTPMailServer[IMOS_URL_LEN];

    /** SMTP邮件服务器端口 */
    ULONG_32   ulPortNum;

    /** SMTP邮件服务器是否要求认证 */
    BOOL_T  bRequireAuthentication;

    /** 认证使用的用户名 */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** 认证使用的密码 */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** 允许群发的最大数量 */
    ULONG_32   ulEmailSenderGroupNum;
} EMAIL_SENDING_CONFIG_S;

/**
* @struct tagSMSSendingConfig
* @brief 短信业务中心配置信息
* @attention
*/
typedef struct tagSMSSendingConfig
{
    /** IP地址类型:IPV4取值为#IMOS_IPADDR_TYPE_IPV4, IPV6取值为#IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32   ulIPAddrType;

    /** 短信服务器IP地址 */
    CHAR    szIPAddress[IMOS_IPADDR_LEN];

    /** 短信服务器端口 */
    USHORT  usServerPort;

    /** 补齐位, 用于字节对齐, 无实际含义 */
    CHAR    acReserved[2];
}SMS_SENDING_CONFIG_S;

/**
* @struct tagSMSTestSendingConfig
* @brief 短信测试发送的相关配置
* @attention
*/
typedef struct tagSMSTestSendingConfig
{
    /** 短信业务中心配置信息 */
    SMS_SENDING_CONFIG_S  stSMSSendingConfig;

    /** 收信人手机号码 */
    CHAR  szSMSRecvMobilePhone[IMOS_MOBILE_LEN];

} SMS_TEST_SENDING_CONFIG_S;

/**
* @struct tagAssetInfo
* @brief 资产信息结构
* @attention
*/
typedef struct tagAssetInfo
{
    /** 资产编号 */
    CHAR    szAssetCode[IMOS_CODE_LEN];

    /** 资产名称 */
    CHAR    szAssetName[IMOS_NAME_LEN];

    /** 资产类型，取值为#ASSET_TYPE_E */
    ULONG_32   ulAssetType;

    /** 资产状态，取值为#ASSET_STATUS_E */
    ULONG_32   ulAssetStatus;

    /** 资产关联设备编码 */
    CHAR    szDevCode[IMOS_CODE_LEN];

    /** 资产关联设备名称 */
    CHAR    szDevName[IMOS_NAME_LEN];

    /** 资产直属组织编码 */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** 资产直属组织名称 */
    CHAR    szParOrgName[IMOS_NAME_LEN];

    /** 资产型号 */
    CHAR    szAssetModel[IMOS_NAME_LEN];

    /** 资产厂商 */
    CHAR    szManufacturer[IMOS_NAME_LEN];

    /** 资产IP */
    CHAR    szIpAddress[IMOS_IPADDR_LEN];

    /** 购买时间 */
    CHAR    szPurchaseTime[IMOS_TIME_LEN];

    /** 安装时间 */
    CHAR    szInstallTime[IMOS_TIME_LEN];

    /** 保修时间 */
    CHAR    szWarrantTime[IMOS_TIME_LEN];

    /** 工程商 */
    CHAR    szProdealer[IMOS_NAME_LEN];

    /** 安装地点 */
    CHAR    szLocation[IMOS_NAME_LEN];

    /** MAC地址 */
    CHAR    szMacAddr[IMOS_MAC_ADDR_LEN];

    /** 维护人 */
    CHAR    szMPerson[IMOS_NAME_LEN];

    /** 维护联系电话 */
    CHAR    szTelephone[IMOS_PHONE_LEN];

    /** 监控目标 */
    CHAR    szTarget[IMOS_NAME_LEN];

    /** 经度 */
    CHAR    szLongitude[IMOS_STRING_LEN_32];

    /** 纬度 */
    CHAR    szLatitude[IMOS_STRING_LEN_32];

    /** 海拔 */
    CHAR    szaltitude[IMOS_STRING_LEN_32];
}ASSET_INFO_S;

/**
* @struct tagAssetStatistic
* @brief 资产统计(查询资产统计的时候返回)
* @attention
*/
typedef struct tagAssetStatistic
{
    /** 分类条目(整型)，按资产类型(取值参见#ASSET_TYPE_E )分类统计时使用 */
    ULONG_32  ulCatalog;

    /** 分类条目(字符串)，按资产型号分类统计时使用 */
    CHAR  szCatalog[IMOS_STRING_LEN_64];

    /** 总数 */
    ULONG_32  ulTotalNum;

    /** 正常个数 */
    ULONG_32  ulNormalNum;

    /** 故障个数 */
    ULONG_32  ulFaultNum;

    /** 维修个数 */
    ULONG_32  ulMaintenanceNum;

    /** 报废个数 */
    ULONG_32  ulRetirementNum;

    /** 库存个数 */
    ULONG_32  ulStockNum;

    /** 待安装个数 */
    ULONG_32  ulToInstallNum;

    /** 已安装个数 */
    ULONG_32  ulInstalledNum;

    /** 已调试个数 */
    ULONG_32  ulDebuggedNum;
}ASSET_STATISTIC_S;

/**
* @struct tagFaultDevInfo
* @brief 故障设备信息(查询故障设备列表的时候返回)
* @attention
*/
typedef struct tagFaultDevInfo
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备直属组织编码 */
    CHAR  szParOrgCode[IMOS_CODE_LEN];

    /** 设备直属组织名称 */
    CHAR  szParOrgName[IMOS_NAME_LEN];

    /** 设备类型 */
    ULONG_32  ulDevType;

    /** 设备型号 */
    CHAR  szDevModel[IMOS_NAME_LEN];

    /** 设备故障状态，取值为#IMOS_DEV_FAULT_STATUS_E */
    ULONG_32  ulDevStatus;

    /** 设备IP地址 */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** 故障时间 */
    CHAR szFaultTime[IMOS_TIME_LEN];
}FAULT_DEV_INFO_S;


/**
* @struct tagFaultStatistic
* @brief 故障统计(查询故障统计的时候返回)
* @attention
*/
typedef struct tagFaultStatistic
{
    /** 设备类型，取值参见#IMOS_TYPE_E */
    ULONG_32  ulDevType;

    /** 总数 */
    ULONG_32  ulTotalNum;

    /** 故障个数 */
    ULONG_32  ulFaultNum;

    /** 故障时间 */
    CHAR szFaultTime[IMOS_TIME_LEN];
}FAULT_STATISTIC_S;

/**
 * @struct tagSThirdpartyEC
 * @brief 第三方EC信息
 * @attention
 */
typedef struct tagThirdpartyEC
{
    /* 摄像机基本信息 */
    CAMERA_INFO_S  stBaseCameraInfo;

    /* 厂商类型, 0 onvif1.0 1 onvif2.0 2 onvif2.1  9 国标*/
    ULONG_32  ulCameraManutype;

    /*设备地址*/
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /*设备端口*/
    ULONG_32  ulDevPort;

    /* 接入类型，0 本地模拟摄像机 1 IPC   */
    ULONG_32  ulCameraAccessType;

    /* 用户名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /* 密码 */
    CHAR szPassword[IMOS_PASSWD_LEN];

    /* 外接DVR通道ID,保留 */
    ULONG_32 ulCameraChnId;

    /* IPC状态，1表示在线，0表示离线 */
    ULONG_32 ulStatus;

    /* 组播地址 */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /* 组播端口, 范围为: 10002-65534, 且必须为偶数 */
    ULONG_32   ulMulticastPort;

    /* IPC所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /* MS选择的适应策略, 1为自适应; 0为指定MS, 2为不经过MS, 取值为#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulIsAutofit;

    /* 使用MS数目, 视实际情况而定, 当适应策略#ulIsAutofit为自适应, 该值为0; 当适应策略#ulIsAutofit为非自适应(即指定), 该值为1 */
    ULONG_32 ulUseMSNum;

    /* MS编码列表 */
    CHAR szMSCode[IMOS_MS_MAX_NUM_PER_CHANNEL][IMOS_DEVICE_CODE_LEN];

    /* 最大直连媒体流数目 */
    ULONG_32 ulMaxStreamNum;

    /* 告警使能 */
    BOOL_T bAlarmEnabled;

    /* 码率(用户配置ONVIF码率，并不会下发设备，所以需要用户配置成和设备一致的码率，主要用来计算可用存储天数) */
    ULONG_32 ulFakeBitRate;

    /* 使用协议类型，0: UDP 1:TCP */
    ULONG_32 ulProtocalType;

    /* 无需鉴权使能 */
    ULONG_32 ulNoAuthenticationEnabled;

    /* 时钟同步使能 */
    BOOL_T bTimeSyncEnabled;

    /* 保留字段 */
    CHAR szReserve[20];
}THIRDPARTY_EC_S;
/**
 * @struct tagCamStoreBasicQueryItem
 * @brief 摄像机存储相关基本信息项(查询存储设备上摄像机列表时返回)
 * @attention
 */
typedef struct tagCamStoreBasicQueryItem
{
    /** 摄像机名称 */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR        szCamCode[IMOS_CODE_LEN];

    /** 摄像机类型(云台，固定)#CAMERA_TYPE_E */
    ULONG_32       ulCamType;

    /** 存储类型(直存,转存)#STORE_CONFIG_TYPE_E */
    ULONG_32       ulStoreType;

    /** 存储配置设备编码(直存的存储配置设备为存储设备,转存的存储配置设备为存储资源所在BM编码) */
    CHAR        szStoreCfgDevCode[IMOS_CODE_LEN];

    /** 是否制定直存或转存计划, #BOOL_TRUE为制定, #BOOL_FALSE为未制定 */
    BOOL_T      bHasStorePlan;

    /** 直存或转存计划编码 */
    CHAR        szStorePlanCode[IMOS_CODE_LEN];

    /** 计划状态, #BOOL_TRUE为计划启动, #BOOL_FALSE为计划未启动 */
    BOOL_T      bPlanStatus;

    /** 预留字段 */
    CHAR szReserve[128];
}CAM_STORE_BASIC_QUERY_ITEM_S;

/**
 * @struct tagASDomainSynPushUI
 * @brief 域间同步结果推送给UI
 * @attention
 */
typedef struct tagASDomainSynPushUI
{
    /** 操作错误码*/
    ULONG_32 ulErrorCode;
    /** 消息的业务类型#DOMAIN_SYN_SRVTYPE_E*/
    ULONG_32 ulServiceType;
    /** 目标域*/
    CHAR  szDomainCode[IMOS_CODE_LEN];
    /** 实况数量*/
    ULONG_32 ulServiceNum;
}AS_DOMAIN_SYN_PUSHUI_S;

/**
 * @struct tagTopologyServiceInfo
 * @brief VM的监控拓扑业务信息
 * @attention
 */
typedef struct tagTopologyServiceInfo
{
    /*两个服务器间的实况数量*/
    ULONG_32 ulServiceMonitorNum;
}TOPOLOGY_SERVICE_INFO_S;

typedef struct tagTopologySrvDomain
{
    /** 用户登录信息 */
    USER_LOGIN_ID_INFO_S stUserLogIDInfo;

    /** 域编码 */
    CHAR szParentDomainCode[IMOS_CODE_LEN];

    /** 域编码 */
    CHAR szSubDomainCode[IMOS_CODE_LEN];
}TOPOLOGY_SRV_DOMAIN_S;

/**
* @struct tagIMOSSystemParamInfo
* @brief 系统参数信息
* @attention
*/
typedef struct tagIMOSSystemParamInfo
{
    /** 系统参数类型，取值为#IMOS_SYS_PARAM_TYPE_E */
    ULONG_32  ulSysParamType;

    /** 系统参数值 */
    CHAR  szSysParamValue[IMOS_SYS_PARAM_LEN];

    /** 系统参数保留字段 */
    CHAR szReserv[64];
}IMOS_SYS_PARAM_INFO_S;

/**
* @struct tagSyncServiceInfo
* @brief 同步业务信息
* @attention
*/
typedef struct tagSyncServiceInfo
{
    /** 同步业务类型，取值参见#SYNCSRV_TYPE_E */
    ULONG_32  ulSyncSrvType;

    /** 同步模式，取值参见#SYNCSRV_MODE_E */
    ULONG_32  ulSyncMode;

}SYNC_SERVICE_INFO;

/**
 * @struct tagGuardPositionInfo
 * @brief 看守位信息
 * @attention
 */
typedef struct tagGuardPositionInfo
{
    /** 看守位，与设定的预置位的编号相对应 */
    ULONG_32   ulGuardPosition;

    /** 自动看守时间, 单位为秒, 最大不超过3600秒, 0表示不看守 */
    ULONG_32   ulAutoGuard;
 }GUARD_POSITION_INFO_S;
/**
* @struct tagDevFaultDetailStatistic
* @brief 设备 故障详细信息统计
* @attention
*/
typedef struct tagDevFaultDetailStatistic
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备类型 */
    ULONG_32  ulDevType;

    /** 设备型号 */
    CHAR  szDevModel[IMOS_NAME_LEN];

    /** 设备IP地址 */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** 故障时长(单位是秒) */
    ULONG_32 ulFaultInterval;

    /** 故障次数 */
    ULONG_32 ulFaultCount;

    /** 设备直属的组织编码 */
    CHAR szParentCode[IMOS_CODE_LEN];

    /** 设备直属的组织名称 */
    CHAR szParentName[IMOS_NAME_LEN];
}DEV_FAULT_DETAIL_STAT_S;

/**
* @struct tagDevFaultDetail
* @brief 设备故障详细信息
* @attention
*/
typedef struct tagDevFaultDetail
{
    /** 设备编码 */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备类型 */
    ULONG_32  ulDevType;

    /** 设备型号 */
    CHAR  szDevModel[IMOS_NAME_LEN];

    /** 设备故障状态，取值为#IMOS_DEV_FAULT_STATUS_E */
    ULONG_32  ulDevStatus;

    /** 设备IP地址 */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** 故障时间 */
    CHAR szFaultTime[IMOS_TIME_LEN];

    /** 故障恢复时间 */
    CHAR szRecoverTime[IMOS_TIME_LEN];

    /** 故障时长(单位是秒) */
    ULONG_32 ulFaultInterval;

    /** 设备直属的组织编码 */
    CHAR szParentCode[IMOS_CODE_LEN];

    /** 设备直属的组织名称 */
    CHAR szParentName[IMOS_NAME_LEN];
}DEV_FAULT_DETAIL_S;

/**
 * @struct tagTimeSlice
 * @brief 基本时间片信息
 * @attention 00:00:00~23:59:59表示一整天的时间片
 */
typedef struct tagQueryTimeSlice
{
    /* 是否需要根据时间片筛选 */
    BOOL_T bIsNeed;

    /** 开始时间 格式为"hh:mm:ss" */
    CHAR        szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 格式为"hh:mm:ss" */
    CHAR        szEndTime[IMOS_TIME_LEN];
}QUERY_TIME_SLICE_S;

/**
* @union tagVocDstInfo
* @brief 语音目的联合结构
* @attention 无
*/
typedef union tagVocDstInfo
{
    /** 目的用户信息 */
    USER_LOGIN_ID_INFO_S stDstUserInfo;

    /** 目的摄像机编码 */
    CHAR szCameraCode[IMOS_CODE_LEN];
}VOC_DST_INFO_U;

/**
* @struct tagVocSrvDstInfo
* @brief 语音业务目的信息结构
* @attention 无
*/
typedef struct tagVocSrvDstInfo
{
     /** 目的类型，请参见IMOS_TYPE_E */
     ULONG_32  ulDstType;

     /** 目的编码有关信息 */
     VOC_DST_INFO_U unDstInfo;
}VOC_SRV_DST_INFO_S;

/**
* @struct tagVocSrvRecordInfo
* @brief 语音业务记录信息结构
* @attention 无
*/
typedef struct tagVocSrvRecordInfo
{
     /** 目的信息 */
     VOC_SRV_DST_INFO_S  stDstInfo;

     /** 目的名称 */
     CHAR   szDstName[IMOS_NAME_LEN];

     /** 目的是否是主叫方 */
     BOOL_T bCaller;

     /** 语音业务请求序列号 */
     ULONG_32  ulReqSeq;

     /** 语音业务类型，请参见SRV_TYPE_E */
     ULONG_32  ulVocSrvType;

     /** 语音业务状态，请参见VOCSRV_STATUS_E */
     ULONG_32  ulVocSrvState;

     /** 语音业务操作结果 */
     ULONG_32  ulVocOperResult;

}VOCSRV_RECORD_INFO_S;

/**
* @struct tagCSVocReqNotify
* @brief SOI 语音业务请求通知信息结构
* @attention 无
*/
typedef struct tagCSVocReqNotify
{
    BOOL_T  bNewReq;                     /* 是否是新建请求通知 */
    ULONG_32   ulReqSequence;               /* 请求序列号 */
    ULONG_32   ulVocType;                   /* 语音业务类型, 值含义见SRV_TYPE_E */
    USER_LOGIN_ID_INFO_S  stCallerInfo;  /* 主叫用户信息 */
    CHAR    szCallerName[IMOS_NAME_LEN]; /* 主叫用户名称 */
}CS_VOC_REQ_NOTIFY_S;

/**
* @struct tagCSVocStateNotify
* @brief SOI 语音业务状态同志信息结构
* @attention 无
*/
typedef struct tagCSVocStateNotify
{
    ULONG_32   ulEventType;                               /* 事件操作类型，枚举值为:VOC_EVENT_TYPE_E */
    ULONG_32   ulTroubleCode;                             /* 异常事件详细错误码，见具体错误码含义 */
    CHAR    szCreatUserName[IMOS_NAME_LEN];            /* 发生事件的用户的名称 */
    CHAR    szCreatUserIpAddress[IMOS_IPADDR_LEN];     /* 发生事件的用户的登录IP */
    CHAR    szCreatUserLoginCode[IMOS_CODE_LEN];       /* 发生事件的用户的登录ID */

    ULONG_32   ulOrgSrvType;                              /* 事件发生前原有业务类型，枚举值为:SRV_TYPE_E */
    CHAR    szOrgDstCode[IMOS_CODE_LEN];               /* 原业务操作对象编码 */
    CHAR    szOrgDstName[IMOS_NAME_LEN];               /* 原业务操作对象名 */
    CHAR    szOrgDstDomainCode[IMOS_CODE_LEN];         /* 原业务操作对象所属域编码 */
    CHAR    szOrgDstDomainName[IMOS_NAME_LEN];         /* 原业务操作对象所属域名 */

    ULONG_32   ulCurSrvType;                              /* 事件发生后的业务类型，枚举值为:SRV_TYPE_E */
    CHAR    szCurDstCode[IMOS_CODE_LEN];               /* 新业务操作对象编码 */
    CHAR    szCurDstName[IMOS_NAME_LEN];               /* 新业务操作对象名 */
    CHAR    szCurDstDomainCode[IMOS_CODE_LEN];         /* 新业务操作对象所属域编码 */
    CHAR    szCurDstDomainName[IMOS_NAME_LEN];         /* 新业务操作对象所属域名 */
}CS_VOC_STATE_NOTIFY_S;

/**
* @struct tagQueryResRequestInfo
* @brief 资源查询请求信息结构体
* @attention
*/
typedef struct tagQueryResRequestInfo
{
    /** 资源编码 */
    CHAR                    szResCode[IMOS_CODE_LEN];

    /** 资源类型,取值范围为#IMOS_TYPE_E */
    ULONG_32                   ulResType;
}QUERY_RES_REQUEST_INFO_S;

/**
 * @struct tagShareResBase
 * @brief 共享资源基本信息
 * @attention
 */
typedef union tagShareResBase
{
    /** 共享组织基本信息 */
    SHARE_ORG_BASE_S  stOrgShareInfo;

    /** 共享摄像机基本信息 */
    SHARE_CAMERA_BASE_V2_S stCamShareInfo;

    /** 共享告警源基本信息 */
    SHARE_ALARMSRC_BASE_S stAlaramSrcShareInfo;

    /** 共享地图基本信息 */
    SHARE_MAP_BASE_S    stMapShareInfo;

    /** 共享场景基本信息 */
    SHARE_SCENE_BASE_S   stShareSceneInfo;
} SHARE_RES_BASE_U;

/**
* @struct tagResShareInRecordInfo
* @brief 资源被共享外域(IN)结构体
* @attention
* 1.如是本域资源则填写本域名称和编码
*/
typedef struct tagResShareInRecordInfo
{
    /** 资源所属域名称 */
    CHAR                    szResDomainName[IMOS_NAME_LEN];

    /** 资源所属域编码 */
    CHAR                    szResDomainCode[IMOS_CODE_LEN];
}RES_SHARE_IN_RECORD_INFO_S;

/**
* @struct tagResShareOutRecordInfo
* @brief 资源共享外域(OUT)结构体
*/
typedef struct tagResShareOutRecordInfo
{
    /** 共享资源基本信息 */
    SHARE_RES_BASE_U        unShareResBaseInfo;

    /** 资源共享域(OUT)名称 */
    CHAR                    szDomainName[IMOS_NAME_LEN];

    /** 资源共享域(OUT)编码 */
    CHAR                    szDomainCode[IMOS_CODE_LEN];

    /** 外域类型(只可能是:上级域/平级域), 取值为#EX_DOMAIN_TYPE_E */
    ULONG_32   ulOuterDomainType;

    /** 外域地址类型，1-IPv4 2-IPv6 */
    ULONG_32   uladdrtype;

    /** 外域地址 */
    CHAR    szDomainAddr[IMOS_IPADDR_LEN];

    /** 厂商类型
        对于非OEM版本(VM8500等H3C设备),取值为
            #IMOS_MANUFACTURER_TYPE_VMISC
            #IMOS_MANUFACTURER_TYPE_DA
            #IMOS_MANUFACTURER_TYPE_OTHER
        对于OEM版本(PL/PL-S),取值为
            #IMOS_MANUFACTURER_TYPE_PL
            #IMOS_MANUFACTURER_TYPE_PLS
            #IMOS_MANUFACTURER_TYPE_OTHER */
    CHAR szManufacturerType[IMOS_STRING_LEN_64];

    /** 跨域中的域等级，有效范围为1～7 */
    ULONG_32 ulDomainLevel;

    /** 域间通讯协议类型，取值为#INTERDOMAIN_PROTOCOL_TYPE_E */
    ULONG_32 ulProtocolType;

    /** 主动注册状态，指本域向当前这个外域注册是否成功, 1为成功; 2为失败 */
    ULONG_32                     ulActiveRegSta;

    /** 接收注册状态，指当前这个外域向本域注册是否成功, 1为成功; 2为失败 */
    ULONG_32                     ulRecvRegSta;

    /** 保留字段 */
    CHAR szReserve[128];
}RES_SHARE_OUT_RECORD_INFO_S;

/**
* @struct tagAlarmRecordInfo
* @brief 告警记录
* @attention
*/
typedef struct tagAlarmRecordInfo
{
    /** 告警编码 */
    CHAR szEventCode[IMOS_CODE_LEN];

    /** 告警记录类型，取值为#ALARM_RECORD_TYPE_E */
    ULONG_32 ulAlarmRecordType;

    /** 执行用户名称 */
    CHAR szExecuteUserName[IMOS_NAME_LEN];

    /** 执行时间 */
    CHAR szExecuteTime[IMOS_TIME_LEN];

    /** 用户IP地址 */
    CHAR szUserAddr[IMOS_IPADDR_LEN];

    /** 记录描述 */
    CHAR szExecuteDesc[IMOS_STRING_LEN_512];

    /** 新告警编码，为空表示不是产生新告警或新告警没有告警处理记录 */
    CHAR szNewEventRecordCode[IMOS_CODE_LEN];
}ALARM_RECORD_INFO_S;

/**
* @struct tagEndTaskBase
* @brief 结束任务基本信息
* @attention
*/
typedef struct tagEndTaskBase
{
    /** 任务序号，为0表示结束所有任务 */
    ULONG_32 ulTaskSequence;

    /** 任务名 */
    CHAR  szTaskName[IMOS_NAME_LEN];
}END_TASK_BASE_S;

/**
* @struct tagEndTaskAction
* @brief 联动到结束任务
* @attention
*/
typedef struct tagEndTaskAction
{
    /** 任务数目 */
    ULONG_32 ulEndTaskNum;

    /** 结束任务基本信息 */
    END_TASK_BASE_S astEndTaskBase[IMOS_MAX_TASK_NUM];
}END_TASK_ACTION_S;

/**
* @struct tagStartTaskBase
* @brief 启动任务基本信息
* @attention
*/
typedef struct tagStartTaskBase
{
    /** 任务序号 */
    ULONG_32 ulTaskSequence;

    /** 任务名 */
    CHAR  szTaskName[IMOS_NAME_LEN];

    /** 等待时长（过多久启动，单位:秒）*/
    ULONG_32 ulTime;
}START_TASK_BASE_S;

/**
* @struct tagStartTaskAction
* @brief 联动到启动任务
* @attention
*/
typedef struct tagStartTaskAction
{
    /** 任务数目 */
    ULONG_32 ulStartTaskNum;

    /** 启动任务基本信息 */
    START_TASK_BASE_S astStartTaskBase[IMOS_MAX_TASK_NUM];
}START_TASK_ACTION_S;

/**
* @struct tagTranAlarmAction
* @brief 联动转发原告警
* @attention
*/
typedef struct tagTranAlarmAction
{
    /** 转发用户数目 */
    ULONG_32 ulTranUserNum;

    /** 转发用户信息(增改时用户编码有效，其他无效；查询时用户登录ID、用户登录地址、用户登陆时间、用户是否被锁定无效，其他有效) */
    USER_QUERY_ITEM_S astTranUserInfo[IMOS_ALARM_ACTION_TRAN_MAXNUM];
}TRAN_ALARM_ACTION_S;

/**
* @struct tagCreateNewAlarmAction
* @brief 联动产生新告警
* @attention
*/
typedef struct tagCreateNewAlarmAction
{
     /** 新告警数目 */
    ULONG_32 ulNewAlarmNum;

    /** 新告警信息 */
    EVENT_TYPE_INFO_S astNewAlarmBase[IMOS_MAX_NEW_ALARM_NUM];
}CREATE_NEW_ALARM_ACTION_S;

/**
* @struct tagPlanAction
* @brief 预案特有联动动作
* @attention
*/
typedef struct tagPlanAction
{
    /** 联动结束任务 */
    END_TASK_ACTION_S           stEndTaskAction;

    /** 联动启动任务 */
    START_TASK_ACTION_S         stStartTaskAction;

    /** 转发原告警 */
    TRAN_ALARM_ACTION_S         stTranAlarmAction;

    /** 产生新告警 */
    CREATE_NEW_ALARM_ACTION_S   stCreateNewAlarmAction;
}TASK_ACTION_S;

/**
* @struct tagTaskActionInfo
* @brief 任务动作集
* @attention
*/
typedef struct tagTaskActionInfo
{
    /** 告警联动动作 */
    ALARM_ACTION_S stNormalAlarmAction;

    /** 预案中特有的动作 */
    TASK_ACTION_S stPlanAction;
}TASK_ACTION_INFO_S;

/**
* @struct tagTaskTriggerInfo
* @brief 触发器结构
* @attention
*/
typedef struct tagTaskTriggerInfo
{
    /** 触发器ID，取值为#TRIGGER_ID_E */
    ULONG_32 ulTriggerID;

    /** 触发器名称 */
    CHAR szTriggerName[IMOS_NAME_LEN];

    /** 触发器参数个数 */
    ULONG_32 ulParamNum;

    /** 触发器参数名称(以英文;分割*/
    CHAR szParamName[IMOS_DESC_LEN];

    /** 触发器参数值(以英文;分割 */
    CHAR szParamValue[IMOS_DESC_LEN];
}TASK_TRIGGER_INFO_S;

/**
* @struct tagActionPlanTaskInfo
* @brief 任务结构
* @attention
*/
typedef struct tagPlanTaskInfo
{
    /** 任务序号 */
    ULONG_32 ulTaskSequence;

    /** 任务名称 */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** 任务执行策略，取值为#TASK_EXEC_STRATEGY_E */
    ULONG_32 ulTaskExecStrategy;

    /** 手动执行超时时间(单位:秒，手动执行时此字段才有效) */
    ULONG_32 ulOverTime;

    /** 触发器个数 */
    ULONG_32 ulTriggerNum;

    /** 触发器列表 */
    TASK_TRIGGER_INFO_S astTriggerList[IMOS_MAX_TRIGGER_NUM];

    /** 动作集结构 */
    TASK_ACTION_INFO_S stTaskActionInfo;
}ACTION_PLAN_TASK_INFO_S;

/**
* @struct tagActionPlanInfo
* @brief 预案信息
* @attention
*/
typedef struct tagActionPlanInfo
{
    /** 预案编码 */
    CHAR szActionPlanCode[IMOS_CODE_LEN];

    /** 预案名称 */
    CHAR szActionPlanName[IMOS_NAME_LEN];

    /** 预案类型，取值为#ACTION_PLAN_TYPE_E */
    ULONG_32 ulActionPlanType;

    /** 预案策略，取值为#PLAN_EXEC_STRATEGY_E */
    ULONG_32 ulExecStrategy;

    /** 预案描述 */
    CHAR szActionPlanDesc[IMOS_DESC_LEN];

    /** 预案任务数量 */
    ULONG_32 ulTaskNum;

    /** 预案任务列表 */
    ACTION_PLAN_TASK_INFO_S astTaskList[IMOS_MAX_TASK_NUM];
}ACTION_PLAN_INFO_S;

/**
* @struct tagPlanTaskBaseInfo
* @brief 任务基本结构
* @attention
*/
typedef struct tagPlanTaskBaseInfo
{
    /** 任务序号 */
    ULONG_32 ulTaskSequence;

    /** 任务名称 */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** 任务处理方式，取值为#TASK_DEAL_MODE_E */
    ULONG_32 ulTaskDealMode;
}PLAN_TASK_BASE_INFO_S;

/**
* @struct tagPlanAlarmChgPushUI
* @brief 推送给UI的预案告警变化推送结构
* @attention
*/
typedef struct tagPlanAlarmChgPushUI
{
    /** 告警记录信息 */
    EVENT_RECORD_S stEventRecord;

    /** 预案告警变化类型，取值为#PLAN_ALARM_CHG_TYPE_E */
    ULONG_32 ulChgType;
}PLAN_ALARM_CHG_PUSH_UI_S;

/**
* @struct tagPlanAlarmChgExPushUI
* @brief 预案告警变化扩展推送信息
* @attention
*/
typedef struct tagPlanAlarmChgExPushUI
{
    /** 预案告警变化推送信息 */
    PLAN_ALARM_CHG_PUSH_UI_S stPlanAlarmChgPushUI;

    /** 用户登陆信息表id */
    CHAR    szUserLoginId[IMOS_STRING_LEN_32];

    /** SDK Module Name */
    CHAR    szSDKModuleName[IMOS_NAME_LEN];

}PLAN_ALARM_CHG_EX_PUSH_UI_S;

/**
* @struct tagQuerySysInfo
* @brief 查询系统信息
* @attention
*/
typedef struct tagQuerySysInfo
{
    /** 查询信息名字，取值为# QUERY_SYS_INFO_NAME_E */
    ULONG_32 ulQuerySysInfoName;

    /** 查询值 */
    CHAR szQueryValue[IMOS_DESC_LEN];
}QUERY_SYS_INFO_S;

/**
* @struct tagExAutoShareInfo
* @brief 组织自动共享给外域信息结构
*/
typedef struct tagExAutoShareInfo
{
    /** 外域编码 */
    CHAR szExDomainCode[IMOS_CODE_LEN];

    /** 组织编码 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 是否自动共享给外域，#BOOL_TRUE为自动共享给外域，反之取值为#BOOL_FALSE */
    BOOL_T bIsAutoShare;

    /** (设置是否自动共享给外域时)是否包含子组织，#BOOL_TRUE为包含子组织，反之取值为#BOOL_FALSE */
    BOOL_T bDoesContainSub;

    /** 保留字段 */
    CHAR szReserved[128];
} EX_AUTO_SHARE_INFO_S;

/**
 * @struct tagShareUnSucceedRes
 * @brief 未共享成功资源信息
 * @attention
 */
typedef struct tagShareUnSucceedRes
{
    /** 未成功原因码，#ERR_COMMON_SUCCEED表示还在推送中，其它值都表示推送失败，值对应的错误类型见错误码列表*/
    ULONG_32 ulDetailCode;

    /** 资源类型 */
    ULONG_32 ulResType;

    /** 资源编码 */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 资源互联编码 */
    CHAR  szResShareCode[IMOS_CODE_LEN];

    /** 资源父编码 */
    CHAR  szResParentCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR  szResParentName[IMOS_NAME_LEN];

    /** 资源共享的权限 */
    ORG_AUTHORITY_V2_S  stAuthority;
}SHARE_UNSUCCEED_RES_S;

/**
* @struct tagEventEnableInfo
* @brief 事件使能策略信息结构
* @attention
*/
typedef struct tagEventEnableInfo
{

    /** 事件系统默认名字 */
    CHAR    szPreEventName[IMOS_NAME_LEN];

    /** 事件系统默认级别, 取值为#ALARM_SEVERITY_LEVEL_E */
    ULONG_32   ulPreEventSecurity;

    /** 事件系统自定义名字, 系统事件使能策略显示事件使能名称 */
    CHAR    szSysEventName[IMOS_NAME_LEN];

    /** 事件系统自定义级别, 取值为#ALARM_SEVERITY_LEVEL_E, 系统事件使能策略显示事件使能级别 */
    ULONG_32   ulSysEventSecurity;

    /** 事件使能重名字 */
    CHAR    szEventName[IMOS_NAME_LEN];

    /** 事件使能级别, 取值为#ALARM_SEVERITY_LEVEL_E */
    ULONG_32   ulEventSecurity;

    /** 是否自动确认, #BOOL_TRUE为自动确认, #BOOL_FALSE不自动确认, 默认为#BOOL_TRUE */
    BOOL_T   bAutoAck;

    /** 是否使能, #BOOL_TRUE为使能, #BOOL_FALSE为未使能, 默认为BOOL_TRUE */
    BOOL_T   bEnable;

}EVENT_ENABLE_INFO_S;

/**
* @struct tagBathEventEnableInfo
* @brief  批量设置事件使能策略信息结构
* @attention
*/
typedef struct tagBathEventEnableInfo
{
    /** 需要自定义的告警类型, 取值为#AlARM_TYPE_E, 0表示为全部 */
    ULONG_32       ulEventType;

    /** 批处理的告警源数量 */
    ULONG_32       ulDevNum;

    /** 批处理告警源信息 */
    ALARM_SRC_QUERY_ITEM_S astAlarmSrcList[IMOS_PAGE_QUERY_ROW_MAX_NUM];

} BATH_EVENT_ENABLE_INFO_S;
/**
 * @struct tagSetNetworkAdaptInfo
 * @brief实况网络适应性信息
 * @attention
 */
typedef struct tagSetNetworkAdaptInfo
{
     /** 实况网络适应开关 1开 2关 */
    ULONG_32  ulMonitorNetworkAdaptEnable;

    /**存储 网络适应开关 1开 2关 */
    ULONG_32  ulStoreNetworkAdaptEnable;

    /** 网络适应模式   0:帧率优先 1：图像优先 */
    ULONG_32  ulNetworkAdaptMode;

    /** 实况网络自适应恢复时间 */
    ULONG_32  ulNetworkAdaptCount;

     /**保留  */
    UCHAR   szReserved[128];
} NETWORK_ADAPT_INFO_S;

/**
* @struct tagEventTypeL2oRel
* @brief 本外域告警类型对应关系
* @attention
*/
typedef struct tagEventTypeL2oRel
{
    /** 关系类型ID */
    CHAR szEventTypeL2ORelCode[IMOS_CODE_LEN];

	 /* 协议类型 */
    ULONG_32 ulProtocolType;

    /** 本域事件类型 */
    ULONG_32 ulH3cEventType;

    /** 协议事件类型 */
    ULONG_32  ulProtocolEventType;

    /** 告警状态 */
    ULONG_32   ulEventStatus;

    /** 关系描述 */
    CHAR   szRelDesc[IMOS_DESC_LEN];

}EVENT_TYPE_L2OREL_S;

/**
 * @struct tagMapColors
 * @brief GIS地图颜色
 * @attention
 */
typedef struct tagMapColors
{
	/** 地图填充颜色 */
    ULONG_32                   ulFillZone;

	/** 地图线条颜色 */
    ULONG_32                   ulLine;

	/** 山川区域颜色 */
    ULONG_32                   ulHills;

	/** 深水区域颜色 */
    ULONG_32                   ulDeepWater;

	/** 城市区域颜色 */
	ULONG_32                   ulCity;

	/** 浅水区域颜色 */
	ULONG_32                   ulShallowWater;
}FILE_MAP_COLORS_S;

/**
* @struct tagEventSecurityType
* @brief 事件级别
* @attention
*/
typedef struct tagEventSecurityType
{
    /** 级别类型 */
    ULONG_32  ulSecurityType;

    /** 级别名称 */
    CHAR   szSecurityName[IMOS_NAME_LEN];

    /** 级别显示颜色，颜色RGB值，不包含(#)号 */
    CHAR  szSecurityColor[IMOS_STRING_LEN_14];

    /** 级别描述信息 */
    CHAR   szDesc[IMOS_DESC_LEN];

    /** 保留 */
    UCHAR   szReserved[128];

} EVENT_SECURITY_TYPE_S;

/**
* @struct tagEventSecurityExtType
* @brief 事件级别扩展信息
* @attention
*/
typedef struct tagEventSecurityExtType
{
    /** 级别信息 */
    EVENT_SECURITY_TYPE_S stEventSecurityType;

    /** 是否是系统预定义告警级别 */
    BOOL_T                bSysEventType;

} EVENT_SECURITY_EXT_TYPE_S;

/**
* @struct tagEventSecurityChgPushUI
* @brief 推送给UI的级别信息变化推送结构
* @attention
*/
typedef struct tagEventSecurityChgPushUI
{
    /** 告警级别信息 */
    EVENT_SECURITY_TYPE_S stEventSecurity;

    /** 告警级别变化类型，取值为#EVENT_SECURITY_CHG_TYPE_E */
    ULONG_32 ulChgType;
} EVENT_SECURITY_CHG_PUSH_UI_S;

/**
* @struct tagEventSecurityChgExPushUI
* @brief 事件级别变化扩展推送信息
* @attention
*/
typedef struct tagEventSecurityChgExPushUI
{
    /** 事件级别变化推送信息 */
    EVENT_SECURITY_CHG_PUSH_UI_S stEventSecurityChgPushUI;

    /** 用户登陆信息表id */
    CHAR    szUserLoginId[IMOS_STRING_LEN_32];

    /** SDK Module Name */
    CHAR    szSDKModuleName[IMOS_NAME_LEN];

} EVENT_SECURITY_CHG_EX_PUSH_UI_S;

/**
/**
* @struct tagCSPtzStatusNotify
* @brief SOI 云台状态变更信息 结构
* @attention 无
*/
typedef struct tagCSPtzStatusNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                  /* 用户名称 */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];           /* 抢占操作用户的登录IP */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];         /* 摄像机编码 */
    CHAR    szCameraName[IMOS_NAME_LEN];                /* 摄像机名称 */
    ULONG_32   ulNotifyType;                               /* 通知类型 对应枚举:#PTZ_NOTIFY_UI_EVENT_TYPE */
	ULONG_32   ulAutoGuard;                                /* 云台返回看守位时间 */
}CS_PTZ_STATUS_NOTIFY_S;

/**
* @struct tagCaseInfo
* @brief 案件信息结构
* @attention
*/
typedef struct tagGACaseInfo
{
    /** 案件编号 */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** 案件名称 */
    CHAR    szCaseName[IMOS_STRING_LEN_256];

    /** 案件性质，取值为#CASE_PROPERTY_E */
    ULONG_32   ulCaseProperty;

    /** 案件类型，取值为#CASE_TYPE_E */
    // ULONG_32   ulCaseType;

    /** 案件类型 */
    CHAR    szCaseType[IMOS_STRING_LEN_256];

    /** 案件状态，取值为#CASE_STATUS_E */
    ULONG_32   ulCaseStatus;

    /** 警情来源，取值为#POLICE_INTELLIGENCE_SOURCE_E */
    ULONG_32   ulPoliceIntSrc;

    /** 密级，取值#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** 接警单号 */
    CHAR    szReportCode[IMOS_CODE_LEN];

    /** 接警时间 */
    CHAR    szReportTime[IMOS_TIME_LEN];

    /** 处理人 */
    CHAR    szProPerson[IMOS_NAME_LEN];

    /** 案件创建人员名称 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 危害程度 */
    CHAR    szEndangerment[IMOS_NAME_LEN];

    /** 案件描述 */
    CHAR    szCaseDesc[IMOS_CASE_DESC_LEN];

    /** 案件备注 */
    CHAR    szCaseNote[IMOS_NOTE_LEN];

    /** 开始时间 */
    CHAR    szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR    szEndTime[IMOS_TIME_LEN];

    /** 作案时机 */
    CHAR    szCrimeOpporunity[IMOS_NAME_LEN];

    /** 作案场所 */
    CHAR    szCrimelocation[IMOS_NAME_LEN];

    /** 作案部位 */
    CHAR    szCrimePosition[IMOS_NAME_LEN];

    /** 作案人数 */
    ULONG_32    ulCriminalNum;

    /** 作案对象 */
    CHAR    szCrimeTarget[IMOS_NAME_LEN];

    /** 作案手段 */
    CHAR    szCrimeStyle[IMOS_STRING_LEN_512];

    /** 作案特点 */
    CHAR    szCrimeFeature[IMOS_STRING_LEN_512];

    /** 区县 */
    CHAR    szDistrict[IMOS_NAME_LEN];

    /** 街道 */
    CHAR    szStreet[IMOS_NAME_LEN];

    /** 警区 */
    CHAR    szPoliceDstrict[IMOS_STRING_LEN_256];

    /** 社区 */
    CHAR    szCommunity[IMOS_NAME_LEN];

    /** 详细地址 */
    CHAR    szAddress[IMOS_STRING_LEN_256];

    /** 部门编码 */
    CHAR    szDeptCode[IMOS_CODE_LEN];

    /** 部门名称 */
    CHAR    szDeptName[IMOS_NAME_LEN];

    /** 创建时间 */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** 破案时间 */
    CHAR    szSolvedTime[IMOS_TIME_LEN];

    /** 结案时间 */
    CHAR    szClosedTime[IMOS_TIME_LEN];

    /** 源案件编号 */
    CHAR    szSrcCaseCode[IMOS_CODE_LEN];

    /** 转案件编号 */
    CHAR    szTransCaseCode[IMOS_CODE_LEN];
}CASE_INFO_S;


/**
* @struct tagCaseListInfo
* @brief 案件列表信息结构
* @attention
*/
typedef struct tagCaseListInfo
{
    /** 案件编号 */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** 案件名称 */
    CHAR    szCaseName[IMOS_STRING_LEN_256];

    /** 案件类型，取值为#CASE_TYPE_E */
    //ULONG_32   ulCaseType;

    /** 案件类型 */
    CHAR    szCaseType[IMOS_STRING_LEN_256];

    /** 案件状态，取值为#CASE_STATUS_E */
    ULONG_32   ulCaseStatus;

    /* 是否存在串并案，0:非串并案，1:存在串并案 */
    BOOL_T  bIsSeries;

    /** 案件性质，取值为#CASE_PROPERTY_E */
    ULONG_32   ulCaseProperty;

    /** 警情来源，取值为#POLICE_INTELLIGENCE_SOURCE_E */
    ULONG_32   ulPoliceIntSrc;

    /** 危害程度 */
    CHAR    szEndangerment[IMOS_NAME_LEN];

    /** 创建人 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 开始时间 */
    CHAR    szBeginTime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR    szEndTime[IMOS_TIME_LEN];

    /** 直属部门编码 */
    CHAR    szParDeptCode[IMOS_CODE_LEN];

    /** 直属部门名称 */
    CHAR    szParDeptName[IMOS_NAME_LEN];
}CASE_LIST_INFO_S;

/**
* @struct tagCasePersonnelExtraInfo
* @brief 案件人员额外信息结构
* @attention
*/
typedef struct tagCasePersonnelExtraInfo
{
    /** 行为 */
    CHAR    szBehavior[IMOS_NAME_LEN];

    /** 口音 */
    CHAR    szAccent[IMOS_NAME_LEN];

    /** 体型 */
    CHAR    szBodyShape[IMOS_NAME_LEN];

    /** 身高 */
    CHAR    szHeight[IMOS_NAME_LEN];

    /** 肤色 */
    CHAR    szSkinColor[IMOS_NAME_LEN];

    /** 体表 */
    CHAR    szBodySurface[IMOS_NAME_LEN];

    /** 上衣款式 */
    CHAR    szShirtStyle[IMOS_NAME_LEN];

    /** 上衣颜色 */
    CHAR    szShirtColor[IMOS_NAME_LEN];

    /** 上衣特征 */
    CHAR    szShirtFeature[IMOS_NAME_LEN];

    /** 衣袖长度 */
    CHAR    szSleeveLength[IMOS_NAME_LEN];

    /** 衣领 */
    CHAR    szCollar[IMOS_NAME_LEN];

    /** 裤型 */
    CHAR    szTrousers[IMOS_NAME_LEN];

    /** 裤长 */
    CHAR    szTrousersLength[IMOS_NAME_LEN];

    /** 裤色 */
    CHAR    szTrousersColor[IMOS_NAME_LEN];

    /** 发型 */
    CHAR    szHairstyle[IMOS_NAME_LEN];

    /** 发色 */
    CHAR    szHairColor[IMOS_NAME_LEN];

    /** 眼镜 */
    CHAR    szEyeglasses[IMOS_NAME_LEN];

    /** 帽子 */
    CHAR    szCap[IMOS_NAME_LEN];

    /** 围巾 */
    CHAR    szScarf[IMOS_NAME_LEN];

    /** 包 */
    CHAR   szBag[IMOS_NAME_LEN];

    /** 鞋型 */
    CHAR   szShoeType[IMOS_NAME_LEN];

    /** 鞋色*/
    CHAR   szShoeColor[IMOS_NAME_LEN];
}CASE_PERSONNEL_EXTRA_INFO_S;

/**
* @struct tagCasePersonnelInfo
* @brief 案件人员信息结构
* @attention
*/
typedef struct tagCasePersonnelInfo
{
    /** 案件编号 */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** 案件人员编号，查询时由后台带出 */
    CHAR    szPersCode[IMOS_CODE_LEN];

    /** 人员类别，取值为#CASE_PERSONNEL_TYPE_E */
    ULONG_32   ulPersonnelType;

    /** 姓名 */
    CHAR    szName[IMOS_NAME_LEN];

    /** 性别，取值为#GENDER_TYPE_E */
    ULONG_32   ulGender;

    /** 年龄，下限 */
    ULONG_32   ulMinAge;

    /** 年龄，上限 */
    ULONG_32   ulMaxAge;

    /** 籍贯 */
    CHAR   szNativePlace[IMOS_NAME_LEN];

    /** 联系电话 */
    CHAR    szTelephone[IMOS_PHONE_LEN];

    /** 工作单位 */
    CHAR    szCompany[IMOS_NAME_LEN];

    /** 创建人 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];

    CASE_PERSONNEL_EXTRA_INFO_S stCasePerExInfo;
}CASE_PERSONNEL_INFO_S;

/**
* @struct tagCaseVehicleInfo
* @brief 案件车辆信息结构
* @attention
*/
typedef struct tagCaseVehicleInfo
{
    /** 案件编号 */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** 案件车辆编号 */
    CHAR    szVehicleCode[IMOS_CODE_LEN];

    /** 车牌号码 */
    CHAR    szPlateCode[IMOS_CODE_LEN];

    /** 车辆颜色*/
    CHAR    szVehicleColor[IMOS_NAME_LEN];

    /** 车辆类型 */
    CHAR    szVehicleType[IMOS_NAME_LEN];

    /** 车辆行为*/
    CHAR    szBehavior[IMOS_NAME_LEN];

    /** 车辆特征 */
    CHAR    szVehicleFeature[IMOS_NAME_LEN];

    /** 车辆属地 */
    CHAR   szlocalization[IMOS_NAME_LEN];

    /** 车辆分类 */
    CHAR    szClassification[IMOS_NAME_LEN];

    /** 车辆厂商 */
    CHAR    szManufacturer[IMOS_NAME_LEN];

    /** 车牌类型 */
    CHAR    szPlateType[IMOS_NAME_LEN];

    /** 车牌颜色 */
    CHAR    szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌遮挡 */
    CHAR    szPlateCover[IMOS_NAME_LEN];

    /** 车辆贴膜 */
    CHAR    szWindowFilm[IMOS_NAME_LEN];

    /** 创建人 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_VEHICLE_INFO_S;


/**
* @struct tagCaseStuffInfo
* @brief 案件物品信息结构
* @attention
*/
typedef struct tagCaseStuffInfo
{
    /** 案件编号 */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** 案件物品编号，查询时由服务器带出 */
    CHAR    szStuffCode[IMOS_CODE_LEN];

    /** 物品名称 */
    CHAR    szStuffName[IMOS_NAME_LEN];

    /** 涉案物品类别，取值为#CASE_STUFF_TYPE_E */
    ULONG_32   ulCaseStuffType;

    /** 涉案物品性质，取值为#CASE_STUFF_PROPERTY_E */
    ULONG_32   ulCaseStuffProperty;

    /** 创建人 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_STUFF_INFO_S;

/**
* @struct tagCaseRecordInfo
* @brief 案件录像信息结构
* @attention
*/
typedef struct tagCaseRecordInfo
{
    /** 录像编码，查询时带出 */
    CHAR    szRecCode[IMOS_CODE_LEN];

    /** 视频监控点 */
    CHAR    szTarget[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** 开始时间 */
    CHAR    szBegintime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR    szEndtime[IMOS_TIME_LEN];

    /** 密级，取值#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_RECORD_INFO_S;

/**
* @struct tagCaseRecordListInfo
* @brief 案件录像列表信息结构
* @attention
*/
typedef struct tagCaseRecordListInfo
{
    /** 录像编码 */
    CHAR    szRecordCode[IMOS_CODE_LEN];

    /** 视频监控点 */
    CHAR    szTarget[IMOS_NAME_LEN];

    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** 开始时间 */
    CHAR    szBegintime[IMOS_TIME_LEN];

    /** 结束时间 */
    CHAR    szEndtime[IMOS_TIME_LEN];

    /** 录像大小 */
    ULONG_32    ulRecordSize;

    /** 录像备份状态，0:未完成，1:完成 */
    ULONG_32    ulBakStatus;

    /** 上传用户 */
    CHAR    szUploadUser[IMOS_NAME_LEN];

    /** 上传时间 */
    CHAR    szUploadtime[IMOS_TIME_LEN];

    /** 备份录像文件全路径，查询列表时由服务器返回 */
    //CHAR    szFilePath[IMOS_FILE_MAXNUM_PER_CASERECORD][IMOS_FILE_PATH_LEN];

    /** 解码插件类型 */
    CHAR szDecoderTag[IMOS_STRING_LEN_64];

}CASE_RECORD_LIST_INFO_S;

/**
* @struct tagCaseFileInfo
* @brief 案件关联文件信息结构
* @attention
*/
typedef struct tagCaseFileInfo
{
    /** 文件编码 */
    CHAR    szFileCode[IMOS_CODE_LEN];

    /** 文件名 */
    CHAR    szFileName[IMOS_FILE_NAME_LEN];

    /** 文件类型,取值#CASE_FILE_TYPE_E */
    ULONG_32    ulFileType;

    /** 文件大小 */
    ULONG_32    ulFileSize;

    /** 密级，取值#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** 上传用户 */
    CHAR    szUploadUser[IMOS_NAME_LEN];

    /** 上传时间 */
    CHAR    szUploadtime[IMOS_TIME_LEN];

    /** 对于其他录像，为录像开始时间
        对案件图片，为拍摄时间 */
    CHAR    szBeginTime[IMOS_TIME_LEN];

    /** 结束时间，用于其他录像*/
    CHAR    szEndTime[IMOS_TIME_LEN];

    /** 拍摄地点--经度 */
    CHAR    szLongitude[IMOS_COORDINATE_LEN];

    /** 拍摄地点--纬度 */
    CHAR    szLatitude[IMOS_COORDINATE_LEN];

    /** 下载服务器IP，查询列表时由服务器返回 */
    CHAR    szDLServerIP[IMOS_IPADDR_LEN];

    /** 文件全路径，查询列表时由服务器返回 */
    CHAR    szFilePath[IMOS_FILE_PATH_LEN];

    /** 图片组编码，文件类型为图片组图片时使用 */
    CHAR    szPicGrpCode[IMOS_CODE_LEN];

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_FILE_INFO_S;

/**
* @struct tagFileDownloadInfo
* @brief 文件下载信息数据结构
*/
typedef struct tagFileDownloadInfo
{
    /** 服务器地址*/
    CHAR    szServerIP[IMOS_IPADDR_LEN];

    /** 文件全路径  */
    CHAR    szFilePath[IMOS_FILE_PATH_LEN];

    /** 备份时间:开始、结束 */
    TIME_SLICE_S stBakTime;

}FILE_DOWNLOAD_INFO_S;

/**
* @struct tagSeriesCaseInfo
* @brief 串并案信息结构
* @attention
*/
typedef struct tagSeriesCaseInfo
{
    /** 串并案类型，取值为#SERIES_CASE_TYPE_E */
    ULONG_32   ulSeriesCaseType;

    /** 串并案编号 */
    CHAR    szSeriesCaseCode[IMOS_CODE_LEN];

    /** 串并案名称 */
    CHAR    szSeriesCaseName[IMOS_NAME_LEN];

    /** 密级，取值#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** 创建人 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 创建时间 */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** 处理人 */
    CHAR    szProPerson[IMOS_NAME_LEN];

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];

    /** 部门编码 */
    CHAR    szDeptCode[IMOS_CODE_LEN];

    /** 部门名称 */
    CHAR    szDeptName[IMOS_NAME_LEN];

    /** 串并案包含的案件实际数量, 最大值为#IMOS_CASE_MAXNUM_PER_SERIESCASE */
    ULONG_32       ulCaseNum;

    /** 案件列表数组 */
    CASE_LIST_INFO_S astCaseList[IMOS_CASE_MAXNUM_PER_SERIESCASE];
}SERIES_CASE_INFO_S;


/**
* @struct tagSeriesCaseList
* @brief 串并案列表信息结构
* @attention
*/
typedef struct tagSeriesCaseList
{
    /** 串并案类型，取值为#SERIES_CASE_TYPE_E */
    ULONG_32   ulSeriesCaseType;

    /** 串并案编号 */
    CHAR    szSeriesCaseCode[IMOS_CODE_LEN];

    /** 串并案名称 */
    CHAR    szSeriesCaseName[IMOS_NAME_LEN];

    /** 创建人 */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** 处理人 */
    CHAR    szProPerson[IMOS_NAME_LEN];

    /** 串并案包含的案件实际数量, 最大值为#IMOS_CASE_MAXNUM_PER_SERIESCASE */
    ULONG_32       ulCaseNum;

    /** 直属部门编码 */
    CHAR    szParDeptCode[IMOS_CODE_LEN];

    /** 直属部门名称 */
    CHAR    szParDeptName[IMOS_NAME_LEN];
}SERIES_CASE_lIST_S;


/**
* @struct tagCaseShareDstInfo
* @brief 案件共享目标信息结构
* @attention
*/
typedef struct tagCaseShareDstInfo
{
    /** 资源编码 */
    CHAR    szResCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR    szResName[IMOS_NAME_LEN];

    /** 案件共享类型，取值为#CASE_SHARE_TYPE_E */
    ULONG_32   ulShareType;

    /** 直属组织编码 */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** 直属组织名称 */
    CHAR    szParOrgName[IMOS_NAME_LEN];
}CASE_SHAREDST_INFO_S;

/**
* @struct tagElectronicBulletinInfo
* @brief 电子公告信息结构
* @attention
*/
typedef struct tagElectronicBulletinInfo
{
    /** 公告编码 */
    CHAR    szBulletinCode[IMOS_CODE_LEN];

    /** 有效期 */
    ULONG_32    ulExpDate;

    /** 公告内容 */
    CHAR    szContent[IMOS_DESC_LEN];

    /** 发布人 */
    CHAR    szPublisher[IMOS_NAME_LEN];

    /** 发布时间 */
    CHAR    szPubTime[IMOS_TIME_LEN];
}ELECTRONIC_BULLETIN_INFO_S;

/**
* @struct tagCaseProcessStatistic
* @brief 案件处理统计
* @attention
*/
typedef struct tagCaseProcessStatistic
{
    /** 人员名称 */
    CHAR  szUserName[IMOS_NAME_LEN];

    /** 录像关联数量 */
    ULONG_32  ulRecordNum;

    /** 结案数量 */
    ULONG_32  ulClosedNum;

    /** 直属组织编码 */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** 直属组织名称 */
    CHAR    szParOrgName[IMOS_NAME_LEN];

}CASE_PROCESS_STATISTIC_S;

/**
* @struct tagElecBulletinPushUI
* @brief 推送给UI的电子公告变化推送结构
* @attention
*/
typedef struct tagElecBulletinPushUI
{
    /** 电子公告编码 */
    CHAR   szEBCode[IMOS_CODE_LEN];

    /** 电子公告变化类型，0:新增，1:删除 */
    ULONG_32       ulChangeType;

    /** 发布时间 */
    CHAR   szPubTime[IMOS_TIME_LEN];

    /** 公告内容 */
    CHAR    szContent[IMOS_DESC_LEN];

}ELEC_BULLETIN_PUSH_UI_S;

#if 0
#endif

/**
* @struct tagIMOSUploadADDR
* @brief 备份文件上传地址结构
* @attention
*/
typedef struct tagIMOSUploadADDR
{
    /**< 地址类型#IMOS_UPLOAD_ADDR_TYPE_E */
    ULONG_32   ulAddrType;

    /**< 地址内容指针, 由地址类型决定 */
    VOID    *pAddr;

    /**< 地址内容长度, 由地址类型决定, 用于校验 */
    ULONG_32   ulAddrLen;
}IMOS_UPLOAD_ADDR_S;

/* 上传回调函数接口定义, ulUploadRet具体值参考#BP_FILETRANS_ERR_CODE_E */
typedef VOID (* IMOS_UPLOAD_FILE_PF)(IN IMOS_HANDLE hHandle, IN ULONG_32 ulUploadRet, INOUT VOID *pParam);

/**
* @struct tagIMOSUploadOption
* @brief 备份文件上传选项信息结构
* @attention
*/
typedef struct tagIMOSUploadOption
{
    /**< 业务类型#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32   ulServiceType;

    /** 最大传输速率, kbps */
    ULONG_32   ulTransRate;

    /** 最大传输时间, 单位秒 */
    ULONG_32   ulTransTimeout;

    /* 关联的ID, 为DAO_INVALID_IMOSID时表示没有关联任何ID */
    IMOS_ID idIMOSID;

    /* 关联的ID类型#IMOS_ID_TYPE_E */
    ULONG_32   ulIDType;

    /* 回调参数, 用于回调时传入 */
    VOID *pParam;

    /* 上传结束后的回调函数, 提供者需要支持多线程调用, 用户主动取消下载时该接口不被调用 */
    IMOS_UPLOAD_FILE_PF pfnUploadEnd;
}IMOS_UPLOAD_OPTION_S;

/**
* @struct tagIMOSLocalFileInfo
* @brief 准备上传的本地文件信息结构
* @attention
*/
typedef struct tagIMOSLocalFileInfo
{
    /** 本地文件全路径 */
    CHAR    szFilePath[IMOS_FILE_PATH_LEN];

    /** 上传到服务器的地址路径, 可以包括文件名, 为空情况下由服务器指定. 暂不支持 */
    CHAR    szSrvPath[IMOS_FILE_PATH_LEN];

    /** 文件类型,取值#CASE_FILE_TYPE_E */
    ULONG_32   ulFileType;

    ULONG_32   ulFileSubType;

    /* 上传起始偏移量(暂不支持) */
    ULONG_32   ulOffset;

    /** 上传长度(暂不支持, 目前整个文件一起上传) */
    ULONG_32   ulUploadLen;

    /** 备注 */
    CHAR    szNote[IMOS_NOTE_LEN];
}IMOS_LOCAL_FILE_INFO_S;

/**
* @struct tagIMOSUploadFileInfo
* @brief 备份文件上传扩展信息结构, 用于客户端跟文件服务器交互
* @attention
*/
typedef struct tagIMOSUploadFileInfo
{
    /* 文件类型，对于摄像机TS文件，值为0; 对于客户端上传, 值为1 */
    ULONG_32   ulUploadType;

    /**< 业务类型#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32   ulServiceType;

    /* 文件大小, 以字节为单位 */
    DULONG     dulFileSize;

    /* 关联的ID */
    IMOS_ID idIMOSID;

    /* 关联的ID类型#IMOS_ID_TYPE_E */
    ULONG_32   ulIDType;

    /* 仅客户端使用, 用于区分不同的回调 */
    ULONG_32   ulSeq;

    /* 上传后的文件ID, 暂不使用; 需要服务器结束后可以将文件id通过消息返回给客户端结束回调 */
    /* 目前只能根据关联ID或者文件名查询 */
    IMOS_ID idUploadFile;

    /* 用户登录信息 */
    USER_LOGIN_ID_INFO_S stUserLogin;

    /* 目前就按照客户端上传的本地文件名填写, 仅文件名 */
    CHAR    szSrvFilePath[IMOS_FILE_PATH_LEN];
}IMOS_UPLOAD_FILE_INFO_S;


/**
* @struct tagPictureGroupInfo
* @brief 图片组信息结构
* @attention
*/
typedef struct tagPictureGroupInfo
{
    /** 图片组编码，由后台生成带出 */
    CHAR    szPicGrpCode[IMOS_CODE_LEN];

    /** 图片组名称 */
    CHAR    szPicGrpName[IMOS_NAME_LEN];

    /** 密级，取值#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** 案件录像编码 */
    CHAR    szCaseRecCode[IMOS_CODE_LEN];

    /** 图片组描述 */
    CHAR    szPicGrpDesc[IMOS_DESC_LEN];

}PICTURE_GROUP_INFO_S;

/**
* @struct tagDeptInfo
* @brief 部门信息结构
* @attention
*/
typedef struct tagDeptInfo
{
    /** 部门编码 */
    CHAR    szDeptCode[IMOS_CODE_LEN];

    /** 部门名称 */
    CHAR    szDeptName[IMOS_NAME_LEN];

    /** 部门描述 */
    CHAR    szDeptDesc[IMOS_DESC_LEN];

}DEPT_INFO_S;

/**
 * @struct tagCaseInfoAnalysisStat
 * @brief 案件信息分析统计
 * @attention
 */
typedef struct tagCaseInfoAnalysisStat
{
    /** 单位编码 */
    CHAR szDepartmentCode[IMOS_CODE_LEN];

    /** 单位名称 */
    CHAR szDepartmentName[IMOS_NAME_LEN];

    /** 案件总数 */
    ULONG_32 ulCaseTotalNum;

    /** 上传视频数量 */
    ULONG_32 ulCaseVideoNum;

    /** 所有破案的案件的视频总数 */
    ULONG_32 ulEndCaseVideoNum;

    /** 破案的案件总数 */
    ULONG_32 ulEndCaseTotalNum;

    /** 包含视频的破案的案件数量 */
    ULONG_32 ulVideoEndCaselNum;

}CASE_ANALYSIS_STAT_S;
/**
 * @struct tagCaseDepartmentStat
 * @brief 案件信息分部门统计
 * @attention
 */
typedef struct tagCaseDepartmentStat
{
    /** 单位编码 */
    CHAR szDepartmentCode[IMOS_CODE_LEN];

    /** 单位名称 */
    CHAR szDepartmentName[IMOS_NAME_LEN];

    /** 平台录像数量或者包含平台录像的案件数量 */
    ULONG_32 ulIMOSVideoCount;

    /** 上传录像数量或者包含上传录像的案件数量 */
    ULONG_32 ulUploadVideoCount;

    /** 上传图片数量或者包含上传图片的案件数量 */
    ULONG_32 ulUploadPicturCount;

    /** 上传其他数量或者包含上传其他的案件数量 */
    ULONG_32 ulUploadOtherCount;

}CASE_DEPARTMENT_STAT_S;

/**
 * @struct tagCaseUserStat
 * @brief 案件信息分用户统计
 * @attention
 */
typedef struct tagCaseUserStat
{
    /** 单位编码 */
    CHAR szDepartmentCode[IMOS_CODE_LEN];

    /** 单位名称 */
    CHAR szDepartmentName[IMOS_NAME_LEN];

    /** 用户名称 */
    CHAR szUserName[IMOS_NAME_LEN];

    /** 用户全名 */
    CHAR szUserFullName[IMOS_NAME_LEN];

    /** 平台录像数量或者包含平台录像的案件数量 */
    ULONG_32 ulIMOSVideoCount;

    /** 上传录像数量或者包含上传录像的案件数量 */
    ULONG_32 ulUploadVideoCount;

    /** 上传图片数量或者包含上传图片的案件数量 */
    ULONG_32 ulUploadPicturCount;

    /** 上传其他数量或者包含上传其他的案件数量 */
    ULONG_32 ulUploadOtherCount;

    /** 其他分析信息的记录数(嫌疑人，车辆，物品，报警人) */
    ULONG_32 ulCaseItemCount;
}CASE_USER_STAT_S;
/**
 * @struct tagCaseStatFlag
 * @brief 案件信息统计标志位
 * @attention
 */
typedef enum tagCaseStatFlag
{
    /** 按照单位统计案件信息 */
    STAT_DEPARTMENT_CASE_FLAG,

    /** 按照单位统计资料信息 */
    STAT_DEPARTMENT_DATA_FLAG,

    /** 按照用户统计案件信息 */
    STAT_USER_CASE_FLAG,

    /** 按照用户统计案件信息 */
    STAT_USER_DATA_FLAG,

    STAT_FLAG_INVAILD = 0XFFFF
}CASE_STAT_FLAG_S;

/* added by z06806 for tollgate struct */
/**
 * @struct tagReservedInfo
 * @brief 预留字段结构
 * @attention
 */
typedef struct tagReservedInfo
{
    /** 预留字段1:已使用，用于表示触发原因 */
    ULONG_32 ulReserved1;

    /** 预留字段2 */
    ULONG_32 ulReserved2;

    /** 预留字段3 */
    ULONG_32 ulReserved3;

    /** 预留字段4 */
    CHAR szReserved4[IMOS_RESERVED_LEN];

    /** 预留字段5 */
    CHAR szReserved5[IMOS_RESERVED_LEN];

    /** 预留字段6 */
    CHAR szReserved6[IMOS_RESERVED_LEN];
} RESERVED_INFO_S;

/**
 * @struct tagVehicleAlarmData
 * @brief 车辆报警记录
 * @attention
 */
typedef struct tagVehicleAlarmData
{
    /** 车辆报警信息编号 */
    CHAR  szVehicleAlarmCode[IMOS_CODE_LEN];

    /** 车辆信息编号，查询返回，其他情况下可以不填 */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** 互联类型，取值为DISPOSITION_INTER_TYPE_LOCAL或者DISPOSITION_INTER_TYPE_LOWER */
    ULONG_32 ulInterType;

    /** 卡口编号，查询返回，其他情况下可以不填 */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称，查询返回，其他情况下可以不填 */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** 车道号，查询返回，其他情况下可以不填 */
    ULONG_32 ulLaneNumber;

    /** 行驶方向编号，已废弃 */
    ULONG_32 ulDirection;

    /** 行驶方向名称，已废弃 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** 通过时间/告警类别为区间测速告警时，为驶入卡口时间 */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** 号牌数量 */
    ULONG_32 ulLicensePlateNum;

    /** 号牌号码 */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** 号牌种类，参考数据字典 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆速度，单位Km/h，告警类别为区间测速告警时，为区间平均行驶速度 */
    ULONG_32 ulVehicleSpeed;

    /** 标示限速，单位Km/h，查询返回，其他情况下可以不填 */
    ULONG_32 ulMarkedSpeed;

    /** 车道限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 车辆品牌，参考数据字典 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车长，单位: 厘米 */
    ULONG_32 ulVehicleLen;

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 告警类别，参考#VEHICLE_ALARM_TYPE_E */
    ULONG_32 ulAlarmType;

    /** 根据告警类别填写，如果是布控报警，则为布控编号，如果是黑名单报警，则为黑名单编号。如果是其他，则为空 */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** 布控类别，参考数据字典，布控报警才有值，否则为空 */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** 报警时间，告警类别为区间测速告警时，为驶出卡口时间 */
    CHAR  szAlarmTime[IMOS_TIME_LEN];

    /** 处理标记，参考#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** 图像数量 */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of 卡口三期 */
    /** 图像名称(包含路径)列表，告警类别为区间测速告警时，第0张图片为合成图片，第1张图片为驶入图片，第2张图片为驶出图片 */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** 告警类别为区间测速告警时，为区间编码，其他情况为空 */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** 告警类别为区间测速告警时，为区间名称，其他情况为空 */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口编号，其他情况为空 */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口名称，其他情况为空 */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口车道号，其他情况为0 */
    ULONG_32 ulLaneNumber2;

    /** 告警类别为区间测速告警时，为驶出卡口行驶方向编号，已废弃 */
    ULONG_32 ulDirection2;

    /** 告警类别为区间测速告警时，为驶出卡口行驶方向名称，其他情况为空 */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口时间，否则等于szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** 告警类别为区间测速告警时，为区间距离，单位:米，其他情况为0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of 卡口三期 */

    /** 是否为外域图片，1:外域图片; 0:本域图片，按比特位从低到高，每个比特位表示一张图片
    aszImgList:1 ~ 4, 车牌彩色特征图片:5, 车牌二值化特征图片:6, 驾驶室特征图片:7, 副驾驶室特征图片:8, 车标特征图片:9 */
    ULONG_32 ulIsForeign;

    /** 违章地点编码 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** 违章地点名称 */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** 采集设备类型 */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 校对用户编码 */
    CHAR szCorrectUserCode[IMOS_CODE_LEN];

    /** 校对时间 */
    CHAR szCorrectTime[IMOS_TIME_LEN];

    /** 处理用户编码 */
    CHAR szDoneUserCode[IMOS_CODE_LEN];

    /** 处理时间 */
    CHAR szDoneTime[IMOS_TIME_LEN];

    /** 采集机关编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 采集机关名称 */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** 更新时间 */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** 行驶方向,告警类别为区间测速告警时，为驶入卡口行驶方向 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶方向2,通常等于szDirection,告警类别为区间测速告警时，为驶出卡口行驶方向 */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌坐标 */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** 车标坐标 */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** 合成图片标识，BOOL_TRUE:aszImgList[0]为合成图片，BOOL_FALSE:无合成图片 */
    ULONG_32 ulCombineFlag;

    /** 号牌置信度，取值范围[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** 尾部号牌置信度，取值范围[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** 车辆重量，单位kg */
    ULONG_32 ulVehicleWeight;

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 支持毫秒 */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime 支持毫秒 */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** 报警时间，告警类别为区间测速告警时，为驶出卡口时间 支持毫秒 */
    CHAR  szAlarmTimeEx[IMOS_TIME_LEN];

    /** 预留字段 */
    CHAR szReserve[64];

} VEHICLE_ALARM_DATA_S;

/**
 * @struct tagVehicleAlarmDataV2
 * @brief 车辆报警记录V2，内部使用
 * @attention
 */
typedef struct tagVehicleAlarmDataV2
{
    /** 车辆报警信息编号 */
    CHAR  szVehicleAlarmCode[IMOS_CODE_LEN];

    /** 车辆信息编号，查询返回，其他情况下可以不填 */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** 互联类型，取值为DISPOSITION_INTER_TYPE_LOCAL或者DISPOSITION_INTER_TYPE_LOWER */
    ULONG_32 ulInterType;

    /** 卡口编号，查询返回，其他情况下可以不填 */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称，查询返回，其他情况下可以不填 */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** 车道号，查询返回，其他情况下可以不填 */
    ULONG_32 ulLaneNumber;

    /** 行驶方向编号，已废弃 */
    ULONG_32 ulDirection;

    /** 行驶方向名称，已废弃 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** 通过时间/告警类别为区间测速告警时，为驶入卡口时间 */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** 号牌数量 */
    ULONG_32 ulLicensePlateNum;

    /** 号牌号码 */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** 号牌种类，参考数据字典 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆速度，单位Km/h，告警类别为区间测速告警时，为区间平均行驶速度 */
    ULONG_32 ulVehicleSpeed;

    /** 标示限速，单位Km/h，查询返回，其他情况下可以不填 */
    ULONG_32 ulMarkedSpeed;

    /** 车道限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 车辆品牌，参考数据字典 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车长，单位: 厘米 */
    ULONG_32 ulVehicleLen;

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 告警类别，参考#VEHICLE_ALARM_TYPE_E */
    ULONG_32 ulAlarmType;

    /** 根据告警类别填写，如果是布控报警，则为布控编号，如果是黑名单报警，则为黑名单编号。如果是其他，则为空 */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** 布控类别，参考数据字典，布控报警才有值，否则为空 */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** 报警时间，告警类别为区间测速告警时，为驶出卡口时间 */
    CHAR  szAlarmTime[IMOS_TIME_LEN];

    /** 处理标记，参考#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** 图像数量 */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of 卡口三期 */
    /** 图像名称(包含路径)列表，告警类别为区间测速告警时，第0张图片为合成图片，第1张图片为驶入图片，第2张图片为驶出图片 */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** 告警类别为区间测速告警时，为区间编码，其他情况为空 */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** 告警类别为区间测速告警时，为区间名称，其他情况为空 */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口编号，其他情况为空 */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口名称，其他情况为空 */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口车道号，其他情况为0 */
    ULONG_32 ulLaneNumber2;

    /** 告警类别为区间测速告警时，为驶出卡口行驶方向编号，已废弃 */
    ULONG_32 ulDirection2;

    /** 告警类别为区间测速告警时，为驶出卡口行驶方向名称，其他情况为空 */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** 告警类别为区间测速告警时，为驶出卡口时间，否则等于szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** 告警类别为区间测速告警时，为区间距离，单位:米，其他情况为0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of 卡口三期 */

    /** 是否为外域图片，1:外域图片; 0:本域图片，按比特位从低到高，每个比特位表示一张图片
    aszImgList:1 ~ 4, 车牌彩色特征图片:5, 车牌二值化特征图片:6, 驾驶室特征图片:7, 副驾驶室特征图片:8, 车标特征图片:9 */
    ULONG_32 ulIsForeign;

    /** 违章地点编码 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** 违章地点名称 */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** 采集设备类型 */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 校对用户编码 */
    CHAR szCorrectUserCode[IMOS_CODE_LEN];

    /** 校对时间 */
    CHAR szCorrectTime[IMOS_TIME_LEN];

    /** 处理用户编码 */
    CHAR szDoneUserCode[IMOS_CODE_LEN];

    /** 处理时间 */
    CHAR szDoneTime[IMOS_TIME_LEN];

    /** 采集机关编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 采集机关名称 */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** 更新时间 */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** 行驶方向,告警类别为区间测速告警时，为驶入卡口行驶方向 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶方向2,通常等于szDirection,告警类别为区间测速告警时，为驶出卡口行驶方向 */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌坐标 */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** 车标坐标 */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** 合成图片标识，BOOL_TRUE:aszImgList[0]为合成图片，BOOL_FALSE:无合成图片 */
    ULONG_32 ulCombineFlag;

    /** 车牌彩色特征图片 */
    CHAR szPlatePic[IMOS_URL_LEN];

    /** 车牌二值化特征图片 */
    CHAR szBinaryPlatePic[IMOS_URL_LEN];

    /** 驾驶室特征图片 */
    CHAR szDriveCabPic[IMOS_URL_LEN];

    /** 副驾驶室特征图片 */
    CHAR szAssistDriveCabPic[IMOS_URL_LEN];

    /** 车标特征图片 */
    CHAR szVehicleLogoPic[IMOS_URL_LEN];

    /** 关联录像地址 */
    CHAR szRelateVideoAddr[IMOS_URL_LEN];

    /** 号牌置信度，取值范围[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** 尾部号牌置信度，取值范围[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** 车辆重量，单位kg */
    ULONG_32 ulVehicleWeight;

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 支持毫秒 */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime 支持毫秒 */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** 报警时间，告警类别为区间测速告警时，为驶出卡口时间 支持毫秒 */
    CHAR  szAlarmTimeEx[IMOS_TIME_LEN];

    /** 预留字段 */
    CHAR szReserve[156];

} VEHICLE_ALARM_DATA_V2_S;

/**
 * @struct tagVehicleData
 * @brief 车辆行驶记录
 * @attention
 */
typedef struct tagVehicleData
{
    /** 车辆信息编号 */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编号，查询返回，其他情况下可以不填 */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称，查询返回，其他情况下可以不填 */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** 车道号，查询返回，其他情况下可以不填 */
    ULONG_32 ulLaneNumber;

    /** 行驶方向编号，已废弃 */
    ULONG_32 ulDirection;

    /** 行驶方向名称，已废弃 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** 号牌数量 */
    ULONG_32 ulLicensePlateNum;

    /** 号牌号码 */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** 号牌种类，参考数据字典 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆速度，单位Km/h */
    ULONG_32 ulVehicleSpeed;

    /** 标示限速，单位Km/h，查询返回，其他情况下可以不填 */
    ULONG_32 ulMarkedSpeed;

    /** 车道限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 车辆品牌，参考数据字典 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车长，单位: 厘米 */
    ULONG_32 ulVehicleLen;

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 识别时间，单位: 毫秒 */
    ULONG_32 ulIdentifyTime;

    /** 识别状态，参考#VEHICLE_IDENTIFY_STATUS_E */
    ULONG_32 ulIdentifyStatus;

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 处理标记，参考#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** 图像数量 */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of 卡口三期 */
    /** 图像名称(包含路径)列表，过车数据类型为区间测速时，第0张图片为驶入图片，第1张图片为驶出图片 */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** 过车数据类型，参考#VEHICLE_RECORD_TYPE_E */
    ULONG_32 ulVehicleDataType;

    /** 过车数据类型为区间测速时，为区间编号，其他情况为空 */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** 过车数据类型为区间测速时，为区间名称，其他情况为空 */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口编号，其他情况为空 */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口名称，其他情况为空 */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口车道号，其他情况为0 */
    ULONG_32 ulLaneNumber2;

    /** 过车数据类型为区间测速时，为驶出卡口行驶方向编号，已废弃 */
    ULONG_32 ulDirection2;

    /** 过车数据类型为区间测速时，为驶出卡口行驶方向名称，其他情况为空 */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为区间距离，单位:米，其他情况为0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of 卡口三期 */

    /** 是否为外域图片，1:外域图片; 0:本域图片，按比特位从低到高，每个比特位表示一张图片
    aszImgList:1 ~ 4, 车牌彩色特征图片:5, 车牌二值化特征图片:6, 驾驶室特征图片:7, 副驾驶室特征图片:8, 车标特征图片:9 */
    ULONG_32 ulIsForeign;

    /** 地点编码 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** 地点名称 */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** 采集类型 */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 采集机关编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 采集机关名称 */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** 更新时间 */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** 行驶方向,告警类别为区间测速告警时，为驶入卡口行驶方向 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶方向2,通常等于szDirection,告警类别为区间测速告警时，为驶出卡口行驶方向 */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌坐标 */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** 车标坐标 */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** 号牌置信度，取值范围[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** 尾部号牌置信度，取值范围[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** 车辆重量，单位kg */
    ULONG_32 ulVehicleWeight;

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 支持毫秒 */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime 支持毫秒 */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** 预留字段 */
    CHAR szReserve[100];
} VEHICLE_DATA_S;


/**
 * @struct tagVehicleDataV2
 * @brief 车辆行驶记录V2，内部使用
 * @attention
 */
typedef struct tagVehicleDataV2
{
    /** 车辆信息编号 */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** 卡口编号，查询返回，其他情况下可以不填 */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** 卡口名称，查询返回，其他情况下可以不填 */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** 车道号，查询返回，其他情况下可以不填 */
    ULONG_32 ulLaneNumber;

    /** 行驶方向编号，已废弃 */
    ULONG_32 ulDirection;

    /** 行驶方向名称，已废弃 */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** 号牌数量 */
    ULONG_32 ulLicensePlateNum;

    /** 号牌号码 */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** 号牌种类，参考数据字典 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆速度，单位Km/h */
    ULONG_32 ulVehicleSpeed;

    /** 标示限速，单位Km/h，查询返回，其他情况下可以不填 */
    ULONG_32 ulMarkedSpeed;

    /** 车道限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 车辆品牌，参考数据字典 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车长，单位: 厘米 */
    ULONG_32 ulVehicleLen;

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 识别时间，单位: 毫秒 */
    ULONG_32 ulIdentifyTime;

    /** 识别状态，参考#VEHICLE_IDENTIFY_STATUS_E */
    ULONG_32 ulIdentifyStatus;

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 处理标记，参考#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** 图像数量 */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of 卡口三期 */
    /** 图像名称(包含路径)列表，过车数据类型为区间测速时，第0张图片为驶入图片，第1张图片为驶出图片 */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** 过车数据类型，参考#VEHICLE_RECORD_TYPE_E */
    ULONG_32 ulVehicleDataType;

    /** 过车数据类型为区间测速时，为区间编号，其他情况为空 */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** 过车数据类型为区间测速时，为区间名称，其他情况为空 */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口编号，其他情况为空 */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口名称，其他情况为空 */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口车道号，其他情况为0 */
    ULONG_32 ulLaneNumber2;

    /** 过车数据类型为区间测速时，为驶出卡口行驶方向编号，已废弃 */
    ULONG_32 ulDirection2;

    /** 过车数据类型为区间测速时，为驶出卡口行驶方向名称，其他情况为空 */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为区间距离，单位:米，其他情况为0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of 卡口三期 */

    /** 是否为外域图片，1:外域图片; 0:本域图片，按比特位从低到高，每个比特位表示一张图片
    aszImgList:1 ~ 4, 车牌彩色特征图片:5, 车牌二值化特征图片:6, 驾驶室特征图片:7, 副驾驶室特征图片:8, 车标特征图片:9 */
    ULONG_32 ulIsForeign;

    /** 地点编码 */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** 地点名称 */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** 采集类型 */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 采集机关编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 采集机关名称 */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** 更新时间 */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** 行驶方向,告警类别为区间测速告警时，为驶入卡口行驶方向 */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** 行驶方向2,通常等于szDirection,告警类别为区间测速告警时，为驶出卡口行驶方向 */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** 车牌坐标 */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** 车标坐标 */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** 车牌彩色特征图片 */
    CHAR szPlatePic[IMOS_URL_LEN];

    /** 车牌二值化特征图片 */
    CHAR szBinaryPlatePic[IMOS_URL_LEN];

    /** 驾驶室特征图片 */
    CHAR szDriveCabPic[IMOS_URL_LEN];

    /** 副驾驶室特征图片 */
    CHAR szAssistDriveCabPic[IMOS_URL_LEN];

    /** 车标特征图片 */
    CHAR szVehicleLogoPic[IMOS_URL_LEN];

    /** 关联录像地址 */
    CHAR szRelateVideoAddr[IMOS_URL_LEN];

    /** 号牌置信度，取值范围[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** 尾部号牌置信度，取值范围[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** 车辆重量，单位kg */
    ULONG_32 ulVehicleWeight;

    /** 通过时间/过车数据类型为区间测速时，为驶入卡口时间 支持毫秒 */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** 过车数据类型为区间测速时，为驶出卡口时间，否则等于szPassTime 支持毫秒 */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** 预留字段 */
    CHAR szReserve[188];
} VEHICLE_DATA_V2_S;

/**
 * @struct tagVehicleRealTimeData
 * @brief 车辆实时显示记录
 * @attention
 */
typedef struct tagVehicleRealTimeData
{
    /** XP窗格编码 */
    CHAR szXPWinCode[IMOS_CODE_LEN];

    /** 相机编码 */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /** 车辆基本信息 */
    VEHICLE_DATA_S stVehicleData;
}VEHICLE_REAL_TIME_DATA_S;

/**
 * @struct tagDeviceGISStatusData
 * @brief 设备GIS状态信息
 * @attention
 */
typedef struct tagDeviceGISStatusData
{
    /** 设备编码 */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** 设备故障状态，参考#DEVICE_GIS_STATUS_E */
    ULONG_32 ulDevStatus;
}DEVICE_GIS_STATUS_DATA_S;


/**
* @struct tagNeighborCameraInfo
* @brief 周边摄像机位置信息结构
* @attention
*/
typedef struct tagNeighborCameraInfo
{
    /** 摄像机编码 */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** 经度 */
    CHAR    szLongitude[IMOS_COORDINATE_LEN];

    /** 纬度 */
    CHAR    szLatitude[IMOS_COORDINATE_LEN];

    /** 摄像机类型, 取值为#CAMERA_TYPE_E */
    ULONG_32    ulCameraType;

    /** 当前距离，单位:m */
    ULONG_32    ulDistance;

    /** 当前方位，取1~12点钟方向 */
    ULONG_32    ulAzimuth;

}NEIGHBOR_CAMERA_INFO_S;

/**
 * @struct tagWebGisScaleInfo
 * @brief WebGIS 地图比例尺信息
 * @attention
 */
typedef struct tagWebgisScaleInfo
{
    /** 比例尺ID */
    ULONG_32 ulScaleID;

    /** 比例尺名称 */
    CHAR    szScaleName[IMOS_NAME_LEN];

    /** 比例尺层级 */
    ULONG_32   ulScaleNum;

    /** 比例尺的内容，存放格式"100,200"，单位是米  */
    CHAR    szScaleInfo[256];

}WEBGIS_SCALE_INFO_S;

/**
 * @struct tagWebGisBaseInfo
 * @brief WebGIS 地图信息
 * @attention
 */
typedef struct tagWebGisBaseInfo
{
    /** 地图编码 */
    CHAR        szGISCode[IMOS_CODE_LEN];

    /** 地图名称 */
    CHAR        szGISName[IMOS_NAME_LEN];

    /** 是否是第三方地图，1:第三方地图，0:非第三方地图 */
    BOOL_T      bIsThirdParty;

    /** 地图类型，取值#WEBGIS_MAP_TYPE */
    ULONG_32       ulGisMapType;

    /** 默认地图标记位，1:默认地图，0:非默认地图 */
    BOOL_T      bIsDefaultMap;

    /** Map服务URL */
    CHAR        szMapServiceUrl[IMOS_URL_LEN];

    /** Feature服务URL,可不填，用于查询第三方要素 */
    CHAR        szFeatureSrvUrl[IMOS_URL_LEN];

    /** 图层名称 */
    CHAR        szBaseLayerName[IMOS_WEBGIS_LAYER_NAME_LEN];

    /** .map文件Name */
    CHAR        szConfigName[IMOS_NAME_LEN];

    /** 配色方案 */
    CHAR        szColorScheme[IMOS_DESC_LEN];

    /** 地图最小经度 */
    CHAR        szMinLongitude [IMOS_COORDINATE_LEN];

    /** 地图最小纬度 */
    CHAR        szMinlatitude [IMOS_COORDINATE_LEN];

    /** 地图最大经度 */
    CHAR        szMaxLongitude [IMOS_COORDINATE_LEN];

    /** 地图最大纬度 */
    CHAR        szMaxlatitude [IMOS_COORDINATE_LEN];

    /** TMS地图比例尺ID */
    ULONG_32       ulTmsScaleID;

    /** 保留字段 */
    CHAR        szReserve[252];
}WEBGIS_BASE_INFO_S;


/**
 * @struct tagWebGisAttentivePoint
 * @brief WebGIS 关注点信息
 * @attention
 */
typedef struct tagWebGisAttentivePoint
{
    /** 关注点编码 */
    CHAR    szPointCode[IMOS_CODE_LEN];

    /** 关注点名称 */
    CHAR    szPointName[IMOS_NAME_LEN];

    /** 是否是默认点，1:默认点，0:非默认点 */
    BOOL_T  bIsDefaultPoint;

    /** 所属地图编码 */
    CHAR    szGisCode[IMOS_CODE_LEN];

    /** 经度 */
    CHAR    szLongitude [IMOS_COORDINATE_LEN];

    /** 纬度 */
    CHAR    szlatitude [IMOS_COORDINATE_LEN];

    /** 缩放级别 */
    ULONG_32   ulZoomLevel;

    /** 描述 */
    CHAR    szPointDesc[IMOS_DESC_LEN];

    /** 保留字段 */
    CHAR    szReserve[128];

}WEBGIS_ATTENTIVE_POINT_S;


/**
* @struct tagCommunityCameraInfo
* @brief 社会摄像机资源信息结构
* @attention
*/
typedef struct tagCommunityCameraInfo
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** 摄像机类型，取值为#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** 摄像机使用状态，取值为#COMMUNITY_CAMERA_STATUS_E */
    ULONG_32   ulCameraStatus;

    /** 摄像机直属组织编码 */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** 摄像机直属组织名称 */
    CHAR    szParOrgName[IMOS_NAME_LEN];

    /** 摄像机型号 */
    CHAR    szCameraModel[IMOS_NAME_LEN];

    /** 摄像机厂商 */
    CHAR    szManufacturer[IMOS_NAME_LEN];

    /** 安装地点 */
    CHAR    szLocation[IMOS_STRING_LEN_256];

    /** 所属单位 */
    CHAR    szDepartment[IMOS_NAME_LEN];

    /** 摄像机归属联系人名称 */
    CHAR    szMPerson[IMOS_NAME_LEN];

    /** 摄像机归属联系电话 */
    CHAR    szTelephone[IMOS_PHONE_LEN];

    /** 经度 */
    CHAR    szLongitude[IMOS_COORDINATE_LEN];

    /** 纬度 */
    CHAR    szLatitude[IMOS_COORDINATE_LEN];

    /** 海拔 */
    CHAR    szaltitude[IMOS_COORDINATE_LEN];

    /** 解码插件类型 */
    CHAR szDecoderTag[IMOS_STRING_LEN_64];

    /** 指向 */
    CHAR    szDirection[IMOS_STRING_LEN_32];

    /** 视角 */
    CHAR    szViewAngle[IMOS_STRING_LEN_32];

    /** 可视距离 */
    CHAR    szVisibleRange[IMOS_STRING_LEN_32];

}COMMUNITY_CAMERA_INFO_S;

/**
* @struct tagDatabaseInfo
* @brief 数据库信息
* @attention
*/
typedef struct tagDatabaseInfo
{
    /** 数据库IP地址 */
    CHAR    szDatabaseIp[IMOS_IPADDR_LEN];

    /** 数据库名称 */
    CHAR    szDatabaseName[IMOS_NAME_LEN];

    /** 数据库端口 */
    ULONG_32   ulPort;

    /** 数据库用户 */
    CHAR    szUser[IMOS_NAME_LEN];

    /** 数据库密码 */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** 数据库的类型:"SQLServer";"Oracle","PostgreSQL";"Sqlite" */
    CHAR    szDBType[IMOS_NAME_LEN];

    /** 保留字段 */
    CHAR    szReserve[256];
}DATABASE_INFO_S;

/**
* @struct tagCameraViewInfo
* @brief 摄像机的视角信息
* @attention
*/
typedef struct tagCameraViewInfo
{
    /** 摄像机编码 */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /** 指向 */
    CHAR    szDirection[IMOS_STRING_LEN_32];

    /** 视角 */
    CHAR    szViewAngle[IMOS_STRING_LEN_32];

    /** 可视距离 */
    CHAR    szVisibleRange[IMOS_STRING_LEN_32];
}CAMERA_VIEW_INFO_S;

 /**
 * @struct tagCenterStoreActionInfo
 * @brief 配置模块发给外域联动中心域存储动作信息结构
 * @attention
 */
typedef struct tagCenterStoreActionInfo
{
    /** 告警源编码 */
    CHAR    szAlarmSrcCode[IMOS_CODE_LEN];

    /** 告警类型 */
    ULONG_32   ulAlarmType;

    /** 消息总个数 */
    ULONG_32 ulTotalNum;

    /** 第几个消息 */
    ULONG_32 ulCurrentNum;

    /** 存储动作数组中存储动作的实际数目, 取值最大值为#IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM */
    ULONG_32  ulCenterStoreActionNum;

    /** 中心域存储动作数组 */
    STORE_ACTION_S  astCenterStoreAction[IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM];

}CENTER_STORE_ACTION_INFO_S;

/**
* @struct tagThirdDeviceError
* @brief 第三方设备错误结构
* @attention
*/
typedef  struct  tagThirdDeviceError
{
    /** 错误源编码 */
    CHAR    szDevCode[IMOS_CODE_LEN];

    /** 错误源名 */
    CHAR    szDevName[IMOS_NAME_LEN];

    /** 错误时间 */
    CHAR   szTime[IMOS_TIME_LEN];

    /** 其他描述 */
    CHAR  szDesc[IMOS_DESC_LEN];
}THIRD_DEVICE_ERROR_S;

/**
* @struct tagMgSessionStatusEx
* @brief 摄像机存储资源释放上报结构
* @attention
*/
typedef struct tagFreeStoreResSucceed
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_CODE_LEN];
}FREE_STORE_RES_SUCCEED_S;

/**
 * @struct tagLinkWallLabel
 * @brief 告警联动上墙标注信息
 * @attention
 */
typedef struct tagLinkWallLabel
{
    /** 启动标注，0为不启用，1为启用 */
    ULONG_32 ulEnabledFlag;

    /** 场名OSD内容*/
    CHAR szOsdString[IMOS_NAME_LEN];

    /** 场名OSD区域坐标 */
    AREA_SCOPE_S stAreaScope;

    /** OSD颜色, 取值为#IMOS_OSD_COLOR_E */
    ULONG_32 ulOsdColor;

    /**切换时间, 单位为秒, 取值为0~300。取值为0, 不闪烁*/
    ULONG_32 ulSwitchIntval;

    /** 预留字段 */
    CHAR szReserve[128];
} LINK_WALL_LABEL_INFO_S;


/**
 * @struct  tagAlarmLinkageStoreInfo
 * @brief 告警联动录像存储信息
 * @attention
 */
typedef struct tagAlarmLinkageStoreInfo
{
    /** 开始存储时间 */
    CHAR    szBeginStoreTime[IMOS_TIME_LEN];

    /** 告警源编码 */
    CHAR    szAlarmSrcCode[IMOS_CODE_LEN];

    /** 保留字段 */
    CHAR    szReserved[128];
}ALARM_LINKAGE_STORE_INFO_S;

/**
 * @struct  tagExDomainCamStoreInfo
 * @brief 外域摄像机录像存储信息
 * @attention
 */
typedef struct tagExDomainCamStoreInfo
{
    /** 摄像机编码 */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /** 摄像机名称 */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** 录像存储是否存在 */
    BOOL_T  bStoreExist;

    /** 保留字段 */
    CHAR    szReserved[128];
}EXDOMAIN_CAM_STORE_INFO_S;

/**
* @struct tagIpAddressInfo
* @brief 用户登录限制IP地址结构
* @attention
*/
typedef struct tagIpAddressInfo
{
    /** 地址类型，#IMOS_IPADDR_TYPE_IPV4为IPv4类型; #IMOS_IPADDR_TYPE_IPV6为IPv6类型 */
    ULONG_32 ulIpAddrType;

    /** 起始IP地址 */
    CHAR szStartIpAddress[IMOS_IPADDR_LEN];

    /** 结束IP地址，如果只有一个地址，则为空 */
    CHAR szEndIpAddress[IMOS_IPADDR_LEN];
}IP_ADDRESS_INFO_S;

/**
* @struct tagMacAddressInfo
* @brief 用户登录限制MAC地址结构
* @attention
*/
typedef struct tagMacAddressInfo
{
    /** MAC地址 */
    CHAR szMacAddress[IMOS_MAC_ADDR_LEN];
}MAC_ADDRESS_INFO_S;

/**
* @struct tagLoginExtInfo
* @brief 用户登录扩展信息
* @attention
*/
typedef struct tagLoginExtInfo
{
    /** IP地址 */
    CHAR szIpAddress[IMOS_IPADDR_LEN];

    /** MAC地址数量 */
    ULONG_32 ulOperMachineMacNum;

    /** MAC地址列表 */
    MAC_ADDRESS_INFO_S astOperMachineMac[IMOS_MAX_LOGIN_ADDRESS_NUM];

    /** 用户登录名类型, 区分是用户名称/用户编码, 取值#USER_LOGIN_NAME_TYPE */
    ULONG_32 ulLoginNameType;

    /** 用户前端的类型 取值#USER_CLIENT_TYPE_E */
    ULONG_32 ulLoginType;

    /** 操作系统类型 保留 */
    ULONG_32 ulOSType;

    /** 保留字段 */
    CHAR  szReserve[116];
}LOGIN_EXT_INFO_S;

/**
* @struct tagUserLoginBindInfo
* @brief 用户登录限制绑定信息
* @attention
*/
typedef struct tagUserLoginBindInfo
{
    /** 是否允许多点登录, #BOOL_TRUE时允许; #BOOL_FALSE时不允许 */
    BOOL_T bAllowLoginAtSameTime;

    /** 是否绑定IP, #BOOL_TRUE时绑定; #BOOL_FALSE时不绑定 */
    BOOL_T bBindIP;

    /** IP地址数量 */
    ULONG_32 ulOperMachineIpNum;

    /** IP地址列表 */
    IP_ADDRESS_INFO_S astOperMachineIp[IMOS_MAX_BINDING_ADDRESS_NUM];

    /** 是否绑定MAC, #BOOL_TRUE时绑定; #BOOL_FALSE时不绑定 */
    BOOL_T bBindMac;

    /** MAC地址数量 */
    ULONG_32 ulOperMachineMacNum;

    /** MAC地址列表 */
    MAC_ADDRESS_INFO_S astOperMachineMac[IMOS_MAX_BINDING_ADDRESS_NUM];

    /** 绑定策略 1: 使用全局配置 2: 使用自身配置 3: 不做任何限制 */
    ULONG_32 ulBindPolicy;

    /** 保留字段 */
    CHAR  szReserve[128];
}USER_LOGIN_BIND_INFO_S;

/**
* @struct tagXpLayoutInfo
* @brief XP窗格布局信息
* @attention
*/
typedef struct tagXpLayoutInfo
{
    /** 布局编码 */
    CHAR szXpLayoutCode[IMOS_CODE_LEN];

    /** 布局描述字符串 */
    CHAR szXpLayoutDesc[IMOS_XP_LAYOUT_DESC_LEN];

    /** 预留字段 */
    CHAR  szReserved[128];
}XP_LAYOUT_INFO_S;

/**
* @struct tagMediaStatusNotify
* @brief 媒体状态通知消息
* @attention
*/
typedef struct tagMediaStatusNotify
{
    ULONG_32 ulReleaseCode;            /* 释放原因 */
    CHAR szSrcUAID[IMOS_UAID_LEN];  /* 源UAID */
    CHAR szDstUAID[IMOS_UAID_LEN];  /* 目的UAID */
}MEDIA_STATUS_NOTIFY_S;

/**
* @struct tagSerialAllInfoQueryItem
* @brief 定义所有设备串口信息查询列表结构体 for UI 界面调整特性
* @attention 无
*/
typedef struct tagSerialAllInfoQueryItem
{
    /** 串口索引 */
    ULONG_32   ulSerialIndex;

    /** 串口类型 */
    ULONG_32   ulSerialType;

    /* 串口模式 */
    ULONG_32       ulSerialMode;

    /* 所属设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备编码 */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /* 设备类型 */
     ULONG_32 ulDevType;

     /* 设备子类型 */
     ULONG_32 ulSubDevType;

     /* 保留字段0 */
     ULONG_32 ulSpare0;

     /* 设备字段1 */
     ULONG_32 ulSpare1;
}SERIAL_ALLINFO_QUERY_ITEM_S;

/**
* @struct tagSemaOutAllInfoQueryItem
* @brief 定义所有设备输出开关量信息查询列表结构体for UI 界面调整特性
* @attention 无
*/
typedef struct tagSemaOutAllInfoQueryItem
{
     /** 开关量索引 */
    ULONG_32       ulSemaOutputIndex;

    /** 输出开关量状态  */
    ULONG_32       ulSemaOutputStatus;  /* 1表示常开，2表示常闭 */

    /** 是否使能 */
    ULONG_32       ulEnabledFlag;   /* 0表示使能，1表示不使能，对于输出开关量使用填写0 */

    /* 所属设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备编码 */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /* 设备类型 */
     ULONG_32 ulDevType;

     /* 设备子类型 */
     ULONG_32 ulSubDevType;

     /* 保留字段0 */
     ULONG_32 ulSpare0;

     /* 设备字段1 */
     ULONG_32 ulSpare1;

}SEMAOUT_ALLINFO_QUERY_ITEM_S;

/**
* @struct tagSemaInAllInfoQueryItem
* @brief 定义所有设备输入开关量信息查询列表结构体for UI 界面调整特性
* @attention 无
*/
typedef struct tagSemaInAllInfoQueryItem
{
     /** 开关量索引 */
    ULONG_32       ulSemaInputIndex;

    /** 输入开关量状态  */
    ULONG_32       ulSemaInputStatus;  /* 1表示常开，2表示常闭 */

    /** 是否使能 */
    ULONG_32       ulEnabledFlag;   /* 0表示使能，1表示不使能*/

    /* 所属设备名称 */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** 设备编码 */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /* 设备类型 */
     ULONG_32 ulDevType;

     /* 设备子类型 */
     ULONG_32 ulSubDevType;

     /* 保留字段0 */
     ULONG_32 ulSpare0;

     /* 设备字段1 */
     ULONG_32 ulSpare1;

}SEMAIN_ALLINFO_QUERY_ITEM_S;

/**
 * @struct tagSThirdpartyIPC
 * @brief 第三方IPC信息
 * @attention
 */
typedef struct tagThirdpartyIPC
{
    /* 摄像机基本信息 */
    CAMERA_INFO_S  stBaseCameraInfo;

    /* 厂商类型*/
    ULONG_32  ulCameraManutype;

    /* 设备地址*/
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /* 设备端口*/
    ULONG_32  ulDevPort;

    /* 接入类型，0 本地模拟摄像机 1 IPC   */
    ULONG_32  ulCameraAccessType;

    /* 用户名 */
    CHAR szUserName[IMOS_NAME_LEN];

    /* 密码 */
    CHAR szPassword[IMOS_PASSWD_LEN];

    /* 外接DVR通道ID,保留 */
    ULONG_32 ulCameraChnId;

    /* IPC状态，1表示在线，0表示离线 */
    ULONG_32 ulStatus;

    /** 组播地址 */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口,范围为：10002-65534，且必须为偶数 */
    ULONG_32   ulMulticastPort;

    /* Added by zhuhongyan 00342 2013-3-18 for IVSD01426国标完善性特性 */
    /** 最大直连媒体流数目 */
    ULONG_32 ulMaxStreamNum;

    /** 保留字段 */
    CHAR szReserve[24];
} THIRDPARTY_IPC_S;

/**
 * @struct tagECInfoEx
 * @brief EC及下属摄像机相关信息
 * @attention
 */
typedef struct tagECInfoEx
{
    /** EC编码, EC的唯一标识 */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC名称 */
    CHAR  szECName[IMOS_NAME_LEN];

    /** EC类型，取值为#IMOS_DEVICE_TYPE_E, 合法取值参见#ulChannum参数的说明 */
    ULONG_32 ulECType;

    /** EC通道数量:
        几种常见EC类型对应的通道个数如下:
        EC1101(#IMOS_DT_EC1101_HF)/EC1001(#IMOS_DT_EC1001)/EC1001-HF(#IMOS_DT_EC1001_HF): 1
        EC1501(#IMOS_DT_EC1501_HF)/R1000 (#IMOS_DT_R1000) : 1
        EC2004(#IMOS_DT_EC2004_HF)/VR2004(#IMOS_DT_VR2004): 4
        EC1102(#IMOS_DT_EC1102_HF)/VR1102(#IMOS_DT_VR1102): 2
        EC1801(#IMOS_DT_EC1801_HH): 1
        EC2016(#IMOS_DT_EC2016_HC): 16
        EC2016[8CH](#IMOS_DT_EC2016_HC_8CH): 8
        EC2016[4CH](#IMOS_DT_EC2016_HC_4CH): 4
        HIC5201-H(#IMOS_DT_HIC5201)/HIC5221-H(#IMOS_DT_HIC5221): 1
        ECR3308-HF(#IMOS_DT_ECR3308_HF): 8
        ECR3316-HF(#IMOS_DT_ECR3316_HF): 16
    */
    ULONG_32 ulChannum;

    /** 是否支持组播, 1为支持; 0为不支持 */
    ULONG_32 ulIsMulticast;

    /** 低温告警温度上限, 取值为-100~49 */
    LONG_32 lTemperatureMax;

    /** 高温告警温度下限, 取值为50~100 */
    LONG_32 lTemperatureMin;

    /** 告警使能, 1为使能; 0为不使能 */
    ULONG_32 ulEnableAlarm;

    /** EC所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 时间同步方式，默认为1，表示使用H3C的私有同步方式；2表示NTP的同步方式(目前暂不支持) */
    ULONG_32 ulTimeSyncMode;

    /** 时区, 取值为-12~12 */
    LONG_32 lTimeZone;

    /** 语言设置，由中心服务器来配置，取值为:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** 是否启用本地缓存，1表示启用; 0表示不启动，默认值为0 */
    ULONG_32 ulEnableLocalCache;

    /** 流套餐, 取值为:#IMOS_STREAM_RELATION_SET_E
        0：MPEG4+MPEG4(#IMOS_SR_MPEG4_MPEG4)
        1：H264主码流(#IMOS_SR_H264_SHARE)
        2：MPEG2+MPEG4(#IMOS_SR_MPEG2_MPEG4)
        3：H264+MJPEG(#IMOS_SR_H264_MJPEG)
        4：MPEG4主码流(#IMOS_SR_MPEG4_SHARE)
        5：MPEG2主码流(#IMOS_SR_MPEG2_SHARE)
        8: MPEG4主码流_D1(#IMOS_SR_STREAM_MPEG4_8D1)
        9：MPEG2+MPEG2(#IMOS_SR_MPEG2_MPEG2)
        11：H264+H264(#IMOS_SR_H264_H264)
    */
    ULONG_32 ulEncodeSet;

    /** 制式, 取值为#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** 音频输入源，取值为#IMOS_AUDIO_INPUT_SOURCE_E */
    ULONG_32 ulAudioinSource;

    /** 语音对讲资源编码 */
    CHAR szAudioCommCode[IMOS_RES_CODE_LEN];

    /** 语音广播资源编码 */
    CHAR szAudioBroadcastCode[IMOS_RES_CODE_LEN];

    /** 设备访问密码 */
    CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

    /** 设备描述, 目前该字段未使用 */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** EC的IP地址, 添加及修改EC不需填写该参数, 查询EC信息时返回该字段 */
    CHAR szECIPAddr[IMOS_IPADDR_LEN];

    /** EC的在线状态,添加及修改EC不需填写该参数, 查询EC信息时返回该字段, 1为在线; 0为离线 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，取值为#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** 流媒体的协议类型,取值为#IMOS_TRANS_TYPE_E。目前EC只支持UDP和TCP */
    ULONG_32 ulStreamTransProtocol;
    /** 设备版本信息 */
    CHAR szECVer[IMOS_STRING_LEN_64];

    /* 新增加字段，当前EC下的摄像机列表,可以做成最大值（动态分配不大合适，人机上是需要事先分配的） */
    CAM_AND_CHANNEL_QUERY_ITEM_S astCameraInfo[IMOS_CAM_MAX_NUM];

    /** 保留字段 */
    CHAR szReserve[28];

}EC_INFO_EX_S;

/**
*@ struct tagMMIScreenMapInfoForECR
*@ brief 配置人机预览窗格表基本信息结构
*@ attention 对应于表tbl_mmi_preview_window_config
*/
typedef struct tagMMIScreenMapInfoForECR
{
    /** 窗格序号*/
    ULONG_32 ulWindowID;

    /** 摄像机编码*/
    CHAR szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 流标识 1-主流，2-辅流,目前该字段尚未使用,默认主流*/
    ULONG_32 ulStreamFlag;

    /** 保留字段*/
    ULONG_32 ulReserve;

}MMI_SCREEN_MAP_INFO_FOR_ECR_S;

/**
 *@ struct tagMMIVoutWinListInfoForECR
 *@ brief 人机预览窗格摄像机序列信息结构(包含输出端口序号信息)
 *@ attention 无
 */
typedef struct tagMMIVoutWinListInfoForECR
{
    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1开发二期-解码卡 */
    /** 槽位号 */
    ULONG_32 ulSlotID;

    /** 人机输出端口序号,取值参考#MMI_VEDIO_OUT_ID_E */
    ULONG_32 ulMMIVoutID;

    /** 人机预览窗格个数 */
    ULONG_32 ulWindowNum;     /*added by t00764, 2013.2.25 of V5R2 -- IVSD00541 */

    /** 人机预览分屏窗格摄像机序列信息 */
    MMI_SCREEN_MAP_INFO_FOR_ECR_S astMMIScreenMap[IMOS_MAX_WINDOW_NUMBER];

} MMI_VOUT_WINLIST_INFO_FOR_ECR_S;

/**
 *@ struct tagMMIVoutInfoForECR
 *@ brief 人机输出端口表基本信息结构体
 *@ attention  对应表tb1_mmi_vout
 */
typedef struct tagMMIVoutInfoForECR
{
    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1开发二期-解码卡 */
    /** 槽位号 */
    ULONG_32 ulSlotID;

    /** 人机输出端口序号*/
    ULONG_32 ulMMIVoutID;

    /** 分屏模式*/
    ULONG_32 ulSplitScn;

    /** 切换时间*/
    ULONG_32 ulInterval;

    /** 是否启动组切标识*/
    ULONG_32 ulSwitchFlag;

    /** 多屏请求辅流优先标志位,1-辅流优先, 0-主流优先*/
    ULONG_32 ulSubStreamFlag;

    /** 保留字段*/
    ULONG_32 ulReserve;

}MMI_VOUT_INFO_FOR_ECR_S;

/**
*@struct tagVirtualChannelBindStatusForECR
*@biref 虚拟通道绑定状态基本信息结构体
*@attention 对应表 tbl_virtual_channel, tbl_device
*/
typedef struct tagVirtualChannelBindStatusForECR
{
    /** 虚拟通道序号 */
    ULONG_32 ulVirtualChannelID;

    /** 标识位，#BOOL_FALSE-未绑定虚拟通道 #BOOL_TRUE-绑定虚拟通道，对于未绑定虚拟通道，下面参数无意义 */
    ULONG_32 ulBindFlag;

    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1开发二期-解码卡 */
    /** 槽位号 */
    ULONG_32 ulSlotID;

    /** 物理输出端口序号 */
    ULONG_32 ulVoutID;

    /** 虚拟通道所对应的视频通道索引 */
    ULONG_32 ulVinChannelIndex;

    /** 对应的虚拟摄像机编码 */
    CHAR szVirtualCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 虚拟摄像机名称 */
    CHAR szVirtualCameraName[IMOS_NAME_LEN];

    /** 保留字段 */
    ULONG_32 ulReserve;

}VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S;
/* Begin: Added by chenyongfa, 2013-05-03 of IVSD00832 */
/**
*@struct tagVirtualChannelInfoForECR
*@biref 修改虚拟通道分辨率/帧率NOTIFY消息结构体
*@attention
*/
typedef struct tagVirtualChannelInfoForECR
{
    /** 分辨率, 取值为#IMOS_PICTURE_SIZE_E */
    ULONG_32       ulResolution;

    /** 帧率,可取的值有1, 3, 5, 8, 10, 15, 20, 25, 30 */
    ULONG_32       ulFrameRate;

    /** 虚拟通道序号 */
    VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S stVirtualChannelStatus;

}VIRTUAL_CHANNEL_INFO_FOR_ECR_S;
/* End: Added by chenyongfa, 2013-05-03 of IVSD00832 */

/**
*@struct tagBindVirtualChannel
*@brief 虚拟通道绑定基本信息结构体
*@attention 无
*/
typedef struct tagVirtualChannelBindInfoForECR
{
    /** 摄像机及其绑定通道信息 */
    VINCHNL_BIND_CAMERA_FOR_ECR_S stVinChnAndCamInfo;

    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1开发二期-解码卡 */
    /** 槽位号 */
    ULONG_32 ulSlotID;

    /** 物理输出端口序号 */
    ULONG_32 ulMMIVoutID;

    /** 虚拟通道序号，目前固定为1(只支持一个虚拟通道) */
    ULONG_32 ulVirtualChannelID;

}VIRTUAL_CHANNEL_BIND_INFO_FOR_ECR_S;

/**
*@struct tagReBindVirtualChannel
*@brief 虚拟通道重新绑定基本信息结构体
*@attention 无
*/
typedef struct tagVirtualChannelReBindInfoForECR
{
    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1开发二期-解码卡 */
    /** 槽位号 */
    ULONG_32 ulSlotID;

    /** 物理输出端口序号 */
    ULONG_32 ulMMIVoutID;

    /** 虚拟通道序号，目前固定为1(只支持一个虚拟通道) */
    ULONG_32 ulVirtualChannelID;

}VIRTUAL_CHANNEL_REBIND_INFO_FOR_ECR_S;

/**
*@ CAM_SHARE_INFO_S
*@ brief 摄像机以及通道信息项(查询摄像机以及通道列表时返回)
*@ attention
*/
typedef struct tagCamShareInfo
{
    /** 设备通道索引信息 */
    DEV_CHANNEL_INDEX_S  stECChannelIndex;

    /** 摄像机编码 */
    CHAR szCamCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR szCamName[IMOS_NAME_LEN];

    /** 摄像机类型，取值为#CAMERA_TYPE_E */
    ULONG_32 ulCamType;

    /** 资源互联编码 */
    CHAR szInterCode[IMOS_CODE_LEN];

    /** 摄像机共享状态，1表示共享成功，0表示其他 */
    ULONG_32 ulState;

    /** 保留字段 */
    CHAR szReserve[IMOS_CAM_SHARE_RESERVED_LEN];

    /** 资源所属组织节点 */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 资源所属设备名称 */
    CHAR szDeviceName[IMOS_NAME_LEN];

}CAM_SHARE_INFO_S;

/**
*@ struct tagSemaShareInfo
*@ brief开关量共享信息项
*@ attention
*/
typedef struct tagSemaShareInfo
{
    /** 资源所属设备编码*/
    CHAR szDeviceCode[IMOS_CODE_LEN];

    /** 资源所属设备名称*/
    CHAR szDeviceName[IMOS_NAME_LEN];

    /** 通道索引*/
    ULONG_32 ulIndex;

    /** 开关量共享状态，1表示共享失败，0表示其它 */
    ULONG_32 ulState;

    /** 开关量类型，0无效，1表示输入，2表示输出 */
    ULONG_32 ulSemaType;

    /** 资源编码 */
    CHAR szResCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR szResName[IMOS_NAME_LEN];

    /** 资源互联编码 */
    CHAR szInterCode[IMOS_CODE_LEN];

    /** 资源所属组织节点 */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];
}SEMA_SHARE_INFO_S;

/**
* @struct tagSDKMUInit
* @brief SDK 初始化时用的结构
*/
typedef struct tagSDKMUInit
{
    /** 进程名称 */
    CHAR szProcName[IMOS_PROC_NAME_MAX_LEN];

    /** 进程procID（IMOS系统内统一分配，相同类型进程使用相同的procID） */
    USHORT usProcID;

    /** 是否UI侧的标记 */
    BOOL_T bUIFlag;

    /** 是否包含XP标记 */
    BOOL_T bXPFlag;

    ULONG_32  ulSDKInitFlag;

    /* 服务器IP */
    CHAR    szServerAddr[IMOS_IPADDR_LEN];

    /* 服务器端口 */
    ULONG_32   ulServerPort;

    /** 回调函数指针 */
    SDK_CALL_BACK_PROC_PF pfnCallBackProc;

    /** 回调函数参数，用于回调函数出入参赋值 */
    VOID *pParam;

}SDK_MU_INIT_S;

/**
 * @struct tagDevInst
 * @brief DC设备各通道参数
 * @attention
 */
typedef struct  tagDevInst
{
    /**参数类型 参见#DEV_INST_TYPE_E */
    ULONG_32    ulInstType;

   /** 参数值1。控制时，拼接下为[a]x[b]形式，即a*b分屏，为拼接的具体通道由","分隔。
    *  模拟输入下为模拟枚举值0(无)/1(VGA)/2(DVI)。查询时，模拟输入返回模拟枚举值 */
    CHAR   szPara1[IMOS_STRING_LEN_256];

   /** 参数值2。控制时，拼接下的具体通道由","分隔，模拟输入下为解码输出的通道号。
    *  查询时，返回每个通道的主屏号具体通道由","间隔，拼接下无拼接返回0。 */
    CHAR   szPara2[IMOS_STRING_LEN_256];

   /** 参数值3，保留 */
    CHAR   szPara3[IMOS_STRING_LEN_256];

    /** 保留字段 */
    CHAR szReserve[IMOS_STRING_LEN_128];
} DEVINST_S;

/*@brief 推送信息处理回调函数类型pstUserLoginIDInfo为用户登录ID信息，ulProcType为处理类型，枚举值为CALL_BACK_PROC_TYPE_E */
typedef VOID (STDCALL *CALL_BACK_PROC_EX_PF)(IN USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN ULONG_32 ulProcType, IN VOID *pParam);

/*@brief 推送信息处理回调函数类型pstUserLoginIDInfo为用户登录ID信息，ulProcType为处理类型，枚举值为CALL_BACK_PROC_TYPE_E，pClientParam为用户设置的指针信息 */
typedef VOID (STDCALL *CALL_BACK_PROC_PF_V2)(IN USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN ULONG_32 ulProcType, IN VOID *pParam, IN VOID *pClientParam);

/**
 * @struct tagVideoStreamExtendForECR
 * @brief 视频流及扩展信息
 * @attention
 */
typedef struct tagVideoStreamExtendForECR
{

    /** 码流类型, 取值为#IMOS_STREAM_TYPE_E, 目前仅支持#IMOS_ST_TS */
    ULONG_32       ulStreamType;

    /** 流索引，1为主流，2为辅流 */
    ULONG_32       ulStreamIndex;

    /** 流使能标识, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 流传输方式, 取值为#IMOS_TRANS_TYPE_E */
    ULONG_32       ulTranType;

    /** 编码格式, 取决于具体的流套餐值, 取值为#IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /** 分辨率, 取值为#IMOS_PICTURE_SIZE_E */
    ULONG_32       ulResolution;

    /** 码率 */
    ULONG_32       ulBitRate;

    /** 帧率,可取的值有1, 3, 5, 8, 10, 15, 20, 25, 30 */
    ULONG_32       ulFrameRate;

    /** GOP模式, 取值为#IMOS_GOP_TYPE_E */
    ULONG_32       ulGopMode;

    /** I帧间隔, 取决于GOP模式值, 当GOP模式为#IMOS_GT_I时, I帧间隔为1; 当GOP模式为#IMOS_GT_IP时, I帧间隔为10~50 */
    ULONG_32       ulIFrameInterval;

    /** 图像质量, 取值为#IMOS_VIDEO_QUALITY_E */
    ULONG_32       ulImageQuality;

    /** 流编码模式, 取值为#IMOS_ENC_MODE_E */
    ULONG_32       ulEncodeMode;

    /** 优先级, 仅在编码模式为#IMOS_EM_CBR时可设置该值, 取值为#IMOS_CBR_ENC_MODE_E */
    ULONG_32       ulPriority;

    /** 码流平滑，取值为#IMOS_STREAM_SMOOTH_E */
    ULONG_32       ulSmoothValue;

    /** 分辨率的X轴值 */
    ULONG_32       ulXValue;

    /** 分辨率的Y轴值 */
    ULONG_32       ulYValue;

}VIDEO_STREAM_EXTEND_FORECR_S;

/**
 * @struct tagIPCCamInfo
 * @brief  IPC摄像机信息
 * @attention
 */
typedef struct tagIPCCamInfoForECR
{
    /** 摄像机所属设备编码*/
    CHAR szDeviceCode[IMOS_CODE_LEN];

    /** 摄像机所属设备名称*/
    CHAR szDeviceName[IMOS_NAME_LEN];

    /** 摄像机所属设备厂商信息 */
    CHAR szManufactureName[IMOS_NAME_LEN];

    /** 摄像机所属设备型号，标清,720p高清，1080p高清*/
    ULONG_32 ulDeviceType;

    /** 摄像机所属设备子型号 */
    CHAR szDeviceSubType[IMOS_NAME_LEN];

    /** 摄像机所属设备地址  */
    CHAR szDeviceAddress[IMOS_IPADDR_LEN];

    /** 摄像机所属设备端口  */
    ULONG_32 ulPort;

    /** 摄像机编码*/
    CHAR szCamCode[IMOS_CODE_LEN];

    /** 摄像机名称*/
    CHAR szCamName[IMOS_NAME_LEN];

    /** 摄像机类型，0 标识我司IPC 摄像机，1标识第三方IPC 摄像机，其它预留*/
    ULONG_32 ulCamType;

    /** 摄像机状态，2标识离线，1标识在线，其它预留  */
    ULONG_32 ulCamState;

     /** 设备配置状态，0表示未初始化，1表示已初始化 */
    ULONG_32 ulDevState ;

    /** 组播地址 */
    CHAR szMultiCastAddr[IMOS_IPADDR_LEN];

    /** 组播端口  */
    ULONG_32 ulMultiCastPort;

    /** 扩展预留 */
    CHAR szReversed[IMOS_IPC_CAM_INFO_REVERSED_LEN];
}IPC_CAM_INFO_FORECR_S;


/**
 * @struct tagUnitedRecDomainCfg
 * @brief 服务器的云录像检索配置信息结构
 * @attention
 */
typedef struct tagUnitedRecDomainCfg
{
    /** 检索策略 0:优先检索注册域录像 1:只检索当前域录像 2:云录像检索 */
    ULONG_32 ulRecPolicy;

    /** 录像优先级 0:当前域录像优先 1:注册域录像优先
        本字段只有当检索策略为云录像检索时才有效 */
    ULONG_32 ulRecPriority;

     /** 保留字段 */
    CHAR   szReserve[32];
}UNITED_REC_DOMAIN_CFG_S;

/**
*@struct tagDeviceVersionForECR
*@brief 作用:获取设备允许的状态信息
*/
typedef struct tagDeviceVersionForECR
{
    CHAR szSoftwareVer[IMOS_VERSION_LENTH + 4];          /* program版本 */
    CHAR szSoftwareInnerVer[IMOS_VERSION_LENTH + 4];     /* program内部版本 */
    CHAR szProuductVer[IMOS_VERSION_LENTH + 4];          /* uimage版本 */
    CHAR szProuductInnerVer[IMOS_VERSION_LENTH + 4];     /* uimage内部版本 */
    CHAR szPCBVer[IMOS_VERSION_LENTH + 4];               /* PCB版本 */
    CHAR szCPLDVer[IMOS_VERSION_LENTH + 4];              /* CPLD版本 */
    CHAR szDSPVer[IMOS_VERSION_LENTH + 4];               /* DSP版本 */
    CHAR szUbootVer[IMOS_VERSION_LENTH + 4];             /* UBOOT引导版本 */
    CHAR szFPGAVer[IMOS_VERSION_LENTH + 4];              /* FPGA版本 */
    CHAR szMCUVer[IMOS_VERSION_LENTH + 4];               /* MCU版本 */
}DEVICE_VERSION_FOR_ECR_S;

/**
* @struct tagDevBaseInfoForECR
* @brief  设备基本信息
* @attention
*/
typedef struct tagDevBaseInfoForECR
{
    DEVICE_TYPE_FOR_ECR_E       enDeviceType;                                 /* 设备类型 */
    CHAR                        szDeviceName[IMOS_DEVICE_CODE_LEN];           /* 设备名称 */
    CHAR                        szDeviceSerialNumber[IMOS_DEVICE_CODE_LEN];   /* 设备序列号 */
    DEVICE_VERSION_FOR_ECR_S    stDeviceVer;                                  /* 版本信息 */
}DEV_BASE_INFO_FOR_ECR_S;

/**
*@struct tagDevHeatStatusForECR
*@brief 加热模块工作状态
*/
typedef enum tagDevHeatStatusForECR
{
    IMOS_HEAT_NO = 0,    /* 未加热 */
    IMOS_HEAT_LOW,       /* 低功率加热 */
    IMOS_HEAT_HIGH,      /* 高功率加热 */
    IMOS_HEAT_NULL,      /* 没有加热模块 */
    IMOS_HEAT_BUTT
} DEV_HEAT_STATUS_FOR_ECR_E;

/**
* @struct tagDevRunStatusForECR
* @brief  设备运行信息
* @attention
*/
typedef struct tagDevRunStatusForECR
{
    TIME_T                      stSystemTime;           /* 系统时间 */
    ULONG_32                       ulRunTime;              /* 设备运行时间 单位：分钟*/
    LONG_32                        lDeviceTemperature;     /* 设备温度 */
    BOOL_T                      bDeviceIsOnline;        /* 设备在线状态 */
    ULONG_32                       ulCPUUtilization;       /* CPU使用率 */
    ULONG_32                       ulMemFree;              /* 空闲内存量，单位：M */
    ULONG_32                       ulMemMax;               /* 最大内存量，单位：M */
    ULONG_32                       ulIORead;                   /* IO读，单位：kB/s */
    ULONG_32                       ulIOWrite;                  /* IO写，单位：kB/s */
    DEV_FANS_STATUS_FOR_ECR_E   enFansStatus;         /* 风扇状态 */
    DEV_HEAT_STATUS_FOR_ECR_E   enHeatStatus;         /* 加热状态 */
}DEV_RUN_STATUS_FOR_ECR_S;

/**
* @struct tagNicNumberForECR
* @brief  设备网卡的数量
* @attention
*/
typedef struct tagNicNumberForECR
{
    ULONG_32    ulNICNumber;                          /* 网卡数量 */
}NIC_NUMBER_FOR_ECR_S;

/**
* @struct tagLinkInfoForECR
* @brief  链路状况
* @attention
*/
typedef struct tagLinkInfoForECR
{
    NET_LINK_MODE_FOR_ECR_E     enLinkType;    /* 链路类型 */
    CHAR    szLinkName[IMOS_NAME_LEN];      /* 接口名称，和设备后的丝印保持一致*/
    CONNECTION_STATUS_FOR_ECR_E         enConnectionStatus;    /* 连接状态 未连接后面的参数无意义*/
    ETH_SPEED_FOR_ECR_E     enBandwidth;    /* 带宽*/
    ETH_DUPLEX_FOR_ECR_E   enOperatingMode;  /* 工作模式*/
}LINK_INFO_FOR_ECR_S;

/**
* @struct tagIPInfoForECR
* @brief  IP信息
* @attention
*/
typedef struct tagIPInfoForECR
{
    IP_GET_TYPE_FOR_ECR_E     enIPObtain;                       /* IP获取方式 */
    CHAR    szIpAddress[IMOS_IPADDR_LENTH + 4];            /* IP地址 */
    CHAR    szIpNetmask[IMOS_IPADDR_LENTH + 4];            /* 子网掩码 */
    CHAR    szIpGateway[IMOS_IPADDR_LENTH + 4];            /* 网关 */
}IP_INFO_FOR_ECR_S;

/**
* @struct tagNicInfoForECR
* @brief  设备单个网卡的信息
* @attention
*/
typedef struct tagNicInfoForECR
{
    ULONG_32                   ulNICIndex;                                 /* 网卡的序号 */
    CHAR                    szMacAddress[IMOS_STRING_LEN_32];           /* 该网卡的Mac地址，32位，以数组的形式传递 */
    CHAR                    szNICName[IMOS_NETWORK_CARD_NAME_LEN_FOR_ECR]; /* 网卡名称 */
    ULONG_32                   ulLinkNumber;            /* 该网卡的物理接口数量 最大值为16*/
    LINK_INFO_FOR_ECR_S         astLinkInfo[IMOS_NETWORK_CARD_PHY_MAXNUM_FOR_ECR];    /* 链路状况，最大值为16 */
    ULONG_32                               ulIPNumber;         /* 该网卡的IP地址数量 最大值为4*/
    IP_INFO_FOR_ECR_S       astIPInfo[IMOS_NETWORK_CARD_IP_ADDR_MAXNUM_FOR_ECR];  /* IP状况，最大值为4 */
}NIC_INFO_FOR_ECR_S;

/**
* @struct tagVehicleDataForECR
* @brief 过车记录结构
* @attention
*/
typedef struct tagVehicleDataForECR
{
    /** 车辆信息编号 */
    CHAR  szVehicleRecodeId[IMOS_TOLLGATE_SPECIAL_ID_LEN];

    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_TOLLGATE_CODE_LEN];

    /** 卡口编号 */
    CHAR  szTollgateCode[IMOS_TOLLGATE_CODE_LEN];

    /** 车道号，不可修改 */
    CHAR  szLaneNumber[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 行驶方向 */
    CHAR szDirectionName[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 通过时间 */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** 号牌数量 */
    ULONG_32 ulLicensePlateNum;

    /** 号牌号码 */
    CHAR  szLicensePlatCode[IMOS_TOLLGATE_CODE_LEN];

    /** 号牌颜色，参考数据字典 */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌种类，参考数据字典 */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 号牌一致 */
    BOOL_T bLicensePlateCoincide;

    /** 车辆品牌，参考数据字典 */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** 车身颜色深浅，参考#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** 车身颜色，参考数据字典 */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆外形，暂不使用 */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** 车辆类型，参考数据字典 */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** 车长，单位: 厘米 */
    ULONG_32 ulVehicleLen;

    /** 车长是否存在 */
    ULONG_32 ulIsVehicleLen;

    /** 车辆速度，单位Km/h */
    ULONG_32 ulVehicleSpeed;

    /** 车辆速度是否存在 */
    ULONG_32 ulIsVehicleSpeed;

    /** 车道限速，单位Km/h */
    ULONG_32 ulLimitedSpeed;

    /** 车道限速是否存在 */
    ULONG_32 ulIsLimitedSpeed;

    /** 行驶状态，参考数据字典 */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** 图像数量 */
    ULONG_32 ulImgNum;

    /** 图像名称列表 */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** 图像路径列表用于Tware内部使用，这里的图像名称可能和xml中不一样 */
    CHAR  aszImgPathList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** 图像类型列表 */
    ULONG_32 aulImgTypeList[IMOS_MAX_VEHICLE_IMG_NUM];

    /** 图像子合成标志列表 */
    CHAR szImgSubComposeList[IMOS_MAX_VEHICLE_IMG_NUM];

    /** 图像子合成标志是否存在列表 */
    CHAR szImgIsSubComposeList[IMOS_MAX_VEHICLE_IMG_NUM];

    /** 识别时间，单位: 毫秒 */
    ULONG_32 ulIdentifyTime;

    /** 识别时间是否存在 */
    ULONG_32 ulIsIdentifyTime;

    /** 识别状态，参考#VEHICLE_IDENTIFY_STATUS_E */
    ULONG_32 ulIdentifyStatus;

    /** 处理标记 */
    CHAR  szDealStatus[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 过车数据类型，参考#VEHICLE_RECORD_TYPE_E */
    ULONG_32 ulVehicleDataType;

    /** 卡口编号2 */
    CHAR  szTollgateCode2[IMOS_TOLLGATE_CODE_LEN];

    /** 卡口车道号2 */
    CHAR  szLaneNumber2[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 行驶方向2 */
    CHAR szDirectionName2[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 通过时间2 */
    CHAR szPassTime2[IMOS_TIME_LEN];

    /** 是否已上传 */
    ULONG_32 ulTransFlag;

    /** 违章地点编码 */
    CHAR szPlaceCode[IMOS_TOLLGATE_CODE_LEN];

    /** 采集设备类型 */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** 采集机关编码 */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** 更新时间 */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /* begin added by suzhijie for change */
    /** 卡口名称 */
    CHAR  szTollgateName[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 卡口名称2 */
    CHAR  szTollgateName2[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** 地点名称 */
    CHAR szSectionName[IMOS_PLACE_NAME_LEN];

    /** 是否实时记录和命令字 */
    ULONG_32 ulCommand;

    /** 卡口车道类型 */
    CHAR  szLaneType[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 卡口车道类型2 */
    CHAR  szLaneType2[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 方向编号 */
    CHAR szDirectNumber[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 方向编号2 */
    CHAR szDirectNumber2[IMOS_TOLLGATE_SPECIAL_LEN];

    /** 尾部号牌号码 */
    CHAR  szBackendPlatCode[IMOS_TOLLGATE_CODE_LEN];

    /** 尾部号牌颜色，参考数据字典 */
    CHAR  szBackendPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** 尾部号牌种类，参考数据字典 */
    CHAR  szBackendPlateType[IMOS_DICTIONARY_KEY_LEN];

    /** 标识限速 */
    ULONG_32 ulMarkedSpeed;

    /** 标识限速是否存在 */
    ULONG_32 ulIsMarkedSpeed;

    /** 行人衣着颜色，参考数据字典 */
    CHAR  szDressColor[IMOS_DICTIONARY_KEY_LEN];

    /** 红灯时间 */
    ULONG_32 ulRedLightTime;

    /** 红灯时间是否存在 */
    ULONG_32 ulIsRedLightTime;

    /** 应用类型 */
    ULONG_32 ulApplycationType;

    /** 应用类型是否存在 */
    ULONG_32 ulIsApplycationType;

    /** 全局合成标识 */
    ULONG_32 ulGlobalComposeFlag;

    /** 全局合成标识是否存在 */
    ULONG_32 ulIsGlobalComposeFlag;

    /* end added by suzhijie for change */
} VEHICLE_DATA_FOR_ECR_S;

/**
*@ struct tagAudioResShareInfo
*@ brief语音业务资源共享信息项
*@ attention
*/
typedef struct tagAudioResShareInfo
{
    /** 语音业务资源索引*/
    ULONG_32 ulIndex;

    /** 语音业务资源共享状态，1表示共享失败，0表示其它 */
    ULONG_32 ulState;

    /** 语音业务资源类型 对讲:IMOS_TYPE_MICROPHONE; 广播:IMOS_TYPE_SPEAKER */
    ULONG_32 ulAudioResType;

    /** 资源编码 */
    CHAR szAudioResCode[IMOS_CODE_LEN];

    /** 资源名称 */
    CHAR szAudioResName[IMOS_NAME_LEN];

    /** 资源互联编码 */
    CHAR szInterCode[IMOS_CODE_LEN];

    /* 资源所属组织节点 */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];
}AUDIO_RES_SHARE_INFO_S;

/**
 *@struct tagAudioInAndChannelInfoForECR
 *@brief独立音频输入及通道信息结构体(查询音频输入及通道信息时返回)
 *@attention
 */
typedef struct tagAudioInAndChannelInfoForECR
{
	/** 设备通道索引信息  */
	DEV_CHANNEL_INDEX_S        stChannelIndex;

    /** 是否使能 0/1:不使能/使能 */
    ULONG_32       ulAudioEnabled;

    /** 音频编码，取值范围为 #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** 音频声道，取值范围为 #IMOS_AUDIO_CHANNEL_TYPE_E  */
    ULONG_32       ulTrack;

    /** 采样率，取值范围为 #IMOS_AUDIO_SAMPLING_E */
    ULONG_32       ulSamplingRate;

    /** 码率 */
    ULONG_32       ulEncodeRate;

    /** 输入增益值，取值范围为0-255，默认0  */
    ULONG_32       ulIncrement;

    /** 音频输入描述 */
    CHAR        szDesc[IMOS_DESC_LEN];
}AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S;

/**
 *@struct tagAudioOutAndChannelInfoForECR
 *@brief独立音频输出及通道信息结构体(查询音频输出及通道信息时返回)
 *@attention
 */
typedef struct tagAudioOutAndChannelInfoForECR
{
	/** 设备通道索引信息  */
	DEV_CHANNEL_INDEX_S        stChannelIndex;

    /** 使能标识 */
    ULONG_32       ulAudioEnabled;

    /** 音频编码，取值范围为 #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** 音频声道，取值范围为 #IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32       ulTrack;

    /** 音量值 */
    ULONG_32       ulVolume;

    /** 音频输出描述 */
    CHAR        szDesc[IMOS_DESC_LEN];
}AUDIO_OUT_AND_CHANNEL_INFO_FOR_ECR_S;

/**
 *@struct tagAudioResInfoForECR
 *@brief语音业务资源信息结构体
 *@attention
 */
typedef struct tagAudioResInfoForECR
{
    /** 语音业务资源索引 */
    ULONG_32       ulAudioResIndex;

    /** 语音业务资源名称 */
    CHAR        szAudioResName[IMOS_NAME_LEN];

    /** 语音业务资源编码 */
    CHAR        szAudioResCode[IMOS_RES_CODE_LEN];

    /** 所属设备编码 */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 所属设备名称 */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** 语音业务资源类型，取值为：8001--对讲, 8002--广播, 其他值无效 */
    ULONG_32       ulAudioResType;

    /** 音频输入类型，取值为：AUDIO_INPUT_TYPE_FOR_ECR_E */
    ULONG_32       ulAudioInType;

    /** 音频输入索引 */
    ULONG_32       ulAudioInputIndex;

    /** 音频输出索引 */
    ULONG_32       ulAudioOutputIndex;
}AUDIO_RES_INFO_FOR_ECR_S;

/**
 *@struct tagCamBindAudioResInfoForECR
 *@brief 摄像机绑定语音资源信息结构体
 *@attention
 */
typedef struct tagCamBindAudioResInfoForECR
{
    /** 摄像机编码 */
    CHAR        szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机名称 */
    CHAR        szCameraName[IMOS_NAME_LEN];

    /** 语音对讲业务资源编码 */
    CHAR        szAudioTalkResCode[IMOS_RES_CODE_LEN];

    /** 语音对讲业务资源名称 */
    CHAR        szAudioTalkResName[IMOS_NAME_LEN];

    /** 语音广播业务资源编码 */
    CHAR        szAudioBrdcastResCode[IMOS_RES_CODE_LEN];

    /** 语音广播业务资源名称 */
    CHAR        szAudioBrdcastResName[IMOS_NAME_LEN];

    /** 语音业务资源索引 */
    ULONG_32       ulAudioResIndex;
}CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S;

/**
 *@struct tagSdkSerialToIOInfo
 * @brIEf IO消息体串口内容
 * @attention
 */
 typedef struct tagSerialOfIOInfoForECR
{
    /** 设备编号 */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** 串口索引 */
    ULONG_32 ulSerialIndex;

}SERIAL_OF_IO_INFO_FOR_ECR_S;

/**
 * @struct tagMsgFromUMPInfo
 * @brIEf UMP处理完IO发过来的消息后重新封装的消息内容
 * @attention
 */
 typedef struct tagMsgFromUMPInfoForECR
{
    /** 串口信息 */
    SERIAL_OF_IO_INFO_FOR_ECR_S stSerialInfo;

    /** 消息长度 */
    ULONG_32 ulInfoLen;

    /**  占位符 */
    CHAR szIOMsgInfo [4];
}MSG_FROM_UMP_INFO_FOR_ECR_S;

/**
 * @struct tagSdkMsgToIOInfo
 * @brIEf UMP处理完IO发过来的消息后重新封装的OSD消息内容结构体
 * @attention
 */
 typedef struct tagMsgFromUMPOSDInfoForECR
{
    /** OSD通道号 */
    ULONG_32 ulOSDCode;

    /** 场名OSD的数量 */
    ULONG_32                   ulOSDNameNum;

    /** 场名OSD */
    OSD_NAME_S              astOSDName[1];
}MSG_FROM_UMP_OSD_INFO_FOR_ECR_S;

/**
 * @struct tagUMPLOGINCFGLogin
 * @brief 用户登录请求IE体结构
 * @attention 无
 */
typedef struct tagUMPLOGINCFGLoginForECR
{
    /** 用户登录名 */
    CHAR  szUserLoginName[IMOS_NAME_LEN];

    /** 用户口令 */
    CHAR  szPassword[IMOS_PASSWD_ENCRYPT_LEN];

    /** 登录IP地址 */
    CHAR  szIpAddress[IMOS_IPADDR_LEN];

} UMP_LOGINCFG_LOGIN_FOR_ECR_S;

/**
 * @struct tagSdkSerialToIOInfo
 * @brIEf 向IO发送消息体内容
 * @attention
 */
typedef struct tagMsgOFIOInfoForECR
{
    /** 消息长度 */
    ULONG_32 ulMsgLen;

    /** 消息起始指针 */
    CHAR  szIOMsgInfo[4];

}MSG_OF_IO_INFO_FOR_ECR_S;

/**
 * @struct tagSdkMsgToIOInfo
 * @brIEf 向IO发送消息
 * @attention
 */
 typedef struct tagSdkMsgToIOInfoForECR
{
    /** 用户登录信息 */
    USER_LOGIN_ID_INFO_S               stUserInfo;

    /** 串口信息 */
    SERIAL_OF_IO_INFO_FOR_ECR_S stSerialInfo;

    /** 消息体 */
    MSG_OF_IO_INFO_FOR_ECR_S stIOMsgInfo;

}SDK_MSG_TO_IO_INFO_FOR_ECR_S;

/**
 *@struct tagIOMSGInfoForECR
 * @brIEf IO消息体内容
 * @attention
 */
 typedef struct tagIOMSGInfoForECR
{
    /** 消息长度 */
    ULONG_32 ulInfoLen;

    /**  占位符 */
    CHAR szIOMsgInfo [4];

}IO_MSG_INFO_FOR_ECR_S;

/**
* @struct tagUniversalPage
* @brief 通用分页信息
* @attention
*/
typedef struct tagUniversalPageInfo
{
    ULONG_32 ulFirstRow;               /**< 本页从第几行开始查询 */
    ULONG_32 ulPageRowNum;             /**< 本页要查询的行数 */
    ULONG_32 ulFiledNum;                    /* 查询的字段数目*/
    ULONG_32 ulActualRowCount;         /**< 实际返回的行数 */
    ULONG_32 ulTotalRowCount;          /**< 符合条件的行数总计 */
    ULONG_32 ulVecNum;                      /**< vector 容器中存入的字符串数量*/
}UNI_PAGE_INFO_S;

/* Begin Added by liuhongjieKF0170,2013-8-28 of 支持区块OSD */
/**
 * @struct tagThreeDimensionCoverAreaInfo
 * @brief 3D遮盖区域信息
 * @attention
 */
typedef struct tagThreeDimensionCoverAreaInfo
{
    /* 区域索引 */
    ULONG_32            ulAreaIndex;

    /* 区域使能标志位 */
    ULONG_32            ulEnableFlag;

    /* 区域坐标 */
    AREA_SCOPE_S     stArea;

}THREE_DIM_COVER_AREA_INFO_S;

/**
 * @struct tagThreeDimensionCoverPositionState
 * @brief 3D遮盖区域位置状态信息
 * @attention
 */
typedef struct tagThreeDimensionCoverPositionState
{
   /* 区域个数 */
   ULONG_32  ulAreaNum;

   /* 3D遮盖区域信息*/
   VIDEO_AREA_S    ast3DCoverAreaInfo[IMOS_MAX_3D_COVER_AREA_NUM];

}THREE_DIM_COVER_POSITION_STATE_S;
/* End Added by liuhongjieKF0170,2013-8-28 of 支持区块OSD */

/* Begin Added by liuhongjieKF0170,2013-9-4 of 支持区块OSD */
/**
 * @struct tagNewOSDRowCommonParam
 * @brief NewOSD 通用参数
 * @attention
 */
typedef struct tagNewOSDRowCommParam
{
    ULONG_32  ulFontEffect;                  /** 字体效果 */

    ULONG_32  ulFontSize;                    /** 字体大小 */

}NEW_OSD_ROW_COMM_PARAM_S;

/**
 * @struct tagNewOsd
 * @brief  新的OSD信息
 * @attention
 */
typedef struct tagNewOsd
{
    ULONG_32  ulEnabledFlag;                 /** 是否使能场名OSD, 1为使能; 2为非使能 */
    ULONG_32  ulOsdIndex;                    /** OSD索引 */
    ULONG_32  ulAreaIndex;                   /** 所属区域索引 */
    ULONG_32  ulOsdColor;                    /** 场名OSD颜色 */
    ULONG_32  ulTransparence;                /** 场名OSD透明度 */
    ULONG_32  ulFontEffect;                  /** 字体效果 */
    ULONG_32  ulFontSize;                    /** 字体大小 */
    ULONG_32  ulOsdType;                     /** OSD类型 */
    CHAR   szOsdString[IMOS_NAME_LEN];    /** OSD内容 */
    ULONG_32       ulOsdDateFormat;         /* OSD时间格式 */       
    ULONG_32       ulOsdMinMargin;         /* 最小间距 */
    CHAR   szReserve[56];               /** 保留字段 */
}NEW_OSD_S;
/* End Added by liuhongjieKF0170,2013-9-4 of 支持区块OSD */

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
 * @struct tagSdkOperLogInfoForECR
 * @brief 图片OSD 叠加方式
 * @attention
 */
 typedef struct tagSdkOperLogInfoForECR
{
    /** 业务类型 */
    ULONG_32 ulOperateType;

    /** 操作类型 */
    ULONG_32 ulServiceType;

    /** 操作结果 */
    ULONG_32   ulResult;

    /** 操作对象 */
    CHAR szOperateObject[IMOS_STRING_LEN_128];
}SDK_OPER_LOG_INFO_FOR_ECR_S;

typedef struct tagGuardAgentInfoForECR
{
    /** 监管代理的ID号*/
    CHAR szAgentID[IMOS_CODE_LEN];

    /** 监管代理的名称*/
    CHAR szAgentName[IMOS_NAME_LEN];

    /** 监管平台启用标记*/
    ULONG_32 ulServerEnableFlag;

    /** 监管平台状态标记*/
    ULONG_32 ulServerIsOnline;

    /** 监管平台IP地址类型 1 IPV4 2 IPV6*/
    ULONG_32 ulServerAddrType;

    /** 监管平台IP地址  */
    CHAR szServerAddr[IMOS_IPADDR_LEN];

    /** 监管平台端口  */
    ULONG_32 ulServerPort;

    /** 扩展预留 */
    CHAR szReserved[IMOS_NAME_LEN];
}GUARD_AGENT_INFO_FOR_ECR_S;

/**
*@ struct tagCameraMaintainInfoForECR
*@ brief 上报图片相关信息
*@ attention
*/
typedef struct tagCameraMaintainInfoForECR
{
    /** 摄像机编码*/
    CHAR szCameraCode[IMOS_RES_CODE_LEN];

    /** 摄像机索引*/
    ULONG_32 ulCameraIndex;

    /** 动作类型 1-测试 2-验收 3-日常维护*/
    ULONG_32 ulActionType;

    /** 描述信息*/
    CHAR szDesc[IMOS_DESC_LEN];

    /** 图片名字*/
    CHAR szPictureName[IMOS_NAME_LEN];

    /** 图像格式  1-JPEG, base64编码 */
    ULONG_32 ulPictureFormat;

    /** 图像尺寸，目前最大512  */
    ULONG_32 ulPictureSize;

    /** 图片具体数据，长度已pictureSize为准 */
    CHAR astPicture[1];
}CAMERA_MAINTAIN_INFO_FOR_ECR_S;

/**
 * @struct tagAddIPCInfo
 * @brief  添加IPC信息
 * @attention
 */
typedef struct tagAddIPCInfo
{
    /** EC编码, EC的唯一标识 */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC名称 */
    CHAR  szECName[IMOS_NAME_LEN];

    /** 是否支持组播, 1为支持; 0为不支持 */
    ULONG_32 ulIsMulticast;

    /** 告警使能, 1为使能; 0为不使能 */
    ULONG_32 ulEnableAlarm;

    /** EC所属组织编码 */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** 时间同步方式，默认为1，表示使用H3C的私有同步方式；2表示NTP的同步方式(目前暂不支持) */
    ULONG_32 ulTimeSyncMode;

    /** 时区, 取值为-12~12 */
    LONG_32 lTimeZone;

    /** 语言设置，由中心服务器来配置，取值为:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** 是否启用本地缓存，1表示启用; 0表示不启动，默认值为0 */
    ULONG_32 ulEnableLocalCache;

    /*厂商类型*/
    ULONG_32  ulCameraManutype;   /*0我司、1第三方*/

    /** IPC的IP地址, 添加第三方需填写该参数*/
    CHAR szECIPAddr[IMOS_IPADDR_LEN];

    /*设备端口*/
    ULONG_32  ulDevPort;

   /* 用户名 */
   CHAR szUserName[IMOS_NAME_LEN];

   /** 设备访问密码 */
   CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

   /* 接入类型，1 ONVIF1.0  ，2  ONVIF2.0 */
   ULONG_32  ulCameraAccessType;

   /** 保留字段 */
   CHAR szReserve[64];

}ADD_IPC_INFO_S;

/**
 * @struct tagDAOIPCSerialPortInfo
 * @brief  IPC串口能力信息
 * @attention
 */
typedef struct tagIPCSerialPortInfo
{
   /* 串口个数*/
   ULONG_32 ulSerialPortNum;

   /* 串口类型在xml中节点名字 */
   CHAR  aszSerialExpand[IMOS_IPC_SERIAL_PORT_MAX_NUM][IMOS_XML_EXPAND_DESC_LEN];
}IPC_SERIAL_PORT_INFO_S;


typedef struct tagIPCCapabilities
{
    CHAR    szOSDVersion[IMOS_XML_EXPAND_DESC_LEN];                   /** OSD版本 */
    ULONG_32   ulOSDBlockNum;                                            /** OSD块个数 */
    ULONG_32   ulOSDNum;                                                  /** OSD个数 */

    CHAR    szROIVersion[IMOS_XML_EXPAND_DESC_LEN];                   /** ROI版本 */
    ULONG_32   ulROINum;                                                 /** 区域增强个数 */

    CHAR    szMaskVersion[IMOS_XML_EXPAND_DESC_LEN];                  /** 遮盖区域版本 */
    ULONG_32   ulMaskAreaNum;                                            /** 遮盖区域个数 */

    CHAR    szMotionDetectVersion[IMOS_XML_EXPAND_DESC_LEN];          /** 移动检测版本 */
    ULONG_32   ulMotionDetectNum;                                        /** 移动侦测区域个数 */

    CHAR    szSemaphoreInputVersion[IMOS_XML_EXPAND_DESC_LEN];        /** 输入开关量版本 */
    ULONG_32   ulSemaphoreInputNum;                                      /** 输入开关量个数 */

    CHAR    szSemaphoreOutputVersion[IMOS_XML_EXPAND_DESC_LEN];       /** 输出开关量版本 */
    ULONG_32   ulSemaphoreOutputNum;                                     /** 输出开关量个数 */

    ULONG_32   ulEncodeCapacity;                                         /** 编码能力 暂不使用 */
    CHAR    szCamTypeBas[IMOS_XML_EXPAND_DESC_LEN];                   /** 摄像机基本类型 */

    CHAR    szTempAlarm[IMOS_XML_EXPAND_DESC_LEN];                    /** 温度告警版本 */
    LONG_32    lTempMax;                                                 /** 最高温度  */
    LONG_32    lTempMin;                                                 /** 最低温度  */

    CHAR    szAudioCodeSet[IMOS_XML_EXPAND_DESC_LEN];                 /** 音频编码 */
    CHAR    szVideoEncodeSet[IMOS_XML_EXPAND_DESC_LEN];                /** 视频流套餐*/

    CHAR    szTransProtocol[IMOS_XML_EXPAND_DESC_LEN];                 /** 传输流协议*/

    IPC_SERIAL_PORT_INFO_S stSerialPortInfo;                       /** 串口信息 */

    CHAR    szMirrorVersion[IMOS_XML_EXPAND_DESC_LEN];                /*镜像模式*/
}IPC_CAPABILITIES_S;

/**
 * @struct tagMotionDetectArea
 * @brief  移动侦测区域信息(V2.0)
 * @attention
 */
typedef struct tagMotionDetectArea
{
    ULONG_32           ulDruation;                      /** 持续时间 */
    ULONG_32           ulTargetSize;                    /** 目标大小 */
    VIDEO_AREA_S    stVideoArea;                     /** 区域坐标 */
    CHAR            szReserve[IMOS_RESERVED_LEN];    /** 保留字段 */
}MOTION_DETECT_AREA_S;

/**
 * @struct tagAreaScopeV2
 * @brief 区域范围的两个顶点坐标(区域是矩形的)
 * @attention
 */
typedef struct tagAreaScopeV2
{
    /** 左上角x坐标, 取值为0~10000 */
    ULONG_32       ulTopLeftX;

    /** 左上角y坐标, 取值为0~10000 */
    ULONG_32       ulTopLeftY;

    /** 右下角x坐标, 取值为0~10000 */
    ULONG_32       ulBottomRightX;

    /** 右下角y坐标, 取值为0~10000 */
    ULONG_32       ulBottomRightY;

}AREA_SCOPE_V2_S;

/**
* @struct tagROIArea
* @brief 区域增强信息
* @attention
*/
typedef struct tagROIArea
{
 /** 区域索引 */
 ULONG_32            ulAreaIndex;

 /** 使能标记 */
 ULONG_32            ulEnabledFlag;

 /** 区域坐标 */
 AREA_SCOPE_V2_S  stAreaScope;

}ROI_AREA_S;

/**
 * @struct tagVideoInChannelExtend
 * @brief 音视频输入通道信息
 * @attention
 */
typedef struct tagVideoInChannelExtend
{

    /** 视频输入通道描述 */
    CHAR szVinChannelDesc[IMOS_DESC_LEN];

    /** 组播地址 */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** 组播端口,范围为：10002-65534，且必须为偶数 */
    ULONG_32   ulMulticastPort;

    /** MS选择的适应策略, 1为自适应; 0为非自适应 */
    ULONG_32 ulIsAutofit;

    /** 使用MS数目, 视实际情况而定, 当适应策略#ulIsAutofit为自适应, 该值为0;
        当适应策略#ulIsAutofit为非自适应(即指定), 该值为1 */
    ULONG_32 ulUseMSNum;

    /** MS编码列表 */
    CHAR aszMSCode[IMOS_MS_MAX_NUM_PER_CHANNEL][IMOS_DEVICE_CODE_LEN];

    /** 是否启动图像遮挡检测告警, 1为启动; 0为不启动 */
    ULONG_32 ulEnableKeepout;

    /** 是否启动运动检测告警, 1为启动运动检测告警; 0为不启动运动检测告警 */
    ULONG_32 ulEnableMotionDetect;

    /** 是否启动视频丢失告警, 1为启动视频丢失告警; 0为不启动视频丢失告警 */
    ULONG_32 ulEnableVideoLost;

    /** 绑定的串口编号，如无则填写0 */
    ULONG_32 ulSerialIndex;

    /** 亮度，取值为（0~255） */
    ULONG_32 ulBrightness;

    /** 对比度，取值为（0~255） */
    ULONG_32 ulContrast;

    /** 饱和度，取值为（0~255） */
    ULONG_32 ulSaturation;

    /** 色调，取值为（0~255） */
    ULONG_32 ulTone;

    /** 图像优化模式  */
    ULONG_32 ulProcessingMode;

    /**  锐度模式  */
    ULONG_32 ulSharpnessMode;

    /**  锐度值  */
    ULONG_32   ulSharpnessValue;

    /**  2D降噪等级  */
    ULONG_32  ul2DLevel;

    /**  3D降噪等级  */
    ULONG_32 ul3DLevel;

    /**   镜像模式 */
    ULONG_32 ulMirrorMode;

    /** 是否启动声音, 1为不静音; 0为静音 */
    ULONG_32 ulAudioEnabled;

    /** 音频编码, 取值为#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioCoding;

    /** 音频声道, 取值为#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** 音频采样率, 取值为#IMOS_AUDIO_SAMPLING_E */
    ULONG_32 ulSamplingRate;

    /** 音频码率, 不可配置 */
    ULONG_32 ulAudioCodeRate;

    /** 音频增益值，取值为（0~255） */
    ULONG_32 ulIncrement;
}VIN_CHANNEL_EXTEND_S;

/**
 * @struct tagExportProcessInfoForECR
 * @brief 进度信息
 * @attention
 */
typedef struct tagExportProcessInfoForECR
{
    /** 进度状态，0，进行中，1，异常，2，完成*/
    ULONG_32 ulProcessState;

    /** 进度值，对进行中的进度有效*/
    ULONG_32 ulProcessValue;
}EXPORT_PROCESS_FOR_ECR_S;

/**
 * @struct tagUMUsbDiskMessageForECR
 * @brief 单个U盘信息
 * @attention
 */
typedef struct tagUMUsbDiskMessageForECR
{
    ULONG_32                           ulUsbDiskIdx;               /* U盘索引 */
    BOOL_T                          bIsOnLine;                  /* U盘是否在线 */
    ULONG_32                           ulUsbDiskTotalSpace;        /* U盘总容量:MB */
    ULONG_32                           ulUsbDiskFreeSpace;         /* U盘剩余容量:MB */
}UM_USB_DISK_MESSAGE_FOR_ECR_S;

/**
 * @struct tagUMUsbDiskInfoForECR
 * @brief 所有U盘信息
 * @attention
 */
typedef struct tagUMUsbDiskInfoForECR
{

    ULONG_32                           ulUsbDiskNum;                                       /* U盘个数 */
    UM_USB_DISK_MESSAGE_FOR_ECR_S        astUsbDiskMessage[USB_DISK_MAX_NUMBER];     /* U盘信息 */
 }UM_USB_DISK_INFO_FOR_ECR_S;

/**
*@struct tagUMUsbDirInfoForECR
*@brief USB目录信息
*/
typedef struct tagUMUsbDirInfoForECR
{
    UM_USB_DIR_TYPE_E                  enDirType;                                      /* 目录类型 */
    CHAR                            aszDirName[IMOS_FILE_NAME_LEN];                  /* 目录名称 */
}UM_USB_DIR_INFO_FOR_ECR_S;

/**
*@struct tagUMUsbDirListForECR
*@brief USB目录列表
*/
typedef struct tagUMUsbDirListForECR
{
    ULONG_32                           ulNum;
    UM_USB_DIR_INFO_FOR_ECR_S                  astDirInfo[UM_USB_DIR_NUM];
}UM_USB_DIR_LIST_FOR_ECR_S;

/**
 * @struct tagDictionaryDataForECR
 * @brief 数据字典结构
 * @attention
 */
typedef struct tagDictionaryDataForECR
{

    /** 数据字典编码 */
    CHAR  szDataCode[IMOS_DICTIONARY_KEY_LEN];

    /** 数据字典名称 */
    CHAR  szDataName[IMOS_NAME_LEN];

    /** 是否系统预定义项，系统预定义项不允许删除和修改，BOOL_TRUE:系统预定义，BOOL_FALSE:非系统预定义 */
    BOOL_T bPreDefined;

} DICTIONARY_DATA_FOR_ECR_S;

/* End Added by lw0581,2013-11-6 for  VVD06374*/
/* Begin Added by lw0581,2013-11-12 for  VVD05864*/
/**
 * @struct tagMasStoreResInfoForECR
 * @brief 存储资源信息
 * @attention 无.
 */
typedef struct tagMasStoreResInfoForECR
{


    /** 存储设备类型, 取值为#STORE_DEV_TYPE_E */
    ULONG_32       ulStoreDevType;

    /** 存储设备编码 */
    CHAR        szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** 存储设备名称 */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** 磁盘满处理策略，取值为#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32       ulDiskFullPolicy;

    /** 存储空间(在IMOS_AssignMasStoreResForECR中,指第一次分配的存储空间; 在IMOS_ExpandMasStoreResForECR中,指扩展空间[不含已分配空间]), 该值取值无上限, 单位为MB */
    ULONG_32       ulStoreSize;

}MAS_STORE_RES_INFO_FOR_ECR_S;


/**
 * @struct tagTMSInfoForECR
 * @brief TMS(交通媒体交换服务器)信息
 * @attention
 */
typedef struct tagTMSInfoForECR
{
    /** 编码 */
    CHAR szTMSCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR szTMSName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** TMS类型，目前填写0 */
    ULONG_32 ulType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /*设备端口*/
    ULONG_32 ulDevPort;

    /** 设备是否启用, 1为启用; 0为不启用 */
    ULONG_32 ulDevEnabled;

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 描述, 暂不使用，填空 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

} TMS_INFO_FOR_ECR_S;

/*Begin Modified by lw0581, 2013-11-12 for VVD06485*/
/** 图片合成方式类型 */
typedef enum tagTollgateCompositeType
{
    TOLLGATE_COMPOSITE_TYPE_ADAPT = 0,                 /**< 自适应叠加 */
    TOLLGATE_COMPOSITE_TYPE_LINE,                 /**<线形叠加 */

    TOLLGATE_COMPOSITE_TYPE_MAX,                   /**< 最大值 */
    TOLLGATE_COMPOSITE_TYPE_INVALID = 0xFFFF       /**< 无效值 */
}TOLLGATE_COMPOSITE_TYPE_E;
/*End Modified by lw0581, 2013-11-12 for VVD06485*/


/** 电警图片合成方式类型 */
typedef enum tagEPoliceCompositeType
{
    EPOLICE_COMPOSITE_TYPE_SQUARE = 0,            /**< 田字合成 */
    EPOLICE_COMPOSITE_TYPE_HORIZONTAL,            /**< 图片横排 */
    EPOLICE_COMPOSITE_TYPE_VERTICAL,              /**< 图片竖排 */
    EPOLICE_COMPOSITE_TYPE_ADAPT,                 /**< 自适应叠加 */

    EPOLICE_COMPOSITE_TYPE_MAX,                   /**< 最大值 */
    EPOLICE_COMPOSITE_TYPE_INVALID = 0xFFFF       /**< 无效值 */
}EPOLICE_COMPOSITE_TYPE_E;

/**
 * @struct tagPicCompositeInfoForECR
 * @brief 图片合成方式
 * @attention
 */
typedef struct tagPicCompositeInfoForECR
{
    /** 摄像机编码 */
    CHAR szCamCode[IMOS_CODE_LEN];

    /** 图片合成方法类型，参考#TOLLGATE_COMPOSITE_TYPE_E */
    ULONG_32 ulTollgatePicCompositeType;

    /** 电警图片合成方法类型，该字段暂不使用，参考#EPOLICE_COMPOSITE_TYPE_E */
    ULONG_32 ulEPolicePicCompositeType;

     /** 合成质量，参考#COMPOSITE_QUALITY_E */
    ULONG_32 ulPicQuality;

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;
} PIC_COM_INFO_FOR_ECR_S;

/** 电警图片OSD叠加类型 */
typedef enum tagEpoliceOSDOverlayType
{
    EPOLICE_OSD_OVERLAY_TYPE_INNER = 0,             /**< 图片内叠加 */
    EPOLICE_OSD_OVERLAY_TYPE_OUTSIDE_TOP,           /**< 图片上方叠加 */
    EPOLICE_OSD_OVERLAY_TYPE_OUTSIDE_BOTTOM,        /**< 图片下方叠加 */

    EPOLICE_OSD_OVERLAY_TYPE_MAX,                   /**< 最大值 */
    EPOLICE_OSD_OVERLAY_TYPE_INVALID = 0xFFFF       /**< 无效值 */
}EPOLICE_OSD_OVERLAY_TYPE_E;

/**
 * @struct tagPicOsdSpliceInfoForECR
 * @brief 图片OSD 叠加方式
 * @attention
 */
typedef struct tagPicOsdSpliceInfoForECR
{
    /** 摄像机编码 */
    CHAR szCamCode[IMOS_CODE_LEN];

    /** 使能时间信息 */
    ULONG_32 ulEnableTimeInfo;

     /** 使能地点信息 */
    ULONG_32 ulEnableDestinatonInfo;

    /** 使能方向信息 */
    ULONG_32 ulEnableDirectionInfo;

    /** 使能车道信息 */
    ULONG_32 ulEnableLaneInfo;

    /** 使能车牌号信息 */
    ULONG_32 ulEnablePlateCodeInfo;

    /** 使能车牌颜色信息 */
    ULONG_32 ulEnablePlateColorInfo;

    /** 使能行驶状态信息 */
    ULONG_32 ulEnableDriveStatusInfo;

    /** 使能红灯时间信息 */
    ULONG_32 ulEnableRedlightTimeInfo;

    /** 使能车辆速度信息 */
    ULONG_32 ulEnableVehicleSpeedInfo;

    /** 使能车标信息*/
    ULONG_32 ulEnableVehicleBrand;

    /** 使能车型信息*/
    ULONG_32 ulEnableVehicleType;

    /** 使能车辆颜色 */
    ULONG_32 ulEnableVehicleColor;

    /** OSD 字体大小 */
    ULONG_32 ulOSDFontSize;

     /** OSD 字体颜色*/
    ULONG_32 ulOSDColor;

    /** OSD 字体透明度*/
    ULONG_32 ulOSDTransparence;

    /** OSD 行最大字数*/
    ULONG_32 ulLineCharNum;

    /** OSD 左上座标X */
    ULONG_32 ulTopLeftX;

    /** OSD 左上座标Y */
    ULONG_32 ulTopLeftY;

    /** OSD 右下座标X */
    ULONG_32 ulBottomRightX;

    /** OSD 右下y坐标 */
    ULONG_32 ulBottomRightY;

    /** 类型1 */
    ULONG_32 ulOSDType1;

    /** 内容1 */
    CHAR szOsdValue1[IMOS_NAME_LEN];

    /** 类型2 */
    ULONG_32 ulOSDType2;

    /** 内容2 */
    CHAR szOsdValue2[IMOS_NAME_LEN];

    /** 切换时间 */
    ULONG_32 ulSwitchInterval;

    /** 是否自动换行 */
    ULONG_32 ulEnableChangeLine;

    /** 图片内/外叠加 ，对应枚举EPOLICE_OSD_OVERLAY_TYPE_E */
    ULONG_32 ulPicInOrOut;

    /** 使能限速信息 */
   ULONG_32 ulEnableLimitSpeed;

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;
}PIC_OSD_SPLICE_INFO_FOR_ECR_S;
/* End Added by lw0581,2013-11-12 for  VVD05864*/

/**
 * @struct tagDeviceInfo
 * @brief 国标设备详细信息
 * @attention
 */
typedef struct tagDeviceInfo
{
    /** 设备结果，可取值为正常#RESULT_TYPE_OK；异常#RESULT_TYPE_ERROR */
    ULONG_32 ulResultType;

    /** 设备生产商 */
    CHAR szManufacturer[IMOS_STRING_LEN_128];

    /** 设备型号 */
    CHAR szModel[IMOS_STRING_LEN_64];

    /** 设备固件版本 */
    CHAR szFirmware[IMOS_STRING_LEN_256];

    /** 视频输入通道数目 */
    CHAR szChannel[IMOS_STRING_LEN_32];
}DEVICE_INFO_S;

/**
 * @struct tagDeviceStatus
 * @brief 国标设备状态信息
 * @attention
 */
typedef struct tagDeviceStatus
{
    /** 设备结果，可取值为正常#RESULT_TYPE_OK；异常#RESULT_TYPE_ERROR */
    ULONG_32 ulResultType;

    /** 是否在线；BOOL_TRUE代表在线， BOOL_FALSE代表离线 */
    BOOL_T bIsOnline;

    /** 是否正常工作，可取值为正常#RESULT_TYPE_OK；异常#RESULT_TYPE_ERROR */
    ULONG_32 ulStatusType;

    /** 不正常工作原因 */
    CHAR szAbnormalReson[IMOS_DESC_LEN];

    /** 是否有录像；BOOL_TRUE代表有， BOOL_FALSE代表没有 */
    BOOL_T bIsRecord;
}DEVICE_STATUS_S;

#define SDK_GAI_MSG_LEN(Msg)                ((Msg)->ulBodyLen + sizeof(SDK_GAI_MSG_S) - sizeof(ULONG_32)) /**< GAI消息长度 */
#define SDK_GAI_MSG_BODY_LEN(Msg)           ((Msg)->ulBodyLen)                      /**< GAI消息体长度 */
#define SDK_GAI_IE_LEN(Ie)                  ((Ie)->ulBodyLen + sizeof(SDK_GAI_IE_S) - sizeof(ULONG_32))   /**< GAI IE长度 */
#define SDK_GAI_IE_HEADDER_LEN              (sizeof(SDK_GAI_IE_S) - 4 * sizeof(UCHAR))
typedef struct tagSDKGAIMsg
{
    ULONG_32   ulFlag;                                 /**< 起始标识 */
    UCHAR   ucMainVer;                              /**< 版本号, 当前为0x01  */
    UCHAR   ucSubVer;                               /**< 子版本，当前为0x00 */
    UCHAR   ucListFlag;                             /**< 消息主机序还是网络序的标志位 */
    UCHAR   ucRerv;                                 /**< 保留字段 */
    ULONG_32   ulMsgID;                                /**< 消息的ID, 参见 #GAI_MSG_ID_E */
    ULONG_32   ulMsgType;                              /**< 消息类型, 参见 #GAI_MSG_TYPE_E */
    ULONG_32   ulSequence;                             /**< 消息序号, 响应要与请求一致 */
    CHAR    szSrcSysID[IMOS_MODULE_NAME_LEN];          /**< 请求系统ID, 响应要与请求一致 */
    CHAR    szDstSysID[IMOS_MODULE_NAME_LEN];          /**< 响应系统ID, 响应要与请求一致 */
    CHAR    szSrcSubSysID[8];    /**< 请求子系统ID, 响应要与请求一致 */
    CHAR    szDstSubSysID[8];    /**< 响应子系统ID, 可选 */
    ULONG_32   ulSrcHandel;                            /**< 请求系统句柄, 响应要与请求一致 */
    ULONG_32   ulDstHandel;                            /**< 响应系统句柄, 可选 */
    ULONG_32   ulBodyLen;                              /**< 消息体长度 */
    UCHAR   aucBody[4];                             /**< 消息体内容 */
}SDK_GAI_MSG_S;


#define SDK_GAI_IE_HEADER                                                               \
    ULONG_32       ulIEID;                             /**< IE的ID, 参见 #GAI_IE_ID_E */   \
    ULONG_32       ulBodyLen;                          /**< IE体长度 */

/**
* @struct tagGAIIE
* @brief GAI消息IE通用 IE结构
*/
typedef struct tagSDKGAIIE
{
    SDK_GAI_IE_HEADER
    UCHAR       aucBody[4];                         /**< IE体内容 */
}SDK_GAI_IE_S;


typedef struct tagSDKGAIIEFrom
{
    SDK_GAI_IE_HEADER
    CHAR        szUAID[IMOS_UAID_LEN];
}SDK_GAI_IE_FROM_S;

typedef struct tagSDKGAIIETo
{
    SDK_GAI_IE_HEADER
    CHAR        szUAID[IMOS_UAID_LEN];
}SDK_GAI_IE_TO_S;

typedef struct tagSDKGAIIEDomInfo
{
    SDK_GAI_IE_HEADER
    BOOL_T   bIsLocalDomain;                     /**< 是否本域 */
    ULONG_32    ulDstMsgID;                         /**< 目的消息类型，详见DIM_MSG_ID_E */
}SDK_GAI_IE_DOM_INFO_S;

typedef struct tagSDKGAIIEData
{
    SDK_GAI_IE_HEADER

    UCHAR       ucHasDataType ;                   /**< 是否携带 BOOL_TRUE、BOOL_FALSE */
    UCHAR       ucTypeVal;                        /**< DATA信息 媒体类型 #GAI_MEDIA_TYPE_E */
    USHORT      usTypeLen;

    UCHAR       aucType[32];         /**< DATA信息 媒体类型字符串 */

    UCHAR       ucSubTypeVal;                     /**< DATA信息 媒体子类型 #GAI_SUB_MEDIA_TYPE_E */
    UCHAR       ucSpare1;
    USHORT      usSubTypeLen;

    UCHAR       aucSubType[32];   /**< DATA信息 媒体子类型字符串 */

    ULONG_32       ulDataLen;
    UCHAR       aucData[4];
}SDK_GAI_IE_DATA_S;

/* Begin Add by zhouquanwei/z01364 2013-11-08 of onvif支持多profile */
/**
 * @struct tagVideoResolution
 * @brief 分辨率
 * @attention
 */
typedef struct tagVideoResolution
{
    /* 分辨率的宽度 */
    ULONG_32 ulWidth;

    /* 分辨率的高度 */
    ULONG_32 ulHeight;
}VIDEO_RESOLUTION_S;

/**
 * @struct tagOnvifProfile
 * @brief onvif摄像机profile
 * @attention
 */
typedef struct tagOnvifProfile
{
    /* profile名称 */
    CHAR       szName[IMOS_NAME_LEN];

    /* 编码格式, 取决于具体的流套餐值, 取值为#IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /* 码流分辨率 */
    VIDEO_RESOLUTION_S      stVideoResolution;

    /* 码率 */
    ULONG_32       ulBitRate;

    /* 常用帧率:1, 3, 5, 8, 10, 15, 20, 25, 30, 60 */
    ULONG_32       ulFrameRate;
}ONVIF_Profile_S;

/**
 * @struct tagOnvifProfiles
 * @brief onvif摄像机profile集合
 * @attention
 */
typedef struct tagOnvifProfiles
{
    /* profile个数 */
    ULONG_32 ulOnvifProfileCount;

    /* profile */
    ONVIF_Profile_S stOnvifProfile[IMOS_ONVIF_PROFILE_MAX];
}ONVIF_PROFILES_S;

/**
 * @struct tagOnvifStreamCFGS
 * @brief 主辅流对应profile集合
 * @attention
 */
typedef struct tagOnvifStreamCFGS
{
    /* 摄像机编码 */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /* 主码流Profile名称 */
    CHAR szStreamFirst[IMOS_NAME_LEN];

    /* 辅码流Profile名称 */
    CHAR szStreamSecond[IMOS_NAME_LEN];
}ONVIF_STREAM_CFGS_S;
/* End Add by zhouquanwei/z01364 2013-11-08 of onvif支持多profile */

/* Begin added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */
/**
* @struct tagAlarmLinkageVocTalkToUI
* @brief 告警联动到语音对讲上报UI结构
* @attention 无
*/
typedef struct tagAlarmLinkageVocTalkToUI
{
    /** 摄像机编码 */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /** 联动语音对讲的用户编码 */
    CHAR szUserCode[IMOS_CODE_LEN];

}ALARM_LINKAGE_VOCTALK_TO_UI_S;
/* End added by liuzhikun/01420, 2013-11-12 for 告警联动到语音对讲 */

/** Begin:add by lw0581, 2013-8-16 for MPPD07153 开关量告警恢复停止存储 **/
typedef struct tagStoreActionForECRV2
{
    CHAR       szCamCode[IMOS_RES_CODE_LEN];    /** 联动摄像机编码 */

    CHAR       szCamName[IMOS_NAME_LEN];        /** 联动摄像机名称（只用于告警联动策略查询接口） */

    ULONG_32      ulStorageStopFlag;               /** 告警恢复后录像自动停止标识  0-不自动停止 1-自动停止 */

    ULONG_32      ulDelayTime;                     /** 告警恢复后录像延迟时间，只有当ulStorageStopFlag取值为1才生效；
                                                    取值范围0~1800，默认值：0 */
    ULONG_32      ulReserver1;                     /** 保留字段，初始化为0 */

    CHAR       szReserver2[32];                 /** 保留字段，初始化为0*/
}STORE_ACTION_FOR_ECR_S;

/**
 * @struct tagAlarmActionForECRV2
 * @brief 告警联动动作(for ECR&NVR buzzer)
 * @attention
 */
typedef struct tagAlarmActionForECRV2
{

    /** 存储动作数组中存储动作的实际数目, 取值最大值为#IMOS_ALARM_STORE_ACTION_MAXNUM */
    ULONG_32                       ulStoreActionNum;

    /** 存储动作数组 */
    STORE_ACTION_FOR_ECR_S     astStoreAction[IMOS_ALARM_STORE_ACTION_MAXNUM];

    /** 预置位动作数组中预置位动作的实际数目, 取值最大值为#IMOS_ALARM_PRESET_ACTION_MAXNUM */
    ULONG_32                       ulPresetActionNum;

    /** 预置位动作数组 */
    PRESET_ACTION_S         astPresetAction[IMOS_ALARM_PRESET_ACTION_MAXNUM];

    /** 联动实况到窗格动作数组中联动实况到窗格动作的实际数目, 取值最大值为#IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM */
    ULONG_32                       ulScreenLiveActionNum;

    /** 联动实况到窗格动作数组 */
    SCREENLIVE_ACTION_FOR_ECR_S     astScreenLiveAction[IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM];

    /** 联动实况到监视器动作数组中联动实况到监视器动作的实际数目, 取值最大值为#IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM */
    ULONG_32                   ulMonitorLiveActionNum;

    /** 联动实况到监视器动作数组 */
    MONITORLIVE_ACTION_FOR_ECR_S    astMonitorLiveAction[IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM];

    /** 联动地图闪烁动作数组中联动地图闪烁动作的实际数目, 取值最大值为#IMOS_ALARM_GIS_ACTION_MAXNUM */
    ULONG_32                   ulGISActionNum;

    /** 联动地图闪烁动作数组 */
    GIS_ACTION_S            astGISAction[IMOS_ALARM_GIS_ACTION_MAXNUM];

    /** 联动开关量输出动作数组中联动开关量输出动作的实际数目, 取值最大值为#IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM */
    ULONG_32                   ulSwitchOUTActionNum;

    /** 联动开关量输出动作数组 */
    SWITCHOUT_ACTION_S      astSwitchOUTAction[IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM];

    /** 联动备份动作数组中联动备份动作的实际数目, 取值最大值为#IMOS_ALARM_BACKUP_ACTION_MAXNUM */
    ULONG_32                   ulBackupActionNum;

    /** 联动备份动作数组 */
    BACKUP_ACTION_S         astBackupAction[IMOS_ALARM_BACKUP_ACTION_MAXNUM];

    /** 联动蜂鸣器告警动作数目 */
    ULONG_32                   ulBuzzerActionNum;

    /** 联动蜂鸣器告警动作列表 */
    BUZZER_ACTION_S         astBuzzerAction[IMOS_ALARM_BUZZER_ACTION_MAXNUM];

    /** 告警联动邮件使能标记, BOOL_TRUE为使能; BOOL_FALSE为非使能 */
    BOOL_T  bEmailActionEnabled;
}ALARM_ACTION_FOR_ECR_V2_S;
/** End:add by lw0581, 2013-8-16 for MPPD07153 开关量告警恢复停止存储 **/

/* Begin: added by lw0581, 2013.12.19 for  MPPD06992 */
/**
* @struct tagResAuthorityForECR
* @brief 资源的权限信息
* @attention 无
*/
typedef struct tagResAuthorityForECR
{
    /** 权限列表 */
    ORG_AUTHORITY_S  stAuthorities;

    /** 资源ID,全局权限为字符串"0" */
    CHAR            szResId[IMOS_CODE_LEN];

} RES_AUTHORITY_FORECR_S;

/**
 * @struct tagOrgNodeInfoExtend
 * @brief 组织域节点信息（组织公共信息+联系方式信息）
 * @attention
 */
typedef struct tagOrgNodeInfoExtend
{
    /** 组织基本信息 */
    ORG_NODE_INFO_S stOrgInfo;

    /** 组织子类型的子类型, 0为无效值 */
    ULONG_32 ulSubTypeofSubType;
}ORG_NODE_INFO_EXTEND_FORECR_S;

/**
* @struct tagResAuthorityQueryItemForECR
* @brief 资源的权限列表
* @attention 无
*/
typedef struct tagResAuthorityQueryItemForECR
{
    /** 权限列表 */
    ORG_AUTHORITY_S stAuthorities;

    /** 资源信息 */
    RES_INFO_S stResInfo;
} RES_AUTHORITY_QUERY_ITEM_FORECR_S;

/** 报警联动蜂鸣状态类型 */
typedef enum tagBuzzerLinkedAlarmStatusForECR
{
    BUZZER_LINKED_ALARM_STATUS_DISABLE      = 0,        /**< 报警联动蜂鸣状态未使能 */
    BUZZER_LINKED_ALARM_STATUS_ENABLE       = 1,        /**< 报警联动蜂鸣状态使能 */
    BUZZER_LINKED_ALARM_STATUS_UNSUPPORT    = 2,        /**< 报警联动蜂鸣功能不支持 */

    BUZZER_LINKED_ALARM_STATUS_MAX,                     /**< 最大值 */
    BUZZER_LINKED_ALARM_STATUS_INVALID = 0xFFFF         /**< 无效值 */
}BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E;

/**
 * @struct tagCameraMotionDetectAlarmInfoForECR
 * @brief 摄像机动检报警状态信息
 * @attention
 */
 typedef struct tagCameraMotionDetectAlarmInfoForECR
{
    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 通道索引信息,设备编码为摄像头父设备编码 */
    DEV_CHANNEL_INDEX_S stDevChannelIndex;

    /** 告警开启标识, 1为使能; 0为非使能 */
    ULONG_32 ulEnabledFlag;

    /** 布防计划状态, 1为计划已经启动; 0为计划未启动 */
    ULONG_32 ulGuardPlanStatus;

}CAMERA_MOTION_DETECT_ALARM_INFO_FOR_ECR_S;

/**
 * @struct tagCameraMaskDetectAlarmInfoForECR
 * @brief 摄像机遮挡报警状态信息
 * @attention
 */
 typedef struct tagCameraMaskDetectAlarmInfoForECR
{
    /** 摄像机编码 */
    CHAR  szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** 摄像机名称 */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** 通道索引信息,设备编码为摄像头父设备编码 */
    DEV_CHANNEL_INDEX_S stDevChannelIndex;

    /** 告警开启标识, 1为使能; 0为非使能 */
    ULONG_32 ulEnabledFlag;

    /** 布防计划状态, 1为计划已经启动; 0为计划未启动 */
    ULONG_32 ulGuardPlanStatus;

}CAMERA_MASK_DETECT_ALARM_INFO_FOR_ECR_S;

/**
 * @struct tagBuzzerLinkedAlarmInfoForECR
 * @brief 设备类告警联动蜂鸣器状态信息
 * @attention
 */
 typedef struct tagBuzzerLinkedAlarmInfoForECR
{
    /** 设备编码 */
    CHAR szDeviceCode[IMOS_CODE_LEN];

    /** 设备名称 */
    CHAR szDeviceName[IMOS_NAME_LEN];

    /** 高温联动蜂鸣状态, 定义见BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulHighTemperatureLinkBuzzerStatus;

    /** 低温联动蜂鸣状态, 定义见BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulLowTemperatureLinkBuzzerStatus;

    /** 防拆联动蜂鸣状态, 定义见BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulAntiRemoveLinkBuzzerStatus;

    /** 风扇故障联动蜂鸣状态, 定义见BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulFanFaultLinkBuzzerStatus;

}BUZZER_LINKED_ALARM_INFO_FOR_ECR_S;
/* End: added by lw0581, 2013.12.19 for  MPPD06992 */

/**
 * @struct tagMapPointInfo
 * @brief  点坐标的经纬度
 * @attention
 */
typedef struct tagMapPointInfo
{
    /* 点坐标经度 */
    CHAR szPointLon[IMOS_STRING_LEN_32];

    /* 点坐标经度 */
    CHAR szPointLat[IMOS_STRING_LEN_32];
}MAP_POINT_INFO_S;

/**
 * @struct tagMapRoadInfo
 * @brief 地图道路信息结构
 * @attention
 */
typedef struct tagMapRoadInfo
{
    /**< 道路ID,系统自动生成 */
    DULONG  dulRoadID;

    /**< 道路描述 */
    CHAR    szRoadDesc[IMOS_DESC_LEN];

    /**< 道路方向(上行/下行)#MAP_ROAD_DIRECTION_E*/
    ULONG_32   ulDirection;

    /**< 道路经过的点数量 */
    ULONG_32   ulPointNum;

    /**< 道路的经过点，暂定为最大64个点，作为描绘路线显示 */
    MAP_POINT_INFO_S    astPointList[IMOS_MAP_ROAD_POINT_MAX_NUM];
}MAP_ROAD_INFO_S;


/**
 * @struct tagMapRoadFlowmeter
 * @brief 道路流量统计配置结构
 * @attention
 */
typedef struct tagMapRoadFlowmeter
{
    /**< 统计配置ID，后台自己生成 */
    DULONG dulFlowmeterID;

    /**< 道路ID */
    DULONG dulRoadID;

    /**< 道路切面线,2点一线 */
    MAP_POINT_INFO_S    astSectionPoint[IMOS_MAP_LINT_POINT_NUM];

    /**< 道路的拐点，2点一段道路 */
    MAP_POINT_INFO_S    astRoadPoint[IMOS_MAP_LINT_POINT_NUM];

    /**<  拥堵速度阀值,单位公里每小时 */
    ULONG_32   ulBlockSpeed;

    /**< 缓行速度阀值，单位公里每小时 */
    ULONG_32   ulSlowSpeed;
}MAP_ROAD_FLOWMETER_S;

/**
 * @struct tagMAPMInfo
 * @brief MAPM(地图服务器)信息
 * @attention
 */
typedef struct tagMAPMInfo
{
    /** 编码 */
    CHAR szMAPMCode[IMOS_CODE_LEN];

    /** 名称 */
    CHAR szMAPMName[IMOS_NAME_LEN];

    /** 所属组织 */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** 所属组织名称，查询返回，其他情况下可以不填 */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** MAPM类型，目前填写0，为MAP8500 */
    ULONG_32 ulType;

    /** 设备地址类型，1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** 设备地址，查询返回，其他情况下可以不填 */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** 设备是否在线, 取值为#IMOS_DEV_STATUS_ONLINE或#IMOS_DEV_STATUS_OFFLINE，在imos_def.h中定义 */
    ULONG_32 ulIsOnline;

    /** 设备扩展状态，预留 */
    ULONG_32 ulDevExtStatus;

    /** 描述, 暂不使用，填空 */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** 预留字段信息 */
    RESERVED_INFO_S stReservedInfo;

} MAPM_INFO_S;

/**
 * @struct tagDevInst
 * @brief 设备的WEBGIS点位信息
 * @attention
 */
typedef struct tagDevWebGisInfo
{
    /** 编码 */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** 经度 */
    CHAR szLongitude[IMOS_STRING_LEN_32];

    /** 纬度 */
    CHAR szLatitude[IMOS_STRING_LEN_32];

    /** 指向 */
    CHAR    szDirection[IMOS_STRING_LEN_32];

    /** 视角 */
    CHAR szViewAngle[IMOS_STRING_LEN_32];

    /** 设备类型 */
    ULONG_32 ulDevType;

    /** 地图类型-离线地图是4 */
    ULONG_32 ulMapType;
}DEV_WEBGIS_INFO_S;


/**
* @struct tagBMResQueryItemV2
* @brief BM备份资源的信息项(查询BM备份资源列表时返回)
* @attention 无
*/
typedef struct tagBMResQueryItemV2
{
    /** 备份资源编码 */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** BM编码, BM的唯一标识 */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM名称 */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** 资源名称 */
    CHAR  szResName[IMOS_NAME_LEN];

    /** 备份资源类型#BAK_RES_TYPE_E */
    ULONG_32 ulResType;

    /** 存储设备名称 */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** 备份资源状态#BAK_RES_STATUS_E */
    ULONG_32 ulResStatus;

    /** 总容量大小，以MB为单位 */
    ULONG_32 ulTotalCapacity;

    /** 剩余容量大小，以MB为单位 */
    ULONG_32 ulSpareCapacity;

    /** 备份资源全路径-第三方资源才有效 */
    CHAR  szResPath[IMOS_FILE_PATH_LEN];

    /** 资源业务类型，枚举值为#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;

    /** LUN ID */
    ULONG_32  ulLunId;                        

    /** Target名 */
    CHAR    szBmTarget[IMOS_STRING_LEN_64];    

    /** Initiator名 */
    CHAR    szInitiator[IMOS_STRING_LEN_64];   

    /* IPSAN设备地址 */
    CHAR    szDevAddress[IMOS_IPADDR_LEN];     

    /** 保留字段 */
    CHAR  szReserve[256];      
    
} BM_RES_QUERY_ITEM_S_V2;

typedef struct tagDomainProtocolInfo
{
    /** 协议类型*/
    ULONG_32    ulProtocolType;
    
    /** 协议描述 */
    CHAR    szProtocolDesc[IMOS_CODE_LEN];

    /** SG 编码*/
    CHAR    szSGCode[IMOS_DEVICE_CODE_LEN];
    
    /** 支持该协议的SG IP地址 */
    CHAR    szSGIp[IMOS_IPADDR_LEN];

    /** 支持该协议的SG 端口 */
    ULONG_32   ulSGPort;

    /** 该SG是否为默认SG */
    ULONG_32   IsDefaultSG;
}DOMAIN_PROTOCOL_INFO_S;



/**
 * @struct tagNewOSDRowCommonParamV2
 * @brief NewOSD 通用参数
 * @attention
 */
typedef struct tagNewOSDRowCommParamV2
{
    ULONG_32  ulFontEffect;                  /** 字体效果 */

    ULONG_32  ulFontSize;                    /** 字体大小 */
    
    ULONG_32       ulOsdDateFormat;          /* OSD时间格式 */
    
    ULONG_32       ulOsdMinMargin;           /* 最小间距 */
    
   
    CHAR  szReserve[128];                   /** 保留字段 */

}NEW_OSD_ROW_COMM_PARAM_S_V2;


/**
 * @struct tagVideoArea
 * @brief 视频区域信息
 * @attention
 */
typedef struct tagVideoAreaV2
{
    /** 区域索引, 取值为1~4 */
    ULONG_32       ulAreaIndex;

    /** 是否使能, 1为使能; 0为非使能 */
    ULONG_32       ulEnabledFlag;

    /** 灵敏度, 1～5级，1级灵敏度最高。该值仅对运动检测区域有效 */
    ULONG_32       ulSensitivity;

    /** 区域坐标 */
    AREA_SCOPE_S stAreaScope;
    
    /* 对齐方式 */
    ULONG_32       ulFontAlign;

    /** 保留字段 */
    CHAR  szReserve[128]; 

}VIDEO_AREA_S_V2;

typedef struct tagDnsInfo
{
    CHAR szPreferredDNS[IMOS_IPADDR_LEN];    /** 首选DNS服务器IP地址 */
    CHAR szAlternateDNS[IMOS_IPADDR_LEN];    /** 备选DNS服务器IP地址*/
}DNS_INFO_S;

typedef struct tagNicInfo
{
    ULONG       ulNicIndex;             /** 网卡序号 */
    ULONG       ulNicModeType;          /** 网卡速率类型 对应枚举ETH_SPEED_E 默认自适应，界面不可配置*/
    CHAR        szIPv4Addr[IMOS_IPADDR_LEN];        /** IPv4IP地址 */
    CHAR        szIPv4NetMask[IMOS_IPADDR_LEN];     /** IPv4子网掩码 */
    CHAR        szIPv4Gateway[IMOS_IPADDR_LEN];     /** IPv4默认网关 */
    CHAR        szMacAddr[IMOS_MAC_ADDR_LEN];       /** MAC地址*/
    ULONG       ulMtu;          /** MTU 默认1500 */
    ULONG       ulVirtualIPEnabled; /** 是否开启虚拟IP地址 0-不开启(默认) 1-开启*/
    CHAR        szVirtualIPAddr[IMOS_IPADDR_LEN];   /** 虚拟IP地址 */
    CHAR        szVirtualIPNetMask[IMOS_IPADDR_LEN];        /** 虚拟IP子网掩码 */
    CHAR        szVirtualIPGateWay[IMOS_IPADDR_LEN];        /** 虚拟IP网关 */
}NIC_INFO_S;

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

