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
   Description: ���ݽṹ�����ĵ�

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
���ýṹ
****************************************************************************/

/***************************�û���¼����Բ���ʱЯ������Ϣ******************/
#include "sdk_def.h"
/**
 * @struct tagUserLoginIDInfo
 * @brief �û���¼ID��Ϣ�ṹ
 * @attention
 */
typedef struct tagUserLoginIDInfo
{
    /** �û����� */
    CHAR szUserCode[IMOS_USER_CODE_LEN];

    /** �û���¼ID�����û���¼�����������ģ����Ǳ��һ���û���¼��Ψһ��ʶ */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

    /** �û���¼�Ŀͻ���IP��ַ */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

} USER_LOGIN_ID_INFO_S;


/************************************ʱ��ṹ*****************************/

/***********************��ͨ��ʱ��ṹ����ҵ��Ϊ���ģ��ṩ����ʱ��ƻ�***************************************/



/**
 * @struct tagTimeSlice
 * @brief ����ʱ��Ƭ��Ϣ
 * @attention 00:00:00~23:59:59��ʾһ�����ʱ��Ƭ
 */
typedef struct tagTimeSlice
{
    /** ��ʼʱ�� ��ʽΪ"hh:mm:ss"��"YYYY-MM-DD hh:mm:ss", ��ʹ��������� */
    CHAR        szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� ��ʽΪ"hh:mm:ss"��"YYYY-MM-DD hh:mm:ss", ��ʹ��������� */
    CHAR        szEndTime[IMOS_TIME_LEN];

}TIME_SLICE_S;


/**
 * @struct tagTimeSliceInfo
 * @brief ʱ��Ƭ��Ϣ
 * @attention
 */
typedef struct tagTimeSliceInfo
{
    /** ����ʱ��Ƭ��Ϣ */
    TIME_SLICE_S    stTimeSlice;

}TIME_SLICE_INFO_S;

/**
 * @struct tagPlanWeekTime
 * @brief �ƻ�ʱ����Ϣ
 * @attention
 */
typedef struct tagPlanWeekTime
{
    /** �ܼ� */
    ULONG_32       ulWeekDay;

    /** ʱ����Ϣ, ���еĿ�ʼʱ��ͽ���ʱ���ʽΪ"hh:mm:ss" */
    TIME_SLICE_INFO_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];

}PLAN_WEEKTIME_S;


/**
 * @struct tagPlanExtTime
 * @brief �ƻ�����ʱ����Ϣ, ����������ƻ�ʱ��ʱʹ��. ����ƻ����������ƻ��Ļ��������õ�����ִ�мƻ�.
 * @attention
 */
typedef struct tagPlanExtTime
{
    /** ������������, ȡֵΪ0~6: 0��ʾ����, 1~6��ʾ��һ������ */
    ULONG_32       ulDateIndex;

    /** ��������, ��ʽΪ"YYYY-MM-DD" */
    CHAR        szExtDate[IMOS_SIMPLE_DATE_LEN];

    /** ʱ��Ƭ������ʱ��Ƭ��ʵ������ */
    ULONG_32       ulTimeSliceNum;

    /** ʱ��Ƭ����, ���еĿ�ʼʱ��ͽ���ʱ��ĸ�ʽΪ"hh:mm:ss" */
    TIME_SLICE_INFO_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];
}PLAN_EXTTIME_S;

/**
 * @struct tagPlanTime
 * @brief �ƻ�ʱ����Ϣ�ṹ
 * @attention
 */
typedef struct tagPlanTime
{
    /** ��ʱ��ƻ� */
    PLAN_WEEKTIME_S astPlanTime[IMOS_WEEK_DAYS];

    /** ����ʱ������������ʱ���ʵ������, ���ȡֵΪ#IMOS_EXCP_DAYS */
    ULONG_32       ulPlanExtTimeNum;

    /** ����ʱ������ */
    PLAN_EXTTIME_S astPlanExtTime[IMOS_EXCP_DAYS];

}PLAN_TIME_S;


/*******************��ҵ���ʱ���Ϊ���ģ�ÿ��ʱ���������ͬҵ��Ĳ�ͬ��Դ***************************************/

/**
 * @struct tagTimeSliceForRes
 * @brief ������Դ�������Դ���Ƶ�ʱ��Ƭ��Ϣ
 * @attention
 */
typedef struct tagTimeSliceForRes
{
    /** ��ʱ��ε���Դ���� */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** ��ʱ��ε���Դ���� */
    CHAR        szResName[IMOS_NAME_LEN];

    /** ʱ��Ƭ��Ϣ, ���еĿ�ʼʱ��ͽ���ʱ��ĸ�ʽΪ"hh:mm:ss" */
    TIME_SLICE_S    stTimeSlice;

}TIME_SLICE_FOR_RES_S;


/**
 * @struct tagPlanWeekTimeForRes
 * @brief ��ʱ��ƻ���Ϣ
 * @attention
 */
typedef struct tagPlanWeekTimeForRes
{
    /** �ܼ�, 0��ʾ����, 1~6��ʾ��һ������ */
    ULONG_32       ulWeekDay;

    /** ʱ����Ϣ */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];

}PLAN_WEEKTIME_FOR_RES_S;


/**
 * @struct tagPlanExtTimeForRes
 * @brief ����ʱ����Ϣ
 * @attention
 */
typedef struct tagPlanExtTimeForRes
{
    /** �������� ��ʽΪ"YYYY-MM-DD" */
    CHAR        szExtDate[IMOS_TIME_LEN];

    /** ����ʱ��Ƭ����������ʱ��Ƭ��ʵ�ʸ��� */
    ULONG_32       ulTimeSliceNum;

    /** ����ʱ��Ƭ���� */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM];
}PLAN_EXTTIME_FOR_RES_S;

/**
 * @struct tagPlanTimeForRes
 * @brief �ƻ�ʱ����Ϣ
 * @attention
 */
typedef struct tagPlanTimeForRes
{
    /** ��ʱ��ƻ� */
    PLAN_WEEKTIME_FOR_RES_S astPlanTime[IMOS_WEEK_DAYS];

    /** ����ʱ��ƻ�������ʵ�ʵ�����ʱ��ƻ�����, ���ȡֵΪ#IMOS_EXCP_DAYS */
    ULONG_32       ulPlanExtTimeNum;

    /** ����ʱ��ƻ����� */
    PLAN_EXTTIME_FOR_RES_S  astPlanExtTime[IMOS_EXCP_DAYS];

}PLAN_TIME_FOR_RES_S;

#if 0
/**
 * @struct tagPlanWeekTimeForRes
 * @brief ��ʱ��ƻ���Ϣ
 * @attention
 */
typedef struct tagTimeSliceForResV2
{
    /* �Ƿ�Ϊ�ܼ��ı�־�����ΪBOOL_FALSE����ʹ���ַ����ľ���ʱ�� */
    ULONG_32 bWeekDayFlag;

    /** ʱ���ִ���� \n
     * �����ܼƻ���Ϊ�ܼ� \n
     * ������ƻ��������� */
    ULONG_32       ulPlanDay;

    /** ʱ���ִ���գ���ʽΪ"YYYY-MM-DD" */
    CHAR        szPlanDay[IMOS_SIMPLE_DATE_LEN];

    /** ʱ�����������־�ǵ���ĵڼ���ʱ��� */
    ULONG_32       ulTimeIndex;

    /** ��ʼʱ�䣬��ʽΪ"HH:MM:SS" */
    CHAR        szStartTime[IMOS_SIMPLE_TIME_LEN];

    /** ����ʱ�䣬��ʽΪ"HH:MM:SS" */
    CHAR        szEndTime[IMOS_SIMPLE_TIME_LEN];

    /** ʱ��β��� */
    CHAR        szParam[IMOS_STRING_LEN_256];

}TIME_SLICE_FOR_RES_V2_S;

/**
 * @struct tagPlanTimeForResV2
 * @brief �ƻ�ʱ����ϢV2��
 * @attention
 */
typedef struct tagPlanTimeForResV2
{
    /** ʱ��ƻ�����, ���ȡֵΪ# */
    ULONG_32       ulPlanTimeNum;

    /** ����ʱ��ƻ����� */
    TIME_SLICE_FOR_RES_V2_S  astPlanTime[1];

}PLAN_TIME_FOR_RES_V2_S;
#endif

/**
 * @struct tagTimeSliceForRes
 * @brief ������Դ�������Դ���Ƶ�ʱ��Ƭ��Ϣ
 * @attention
 */
typedef struct tagTimeSliceForResV2
{
    /** ��ʱ��ε���Դ���� */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** ��ʱ��ε���Դ���� */
    CHAR        szResName[IMOS_NAME_LEN];

    /** ʱ��Ƭ��Ϣ, ���еĿ�ʼʱ��ͽ���ʱ��ĸ�ʽΪ"hh:mm:ss" */
    TIME_SLICE_S    stTimeSlice;

}TIME_SLICE_FOR_RES_V2_S;


/**
 * @struct tagPlanWeekTimeForRes
 * @brief ��ʱ��ƻ���Ϣ
 * @attention
 */
typedef struct tagPlanWeekTimeForResV2
{
    /** �ܼ�, 0��ʾ����, 1~6��ʾ��һ������ */
    ULONG_32       ulWeekDay;

    /** ʱ��Ƭ��ʵ�ʸ��� */
    ULONG_32       ulTimeSliceNum;

    /** ʱ����Ϣ */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM_V2];

}PLAN_WEEKTIME_FOR_RES_V2_S;


/**
 * @struct tagPlanExtTimeForRes
 * @brief ����ʱ����Ϣ
 * @attention
 */
typedef struct tagPlanExtTimeForResV2
{
    /** �������� ��ʽΪ"YYYY-MM-DD" */
    CHAR        szExtDate[IMOS_TIME_LEN];

    /** ����ʱ��Ƭ����������ʱ��Ƭ��ʵ�ʸ��� */
    ULONG_32       ulTimeSliceNum;

    /** ����ʱ��Ƭ���� */
    TIME_SLICE_FOR_RES_S astTimeInfo[IMOS_MAX_TIME_SLICE_NUM_V2];
}PLAN_EXTTIME_FOR_RES_V2_S;

/**
 * @struct tagPlanTimeForRes
 * @brief �ƻ�ʱ����Ϣ
 * @attention
 */
typedef struct tagPlanTimeForRes_V2
{
    /** ��ʱ��ƻ� */
    PLAN_WEEKTIME_FOR_RES_V2_S astPlanTime[IMOS_WEEK_DAYS];

    /** ����ʱ��ƻ�������ʵ�ʵ�����ʱ��ƻ�����, ���ȡֵΪ#IMOS_EXCP_DAYS */
    ULONG_32       ulPlanExtTimeNum;

    /** ����ʱ��ƻ����� */
    PLAN_EXTTIME_FOR_RES_V2_S  astPlanExtTime[IMOS_EXCP_DAYS];

}PLAN_TIME_FOR_RES_V2_S;



/*******************************�ϴ����ع�����Ϣ***************************************/

/**
 * @struct tagFileBasicInfo
 * @brief �ļ�������Ϣ
 * @attention
 */
typedef struct tagFileBasicInfo
{
    /** �ļ�����, ���������û�����, ���ڱ�ʶ���ļ� */
    CHAR            szName[IMOS_NAME_LEN];

    /** �ļ���ʵ������, �����Ƽ��ļ����ļ�ϵͳ�е����� */
    CHAR            szFileName[IMOS_FILE_NAME_LEN];

    /** �ļ��ϴ�ʱ�䣬���ڱȶԿͻ����ļ��Ƿ������µ��ļ� */
    CHAR            szUploadTime[IMOS_TIME_LEN];
}FILE_BASIC_INFO_S;

/**
 * @struct tagLayerBasicInfo
 * @brief �ļ�������Ϣ
 * @attention
 */
typedef struct tagLayerBasicInfo
{
    /** �ļ���ʵ������, �����Ƽ��ļ����ļ�ϵͳ�е����� */
    CHAR            szLayerName[IMOS_NAME_LEN];

    /** �ļ��ϴ�ʱ�䣬���ڱȶԿͻ����ļ��Ƿ������µ��ļ� */
    CHAR            szUploadTime[IMOS_TIME_LEN];
}LAYER_BASIC_INFO_S;

/**
 * @struct tagFtpInfo
 * @brief FTP������Ϣ
 * @attention
 */
typedef struct tagFtpInfo
{
    /** FTP�û��� */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** FTP���� */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** FTP����������ļ�·����������"/Program_Files/H3C/IMOS"�ķ�ʽ��ʾ */
    CHAR    szFtpFilePath[IMOS_FILE_PATH_LEN];
}FTP_INFO_S;

/**
 * @struct tagFileOnServerInfo
 * @brief �ļ���FTP�������ϵ��й���Ϣ
 * @attention
 */
typedef struct tagFileOnServerInfo
{
    /** �ļ����ƣ��ļ�ʵ�ʱ�������� */
    CHAR            szFileName[IMOS_FILE_PATH_LEN];

    /** FTP������Ϣ */
    FTP_INFO_S  stFtpInfo;
}FILE_ON_SERVER_INFO_S;


/*********************************��ѯ����**********************************/
/**
 * @struct tagQueryPageInfo
 * @brief ��ҳ������Ϣ
 * @brief ����ѯ���ݵ�ÿ���������Ӧһ����š���Ŵ�1��ʼ���������ӡ�
 * - ��ѯ���Ľ����ҳ����ʽ���أ�ÿ�β�ѯֻ�ܷ���һҳ��ҳ������������ulPageRowNum�趨����ΧΪ1~200��
 * - ÿ�β�ѯ�������ôӴ���ѯ�������ض���ţ�ulPageFirstRowNumber����ʼ
 * @attention
 */
typedef struct tagQueryPageInfo
{
    /** ��ҳ��ѯ��ÿҳ�������Ŀ��, ����Ϊ0, Ҳ���ܴ���#IMOS_PAGE_QUERY_ROW_MAX_NUM */
    ULONG_32 ulPageRowNum;

    /** ��ҳ��ѯ�е�һ�����ݵ����(����ѯ�ӵ�ulPageFirstRowNumber�����ݿ�ʼ�ķ�������������), ȡֵ����ULONG���͵ķ�Χ���� */
    ULONG_32 ulPageFirstRowNumber;

    /** �Ƿ��ѯ��Ŀ����, BOOL_TRUEʱ��ѯ; BOOL_FALSEʱ����ѯ */
    BOOL_T bQueryCount;
}QUERY_PAGE_INFO_S;


/**
 * @struct tagRspPageInfo
 * @brief ��ҳ��Ӧ��Ϣ
 * @attention
 */
typedef struct tagRspPageInfo
{
    /** ʵ�ʷ��ص���Ŀ�� */
    ULONG_32 ulRowNum;

    /** ��������������Ŀ�� */
    ULONG_32 ulTotalRowNum;
}RSP_PAGE_INFO_S;

/**
 * @struct tagRecRspRowInfo
 * @brief  ͳһ¼�������Ӧ��Ϣ
 * @attention
 */
typedef struct tagRecRspRowInfo
{
    /** ʵ�ʷ��ص�¼�����Ŀ */
    ULONG_32 ulRowNum;

    /** �Ƿ������� */
    ULONG_32 bHasMoreRow;

    /** ����¼����ܽ���ʱ�� */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** �����ֶ� */
    CHAR  szReserve[32];
}REC_RSP_ROW_INFO_S;

/**
 * @struct tagQueryConditionInfo
 * @brief �ƻ����ѯ�����������ƣ���ʱ���ѯ��
 * @attention
 */
typedef struct tagQueryConditionInfo
{
    /** ����ö�ٱ��λ:#NAME_CODE_FLAG_E */
    ULONG_32   ulNameCodeFlag;

    /** ������ģʽ:#SEARCH_MODE_E */
    ULONG_32   ulSearchMode;

    /** �豸���ƻ���Դ���� */
    CHAR    szNameCode[IMOS_NAME_LEN];

    /** ʱ��ö�ٱ��λ:#TIME_FLAG_E */
    ULONG_32   ulTimeFlag;

    /** ʱ�����Ϣ, ���п�ʼʱ��ͽ���ʱ��ĸ�ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stTimeSlice;

} QUERY_CONDITION_INFO_S;


/**
 * @struct tagQueryByName
 * @brief �����ƽ���ģ����ѯ��
 * @attention
 */
typedef struct tagQueryByName
{
    /** �豸���ƻ���Դ���� */
    CHAR    szName[IMOS_NAME_LEN];
} QUERY_BY_NAME_S;


/***************************************************************************************
��Ƶ�������
***********************************************************************************/


#if 0 /** ��Ƶ */
#endif
/**
 * @struct tagAudioInput
 * @brief ��Ƶ����ͨ����Ϣ
 * @attention
 */
typedef struct tagAudioInput
{
    /** �Ƿ�ʹ�� 0/1:��ʹ��/ʹ�� */
    ULONG_32       ulAudioEnabled;

    /** ��Ƶ���룬ȡֵ��ΧΪ #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** ��Ƶ������ȡֵ��ΧΪ #IMOS_AUDIO_CHANNEL_TYPE_E  */
    ULONG_32       ulTrack;

    /** �����ʣ�ȡֵ��ΧΪ #IMOS_AUDIO_SAMPLING_E */
    ULONG_32       ulSamplingRate;

    /** ���� */
    ULONG_32       ulEncodeRate;

    /** ��������ֵ��ȡֵ��ΧΪ0-255��Ĭ��0  */
    ULONG_32       ulIncrement;

    /** ��Ƶ�������� */
    CHAR        szDesc[IMOS_DESC_LEN];

}AUDIO_INPUT_INFO_S;



/**
 * @struct tagAudioOutput
 * @brief ��Ƶ���ͨ����Ϣ
 * @attention
 */
typedef struct tagAudioOutput
{
    /** ʹ�ܱ�ʶ */
    ULONG_32       ulAudioEnabled;

    /** ��Ƶ���룬ȡֵ��ΧΪ #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** ��Ƶ������ȡֵ��ΧΪ #IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32       ulTrack;

    /** ����ֵ */
    ULONG_32       ulVolume;

    /** ��Ƶ������� */
    CHAR        szDesc[IMOS_DESC_LEN];

}AUDIO_OUTPUT_INFO_S;

/************************************************************************************
�û���¼
*************************************************************************************/
#if 0
/**
* @struct  tagLoginInfo
* @brief �û���¼��Ϣ�ṹ��
* @attention ��
*/
typedef struct tagLoginInfo
{
    /** �û���¼��Ϣ */
    USER_LOGIN_ID_INFO_S    stUserLoginIDInfo;

    /** �û�������֯���� */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �û����������� */
    CHAR szDomainName[IMOS_NAME_LEN];

    /** �û����������� */
    ULONG_32 ulDomainType;

    /** XP���� */
    CHAR szXpCode[IMOS_DEVICE_CODE_LEN];

    /** XP��һ������� */
    CHAR szXpFirstWndCode[IMOS_RES_CODE_LEN];

    /** �����Խ����� */
    CHAR szVoiceTalkCode[IMOS_RES_CODE_LEN];

    /** �����㲥���� */
    CHAR szVoiceBroadcastCode[IMOS_RES_CODE_LEN];

    /** SIPͨ�ŵ�ַ���ͣ�ֵΪ:IMOS_IPADDR_TYPE_IPV4/IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32 ulSipAddrType;

    /** SIP������ͨ��IP��ַ������ʹ��XP��ʱ����Ч */
    CHAR szSipIpAddress[IMOS_IPADDR_LEN];

    /** SIP������ͨ�Ŷ˿ں� */
    ULONG_32 ulSipPort;

    /** ������������� */
    CHAR szServerCode[IMOS_DEVICE_CODE_LEN];
}LOGIN_INFO_S;

#endif

/**
* @struct tagLoginInfo
* @brief �û���¼��Ϣ�ṹ��
* @attention ��
*/
typedef struct tagLoginInfo
{
    /** �û���¼ID��Ϣ */
    USER_LOGIN_ID_INFO_S    stUserLoginIDInfo;

    /** �û�������֯���� */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �û����������� */
    CHAR szDomainName[IMOS_NAME_LEN];

    /** �û�����������, ȡֵΪ#MM_DOMAIN_SUBTYPE_LOCAL_PHYSICAL��#MM_DOMAIN_SUBTYPE_LOCAL_VIRTUAL */
    ULONG_32 ulDomainType;
}LOGIN_INFO_S;

/**
* @struct tagXpInfo
* @brief XP��Ϣ�ṹ��
* @attention ��
*/
typedef struct tagXpInfo
{
    /** XP���� */
    CHAR szXpCode[IMOS_DEVICE_CODE_LEN];

    /** ���� */
    ULONG_32 ulScreenIndex;

    /** XP��һ������� */
    CHAR szXpFirstWndCode[IMOS_RES_CODE_LEN] ;

    /** �����Խ����� */
    CHAR szVoiceTalkCode[IMOS_RES_CODE_LEN] ;

    /** �����㲥���� */
    CHAR szVoiceBroadcastCode[IMOS_RES_CODE_LEN] ;

    /** SIPͨ�ŵ�ַ���ͣ�#IMOS_IPADDR_TYPE_IPV4ΪIPv4����; #IMOS_IPADDR_TYPE_IPV6ΪIPv6���� */
    ULONG_32 ulSipAddrType ;

    /** SIP������ͨ��IP��ַ������ʹ��XP��ʱ����Ч */
    CHAR szSipIpAddress[IMOS_IPADDR_LEN] ;

    /** SIP������ͨ�Ŷ˿ں� */
    ULONG_32 ulSipPort;

    /** ������������� */
    CHAR szServerCode[IMOS_DEVICE_CODE_LEN] ;

} XP_INFO_S;

/**
 * @struct tagXpStreamInfo
 * @brief XPʵʱ�������Ϣ�ṹ
 * @attention
 */
typedef struct tagXpStreamInfo
{
    /** ֧�ֵĵ��鲥���ͣ�0Ϊ��֧�ֵ�����1Ϊ��֧�ֵ���Ҳ֧���鲥 */
    ULONG_32 ulStreamType;

    /** ֧�ֵ�������Э�� �μ�#IMOS_TRANS_TYPE_E��ĿǰXPֻ֧������Ӧ��TCP */
    ULONG_32 ulStreamTransProtocol;

    /** ֧�ֵ������䷽ʽ �μ�#IMOS_STREAM_SERVER_MODE_E��ĿǰXPֻ֧������Ӧ��ֱ������ */
    ULONG_32 ulStreamServerMode;

    /* Begin ModifyBy liuhongjieKF0170,2013-10-22 of �����Խ���MS */
    /** ֧�ֵ������Խ����䷽ʽ �μ�#IMOS_STREAM_SERVER_MODE_E��ĿǰXPֻ֧������Ӧ�Ͳ�����MS */
    ULONG_32 ulVoiceCommMode;

    /** �����ֶ� */
    CHAR  szReserve[28];
    /* End ModifyBy liuhongjieKF0170,2013-10-22 of �����Խ���MS */
}XP_STREAM_INFO_S;

/**
* @struct tagUserLoginIDInfo
* @brief ������������Ϣ�ṹ��
* @attention
*/
typedef struct tagPlayWndInfo
{
    /** ���Ŵ�����Դ���� */
    CHAR szPlayWndCode[IMOS_RES_CODE_LEN];
}PLAY_WND_INFO_S;

/************************************************************************************
��ɫ
*************************************************************************************/
/**
 * @struct tagUserRoleInfo
 * @brief ��ɫ��ϸ��Ϣ
 * @attention
 */
typedef struct tagUserRoleInfo
{
    /** ��ɫ���� */
    CHAR        szRoleName[IMOS_NAME_LEN];

    /** ��ɫ���ȼ���ȡֵ��ΧΪ1-9��1�����ȼ���ߣ�9�����ȼ���� */
    ULONG_32       ulRolePriority;

    /** ��ɫ���������Բ��� */
    CHAR        szRoleDesc[IMOS_DESC_LEN];

    /** ��ɫ������֯����� */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��ɫ���ͣ�����ӱ����ɫʱ��ֵΪ1 */
    ULONG_32       ulRoleType;

    /** ��չ��Ϣ���û������ֶΣ����Բ��� */
    CHAR        szExternInfo[IMOS_STRING_LEN_32];
}USER_ROLE_INFO_S;

/**
 * @struct tagRoleNameQueryItem
 * @brief ��ɫ���롢������Ϣ�����ͨ������Ϣ����ý�ɫ�ľ�����Ϣ
 * @attention
 */
typedef struct tagRoleNameQueryItem
{
    /** ��ɫ���� */
    CHAR        szRoleName[IMOS_NAME_LEN];

    /** ��ɫ���룬��ɫ��Ψһ��ʶ */
    CHAR        szRoleCode[IMOS_RES_CODE_LEN];
}ROLE_NAME_QUERY_ITEM_S;

/**
 * @struct tagRoleQueryItem
 * @brief ��ɫ��Ϣ��(��ѯ��ɫ�б�ʱ����)
 * @attention
 */
typedef struct tagRoleQueryItem
{
    /** ��ɫ���롢������Ϣ */
    ROLE_NAME_QUERY_ITEM_S  stRoleIndexItem;

    /** ��ɫ���ȼ���ȡֵ��ΧΪ1-9��1�����ȼ���ߣ�9�����ȼ���� */
    ULONG_32                       ulRolePriority;

    /** ��ɫ���� */
    CHAR                        szRoleDesc[IMOS_DESC_LEN];

    /** ��ɫ������֯���� */
    CHAR                        szOrgName[IMOS_NAME_LEN];

    /** ��ɫ������֯���� */
    CHAR                        szOrgCode[IMOS_DOMAIN_CODE_LEN];
}ROLE_QUERY_ITEM_S;

/**
* @struct tagAuthorityItem
* @brief ��ͨȨ����Ϣ
* @attention ��
*/
typedef struct tagAuthorityItem
{
    /** Ȩ�����֣�ÿ��ȡֵΨһ����һ��Ȩ�����ͣ����ɲ�Ʒ�趨Ȩ��ʱȷ�� */
    ULONG_32 ulAuthorityName;

    /** �Ƿ�߱�Ȩ�����ֶ�Ӧ��Ȩ��, BOOL_TRUEΪ���и�Ȩ��, BOOL_FALSEΪ�����и�Ȩ�� */
    BOOL_T bHasAuthority;

} AUTHORITY_ITEM_S;

/**
* @struct tagOrgAuthority
* @brief ��֯���Ȩ����Ϣ
* @attention ��
*/
typedef struct tagOrgAuthority
{
    /** Ȩ����Ϣ���� */
    AUTHORITY_ITEM_S astAuthorities[IMOS_AUTHORITY_MAX_NUM];

    /** Ȩ����Ϣ������ʵ�ʵ�Ȩ����Ϣ����, ��ȡ�����ֵΪ#IMOS_AUTHORITY_MAX_NUM */
    ULONG_32 ulAuthCount;

} ORG_AUTHORITY_S;

/**
* @struct tagOrgAuthorityV2
* @brief ��֯���Ȩ����Ϣ
* @attention ��
*/
typedef struct tagOrgAuthorityV2
{
    /** Ȩ����Ϣ���� */
    AUTHORITY_ITEM_S astAuthorities[IMOS_AUTHORITY_MAX_NUM_EX];

    /** Ȩ����Ϣ������ʵ�ʵ�Ȩ����Ϣ����, ��ȡ�����ֵΪ#IMOS_AUTHORITY_MAX_NUM_EX */
    ULONG_32 ulAuthCount;

} ORG_AUTHORITY_V2_S;




/**
 * @struct tagQueryRoleConditionInfo
 * @brief ��ѯ���µĽ�ɫ�б�
 * @attention ROLE_ORDER_INFO_S��ҪUI�ṩ
*/
typedef struct tagQueryRoleConditionInfo
{
    /** ��֯����� */
    CHAR    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��ɫ���� */
    CHAR    szRoleName[IMOS_NAME_LEN];

}QUERY_ROLE_CONDITION_INFO_S;

/**
* @struct tagResAuthority
* @brief ��Դ��Ȩ����Ϣ
* @attention ��
*/
typedef struct tagResAuthority
{
    /** Ȩ���б� */
    ORG_AUTHORITY_V2_S  stAuthorities;

    /** ��ԴID����,ȫ��Ȩ��Ϊ�ַ���"0" */
    CHAR            szResIdCode[IMOS_CODE_LEN];

} RES_AUTHORITY_S;

/**
* @struct tagResInfo
* @brief ��Դ��Ϣ
* @attention ��
*/
typedef struct tagResInfo
{
    /** ��ԴID���ַ���"0"��ʾϵͳ */
    CHAR    szResIdCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR    szResCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR    szResName[IMOS_NAME_LEN];

    /** ��Դ���ͣ�ȡֵ��ΧΪ#IMOS_TYPE_E */
    ULONG_32   ulResType;

    /** ��Դ������,Ŀǰ��Դ������ֻ�������/��֯/����ʾ/����Ѳ��Ч�������������Ϊ��̨/����̨;
        ����֯����Ϊ:1-��������2-�����������3-�����������. 4-�ϼ���������.
        5-�¼���������.6-ƽ����������.
        ������ʾ��Դ��������ʾ���ͣ�ȡֵΪ#SALVO_TYPE_E
        ������Ѳ��Դ��������Ѳ���ͣ�ȡֵΪ#GROUP_SWITCH_TYPE_E */
    ULONG_32   ulResSubType;

    /** ������֯���� */
    CHAR        szOrgCode[IMOS_CODE_LEN];

    /** ������֯���� */
    CHAR        szOrgName[IMOS_NAME_LEN];

} RES_INFO_S;

/**
* @struct tagResAuthorityQueryItem
* @brief ��Դ��Ȩ���б�
* @attention ��
*/
typedef struct tagResAuthorityQueryItem
{
    /** Ȩ���б� */

    ORG_AUTHORITY_V2_S stAuthorities;

    /** ��Դ��Ϣ */
    RES_INFO_S stResInfo;
} RES_AUTHORITY_QUERY_ITEM_S;


/***************************************************************************************
�û�����
***********************************************************************************/

/**
 * @struct tagUserInfo
 * @brief �û���Ϣ
 * @attention
 */
typedef struct tagUserInfo
{

    /** �û����룬�û���Ψһ��ʶ */
    CHAR szUserCode[IMOS_USER_CODE_LEN];

    /** �û���¼�� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û�ȫ�������Բ��� */
    CHAR szUserFullName[IMOS_NAME_LEN];

    /** �û�������֯������ */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** �û������绰���룬���Բ��� */
    CHAR    szTelePhone[IMOS_PHONE_LEN];

    /** �û��ƶ��绰���룬���Բ��� */
    CHAR    szMobilePhone[IMOS_MOBILE_LEN];

    /** �û�������룬���Բ��� */
    CHAR    szFax[IMOS_PHONE_LEN];

    /** �û������ʼ������Բ��� */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** �û������Ƿ�����Ч��ʶ, 1Ϊ������Ч; 0Ϊ�ǳ�����Ч, Ŀǰ���ֶα��� */
    ULONG_32   ulPasswdPermanetFlag;

    /** �û�������Ч����, Ŀǰ���ֶα���, ���Բ��� */
    CHAR    szPasswdValidDate[IMOS_TIME_LEN];

    /** �û�������Ч����, Ŀǰ���ֶα��� */
    ULONG_32   ulPasswdValidDays;

    /** �û������Ƿ���Ч, 1Ϊ��Ч; 0Ϊ��Ч */
    ULONG_32   ulPasswdValidFlag;

    /** �û��Ƿ�����, 1Ϊ������; 0Ϊδ������ */
    ULONG_32   ulUserLockFlag;

    /** �û�����, Ŀǰ�̶�Ϊ#MM_USER_TYPE_LOCAL_DOMAIN */
    ULONG_32   ulUserType;

    /** �û����������Բ��� */
    CHAR    szUserDes[IMOS_DESC_LEN];

    /** �û���չ��Ϣ�����Բ��� */
    CHAR    szReserve[96];
}USER_INFO_S;



/**
 * @struct tagUserPasswordInfo
 * @brief �û���Ϣ(�����û���¼����)
 * @attention
 */
typedef struct tagUserPasswordInfo
{
    /** �û���Ϣ */
    USER_INFO_S   stUserInfo;

    /** �û���¼����,����Ϊ�� */
    CHAR    szPassword[IMOS_PASSWD_ENCRYPT_LEN];
}USER_INFO_PASSWORD_S;


/**
 * @struct  tagUserModifyPassword
 * @brief �û�������Ϣ
 * @attention
 */
typedef struct tagUserModifyPassword
{
    /** �û���¼�� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û������� */
    CHAR    szOldPassword[IMOS_PASSWD_ENCRYPT_LEN];

    /** �û������� */
    CHAR    szNewPassword[IMOS_PASSWD_ENCRYPT_LEN];
}USER_MODIFY_PASSWORD_S;


/**
 * @struct  tagUserQueryItem
 * @brief �û���Ϣ��(��ѯ�û��б�ʱ����)
 * @attention
 */
typedef struct tagUserQueryItem
{
    /** �û����� */
    CHAR szUserCode[IMOS_USER_CODE_LEN];

    /** �û���¼ID(���ڲ�����)����һ���û���¼��Ψһ��ʶ */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

    /** �û���¼�� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û�ȫ�� */
    CHAR szUserFullName[IMOS_NAME_LEN];

    /** �û�������֯������ */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** �û������绰���� */
    CHAR    szTelePhone[IMOS_PHONE_LEN];

    /** �û��ƶ��绰���� */
    CHAR    szMobilePhone[IMOS_MOBILE_LEN];

    /** �û������ʼ� */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** �û��Ƿ�����, 1Ϊ����; 2Ϊδ���� */
    ULONG_32   ulUserLockFlag;

    /** �û���¼�Ŀͻ��˵�ַ */
    CHAR szUserAddr[IMOS_IPADDR_LEN];

    /** �û���չ��Ϣ */
    CHAR    szExternInfo[IMOS_STRING_LEN_32];

    /** �û���¼ʱ�� */
    CHAR  szUserLoginTime[IMOS_TIME_LEN];

} USER_QUERY_ITEM_S;

/**
 * @struct  tagUserQueryItemV2
 * @brief �û���Ϣ��(��ѯ�û��б�V2�ӿ�ʱ����, ��չ����"�û�������֯�ı���")
 * @attention
 */
typedef struct tagUserQueryItemV2
{
    /** V1�û���Ϣ�� */
    USER_QUERY_ITEM_S stUserItemInfoV1;

    /** �û�������֯����� */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** �����ֶ� */
    CHAR szReserve[192];
}USER_QUERY_ITEM_V2_S;

/***************************************************************************************
��֯�������������
***********************************************************************************/

/**
 * @struct tagOrgBasicInfo
 * @brief ��֯�ڵ������Ϣ
 * @attention
 */
typedef struct tagOrgBasicInfo
{
     /** ��֯�ڵ���� */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��֯�ڵ����� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** ��(�ϼ�)��֯�ڵ���� */
    CHAR szOrgParentCode[IMOS_DOMAIN_CODE_LEN];

    /** ��֯�ڵ����� ,ȡֵΪ #MM_DOMAINTYPE_E */
    ULONG_32 ulOrgType;

    /** ��֯�ڵ��Ƿ��Ǳ����, 1Ϊ�Ǳ����; 0Ϊ���Ǳ���� */
    ULONG_32 ulIsLocalDomain;

    /** ��֯�ڵ�����,���Բ��� */
    CHAR szOrgDesc[IMOS_DESC_LEN];

    /** ��չ��Ϣ, ���Բ��� */
    CHAR szUserInfo[IMOS_STRING_LEN_256];
}ORG_BASIC_S;



/**
 * @struct tagOrgContactInfo
 * @brief ��֯�ڵ���ϵ��ʽ��Ϣ
 * @attention
 */
typedef struct tagOrgContactInfo
{
    /** ��ϵ�ˣ����Բ��� */
    CHAR szOrgContszt[IMOS_NAME_LEN];

    /** �ƶ��绰���룬���Բ��� */
    CHAR szOrgMobile[IMOS_MOBILE_LEN];

    /** ��ϵ��ַ�����Բ��� */
    CHAR szOrgAddr[IMOS_STRING_LEN_256];

    /** ������룬���Բ��� */
    CHAR szOrgFax[IMOS_PHONE_LEN];

    /** �������룬���Բ��� */
    CHAR szOrgTel[IMOS_PHONE_LEN];

    /** �����ʼ������Բ��� */
    CHAR szOrgEmail[IMOS_MAIL_LEN];

    /** �������룬���Բ��� */
    CHAR szOrgPostalCode[IMOS_MAIL_CODE_LEN];
}ORG_CONTACT_INFO_S;



/**
 * @struct tagOrgNodeInfo
 * @brief ��֯��ڵ���Ϣ����֯������Ϣ+��ϵ��ʽ��Ϣ��
 * @attention
 */
typedef struct tagOrgNodeInfo
{
    /** ��֯�ڵ������Ϣ */
    ORG_BASIC_S         stOrgBasicInfo;

    /** ��֯�ڵ���ϵ��ʽ��Ϣ */
    ORG_CONTACT_INFO_S  stOrgContactInfo;

}ORG_NODE_INFO_S;



/**
 * @struct tagAuthorizationInfo
 * @brief Ȩǩ��Ϣ
 * @attention
 */
typedef struct tagAuthorizationInfo
{
    /** �û��� */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** ���� */
    CHAR    szRealm[IMOS_STRING_LEN_64];

}AUTHORIZATION_INFO_S;

/**
 * @struct tagExDomain
 * @brief ����������Ϣ
 * @attention
 */
typedef struct tagExDomain
{
    /** �������, ����Ψһ��ʶ */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �������� */
    CHAR    szDomainName[IMOS_NAME_LEN];

    /** ��������(�ϼ���/�¼���/ƽ����), ȡֵΪ#EX_DOMAIN_TYPE_E */
    ULONG_32   ulOuterDomainType;

    /** ����ڵ���롣����޸��ڵ㣬����մ� */
    CHAR    szDomainParentCode[IMOS_DOMAIN_CODE_LEN];

    /** �������ȼ���ȡֵ��ΧΪ1-9��1�����ȼ���ߣ�9�����ȼ���� */
    ULONG_32   ulPriority;

    /** �������λ��ȡֵΪ#DOMAIN_STREAM_PULL_TYPE  */
    ULONG_32   ulIsSession;

    /** SIP�˿ڣ�H3C��Ϊ5061���������̰������� */
    ULONG_32   ulOuterDomainPort;

    /** ����鲥֧�ֲ���. 1Ϊ֧��; 0Ϊ��֧��, �������� */
    ULONG_32   ulBroadcastStrategy;

    /** �����ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32   uladdrtype;

    /** �����ַ */
    CHAR    szDomainAddr[IMOS_IPADDR_LEN];

     /** �����������, ȡֵ��ΧΪ0~9999 */
    ULONG_32 ulInTrunkNum;

    /** ��������
        ���ڷ�OEM�汾(VM8500��H3C�豸),ȡֵΪ
            #IMOS_MANUFACTURER_TYPE_VMISC
            #IMOS_MANUFACTURER_TYPE_DA
            #IMOS_MANUFACTURER_TYPE_OTHER
        ����OEM�汾(PL/PL-S),ȡֵΪ
            #IMOS_MANUFACTURER_TYPE_PL
            #IMOS_MANUFACTURER_TYPE_PLS
            #IMOS_MANUFACTURER_TYPE_OTHER */
    CHAR szManufacturerType[IMOS_STRING_LEN_64];

    /** �����е���ȼ�����Ч��ΧΪ1��7 */
    ULONG_32 ulDomainLevel;

    /** ���ͨѶЭ�����ͣ�ȡֵΪ#INTERDOMAIN_PROTOCOL_TYPE_E */
    ULONG_32 ulProtocolType;

    /** ����ע��״̬��ָ������ǰ�������ע���Ƿ�ɹ�, 1Ϊ�ɹ�; 2Ϊʧ�� */
    ULONG_32                     ulActiveRegSta;

    /** ����ע��״̬��ָ��ǰ�����������ע���Ƿ�ɹ�, 1Ϊ�ɹ�; 2Ϊʧ�� */
    ULONG_32                     ulRecvRegSta;

    /** ����������룬Ŀǰֻ֧��DB33��׼������룬�����޸� */
    CHAR  szInterDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �������û����룬��Ҫ���������õĻ����û�����һ�£������޸� */
    CHAR  szInterUserCode[IMOS_USER_CODE_LEN];

    /** ����ʹ��MS���ԣ�BOOL_TRUEΪ����Ӧ��BOOL_FALSEΪָ�� */
    BOOL_T bIsAutofit;

    /** ����ָ����MS���� */
    CHAR  szMSCode[IMOS_DEVICE_CODE_LEN];

    /** �����ý���Э������,ȡֵΪ#IMOS_TRANS_TYPE_E��Ŀǰ����ֻ֧������Ӧ��TCP */
    ULONG_32 ulStreamTransProtocol;

    /** ������ֱ��ý��������,ȡֵΪ��1~2048��ȱʡΪ1024 */
    ULONG_32 ulStreamByPassMaxNum;

    /** ���ʵ����������������Ӧƥ�����,ȡֵ�μ�#MON_STREAM_ANY_MATCH_POLICY_E */
    ULONG_32 ulMonStreamMatchPolicy;

    /** �����ֶ� */
    CHAR szReserve[20];
}EX_DOMAIN_S;


/**
 * @struct tagExDomainV2
 * @brief ���������ݽṹ������������ϢV2
 * @attention
 */
typedef struct tagExDomainV2
{
    EX_DOMAIN_S        stExDomainInfo;

    /** ����ע���Ƿ���ҪȨǩ��1��ʾ��Ҫ��0��ʾ�� */
    BOOL_T             bNeedAuthorize;

    /** Ȩǩ��Ϣ */
    AUTHORIZATION_INFO_S    stAuthorization;

    /** DecoderTag��Ϣ */
    CHAR szDecoderTag[IMOS_DECODERTAG_LEN];

    /** ����ģʽ ��ͨ����ģʽ��#CTRL_MODE_NORMAL����ǿ����ģʽ��#CTRL_MODE_FULL�� */
    ULONG_32 ulCtrlMode;

    /** �����URL */
    CHAR  szDomainURL[IMOS_URL_LEN];

    /** �ط��м̲���#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulPlaybackAutofit;

    /** ��Ƶ�м̲���#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulVoicecommAutofit;

    /** �豸��ַ�� */
    ULONG_32 ulSafeDevAddrcode;

    /* Begin:Modified by gaoshufeng(00762),2014-4-21 for MPPD11595 */
    /** ONVIF����תTSģʽ */
    ULONG_32 ulONVIFTransPackMode;

    /** �����ֶ� */
    CHAR   szReserve[120];
    /* End:Modified by gaoshufeng(00762),2014-4-21 for MPPD11595 */
}EX_DOMAIN_V2_S;

/**
 * @struct tagExDomainV3
 * @brief ���������ݽṹ������������ϢV3
 * @attention
 */
typedef struct tagExDomainV3
{
    EX_DOMAIN_V2_S  stExDomainInfoV2;

    /** ����������,��ΪDVR:[MM_DOMAIN_SUBTYPE_FOREIGN_DVR3308, MM_DOMAIN_SUBTYPE_FOREIGN_DVR_MAX) */
    ULONG_32           ulExDomainSubType;

    /* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */
}EX_DOMAIN_V3_S;

/**
 * @struct tagLoDomain
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagLoDomain
{
    /** �������, �����Ψһ��ʶ */
    CHAR  szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �������� */
    CHAR  szDomainName[IMOS_NAME_LEN];

    /** ��������
        ���ڷ�OEM�汾(VM8500��H3C�豸),ȡֵΪ
            #IMOS_MANUFACTURER_TYPE_VMISC
        ����OEM�汾(PL/PL-S),ȡֵΪ
            #IMOS_MANUFACTURER_TYPE_PL
            #IMOS_MANUFACTURER_TYPE_PLS */
    CHAR szManufacturerType[IMOS_STRING_LEN_64];

    /** NTP��������ַ����, ֧�ֵ�����ַ��Ϊ#IMOS_NTP_SERVER_MAXNUM */
    CHAR szNTPServerAddr[IMOS_NTP_SERVER_MAXNUM][IMOS_IPADDR_LEN];
}LO_DOMAIN_S;


/**
 * @struct tagOrgResQueryItem
 * @brief ��֯�ڵ�����Դ��Ϣ��(��ѯ��Դ�б�ʱ����)
 * @attention
 */
typedef struct tagOrgResQueryItem
{
    /** ��Դ���� */
    CHAR  szResCode[IMOS_RES_CODE_LEN];

    /** ��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ��Դ���ͣ�ȡֵ��ΧΪ#IMOS_TYPE_E */
    ULONG_32  ulResType;

    /** ��Դ������,Ŀǰ��Դ������ֻ�������/��֯/����ʾ/����Ѳ��Ч�������������Ϊ��̨/����̨;
        ����֯����Ϊ:1-��������2-�����������3-�����������. 4-�ϼ���������.
        5-�¼���������.6-ƽ����������.
        ������ʾ��Դ��������ʾ���ͣ�ȡֵΪ#SALVO_TYPE_E
        ������Ѳ��Դ��������Ѳ���ͣ�ȡֵΪ#GROUP_SWITCH_TYPE_E
        ��ǹ�����������ͣ�ȡֵΪ#BALLLINKAGE_TYPE_E*/
    ULONG_32  ulResSubType;

    /** ��Դ״̬,ȡֵΪ:#IMOS_DEV_STATUS_ONLINE,#IMOS_DEV_STATUS_OFFLINE
        - �������Դ,���������豸(�����/������/EC/DC)������(��������˵,���ֶδ������ע��״̬) */
    ULONG_32  ulResStatus;

    /** ��Դ����״̬
        - ���������,���ֶ��������߲���һ�������ϱ�����Ƶ״̬��Ϣ��(����Ƶ��ʧ�澯/����Ƶ�ָ��澯),��������,ȡֵΪ:#IMOS_DEV_EXT_STATUS_E
        - ��������,���ֶδ�������ע��״̬,ȡֵΪ:#IMOS_DEV_STATUS_ONLINE,#IMOS_DEV_STATUS_OFFLINE */
    ULONG_32  ulResExtStatus;

    /** ����Դ�Ƿ��Ǳ��������Դ, 1Ϊ���������Դ; 0Ϊ�ǻ������Դ */
    ULONG_32  ulResIsBeShare;

    /** ��Դ������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ֧�ֵ�����Ŀ��������Դ����Ϊ�����ʱ��Ч��0:��Чֵ��1:������2:˫�� 3:���� */
    ULONG_32 ulStreamNum;

    /** �Ƿ�Ϊ������Դ��1Ϊ������Դ; 0Ϊ��������Դ */
    ULONG_32  ulResIsForeign;
}ORG_RES_QUERY_ITEM_S;


/**
 * @struct tagResItemV2
 * @brief ��Դ��Ϣ��(V2,��չ����"��Դ������֯������")
 * @attention
 */
typedef struct tagResItemV2
{
    /** V1��Դ��Ϣ�� */
    ORG_RES_QUERY_ITEM_S stResItemV1;

    /** ��Դ������֯������ */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** ��Դ������Ϣ��������Դ�����������ʱ��ȡֵΪ#CAMERA_ATTRIBUTE_E��������Դ���͸��ֶ���δʹ�� */
    ULONG_32  ulResAttribute;

    /** �����ECR HFϵ�е���������߼��������ڵ��豸�����ײͣ�
        ������Դ����,����ͨ�ò�ѯ����IS_QUERY_ENCODESETû����д, ��������"����ѯ", ���ֶξ�Ϊ��Чֵ#IMOS_SR_INVALID
        ȡֵΪ#IMOS_STREAM_RELATION_SET_E */
    ULONG_32  ulDevEncodeSet;

    /* Begin: Modified by lw0581, 2013.12.19 for  MPPD06992 */
    /** ����ҵ��״̬, ������Դ����Ϊ�Խ���Դ���㲥��Դ���������ʱ��Ч;
        0������ͨ״̬, 1�������ڶԽ�, 2�������ڹ㲥, ö��Ϊ#VOICE_STATUS_FOR_ECR_E */
    ULONG_32  ulVoiceStatus;

    /** �Ƿ�������Դ, ������Դ����Ϊ�㲥��ʱ��Ч */
    BOOL_T  bHasBrdSubRes;

    /** �Ƿ�����Դ�� BOOL_FALSE--û�а�, BOOL_TRUE--�а�*/
    BOOL_T  bIsBind;

    /** ��Դ�󶨶�Ӧ��Ϣ, ����Դ����Ϊ�����ʱ, �����Ӧ�󶨹�ϵ��������Դ����,
    ����Դ����Ϊ������Դʱ,�����Ӧ�󶨹�ϵ�����������, ���������Ч */
    CHAR   szResBindCode[IMOS_DEVICE_CODE_LEN];
    /* Begin:Modified by h00275, 2013.4.12 for  of V2R1���� */
    /* ���ֶ�ֻ����Դ����Ϊ��֯��Ч���������������� */
    ULONG_32 ulSubTypeOfSubType;

    /** �����ֶ�*/
    CHAR   szReserve[120];
    /* End: Modified by lw0581, 2013.12.19 for  MPPD06992 */
}RES_ITEM_V2_S;


/**
 * @struct tagQueryConditionItem
 * @brief ��ѯ������
 * @attention
 */
typedef struct tagQueryConditionItem
{
    /** ��ѯ��������: #QUERY_TYPE_E */
    ULONG_32 ulQueryType;

    /** ��ѯ�����߼���ϵ����: #LOGIC_FLAG_E */
    ULONG_32 ulLogicFlag;

    /** ��ѯ���� */
    CHAR  szQueryData[IMOS_QUERY_DATA_MAX_LEN];
}QUERY_CONDITION_ITEM_S;


/**
 * @struct tagCommonQueryCondition
 * @brief ͨ�ò�ѯ����
 * @attention
 */
typedef struct tagCommonQueryCondition
{
    /** ��ѯ���������в�ѯ������ʵ�ʸ���, ���ȡֵΪ#IMOS_QUERY_ITEM_MAX_NUM */
    ULONG_32 ulItemNum;

    /** ��ѯ�������� */
    QUERY_CONDITION_ITEM_S astQueryConditionList[IMOS_QUERY_ITEM_MAX_NUM];

 }COMMON_QUERY_CONDITION_S;



/***************************************************************************************
EC,DC����
***********************************************************************************/


/**
 * @struct tagDevChannelIndex
 * @brief ͨ��������Ϣ
 * @attention
 */
typedef struct tagDevChannelIndex
{
    /** �豸���� */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���ͣ���ȡֵΪ������#IMOS_TYPE_EC; ������#IMOS_TYPE_DC; ����洢���ܵı�����#IMOS_TYPE_ECR */
    ULONG_32 ulDevType;

    /** ͨ�������ţ���Ϊ:��Ƶ��Ƶͨ��������ͨ����������ͨ��(����/���), ȡֵ�Ӿ�������� */
    ULONG_32   ulChannelIndex;
}DEV_CHANNEL_INDEX_S;



/**
 * @struct tagECInfo
 * @brief EC��Ϣ
 * @attention
 */
typedef struct tagECInfo
{
    /** EC����, EC��Ψһ��ʶ */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC���� */
    CHAR  szECName[IMOS_NAME_LEN];

    /** EC���ͣ�ȡֵΪ#IMOS_DEVICE_TYPE_E, �Ϸ�ȡֵ�μ�#ulChannum������˵�� */
    ULONG_32 ulECType;

    /** ECͨ������:
        ���ֳ���EC���Ͷ�Ӧ��ͨ����������:
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

    /** �Ƿ�֧���鲥, 1Ϊ֧��; 0Ϊ��֧�� */
    ULONG_32 ulIsMulticast;

    /** ���¸澯�¶�����, ȡֵΪ50~100 */
    LONG_32 lTemperatureMax;

    /** ���¸澯�¶�����, ȡֵΪ-100~49 */
    LONG_32 lTemperatureMin;

    /** �澯ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnableAlarm;

    /** EC������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ʱ��ͬ����ʽ��Ĭ��Ϊ1����ʾʹ��H3C��˽��ͬ����ʽ��2��ʾNTP��ͬ����ʽ(Ŀǰ�ݲ�֧��) */
    ULONG_32 ulTimeSyncMode;

    /** ʱ��, ȡֵΪ-12~12 */
    LONG_32 lTimeZone;

    /** �������ã������ķ����������ã�ȡֵΪ:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** �Ƿ����ñ��ػ��棬1��ʾ����; 0��ʾ��������Ĭ��ֵΪ0 */
    ULONG_32 ulEnableLocalCache;

    /** ���ײ�, ȡֵΪ:#IMOS_STREAM_RELATION_SET_E
        0��MPEG4+MPEG4(#IMOS_SR_MPEG4_MPEG4)
        1��H264������(#IMOS_SR_H264_SHARE)
        2��MPEG2+MPEG4(#IMOS_SR_MPEG2_MPEG4)
        3��H264+MJPEG(#IMOS_SR_H264_MJPEG)
        4��MPEG4������(#IMOS_SR_MPEG4_SHARE)
        5��MPEG2������(#IMOS_SR_MPEG2_SHARE)
        8: MPEG4������_D1(#IMOS_SR_STREAM_MPEG4_8D1)
        9��MPEG2+MPEG2(#IMOS_SR_MPEG2_MPEG2)
        11��H264+H264(#IMOS_SR_H264_H264)
    */
    ULONG_32 ulEncodeSet;

    /** ��ʽ, ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** ��Ƶ����Դ��ȡֵΪ#IMOS_AUDIO_INPUT_SOURCE_E */
    ULONG_32 ulAudioinSource;

    /** �����Խ���Դ���� */
    CHAR szAudioCommCode[IMOS_RES_CODE_LEN];

    /** �����㲥��Դ���� */
    CHAR szAudioBroadcastCode[IMOS_RES_CODE_LEN];

    /** �豸�������� */
    CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

    /** �豸����, Ŀǰ���ֶ�δʹ�� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** EC��IP��ַ, ��Ӽ��޸�EC������д�ò���, ��ѯEC��Ϣʱ���ظ��ֶ� */
    CHAR szECIPAddr[IMOS_IPADDR_LEN];

    /** EC������״̬,��Ӽ��޸�EC������д�ò���, ��ѯEC��Ϣʱ���ظ��ֶ�, 1Ϊ����; ����Ϊ���� */
    ULONG_32 ulIsECOnline;

    /** ��ý���Э������,ȡֵΪ#IMOS_TRANS_TYPE_E��ĿǰECֻ֧��UDP��TCP */
    ULONG_32 ulStreamTransProtocol;

    /** �豸�ͺ���Ϣ */
    CHAR szECVer[IMOS_STRING_LEN_64];

    /** �����ֶ� */
    CHAR szReserve[28];
}EC_INFO_S;


/**
 * @struct tagECQueryItem
 * @brief ��������Ϣ��(��ѯ�������б�ʱ����)
 * @attention
 */
typedef struct tagECQueryItem
{
    /** EC���� */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC���� */
    CHAR  szECName[IMOS_NAME_LEN];

    /** EC���ͣ�ȡֵΪ#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulECType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** �豸��ַ */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** ������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸�Ƿ�����ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** �Ƿ�֧���鲥, 1Ϊ֧���鲥; 0Ϊ��֧���鲥 */
    ULONG_32 ulIsMulticast;

    /** �澯ʹ��, 1Ϊʹ�ܸ澯; 0Ϊ��ʹ�ܸ澯 */
    ULONG_32 ulEnableAlarm;

    /** ���ײ����ͣ�ȡֵΪ#IMOS_STREAM_RELATION_SET_E */
    ULONG_32 ulEncodeType;

    /** ��ʽ��ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** �����ֶ� */
    CHAR szReserve[32];
}EC_QUERY_ITEM_S;


/**
 * @struct tagECAndAudioInfo
 * @brief EC������Ϣ
 * @attention
 */
typedef struct tagECAndAudioInfo
{
    /**  EC������Ϣ */
    EC_INFO_S           stEcInfo;

    /** ������Ƶ��Ϣ */
    AUDIO_INPUT_INFO_S  stAudioInPutInfo;
}EC_AND_AUDIO_INFO_S;


/**
 * @struct tagCamAndChannelQueryItem
 * @brief ������Լ�ͨ����Ϣ��(��ѯ������Լ�ͨ���б�ʱ����)
 * @attention
 */
typedef struct tagCamAndChannelQueryItem
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** ��������� */
    CHAR    szCamCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32   ulCamType;

    /** ��̨����Э�� */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** ��̨��ַ��, ȡֵΪ0~255, ����ȡֵ����̨�������ʵ�ʵ�ַ����� */
    ULONG_32   ulPtzAddrCode;

    /** �鲥��ַ */
    CHAR    szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�, ��ΧΪ��10002-65534 */
    ULONG_32   ulMulticastPort;

    /** �����ֶ� */
    CHAR szReserve[32];
}CAM_AND_CHANNEL_QUERY_ITEM_S;


/**
 * @struct tagCamAndChannelQueryItem
 * @brief ������Լ�ͨ����Ϣ��(��ѯ������Լ�ͨ���б�ʱ����)
 * @attention
 */
typedef struct tagCamAndChannelQueryItemV2
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** ��������� */
    CHAR    szCamCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32   ulCamType;

    /** ��̨����Э�� */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** ��̨��ַ��, ȡֵΪ0~255, ����ȡֵ����̨�������ʵ�ʵ�ַ����� */
    ULONG_32   ulPtzAddrCode;

    /** �鲥��ַ */
    CHAR    szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�, ��ΧΪ��10002-65534 */
    ULONG_32   ulMulticastPort;

    /** �鲥��ַ */
    CHAR    szSecondMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�, ��ΧΪ��10002-65534 */
    ULONG_32   ulSecondMulticastPort;

    /** �����ֶ� */
    CHAR szReserve[512];
}CAM_AND_CHANNEL_QUERY_ITEM_V2_S;




/**
 * @struct tagDCInfo
 * @brief DC��Ϣ
 * @attention
 */
typedef struct tagDCInfo
{
    /** DC���� */
    CHAR  szDCCode[IMOS_DEVICE_CODE_LEN];

    /** DC���� */
    CHAR  szDCName[IMOS_NAME_LEN];

    /** DC����, ȡֵΪ#IMOS_DEVICE_TYPE_E, �Ϸ�ȡֵ�μ�#ulChannum������˵�� */
    ULONG_32 ulDCType;

    /** DCͨ������:
        ���ֳ���DC���Ͷ�Ӧ��ͨ����������:
        DC1001(#IMOS_DT_DC1001): 1
        DC2004(#IMOS_DT_DC2004_FF)/VL2004(#IMOS_DT_VL2004): 4
        DC1801(#IMOS_DT_DC1801_FH): 1
    */
    ULONG_32 ulChannum;

    /** �Ƿ�֧���鲥, 1Ϊ֧���鲥; 0Ϊ��֧���鲥 */
    ULONG_32 ulIsMulticast;

    /** ���¸澯�¶�����, ȡֵΪ50~100 */
    LONG_32 lTemperatureMax;

    /** ���¸澯�¶�����, ȡֵΪ-100~49 */
    LONG_32 lTemperatureMin;

    /** �澯ʹ��, 1Ϊʹ�ܸ澯; 0Ϊ��ʹ�ܸ澯 */
    ULONG_32 ulEnableAlarm;

    /** ������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ʱ��ͬ����ʽ��Ĭ��Ϊ1����ʾʹ��H3C��˽��ͬ����ʽ��2��ʾNTP��ͬ����ʽ(Ŀǰ�ݲ�֧��) */
    ULONG_32 ulTimeSyncMode;

    /** ʱ��, ȡֵΪ-12~12 */
    LONG_32 lTimeZone;

    /** �������ã������ķ����������ã�ȡֵΪ:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** ��ʽ, ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** ���ײͣ�ȡֵΪ#IMOS_STREAM_RELATION_SET_E
        ����Ϊ���������ײ�ֵ��
        1��H264(#IMOS_SR_H264_SHARE)
        3: MJPEG(#IMOS_SR_H264_MJPEG)
        4��MEPG4(#IMOS_SR_MPEG4_SHARE)
        5��MEPG2(#IMOS_SR_MPEG2_SHARE)
    */
    ULONG_32 ulEncodeSet;

    /** �豸�������� */
    CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

    /** �豸����, Ŀǰ���ֶ�δʹ�� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** DC��IP��ַ,��Ӽ��޸�DC������д�ò���,��ѯDC��Ϣʱ�᷵�ظ��ֶ� */
    CHAR szDCIPAddr[IMOS_IPADDR_LEN];

    /** DC������״̬,��Ӽ��޸�DC�ò�����Ч, ��ѯDC��Ϣʱ���ظ��ֶ�, 1Ϊ����; ����Ϊ���� */
    ULONG_32 ulIsDCOnline;

    /** ��ý���Э������,ȡֵΪ#IMOS_TRANS_TYPE_E��ĿǰDCֻ֧������Ӧ��TCP */
    ULONG_32 ulStreamTransProtocol;

    /** ��ý��ķ�ʽ����,ȡֵΪ#IMOS_STREAM_SERVER_MODE_E��ĿǰDCֻ֧������Ӧ��ֱ������ */
    ULONG_32 ulStreamServerMode;

    /** �豸ע��Э�����ͣ�ȡֵΪ#IMOS_DEVICE_REG_PROTOCOL_TYPE_E */
    ULONG_32 ulRegProtocol;

    /** �豸ע���û��� */
    CHAR szRegUserName[IMOS_NAME_LEN];

    /** �豸ע���������� */
    CHAR szRegUserPasswd[IMOS_PASSWD_LEN];

    /** �����ֶ� */
    CHAR szReserve[4];
}DC_INFO_S;


/**
 * @struct tagDCQueryItem
 * @brief ��������Ϣ��(��ѯ�������б�ʱ����)
 * @attention
 */
typedef struct tagDCQueryItem
{
    /** DC���� */
    CHAR  szDCCode[IMOS_DEVICE_CODE_LEN];

    /** DC���� */
    CHAR  szDCName[IMOS_NAME_LEN];

    /** DC���ͣ�ȡֵΪ#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulDCType;

    /** DC�豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** DC�豸��ַ */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** DC������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ö��ֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** �Ƿ�֧���鲥, 1Ϊ֧���鲥; 0Ϊ��֧���鲥 */
    ULONG_32 ulIsMulticast;

    /** �澯ʹ��, 1Ϊʹ�ܸ澯; 0Ϊ��ʹ�ܸ澯 */
    ULONG_32 ulEnableAlarm;

    /** ���ײ����ͣ�ȡֵΪ#IMOS_STREAM_RELATION_SET_E */
    ULONG_32 ulEncodeType;

    /** ��ʽ, ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** ע��Э������,ȡֵΪ#IMOS_DEVICE_REG_PROTOCOL_TYPE_E */
    ULONG_32 ulRegProtocol;

    /** �����ֶ� */
    CHAR szReserve[28];
}DC_QUERY_ITEM_S;


/**
 * @struct tagScrAndChannelQueryItem
 * @brief �������Լ�ͨ����Ϣ��(��ѯ�������Լ�ͨ���б�ʱ����)
 * @attention
 */
typedef struct tagScrAndChannelQueryItem
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stDCChannelIndex;

    /** ���������� */
    CHAR    szScrCode[IMOS_RES_CODE_LEN];

    /** ���������� */
    CHAR    szScrName[IMOS_NAME_LEN];

    /** �������� */
    ULONG_32 ulSplitScrNum;

    /** �����ֶ� */
    CHAR szReserve[28];
}SCR_AND_CHANNEL_QUERY_ITEM_S;

/***************************************************************************************
���������
***********************************************************************************/

/**
 * @struct tagSCameraInfo
 * @brief �������Ϣ
 * @attention
 */
typedef struct tagSCameraInfo
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** ���������, �ɲ��� */
    CHAR    szCameraDesc[IMOS_DESC_LEN];

    /** ��̨����Э��, Ŀǰ֧�ֵİ���:PELCO-D, PELCO-P, ALEC, VISCA, ALEC_PELCO-D, ALEC_PELCO-P, MINKING_PELCO-D, MINKING_PELCO-P */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** ��̨��ַ��, ȡֵΪ0~255, ����ȡֵ����̨�������ʵ�ʵ�ַ����� */
    ULONG_32   ulPtzAddrCode;

    /** ��̨Э�鷭��ģʽ,����ȡֵΪ#PTZ_CMDPARSEMODE_E */
    ULONG_32   ulPtzTranslateMode;

    /** ���� */
    CHAR szLongitude[IMOS_STRING_LEN_32];

    /** γ�� */
    CHAR szLatitude[IMOS_STRING_LEN_32];

    /** ����λ�����趨��Ԥ��λ�ı�����Ӧ */
    ULONG_32   ulGuardPosition;

    /** �Զ�����ʱ��, ��λΪ��, ��󲻳���3600��, 0��ʾ������ */
    ULONG_32   ulAutoGuard;

    /** �豸����, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** ����EC���������EC�ı���, ����ECR���������ECR�ı���, ��������ʱ����ı��� */
    CHAR    szECCode[IMOS_DEVICE_CODE_LEN];

    /** �ڰ󶨼��޸�Cameraʱ,������д,��ѯCamera��Ϣʱ�᷵�ظ��ֶ�, ����EC���������EC��IP, ����ECR���������ECR��IP, ���������������IP */
    CHAR    szECIPAddr[IMOS_IPADDR_LEN];

    /** ����ECͨ��������, �Ӿ����������, ����EC��ECR HCϵ�е�������Ǿ����ͨ������, ����ECR HFϵ�к�������������Чֵ */
    ULONG_32   ulChannelIndex;

    /* ����Ŵ�Э�� ȡֵ#ZOOM_PROTOCOL_E*/
    ULONG_32   ulZoomProtocol;

    /** ���Ŀ������, ȡֵΪ#TARGET_TYPE_E�е�һ��������ɵ��ַ��� */
    CHAR    szTargetType[IMOS_STRING_LEN_14];

    /** ���Ŀ�������ͣ�Ŀǰ�����������պ���չ */
    CHAR    szTargetSubType[IMOS_STRING_LEN_14];
}CAMERA_INFO_S;

/* Begin Add by zhouquanwei/z01364 2013/12/16 for ���������������չ */
/**
 * @struct  tagSCameraInfoEX
 * @brief   ��չ�������Ϣ
 * @attention
 */
typedef struct tagSCameraInfoEX
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** ���������, �ɲ��� */
    CHAR    szCameraDesc[IMOS_DESC_LEN];

    /** ��̨����Э��, Ŀǰ֧�ֵİ���:PELCO-D, PELCO-P, ALEC, VISCA, ALEC_PELCO-D, ALEC_PELCO-P, MINKING_PELCO-D, MINKING_PELCO-P */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** ��̨��ַ��, ȡֵΪ0~255, ����ȡֵ����̨�������ʵ�ʵ�ַ����� */
    ULONG_32   ulPtzAddrCode;

    /** ��̨Э�鷭��ģʽ,����ȡֵΪ#PTZ_CMDPARSEMODE_E */
    ULONG_32   ulPtzTranslateMode;

    /** ���� */
    CHAR szLongitude[IMOS_STRING_LEN_32];

    /** γ�� */
    CHAR szLatitude[IMOS_STRING_LEN_32];

    /** ����λ�����趨��Ԥ��λ�ı�����Ӧ */
    ULONG_32   ulGuardPosition;

    /** �Զ�����ʱ��, ��λΪ��, ��󲻳���3600��, 0��ʾ������ */
    ULONG_32   ulAutoGuard;

    /** �豸����, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** ����EC���������EC�ı���, ����ECR���������ECR�ı���, ��������ʱ����ı��� */
    CHAR    szECCode[IMOS_DEVICE_CODE_LEN];

    /** �ڰ󶨼��޸�Cameraʱ,������д,��ѯCamera��Ϣʱ�᷵�ظ��ֶ�, ����EC���������EC��IP, ����ECR���������ECR��IP, ���������������IP */
    CHAR    szECIPAddr[IMOS_IPADDR_LEN];

    /** ����ECͨ��������, �Ӿ����������, ����EC��ECR HCϵ�е�������Ǿ����ͨ������, ����ECR HFϵ�к�������������Чֵ */
    ULONG_32   ulChannelIndex;

    /* ����Ŵ�Э�� ȡֵ#ZOOM_PROTOCOL_E*/
    ULONG_32   ulZoomProtocol;

    /** ���Ŀ������, ȡֵΪ#TARGET_TYPE_E�е�һ��������ɵ��ַ��� */
    CHAR    szTargetType[IMOS_STRING_LEN_14];

    /** ���Ŀ�������ͣ�Ŀǰ�����������պ���չ */
    CHAR    szTargetSubType[IMOS_STRING_LEN_14];

    /** �����λ��������չ��1-ʡ�ʼ��վ��2-�������ء�3-��վ��ͷ��4-���Ĺ㳡��5-�������ݡ�6-��ҵ���ġ�7-�ڽ̳�����
        8-У԰�ܱߡ�9-�ΰ���������10-��ͨ���ߡ� */
    ULONG_32   ulPositionType;

    /** �������װλ�����⡢�������ԡ�1-���⡢2-���ڡ� */
    ULONG_32   ulRoomType;

    /** �������;���ԡ�1-�ΰ���2-��ͨ��3-�ص㡣 */
    ULONG_32   ulUseType;

    /** ������������ԡ�1-�޲��⡢2-���ⲹ�⡢3-�׹ⲹ�⡣ */
    ULONG_32   ulSupplyLightType;

    /** ��������ӷ�λ���ԡ�1-����2-����3-�ϡ�4-����5-���ϡ�6-������7-���ϡ�8-����������Ŀ¼��Ϊ�����ʱ��ѡ�� */
    ULONG_32   ulDirectionType;
}CAMERA_INFO_EX_S;
/* End Add by zhouquanwei/z01364 2013/12/16 for ���������������չ */

/**
* @struct tagCameraPtzInfo
* @brief �������̨��Ϣ
*/
typedef struct tagCameraPtzInfo
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** ���������, �ɲ��� */
    CHAR    szCameraDesc[IMOS_DESC_LEN];

    /** ��̨����Э��, Ŀǰ֧�ֵİ���:#PELCO-D, #PELCO-P, #ALEC, #VISCA, #ALEC_PELCO-D, #ALEC_PELCO-P, #MINKING_PELCO-D, #MINKING_PELCO-P */
    CHAR    szPtzProtocol[IMOS_STRING_LEN_32];

    /** ��̨��ַ��, ȡֵΪ0~255, ����ȡֵ����̨�������ʵ�ʵ�ַ����� */
    ULONG_32   ulPtzAddrCode;

    /** ��̨��ʶ, ������̨������ */
    ULONG_32   ulPtzID;

    /* �����ֶ� */
    CHAR    szReserv[128];
}CAMERA_PTZ_INFO_S;


/***************************************************************************************
����������
***********************************************************************************/

/**
 * @struct tagScreenInfo
 * @brief ��������Ϣ
 * @attention
 */
typedef struct tagScreenInfo
{
    /** ���������� */
    CHAR        szScreenCode[IMOS_RES_CODE_LEN];

    /** ���������� */
    CHAR        szScreenName[IMOS_NAME_LEN];

    /** ����������, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /**  DC��IP��ַ, �ڰ󶨼��޸�Screenʱ, ������д; ��ѯScreen��Ϣʱ�᷵�ظ��ֶ� */
    CHAR    szDCIPAddr[IMOS_IPADDR_LEN];

    /**  DC�豸���� */
    ULONG_32    ulDCType;

    /** �����ֶ� */
    CHAR szReserve[28];
}SCREEN_INFO_S;

/**
 * @struct tagScreenRelatedDC
 * @brief ����������Ӧ�Ľ�������Ϣ�ṹ��
 * @attention
 */
typedef struct tagScreenRelatedDC
{
    /** ���������� */
    CHAR szScreenCode[IMOS_CODE_LEN];

    /** ���������� */
    CHAR szScreenName[IMOS_NAME_LEN];

    /** ����������, �ɲ��� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** DC���� */
    CHAR szDCCode[IMOS_CODE_LEN];

    /** DC���� */
    CHAR szDCName[IMOS_NAME_LEN];

    /** DC����, ȡֵΪ#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulDCType;

    /** ����ӦDC��IP��ַ, �ڰ󶨼��޸�Screenʱ, ������д; ��ѯScreen��Ϣʱ�᷵�ظ��ֶ� */
    CHAR szDCIPAddr[IMOS_IPADDR_LEN];

    /** ͨ�������ţ���Ƶ��Ƶͨ��*/
    ULONG_32 ulChannelIndex;

    /** �����ֶ� */
    CHAR szReserve[28];
}SCREEN_RELATED_DC_S;

/***************************************************************************
EC,DC��Ƶͨ��
****************************************************************************/

/**
 * @struct tagVideoInChannel
 * @brief ����Ƶ����ͨ����Ϣ
 * @attention
 */
typedef struct tagVideoInChannel
{

    /** ��Ƶ����ͨ������ */
    CHAR szVinChannelDesc[IMOS_DESC_LEN];

    /** �鲥��ַ */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�,��ΧΪ��10002-65534���ұ���Ϊż�� */
    ULONG_32   ulMulticastPort;

    /** MSѡ�����Ӧ����, 1Ϊ����Ӧ; 0Ϊָ��MS��2Ϊ������MS, ȡֵΪ#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulIsAutofit;

    /** ʹ��MS��Ŀ, ��ʵ���������, ����Ӧ����#ulIsAutofitΪ����Ӧ, ��ֵΪ0;
        ����Ӧ����#ulIsAutofitΪ������Ӧ(��ָ��), ��ֵΪ1 */
    ULONG_32 ulUseMSNum;

    /** MS�����б� */
    CHAR aszMSCode[IMOS_MS_MAX_NUM_PER_CHANNEL][IMOS_DEVICE_CODE_LEN];

    /** �Ƿ�����ͼ���ڵ����澯, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulEnableKeepout;

    /** �Ƿ������˶����澯, 1Ϊ�����˶����澯; 0Ϊ�������˶����澯 */
    ULONG_32 ulEnableMotionDetect;

    /** �Ƿ�������Ƶ��ʧ�澯, 1Ϊ������Ƶ��ʧ�澯; 0Ϊ��������Ƶ��ʧ�澯 */
    ULONG_32 ulEnableVideoLost;

    /** �󶨵Ĵ��ڱ�ţ���������дΪ��Чֵ(255)#PTZ_INVALID_SERIAL_INDEX_NUM */
    ULONG_32 ulSerialIndex;

    /** ���ȣ�ȡֵΪ��0~255�� */
    ULONG_32 ulBrightness;

    /** �Աȶȣ�ȡֵΪ��0~255�� */
    ULONG_32 ulContrast;

    /** ���Ͷȣ�ȡֵΪ��0~255�� */
    ULONG_32 ulSaturation;

    /** ɫ����ȡֵΪ��0~255�� */
    ULONG_32 ulTone;

    /** �Ƿ���������, 1Ϊ����������; 0Ϊ�������� */
    ULONG_32 ulAudioEnabled;

    /** ��Ƶ����, ȡֵΪ#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioCoding;

    /** ��Ƶ����, ȡֵΪ#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** ��Ƶ������, ȡֵΪ#IMOS_AUDIO_SAMPLING_E */
    ULONG_32 ulSamplingRate;

    /** ��Ƶ����, �������� */
    ULONG_32 ulAudioCodeRate;

    /** ��Ƶ����ֵ��ȡֵΪ��0~255�� */
    ULONG_32 ulIncrement;
}VIN_CHANNEL_S;

/**
 * @struct tagVideoInChannelExtend
 * @brief ����Ƶ����ͨ����Ϣ
 * @attention
 */
typedef struct tagVideoInChannelV3
{
    VIN_CHANNEL_S stVinChannel;
    /** �鲥��ַ,˫�鲥ʱʹ��*/
    CHAR szExtMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�,˫�鲥ʱʹ��*/
    ULONG_32 ulExtMulticastPort;
    
    /** �����ֶ� */
    CHAR  szReserve[256];
    
}VIN_CHANNEL_V3_S;


/**
 * @struct tagVideoOutChannel
 * @brief �߼����ͨ����Ϣ
 * @attention
 */
typedef struct tagVideoOutChannel
{
    /** �߼����ͨ������, ȡֵΪ1~(#SPLIT_SCR_MODE_MAX - 1) */
    ULONG_32   ulVoutChannelindex;

    /** �߼����ͨ������, �ɲ��� */
    CHAR szVoutChannelDesc[IMOS_DESC_LEN];

    /** �Ƿ�ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnable;

    /** ��������, ȡֵΪ#IMOS_STREAM_TYPE_E, Ŀǰ��֧��#IMOS_ST_TS */
    ULONG_32 ulStreamType;

    /** ������ģʽ, ȡֵΪ#IMOS_TRANS_TYPE_E */
    ULONG_32   ulTranType;

    /** �Ƿ�����������, 1Ϊ����; 0Ϊ������ */
    ULONG_32   ulEnableJitterBuff;

}VOUT_CHANNEL_S;


/**
 * @struct tagPhyOutChannel
 * @brief �������ͨ����Ϣ
 * @attention
 */
typedef struct tagPhyOutChannel
{

    /** ����ģʽ��ȡֵΪ1��4������BNC�ڵķ����� */
    ULONG_32 ulPhyoutMode;

    /** ��Ƶ�����ʽ��ȡֵΪ#IMOS_VIDEO_FORMAT_E */
    ULONG_32 ulDecodeFormat;

    /** ��Ƶ��ʽ��ȡֵΪ#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioFormat;

    /** �������ã�ȡֵΪ#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** �Ƿ�������������, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulAudioEnabled;

    /** �������, ȡֵΪ1~7 */
    ULONG_32 ulVolume;

    /** ��Ƶ���ѡ��, �ӹ���ģʽ����#ulPhyoutMode�������������ģʽȡֵΪ1, ���ֵΪ1; �������ģʽȡֵΪ4, ���ֵȡֵΪ1~4 */
    ULONG_32 ulOutputIndex ;

    /** ������������, ��ʾ������ͨ�����ɰ󶨵ļ���������, Ŀǰ�̶�Ϊ1 */
    ULONG_32 ulMaxScreenNum;
}PHYOUT_CHANNEL_S;



/**
 * @struct tagVideoStream
 * @brief ��Ƶ����Ϣ
 * @attention
 */
typedef struct tagVideoStream
{

    /** ��������, ȡֵΪ#IMOS_STREAM_TYPE_E, Ŀǰ��֧��#IMOS_ST_TS */
    ULONG_32       ulStreamType;

    /** ��������1Ϊ������2Ϊ������3Ϊ�������� */
    ULONG_32       ulStreamIndex;

    /** ��ʹ�ܱ�ʶ, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** �����䷽ʽ, ȡֵΪ#IMOS_TRANS_TYPE_E */
    ULONG_32       ulTranType;

    /** �����ʽ, ȡ���ھ�������ײ�ֵ, ȡֵΪ#IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /** �ֱ���, ȡֵΪ#IMOS_PICTURE_SIZE_E */
    ULONG_32       ulResolution;

    /** ���� */
    ULONG_32       ulBitRate;

    /** ֡��,��ȡ��ֵ��1, 3, 5, 8, 10, 15, 20, 25, 30, 60
        ������ʽ#IMOS_PF_720P60HZ,Ĭ��ֵΪ60 */
    ULONG_32       ulFrameRate;

    /** GOPģʽ, ȡֵΪ#IMOS_GOP_TYPE_E */
    ULONG_32       ulGopMode;

    /** I֡���, ȡ����GOPģʽֵ, ��GOPģʽΪ#IMOS_GT_Iʱ, I֡���Ϊ1; ��GOPģʽΪ#IMOS_GT_IPʱ, I֡���Ϊ10~60
        ������ʽ#IMOS_PF_720P60HZ,Ĭ��ֵΪ60 */
    ULONG_32       ulIFrameInterval;

    /** ͼ������, ȡֵΪ#IMOS_VIDEO_QUALITY_E */
    ULONG_32       ulImageQuality;

    /** ������ģʽ, ȡֵΪ#IMOS_ENC_MODE_E */
    ULONG_32       ulEncodeMode;

    /** ���ȼ�, ���ڱ���ģʽΪ#IMOS_EM_CBRʱ�����ø�ֵ, ȡֵΪ#IMOS_CBR_ENC_MODE_E */
    ULONG_32       ulPriority;

    /** ����ƽ����ȡֵΪ#IMOS_STREAM_SMOOTH_E */
    ULONG_32       ulSmoothValue;

}VIDEO_STREAM_S;

/**
 * @struct tagAreaScope
 * @brief ����Χ��������������(�����Ǿ��ε�)
 * @attention ԭ��Ϊ���úͽ�����Ҫͳһ�������ģ��
 */
typedef struct tagAreaScope
{
    /** ���Ͻ�x���� */
    ULONG_32       ulTopLeftX;

    /** ���Ͻ�y���� */
    ULONG_32       ulTopLeftY;

    /** ���½�x���� */
    ULONG_32       ulBottomRightX;

    /** ���½�y���� */
    ULONG_32       ulBottomRightY;

}AREA_SCOPE_S;

/**
 * @struct tagVideoArea
 * @brief ��Ƶ������Ϣ
 * @attention
 */
typedef struct tagVideoArea
{
    /** ��������, ȡֵΪ1~4 */
    ULONG_32       ulAreaIndex;

    /** �Ƿ�ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** ������, 1��5����1����������ߡ���ֵ�����˶����������Ч */
    ULONG_32       ulSensitivity;

    /** �������� */
    AREA_SCOPE_S stAreaScope;

}VIDEO_AREA_S;



/**
 * @struct tagDetectArea
 * @brief �ڵ����˶��������
 * @attention
 */
typedef struct tagDetectArea
{
    /** �ڵ�������� */
    VIDEO_AREA_S       astCoverDetecArea[IMOS_COVER_AREA_MAXNUM];

    /** �˶�������� */
    VIDEO_AREA_S       astMotionDetecArea[IMOS_DETECT_AREA_MAXNUM];
}DETECT_AREA_S;

/**
 * @struct tagOsdMaskArea
 * @brief �ڸ�����
 * @attention
 */
typedef struct tagOsdMaskArea
{
    /** �ڸ����� */
    VIDEO_AREA_S       astMaskArea[IMOS_MASK_AREA_MAXNUM];
}OSD_MASK_AREA_S;




/**
 * @struct tagOsdTime
 * @brief OSDʱ�����
 * @attention
 */
typedef struct tagOsdTime
{
    /** ʱ��OSD����, �̶�Ϊ1 */
    ULONG_32       ulOsdTimeIndex;

    /** ʱ��OSDʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnableFlag;

    /** ʱ��OSDʱ���ʽ */
    ULONG_32       ulOsdTimeFormat;

    /** ʱ��OSD���ڸ�ʽ */
    ULONG_32       ulOsdDateFormat;

    /** ʱ��OSD��ɫ, ȡֵΪ#IMOS_OSD_COLOR_E */
    ULONG_32       ulOsdColor;

    /** ʱ��OSD͸����, ȡֵΪ#IMOS_OSD_ALPHA_E */
    ULONG_32       ulTransparence;

    /** ʱ��OSD�������� */
    AREA_SCOPE_S stAreaScope;

}OSD_TIME_S;

/**
 * @struct tagOsdName
 * @brief OSD������Ϣ
 * @attention
 */
typedef struct tagOsdName
{
    /** �Ƿ�ʹ�ܳ���OSD, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** ����OSD����, �̶�Ϊ1 */
    ULONG_32       ulOsdNameIndex;

    /** ����OSD��ɫ, ȡֵΪ#IMOS_OSD_COLOR_E */
    ULONG_32       ulOsdColor;

    /** ����OSD͸����, ȡֵΪ#IMOS_OSD_ALPHA_E */
    ULONG_32       ulTransparence;

    /** ����OSD�������� */
    AREA_SCOPE_S stAreaScope;

    /** ��һ��(��)����OSD����, ȡֵΪ#IMOS_INFO_OSD_TYPE_E */
    ULONG_32       ulOsdType1;

    /** ��һ��(��)����OSD���ݣ������֣���ֵΪ�ַ������Ϊ20�ַ�����ͼƬ����ֵΪOSDͼƬ���� */
    CHAR        szOsdString1[IMOS_NAME_LEN];

    /** �ڶ���(��)����OSD����, ȡֵΪ#IMOS_INFO_OSD_TYPE_E */
    ULONG_32       ulOsdType2;

    /** �ڶ���(��)����OSD���ݣ������֣���ֵΪ�ַ������Ϊ20�ַ�����ͼƬ����ֵΪOSDͼƬ���� */
    CHAR        szOsdString2[IMOS_NAME_LEN];

    /** (��һ���͵ڶ���)����OSD֮����л�ʱ��, ��λΪ��, ȡֵΪ0~300��ȡֵΪ0, ��ʾֻ��ʾ��һ��(��)OSD */
    ULONG_32       ulSwitchIntval;

    /** ����OSD����,ȡֵΪ:0 ��ͨ����OSD,1 ��̨�����û�OSD */
    ULONG_32 ulOsdNameType;

    /** �����ֶ� */
    CHAR szReserve[12];
}OSD_NAME_S;


/**
 * @struct tagOsdInfo
 * @brief OSD��Ϣ
 * @attention
 */
typedef struct tagOsdInfo
{
    /** ʱ��OSD */
    OSD_TIME_S      stOSDTime;

    /** ����OSD */
    OSD_NAME_S      astOSDName[IMOS_OSD_NAME_MAXNUM];

    /** �ڸ����� */
    OSD_MASK_AREA_S stOSDMaskArea;
}OSD_INFO_S;



/**
 * @struct tagVinChnlBindCamera
 * @brief ����������ͨ������Ϣ
 * @attention
 */
typedef struct tagVinChnlBindCamera
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** �������Ϣ */
    CAMERA_INFO_S       stCameraInfo;

    /** ��Ƶ����ͨ����Ϣ */
    VIN_CHANNEL_S       stVinChannel;

    /** OSD��Ϣ */
    OSD_INFO_S          stOSDInfo;

    /** ��Ƶ����������Ƶ����ʵ����Ŀ, ���ȡֵΪ#IMOS_STREAM_MAXNUM, �Ӿ������ײ�ֵ���� */
    ULONG_32               ulVideoStreamNum;

    /** ��Ƶ����Ϣ���� */
    VIDEO_STREAM_S      astVideoStream[IMOS_STREAM_MAXNUM];

    /** ������򣬰����˶�����Լ��ڵ�������� */
    DETECT_AREA_S       stDetectArea;
}VINCHNL_BIND_CAMERA_S;

/**
 * @struct tagMultiOsdInfo
 * @brief OSD��Ϣ(֧�ֶ���OSD)
 * @attention
 */
typedef struct tagMultiOsdInfo
{
    /** ʱ��OSD */
    OSD_TIME_S      stOSDTime;

    /** ����OSD */
    OSD_NAME_S      astOSDName[IMOS_OSD_NAME_MAX];

    /** �ڸ����� */
    OSD_MASK_AREA_S stOSDMaskArea;
}MULTI_OSD_INFO_S;

/**
* @struct tagOpticsParam
* @brief ��ѧ����
* @attention
*/
typedef struct tagOpticsParam
{
    /** ��ѧͨ����Ŀǰֻ��һ��ͨ����Զ��1 */
    ULONG_32 ulOpticsIndex;

    /** �ڰ�ģʽ��ȡֵΪ#IMOS_BLACKWHIT_MODE_E 0 �Զ�ģʽ��ȱʡ�� */
    ULONG_32 ulBlackWhiteMode;

    /** �ڰ�ģʽ�����ȣ�ֻ�кڰ�ģʽ���Զ�ģʽ��������Ч 0(���) - 2(���) Ĭ��1 */
    ULONG_32 ulBlackWhiteSense;

    /** �Զ��ع⣬2���ر��Զ��ع� 1��ʹ���Զ��ع⣨ȱʡ�� */
    ULONG_32 ulAutoExposal;

    /** ���ţ�ȡֵΪ#IMOS_SHUTTER_E��ȱʡΪ50 */
    ULONG_32 ulShutter;

    /** �Զ�������ƣ���Χ0-36��ȱʡ0  */
    ULONG_32 ulOpticsAGC;

    /** �����ƣ�ȡֵΪ#IMOS_AEMETERING_E 0 ����Ȩ�أ�ȱʡ�� */
    ULONG_32 ulVideoAEMetering;

    /** ��ȣ�ȡֵΪ# ��Χ0-6  Ĭ��0 */
    ULONG_32 ulVideoSharpness;

    /** ��ƽ�⣬ȡֵΪ#IMOS_AWB_E 0 �Զ�ģʽ��ȱʡ�� */
    ULONG_32 ulWhiteBalance;

    /** ͼ����ȡֵΪ#IMOS_MIRRORTYPE_E 0 ������ȱʡ�� */
    ULONG_32 ulVideoMirror;

    /** ����Ƶ�ʣ�ȡֵΪ#IMOS_FLICKER_MODE_E 0 �رգ�ȱʡ�� */
    ULONG_32 ulVideoFlicker;

    /** ��̬(#BOOL_FALSE �ر�, #BOOL_TRUE ����) */
    BOOL_T bEnableWDR;

    /** ���ⲹ��(#BOOL_FALSE �ر�, #BOOL_TRUE ����) */
    BOOL_T bEnableBLC;

    /** �����ֶ�3�� ȱʡΪ0 */
    ULONG_32 ulReserved3;
} OPTICS_PARAM_S;

/**
 * @struct tagPTZParam
 * @brief ��̨����
 * @attention
*/
typedef struct tagPTZParam
{
    /** ���������ٶ�(��/��),ȡֵ��Χ[30,360] */
    ULONG_32 ulXMaxAngleSpeed;

    /** ���������ٶ�(��/��),ȡֵ��Χ[30,360] */
    ULONG_32 ulYMaxAngleSpeed;

    /** ��������ӽ�(��),ȡֵ��Χ[30,360] */
    ULONG_32 ulXMaxViewAngle;

    /** ��������ӽ�(��),ȡֵ��Χ[30,360] */
    ULONG_32 ulYMaxViewAngle;

    /** �䱶ʱ��(����),ȡֵ��Χ[100,60000] */
    ULONG_32 ulZoomTime;

    /** �䱶����,ȡֵ��Χ[1,35] */
    ULONG_32 ulZoomMultiple;
} PTZ_PARAMETER_S;

/**
 * @struct tagReviseParam
 * @brief �㷨У������
 * @attention
*/
typedef struct tagReviseParam
{
    /** ����ת������ϵ��(%),ȡֵ��Χ[50,200] */
    ULONG_32 ulXTurnCoefficient;

    /** ����ת������ϵ��(%),ȡֵ��Χ[50,200] */
    ULONG_32 ulYTurnCoefficient;

    /** �佹����ϵ��(%),ȡֵ��Χ[50,200] */
    ULONG_32 ulFocusCoefficient;
} REVISE_PARAMETER_S;

/**
 * @struct tagLocateInfo
 * @brief ��λ��Ϣ
 * @attention
*/
typedef struct tagLocateInfo
{
    /** �Ƿ�����(#BOOL_FALSE ������,#BOOL_TURE ����) */
    BOOL_T  bIsEnabled;

    /** ��̨���� */
    PTZ_PARAMETER_S stPTZParam;

    /** �㷨У������ */
    REVISE_PARAMETER_S  stReviseParam;
} LOCATE_INFO_S;

/**
 * @struct tagIMOSAnalyseSizeFilter
 * @brief ��Ϊ���������С������Ϣ
 * @attention
 */
typedef struct tagIMOSAnalyseSizeFilter
{
    /** �Ƿ�ʹ��(BOOL_FALSE ��,BOOL_TRUE ��) */
    BOOL_T bEnable;

    /** ��С����,��ʽΪ"x1,y1;x2,y2" */
    CHAR szAreaMin[IMOS_COORDINATE_STR_LEN_16];

    /** �������,��ʽΪ"x1,y1;x2,y2" */
    CHAR szAreaMax[IMOS_COORDINATE_STR_LEN_16];

    /** �����ֶ� */
    CHAR szReserve[128];
} IMOS_ANALYSE_SIZE_FILTER_S;

/**
 * @struct tagIMOSBehaviorThruLine
 * @brief "������Ϊ"��Ϣ
 * @attention
 */
typedef struct tagIMOSBehaviorThruLine
{
    /** ��,��ʽΪ"x1,y1;x2,y2" */
    CHAR szLine[IMOS_COORDINATE_STR_LEN_16];

    /** ����,ȡֵΪ#IMOS_THRU_LINE_DIRECTION_E */
    ULONG_32 ulDirection;

    /** �߶� */
    ULONG_32 ulHeight;

    /** ��ɫ */
    ULONG_32 ulColor;

    /** �����ֶ� */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_THRU_LINE_S;

/**
 * @struct tagIMOSBehaviorArea
 * @brief "������Ϊ"��Ϣ
 * @attention
 */
typedef struct tagIMOSBehaviorArea
{
    /** �������ζ�������,ȡֵΪ[3-6] */
    ULONG_32 ulPointNum;

    /** ��������:�ɶ���������ɵ��ַ���,��ʽΪ"x1,y1;x2,y2;......" */
    CHAR szAreaPolygon[IMOS_COORDINATE_STR_LEN_56];

    /** ����,ȡֵΪ#IMOS_AREA_DIRECTION_E */
    ULONG_32 ulDirection;

    /** ��ɫ */
    ULONG_32 ulColor;

    /** �����ֶ� */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_AREA_S;

/**
 * @struct tagIMOSBehavior
 * @brief ��Ϊ��Ϣ
 * @attention
 */
typedef union tagIMOSBehavior
{
    /** ������Ϊ */
    IMOS_BEHAVIOR_THRU_LINE_S stThruLine;

    /** ������Ϊ */
    IMOS_BEHAVIOR_AREA_S stArea;
} IMOS_BEHAVIOR_U;

/**
 * @struct tagIMOSBehaviorAnalyseRule
 * @brief ��Ϊ��������
 * @attention
 */
typedef struct tagIMOSBehaviorAnalyseRule
{
    /** ����,ȡֵΪ[1-8] */
    ULONG_32  ulIndex;

    /** �Ƿ�ʹ��(BOOL_FALSE ��,BOOL_TRUE ��) */
    BOOL_T bEnable;

    /** ���������С������Ϣ */
    IMOS_ANALYSE_SIZE_FILTER_S  stFilter;

    /** ��Ϊ����,ȡֵΪ#IMOS_BEHAVIOR_TYPE_E */
    ULONG_32 ulBehaviorType;

    /** ��Ϊ��Ϣ */
    IMOS_BEHAVIOR_U unBehavior;

    /** �����ֶ� */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_ANALYSE_RULE_S;

/**
 * @struct tagIMOSBehaviorAnalyseArithmetic
 * @brief ��Ϊ�����㷨��Ϣ
 * @attention
 */
typedef struct tagIMOSBehaviorAnalyseArithmetic
{
    /** ֡��,ȡֵΪ[1-60] */
    ULONG_32  ulFrameRate;

    /** �Ƿ�ȥ��Ӱ(BOOL_FALSE ��,BOOL_TRUE ��) */
    BOOL_T bShadow;

    /** �����ֶ� */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_ANALYSE_ARITHMETIC_S;

/**
 * @struct tagIMOSBehaviorAnalyseInfo
 * @brief ��Ϊ������Ϣ
 * @attention
 */
typedef struct tagIMOSBehaviorAnalyseInfo
{
    /** �Ƿ�ʹ��(BOOL_FALSE ��,BOOL_TRUE ��) */
    BOOL_T bEnable;

    /** �㷨 */
    IMOS_BEHAVIOR_ANALYSE_ARITHMETIC_S stArithmetic;

    /** ���� */
    IMOS_BEHAVIOR_ANALYSE_RULE_S astRule[IMOS_BEHAVIOR_RULE_MAX];

    /** �����ֶ� */
    CHAR szReserve[128];
} IMOS_BEHAVIOR_ANALYSE_INFO_S;

/* BEGIN: Added by kf0092 for ��ȫ��������, 2013��3��15�� */
/**
 * @struct tagSafeCameraInfo
 * @brief ��ȫ���������
 * @attention
 */
typedef struct tagSafeCameraInfo
{
    /** ��ȫ���������� */
    CHAR szSafeDomainName[IMOS_NAME_LEN];

    /** ��ȫ��������� */
    CHAR szSafeDomainCode[IMOS_CODE_LEN];

    /** ��ȫ������������� */
    CHAR szSafeMonitorCode[IMOS_CODE_LEN];

    /** �豸�����Ƶͨ���� */
    ULONG_32 ulDevOutputChannelIndex;

    /** ��ռ�û���ɫ������ */
    CHAR szSafeRoleName[IMOS_NAME_LEN];

    /** ��ռ�û���ɫ����� */
    CHAR szSafeRoleCode[IMOS_CODE_LEN];
}SAFE_CAMERA_INFO_S;

/* END  : Added by kf0092 for ��ȫ��������, 2013��3��15�� */


/**
 * @struct tagVinChnlBindCameraBase
 * @brief ����������ͨ���Ļ�����Ϣ
 * @attention
 */
typedef struct tagVinChnlBindCameraBase
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** �������Ϣ */
    CAMERA_INFO_S       stCameraInfo;

    /** ��Ƶ����ͨ����Ϣ */
    VIN_CHANNEL_S       stVinChannel;

    /** ʱ��OSD */
    OSD_TIME_S      stOSDTime;

    /** ��ѧ���ò��� */
    OPTICS_PARAM_S      stOpticsParam;

    /** ��λ��Ϣ */
    LOCATE_INFO_S stLocateInfo;

    /** ��ȫ�����������Ϣ */
    SAFE_CAMERA_INFO_S stSafeCameraInfo;
}VINCHNL_BIND_CAMERA_BASE_S;

/**
 * @struct tagVinChnlBindCameraBase
 * @brief ����������ͨ���Ļ�����Ϣ
 * @attention
 */
typedef struct tagVinChnlBindCameraBaseV2
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** �������Ϣ */
    CAMERA_INFO_S       stCameraInfo;

    /** ��Ƶ����ͨ����Ϣ */
    VIN_CHANNEL_V3_S       stVinChannel;

    /** ʱ��OSD */
    OSD_TIME_S      stOSDTime;

    /** ��ѧ���ò��� */
    OPTICS_PARAM_S      stOpticsParam;

    /** ��λ��Ϣ */
    LOCATE_INFO_S stLocateInfo;

    /** ��ȫ�����������Ϣ */
    SAFE_CAMERA_INFO_S stSafeCameraInfo;
}VINCHNL_BIND_CAMERA_BASE_V2_S;


/**
 * @struct tagVinChnlBindCameraElement
 * @brief ��Ƶͨ��ȫ���䳤Ԫ�ؽṹ��
 * @attention
 */
typedef struct tagVinChnlFullVarietyElement
{
    /** ����OSD���� */
    ULONG_32           ulOSDNameNum;

    /** ����OSD */
    OSD_NAME_S      *pstOSDName;

    /** �ڸ�������� */
    ULONG_32           ulMaskAreaNum;

    /** �ڸ����� */
    VIDEO_AREA_S     *pstMaskArea;

    /** ��Ƶ������ */
    ULONG_32               ulVideoStreamNum;

    /** ��Ƶ����Ϣ���� */
    VIDEO_STREAM_S      *pstVideoStream;

    /** �ڵ����������� */
    ULONG_32           ulCoverDetecAreaNum;

    /** �ڵ�������� */
    VIDEO_AREA_S       *pstCoverDetecArea;

    /** �˶����������� */
    ULONG_32           ulMotionDetecAreaNum;

    /** �˶�������� */
    VIDEO_AREA_S       *pstMotionDetecArea;
}VINCHNL_FULL_VARIETY_ELEMENT_S;

/**
 * @struct tagVinChnlBindCameraV2
 * @brief ����������ͨ������Ϣ(֧�ֶ���OSD����ѧ��������)
 * @attention
 */
typedef struct tagVinChnlBindCameraV2
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** �������Ϣ */
    CAMERA_INFO_S       stCameraInfo;

    /** ��Ƶ����ͨ����Ϣ */
    VIN_CHANNEL_S       stVinChannel;

    /** OSD��Ϣ */
    MULTI_OSD_INFO_S    stOSDInfo;

    /** ��Ƶ����������Ƶ����ʵ����Ŀ, ���ȡֵΪ#IMOS_STREAM_MAXNUM_II, �Ӿ������ײ�ֵ���� */
    ULONG_32               ulVideoStreamNum;

    /** ��Ƶ����Ϣ���� */
    VIDEO_STREAM_S      astVideoStream[IMOS_STREAM_MAXNUM_II];

    /** ������򣬰����˶�����Լ��ڵ�������� */
    DETECT_AREA_S       stDetectArea;

    /** ��ѧ���ò��� */
    OPTICS_PARAM_S      stOpticsParam;
}VINCHNL_BIND_CAMERA_V2_S;

/**
 * @struct tagVinChnlBindCameraForECR
 * @brief ����������ͨ������Ϣfor ECR&NVR
 * @attention
 */
typedef struct tagVinChnlBindCameraForECR
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stECChannelIndex;

    /** �������Ϣ */
    CAMERA_INFO_S       stCameraInfo;

    /** ��Ƶ����ͨ����Ϣ */
    VIN_CHANNEL_S       stVinChannel;

    /** OSD��Ϣ */
    MULTI_OSD_INFO_S    stOSDInfo;

    /** ��Ƶ����������Ƶ����ʵ����Ŀ, ���ȡֵΪ#IMOS_STREAM_MAXNUM, �Ӿ������ײ�ֵ���� */
    ULONG_32               ulVideoStreamNum;

    /** ��Ƶ����Ϣ���� */
    VIDEO_STREAM_S      astVideoStream[IMOS_STREAM_MAXNUM];

    /** ������򣬰����˶�����Լ��ڵ�������� */
    DETECT_AREA_S       stDetectArea;

    /** ��ѧ���ò��� */
    OPTICS_PARAM_S      stOpticsParam;
}VINCHNL_BIND_CAMERA_FOR_ECR_S;

/**
 * @struct tagSemaOutputInfoSdkWithTime
 * @brief �����������Ϣ(  ��ʱ��)
 * @attention
 */
typedef struct tagSemaOutputInfoSdkWithTimeForECR
{
    /** ������������� */
    CHAR        szSemaDesc[IMOS_DESC_LEN];

     /** ����������澯������ʽ, ȡֵ1Ϊ����; 2Ϊ���� */
    ULONG_32       ulTriggerMode;

    /** ����������澯����ʱ�䣬��λΪ�� */
    ULONG_32       ulOutPutTime;

} SEMA_OUTPUT_INFO_WITHTIME_FOR_ECR_S;

/**
 * @struct tagVoutChnlBindScreen
 * @brief �����������ͨ������Ϣ
 * @attention
 */
typedef struct tagVoutChnlBindScreen
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S stDCChannelIndex;

    /** ��������Ϣ */
    SCREEN_INFO_S       stScreenInfo;

    /** �߼����ͨ����Ϣ */
    VOUT_CHANNEL_S      stVoutChannel;

    /** OSD��Ϣ */
    OSD_INFO_S          stOSDInfo;

    /** �������ͨ����Ϣ */
    PHYOUT_CHANNEL_S    stPhyoutChannel;
}VOUTCHNL_BIND_SCREEN_S;


/***************************************************************************************
���ڹ���
***********************************************************************************/

/**
 * @struct tagSerialInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagSerialInfo
{
    /** ����ģʽ, ȡֵΪ#IMOS_SERIAL_MODE_E */
    ULONG_32       ulSerialMode;

    /** ��������, ȡֵΪ#SERIAL_TYPE_E */
    ULONG_32       ulSerialType;

    /** ������, ȡֵΪ
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

    /** ����λ, ȡֵΪ5~8 */
    ULONG_32       ulDataBit;

    /** ֹͣλ, ȡֵΪ1~2 */
    ULONG_32       ulStopBit;

    /** У��λ, ȡֵΪ
        #IMOS_PARITY_NULL
        #IMOS_PARITY_ODD
        #IMOS_PARITY_EVEN
    */
    ULONG_32       ulParityBit;

    /** ����, 0Ϊ������; 1Ϊ�������; 2ΪӲ������ */
    ULONG_32       ulFlowControl;

} SERIAL_INFO_S;


/**
 * @struct tagSerialQueryItem
 * @brief ���ڲ�ѯ��Ϣ�б�Ԫ��Ϣ
 * @attention
 */
typedef struct tagSerialQueryItem
{
    /** �������� */
    ULONG_32   ulSerialIndex;

    /** �������� */
    ULONG_32   ulSerialType;

    /* ����ģʽ */
    ULONG_32   ulSerialMode;
} SERIAL_QUERY_ITEM_S;


/**
 * @struct tagSerialRelationItem
 * @brief ���������Դ��Ϣ��(��ѯ���������Դ�б�ʱ����)
 * @attention
 */
typedef struct tagSerialRelationItem
{
    /** ��Դ���� */
    CHAR    szResCode[IMOS_RES_CODE_LEN];

    /** ��Դ���� */
    CHAR    szResName[IMOS_NAME_LEN];

    /** ��Դ����, ȡֵΪ#IMOS_TYPE_E*/
    ULONG_32 ulResType;

}SERIAL_RELATION_ITEM_S;


/***************************************************************************************
����������
***********************************************************************************/
/**
 * @struct tagSemaInputInfo
 * @brief ���뿪������Ϣ
 * @attention
 */
typedef struct tagSemaInputInfo
{
    /** ���뿪��������, �ɲ��� */
    CHAR        szSemaDesc[IMOS_DESC_LEN];

    /** ���뿪�����澯������ʽ, ȡֵ1Ϊ����; 2Ϊ���� */
    ULONG_32       ulTriggerMode;

    /** �Ƿ�ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** ��·���ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnableDetectFlag;
} SEMA_INPUT_INFO_S;


/**
 * @struct tagSemaOutputInfoSdk
 * @brief �����������Ϣ
 * @attention
 */
typedef struct tagSemaOutputInfoSdk
{
    /** ������������� */
    CHAR        szSemaDesc[IMOS_DESC_LEN];

     /** ����������澯������ʽ, ȡֵ1Ϊ����; 2Ϊ���� */
    ULONG_32       ulTriggerMode;

} SEMA_OUTPUT_INFO_S;

/**
 * @struct tagSemaOutputInfoV2
 * @brief �����������ϢV2
 * @attention
 */
typedef struct tagSemaOutputInfoV2
{
    /** �����������Ϣ */
    SEMA_OUTPUT_INFO_S  stBaseOutputInfo;

    /** ����������澯����ʱ�䣬��λΪ�� */
    ULONG_32               ulOutPutTime;

    /** �����������ʶ */
    CHAR             szSwitchToken[IMOS_CODE_LEN];

    /**���� */
    CHAR                szRetention[128];
}SEMA_OUTPUT_INFO_V2_S;


/**
 * @struct tagSemaQueryItem
 * @brief ��������ѯ��Ϣ��(��ѯ�������б�ʱ����)
 * @attention
 */
typedef struct tagSemaQueryItem
{
    /** ����������, Ϊ�������ı�� */
    ULONG_32       ulSemaIndex;

    /** ����������, ȡֵ0Ϊ����; 1Ϊ��� */
    ULONG_32       ulSemaType;

    /** ���뿪�����澯������ʽ, ȡֵ1Ϊ����; 2Ϊ���� */
    ULONG_32       ulTriggerMode;

    /** �Ƿ�ʹ�ܣ�1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

} SEMA_QUERY_ITEM_S;

/**
 * @struct tagSemaQueryItemV2
 * @brief ��������ѯ��Ϣ��V2(��ѯ�������б�ʱ����)
 * @attention
 */
typedef struct tagSemaQueryItemV2
{
    /** ��������ѯ��Ϣ�� */
    SEMA_QUERY_ITEM_S stSemaQueryItemInfo;

    /** �����������豸���� */
    CHAR    szDevCode[IMOS_CODE_LEN];

    /** ���������� */
    CHAR    szSemaDesc[IMOS_DESC_LEN];

    /** �澯Դ���߸澯����Ƿ�ʹ��, 1Ϊʹ��, 0Ϊ��ʹ�� */
    ULONG_32   ulAlarmIOEnableFlag;

    /** �澯Դ���߸澯�������, �澯Դ���߸澯�����ʹ��ʱ��Ч */
    CHAR    szAlarmIOCode[IMOS_CODE_LEN];

    /** �澯Դ���߸澯�������, �澯Դ���߸澯�����ʹ��ʱ��Ч */
    CHAR    szAlarmIOName[IMOS_NAME_LEN];

    /** ���뿪��������·���ʹ��, 1Ϊʹ��; 0Ϊ��ʹ��. ��Ϊ���뿪����ʱ��Ч */
    ULONG_32   ulEnableDetectFlag;

    /** �澯����򿪵�ʱ��. ���澯���ʹ��ʱ��Ч */
    ULONG_32   ulOutputTime;

    /** �����ֶ� */
    CHAR    szReserve[64];
} SEMA_QUERY_ITEM_V2_S;


/************************************************************************************************************
OSD
************************************************************************************************************/

/**
 * @struct tagOsdImageListItem
 * @brief OSDͼƬ��Ϣ
 * @attention
 */
typedef struct tagOsdImageListItem
{
    /** OSDͼƬ���� */
    CHAR szOsdImageCode[IMOS_RES_CODE_LEN];

    /** OSDͼƬ�� */
    CHAR    szName[IMOS_NAME_LEN];
}OSD_IMAGE_LIST_ITEM_S;



/*******************************************************************************
ģ�����
********************************************************************************/
/**
 * @struct tagVideoInChannelParam
 * @brief ��Ƶ�������ģ��
 * @attention
 */
typedef struct tagVideoInChannelParam
{
    /** �鲥��ַ */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�, ȡֵΪ10002-65534, �ұ���Ϊż�� */
    ULONG_32 ulMulticastPort;

    /** MSѡ�����Ӧ����, 1Ϊ����Ӧ; 0Ϊָ��MS��2Ϊ������MS, ȡֵΪ#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulIsAutofit;

    /** �Ƿ�����ͼ���ڵ����澯, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulEnableKeepout;

    /** �Ƿ������˶����澯, 1Ϊ�����˶����澯; 0Ϊ�������˶����澯 */
    ULONG_32 ulEnableMotionDetect;

    /** �Ƿ�������Ƶ��ʧ�澯, 1Ϊ������Ƶ��ʧ�澯; 0Ϊ��������Ƶ��ʧ�澯 */
    ULONG_32 ulEnableVideoLost;

    /** �󶨵Ĵ��ڱ��, ��������д0 */
    ULONG_32 ulSerialIndex;

    /** ����, ȡֵΪ��0~255�� */
    ULONG_32 ulBrightness;

    /** �Աȶ�, ȡֵΪ��0~255�� */
    ULONG_32 ulContrast;

    /** ���Ͷ�, ȡֵΪ��0~255�� */
    ULONG_32 ulSaturation;

    /** ɫ��, ȡֵΪ��0~255�� */
    ULONG_32 ulTone;

    /** �Ƿ���������, 1Ϊ��������; 0Ϊ���������� */
    ULONG_32 ulIsMute;

    /** ��Ƶ����, ȡֵΪ#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioCoding;

    /** ��Ƶ����, ȡֵΪ#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** ��Ƶ������, ȡֵΪ#IMOS_AUDIO_SAMPLING_E */
    ULONG_32 ulSamplingRate;

    /** ��Ƶ����, �������� */
    ULONG_32 ulAudioCodeRate;

    /** ��Ƶ����ֵ, ȡֵΪ(0-255) */
    ULONG_32 ulIncrement;
}VIN_CHANNEL_PARAM_S;

/**
 * @struct tagVideoStreamParam
 * @brief ��Ƶ����������ģ��
 * @attention
 */
typedef struct tagVideoStreamParam
{
    /** �������� */
    ULONG_32       ulStreamType;

    /** ������ */
    ULONG_32       ulStreamIndex;

    /** ��ʹ�ܱ�ʶ */
    ULONG_32       ulEnabledFlag;

    /** �����䷽ʽ */
    ULONG_32       ulTranType;

    /** �����ʽ,ö��ֵΪIMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /** �ֱ��� */
    ULONG_32       ulResolution;

    /** ���� */
    ULONG_32       ulBitRate;

    /** ֡�� */
    ULONG_32       ulFrameRate;

    /** GOPģʽ */
    ULONG_32       ulGopMode;

    /** I֡��� */
    ULONG_32       ulIFrameInterval;

    /** ͼ������ */
    ULONG_32       ulImageQuality;

    /** ������ģʽ CBR VBR */
    ULONG_32       ulEncodeMode;

    /** ���ȼ������ڱ���ģʽΪCBRʱ�����á�0-�����Է�ʽ��1-�����Է�ʽ */
    ULONG_32       ulPriority;

    /** ����ƽ����ö��ֵΪIMOS_STREAM_SMOOTH_E��Ŀǰֻ֧��0��5������ */
    ULONG_32       ulSmoothValue;

}VIDEO_STREAM_PARAM_S;

/**
 * @struct tagVideoAreaParam
 * @brief ��Ƶ�����������
 * @attention
 */
typedef struct tagVideoAreaParam
{
    /** �������� */
    ULONG_32       ulAreaIndex;

    /** �Ƿ�ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** ������ */
    ULONG_32       ulSensitivity;

    /** �������� */
    AREA_SCOPE_S stAreaScope;

    /** ��Ƶ��������: �ڵ����ƶ����ڸǣ��μ�ö��ֵ:#VIDEO_AREA_TYPE_E */
    ULONG_32       ulAreaType;

}VIDEO_AREA_PARAM_S;

/**
 * @struct tagVinChannelTemplet
 * @brief ��Ƶ����ͨ��ģ��
 * @attention
 */
typedef struct tagVinChannelTemplet
{
    /** ��Ƶ�������ģ�� */
    VIN_CHANNEL_PARAM_S stVinChannel;

    /** �豸�ͺš����豸������ص�ģ��, ��Ҫ�õ����ֶ� */
    ULONG_32 ulDevType;

    /** dsp imageѡ��ȡֵΪ#IMOS_STREAM_RELATION_SET_E */
    ULONG_32 ulEncodeSet;

    /** ��ʽ ��ȡֵΪIMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** ��Ƶ����������ģ�� */
    VIDEO_STREAM_PARAM_S astVideoStream[IMOS_STREAM_MAXNUM_II];
}VIN_CHANNEL_TEMPLET_S;


/**
 * @struct tagChannelTempletBasic
 * @brief ͨ��ģ�������Ϣ
 * @attention
 */
typedef struct tagChannelTempletBasic
{
    /** ģ������ */
    CHAR szTempletName[IMOS_NAME_LEN];

    /** ģ��������ʱ�� */
    CHAR  szLastUpdateTime[IMOS_TIME_LEN];
}CHANNEL_TEMPLET_BASIC_S;


/**
 * @struct tagChannelTempQueryItem
 * @brief ͨ��ģ����Ϣ��(��ѯͨ��ģ���б�ʱ����)
 * @attention
 */
typedef struct tagChannelTempQueryItem
{
    /** ģ����� */
    CHAR        szTempletCode[IMOS_RES_CODE_LEN];

    /** ģ������ */
    CHAR        szTempletName[IMOS_NAME_LEN];

    /** ģ��������ʱ�� */
    CHAR        szLastUpdateTime[IMOS_TIME_LEN];

    /** �豸�ͺ�, ȡֵΪ#IMOS_DEVICE_TYPE_E */
    ULONG_32       ulDevType;

    /** ���ײ�, ȡֵΪ#IMOS_STREAM_RELATION_SET_E */
    ULONG_32       ulEncodeSet;

    /** ��ʽ, ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32       ulStandard;
}CHANNEL_TEMP_QUERY_ITEM_S;


/**
 * @struct tagECChannelTemplet
 * @brief ECͨ��ģ��
 * @attention
 */
typedef struct tagECChannelTemplet
{
    /** ģ�������Ϣ */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

    /** ��Ƶ�������ģ�� */
    VIN_CHANNEL_TEMPLET_S       stVinChannelTemp;
}EC_CHANNEL_TEMPLET_S;



/**
 * @struct tagVideoOutChannelParam
 * @brief ��Ƶ���ͨ����Ϣ
 * @attention
 */
typedef struct tagVideoOutChannelParam
{
    /** ��������, ȡֵΪ#IMOS_STREAM_TYPE_E, Ŀǰ��֧��#IMOS_ST_TS */
    ULONG_32 ulStreamType;

    /** �Ƿ�����������, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulEnableJitterBuff;
}VOUT_CHANNEL_PARAM_S;


/**
 * @struct tagPhyOutChannelParam
 * @brief ��Ƶ�������
 * @attention
 */
typedef struct tagPhyOutChannelParam
{
    /** ����ģʽ��ȡֵΪ1��4������BNC�ڵķ����� */
    ULONG_32 ulPhyoutMode;

    /** �����ʽ��ȡֵΪ#IMOS_VIDEO_FORMAT_E */
    ULONG_32 ulDecodeFormat;

    /** ��Ƶ��ʽ��ȡֵΪ#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioFormat;

    /** �������ã�ȡֵΪ#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** �Ƿ�������������, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulAudioEnabled;

    /** �������, ȡֵΪ1~7 */
    ULONG_32 ulVolume;

    /** ��Ƶ���ѡ��, �ӹ���ģʽ����#ulPhyoutMode�������������ģʽȡֵΪ1, ���ֵΪ1; �������ģʽȡֵΪ4, ���ֵȡֵΪ1~4 */
    ULONG_32 ulOutputIndex ;
}PHYOUT_CHANNEL_PARAM_S;


/**
 * @struct tagVoutChannelTemplet
 * @brief ��Ƶ���ͨ��ģ��
 * @attention
 */
typedef struct tagVoutChannelTemplet
{

    /** ��Ƶ���ͨ��ģ�� */
    VOUT_CHANNEL_PARAM_S    stVoutChannel;

    /** �豸�ͺţ�ȡֵΪ#IMOS_DEVICE_TYPE_E */
    ULONG_32 ulDevType;

    /** ���ײ�ѡ��ȡֵΪ#IMOS_STREAM_RELATION_SET_E, Ŀǰ��Ƶ���ͨ����֧��
        #IMOS_SR_H264_SHARE��
        #IMOS_SR_MPEG4_SHARE
        #IMOS_SR_MPEG2_SHARE
        #IMOS_SR_H264_MJPEG
    */
    ULONG_32 ulEncodeSet;

    /** ��ʽ��ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** ��Ƶ�������ͨ��ģ�� */
    PHYOUT_CHANNEL_PARAM_S stPhyVoutChannel;
}VOUT_CHANNEL_TEMPLET_S;


/**
 * @struct tagDCChannelTemplet
 * @brief DCͨ��ģ��
 * @attention
 */
typedef struct tagDCChannelTemplet
{
    /** ģ�������Ϣ */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

    /** ��Ƶ�������ģ�� */
    VOUT_CHANNEL_TEMPLET_S      stVoutChannelTemp;

}DC_CHANNEL_TEMPLET_S;


/**
 * @struct tagPlanTemplet
 * @brief ʱ��ƻ�ģ��
 * @attention
 */
typedef struct tagPlanTemplet
{
    /** ģ�������Ϣ */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

    /** ��ѭ��������ѭ��, ȡֵΪ:MM_JOBSCHDTYPE_E */
    ULONG_32                       ulCycleType;

    /** ʱ��ƻ��ṹ�� */
    PLAN_TIME_S                 stPlanTimeInfo;
}PLAN_TEMPLET_S;

/*------------------------------------------------------------------------------------------*/

/**
 * @struct tagSnmpV1Special
 * @brief SNMP_V1�����Բ���
 * @attention
 */
typedef struct tagSnmpV1Special
{
    /** ��ȡ������ */
    CHAR  szRoCommunity[IMOS_STRING_LEN_64];

    /** д�������� */
    CHAR  szRwCommunity[IMOS_STRING_LEN_64];
}SNMPV1_SPECIAL_S;

/**
 * @struct tagSnmpV3Special
 * @brief SNMP_V3�����Բ���
 * @attention
 */
typedef struct tagSnmpV3Special
{
    /** ��ȫ���� */
    ULONG_32 ulSecurityMode;

    /** ��֤���� */
    ULONG_32 ulAuthScheme;

    /** ��֤���� */
    CHAR  szAuthPassword[IMOS_STRING_LEN_64];

    /** �������� */
    ULONG_32 ulPrivScheme;

    /** �������� */
    CHAR  szPrivPassword[IMOS_STRING_LEN_64];

}SNMPV3_SPECIAL_S;

/**
 * @struct tagSnmpSpecial
 * @brief SNMP������ģ��
 * @attention
 */
typedef struct tagSnmpSpecial
{
    /** SNMP_V1�����Բ��� */
    SNMPV1_SPECIAL_S stSnmpV1Special;

    /** SNMP_V3�����Բ��� */
    SNMPV3_SPECIAL_S stSnmpV3Special;

}SNMP_SPECIAL_S;

/**
 * @struct tagSnmpTemp
 * @brief SNMPģ��
 * @attention
 */
typedef struct tagSnmpTemp
{
    /** Э��˿ں� */
    ULONG_32 ulSnmpPort;

    /** �����ϻ�ʱ�� */
    ULONG_32 ulTimeout;

    /** �������Դ��� */
    ULONG_32 ulRetries;

    /** ���Ķ�Ӧ�汾�� */
    ULONG_32 ulSnmp_version;

    /** ���������� */
    CHAR  szContextName[IMOS_STRING_LEN_64];

    /** ��ȫģ������ */
    CHAR  szSecurityName[IMOS_STRING_LEN_64];

    /** SNMP������ģ�� */
    SNMP_SPECIAL_S              stSnmpSpecial;

    /** ģ�������Ϣ */
    CHANNEL_TEMPLET_BASIC_S     stTempBasicInfo;

}SNMP_TEMP_S;


/*******************************************************************************
DM
********************************************************************************/

/**
* @struct tagDMInfo
* @brief DM��Ϣ�ṹ��
* @attention ��
*/
typedef struct tagDMInfo
{
    /** DM����, DM��Ψһ��ʶ */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** DM���� */
    CHAR  szDMName[IMOS_NAME_LEN];

    /** DM���ͣ�ĿǰֵΪ0 */
    ULONG_32 ulDMType;

    /** DM������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** DM����, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** �����ֶ� */
    CHAR szReserve[32];
}DM_INFO_S;


/**
* @struct tagDMQueryItem
* @brief DM��Ϣ��(��ѯDM�б�ʱ����)
* @attention ��
*/
typedef struct tagDMQueryItem
{
    /** DM����, DM��Ψһ��ʶ */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** DM���� */
    CHAR  szDMName[IMOS_NAME_LEN];

    /** DM����, ȡֵ0: DM3.0, 1: DM3.5 */
    ULONG_32 ulDMType;

    /** DM������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** DM������֯���� */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /**�豸��ַ */
    CHAR szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ö��ֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** �����ֶ� */
    CHAR szReserve[32];
}DM_QUERY_ITEM_S;


/***************************************************************************
�豸-�洢�豸
****************************************************************************/


/**
 * @struct tagStoreDevInfo
 * @brief �洢�豸(IPSAN)��Ϣ
 * @attention
 */
typedef struct tagStoreDevInfo
{
    /** �洢�豸���� */
    CHAR  szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸���� */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** IPSAN �洢�豸���� ��1-VX 2-EX */
    ULONG_32 ulStoreDevType;

    /** �洢�豸��ַ */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** �洢�豸����DM���� */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸��¼�û��� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �洢�豸��¼�û����� */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** �洢�豸����, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** IPSAN �洢�豸������(ֻ�����豸����ΪVX��ʱ�����Ч) ��0��VX1500��1��VX1500-E��2��VX1600 */
    ULONG_32   ulStoreDevSubType;

    /** �����ֶ� */
    CHAR szReserve[60];
}STORE_DEV_INFO_S;


/**
 * @struct tagStoreDevQueryItem
 * @brief �洢�豸��Ϣ��(��ѯ�洢�豸�б�ʱ����)
 * @attention
 */
typedef struct tagStoreDevQueryItem
{
    /** �洢�豸���� */
    CHAR    szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸���� */
    CHAR    szStoreDevName[IMOS_NAME_LEN];

    /** IPSAN �洢�豸���ͣ�1-VX; 2-EX */
    ULONG_32   ulStoreDevType;

    /** ����DM���� */
    CHAR    szDMCode[IMOS_DEVICE_CODE_LEN];

    /** ����DM���� */
    CHAR    szDMName[IMOS_NAME_LEN];

    /** �豸��ַ���ͣ�1-IPv4; 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** �豸��ַ */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** �洢�豸������,��λ:M(��)  */
    ULONG_32   ulStoreDevTotalSize;

    /** �洢�豸��ʹ������,��λ:M(��)  */
    ULONG_32   ulStoreDevUsedSize;

    /** �洢����״̬, �μ�mp_ism_pub.h�е�ö��"�豸�洢����״̬",
        0-�豸�޷����ʣ�1-�豸�洢������2-�豸˥��(������Դ�޷����ʣ�������Դ�洢����) */
    ULONG_32   ulStoreRunStatus;

    /** �豸�Ƿ�����, ȡֵ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** IPSAN �洢�豸������(ֻ�����豸����ΪVX��ʱ�����Ч) ��0��VX1500��1��VX1500-E��2��VX1600 */
    ULONG_32   ulStoreDevSubType;

    /** �����ֶ� */
    CHAR szReserve[60];
}STORE_DEV_QUERY_ITEM_S;



/**
 * @struct tagStoreDevSimpleQueryItem
 * @brief �洢�豸����Ϣ��(��ѯ�洢�豸����Ϣʱ����)
 * @attention
 */
typedef struct tagStoreDevSimpleQueryItem
{
    /** �洢�豸���� */
    CHAR    szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸���ͣ�ȡֵΪ#STORE_DEV_TYPE_E */
    ULONG_32       ulStoreDevType;

    /** �洢�豸���� */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** �洢�豸������,��λ:M(��) */
    ULONG_32       ulStoreDevTotalSize;

    /** �洢�豸������������,��λ:M(��) */
    ULONG_32       ulStoreDevUsedSize;

}STORE_DEV_SIMPLE_QUERY_ITEM_S;

/***************************************************************************
�豸-VX500����
****************************************************************************/

/**
 * @struct tagVX500Info
 * @brief VX500�豸��Ϣ
 * @attention
 */
typedef struct tagVX500Info
{
    /** VX500�豸����, VX500��Ψһ��ʶ */
    CHAR  szVX500Code[IMOS_DEVICE_CODE_LEN];

    /** VX500�豸���� */
    CHAR  szVX500Name[IMOS_NAME_LEN];

    /** VX500�豸����, �Ǳ�����, ĿǰĬ��Ϊ0 */
    ULONG_32 ulVX500Type;

    /** VX500������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸����, ���Բ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** �����ֶ� */
    CHAR szReserve[32];
}VX500_INFO_S;


/**
 * @struct tagVX500QueryItem
 * @brief VX500��Ϣ��(��ѯVX500�б�ʱ����)
 * @attention
 */
typedef struct tagVX500QueryItem
{
    /** VX500�豸���� */
    CHAR    szVX500Code[IMOS_DEVICE_CODE_LEN];

    /** VX500�豸���� */
    CHAR    szVX500Name[IMOS_NAME_LEN];

    /** VX500�豸���ͣ��Ǳ����ĿǰĬ����дΪ0 */
    ULONG_32   ulVX500Type;

    /** VX500������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

     /** VX500������֯���� */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** �豸��ַ���ͣ�1-IPv4; 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** �豸��ַ */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** VX500�豸������,��λ:M(��) */
    ULONG_32   ulVX500DevTotalSize;

    /** VX500�豸��ʹ������,��λ:M(��) */
    ULONG_32   ulVX500DevUsedSize;

    /** �洢����״̬, �μ�mp_ism_pub.h�е�ö��"�豸�洢����״̬",
        0-�豸�޷����ʣ�1-�豸�洢������2-�豸˥��(������Դ�޷����ʣ�������Դ�洢����) */
    ULONG_32   ulStoreRunStatus;


    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** �����ֶ� */
    CHAR szReserve[32];
}VX500_QUERY_ITEM_S;


/**
 * @struct tagArrayInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagArrayInfo
{
    /** �������� */
    CHAR       szArrayName[IMOS_NAME_LEN];

    /** ��λ��������ʵ�ʵĲ�λ����, ���ֵΪ#IMOS_ARRAY_SLOT_MAXNUM */
    ULONG_32       ulNumber;

    /** ��λ������ */
    ULONG_32       aulSlotNum[IMOS_ARRAY_SLOT_MAXNUM];

    /** �������ͣ�0-JBOD 1-RAID0 2-RAID1 3-RAID5 4-RAID10 */
    ULONG_32       ulArrayType;
} ARRAY_INFO_S;


/**
 * @struct tagArrayStatusInfo
 * @brief ����״̬��Ϣ
 * @attention
 */
typedef struct tagArrayStatusInfo
{
    /** ����״̬,0-���� 1-�ؽ� 2-˥�� 3-�޷�ʹ�� 4-��ʼ�� */
    ULONG_32   ulArrayStatus;

    /** ����������,��λ:M(��) */
    ULONG_32   ulArrayTotleSize;

    /** ��������,��λ:M(��) */
    ULONG_32   ulArrayUsedSize;

    /** �Ƿ��Ѿ����⻯ */
    BOOL_T  bisVirtualized;

    /** ������Ϣ */
    ARRAY_INFO_S    stArrayInfo;

    /** �ؽ����� */
    ULONG_32   ulRebuildProgress;
} ARRAY_STATUS_INFO_S;


/**
 * @struct tagSlotInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagSlotInfo
{
    /** ��λ�� */
    ULONG_32       ulSlotNum;

    /** �Ƿ��Ѿ���Ӳ�� */
    ULONG_32       ulHasDisk;

    /** ��������,��λ:M(��)  */
    ULONG_32       ulUsedSize;

    /** ����������,��λ:M(��)  */
    ULONG_32       ulDiskCapacity;

    /** ����״̬��ö��ֵΪ#SS_DISK_STATE_E */
    ULONG_32       ulStatus;

    /** ���̳��� */
    CHAR        szManufacturer[IMOS_NAME_LEN];
} SLOT_INFO_S;


/*******************************************************************************
MS
********************************************************************************/

/**
 * @struct tagMSInfo
 * @brief MS�豸��Ϣ
 * @attention
 */
typedef struct tagMSInfo
{
    /** MS�豸����, MS��Ψһ��ʶ */
    CHAR  szMSCode[IMOS_DEVICE_CODE_LEN];

    /** MS�豸���� */
    CHAR  szMSName[IMOS_NAME_LEN];

    /** MS������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸����, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN - IMOS_STRING_LEN_128];

	/* MS���ͣ��μ�ö��MS_DEV_TYPE_E */
	ULONG_32  ulMSType;

	/* �����ֶ� */
    CHAR    szReserve[124];


}MS_INFO_S;


/**
 * @struct tagMSQueryItem
 * @brief MS��Ϣ��(��ѯMS�б�ʱ����)
 * @attention
 */
typedef struct tagMSQueryItem
{
    /** MS���� */
    CHAR    szMSCode[IMOS_DEVICE_CODE_LEN];

    /** MS���� */
    CHAR    szMSName[IMOS_NAME_LEN];

    /** MS������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

     /** MS������֯���� */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** MS�豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** �豸��ַ */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

}MS_QUERY_ITEM_S;


/*******************************************************************************
TS
********************************************************************************/

/**
 * @struct tagTSInfo
 * @brief TS�豸��Ϣ
 * @attention
 */
typedef struct tagTSInfo
{
    /** TS�豸����, TS��Ψһ��ʶ */
    CHAR  szTSCode[IMOS_DEVICE_CODE_LEN];

    /** TS�豸���� */
    CHAR  szTSName[IMOS_NAME_LEN];

    /** TS������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸����, �ɲ��� */
    CHAR    szDevDesc[IMOS_DESC_LEN - IMOS_STRING_LEN_128];

	/*TS���ͣ��μ�ö��TS_DEV_TYPE_E*/
	ULONG_32  ulTSType;

	/* �����ֶ� */
    CHAR    szReserve[124];	


}TS_INFO_S;

/**
 * @struct tagTSQueryItem
 * @brief TS��Ϣ��(��ѯTS�б�ʱ����)
 * @attention
 */
typedef struct tagTSQueryItem
{
    /** TS���� */
    CHAR    szTSCode[IMOS_DEVICE_CODE_LEN];

    /** TS���� */
    CHAR    szTSName[IMOS_NAME_LEN];

    /** TS������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

     /** TS������֯���� */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** TS�豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32   ulDevaddrtype;

    /** �豸��ַ */
    CHAR    szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

}TS_QUERY_ITEM_S;

/* Begin added by l01420, 2014-6-30 for �Զ���TSת����� */
/**
 * @struct tagTSRuleUAInfo
 * @brief TS�����е�UA��Ϣ
 * @attention
 */
typedef struct tagTSRuleUAInfo
{   
    /** UA���� ��ȡֵ��ΧTS_RULE_SRC_TYPE_E����TS_RULE_DST_TYPE_E*/
    ULONG_32    ulUAType;

    /** UA�����ֶΣ�Ĭ������дUA�ı���*/
    CHAR        szUACode[IMOS_CODE_LEN];

    /** UA����*/
    CHAR        szUAName[IMOS_NAME_LEN];
}TS_RULE_UA_INFO_S;

/**
 * @struct tagTSRuleInfo
 * @brief TS������Ϣ
 * @attention
 */
typedef struct tagTSRuleInfo
{
    /* ��������*/
    CHAR                szRuleName[IMOS_NAME_LEN];
    
    /* ������� */
    CHAR                szRuleCode[IMOS_CODE_LEN];
    
    /* �Ƿ����ô˹��� */
    BOOL_T              bIsEnable;

    /**
       *    ��Ҫת����Ŀ�������ͣ�ȡֵ��ΧIMOS_STREAM_TYPE_E, 
       *    ֻ����IMOS_ST_TS, IMOS_ST_H3C_ES,IMOS_ST_PS,IMOS_ST_3984���֣�����ȥ��
       */
    ULONG_32            ulStreamType;

    /* �����䷽ʽ��ȡֵ��ΧIMOS_TRANS_TYPE_E�� Ŀǰ���������� */
    ULONG_32            ulTransType;

    /* �����ֶ� */
    CHAR                szReserved[IMOS_STRING_LEN_512];
}TS_RULE_INFO_S;


/**
 * @struct tagTSRuleQueryInfo
 * @brief TS������Ϣ(��ѯ�ӿ�ʹ��)
 * @attention
 */
typedef struct tagTSRuleQueryInfo
{
    /* ��������*/
    CHAR                szRuleName[IMOS_NAME_LEN];
    
    /* ������� */
    CHAR                szRuleCode[IMOS_CODE_LEN];
    
    /* �Ƿ����ô˹��� */
    BOOL_T              bIsEnable;

    /**
       *    ��Ҫת����Ŀ�������ͣ�ȡֵ��ΧIMOS_STREAM_TYPE_E, 
       *    ֻ����IMOS_ST_TS, IMOS_ST_H3C_ES,IMOS_ST_PS,IMOS_ST_3984���֣�����ȥ��
       */
    ULONG_32            ulStreamType;

    /* �����䷽ʽ��ȡֵ��ΧIMOS_TRANS_TYPE_E�� Ŀǰ���������� */
    ULONG_32            ulTransType;

    /* �����ֶ� */
    CHAR                szReserved[IMOS_STRING_LEN_512];

}TS_RULE_QUERY_ITEM_S;
/* End added by l01420, 2014-6-30 for �Զ���TSת����� */


/***************************************************************************
���������
****************************************************************************/

/**
 * @struct tagShareCameraBase
 * @brief ���������������Ϣ
 * @attention
 */
typedef struct tagShareCameraBase
{
    /** ��������� */
    CHAR   szCamName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR   szCamCode[IMOS_RES_CODE_LEN];

    /** ������������� */
    CHAR   szCamShareCode[IMOS_RES_CODE_LEN];

    /** ����������Ȩ�� */
    ORG_AUTHORITY_S             stAuthority;
 }SHARE_CAMERA_BASE_S;

/**
 * @struct tagShareCameraBaseV2
 * @brief ���������������ϢV2
 * @attention
 */
typedef struct tagShareCameraBaseV2
{
    SHARE_CAMERA_BASE_S   stShareCamera;

    /** ����֯�ڵ���� */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];
 }SHARE_CAMERA_BASE_V2_S;

/**
* @struct tagShareCamInfo
* @brief �����������Ϣ��(��ѯ����������б�ʱ����)
*/
typedef struct tagShareCamInfo
{

    /** ���������������Ϣ */
    SHARE_CAMERA_BASE_S stShareCamBaseInfo;

    /** ���������״̬,ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE */
    ULONG_32                   ulDevStatus;

    /** �Ƿ�Ϊ�����豸��1Ϊ�����豸��0Ϊ�Ǳ����豸 */
    BOOL_T                  bIsLocalDev;

    /** ���������������룬�����Ϊ��������ʱʹ�� */
    CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** ���������EC���� */
    CHAR                    szECCode[IMOS_DEVICE_CODE_LEN];
}SHARE_CAM_INFO_S;
/**
* @struct tagShareCamInfoV2
* @brief �����������Ԫ��ϢV2
*/
typedef struct tagShareCamInfoV2
{
    /** ���������������Ϣ */
    SHARE_CAMERA_BASE_V2_S     stShareCamBaseInfo;

    /** �����״̬,ȡֵΪIMOS_DEV_STATUS_ONLINE/IMOS_DEV_STATUS_OFFLINE */
    ULONG_32                   ulDevStatus;

    /** �Ƿ�Ϊ�����豸��1��ʾ�ǣ�0��ʾ�� */
    BOOL_T                  bIsLocalDev;

    /** �Ƿ��ѹ��������1��ʾ�ǣ�0��ʾ�� */
    BOOL_T                  bIsShared;

    /** �����֧�ֵ�����Ŀ */
    ULONG_32                   ulStreamNum;

    /** ���������������룬�����Ϊ��������ʱʹ�� */
    CHAR                    szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** ���������EC���� */
    CHAR                    szECCode[IMOS_DEVICE_CODE_LEN];
}SHARE_CAM_INFO_V2_S;


/**
* @struct tagShareCamList
* @brief ����������б���Ϣ
*/
typedef struct tagShareCamList
{
    /** �������������� */
    CHAR                    szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** ��������������� */
    CHAR                    szDomainName[IMOS_NAME_LEN];

    /** �������ͣ�ȡֵΪ AS_DEVSHARE_OPERATION_TYPE_E */
    ULONG_32                   ulOperType;

    /** �������͵��豸��Ŀ */
    ULONG_32                   ulDevNum;

    /** �����������Ϣ�б� */
    SHARE_CAM_INFO_S    astCamInfo[IMOS_ONCE_SHARE_RES_MAXNUM];
}SHARE_CAM_LIST_S;


/***************************************************************************
������֯
****************************************************************************/

/**
 * @struct tagShareOrgBase
 * @brief ������֯������Ϣ
 * @attention
 */
typedef struct tagShareOrgBase
{
     /** ��֯�ڵ���� */
    CHAR szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��֯�ڵ����� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** ����֯�ڵ���� */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��֯���������ʱ�Ķ������ */
    CHAR szOrgShareCode[IMOS_RES_CODE_LEN];

    /** ��֯״̬ */
    ULONG_32 ulStatus;

 }SHARE_ORG_BASE_S;


/**
* @struct tagShareOrgInfo
* @brief ������֯��Ԫ��Ϣ
*/
typedef struct tagShareOrgInfo
{
    /** ��֯����������룬��֯Ϊ��������ʱʹ�� */
    CHAR                szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �Ƿ��ѹ��������1��ʾ�ǣ�0��ʾ�� */
    BOOL_T              bIsShared;

    /** �Ƿ��Զ����������#BOOL_TRUE��ʾ�Զ���������򣬷�֮ȡֵΪ#BOOL_FALSE */
    BOOL_T bIsAutoShare;

    /** ������֯������Ϣ */
    SHARE_ORG_BASE_S    stShareOrgBaseInfo;

}SHARE_ORG_INFO_S;

/***************************************************************************
����澯Դ
****************************************************************************/

/**
 * @struct tagShareAlarmSrcBase
 * @brief ����澯Դ������Ϣ
 * @attention
 */
typedef struct tagShareAlarmSrcBase
{
    /** �澯Դ���� */
    CHAR        szAlarmSrcCode[IMOS_RES_CODE_LEN];

    /** �澯Դ������ */
    CHAR        szAlarmSrcName[IMOS_NAME_LEN];

    /** ����֯�ڵ���� */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �澯Դ������� */
    CHAR   szAlarmSrcShareCode[IMOS_RES_CODE_LEN];

 }SHARE_ALARMSRC_BASE_S;


/**
* @struct tagShareAlarmSrcInfo
* @brief ����澯Դ��Ԫ��Ϣ
*/
typedef struct tagShareAlarmSrcInfo
{
    /** �澯Դ����������룬�澯ԴΪ��������ʱʹ�� */
    CHAR                szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �Ƿ��ѹ��������1��ʾ�ǣ�0��ʾ�� */
    BOOL_T              bIsShared;

    /** ����澯Դ������Ϣ */
    SHARE_ALARMSRC_BASE_S    stShareAlmSrcBaseInfo;

}SHARE_ALARMSRC_INFO_S;

/***************************************************************************
����澯���
****************************************************************************/
/**
 * @struct tagShareAlarmOutBase
 * @brief ����澯���������Ϣ
 * @attention
 */
typedef struct tagShareAlarmOutBase
{
    /** �澯������� */
    CHAR        szAlarmOutCode[IMOS_CODE_LEN];

    /** �澯��������� */
    CHAR        szAlarmOutName[IMOS_NAME_LEN];

    /** ����֯�ڵ���� */
    CHAR        szParentOrgCode[IMOS_CODE_LEN];

    /** �澯���������� */
    CHAR        szAlarmOutShareCode[IMOS_CODE_LEN];

 }SHARE_ALARMOUT_BASE_S;

/**
* @struct tagShareAlarmOutInfo
* @brief ����澯�����Ԫ��Ϣ
*/
typedef struct tagShareAlarmOutInfo
{
    /** �澯�������������룬�澯���Ϊ��������ʱʹ�� */
    CHAR                        szExDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �Ƿ��ѹ��������1��ʾ�ǣ�0��ʾ�� */
    BOOL_T                      bIsShared;

    /** ����澯���������Ϣ */
    SHARE_ALARMOUT_BASE_S       stShareAlmOutBaseInfo;

}SHARE_ALARMOUT_INFO_S;

/***************************************************************************
�����ͼ
****************************************************************************/

/**
 * @struct tagShareMapBase
 * @brief �����ͼ������Ϣ
 * @attention
 */
typedef struct tagShareMapBase
{
     /** ��ͼ���� */
    CHAR szMapCode[IMOS_CODE_LEN];

    /** ��ͼ���� */
    CHAR szMapName[IMOS_NAME_LEN];

    /** ����֯�ڵ���� */
    CHAR szParentOrgCode[IMOS_CODE_LEN];

    /** ��ͼ���������ʱ�Ķ������ */
    CHAR szMapShareCode[IMOS_CODE_LEN];

 }SHARE_MAP_BASE_S;


/**
* @struct tagShareMapInfo
* @brief �����ͼ��Ϣ
*/
typedef struct tagShareMapInfo
{
    /** ��ͼ����������룬��ͼΪ��������ʱʹ�� */
    CHAR                szExDomainCode[IMOS_CODE_LEN];

    /** �Ƿ��ѹ��������1��ʾ�ǣ�0��ʾ�� */
    BOOL_T              bIsShared;

    /** �����ͼ������Ϣ */
    SHARE_MAP_BASE_S    stShareMapBaseInfo;

}SHARE_MAP_INFO_S;

/***************************************************************************
Ԥ��λ
****************************************************************************/

/**
 * @struct tagPresetInfo
 * @brief Ԥ��λ��Ϣ
 * @attention
 */
typedef struct tagPresetInfo
{
    /** Ԥ��λֵ, ȡֵ��ΧΪ#PTZ_PRESET_MINVALUE~�����������ļ������õ�Ԥ��λ���ֵ */
    ULONG_32       ulPresetValue;

    /** Ԥ��λ����, ��Ҫ��д */
    CHAR        szPresetDesc[IMOS_DESC_LEN];
 }PRESET_INFO_S;


/***************************************************************************
Ѳ��·��
****************************************************************************/

/**
 * @struct tagCruisePathItem
 * @brief Ѳ��·���е�Ԥ��λ��Ϣ
 * @attention
 */
typedef struct tagCruisePathItem
{
    /** ��ţ���ʶ��Ԥ��λ��Ѳ��·���е�ִ��˳�� */
    ULONG_32       ulSeqID;

    /** �����Ԥ��λֵ����1��2�ȣ�ȡֵ��ΧΪ#PTZ_PRESET_MINVALUE~�����������ļ������õ�Ԥ��λ���ֵ
        ��չ֧�ֹ켣Ѳ��
            901��909,�����˶�,�ٶ�Ϊ1��9
            911��919,�����˶�,�ٶ�Ϊ1��9
            921��929,�����˶�,�ٶ�Ϊ1��9
            931��939,�����˶�,�ٶ�Ϊ1��9 */
    ULONG_32       ulPresetValue;

    /** Ԥ��λ���� */
    CHAR        szPresetDesc[IMOS_DESC_LEN];

    /** Ԥ��λͣ��ʱ��, ���ֵΪ64 */
    ULONG_32       ulPreSetStopTime;
}CRUISE_PATH_ITEM_S;

/**
 * @struct tagCruisePathInfo
 * @brief Ѳ��·����Ϣ
 * @attention
 */
typedef struct tagCruisePathInfo
{
    /** ��������� */
    CHAR                        szCamName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR                        szCamCode[IMOS_RES_CODE_LEN];

    /** Ѳ��·������ */
    CHAR                        szCruisePathName[IMOS_NAME_LEN];

    /** Ѳ��·��Ԥ��λ������Ԥ��λ��ʵ����Ŀ, ȡֵ������#IMOS_CRUISE_PATH_PRESET_MAX_COUNT */
    ULONG_32                       ulCruisePathItemNum;

    /** Ѳ��·��Ԥ��λ���� */
    CRUISE_PATH_ITEM_S          astCruisePathItemList[IMOS_CRUISE_PATH_PRESET_MAX_COUNT];

    /** �����ֶ� */
    CHAR szReserve[8];
}CRUISE_PATH_INFO_S;

/**
 * @struct tagCruisePathQueryItem
 * @brief Ѳ��·����Ϣ��(��ѯѲ��·���б�ʱ����)
 * @attention
 */
typedef struct tagCruisePathQueryItem
{
   /** Ѳ��·�߱��� */
   CHAR     szCruisePathCode[IMOS_RES_CODE_LEN];

   /** Ѳ��·������ */
   CHAR     szCruisePathName[IMOS_NAME_LEN];
}CRUISE_PATH_QUERY_ITEM_S;


/***************************************************************************
Ѳ���ƻ�
****************************************************************************/

/**
 * @struct tagCruisePlanBase
 * @brief Ѳ���ƻ�������Ϣ
 * @attention
 */
typedef struct tagCruisePlanBase
{
    /** �ƻ����� */
    CHAR        szCruisePlanName[IMOS_NAME_LEN];

    /** �ƻ����������� */
    CHAR        szCreatorName[IMOS_NAME_LEN];

    /** �ƻ��������� */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** ��������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** Ѳ���ƻ�������֯���� */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �ƻ�����, ȡֵΪ#PLAN_TYPE_E */
    ULONG_32       ulPlanType;

    /** �ƻ�����, �ɲ��� */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}CRUISE_PLAN_BASE_S;

/**
 * @struct tagCruisePlanInfo
 * @brief Ѳ���ƻ�������Ϣ
 * @attention
 */
typedef struct tagCruisePlanInfo
{
    /** Ѳ���ƻ�������Ϣ */
    CRUISE_PLAN_BASE_S  stCruiseBaseInfo;

    /** Ѳ���ƻ�ʱ����Ϣ */
    PLAN_TIME_FOR_RES_S stCruiseTimeInfo;
}CRUISE_PLAN_INFO_S;

/**
 * @struct tagCruisePlanQueryItem
 * @brief Ѳ���ƻ���Ϣ��(��ѯѲ���ƻ��б�ʱ����)
 * @attention
 */
typedef struct tagCruisePlanQueryItem
{
    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** Ѳ���ƻ����� */
    CHAR        szCruisePlanName[IMOS_NAME_LEN];

    /** Ѳ���ƻ����� */
    CHAR        szCruisePlanCode[IMOS_RES_CODE_LEN];

    /** Ѳ���ƻ����������� */
    CHAR        szCreatorName[IMOS_NAME_LEN];

    /** Ѳ���ƻ��������� */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** Ѳ���ƻ�״̬, BOOL_TRUEΪ�ƻ��Ѿ�����; BOOL_FALSEΪ�ƻ�δ���� */
    ULONG_32       ulPlanStatus;

     /** �����ֶ� */
     CHAR szReserve[8];
 }CRUISE_PLAN_QUERY_ITEM;



/***************************************************************************
 �洢��Դ
****************************************************************************/

/**
 * @struct taAlarmStorageTime
 * @brief ��ǰ����洢ʱ��
 * @attention
 */
typedef struct taAlarmStorageTime
{
    /** ��ǰ¼��ʱ��, ��ֵ��������, ����д����ULONGֵ */
    ULONG_32       ulPreAlarmTime;

    /** ����¼��ʱ��, ȡֵ��ΧΪ30~1800 */
    ULONG_32       ulAfterAlarmTime;

}ALARM_STORAGE_TIME_S;


/**
 * @struct tagStorageInfo
 * @brief ͨ���洢��Ϣ
 * @attention
 */
typedef struct tagStorageInfo
{
    /** �洢����,ö��ֵΪAS_DEVCM_STORAGE_TYPE_E, 0-IPSAN, 1-NAS, 2-���ش洢 */
    ULONG_32       ulStorageType;

    /** �洢��������, ȡֵ��Χ(0-2), 0��ʾipsan�洢, 1��ʾnas�洢, 2��ʾlocal�洢 */
    ULONG_32       ulStorageMedium;

    /** �洢ģʽ,��3��bit��ʾ��
        ��0λ���ƻ�
        ��1λ���ֶ�
        ��2λ���澯
    */
    ULONG_32       ulStorageMode;

    /** �ƻ������� */
    ULONG_32       ulPlanStreamType;

    /** �ֹ������� */
    ULONG_32       ulManualStreamType;

    /** �¼������� */
    ULONG_32       ulEventStreamType;

    /** ������������ԣ�ȡֵ0��1, 0��ʾ��ֹͣ,1����  */
    ULONG_32       ulDiskFullPolicy;

}STORAGE_INFO_S;

/**
 * @struct tagStoreResInfo
 * @brief �洢��Դ��Ϣ
 * @attention ��IMOS_ExpandStoreRes��: �����洢�豸��Ϣ,��ulStoreDevType, szStoreDevCode, szStoreDevName����.
 */
typedef struct tagStoreResInfo
{

    /** �洢����, ȡֵΪ#AS_DEVCM_STORAGE_TYPE_E */
    ULONG_32       ulStorageType;

    /** �洢�豸����, ȡֵΪ#STORE_DEV_TYPE_E */
    ULONG_32       ulStoreDevType;

    /** �洢�豸���� */
    CHAR        szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸���� */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** ָ���洢�豸�ռ䲻��ʱ,�Ƿ�֧���Զ�ѡ��洢�豸(BOOL_TRUEΪ֧��; BOOL_FALSEΪ��֧��) */
    BOOL_T  bStoreDevAutoSelect;

    /** �ƻ�������, ��ֵ�����������ECѡ������ײ�ֵ�й�, �����ײ�ֵΪ�����ײ�ʱ, ���������ֵΪ1; �����ײ�ֵΪ˫���ײ�ʱ, ���������ֵΪ2 */
    ULONG_32       ulPlanStreamType;

    /** �ֹ�������, ȡֵ�μ�#ulPlanStreamType��˵�� */
    ULONG_32       ulManualStreamType;

    /** �¼�������, ȡֵ�μ�#ulPlanStreamType��˵�� */
    ULONG_32       ulEventStreamType;

    /** ������������ԣ�ȡֵΪ#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32       ulDiskFullPolicy;

    /** �洢�ռ�(��IMOS_AssignStoreRes��,ָ��һ�η���Ĵ洢�ռ�; ��IMOS_ExpandStoreRes��,ָ��չ�ռ�[���ѷ���ռ�]), ��ֵȡֵ������, ��λΪMB */
    ULONG_32       ulStoreSize;

    /** ��ǰ����¼��ʱ�� */
    ALARM_STORAGE_TIME_S stAlarmStorageTime;

}STORE_RES_INFO_S;

/**
 * @struct tagStoreResInfoV2
 * @brief �洢��Դ��Ϣ
 * @attention ��IMOS_ExpandStoreRes��: �����洢�豸��Ϣ,��ulStoreDevType, szStoreDevCode, szStoreDevName����.
 */
typedef struct tagStoreResInfoV2
{
    /**�洢��Ϣ*/
    STORE_RES_INFO_S        stStoreResInfo;

    /**DM �豸����*/
    CHAR        szDMDevCode[IMOS_CODE_LEN];

    /**DM �豸����*/
    CHAR        szDMDevName[IMOS_NAME_LEN];

}STORE_RES_INFO_V2_S;

/**
 * @struct tagStoreResQueryItem
 * @brief �洢��Դ��Ϣ��(��ѯ�洢��Դ�б�ʱ����)
 * @attention �Դ洢�豸�������ж��Ƿ�����˴洢��Դ, ������洢�豸����Ϊ��, ����û�з���洢��Դ��
 */
typedef struct tagStoreResQueryItem
{

    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR        szCamCode[IMOS_CODE_LEN];

    /** �洢�豸���� */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** �洢�豸��DM���� */
    CHAR        szDMName[IMOS_NAME_LEN];

    /** �Ƿ��ƶ��洢�ƻ�, BOOL_TRUEΪ�ƶ��洢�ƻ�; BOOL_FALSEΪδ�ƶ��洢�ƻ� */
    BOOL_T      bHasStorePlan;

    /** �洢�ƻ����� */
    CHAR        szStorePlanCode[IMOS_CODE_LEN];

    /** �ƻ�״̬, BOOL_TRUEΪ�ƻ�����; BOOL_FALSEΪ�ƻ�δ���� */
    BOOL_T      bPlanStatus;

    /** �洢��Դ״̬(#ISM_RES_FAILUREΪ����,1 ����,2 δ֪) */
    ULONG_32   ulResStatus;

    /** "�ƻ��洢"״̬(0 δ���ƻ��洢,1 ���ƻ��洢,2 δ֪) */
    ULONG_32   ulPlanStoreStatus;
}STORE_RES_QUERY_ITEM_S;

/**
 * @struct tagStoreResExtInfo
 * @brief �洢��Դ��չ��Ϣ
 * @attention
 */
typedef struct tagStoreResExtInfo
{
    /** �������豸���� */
    CHAR    szParentDevCode[IMOS_DEVICE_CODE_LEN];

    /** �������豸����,ȡֵ��ΧΪ #IMOS_TYPE_EC��#IMOS_TYPE_ECR */
    ULONG_32   ulParentDevType;

    /** �������豸������,��ȡֵ����Ϊ#IMOS_DEVICE_TYPE_E�еı���������洢���ܵı��������� */
    ULONG_32   ulParentSubDevType;

    /* �洢�ռ�ģʽ: ȡֵ��ΧΪ #AS_DEVCM_STORAGE_TYPE_E  */
    ULONG_32   ulStorageType;

    /** ����¼��״̬: ȡֵ��ΧΪ MANUAL_STORE_STATUS_E */
    ULONG_32   ulManStoStatus;

    /** �����ֶ�1 */
    CHAR    szReserved[IMOS_STRING_LEN_32 - 4];
}STORE_RES_EXT_INFO_S;

/**
 * @struct tagStoreResQueryItemV2
 * @brief �洢��Դ��Ϣ��V2(��ѯ�洢��Դ�б�ʱ����)
 * @attention
 */
typedef struct tagStoreResQueryItemV2
{
    /** �洢��Դ��Ϣ */
    STORE_RES_QUERY_ITEM_S stStoreResQryItem;

    /** �洢��Դ��չ��Ϣ */
    STORE_RES_EXT_INFO_S   stStoreResExtInfo;
}STORE_RES_QUERY_ITEM_V2_S;

/**
 * @struct tagDMShareResInfo
 * @brief ����洢��Դ����Ϣ�ṹ��
 * @attention
 */
typedef struct tagDMShareResInfo
{
    /** ������Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ������С����MBΪ��λ */
    ULONG_32  ulCapacity;

    /** �洢�豸����, ȡֵΪ#STORE_DEV_TYPE_E */
    ULONG_32  ulStoreDevType;

    /** �洢�豸���� */
    CHAR  szStoreDevCode[IMOS_CODE_LEN];

    /** �洢�豸���� */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /**DM �豸����*/
    CHAR  szDMDevCode[IMOS_CODE_LEN];

    /**DM �豸����*/
    CHAR  szDMDevName[IMOS_NAME_LEN];

    /** �����ֶ� */
    CHAR  szReserve[32];
}DM_SHARE_RES_INFO_S;

/**
 * @struct tagDmShareResQueryItem
 * @brief������Դ��ѯ��Ϣ��(��ѯ������Դ�б�ʱ����)
 */
typedef struct tagDmShareResQueryItem
{
    /** ������Դ���� */
    CHAR  szShareResCode[IMOS_CODE_LEN];

    /** ������Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** �洢�豸���� */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** �洢�豸��DM���� */
    CHAR  szDMName[IMOS_NAME_LEN];

    /** ������С����MBΪ��λ */
    ULONG_32  ulCapacity;

    /** ������Դ״̬(#ISM_RES_FAILURE �޷����� 1 ����, 2 δ֪) */
    ULONG_32  ulResStatus;

    /** �����ֶ� */
    CHAR  szReserve[32];
}DM_SHARE_RES_QUERY_ITEM_S;

/**
 * @struct tagShareStorageDeviceInfo
 * @brief ������Դ�ɴ洢��Ϣ
 */
typedef struct tagShareStorageDeviceInfo
{
    /** �洢�豸���� */
    CHAR  szStoreDevCode[IMOS_CODE_LEN];

    /** �洢�豸���� */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /* ������ */
    ULONG_32 ulTotalCapacity;

    /* ʣ������ */
    ULONG_32 ulSpareCapacity;

    /* ������Դ������ */
    ULONG_32 ulTotalShareCapacity;

    /* �ɴ洢Сʱ��(������Դ������ / (���豸�����ô洢���������֮�� + ��Ҫ�������������)) */
    ULONG_32 ulStorageHours;

    /** �����ֶ� */
    CHAR  szReserve[32];
}SHARE_STORAGE_DEVICE_INFO_S;


/**
 * @struct tagShareStorageDeviceInfo
 * @brief DM ������Դ�ɴ洢��Ϣ
 */
typedef struct tagDMShareStorageDeviceInfo
{
    /** DM �豸����*/
    CHAR  szStoreDevCode[IMOS_CODE_LEN];

    /** DM �豸����*/
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /* ������Դ������ */
    ULONG_32 ulTotalShareCapacity;

    /* �ɴ洢Сʱ��(������Դ������ / (���豸�����ô洢���������֮�� + ��Ҫ�������������)) */
    ULONG_32 ulStorageHours;

    /** �����ֶ� */
    CHAR  szReserve[32];
}DM_SHARE_STORAGE_DEVICE_INFO_S;

/***************************************************************************
�洢�ƻ�
****************************************************************************/
/**
 * @struct tagStorePlanBase
 * @brief �洢�ƻ�������Ϣ
 * @attention
 */
typedef struct tagStorePlanBase
{
    /** �洢�ƻ����� */
    CHAR    szStorePlanName[IMOS_NAME_LEN];

    /** �ƻ�����ʱ�� */
    CHAR    szPlanCreateTime[IMOS_TIME_LEN];

    /** �ƻ�����, ȡֵΪ#PLAN_TYPE_E */
    ULONG_32   ulPlanType;

    /** ��֯���� */
    CHAR    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �ƻ�����, �ɲ��� */
    CHAR    szPlanDesc[IMOS_DESC_LEN];

    /** �Ƿ���洢, BOOL_TRUEΪ����洢; BOOL_FALSEΪ�ǰ���洢 */
    BOOL_T  bIsDayStore;

    /** ����洢������(�ݲ�ʹ��) */
    ULONG_32   ulStoreDays;
 }STORY_PLAN_BASE_S;


/**
 * @struct tagStoragePlan
 * @brief �洢�ƻ���Ϣ
 * @attention
 */
typedef struct tagStoragePlan
{
    /** �洢�ƻ�������Ϣ */
    STORY_PLAN_BASE_S   stStorageBasicInfo;

    /** �洢�ƻ�ʱ����Ϣ */
    PLAN_TIME_S         stStorageTimeInfo;

}STORAGE_PLAN_INFO_S;


/**
 * @struct tagStoryPlanQueryItem
 * @brief ��ѯ�洢�ƻ�ʱ�õ���Ϣ���洢�ƻ�������Ϣ����������ֹ�����Ϣ�����ڽ����ѯ��ʾ
 * @attention
 */
typedef struct tagStoryPlanQueryItem
{

    /** �洢�ƻ����� */
    CHAR        szStorePlanCode[IMOS_RES_CODE_LEN];

    /** �洢�ƻ����� */
    CHAR    szStorePlanName[IMOS_NAME_LEN];

    /** �ƻ�����ʱ�� */
    CHAR    szPlanCreateTime[IMOS_TIME_LEN];

    /** �ƻ�״̬��BOOL_TRUE ��ʾ�ƻ��Ѿ����� */
    ULONG_32       ulPlanStatus;

    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** �����������֯���� */
    CHAR        szOrgName[IMOS_NAME_LEN];

 }STORY_PLAN_QUERY_ITEM;


/***************************************************************************
������Դ����
****************************************************************************/
/**
 * @struct tagSwitchBase
 * @brief ������Դ������Ϣ
 * @attention
 */
typedef struct tagSwitchBase
{
    /** �������� */
    CHAR                szSwitchName[IMOS_NAME_LEN];

    /** ��֯���� */
    /* CHAR                szOrgCode[IMOS_DOMAIN_CODE_LEN]; */

    /** ��������, �ɲ��� */
    CHAR                szSwitchDesc[IMOS_DESC_LEN];
}SWITCH_BASE_S;


/**
 * @struct tagSwitchUnit
 * @brief ������Դ�е��������Ϣ
 * @attention
 */
typedef struct tagSwitchUnit
{
    /** ��������� */
    CHAR        szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR        szCameraName[IMOS_NAME_LEN];

    /** ��� */
    ULONG_32       ulSequence;

     /** �л�ʱ�� */
    ULONG_32       ulInterval;
}SWITCH_UNIT_S;

/**
 * @struct tagSwitchResoure
 * @brief ������Դ��Ϣ
 * @attention
 */
typedef struct tagSwitchResoure
{
    /** ���л�����Ϣ */
    SWITCH_BASE_S   stSwitchBaseInfo;

    /** ������Դ������������Դ��ʵ����Ŀ, ���ȡֵΪ#IMOS_SWITCH_CAM_MAXNUM */
    ULONG_32               ulSwitchResNum;

    /** ������Դ���� */
    SWITCH_UNIT_S    astSwitchUnitList[IMOS_SWITCH_CAM_MAXNUM];
}SWITCH_RESOURE_S;

/**
 * @struct tagSwitchUnitV2
 * @brief ������Դ��V2
 * @attention ��
 */
typedef struct tagSwitchUnitV2
{
    /** ������Դ��V1 */
    SWITCH_UNIT_S stSwitchUnitV1;

    /** ������,ȡֵΪ#IMOS_FAVORITE_STREAM_E */
    ULONG_32 ulStreamType;

    /** �����ֶ� */
    CHAR szReserve[128];
} SWITCH_UNIT_V2_S;

/**
 * @struct tagSwitchResoureV2
 * @brief ������ԴV2
 * @attention ��
 */
typedef struct tagSwitchResoureV2
{
    /** ������Դ������Ϣ */
    SWITCH_BASE_S stSwitchBaseInfo;

    /** ������Դ����Ŀ,���ȡֵΪ#IMOS_SWITCH_CAM_MAXNUM_V2 */
    ULONG_32 ulSwitchResNum;

    /** ������Դ���б� */
    SWITCH_UNIT_V2_S astSwitchUnitList[IMOS_SWITCH_CAM_MAXNUM_V2];
} SWITCH_RESOURE_V2_S;

/**
 * @struct tagSwitchResQueryItem
 * @brief ������Դ��Ϣ��(��ѯ������Դ�б�ʱ����)
 * @attention
 */
typedef struct tagSwitchResQueryItem
{
    /** ������Դ���� */
    CHAR                szSwitchResCode[IMOS_RES_CODE_LEN];

    /** ������Դ���� */
    CHAR                szSwitchName[IMOS_NAME_LEN];

    /** ������Դ������֯���� */
    CHAR                szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ������Դ������֯���� */
    CHAR                szOrgName[IMOS_NAME_LEN];

}SWITCH_RES_QUERY_ITEM_S;

/* Begin Added by dengshuhua00673, 2012-12-15 of �Զ�������Ѳ */
/**
 * @struct tagSwitchResQueryItemV2
 * @brief ������Դ�б���Ϣ��Ԫ��Ϣ
 * @attention
 */
typedef struct tagSwitchResQueryItemV2
{
    /** ������Ϣ���� */
    CHAR                szSwitchResCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR                szSwitchName[IMOS_NAME_LEN];

    /** ������֯���� */
    CHAR                szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ������֯���� */
    CHAR                szOrgName[IMOS_NAME_LEN];

	/** ͨ��������Դ���ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E */
	ULONG_32               ulSwitchType;

}SWITCH_RES_QUERY_ITEM_V2_S;
/* End Added by dengshuhua00673, 2012-12-15 of �Զ�������Ѳ */

/**
 * @struct tagSwitchRecord
 * @brief ���м�¼
 * @attention
 */
typedef struct tagSwitchRecord
{
    /** ������Դ���� */
    CHAR                szSwitchResCode[IMOS_RES_CODE_LEN];

    /** ��ʾ������ */
    CHAR                szScreenCode[IMOS_CODE_LEN];

    /** ��ʾ������ */
    CHAR                szScreenName[IMOS_NAME_LEN];

    /** �����û����� */
    CHAR                szUserCode[IMOS_CODE_LEN];

    /** �û���¼ID */
    CHAR                szUserLoginCode[IMOS_RES_CODE_LEN];

    /** �û���ַ */
    CHAR                szUserAddr[IMOS_IPADDR_LEN];

    /* ��ǰ����״̬ */
    ULONG_32               ulState;
}SWITCH_RECORD_S;

/***************************************************************************
���мƻ�
****************************************************************************/

/**
 * @struct tagSwitchPlanBase
 * @brief ���мƻ�������Ϣ
 * @attention
 */
typedef struct tagSwitchPlanBase
{
    /** ���мƻ����� */
    CHAR        szPlanName[IMOS_NAME_LEN];

    /** ���мƻ��������� */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** ���������� */
    CHAR        szScrCode[IMOS_RES_CODE_LEN];

    /** ���������� */
    CHAR        szScrName[IMOS_NAME_LEN];

    /** �ƻ�����, ȡֵΪ#PLAN_TYPE_E */
    ULONG_32       ulPlanType;

    /** ���мƻ�������֯���� */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �ƻ�����, �ɲ��� */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}SWITCH_PLAN_BASE_S;


/**
 * @struct tagSwitchPlanInfo
 * @brief ���мƻ���Ϣ
 * @attention
 */
typedef struct tagSwitchPlanInfo
{
    /** ���мƻ�������Ϣ */
    SWITCH_PLAN_BASE_S  stSwitchBaseInfo;

    /** ���мƻ�ʱ����Ϣ */
    PLAN_TIME_FOR_RES_S stSwitchTimeInfo;
}SWITCH_PLAN_INFO_S;

/**
 * @struct tagSwitchPlanInfo
 * @brief ���мƻ���Ϣ
 * @attention
 */
typedef struct tagSwitchPlanInfoV2
{
    /** ���мƻ�������Ϣ */
    SWITCH_PLAN_BASE_S  stSwitchBaseInfo;

    /** ���мƻ�ʱ����Ϣ */
    PLAN_TIME_FOR_RES_V2_S stSwitchTimeInfo;
}SWITCH_PLAN_INFO_V2_S;


/**
 * @struct tagSwitchPlanQueryItem
 * @brief ���мƻ���Ϣ��(��ѯ���мƻ��б�ʱ����)
 * @attention
 */
typedef struct tagSwitchPlanQueryItem
{
    /** ���мƻ����� */
    CHAR            szSwitchPlanCode[IMOS_RES_CODE_LEN];

    /** ���мƻ����� */
    CHAR            szPlanName[IMOS_NAME_LEN];

    /** ���мƻ��������� */
    CHAR            szCreatTime[IMOS_TIME_LEN];

    /** ���������� */
    CHAR            szScrName[IMOS_NAME_LEN];

    /** �ƻ�״̬��BOOL_TRUEΪ�ƻ��Ѿ�����, BOOL_FALSEΪ�ƻ�δ���� */
    ULONG_32           ulPlanStatus;

}SWITCH_PLAN_QUERY_ITEM_S;




/***************************************************************************
�澯
****************************************************************************/

/**
 * @struct tagAlarmSrc
 * @brief �澯Դ��Ϣ
 * @attention
 */
typedef struct tagAlarmSrc
{

    /** �澯Դ������ */
    CHAR        szAlarmSrcName[IMOS_NAME_LEN];

    /** �澯Դ������, ȡֵΪ#ALARM_DEV_TYPE_E */
    ULONG_32       ulAlarmSrcType;

    /** �����˸澯Դ��ͨ�������豸�ı��� */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �����˸澯Դ��ͨ�������豸������ */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** �澯Դ�󶨵�ͨ������, ȡֵ�Ӹ澯Դ�����豸���Ͷ��� */
    ULONG_32       ulChannelIndex;
}ALARM_SRC_S;

/**
 * @struct tagAlarmSrcQueryItem
 * @brief �澯Դ��ѯ��Ϣ�б�Ԫ��Ϣ
 * @attention
 */
typedef struct tagAlarmSrcQueryItem
{

    /** �澯Դ������ */
    CHAR        szAlarmSrcName[IMOS_NAME_LEN];

    /** �澯Դ�ı��� */
    CHAR        szAlarmSrcCode[IMOS_RES_CODE_LEN];

    /** �豸���ͣ�����ö��ȡֵ�μ�#IMOS_TYPE_E�� */
    ULONG_32       ulDevType;

    /** �豸�����ͣ�����ö��ȡֵ�μ�#IMOS_DEVICE_TYPE_E�� */
    ULONG_32       ulDevSubType;

    /** �澯Դ������֯����(Ŀǰ������,����ʹ��) */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �澯Դ������֯����(Ŀǰ������,����ʹ��) */
    CHAR        szOrgName[IMOS_NAME_LEN];

    /* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */
    /** NVR��ECR�����豸���� */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2012-7-18 for ECR NVR���� */

}ALARM_SRC_QUERY_ITEM_S;

/**
* @struct tagAlarmSrcQueryItemEx
* @brief �澯Դ��ѯ��Ϣ�б�Ԫ��չ��Ϣ
* @attention
*/
typedef struct tagAlarmSrcQueryItemEx
{
    /* �澯Դ��ѯ��Ϣ�б�Ԫ��Ϣ */
    ALARM_SRC_QUERY_ITEM_S stAlarmSrcQueryItem;

    /** ���豸���ͣ�����ö��ȡֵ�μ�#IMOS_TYPE_E�� */
    ULONG_32 ulParentDevType;

    /** ���豸�����ͣ�����ö��ȡֵ�μ�#IMOS_DEVICE_TYPE_E�� */
    ULONG_32 ulParentSubDevType;

    /* �Ƿ�֧������ */
    BOOL_T bHasLinkage;

    /* �Ƿ�֧�ֲ��� */
    BOOL_T bHasGuard;

    /* �Ƿ���ڸ澯�����Զ��� */
    BOOL_T bHasAlarmEnabled;

}ALARM_SRC_QUERY_ITEM_EX_S;

/**
 * @struct tagAlarmExporter
 * @brief �澯����豸��Ϣ
 * @attention
 */
typedef struct tagAlarmExporter
{

    /** �澯����豸������ */
    CHAR        szAlarmExporterName[IMOS_NAME_LEN];

    /** �澯����豸������, ȡֵΪ#ALARM_DEV_TYPE_E */
    ULONG_32       ulAlarmExporterType;

    /** �澯����豸�󶨵�ͨ�������豸�ı��� */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �澯����豸�󶨵�ͨ�������豸������ */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** �澯����豸�󶨵�ͨ������, ȡֵ�Ӹ澯Դ�����豸���Ͷ��� */
    ULONG_32       ulChannelIndex;
}ALARM_EXPORTER_S;

/**
 * @struct tagAlarmExporterQueryItem
 * @brief �澯����豸��ѯ��Ϣ�б�Ԫ��Ϣ
 * @attention
 */
typedef struct tagAlarmExporterQueryItem
{

    /** �澯����豸������ */
    CHAR        szAlarmExporterName[IMOS_NAME_LEN];

    /** �澯����豸�ı��� */
    CHAR        szAlarmExporterCode[IMOS_RES_CODE_LEN];

    /** �澯����豸������,ö������Ϊ:ALARM_DEV_TYPE_E */
    ULONG_32       ulAlarmExporterType;

    /** �澯Դ������֯ */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ������֯���� */
    CHAR        szOrgName[IMOS_NAME_LEN];

}ALARM_EXPORTER_QUERY_ITEM_S;

/**
 * @struct tagEventRecord
 * @brief �澯��¼��Ϣ
 * @attention
 */
typedef struct tagEventRecord
{
    /** �澯����*/
    CHAR szEventRecordCode[IMOS_RES_CODE_LEN];

    /** �澯����, ȡֵΪ#AlARM_TYPE_E */
    ULONG_32 ulEventType;

    /** �豸����*/
    CHAR szDeviceCode[IMOS_DEVICE_CODE_LEN];

    /** �豸����*/
    CHAR  szDeviceName[IMOS_NAME_LEN];

    /** �澯����*/
    CHAR szActiveName[IMOS_NAME_LEN];

    /** �澯����, ȡֵΪ#ALARM_SEVERITY_LEVEL_E */
    ULONG_32 ulEventSecurity;

    /** �澯����ʱ��*/
    CHAR szEventTime[IMOS_TIME_LEN];

    /** �澯״̬, ȡֵΪ#ALARM_STATUS_E */
    ULONG_32 ulAlarmStatus;

    /** �¼��������� */
    CHAR   szSecurityName[IMOS_NAME_LEN];

    /** �¼�������ʾ��ɫ */
    CHAR   szSecurityColor[IMOS_STRING_LEN_14];

    /** �澯�˾�ʱ��*/
    CHAR szCheckTime[IMOS_TIME_LEN];

    /** �澯�˾��û�*/
    CHAR szCheckUser[IMOS_NAME_LEN];

    /** �澯ȷ��ʱ��*/
    CHAR szAckTime[IMOS_TIME_LEN];

    /** �澯ȷ���û�*/
    CHAR szAckUser[IMOS_NAME_LEN];

    /** ������ֵ��*/
    CHAR szKeyValue[IMOS_STRING_LEN_128];

    /** �澯������Ϣ*/
    CHAR szEventDesc[IMOS_DESC_LEN];

    /** �澯ȷ������*/
    CHAR szAckSuggestion[IMOS_DESC_LEN];

    /** �Ƿ��� */
    ULONG_32 ulIsMisinform;

    /** �Ƿ�Ԥ���澯 */
    ULONG_32 ulIsPlanAlarm;

    /** �Ƿ�������Ԥ������ѯ�澯�������̼�¼�ã� */
    ULONG_32 ulIsOncePlanAlarm;

    /** �Ƿ�����Ҫ�ֹ���������*/
    ULONG_32 ulIsManualTask;
}EVENT_RECORD_S;

/**
 * @struct tagStoreAction
 * @brief �����洢
 * @attention
 */
typedef struct tagStoreAction
{

    /** ������������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szCamName[IMOS_NAME_LEN];

}STORE_ACTION_S;


/**
 * @struct tagPresetAction
 * @brief ����Ԥ��λ
 * @attention
 */
typedef struct tagPresetAction
{

    /** ������������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** Ԥ��λֵ, ȡֵ��ΧΪ#PTZ_PRESET_MINVALUE~�����������ļ������õ�Ԥ��λ���ֵ */
    ULONG_32       ulPresetValue;

    /** Ԥ��λ������ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szPresetDesc[IMOS_DESC_LEN];
}PRESET_ACTION_S;


/**
 * @struct tagScreenLiveAction
 * @brief ����ʵ��������
 * @attention
 */
typedef struct tagScreenLiveAction
{

    /** ������������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ�*/
    CHAR        szCamName[IMOS_NAME_LEN];

    /** �������û�����ʱ���û����� */
    CHAR        szUserCode[IMOS_USER_CODE_LEN];

    /** �������û�����ʱ���û����ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szUserName[IMOS_NAME_LEN];

    /** �������û�����Ļ���, ȡֵΪ1 */
    ULONG_32       ulScreenIndex ;

    /** �������û��Ĵ������ */
    CHAR        szXPPaneCode[IMOS_RES_CODE_LEN];

    /** �Ƿ�ץ��, ȡֵΪ0��1 */
    ULONG_32       ulSnatchImage;

    /** ץ�ļ����ȡֵ��λ���� */
    ULONG_32       ulInterval;

    /** ץ������ */
    ULONG_32       ulSnatchCounter;

    /** �Ƿ����þ�ǰ¼��ȡֵ0����1���� */
    ULONG_32       ulIsBefAlarmReplay;

    /** ��ǰ¼��ʱ������ȡֵ��λ�� */
    ULONG_32       ulBefAlarmRepInterval;

    /** ������ǰ¼����û���Ļ���, ȡֵΪ1 */
    ULONG_32       ulBefAlarmRepScreenIndex;

    /** �������û��Ĵ������ */
    CHAR        szBefAlarmRepXPPaneCode[IMOS_CODE_LEN];

}SCREENLIVE_ACTION_S;

/**
 * @struct tagScreenLiveActionForECR
 * @brief ����ʵ��������
 * @attention
 */
typedef struct tagScreenLiveActionForECR
{

    /** ������������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ�*/
    CHAR        szCamName[IMOS_NAME_LEN];

    /** �������û�����ʱ���û����� */
    CHAR        szUserCode[IMOS_USER_CODE_LEN];

    /** �������û�����ʱ���û����ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szUserName[IMOS_NAME_LEN];

    /** �������û�����Ļ���, ȡֵΪ1 */
    ULONG_32       ulScreenIndex ;

    /** �������û��Ĵ������ */
    CHAR        szXPPaneCode[IMOS_RES_CODE_LEN];

}SCREENLIVE_ACTION_FOR_ECR_S;


/**
 * @struct tagMonitorLiveAction
 * @brief ����ʵ����������
 * @attention
 */
typedef struct tagMonitorLiveAction
{

    /** ������������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** ��������������豸�ı������ײ�, ֻ���ڲ�ѯ, ����ʱ��Ч, ȡֵΪ#IMOS_STREAM_RELATION_SET_E */
    ULONG_32       ulEncodeSet;

    /** ���������ʵ��ʱ��������, ȡֵΪ#IMOS_FAVORITE_STREAM_E */
    ULONG_32       ulStreamType;

    /** �������������� */
    CHAR        szSrcCode[IMOS_RES_CODE_LEN];

    /** �������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szSrcName[IMOS_NAME_LEN];

    /** ���������������豸�Ľ������ײ�, ֻ���ڲ�ѯ, ����ʱ��Ч, ȡֵΪ#IMOS_STREAM_RELATION_SET_E�е�
        ����ֵΪ���������ײͣ�
        1��H264(#IMOS_SR_H264_SHARE)
        3: MJPEG(#IMOS_SR_H264_MJPEG)
        4��MEPG4(#IMOS_SR_MPEG4_SHARE)
        5��MEPG2(#IMOS_SR_MPEG2_SHARE)
    ��ȡֵΪ#IMOS_SR_INVALID, ���Ƿ�ֵ, ��˵����֧�ֵĲ�ѯ: ��������ѱ�ɾ���������ECR HF������� */
    ULONG_32       ulDecodeSet;

    /* ������,0Ϊ��Чֵ */
    ULONG_32      ulScreenIndex;


}MONITORLIVE_ACTION_S;

/**
 * @struct tagMonitorLiveActionForECR
 * @brief ����ʵ����������
 * @attention
 */
typedef struct tagMonitorLiveActionForECR
{

    /** ������������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** �������������� */
    CHAR        szSrcCode[IMOS_RES_CODE_LEN];

    /** �������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szSrcName[IMOS_NAME_LEN];

}MONITORLIVE_ACTION_FOR_ECR_S;

/**
 * @struct tagGISAction
 * @brief ������ͼ��˸
 * @attention
 */
typedef struct tagGISAction
{
    /** ��˸ʹ�ܱ��, BOOL_TRUEΪʹ��; BOOL_FALSEΪ��ʹ�� */
    BOOL_T  bIsEnabled;

}GIS_ACTION_S;


/**
 * @struct tagSwitchOUTAction
 * @brief �������������
 * @attention
 */
typedef struct tagSwitchOUTAction
{

    /** �豸���� */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szDevName[IMOS_NAME_LEN];
}SWITCHOUT_ACTION_S;


/**
 * @struct tagBackupAction
 * @brief ��������
 * @attention
 */
typedef struct tagBackupAction
{

    /** ��������� */
    CHAR        szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ��������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */
    CHAR        szCamName[IMOS_NAME_LEN];
}BACKUP_ACTION_S;

/**
* @struct tagReceiverAction
* @brief ���������ʼ�
* @attention ��
*/
typedef struct tagReceiverAction
{
    /** ������ʵ����Ŀ */
    ULONG_32 ulReceiverNum;

    /** ��������Ϣ(����ʱ�û�������Ч��������Ч����ѯʱ�û���¼ID���û���¼��ַ���û���½ʱ�䡢�û��Ƿ�������Ч��������Ч) */
    USER_QUERY_ITEM_S astReceiver[IMOS_ALARM_ACTION_RECEIVER_MAXNUM];

    /** �ʼ����⣨���ŵĻ����ֶ���Ч�� */
    CHAR        szTitle[IMOS_NAME_LEN];

    /** ���� */
    CHAR        szContent[IMOS_DESC_LEN];

}RECEIVER_ACTION_S;

/**
 * @struct tagBuzzerAction
 * @brief �����������澯
 * @attention
 */
typedef struct tagBuzzerAction
{

    /** �����������豸���� */
    CHAR        szDevCode[IMOS_CODE_LEN];

    /** ������������ Ԥ��������չ:����ʱ����Ƶ�ʵ� */
    CHAR        szParam[IMOS_STRING_LEN_64];
}BUZZER_ACTION_S;

/* Begin added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */
/**
* @struct tagVocTalkAction
* @brief �����������Խ�����
* @attention
*/
typedef struct tagVocTalkAction
{
    /* ��������� */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /* ��������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿ� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /* �û����� */
    CHAR    szUserCode[IMOS_CODE_LEN];

    /** �û����ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿ�*/
    CHAR    szUserName[IMOS_NAME_LEN];
}VOCTALK_ACTION_S;
/* End added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */

/**
* @struct tagActionPlanBaseInfo
* @brief Ԥ��������Ϣ
* @attention
*/
typedef struct tagActionPlanBaseInfo
{
    /** Ԥ������ */
    CHAR szActionPlanCode[IMOS_CODE_LEN];

    /** Ԥ������ */
    CHAR szActionPlanName[IMOS_NAME_LEN];

    /** Ԥ������ */
    CHAR szActionPlanDesc[IMOS_DESC_LEN];

    /** Ԥ�����ͣ�ȡֵΪ#ACTION_PLAN_TYPE_E */
    ULONG_32 ulActionPlanType;
}ACTION_PLAN_BASE_INFO_S;

/**
 * @struct tagAlarmAction
 * @brief �澯��������
 * @attention
 */
typedef struct tagAlarmAction
{

    /** �洢���������д洢������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_STORE_ACTION_MAXNUM */
    ULONG_32                       ulStoreActionNum;

    /** �洢�������� */
    STORE_ACTION_S          astStoreAction[IMOS_ALARM_STORE_ACTION_MAXNUM];

    /** Ԥ��λ����������Ԥ��λ������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_PRESET_ACTION_MAXNUM */
    ULONG_32                       ulPresetActionNum;

    /** Ԥ��λ�������� */
    PRESET_ACTION_S         astPresetAction[IMOS_ALARM_PRESET_ACTION_MAXNUM];

    /** ����ʵ��������������������ʵ������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM */
    ULONG_32                       ulScreenLiveActionNum;

    /** ����ʵ�������������� */
    SCREENLIVE_ACTION_S     astScreenLiveAction[IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM];

    /** ����ʵ������������������������ʵ����������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM */
    ULONG_32                       ulMonitorLiveActionNum;

    /** ����ʵ������������������ */
    MONITORLIVE_ACTION_S    astMonitorLiveAction[IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM];

    /** ������ͼ��˸����������������ͼ��˸������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_GIS_ACTION_MAXNUM */
    ULONG_32                       ulGISActionNum;

    /** ������ͼ��˸�������� */
    GIS_ACTION_S            astGISAction[IMOS_ALARM_GIS_ACTION_MAXNUM];

    /** ������������������������������������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM */
    ULONG_32                       ulSwitchOUTActionNum;

    /** ��������������������� */
    SWITCHOUT_ACTION_S      astSwitchOUTAction[IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM];

    /** �������ݶ����������������ݶ�����ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_BACKUP_ACTION_MAXNUM */
    ULONG_32                       ulBackupActionNum;

    /** �������ݶ������� */
    BACKUP_ACTION_S         astBackupAction[IMOS_ALARM_BACKUP_ACTION_MAXNUM];

    /** ���� */
    RECEIVER_ACTION_S        stReceiverSMSAction;

    /** �ʼ� */
    RECEIVER_ACTION_S        stReceiverEmailAction;

    /** ������Ԥ��ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_ACTION_PLAN_MAXNUM */
    ULONG_32 ulActionPlanBaseNum;

    /** Ԥ����Ϣ */
    ACTION_PLAN_BASE_INFO_S  astActionPlanBaseInfo[IMOS_ALARM_ACTION_PLAN_MAXNUM];

    /** ������洢���������д洢������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM */
    ULONG_32                    ulCenterStoreActionNum;

    /** ������洢�������� */
    STORE_ACTION_S           astCenterStoreAction[IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM];

    /* Begin added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */
    /** �����Խ�������Ŀ */
    ULONG_32                   ulVocTalkActionNum;

    /** �����Խ����� */
    VOCTALK_ACTION_S        astVocTalkAction[IMOS_ALARM_VOCTALK_ACTION_MAXNUM];
    /* End added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */

}ALARM_ACTION_S;

/**
 * @struct tagAlarmActionForECR
 * @brief �澯��������(for ECR&NVR buzzer)
 * @attention
 */
typedef struct tagAlarmActionForECR
{

    /** �洢���������д洢������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_STORE_ACTION_MAXNUM */
    ULONG_32                       ulStoreActionNum;

    /** �洢�������� */
    STORE_ACTION_S          astStoreAction[IMOS_ALARM_STORE_ACTION_MAXNUM];

    /** Ԥ��λ����������Ԥ��λ������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_PRESET_ACTION_MAXNUM */
    ULONG_32                       ulPresetActionNum;

    /** Ԥ��λ�������� */
    PRESET_ACTION_S         astPresetAction[IMOS_ALARM_PRESET_ACTION_MAXNUM];

    /** ����ʵ��������������������ʵ������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM */
    ULONG_32                       ulScreenLiveActionNum;

    /** ����ʵ�������������� */
    SCREENLIVE_ACTION_FOR_ECR_S     astScreenLiveAction[IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM];

    /** ����ʵ������������������������ʵ����������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM */
    ULONG_32                       ulMonitorLiveActionNum;

    /** ����ʵ������������������ */
    MONITORLIVE_ACTION_FOR_ECR_S    astMonitorLiveAction[IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM];

    /** ������ͼ��˸����������������ͼ��˸������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_GIS_ACTION_MAXNUM */
    ULONG_32                       ulGISActionNum;

    /** ������ͼ��˸�������� */
    GIS_ACTION_S            astGISAction[IMOS_ALARM_GIS_ACTION_MAXNUM];

    /** ������������������������������������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM */
    ULONG_32                       ulSwitchOUTActionNum;

    /** ��������������������� */
    SWITCHOUT_ACTION_S      astSwitchOUTAction[IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM];

    /** �������ݶ����������������ݶ�����ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_BACKUP_ACTION_MAXNUM */
    ULONG_32                       ulBackupActionNum;

    /** �������ݶ������� */
    BACKUP_ACTION_S         astBackupAction[IMOS_ALARM_BACKUP_ACTION_MAXNUM];

	/** �����������澯������Ŀ */
    ULONG_32                   ulBuzzerActionNum;

    /** �����������澯�����б� */
    BUZZER_ACTION_S      	astBuzzerAction[IMOS_ALARM_BUZZER_ACTION_MAXNUM];

}ALARM_ACTION_FOR_ECR_S;



/**
 * @struct tagAlarmLinkageInfo
 * @brief �澯������Ϣ�ṹ��
 * @attention
 */
typedef struct tagAlarmLinkageInfo
{

    /** �澯Դ�ı��� */
    CHAR                    szAlarmSrcCode[IMOS_RES_CODE_LEN];


    /** �澯���� */
    ULONG_32                   ulAlarmType;

    /** �澯Դ��Ӧ�澯�����������Ķ��� */
    ALARM_ACTION_S      stAction;

}ALARM_LIKNAGE_INFO_S;

/**
* @struct tagAlarmEventQueryCondition
* @brief �澯�¼���ѯ����
*/
typedef struct tagAlarmEventQueryCondition
{
    /** ���������*/
    CHAR                szCamCode[IMOS_CODE_LEN];

    /** ��������ʼ/����ʱ�� */
    TIME_SLICE_S    stQueryTimeSlice;

    /** �����ֶ� */
    CHAR szReserve[64];
}ALARM_EVENT_QUERY_CONDITION_S;


/**
* @struct tagAlarmEventInfo
* @brief �澯�¼���Ϣ(��ѯ�澯�¼���Ϣ�б�ʱ����)
*/
typedef struct tagAlarmEventInfo
{
    /** �澯���� */
    ULONG_32 ulAlarmType;

    /** �澯Դ���� */
    CHAR szAlarmSrcName[IMOS_NAME_LEN];

    /** �澯����ʱ��, ����"%Y-%m-%d %H:%M:%S"��ʽ, �����޶�Ϊ24�ַ� */
    CHAR szAlarmTime[IMOS_TIME_LEN];

    /** �洢������������� */
    CHAR szCameraCode[IMOS_CODE_LEN];

}ALARM_EVENT_INFO_S;



/*******************************************************************************
�����ƻ� GuardPlan , Edited By sunyifan(06966) Completed
********************************************************************************/
/**
 * @struct tagGuardStratageBasicInfo
 * @brief �������Ի�����Ϣ
 * @attention
 */
typedef struct tagGuardStratageBasicInfo
{

    /** ������������ */
    CHAR        szPolicyName[IMOS_NAME_LEN];

    /** �ƻ��������� */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** �Ƿ�ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** ������ѭ�����߰�����ѭ��, ȡֵΪ#MM_JOBSCHDTYPE_E */
    ULONG_32       ulCycleType;

    /** ����������֯���� */
    CHAR    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �ƻ�����, �ɲ��� */
    CHAR        szPlanDesc[IMOS_DESC_LEN];

}GUARD_STRATAGE_BASIC_INFO_S;


/**
 * @struct tagGuardPlanInfo
 * @brief �����ƻ���Ϣ
 * @attention
 */
typedef struct tagGuardPlanInfo
{
    /** �������Ի�����Ϣ */
    GUARD_STRATAGE_BASIC_INFO_S stGuardStratageBasicInfo;

    /** �����ƻ�ʱ����Ϣ */
    PLAN_TIME_S     stGuardTimeInfo;

}GUARD_PLAN_INFO_S;

/**
 * @struct tagGuardPlanQueryItem
 * @brief �������Լƻ���Ϣ��(��ѯ�������Լƻ��б�ʱ����)
 * @attention
 */
typedef struct tagGuardPlanQueryItem
{

    /** �澯Դ���� */
    CHAR            szAlarmSrcName[IMOS_NAME_LEN];

    /** �澯����, ȡֵΪ#AlARM_TYPE_E */
    ULONG_32           ulAlarmType;

    /** �澯Դ������֯���� */
    CHAR            szOrgName[IMOS_NAME_LEN];

    /** �����ƻ����� */
    CHAR        szPlanName[IMOS_NAME_LEN];

    /** �����ƻ��������� */
    CHAR            szCreatTime[IMOS_TIME_LEN];

    /** �����ƻ�״̬, 1Ϊ�ƻ��Ѿ�����; 0Ϊ�ƻ�δ���� */
    ULONG_32           ulPlanStatus;

    /** �����ƻ����� */
    CHAR            szGuardPlanCode[IMOS_RES_CODE_LEN];

}GUARD_PLAN_QUERY_ITEM_S;


/***************************************************************************
GIS
****************************************************************************/

/**
 * @struct tagFileGISInfo
 * @brief GISͼƬ��Ϣ
 * @attention
 */
typedef struct tagFileGISInfo
{
    /** ��ͼ����(����ͼ�ļ���չ��)ȡֵ�μ�#MAP_TYPE_E */
    ULONG_32                   ulGISMapType;

    /** ��ͼ������֯���� */
    CHAR                    szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** GIS�ļ�������Ϣ */
    FILE_BASIC_INFO_S   stFileBasicInfo;
}FILE_GIS_INFO_S;



/**
 * @struct tagGISQueryItem
 * @brief GISͼƬ��Ϣ��(���ڲ�ѯʱ����)
 * @attention
 */
typedef struct tagGISQueryItem
{
    /** ��ͼ���� */
    CHAR        szGISMapCode[IMOS_RES_CODE_LEN];

    /** ��ͼ����, Ϊ���ӵ�ͼʱ�û�ָ�������� */
    CHAR        szName[IMOS_NAME_LEN];

    /** GIS��ͼ������֯���� */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

}GIS_QUERY_ITEM_S;


/**
 * @struct tagGisHotZone
 * @brief GIS������Ϣ
 * @attention
 */
typedef struct tagGisHotZone
{
    /** �������� */
    CHAR        szHotZoneName[IMOS_NAME_LEN];

    /** �������ӵĵ�ͼ���� */
    CHAR        szGISMapCode[IMOS_RES_CODE_LEN];

    /** ����ͼ�α߽��ַ�����֧�ֵ�Ͷ���� */
    CHAR        szBorderline[IMOS_POLYGON_GEO_LEN];

    /** ��������, �ɲ��� */
    CHAR        szHotZoneDesc[IMOS_DESC_LEN];

}GIS_HOTZONE_S;

/**
 * @struct tagGisHotZoneWithCode
 * @brief �������������GIS����ͼ����Ϣ(���ڲ�ѯʱ����)
 * @attention
 */
typedef struct tagGisHotZoneWithCode
{
    /** �������� */
    CHAR            szHotZoneCode[IMOS_RES_CODE_LEN];

    /** ����������Ϣ */
    GIS_HOTZONE_S   stHotZoneInfo;

}GIS_HOTZONE_WITH_CODE_S;

/**
 * @struct tagGisHotSPOT
 * @brief GIS�ȵ���Ϣ
 * @attention
 */
typedef struct tagGisHotSPOT
{
    /** �ȵ����ӵ�����֯���� */
    CHAR            szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �ȵ�λ����Ϣ����, ���Բ��� */
    CHAR            szSiteDesc[IMOS_POINT_GEO_LEN];

}GIS_HOTSPOT_S;

/**
 * @struct tagGisHotSpotWithCode
 * @brief �����ȵ�����GIS�ȵ�ͼ��(���ڲ�ѯʱ����)
 * @attention
 */
typedef struct tagGisHotSpotWithCode
{
    /** �ȵ���� */
    CHAR            szHotSpotCode[IMOS_RES_CODE_LEN];

    /** �ȵ����ӵ�����֯���� */
    CHAR            szOrgName[IMOS_NAME_LEN];

    /** �ȵ�������Ϣ */
    GIS_HOTSPOT_S   stHotSpotInfo;

}GIS_HOTSPOT_WITH_CODE_S;

/**
 * @struct tagGisTextbox
 * @brief GIS�ı���
 * @attention
 */
typedef struct tagGisTextbox
{
    /** �ı���Ϣ */
    CHAR    szTextInfo[IMOS_DESC_LEN];

    /** �ı���λ����Ϣ���� */
    CHAR    szSiteDesc[IMOS_POINT_GEO_LEN];

    /** ��������, �����ȡֵ��ʹ��������� */
    ULONG_32   ulTextType;

    /** ���ִ�С, �����ȡֵ��ʹ��������� */
    ULONG_32   ulTextSize;

    /** ������ɫ, �����ȡֵ��ʹ��������� */
    ULONG_32   ulTextColor;

    /** �����Ƿ�Ӵ�, 1Ϊ�Ӵ�; 0Ϊ���Ӵ� */
    ULONG_32   ulBoldFlag;

}GIS_TEXTBOX_S;


/**
 * @struct tagGisTextBoxWithCode
 * @brief �������ı�������GIS�ı�����Ϣ
 * @attention
 */
typedef struct tagGisTextBoxWithCode
{
    /** �ı������ */
    CHAR            szTextBoxCode[IMOS_RES_CODE_LEN];

    /** �ı���������Ϣ */
    GIS_TEXTBOX_S   stTextBoxInfo;

}GIS_TEXTBOX_WITH_CODE_S;


/**
 * @struct tagGisCamIcon
 * @brief GIS�����ͼ����Ϣ
 * @attention
 */
typedef struct tagGisCamIcon
{
    /** ��������� */
    CHAR        szCamCode[IMOS_DEVICE_CODE_LEN];

    /** �����ͼ��λ����Ϣ����, �ɲ��� */
    CHAR        szSiteDesc[IMOS_POINT_GEO_LEN];

}GIS_CAM_ICON_S;


/**
 * @struct tagGisCamIconWithCode
 * @brief ������ͼ������GIS�����ͼ����Ϣ
 * @attention
 */
typedef struct tagGisCamIconWithCode
{
    /** �����ͼ����� */
    CHAR            szCamIconCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR            szCamName[IMOS_NAME_LEN];

    /** �������״̬, ȡֵΪ#AS_CAMERA_STATUS_E */
    ULONG_32           ulCamState;

    /** ������Ķ���״̬, ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32           ulCamExtState;

    /** ������ĸ澯���س̶�, ȡֵΪ#ALARM_SEVERITY_LEVEL_E */
    ULONG_32           ulCamAlarmLevel;

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32           ulCameraType;

    /** ������Ƿ���������: 1 ��,0 �� */
    ULONG_32           ulIsForeign;

    /** �����ͼ��������Ϣ */
    GIS_CAM_ICON_S  stCamIconInfo;

    /** ������������豸������,ȡֵΪ#IMOS_TYPE_E */
    ULONG_32 ulParentType;

}GIS_CAM_ICON_WITH_CODE_S;


/**
 * @struct tagGisAlarmSrcIcon
 * @brief GIS�澯Դͼ����Ϣ
 * @attention
 */
typedef struct tagGisAlarmSrcIcon
{
    /** �澯Դ���� */
    CHAR        szAlarmSrcCode[IMOS_DEVICE_CODE_LEN];

    /** �澯Դͼ��λ����Ϣ����, �ɲ��� */
    CHAR        szSiteDesc[IMOS_POINT_GEO_LEN];



}GIS_ALARM_SRC_ICON_S;


/**
 * @struct tagGisAlarmSrcIconWithCode
 * @brief �����澯Դͼ������GIS�澯Դͼ����Ϣ
 * @attention
 */
typedef struct tagGisAlarmSrcIconWithCode
{
    /** �澯Դͼ����� */
    CHAR                    szAlarmSrcIconCode[IMOS_RES_CODE_LEN];

    /** �澯Դ���� */
    CHAR                    szAlarmSrcName[IMOS_NAME_LEN];

    /** �澯���س̶�, ȡֵΪ#ALARM_SEVERITY_LEVEL_E */
    ULONG_32                   ulAlarmLevel;

    /** �澯Դͼ��������Ϣ */
    GIS_ALARM_SRC_ICON_S    stAlarmSrcIconInfo;

}GIS_ALARM_SRC_ICON_WITH_CODE_S;


/**
 * @struct tagGisAlarmDstIcon
 * @brief GIS�澯���ͼ����Ϣ
 * @attention
 */
typedef struct tagGisAlarmDstIcon
{
    /** �澯������� */
    CHAR        szAlarmDstCode[IMOS_DEVICE_CODE_LEN];

    /** �澯���ͼ��λ����Ϣ����, �ɲ��� */
    CHAR        szSiteDesc[ IMOS_POINT_GEO_LEN];

}GIS_ALARM_DST_ICON_S;


/**
 * @struct tagGisAlarmDstIconWithCode
 * @brief �����澯���ͼ������GIS�澯���ͼ����Ϣ
 * @attention
 */
typedef struct tagGisAlarmDstIconWithCode
{
    /** �澯���ͼ����� */
    CHAR                    szAlarmDstIconCode[IMOS_RES_CODE_LEN];

    /** �澯������� */
    CHAR                    szAlarmDstName[IMOS_NAME_LEN];

    /** �澯���ͼ��������Ϣ */
    GIS_ALARM_DST_ICON_S    stAlarmDstIconInfo;

}GIS_ALARM_DST_ICON_WITH_CODE_S;


/***************************************************************************************************
͸��ͨ��
****************************************************************************************************/
/**
 * @struct tagTransparentChannel
 * @brief ͸��ͨ��������Ϣ
 * @attention
 */
typedef struct tagTransparentChannel
{
    /** ͸��ͨ������ */
    CHAR        szTransChnlName[IMOS_NAME_LEN];

    /** ͸��ͨ�����ͣ����ɸ���,ȡֵΪ#TL_CHANNEL_MODE_E */
    ULONG_32       ulTransChnlType;

    /** ͸��ͨ�����ݳ��ط�ʽ(UDP/TCP/SIP) **/
    ULONG_32       ulDataTransType;

}TRANSPARENT_CHANNEL_S;

/**
 * @struct tagTransparentSerial
 * @brief ͸��ͨ��������Ϣ
 * @attention
 */
typedef struct tagTransparentSerial
{

    /** �豸���� */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** �豸����, ȡֵΪ#IMOS_TYPE_EC��#IMOS_TYPE_DC */
    ULONG_32       ulDevType;

    /** ��������, ȡֵ��1��ʼ, ���ֵΪ#IMOS_TRANSPARENT_SERIAL_NUM */
    ULONG_32       ulSerialIndex;

}TRANSPARENT_SERIAL_S;

/**
 * @struct tagTransparentIP
 * @brief ͸��ͨ����IP��ַ��Ϣ
 * @attention
 */
typedef struct tagTransparentIP
{
    /** ͨ��������(������),�ɸ��� */
    CHAR szChannelDesc[IMOS_DESC_LEN];

    /** IP��ַ */
    CHAR szTCIPAddress[IMOS_IPADDR_LEN];

    /** ͸��ͨ���˿ں� */
    ULONG_32 ulTCPort;
}TRANSPARENT_IP_S;



/**
 * @struct tagTransparentInfo
 * @brief ͸��ͨ����Ϣ
 * @attention
 */
typedef struct tagTransparentInfo
{
    /** ͸��ͨ��������Ϣ */
    TRANSPARENT_CHANNEL_S   stTransparentChannel;

    /** ͸��ͨ�����������д��ڵ�ʵ����Ŀ, ���ȡֵΪ#IMOS_TRANSPARENT_SERIAL_NUM */
    ULONG_32                   ulSerialNum;

    /** ͸��ͨ���������� */
    TRANSPARENT_SERIAL_S    astTransparentSerial[IMOS_TRANSPARENT_SERIAL_NUM];

    /** ͸��ͨ����IP��ַ��Ϣ������IP��ַ��Ϣ��ʵ����Ŀ, ���ȡֵΪ#IMOS_TRANSPARENT_IP_NUM */
    ULONG_32                   ulIPNum;

    /** ͸��ͨ����IP��ַ��Ϣ���� */
    TRANSPARENT_IP_S        astTransparentIP[IMOS_TRANSPARENT_IP_NUM];

}TRANSPARENT_INFO_S;


/**
 * @struct tagTransparentQueryItem
 * @brief ͸��ͨ����Ϣ��(��ѯ͸��ͨ���б�ʱ����)
 * @attention
 */
typedef struct tagTransparentQueryItem
{
    /** ͸��ͨ������ */
    CHAR                    szTransChnlCode[IMOS_RES_CODE_LEN];

    /** ʹ��״̬, ȡֵΪ#TL_TRANS_CHANNEL_STATUS_E */
    ULONG_32                   ulEnabledFlag;

    /** ͸��ͨ����Ϣ */
    TRANSPARENT_INFO_S  stTransparentInfo;

}TRANSPARENT_QUERY_ITEM_S;




/***************************************************************************************************
��̨����
****************************************************************************************************/
/**
 * @struct tagPTZCtrlCommand
 * @brief ��̨����ָ��
 * @attention
 */
typedef struct  tagPTZCtrlCommand
{
    /** ��̨������������, ȡֵΪ#MW_PTZ_CMD_E */
    ULONG_32    ulPTZCmdID ;

    /** ��������Ĳ���ֵ1, ���ò�������Ϊ��̨ת��ʱȡֵ���ܳ���#MAX_PTZ_SPEED */
    ULONG_32   ulPTZCmdPara1;

    /** ��������Ĳ���ֵ2, ���ò�������Ϊ��̨ת��ʱȡֵ���ܳ���#MAX_PTZ_SPEED */
    ULONG_32   ulPTZCmdPara2;

    /** ��������Ĳ���ֵ3,�����ֶ� */
    ULONG_32   ulPTZCmdPara3;

}PTZ_CTRL_COMMAND_S;



/**************************************************************************************************************
�����ط� Record Retrieval, Edited by sunyifan (06966) 13.Mar.2009 Complete
************************************************************************************************************/

/**
* @struct tagRecQueryInfo
* @brief �ط���ؼ�����Ϣ���ݽṹ
*/
typedef struct tagRecQueryInfo
{
    /** ����ͷ���� */
    CHAR                szCamCode[IMOS_RES_CODE_LEN];

    /** ��������ʼ/����ʱ�� */
    TIME_SLICE_S        stQueryTimeSlice;

    /* ¼����򼶱����: ���ڹ���Э�����ط� */
    ULONG_32               ulDomainLevel;

    /* Begin add by zhengyibing(01306), 2014-04-19 for �¹����޶�*/
    /* ����ģ����ѯ����  #INDISTINCT_QUERY_TYPE_E */
    ULONG_32                ulIndistinctQuery;

    /* ����¼���������  #RECORD_QUERY_TYPE_E */
    ULONG_32                ulType;
    /* End add by zhengyibing(01306), 2014-04-19 for �¹����޶�*/

    /** �����ֶ� */
    CHAR szReserve[20];
}REC_QUERY_INFO_S;


/**
* @struct tagRecordFileInfo
* @brief ¼���ļ���Ϣ(��ѯ¼���ļ��б�ʱ����)
*/
typedef struct tagRecordFileInfo
{
    /** �ļ��� */
    CHAR szFileName[IMOS_FILE_NAME_LEN];

    /** �ļ���ʼʱ��, ����"%Y-%m-%d %H:%M:%S"��ʽ, �����޶�Ϊ24�ַ� */
    CHAR szStartTime[IMOS_TIME_LEN];

    /** �ļ�����ʱ��, ����"%Y-%m-%d %H:%M:%S"��ʽ, �����޶�Ϊ24�ַ� */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** �ļ���С, Ŀǰ�ݲ�ʹ�� */
    ULONG_32 ulSize;

    /** ������Ϣ, �ɲ��� */
    CHAR szSpec[IMOS_DESC_LEN];

}RECORD_FILE_INFO_S;

/**
* @struct tagRecordFileInfoV2
* @brief ¼���ļ���Ϣ(��ѯ¼���ļ��б�ʱ����)(V2)
*/
typedef struct tagRecordFileInfoV2
{
    /** �ļ��� */
    CHAR szFileName[IMOS_FILE_NAME_LEN_V2];

    /** �ļ���ʼʱ��, ����"%Y-%m-%d %H:%M:%S"��ʽ, �����޶�Ϊ24�ַ� */
    CHAR szStartTime[IMOS_TIME_LEN];

    /** �ļ�����ʱ��, ����"%Y-%m-%d %H:%M:%S"��ʽ, �����޶�Ϊ24�ַ� */
    CHAR szEndTime[IMOS_TIME_LEN];

    /** �ļ���С, Ŀǰ�ݲ�ʹ�� */
    ULONG_32 ulSize;

    /** ������Ϣ, �ɲ��� */
    CHAR szSpec[IMOS_DESC_LEN];
}RECORD_FILE_INFO_V2_S;

/**
 * @struct tagUnitedRecFileInfo
 * @brief  ¼�����Ϣ�ṹ
 * @attention
 */
typedef struct tagUnitedRecFileInfo
{
    /** �ļ��� */
    CHAR  szFileName[IMOS_FILE_NAME_LEN_V2];

    /** �ļ���ʼʱ��*/
    CHAR  szStartTime[IMOS_TIME_LEN];

    /** �ļ�����ʱ�� */
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** �ļ���С, Ŀǰ�ݲ�ʹ�� */
    ULONG_32 ulSize;

    /** �򼶱����������¼��Ϊ0���ͼ���¼��������ۼ� */
    ULONG_32 ulDomainLevel;

    /** ������Ϣ, �ɲ��� */
    CHAR  szSpec[IMOS_DESC_LEN];

    /* Ԥ���ֶ� */
    CHAR  szReserved[128];
}UNITED_REC_FILE_INFO_S;

/**
* @struct tagGetUrlInfo
* @brief ��ȡ¼���ļ�URL������ṹ
*/
typedef struct tagGetUrlInfo
{
    /** ��������� */
    CHAR            szCamCode[IMOS_RES_CODE_LEN];

    /** ¼���ļ��� */
    CHAR            szFileName[IMOS_FILE_NAME_LEN];

    /** ¼�����ʼ/����ʱ��, ���е�ʱ���ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stRecTimeSlice;

    /** �ͻ���IP��ַ */
    CHAR            szClientIp[IMOS_IPADDR_LEN];

}GET_URL_INFO_S;

/**
* @struct tagGetUrlInfoV2
* @brief ��ȡ¼���ļ�URL������ṹ(V2)
*/
typedef struct tagGetUrlInfoV2
{
    /** ��������� */
    CHAR            szCamCode[IMOS_RES_CODE_LEN];

    /** ¼���ļ��� */
    CHAR            szFileName[IMOS_FILE_NAME_LEN_V2];

    /** ¼�����ʼ/����ʱ��, ���е�ʱ���ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stRecTimeSlice;

    /** �ͻ���IP��ַ */
    CHAR            szClientIp[IMOS_IPADDR_LEN];

}GET_URL_INFO_V2_S;

/**
* @struct tagGetUrlInfoV3
* @brief ��ȡ¼���ļ�URL������ṹ(V3)
*/
typedef struct tagGetUrlInfoV3
{
    /** ��ȡ¼���ļ�URL����V2 */
    GET_URL_INFO_V2_S stGetUrlInfo;

    /** �ط��м̲���#IMOS_VOD_STREAM_SERVER_MODE_E */
    ULONG_32 ulPlaybackAutofit;

    /** �����ֶ� */
    CHAR   szReserve[128];

}GET_URL_INFO_V3_S;

/**
* @struct tagUnitedGetUrlInfo
* @brief ��ȡ��¼��URL������ṹ
*/
typedef struct tagUnitedGetUrlInfo
{
    /** ��������� */
    CHAR szCamCode[IMOS_CODE_LEN];

    /** ¼���ļ��� */
    CHAR szFileName[IMOS_FILE_NAME_LEN_V2];

    /** ¼�����ʼ/����ʱ��, ���е�ʱ���ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S stRecTimeSlice;

    /** �ͻ���IP��ַ */
    CHAR szClientIp[IMOS_IPADDR_LEN];

    /** �ط��м̲���#IMOS_VOD_STREAM_SERVER_MODE_E */
    ULONG_32 ulPlaybackAutofit;

    /** �򼶱����: 0xFFFFΪ��Ч���򼶱���� */
    ULONG_32 ulDomainLevel;

    /** ����ҵ�����ͣ�ȡֵ#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32           ulBakSrvType;

    /** ����¼����룬����ҵ������Ϊ��������ʱ��Ч */
    CHAR            szCaseRecCode[IMOS_CODE_LEN];

    /** �����ֶ� */
    CHAR   szReserve[76];
}UNITED_GET_URL_INFO_S;

/**
* @struct tagAddTagInfo
* @brief ¼���ǩ��Ϣ
*/
typedef struct tagAddTagInfo
{

    /** ��������� */
    CHAR                szCamCode[IMOS_RES_CODE_LEN];

    /** ��ǩ��ʱ���, ���еĿ�ʼʱ��ͽ���ʱ��ĸ�ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stTagTime;

    /** ��ǩ���� */
    CHAR                szTag[IMOS_RECORD_LABEL_LEN];

}ADD_TAG_INFO_S;


/**
* @struct tagTagQueryCondition
* @brief ��ǩ��������
*/
typedef struct tagTagQueryCondition
{
    /** ��������� */
    CHAR                szCamCode[IMOS_RES_CODE_LEN];

    /** ��������ʼ/����ʱ��, ʱ���ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S        stQueryTimeSlice;

    /** ��ѯ�����Ƿ������ǩ����, BOOL_TRUEΪ������ǩ����; BOOL_FALSEΪ��������ǩ���� */
    BOOL_T  bUseTag;

    /** ��ǩ���� */
    CHAR                szTag[IMOS_RECORD_LABEL_LEN];

}TAG_QUERY_CONDITION_S;


/**
* @struct tagTagQueryItem
* @brief ��ǩ��ѯ��Ϣ�б�Ԫ��Ϣ
*/
typedef struct tagTagQueryItem
{
    /** ��ǩ���� */
    CHAR            szTagCode[IMOS_RES_CODE_LEN];

    /** ��ǩʱ��� */
    CHAR            szTagTime[IMOS_TIME_LEN];

    /** ��ǩ�ַ���*/
    CHAR            szTag[IMOS_RECORD_LABEL_LEN];

}TAG_QUERY_ITEM_S;

/**
* @struct tagVODSeverIpAddr
* @brief �㲥��������IP��ַ�Ͷ˿�
*/
typedef struct tagVODSeverIpAddr
{
    /** RTSP������IP��ַ */
    CHAR   szServerIp[IMOS_IPADDR_LEN];

    /** RTSP�������˿� */
    USHORT  usServerPort;

    /** ����λ, �����ֽڶ���, ��ʵ�ʺ��� */
    CHAR    acReserved[2];
}VOD_SEVER_IPADDR_S;


/**
* @struct tagURLInfo
* @brief URL��Ϣ���ݽṹ
*/
typedef struct tagURLInfo
{
    /** URL��ַ*/
    CHAR                        szURL[IMOS_IE_URL_LEN];

    /** �㲥��������IP��ַ�Ͷ˿� */
    VOD_SEVER_IPADDR_S      stVodSeverIP;

    /** ���������� */
    CHAR szDecoderTag[IMOS_STRING_LEN_64];

}URL_INFO_S;



/***************************************************************************
CSҵ��
****************************************************************************/

/**
 * @struct tagMonitorUnit
 * @brief ʵʱ��ؼ�¼
 * @attention
 */
typedef struct tagMonitorUnit
{
    /** ��ع�ϵ�����Ķ���ҵ������: ʵʱ ���� �ƻ�����, ȡֵΪ#SRV_TYPE_E */
    ULONG_32 ulTopSrvType;

    /** ���������� */
    CHAR  szMonitorCode[IMOS_RES_CODE_LEN];

    /** ����������#IMOS_TYPE_XP_WIN������, #IMOS_TYPE_MONITOR��������� */
    ULONG_32 ulMonitorType;

    /** ����������, ��ΪXP����ʱ, �ṩ������� */
    CHAR  szMonitorName[IMOS_NAME_LEN];

    /** ��������������� */
    CHAR  szMonitorDomain[IMOS_DOMAIN_CODE_LEN];

    /** ��������� */
    CHAR  szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** ����������� */
    CHAR  szCameraDomain[IMOS_DOMAIN_CODE_LEN];

    /** �û����� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û���¼IP��ַ */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

    /** ��ع�ϵ״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulSrvState;
}MONITOR_UNIT_S;

/**
 * @struct tagMonitorRec
 * @brief ʵʱ��ؼ�¼
 * @attention
 */
typedef struct tagMonitorRec
{
    /** ���������� */
    CHAR  szMonitorCode[IMOS_RES_CODE_LEN];

    /** ����������, ��ΪXP����ʱ, �ṩ������� */
    CHAR  szMonitorName[IMOS_NAME_LEN];

    /** ��������������� */
    CHAR  szMonitorDomain[IMOS_DOMAIN_CODE_LEN];

    /** ��������� */
    CHAR  szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** ����������� */
    CHAR  szCameraDomain[IMOS_DOMAIN_CODE_LEN];

    /** �û����� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û���¼IP��ַ */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

    /** ��ع�ϵ״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulSrvState;

    /** ������ */
    ULONG_32 ulStreamType;
}MONITOR_REC_S;

/**
 * @struct tagSrvStateInfo
 * @brief ҵ��״̬��Ϣ
 * @attention ״̬��Χ#SRV_STATE_E
 */
typedef struct tagSrvStateInfo
{
    /** ʵ��ҵ��״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulMonitorState;

    /** ����ҵ��״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulSwitchState;

    /** �ƻ�����״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulPlanSwitchState;

    /** �����Խ�״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulVocTalkState;

    /** �����㲥״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulVocBrdState;

    /* added by z06806 for vodwall prj 20101215 begin */
    /** �ط���ǽ״̬��ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulVod2TVState;
    /* added by z06806 for vodwall prj 20101215 end */
}SRV_STATE_INFO_S;

/**
 * @struct tagResSrvStateInfo
 * @brief ��Դ��ҵ��״̬��Ϣ
 * @attention ״̬��Χ#SRV_STATE_E
 */
typedef struct tagResSrvStateInfo
{
    /** ����ʾ״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulSalvoState;

    /** ����Ѳ״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulGroupsalvoState;

/* Begin Added by dengshuhua00673, 2012-12-26 of �Զ�������Ѳ */
	/** �Զ���������Ѳ״̬, ȡֵΪ#SRV_STATE_E */
    ULONG_32 ulAutosalvoState;
/* End Added by dengshuhua00673, 2012-12-26 of �Զ�������Ѳ */

}RES_SRV_STATE_INFO_S;

/**
 * @struct tagSwitchResUnit
 * @brief ������Դ��Ԫ��Ϣ
 * @attention
 */
typedef struct tagSwitchResUnit
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** ����ʱ��, ȡֵ��ΧΪ#MIN_TIME_SWITCH_INTERVAL~#MAX_TIME_SWITCH_INTERVAL */
    ULONG_32   ulSwitchTime;
}SWITCH_RES_UNIT_S;

/**
 * @struct tagSwitchResBase
 * @brief ������Դ������Ϣ
 * @attention
 */
typedef struct tagSwitchResBase
{
    /** ������Դ���� */
    CHAR    szSwitchResCode[IMOS_RES_CODE_LEN];

    /** ������Դ���� */
    CHAR       szSwitchResName[IMOS_NAME_LEN];

    /** �û����� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û���¼IP��ַ */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

}SWITCH_RES_BASE_S;

/**
 * @struct tagVocBrdUnit
 * @brief �����㲥��Ԫ��Ϣ
 * @attention
 */
typedef struct tagVocBrdUnit
{
    /** ��������� */
    CHAR        szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR        szCameraName[IMOS_NAME_LEN];

    /** �㲥״̬, ȡֵΪ#VOCBRD_STATUS_E */
    ULONG_32       ulState;
}VOC_BRD_UNIT_S;





/***************************************************************************************
��־����
��***********************************************************************************/

/**
 * @struct tagOperateLogInfo
 * @brief ������־��Ϣ
 * @attention
 */
typedef struct tagOperateLogInfo
{
    /** �������� */
    CHAR    szOperatorName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR    szTime[IMOS_TIME_LEN];

    /** ������IP��ַ */
    CHAR    szIpAddress[IMOS_IPADDR_LEN];

    /** ��������, ȡֵΪ#OPERATE_TYPE_E */
    ULONG_32   ulOperateType;

    /** �������, ȡֵΪ�ò������صĴ����� */
    ULONG_32   ulResult;

    /** �������� */
    CHAR    szOperateDesc[IMOS_STRING_LEN_512];

    /** ����ʧ��ԭ�� */
    CHAR    szCause[IMOS_STRING_LEN_128];

    /** ҵ������, ȡֵΪ#SRV_TYPE_E */
    ULONG_32   ulOperationType;

    /** �������� */
    CHAR         szOperateObject[IMOS_STRING_LEN_512];
 }OPERATE_LOG_S;


/***************************************************************************
 ���͸�UI����Ϣ���ݽṹ
****************************************************************************/

/**
* @struct tagASStaPushUI
* @brief ���͸�UI���豸״̬��Ϣ���ݽṹ
*/
typedef struct tagASStaPushUI
{
    /** ���豸���� ��IMOS_TYPE_E,��sdk_def.h�ж��� */
    ULONG_32      ulParDevType;
    /** ���豸���� */
    CHAR    szParDevCode[IMOS_DEVICE_CODE_LEN];
    /** �豸״̬ 1-#IMOS_DEV_STATUS_ONLINE��2-#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж���
                 ������豸����Ϊ"�����",���豸״̬ȡֵΪ#AS_CAMERA_STATUS_E */
    ULONG_32   ulDevSta;
    /* �Ƿ������豸 */
    BOOL_T  bHasSubDev;
    /** ���豸���� */
    ULONG_32      ulSubDevType;
    /** ���豸���� */
    CHAR    szSubDevCode[IMOS_DEVICE_CODE_LEN];
}AS_STAPUSH_UI_S;


/**
* @struct tagASAlarmPushUI
* @brief ���͸�UI�ĸ澯��Ϣ���ݽṹ
*/
typedef struct tagASAlarmPushUI
{
    /** �澯�¼����� */
    CHAR  szAlarmEventCode[IMOS_RES_CODE_LEN];
    /** �澯Դ���� */
    CHAR  szAlarmSrcCode[IMOS_DEVICE_CODE_LEN];
    /** �澯Դ���� */
    CHAR  szAlarmSrcName[IMOS_NAME_LEN];
    /** ʹ�ܺ�����*/
    CHAR  szActiveName[IMOS_NAME_LEN];
    /** �澯���� AlARM_TYPE_E ��sdk_def.h�ж��� */
    ULONG_32  ulAlarmType;
    /** �澯���� ALARM_SEVERITY_LEVEL_E ��sdk_def.h�ж��� */
    ULONG_32  ulAlarmLevel;
    /** �澯����ʱ�� */
    CHAR   szAlarmTime[IMOS_TIME_LEN];
    /** �澯������Ϣ */
    CHAR  szAlarmDesc[IMOS_DESC_LEN];
}AS_ALARMPUSH_UI_S;


/**
* @struct tagASDelExdomainPushUI
* @brief ���͸�UI������(��֯)ɾ��������ݽṹ
*/
typedef struct tagASDelExdomainPushUI
{
    /** ��ɾ����(��֯)���� */
    CHAR  szOrgCode[IMOS_CODE_LEN];

    /** ��ɾ����(��֯)���� */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** ɾ����������ش�����*/
    ULONG_32  ulDelResult;

}AS_DEL_EXDOMAIN_PUSH_UI_S;

/* added by z06806 for vodwall prj 20101203 begin */
/**
* @struct tagCSVodwallReaveNotify
* @brief SOI ʵʱ����ռ��Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSVodwallReaveNotify
{
    ULONG_32   ulDeviceType;                             /* ����ռ���豸���� */
    CHAR    szMonitorCode[IMOS_CODE_LEN];             /* ���������� */
    CHAR    szMonitorName[IMOS_NAME_LEN];             /* ���������� */
    CHAR    szXPCode[IMOS_CODE_LEN];                  /* XP���� */
    CHAR    szXPName[IMOS_NAME_LEN];                  /* XP���� */
    CHAR    szDomainCode[IMOS_CODE_LEN];              /* ��������������� */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* ���������������� */
    CHAR    szUserName[IMOS_NAME_LEN];                /* ��ռ�������û��� */
    CHAR    szUserLoginCode[IMOS_CODE_LEN];           /* ��ռ�����û���¼���� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* ��ռ�����û��ĵ�¼IP */
}CS_VODWALL_REAVE_NOTIFY_S;
/* added by z06806 for vodwall prj 20101203 end */

/**
* @struct tagASShareDevBasicInfo
* @brief ���͸�UI�Ĺ����豸������Ϣ���ݽṹ
*/
typedef struct tagASShareDevBasicInfo
{
    /** �豸���� */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR    szDevName[IMOS_NAME_LEN];

    /** �豸״̬ 1���ߣ�2���� */
    ULONG_32             ulDevStatus;

    /** �豸����״̬  DEV_EXT_STATUS_E ��sdk_def.h�ж��� */
    ULONG_32             ulDevExtStatus;

    /** �豸���ͣ�ȡֵIMOS_TYPE_E */
    ULONG_32   ulDevType;

    /** �豸�����ͣ�Ŀǰֻ�������ȡCAMERA_TYPE_E ��sdk_def.h�ж��� */
    ULONG_32   ulDevSubType;

    /** ֧�ֵ�����Ŀ��ֻ�������������Ч��0:��Чֵ��1:������2:˫�� */
    ULONG_32  ulStreamNum;              /* Added for DoubleStream */
}AS_SHAREDEV_BASIC_INFO_S;


/**
* @struct tagASDevPushUI
* @brief ���͸�UI�Ĺ����豸��Ϣ���ݽṹ
*/
typedef struct tagASDevPushUI
{
    /** �豸��������� */
    CHAR   szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸���������� */
    CHAR   szDomainName[IMOS_NAME_LEN];

    /** �������ͣ�ȡֵΪ AS_DEVSHARE_OPERATION_TYPE_E */
    ULONG_32                       ulOperType;

    /** �����豸������Ϣ */
    AS_SHAREDEV_BASIC_INFO_S    stDevContent;
}AS_DEVPUSH_UI_S;


/* Begin: Added by MultiDomain */
/**
* @struct tagASExdomainStaPushUI
* @brief ���͸�UI������״̬��Ϣ���ݽṹ
*/
typedef struct tagASExdomainStaPushUI
{
    /** ������� */
    CHAR   szDomainCode[IMOS_DOMAIN_CODE_LEN];

    /** �������� */
    CHAR   szDomainName[IMOS_NAME_LEN];

    /** ����ע��״̬��ָ�����������ע���Ƿ�ɹ� */
    ULONG_32                     ulActiveRegSta;

    /** ����ע��״̬��ָ����������ע���Ƿ�ɹ� */
    ULONG_32                     ulRecvRegSta;
}AS_EXDOMAIN_STAPUSH_UI_S;
/* End: Added by MultiDomain */


/**
* @struct tagCSMonitorReaveNotify
* @brief SOI ʵʱ����ռ��Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSMonitorReaveNotify
{
    ULONG_32   ulDeviceType;                             /* ����ռ���豸���� */
    CHAR    szMonitorCode[IMOS_DEVICE_CODE_LEN];      /* ������/XP������� */
    CHAR    szMonitorName[IMOS_NAME_LEN];             /* ������/XP�������� */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];       /* ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];              /* ��������� */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];       /* ������/XP������������� */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* ������/XP�������������� */
    CHAR    szUserName[IMOS_NAME_LEN];                /* ��ռ�������û��� */
    CHAR    szUserLoginCode[IMOS_RES_CODE_LEN];       /* ��ռ�����û���¼���� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* ��ռ�����û��ĵ�¼IP */
}CS_MONITOR_REAVE_NOTIFY_S;


/**
* @struct tagCSSwitchReaveNotify
* @brief SOI ���б���ռ��Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSSwitchReaveNotify
{
    ULONG_32   ulDeviceType;                             /* ����ռ���豸���� */
    CHAR    szMonitorCode[IMOS_DEVICE_CODE_LEN];      /* ������/XP������� */
    CHAR    szMonitorName[IMOS_NAME_LEN];             /* ������/XP�������� */
    CHAR    szSwitchResCode[IMOS_RES_CODE_LEN];       /* ������Դ���� */
    CHAR    szSwitchResName[IMOS_RES_CODE_LEN];       /* ������Դ���� */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];       /* ������/XP������������� */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* ������/XP�������������� */
    CHAR    szUserName[IMOS_NAME_LEN];                /* ��ռ�������û��� */
    CHAR    szUserLoginCode[IMOS_RES_CODE_LEN];       /* ��ռ�����û���¼���� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* ��ռ�����û��ĵ�¼IP */
}CS_SWITCH_REAVE_NOTIFY_S;

/**
* @struct tagCSVocSrvReaveNotify
* @brief SOI ����ҵ����ռ��Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSVocSrvReaveNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                /* �û��� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];         /* ��ռ�����û��ĵ�¼IP */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];       /* ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];              /* ������� */
    CHAR    szDomainCode[IMOS_DOMAIN_CODE_LEN];       /* ����� */
    CHAR    szDomainName[IMOS_NAME_LEN];              /* ���� */
    ULONG_32   ulPreSrvType;                             /* ��ռǰ�����ͣ��Խ���㲥����ö��ֵΪ:SRV_TYPE_E */
    ULONG_32   ulCurSrvType;                             /* ��ռ������ͣ��Խ���㲥����ö��ֵΪ:SRV_TYPE_E */
}CS_VOCSRV_REAVE_NOTIFY_S;


/**
* @struct tagCSPtzReaveNotify
* @brief SOI ��̨ҵ����ռ��Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSPtzReaveNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                  /* �û����� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];           /* ��ռ�����û��ĵ�¼IP */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];         /* ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];                /* ��������� */
    ULONG_32   ulNotifyType;                               /* ֪ͨ���� ��Ӧö��:PTZ_NOTIFY_UI_EVENT_TYPE */
}CS_PTZ_REAVE_NOTIFY_S;

/**
* @struct tagCSNotifyUITrbEventProc
* @brief ֪ͨUI���ϴ����¼�����
* @attention ʵ�������С�����ҵ���ͷŸ��ýṹ�����������ֻ�ṩ������ʹ��
*/
typedef struct tagCSNotifyUITrbEventProc
{
    /** XP������� */
    CHAR szXPWinCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� ����ҵ��ʹ�� */
    CHAR szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ҵ������ */
    ULONG_32 ulServiceType;

}CS_NOTIFY_UI_TRB_EVENT_PROC_S;

/**
* @struct tagCSNotifyCameraInfo
* @brief ҵ������Ϣ֪ͨ�������Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSNotifyCameraInfo
{
    /** ��������� */
    CHAR  szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** ��������� */
    ULONG_32 ulCameraType;

}CS_NOTIFY_CAMERA_INFO_S;

/**
* @struct tagCSNotifySwitchResInfo
* @brief ҵ������Ϣ֪ͨ������Դ��Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSNotifySwitchResInfo
{
    /** ������Դ���� */
    CHAR  szSwitchResCode[IMOS_RES_CODE_LEN];

    /** ������Դ���� */
    CHAR szSwitchResName[IMOS_NAME_LEN];

}CS_NOTIFY_SWITCH_RES_INFO_S;

/**
* @struct tagCSNotifyReplayActionInfo
* @brief ҵ������Ϣ֪ͨ������ǰ¼��ṹ
* @attention ��
*/
typedef struct tagCSNotifyReplayActionInfo
{
    /** �Ƿ����þ�ǰ¼��ȡֵ0����1���� */
    ULONG_32  ulIsBefAlarmReplay;

    /** ��ǰ¼��ʱ������ȡֵ��λ�� */
    ULONG_32  ulBefAlarmRepInterval;

     /** �澯ʱ�� ��ʽΪ "YYYY-MM-DD hh:mm:ss" */
    CHAR   szAlarmTime[IMOS_TIME_LEN];

    /** ������ǰ¼���XP������� */
    CHAR   szRepXPWinCode[IMOS_CODE_LEN];

}CS_NOTIFY_REPLAY_ACTION_INFO_S;


/**
* @struct tagCSNotifyScreenActionInfo
* @brief ҵ������Ϣ֪ͨ����ץ����Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSNotifyScreenActionInfo
{
    /** �Ƿ�ץ��, ȡֵΪ0��1 */
    ULONG_32    ulSnatchImage;

    /** ץ�ļ����ȡֵ��λ���� */
    ULONG_32    ulInterval;

    /** ץ������ */
    ULONG_32    ulSnatchCounter;
    /* ������ǰ¼��ṹ */
    CS_NOTIFY_REPLAY_ACTION_INFO_S  stReplayActInfo;

    /* �����ֶ� */
    CHAR     szParam[IMOS_IDLE_LEN];

}CS_NOTIFY_SCREEN_ACTION_INFO_S;


/**
* @struct tagCSNotifyUISrvSetup
* @brief ֪ͨUIҵ������ʵʱ��أ����У�
* @attention ҵ��ָ����澯�������ýṹ���豸��Ϣ�ṹ����ʵ���ָ���������Դ��Ϣ�������лָ�
*/
typedef struct tagCSNotifyUISrvSetup
{
    /** XP������� */
    CHAR                        szXPWinCode[IMOS_DEVICE_CODE_LEN];

    /** �������Ϣ */
    CS_NOTIFY_CAMERA_INFO_S     stCameraInfo;

    /** ������Դ��Ϣ */
    CS_NOTIFY_SWITCH_RES_INFO_S stSwitchResInfo;

    /** ҵ������ */
    ULONG_32                       ulServiceType;

}CS_NOTIFY_UI_SRV_SETUP_S;

/***************************************************************************************
LICENCE
��***********************************************************************************/

/**
* @struct tagContactInfo
* @brief ��ϵ����Ϣ�ṹ
* @attention ��
*/
typedef struct tagContactInfo
{
    /** ��ϵ������ */
    CHAR szName[IMOS_NAME_LEN];

    /** ��ϵ�����ڹ�˾ */
    CHAR szCompany[IMOS_NAME_LEN];

    /** ��ϵ��email��ַ */
    CHAR szEmail[IMOS_MAIL_LEN];

    /** ��ϵ�˵绰 */
    CHAR szPhone[IMOS_PHONE_LEN];

    /** ��ϵ���ʱ� */
    CHAR szZipcode[IMOS_MAIL_CODE_LEN];

    /** ��ϵ�˵�ַ */
    CHAR szAddress[IMOS_CONTACT_ADDRESS_LEN];

} CONTACTINFO_S;

/**
* @struct tagClientInformation
* @brief �ͻ���Ϣ�ṹ
* @attention ��
*/
typedef struct tagClientInformation
{
    /** �ͻ����ƣ�һ��ͬ��˾���� */
    CHAR szClientName[IMOS_NAME_LEN];

    /** ���� */
    CHAR szCountry[IMOS_NAME_LEN];

    /** ʡ */
    CHAR szProvince[IMOS_NAME_LEN];

    /** ���� */
    CHAR szCity[IMOS_NAME_LEN];

    /** ��˾ */
    CHAR szCompany[IMOS_NAME_LEN];

    /** �ʱ� */
    CHAR szZipcode[IMOS_MAIL_CODE_LEN];

    /** ��ַ */
    CHAR szAddress[IMOS_CONTACT_ADDRESS_LEN];

    /** email��ַ */
    CHAR szEmail[IMOS_MAIL_LEN];

    /** �绰 */
    CHAR szPhone[IMOS_PHONE_LEN];

    /** ��ϵ����Ϣ */
    CONTACTINFO_S stContactInfo;

} CLIENTINFO_S;

/**
* @struct tagLicenseAuthorityInfo
* @brief ҵ������Ϣ(��ѯLicenseҵ������Ϣ���б�ʱ����)
* @attention ��
*/
typedef struct tagLicenseAuthorityInfo
{
    /** ҵ������, ȡֵΪ#LICENSE_TYPE_E */
    ULONG_32 ulServiceType;

    /** ��Ȩ���, ���ݲ�ѯʱ�ķ��ؽ�� */
    ULONG_32 ulServiceValue;

} LICENSE_AUTHORITYINFO_S;


/**
* @struct tagTimeLimit
* @brief ��Ч������Ϣ(��ѯLicenseʱ����Ϣʱ����)
* @attention ��
*/
typedef struct tagTimeLimit
{
    /** License�������� */
    CHAR szCreateDay[IMOS_TIME_LEN];

    /** License����Ч���� */
    ULONG_32 ulTotalDay;

    /** ��ʹ������ */
    ULONG_32 ulUsedDay;

}TIMELIMIT_S;


/***************************************************************************************************
��������
****************************************************************************************************/
/**
* @struct tagUpgTaskInfo
* @brief  ����������Ϣ
* @attention ��
*/
typedef struct tagUpgTaskInfo
{
    /** �Ƿ�����ִ��, BOOL_TRUEΪ����ִ��; BOOL_FALSEΪ������ִ�� */
    BOOL_T bIsImmediateExe;

    /** ���������� */
    CHAR szUpgJobName[IMOS_NAME_LEN];

    /** ������������, �ɲ��� */
    CHAR szUpgJobDesc[IMOS_DESC_LEN];

    /** �������񴴽���, Ϊ��ǰ�����û��� */
    CHAR szUpgJobCreator[IMOS_NAME_LEN];

    /** �����������ʱ�䣨����ʱ���룩, ��ʽΪ"YYYY-MM-DD HH:MM:SS" */
    CHAR szUpgJobSchdTime[IMOS_TIME_LEN];

    /** �����������ʱ��, ��ʽΪ"YYYY-MM-DD HH:MM:SS", ��ֵ�ڲ�ѯ����������Ϣʱ��Ч, �����������д */
    CHAR szUpgJobFinishTime[IMOS_TIME_LEN];

    /** ���������ƶ�ʱ��, �������������ʱ�򲻱���д */
    CHAR szUpgJobEstablishTime[IMOS_TIME_LEN];
} UPG_TASK_INFO_S;


/**
* @struct  tagUpgDevInfo
* @brief �����豸��Ϣ�ṹ
* @attention ��
*/
typedef struct tagUpgDevInfo
{
    /** �豸���� */
    CHAR szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR szDevName[IMOS_NAME_LEN];

    /** �豸����ǰ�汾�� */
    CHAR szDevOldVersion[IMOS_STRING_LEN_256];

    /** �豸�������汾�� */
    CHAR szDevUpgVersion[IMOS_STRING_LEN_256];

    /** �豸����״̬����ѯʱ��Ч��ȡֵΪ#MM_JOBDEVSTATUS_E */
    ULONG_32 ulDevUpgStatus;

    /** �豸�����������ѯʱ��Ч��ȡֵΪ#MM_JOBDEVRESULT_E */
    ULONG_32 ulUpgResult;

    /** �豸������չ�������ӳ���������������ѯʱ��Ч��ȡֵΪ#MM_UPGDEVEXTRESULT_E */
    ULONG_32 ulDevUpgExtResult;
} UPG_DEV_INFO_S;


/**
* @struct tagUpgTaskQueryItem
* @brief  ����������Ϣ��(��ѯ���������б�ʱ����)
* @attention ��
*/
typedef struct tagUpgTaskQueryItem
{
    /** ����������� */
    CHAR szUpgTaskCode[IMOS_RES_CODE_LEN];

    /** ���������� */
    CHAR szUpgJobName[IMOS_NAME_LEN];

    /** �������񴴽��� */
    CHAR szUpgJobCreator[IMOS_NAME_LEN];

    /** �����������ʱ�䣨����ʱ���룩����ʽΪ"YYYY-MM-DD HH:MM:SS" */
    CHAR szUpgJobSchdTime[IMOS_TIME_LEN];

    /** �����������ʱ�� */
    CHAR szUpgJobFinishTime[IMOS_TIME_LEN];

    /** ���������ƶ�ʱ�� */
    CHAR szUpgJobEstablishTime[IMOS_TIME_LEN];

    /** ��������״̬, ȡֵΪ#MM_JOBDEVSTATUS_E  */
    ULONG_32 ulUpgJobStatus;

    /** ����������, ȡֵΪ#MM_JOBDEVRESULT_E*/
    ULONG_32 ulUpgJobResult;
} UPG_TASK_QUERY_ITEM_S;


/**
* @struct tagUpgAdviceInfo
* @brief ����һ���豸����������Ϣ�ṹ
* @attention ��
*/
typedef struct tagUpgAdviceInfo
{
    /** �豸���� */
    CHAR szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR szDevName[IMOS_NAME_LEN];

    /** �豸�������� */
    CHAR szDevTypeDesc[IMOS_DESC_LEN];

    /** �豸��ǰ�汾�� */
    CHAR szDevCurVersion[IMOS_STRING_LEN_256];

    /** �豸�������汾�� */
    CHAR szDevUpgVersion[IMOS_STRING_LEN_256];

    /** �豸��������
    * - 0 UPG_ADVICE_UNINITIAL �������������������
    * - 1 UPG_ADVICE_NEED      ��Ҫ����
    * - 2 UPG_ADVICE_NONEED    ��������*/
    ULONG_32  ulUpgAdvice;

    /** �豸����״̬ */
    ULONG_32 ulDevOnlineStatus;
} UPG_ADVICE_INFO_S;

/*******************************************************************************
��Ϣͳ��
*******************************************************************************/

/**
* @struct tagSrvStatInfo
* @brief ҵ����Ϣ����ͳ�ƽṹ
* @attention ��
*/
typedef struct tagSrvStatInfo
{
    /** ��ǰʵ��ҵ��������ͳ�� */
    ULONG_32    ulMonitorNum;

    /** ��ǰ����ҵ��������ͳ�� */
    ULONG_32    ulSwitchNum;

    /** ��ǰ����ҵ��������ͳ�� */
    ULONG_32    ulVoiceNum;

    /** ��ǰ�����豸����ͳ�� */
    ULONG_32    ulDevOnlineNum;

    /** ��ǰ�����û�����ͳ�� */
    ULONG_32    ulUserOnlineNum;

    /** ��ǰ�ֶ��洢ҵ������ͳ�� */
    ULONG_32    ulManualRecordNum;
} SRV_STAT_INFO_S;

/**
 * @struct tagAlarmOutputDevQueryItem
 * @brief �澯����豸��ѯ��Ϣ�б�Ԫ��Ϣ
 * @attention
 */
typedef struct tagAlarmOutputDevQueryItem
{

    /** �澯����豸������ */
    CHAR        szAlarmOutputDevName[IMOS_NAME_LEN];

    /** �澯����豸�ı��� */
    CHAR        szAlarmOutputDevCode[IMOS_RES_CODE_LEN];

    /** �澯����豸������,ö������Ϊ:ALARM_OUTPUT_DEV_TYPE_E */
    ULONG_32       ulAlarmOutputDevType;

    /** �澯����豸������֯ */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ������֯���� */
    CHAR        szOrgName[IMOS_NAME_LEN];

}ALARM_OUTPUT_DEV_QUERY_ITEM_S;

/**
 * @struct tagAlarmOutputDev
 * @brief �澯����豸��Ϣ
 * @attention
 */
typedef struct tagAlarmOutputDev
{

    /** �澯����豸������ */
    CHAR        szAlarmOutputDevName[IMOS_NAME_LEN];

    /** �澯����豸������,ö������Ϊ:ALARM_OUTPUT_DEV_TYPE_E */
    ULONG_32       ulAlarmOutputDevType;

    /**�澯����豸��Ҫ�󶨵�ͨ�������豸�ı��� */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /**�澯����豸��Ҫ�󶨵�ͨ�������豸������ */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** �澯����豸��Ҫ�󶨵�ͨ������ */
    ULONG_32       ulChannelIndex;
}ALARM_OUTPUT_DEV_S;


/**
* @struct tagSDKCmdInfo
* @brief ������ִ�в���
* @attention ��
*/
typedef struct tagSDKCmdInfo
{
    /** ����ID */
    ULONG_32 ulCmdId;

    /** ��������б�ÿ���������128�ֽڣ�Ŀǰ֧�ֵ�6���������м�û�еĲ�����Ϊ�մ����� */
    CHAR szParamList[IMOS_MAX_CMD_PARAM_NUM][IMOS_MAX_CMD_PARAM_LEN];

}SDK_CMD_INFO_S;

/**
* @struct tagCSNotifyUIMediaParamChangeProc
* @brief ֪ͨUIý������ı䴦��ṹ
* @attention XPWinCode����UI�ͷ�ʹ��
*/
typedef struct tagCSNotifyUIMediaParamChangeProc
{
    /** ý��ı����� 0:��/�鲥�޸� 1:MSѡ�����(����Ӧ/ָ��)�޸� 2:MSѡ���޸� 3: �鲥����(��ַ/�˿�)�޸� */
    ULONG_32 ulMediaParamChangeType;

    /** �豸���� ����ֵ�������#IMOS_TYPE_E */
    ULONG_32 ulDevType;

    /** �ı�ý��������豸����(������DC/EC/XP/CAMERA����) */
    CHAR szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR szDevName[IMOS_NAME_LEN];

    /* XP��������� */
    ULONG_32 ulXPWinCount;

    /** XP������� */
    CHAR aszXPWinCode[IMOS_XP_WIN_MAX_NUM][IMOS_DEVICE_CODE_LEN];
}CS_NOTIFY_UI_MEDIA_PARAM_CHANGE_PROC_S;

/*******************************************************************************
����ǽ
*******************************************************************************/
/**
* @struct tagScreenUnitInfo
* @brief ��������Ԫ��Ϣ
* @attention
*/
typedef struct tagScreenUnitInfo
{
    /** ���������� */
    CHAR szScreenName[IMOS_NAME_LEN];

    /** ���������� */
    CHAR szScreenCode[IMOS_CODE_LEN];

    /** ״̬��Ϣ:����Ϊ#IMOS_DEV_STATUS_ONLINE������Ϊ#IMOS_DEV_STATUS_OFFLINE������޸�ʱ״̬��Ϣ������д */
    ULONG_32 ulStatus;

    /** ������������Ŀ����ֵ���ڲ�ѯʱ��Ч */
    ULONG_32 ulSplitScreenNum;

    /** ��չ״̬��Ϣ:0��ʾΪ��������1��ʾΪDC */
    ULONG_32 ulExtStatus;
}SCREEN_UNIT_INFO_S;


/**
* @struct tagScreenLayoutInfo
* @brief ������������Ϣ
* @attention
*/
typedef struct tagScreenLayoutInfo
{
    /** ÿ���������ĵ�Ԫ��Ϣ */
    SCREEN_UNIT_INFO_S stScreenUnitInfo;

    /** ������������Ϣ */
    AREA_SCOPE_S stScreenLayout;
}SCREEN_LAYOUT_INFO_S;

/**
* @struct tagTVWallInfo
* @brief ����ǽ��Ϣ
* @attention ����ǽ������Ϣ�Լ�������������������Ϣ
*/
typedef struct tagTVWallInfo
{
    /** ����ǽ���� */
    CHAR szTVWallName[IMOS_NAME_LEN];

    /** ����ǽ���룬���ӵ���ǽʱ��дΪ����ƽ̨�Լ����ɣ����ӵ���ǽ�ɹ��󷵻�; ����д������д�ı������� */
    CHAR szTVWallCode[IMOS_CODE_LEN];

    /** ������֯����룬�����޸�ʱ��Ҫ��д��ƽ̨���ز������ֵ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ����ǽ�����ļ��� */
    CHAR szBackGroundFileName[IMOS_FILE_NAME_LEN];

    /** ���ֱ��룬������д����ѯ����ǽʱ��ƽ̨���� */
    CHAR szLayoutCode[IMOS_CODE_LEN];

    /** ����ǽ�����ļ�����ʵ������, ȡֵ���ֵΪ#IMOS_MONITOR_MAXNUM_PER_WALL */
    ULONG_32 ulScreenCount;

    /** ����ǽ�ֱ���, ȡֵΪ#TW_RESOLUTION_E */
    ULONG_32 ulResolution;

    /** ������������Ϣ���� */
    SCREEN_LAYOUT_INFO_S astTVWallLayoutList[IMOS_MONITOR_MAXNUM_PER_WALL];
}TV_WALL_INFO_S;

/**
* @struct tagTVWallQueryItem
* @brief ����ǽ��Ϣ��(��ѯ����ǽ�б�ʱ����)
* @attention
*/
typedef struct tagTVWallQueryItem
{
    /** ����ǽ���� */
    CHAR szTVWallName[IMOS_NAME_LEN];

    /** ����ǽ���룬�����ʱ��дΪ������ƽ̨�Լ����ɵı���; ����д���ѯ���������ʱ��д���� */
    CHAR szTVWallCode[IMOS_CODE_LEN];

    /** ������֯�����,���ڲ�ѯ���Լ������µĵ���ǽ�б�ƽ̨���ز������ֵ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ����ǽ�ֱ���, ȡֵΪ#TW_RESOLUTION_E */
    ULONG_32 ulResolution;

    /** ����ǽ�����ļ��������� */
    ULONG_32 ulScreenCount;
}TV_WALL_QUERY_ITEM_S;

/**
* @struct tagDevStatusStatistic
* @brief �豸״̬ͳ��(��ѯ�豸����ͳ�Ƶ�ʱ�򷵻�)
* @attention
*/
typedef struct tagDevStatusStatistic
{
    /** �豸���ͣ�ȡֵ�μ�#IMOS_TYPE_E */
    ULONG_32  ulDevType;

    /** �������� */
    ULONG_32  ulOnlineNum;

    /** �������� */
    ULONG_32 ulFaultNum;

    /** �������� */
    ULONG_32 ulOfflineNum;
}DEV_STATUS_STATISTIC_S;

/**
* @struct tagDevBaseInfo
* @brief �����豸������Ϣ
* @attention
*/
typedef struct tagDevBaseInfo
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸���ͣ�ȡֵΪ#IMOS_TYPE_DM, #IMOS_TYPE_MS, #IMOS_TYPE_TS, #IMOS_TYPE_VX500, #IMOS_TYPE_MONITOR, #IMOS_TYPE_EC, #IMOS_TYPE_DC, #IMOS_TYPE_CAMERA */
    ULONG_32  ulDevType;

    /** �豸������, �������ȡֵ��#CAMERA_TYPE_E; �Լ�����������;
    �������豸(EC/DC/MS/DM/VX500)ȡֵ��#IMOS_DEVICE_TYPE_E. */
    ULONG_32  ulDevSubType;

    /** �豸״̬��ȡֵΪ#IMOS_DEV_FAULT_STATUS_E */
    ULONG_32  ulDevStatus;

    /** �豸IP��ַ, �������豸(EC/DC/MS/DM/VX500)��Ч */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** ����� */
    CHAR  szDomainCode[IMOS_CODE_LEN];

    /* Begin: Added by mozhanfei(kf0149), 2013-7-18 for ECR NVR���� */
    /** NVR��ECR�����豸���� */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2012-7-18 for ECR NVR���� */
}DEV_BASIC_INFO_S;


/**
* @struct tagCSBackupFinishInfo
* @brief �������֪ͨ
*/
typedef struct tagCSBackupFinishInfo
{
    /** ��������,ȡֵ��Χ��#BP_BACKUPTYPE_E */
    ULONG_32   ulBackupType;

    /** ���ݽ��: 0Ϊ���ݳɹ�; ����Ϊ����ʧ�ܡ�*/
    ULONG_32   ulResult;
}CS_BACKUP_FINISH_INFO_S;


/**
 * @struct tagGeneralDevInfo
 * @brief ͨ���豸������Ϣ
 * @attention
 */
typedef struct tagGeneralDevInfo
{
    /** ͨ���豸���룬���û����룬��ƽ̨���� */
    CHAR  szGeneralDevCode[IMOS_DEVICE_CODE_LEN];

    /** ͨ���豸���� */
    CHAR  szGeneralDevName[IMOS_NAME_LEN];

     /** �豸���� */
    ULONG_32 ulDevType;

    /** �豸������ */
    ULONG_32 ulDevSubType;

    /** �豸�������� */
    CHAR szDevTypeDesc[IMOS_DESC_LEN];

    /** ��ַ���ͣ�1-IPV4 2-IPV6 */
    ULONG_32 ulAddrType;

    /** ��ַ */
    CHAR  szAddress[IMOS_IPADDR_LEN];

    /** �˿� */
    ULONG_32 ulAddrPort;

    /** ������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �豸���� , ����ֻ����дΪ���ַ���*/
    CHAR  szDevDesc[IMOS_DESC_LEN];

    /** �豸��չ��Ϣ */
    CHAR  szDevReserved[IMOS_RESERVED_LEN];

    /** �豸����ҵ��URL, ��ѡ�ֶ�, ���޸� */
    CHAR  szSvcURL[IMOS_URL_LEN];

    /** �豸״̬��Ϣ, �������޸ĸ�ֵ, ֻ���ڲ�ѯ��ʾ, #IMOS_DEV_STATUS_ONLINE��ʾ����, #IMOS_DEV_STATUS_OFFLINE��ʾ���� */
    ULONG_32 ulStatus;
}GENERAL_DEV_INFO_S;

/**
 * @struct tagThdDevPollCfg
 * @brief �������豸��ѯ���ò���
 * @attention
 */
typedef struct tagThdDevPollCfg
{
    /** ��ѯ���, ��λ����, Ĭ��30����, ֵӦ�ô��ڵ���1 */
    ULONG_32 ulPollInterval;

    /** ��ѯ��ʱʱ��, ��λ��, Ĭ��2s, ��Χ: 1s-60s */
    ULONG_32 ulPollTimeOut;

    /** �����豸һ����ѯ����Դ���, Ĭ��3��, ��Χ: 1-20 */
    ULONG_32 ulPollTimes;
}THD_DEV_POLL_CFG_S;

/**
 * @struct tagInterconnectInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagInterconnectInfo
{
    /** ������Ϣ������Դ���� */
    CHAR  szResCode[IMOS_RES_CODE_LEN];

    /** ������Ϣ���ͣ�ȡֵΪ#INTERCONNECT_INFO_TYPE_E */
    ULONG_32       ulInterInfoType;

    /** ����Э�����ͣ�ȡֵΪ#INTERDOMAIN_PROTOCOL_TYPE_E */
    ULONG_32      ulProtocolType;

    /** ��ȼ�, ĿǰȡֵΪ1~7 */
    ULONG_32    ulDomainLevel;

    /** ��������Դ���� */
    CHAR  szInterResCode[IMOS_RES_CODE_LEN];

    /** �������û����� */
    CHAR  szInterUserCode[IMOS_USER_CODE_LEN];

 }INTERCONNECT_INFO_S;


/**
 * @struct tagResourceGroupUnit
 * @brief ��Դ�鵥Ԫ��Ϣ
 * @attention
 */
typedef struct tagResourceGroupUnit
{
    /** ��Դ���� */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** ��Դ���� */
    CHAR        szResName[IMOS_NAME_LEN];

    /** ����¼��״̬, ȡֵΪ#MANUAL_STORE_STATUS_E */
    ULONG_32 ulManualStorStatus;

    /** ���������� */
    ULONG_32 ulOperateRet;

    /** �����ֶ� */
    CHAR szReserve[120];
}RESOURCE_GROUP_UNIT_S;

/**
 * @struct tagResourceGroupInfo
 * @brief ��Դ����Ϣ
 * @attention
 */
typedef struct tagResourceGroupInfo
{
    /** ��Դ����� */
    CHAR        szResGroupCode[IMOS_RES_CODE_LEN];

    /** ��Դ������ */
    CHAR        szResGroupName[IMOS_NAME_LEN];

    /** ��Դ������ */
    ULONG_32       ulGroupResType;

    /** ���ڵ���Դ��Ŀ */
    ULONG_32       ulResNum;

}RESOURCE_GROUP_INFO_S;


/**
 * @struct tagLayoutInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagLayoutInfo
{
    /** ���ֱ��� */
    CHAR        szLayoutCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR        szLayoutName[IMOS_NAME_LEN];

    /** �����������ɲ��� */
    CHAR        szLayoutDes[IMOS_DESC_LEN];

    /** �������ͣ�ȡֵΪ#LAYOUT_TYPE_E */
    ULONG_32       ulLayoutType;

    /** ��Ļ����ʱΪ��Ļ������������������ʱΪ��������Ŀ */
    ULONG_32       ulScreenCount;

    /** ������������Ϣ���飬����������ʱʹ�� */
    AREA_SCOPE_S astScreenLayoutList[IMOS_DISPLAY_MAXNUM_PER_LAYOUT];
}LAYOUT_INFO_S;

/**
* @struct tagLayoutInfoQueryItem
* @brief ������Ϣ��(��ѯ�����б�ʱ����)
* @attention
*/
typedef struct tagLayoutInfoQueryItem
{
    /** �������� */
    CHAR szLayoutName[IMOS_NAME_LEN];

    /** ���ֱ��� */
    CHAR szLayoutCode[IMOS_CODE_LEN];

    /** �������ͣ�ȡֵΪ#LAYOUT_TYPE_E */
    ULONG_32       ulLayoutType;
}LAYOUT_INFO_QUERY_ITEM_S;


/**
 * @struct tagSalvoUnit
 * @brief ����ʾ��Ԫ��Ϣ
 * @attention
 */
typedef struct tagSalvoUnit
{
    /** ��������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** ����1:����������ʾ������������� */
    CHAR        szParam1[IMOS_STRING_LEN_128];

    /** ����2:����������ʾ������������� */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** ����3:��Ļ����ʾ������Ļ���, ȡֵΪ1 */
    ULONG_32       ulParam3;

    /** ����4:��Ļ����ʾ������� */
    ULONG_32       ulParam4;

    /** ����5:���� */
    ULONG_32       ulParam5;

    /** �������ķ�����Ŀ�����ڲ�ѯʱ��Ч */
    ULONG_32       ulSplitScreenNum;
}SALVO_UNIT_S;

/**
 * @struct tagSalvoInfo
 * @brief ����ʾ��Ϣ
 * @attention
 */
typedef struct tagSalvoInfo
{
    /** ����ʾ���ͣ�ȡֵΪ#SALVO_TYPE_E */
    ULONG_32       ulSalvoType;

    /** ����ʾ���� */
    CHAR        szSalvoCode[IMOS_CODE_LEN];

    /** ����ʾ���� */
    CHAR        szSalvoName[IMOS_NAME_LEN];

    /** ���ֱ��룬��ѡ */
    CHAR        szLayoutCode[IMOS_CODE_LEN];

    /** ����ʾ��������ʾ��Ԫʵ������, ���ֵΪ#IMOS_DISPLAY_MAXNUM_PER_SALVO */
    ULONG_32       ulSalvoUnitNum;

    /** ����ʾ��Ԫ���� */
    SALVO_UNIT_S astSalvoUnitList[IMOS_DISPLAY_MAXNUM_PER_SALVO];
}SALVO_INFO_S;

/**
 * @struct tagSalvoInfo
 * @brief ����ʾ��Ϣ
 * @attention
 */
typedef struct tagSalvoInfoV2
{
    /** ����ʾ���ͣ�ȡֵΪ#SALVO_TYPE_E */
    ULONG_32       ulSalvoType;

    /** ����ʾ���� */
    CHAR        szSalvoCode[IMOS_CODE_LEN];

    /** ����ʾ���� */
    CHAR        szSalvoName[IMOS_NAME_LEN];

    /** ���ֱ��룬��ѡ */
    CHAR        szLayoutCode[IMOS_CODE_LEN];

    /** ����ʾ��������ʾ��Ԫʵ������ */
    ULONG_32       ulSalvoUnitNum;

    /** ����ʾ��Ԫ���� */
    SALVO_UNIT_S astSalvoUnitList[1];
}SALVO_INFO_V2_S;

/**
* @struct tagSalvoQueryItem
* @brief ����ʾ��Ϣ��(��ѯ����ʾ�б�ʱ����)
* @attention
*/
typedef struct tagSalvoQueryItem
{
    /** ����ʾ���� */
    CHAR szSalvoName[IMOS_NAME_LEN];

    /** ����ʾ���룬�����ʱ��дΪ������ƽ̨�Լ����ɵı���; ����д���ѯ���������ʱ��д���� */
    CHAR szSalvoCode[IMOS_CODE_LEN];

    /** ������֯�����,���ڲ�ѯ���Լ������µ�����ʾ�б�ƽ̨���ز������ֵ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ����ʾ��������ʾ��Ԫ���� */
    ULONG_32 ulSalvoUnitNum;

    /** ����ʾ���ͣ�ȡֵΪ#SALVO_TYPE_E */
    ULONG_32       ulSalvoType;

}SALVO_QUERY_ITEM_S;


/**
 * @struct tagCommonSwitchUnit
 * @brief ͨ��������Դ�е���Դ��Ϣ
 * @attention
 */
typedef struct tagCommonSwitchUnit
{
    /** ��Դ���� */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** ��Դ���� */
    CHAR        szResName[IMOS_NAME_LEN];

    /** ��Դ���� */
    ULONG_32       ulResType;

    /** ��� */
    ULONG_32       ulSequence;

     /** �л�ʱ�� */
    ULONG_32       ulInterval;
}COMMON_SWITCH_UNIT_S;

/**
 * @struct tagCommonSwitchResource
 * @brief ͨ��������Դ��Ϣ
 * @attention
 */
typedef struct tagCommonSwitchResource
{
    /** ͨ���������ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E */
    ULONG_32                   ulSwitchType;

    /** ͨ�����������ͣ���������Ѳ��������Ѳ���ͣ�ȡֵΪ#GROUP_SWITCH_TYPE_E */
    ULONG_32                   ulSwitchSubType;

    /** ���л�����Ϣ */
    SWITCH_BASE_S           stSwitchBaseInfo;

    /** ͨ��������Դ������������Դ��ʵ����Ŀ, ���ȡֵΪ#IMOS_COMMON_SWITCH_RES_MAXNUM */
    ULONG_32                   ulSwitchResNum;

    /** ͨ��������Դ���� */
    COMMON_SWITCH_UNIT_S    astSwitchUnitList[IMOS_COMMON_SWITCH_RES_MAXNUM];
}COMMON_SWITCH_RESOURCE_S;

/* Begin Added by gKF0090, 2012-12-27 of ��ѯ���������Ѳ��Ϣ */
/**
 * @struct tagGroupSwitchResList
 * @brief ����Ѳ�б��¼
 * @attention
 */
typedef struct tagGroupSwitchResList
{
    /** ��������� */
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** ����������� */
    CHAR  szCameraDomain[IMOS_CODE_LEN];

	/** ����ѲID */
	CHAR  szGroupSwitchResCode[IMOS_CODE_LEN];

	/** ����Ѳ���� */
	CHAR  szGroupSwitchResName[IMOS_NAME_LEN];

    /** ����Ѳ����*/
	ULONG_32  ulGroupSwitchResType;

	/** ����Ѳ����*/
	ULONG_32  ulGroupSwitchResNum;
}GROUP_SWITCH_RES_LIST_S;
/* End Added by gKF0090, 2012-12-27 of ��ѯ���������Ѳ��Ϣ */

/* Begin Added by dengshuhua00673, 2012-11-24 of �Զ�������Ѳ */
/**
 * @struct tagCommonSwitchUnitV2
 * @brief ͨ��������Դ�е���Դ��ϢV2
 * @attention
 */
typedef struct tagCommonSwitchUnitV2
{
    /** ��Դ���� */
    CHAR        szResCode[IMOS_RES_CODE_LEN];

    /** ��Դ���� */
    CHAR        szResName[IMOS_NAME_LEN];

    /** ��Դ���� */
    ULONG_32       ulResType;

    /** ��� */
    ULONG_32       ulSequence;

    /** �л�ʱ�� */
    ULONG_32       ulInterval;

	/** �������������(ͨ��������ԴΪ�Զ���������Ѳ��Դʱ��Ч) */
    ULONG_32       ulStreamType;
}COMMON_SWITCH_UNIT_V2_S;

/**
 * @struct tagCommonSwitchResourceV2
 * @brief ͨ��������Դ��ϢV2
 * @attention
 */
typedef struct tagCommonSwitchResourceV2
{
    /** ͨ���������ͣ�ȡֵΪ#COMMON_SWITCH_TYPE_E */
    ULONG_32	ulSwitchType;

    /** ͨ�����������ͣ���������Ѳ��������Ѳ���ͣ�ȡֵΪ#GROUP_SWITCH_TYPE_E */
    ULONG_32                   ulSwitchSubType;

    /** ���л�����Ϣ */
    SWITCH_BASE_S           stSwitchBaseInfo;

    /** ͨ��������Դ������������Դ��ʵ����Ŀ, ���ȡֵΪ#IMOS_COMMON_SWITCH_RES_MAXNUM */
    ULONG_32                   ulSwitchResNum;

    /** ͨ��������Դ���� */
    COMMON_SWITCH_UNIT_V2_S  astSwitchUnitList[IMOS_COMMON_SWITCH_RES_MAXNUM];

    /** ����ǽ��Դ���� */
    CHAR szTVWallCode[IMOS_CODE_LEN];

    /** �ͻ��˷����� */
    ULONG_32 ulScrNum;

    /** ʵ����ռ����(����ռ����ռ)��ȡֵΪ#AUTOSALVO_REAVE_TYPE_E */
    ULONG_32 ulReaveType;

    /** �Զ���������Ѳ���ʱ�� */
    ULONG_32 ulNolayoutInterval;
}COMMON_SWITCH_RESOURCE_V2_S;
/* End Added by dengshuhua00673, 2012-11-24 of �Զ�������Ѳ */

/**
 * @struct tagCommonSwitchPlanBase
 * @brief ͨ�����мƻ�������Ϣ
 * @attention
 */
typedef struct tagCommonSwitchPlanBase
{
    /** ͨ�����мƻ����ͣ�ȡֵΪ#COMMON_SWITCH_PLANTYPE_E */
    ULONG_32       ulSwitchPlanType;

    /** ���мƻ����� */
    CHAR        szPlanName[IMOS_NAME_LEN];

    /** ���мƻ��������� */
    CHAR        szCreatTime[IMOS_TIME_LEN];

    /** ����1�����������Ϊ�û����� */
    CHAR        szParam1[IMOS_STRING_LEN_128];

    /** ����2�����������Ϊ�û����� */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** ����3: ��������д�����Ļ���, ȡֵΪ1 */
    ULONG_32       ulParam3;

    /** ����4�����������Ϊ����� */
    ULONG_32       ulParam4;

    /** �ƻ�����, ȡֵΪ#PLAN_TYPE_E */
    ULONG_32       ulPlanType;

    /** ���мƻ�������֯���� */
    CHAR        szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** �ƻ�����, �ɲ��� */
    CHAR        szPlanDesc[IMOS_DESC_LEN];
}COMMON_SWITCH_PLAN_BASE_S;

/**
 * @struct tagSwitchPlanInfo
 * @brief ͨ�����мƻ���Ϣ
 * @attention
 */
typedef struct tagCommonSwitchPlanInfo
{
    /** ���мƻ�������Ϣ */
    COMMON_SWITCH_PLAN_BASE_S   stSwitchBaseInfo;

    /** ���мƻ�ʱ����Ϣ */
    PLAN_TIME_FOR_RES_S         stSwitchTimeInfo;
}COMMON_SWITCH_PLAN_INFO_S;


/**
 * @struct tagCommonSwitchPlanQueryItem
 * @brief ͨ�����мƻ���Ϣ��(��ѯͨ�����мƻ��б�ʱ����)
 * @attention
 */
typedef struct tagCommonSwitchPlanQueryItem
{
    /** ͨ�����мƻ����� */
    CHAR            szSwitchPlanCode[IMOS_RES_CODE_LEN];

    /** ͨ�����мƻ����� */
    CHAR            szPlanName[IMOS_NAME_LEN];

    /** ͨ�����мƻ��������� */
    CHAR            szCreatTime[IMOS_TIME_LEN];

    /** ͨ�����мƻ����ͣ�ȡֵΪ#COMMON_SWITCH_PLANTYPE_E */
    ULONG_32       ulSwitchPlanType;

    /** ����1�����������Ϊ�û����� */
    CHAR        szParam1[IMOS_STRING_LEN_128];

    /** ����2�����������Ϊ�û����� */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** ����3: ��������д�����Ļ���, ȡֵΪ1 */
    ULONG_32       ulParam3;

    /** ����4�����������Ϊ����� */
    ULONG_32       ulParam4;

    /** �ƻ�״̬��BOOL_TRUEΪ�ƻ��Ѿ�����, BOOL_FALSEΪ�ƻ�δ���� */
    ULONG_32           ulPlanStatus;

}COMMONSWITCH_PLAN_QUERY_ITEM_S;

/*******************************************************************************
����ʾ
*******************************************************************************/

typedef struct tagCSSalvoStartSalvoUnit
{
    /** ����������/XP������� */
    CHAR szScreenCode[IMOS_DEVICE_CODE_LEN];

    /** ����������/XP����� */
    CHAR szScreenName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR szCameraName[IMOS_NAME_LEN];

    /** ��������� */
    ULONG_32 ulCameraType;

    /** ʵ��������� */
    ULONG_32 ulResultCode;

}CS_SALVO_START_SALVO_UNIT_S;

/**
* @struct tagCSNofityScreenInfo
* @brief ҵ������Ϣ֪ͨ�������Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSNofityScreenInfo
{
    /** ��ʾ������ */
    CHAR  szScreenCode[IMOS_DEVICE_CODE_LEN];

    /** ��ʾ������, �����XP����, ��д����� */
    CHAR  szScreenName[IMOS_NAME_LEN];

    /** ��ʾ������ */
    ULONG_32 ulScreenType;

}CS_NOTIFY_SCREEN_INFO_S;

/* ����ʾ��Ԫ��Ϣ */
/**
* @struct tagCSNotifySalvoUnitItem
* @brief ֪ͨUI����ʾ��Ԫʵ���������������ʾ��Ԫ��Ϣ
* @attention
*/
typedef struct tagCSNotifySalvoUnitItem
{
    /** ��ʾ����Ϣ */
    CS_NOTIFY_SCREEN_INFO_S stScreenInfo;

    /** �������Ϣ */
    CS_NOTIFY_CAMERA_INFO_S stCameraInfo;

}CS_NOTIFY_SALVO_UNIT_ITEM_S;

typedef struct tagCSNotifySalvoInfo
{
    /** ����ʾ���� */
    CHAR szSalvoCode[IMOS_RES_CODE_LEN];

    /** ����ʾ���� */
    CHAR szSalvoName[IMOS_NAME_LEN];

    /** ����ʾ��Ԫ���� */
    ULONG_32 ulSalvoUnitNum;

    /** ����ʾ��Ԫ�б� */
    CS_NOTIFY_SALVO_UNIT_ITEM_S astNotifySalvoUnitItem[IMOS_DISPLAY_MAXNUM_PER_SALVO];

}CS_NOTIFY_SALVO_INFO_S;

typedef struct tagCSNotifyGroupsalvoInfo
{
    /** ����Ѳ��� */
    ULONG_32 ulGroupsalvoHandle;

    /** ����Ѳ���ƿ�Ψһ����� */
    ULONG_32 ulGroupsalvoCBUniqSeq;

    /** ����ѲʱUI��������ʾ����Ϣϵ�к� */
    ULONG_32 ulGroupsalvoNotifyUISeq;

    /** ����Ѳ��Դ���� */
    CHAR szGroupsalvoCode[IMOS_RES_CODE_LEN];

    /** ����Ѳ��Դ���� */
    CHAR szGroupsalvoName[IMOS_NAME_LEN];

}CS_NOTIFY_GROUPSALVO_INFO_S;

/* Begin Added by dengshuhua00673, 2013-01-06 of �Զ�������Ѳ */
typedef struct tagCSNotifyAutoSalvoInfo
{
    /** �Զ���������Ѳ��� */
    ULONG_32 ulAutoSalvoHandle;

    /** �Զ���������Ѳ���ƿ�Ψһ����� */
    ULONG_32 ulAutoSalvoCBUniqSeq;

    /** �Զ���������Ѳ��Դ���� */
    CHAR szAutoSalvoCode[IMOS_RES_CODE_LEN];

    /** �Զ���������Ѳ��Դ���� */
    CHAR szAutoSalvoName[IMOS_NAME_LEN];

}CS_NOTIFY_AUTOSALVO_INFO_S;
/* End Added by dengshuhua00673, 2013-01-06 of �Զ�������Ѳ */

typedef struct tagCSNotifyGroupsalvoPlanInfo
{
    /** ����Ѳ�ƻ����� */
    CHAR szGroupsalvoPlanCode[IMOS_RES_CODE_LEN];

    /** ����Ѳ�ƻ����� */
    CHAR szGroupsalvoPlanName[IMOS_NAME_LEN];

}CS_NOTIFY_GROUPSALVO_PLAN_INFO_S;

typedef struct tagCSNotifyOperateUserInfo
{
    /* ��ռ�������û��� */
    CHAR szUserName[IMOS_NAME_LEN];

    /* ��ռ�����û���¼���� */
    CHAR szUserLoginCode[IMOS_RES_CODE_LEN];

    /* ��ռ�����û��ĵ�¼IP */
    CHAR szUserIpAddress[IMOS_IPADDR_LEN];

}CS_NOTIFY_OPERATE_USER_INFO_S;

/**
* @struct tagCSNotifySalvoUnitEvent
* @brief ֪ͨUI����ʾ��Ԫ�¼�
* @attention
*   ����ʾ��Ԫ�Ķ���ҵ�����������ʾ/����Ѳ/����Ѳ�ƻ�, ͨ���ṹ�ж���ҵ����������
*/
typedef struct tagCSNotifySalvoUnitEvent
{
    /** ����ʾ���� */
    CHAR szSalvoCode[IMOS_RES_CODE_LEN];

    /** ����ʾ��Ԫ��Ϣ */
    CS_NOTIFY_SALVO_UNIT_ITEM_S stNotifySalvoUnitItem;

    /** �����û���Ϣ */
    CS_NOTIFY_OPERATE_USER_INFO_S stOperUserInfo;

    /** ����ҵ������ */
    ULONG_32 ulTopServiceType;

    /** ֪ͨ��Ϣ����: SALVO_UNIT_NOTIFY_UI_EVENT_TYPE_E */
    ULONG_32 ulNotifyType;

}CS_NOTIFY_SALVO_UNIT_EVENT_S;

/**
* @struct tagCSNotifyUISalvoEvent
* @brief ֪ͨUI����ҵ�����(����ʾ/����Ѳ/����Ѳ�ƻ�)
* @attention
*   ���ݶ���ҵ�����ͺ���ҵ��������Ψһȷ����ǰҵ��
*/
typedef struct tagCSNotifyUISalvoEvent
{
    /** ����ʾ��Ϣ, ��ҵ������������ʾʱ��Ч */
    CS_NOTIFY_SALVO_INFO_S stSalvoInfo;

    /** ����Ѳ��Ϣ, ����ҵ�����ͻ���ҵ������������Ѳʱ��Ч */
    CS_NOTIFY_GROUPSALVO_INFO_S stGroupsalvoInfo;

    /* Begin Added by dengshuhua00673, 2013-01-06 of �Զ�������Ѳ */
	/** �Զ�������Ѳ��Ϣ, ����ҵ�����ҵ���������Զ�������Ѳʱ��Ч */
    CS_NOTIFY_AUTOSALVO_INFO_S stAutoSalvoInfo;
    /* End Added by dengshuhua00673, 2013-01-06 of �Զ�������Ѳ */

    /** ����Ѳ�ƻ���Ϣ, ����ҵ������������Ѳ�ƻ�ʱ��Ч */
    CS_NOTIFY_GROUPSALVO_PLAN_INFO_S stGroupsalvoPlanInfo;

    /** �����û���Ϣ */
    CS_NOTIFY_OPERATE_USER_INFO_S stOperUserInfo;

    /** ���ֱ���, ��ҵ������������ʾʱ��Ч */
    CHAR szLayoutCode[IMOS_CODE_LEN];

    /** ����ҵ������ */
    ULONG_32 ulTopServiceType;

    /** ��ҵ������ */
    ULONG_32 ulSubServiceType;

    /** ֪ͨ��Ϣ����: SALVO_NOTIFY_EVENT_TYPE_E */
    ULONG_32 ulNotifyType;

}CS_NOTIFY_UI_SALVO_EVENT_S;

/**
* @struct tagCSNotifyStartXPSalvo
* @brief ֪ͨUI������Ļ����ʾ
* @attention
*/
typedef struct tagCSNotifyStartXPSalvo
{
    /** ����Ѳ���� */
    CHAR szGroupsalvoCode[IMOS_RES_CODE_LEN];

    /** ����ʾ���� */
    CHAR szSalvoCode[IMOS_RES_CODE_LEN];

    /** ���ֱ��� */
    CHAR szLayoutCode[IMOS_RES_CODE_LEN];

    /** ֪ͨ����� */
    ULONG_32 ulSrcHandle;

    /** ��Ϣ���к� */
    ULONG_32 ulMsgSequence;

    /** ����ԭ����: #CS_OPERATE_CODE_E */
    ULONG_32 ulOperateCode;

}CS_NOTIFY_START_XP_SALVO_S;

/* Begin Added by dengshuhua00673, 2013-01-06 of �Զ�������Ѳ */
/**
* @struct tagCSNotifyStartXPAutoSalvo
* @brief  ֪ͨUI������Ļ�Զ���������Ѳ
* @attention
*/
typedef struct tagCSNotifyStartXPAutoSalvo
{
    /** ����Ѳ���� */
    CHAR szAutoSalvoCode[IMOS_RES_CODE_LEN];

    /** ֪ͨ����� */
    ULONG_32 ulSrcHandle;

    /** ��Ϣ���к� */
    ULONG_32 ulMsgSequence;

    /** ����ԭ����: #CS_OPERATE_CODE_E */
    ULONG_32 ulOperateCode;

}CS_NOTIFY_START_XP_AUTOSALVO_S;
/* End Added by dengshuhua00673, 2013-01-06 of �Զ�������Ѳ */

/**
* @struct tagCSTLReaveNotify
* @brief  ͸��ͨ��ҵ����ռ��Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSTLReaveNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                  /* ��ռ�����û����� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];           /* ��ռ�����û��ĵ�¼IP */
    CHAR    szChannelCode[IMOS_RES_CODE_LEN];           /* ͸��ͨ������ */
    CHAR    szChannelName[IMOS_NAME_LEN];               /* ͸��ͨ������ */
    ULONG_32   ulNotifyType;                               /* ֪ͨ���� ��Ӧö��:TL_NOTIFY_UI_EVENT_TYPE */
}CS_TL_REAVE_NOTIFY_S;

/*******************************************************************************
                                         �������豸����
*******************************************************************************/

/**
 * @struct tagFactoryTypeInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagFactoryTypeInfo
{
    /** ��������ID, ȡֵ��Χ��1��65535 */
    ULONG_32 ulTypeId;

    /** �������� */
    CHAR  szTypeName[IMOS_NAME_LEN];

    /** �������� */
    CHAR  szDesc[IMOS_DESC_LEN];

    /** �����ֶΣ���ʱ���� */
    CHAR  szReserved[IMOS_STRING_LEN_64];
}MANUFACTURER_TYPE_INFO_S;

/**
 * @struct tagDevTypeInfo
 * @brief �豸������Ϣ
 * @attention
 */
typedef struct tagDevTypeInfo
{
    /** �豸���� */
    ULONG_32 ulDevType;

    /** �豸������ */
    ULONG_32 ulDevSubType;

    /** �������� */
    ULONG_32 ulManuFactureType;

    /** �������� */
    CHAR szTypeDesc[IMOS_DESC_LEN];

}DEV_TYPE_INFO_S;

/**
 * @struct tagEventTypeInfo
 * @brief �¼����ͣ���Ӧ��tbl_eventtype
 * @attention
 */
typedef struct tagEventTypeInfo
{
    /** �¼����ͣ�ȡֵΪ#AlARM_TYPE_E */
    ULONG_32 ulEventType;

    /** �¼����� */
    CHAR    szEventName[IMOS_NAME_LEN];

    /** �¼����� */
    ULONG_32   ulEventSecurity;

    /** �¼����� */
    ULONG_32   ulEventCategory;

    /** ������ */
    CHAR    szEventSuggestion[IMOS_STRING_LEN_256];

    /** ά������ */
    CHAR    szEventExperience[IMOS_STRING_LEN_256];
}EVENT_TYPE_INFO_S;

/**
* @struct tagEventTypeExtInfo
* @brief �¼����ͣ���Ӧ��tbl_eventtype,tbl_event_enable
* @attention
*/
typedef struct tagEventTypeExtInfo
{
    /** �¼���ʾ��Ϣ */
    EVENT_TYPE_INFO_S  stEventTypeInfo;

    /** ϵͳĬ���¼����� */
    CHAR    szPreEventName[IMOS_NAME_LEN];

    /** ϵͳĬ���¼����� */
    ULONG_32   ulPreEventSecurity;

    /** ϵͳ�Զ����¼����� */
    CHAR    szSysEventName[IMOS_NAME_LEN];

    /** ϵͳ�Զ����¼����� */
    ULONG_32   ulSysEventSecurity;

    /* �Ƿ���ϵͳԤ����澯���� */
    BOOL_T  bSysEventType;

}EVENT_TYPE_EXT_INFO_S;

/**
* @struct tagEventTypeInfo
* @brief �¼��������豸���͹�����ϵ
* @attention
*/
typedef struct tagEventTypeRel
{
    /** �¼����� */
    ULONG_32  ulEventType;

    /** �豸���� */
    DEV_TYPE_INFO_S stDevTypeInfo;
}EVENT_TYPE_REL_S;

/**
* @struct tagEventTypeInfo
* @brief �¼��ۺ���Ϣ
* @attention
*/
typedef struct tagEventType
{
    /** �¼����� */
    EVENT_TYPE_INFO_S  stEventTypeInfo;

    /** �¼������������� */
    ULONG_32              ulEventTypeRelInfoNum;

    /** �¼�����������Ϣ */
    EVENT_TYPE_REL_S   astEventTypeRelInfo[IMOS_EVENT_TYPE_REL_MAX_NUM];

    /** �¼������Ƿ���ڱ��λ,���ھ�Ϊ1�������ھ�Ϊ0 */
    BOOL_T  bEventTypeIsExist;
}EVENT_TYPE_S;
/***************************************************************************
 ����
****************************************************************************/
/**
 * @struct tagConditionItem
 * @brief ��������ѡ��
 * @attention
 */
typedef struct tagSubscConditionItem
{
    /** ���Ĺ����������ͣ��Ͷ��������йأ���Ӧö�ٲμ���������˵�� */
    ULONG_32 ulSubscConType;

    /** ���������߼���ϵ����: LOGIC_FLAG_E��Ŀǰֻ֧�ֵ��� */
    ULONG_32 ulLogicFlag;

    /** �������ݣ����Ϊ��ֵ����ͨ����׼ת������ת�����ַ��� */
    CHAR  szConData[IMOS_STRING_LEN_64];
}SUBSC_CONDITION_ITEM_S;

/**
 * @struct tagSubscCondition
 * @brief ���Ĺ�������
 * @attention
 */
typedef struct tagSubscscCondition
{
    /** �������� */
    ULONG_32 ulItemNum;

    /** ���Ĺ��������б� */
    SUBSC_CONDITION_ITEM_S astQueryConditionList[IMOS_SUBSC_ITEM_MAX_NUM];

 }SUBSC_CONDITION_S;

/**
* @struct tagSubscBaseInfo
* @brief ���ĸ澯�Ļ�����Ϣ
*/
typedef struct tagSubscBaseInfo
{
    CHAR                szResCode[IMOS_RES_CODE_LEN];       /** ���ĵ���Դ���� */
    ULONG_32               ulResType;                          /** ��Դ����:ö��ֵΪ: #IMOS_TYPE_E.Ŀǰ֧��:IMOS_TYPE_CAMERA��IMOS_TYPE_ALARM_SOURCE��IMOS_TYPE_ORG��Դ���� */
    ULONG_32               ulSubscType;                        /** �������ͣ�ö��ֵΪ:#SUBSC_TYPE_E */
    SUBSC_CONDITION_S   stSubscCon;                         /** ���Ĺ������������ݶ������Ͳ�ͬ����ͬ���μ�ö��ֵ#SUBSC_TYPE_E�е������� */
    ULONG_32               ulSubscExpires;                     /** ����ʱ��������Ϊ��λ��������Сʱ��1Сʱ���ϣ��Ϊ8760��Сʱ */
}SUBSC_BASE_INFO_S;


/**
* @struct tagSubscFullInfo
* @brief ���ĵ�ȫ����Ϣ
*/
typedef struct tagSubscFullInfo
{
    SUBSC_BASE_INFO_S   stSubscBaseInfo;            /** ���Ļ�����Ϣ */
    CHAR    szSubscResName[IMOS_NAME_LEN];          /** ���ĵ���Դ���� */
    CHAR    szSessionID[IMOS_SSN_ID_LEN];           /** ����ҵ��ID */
    CHAR    szEndTime[IMOS_TIME_LEN];               /** ���Ľ���ʱ�� */
}SUBSC_FULL_INFO_S;

/**
* @struct tagTrunkInfo
* @brief ������Ϣ
*/
typedef struct tagTrunkInfo
{
    /** ���߱��룬����ʱ��Ч */
    CHAR    szTrunkCode[IMOS_RES_CODE_LEN];

    /** �������� */
    CHAR    szTrunkName[IMOS_NAME_LEN];

    /** ���߹������ͣ�ȡֵ��Χ���:TRUNK_TYPE_E */
    ULONG_32   ulTrunkType;

    /** �����������ֵ */
    ULONG_32   ulTrunkMaxNum;

    /** ������ʹ����������ѯʱ��Ч */
    ULONG_32   ulTrunkUsedNum;

    /** ���ߴ������ֵ(��λK) */
    ULONG_32   ulTrunkMaxBandWidth;

    /** ������ʹ�ô�����ѯʱ��Ч */
    ULONG_32   ulTrunkUsedBandWidth;

    /** �����Ƿ����ã���ѯʱ��Ч */
    BOOL_T  bTrunkEnable;

}TRUNK_INFO_S;

/**
* @struct tagTrunkContentInfo
* @brief ����������Ϣ
*/
typedef struct tagTrunkContentInfo
{
    /** �������ݱ��룬����ʱ��Ч */
    CHAR    szTrunkContentCode[IMOS_RES_CODE_LEN];

    /** �����������ͣ�ȡֵ��Χ���:TRUNK_CONTENT_TYPE_E */
    ULONG_32   ulTrunkContentType;

    /** ������Դ���� */
    CHAR    szPhyResCode[IMOS_RES_CODE_LEN];

    /** ���Ӿ�����Դ���ƣ�����ʱ��Ч */
    CHAR    szPhyResName[IMOS_NAME_LEN];

    /** ����Χ��־��ȡֵ��Χ���:TRUNK_CONTENT_RANGE_TYPE_E */
    ULONG_32   ulTrunkRangeType;

}TRUNK_CONTENT_INFO_S;

/**
* @struct tagSysStreamFormat
* @brief ϵͳ��װ����ʽ
* @attention
*/
typedef struct tagSysStreamFormat
{
    /** �����䷽ʽ#IMOS_TRANS_TYPE_E */
    ULONG_32 ulTransType;

    /** ��������#IMOS_STREAM_TYPE_E */
    ULONG_32 ulStreamType;
}SYS_STREAM_FORMAT_S;
/**
 * @struct tagDevStatusInfo
 * @brief �豸�澯״̬��Ϣ
 * @attention
 */
typedef struct tagDevStatusInfo
{
    /** �豸���� */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR szDevName[IMOS_NAME_LEN];

    /** �豸���� ȡֵ�μ�#IMOS_TYPE_E */
    ULONG_32 ulDevType;

    /** �豸������, �������ȡֵ��#CAMERA_TYPE_E; �Լ�����������;
    �������豸(EC/DC/MS/DM/VX500)ȡֵ��#IMOS_DEVICE_TYPE_E. */
    ULONG_32 ulDevSubType;

    /** �豸״̬��4��ULONG�ֶΣ�ÿ������λ��ʾһ���豸״̬(��λȡ˳��ӵ�λ��ʼ);
    �ܹ���֧��128λ�豸״̬, ������λ�����Ӧ���豸״̬�����#DEV_STATUS_BIT_E */
    ULONG_32 aulDevStatus[IMOS_DEV_STATUS_MAX_NUM];

}DEV_STATUS_INFO_S;


/*******************************************************************************
BM
********************************************************************************/

/**
* @struct tagBMInfo
* @brief BM��Ϣ�ṹ��
* @attention �޸�BM��Ϣʱ��ֻ�����޸�BM���ƣ���������ԣ�����ʱ�䴰�ڣ�BM�������Ƿ񰸼����������
*/
typedef struct tagBMInfo
{
    /** BM����, BM��Ψһ��ʶ */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� -- ���޸� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** BM���ͣ�ֵΪ0����ʾBM8500 */
    ULONG_32 ulBMType;

    /** BM������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��������ԣ�0-��ֹͣ��1-������ -- ���޸� */
    ULONG_32 ulFullPolicy;

    /** ���ݿ�ʼʱ�� -- ���޸� */
    CHAR  szBkStartTime[IMOS_SIMPLE_TIME_LEN];

    /** ���ݽ���ʱ�� -- ���޸� */
    CHAR  szBkEndTime[IMOS_SIMPLE_TIME_LEN];

    /** BM����, �ɲ��� -- ���޸� */
    CHAR  szDevDesc[IMOS_DESC_LEN];

    /** ��ת��ý�������ԣ���IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulStreamStorSvrPolicy;

    /** �Ƿ񰸼������������ʶ�� 0-���ǡ�1-�� -- ���޸� */
    ULONG_32 ulIsCaseServer;

    /** �����ֶ� */
    CHAR  szReserve[32];
}BM_INFO_S;

/**
* @struct tagBMQueryItem
* @brief BM����Ϣ��(��ѯBM�б�ʱ����)
* @attention ��
*/
typedef struct tagBMQueryItem
{
    /** BM����, BM��Ψһ��ʶ */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** BM����, ���ֶ���Ч, ȱʡֵΪ0 */
    ULONG_32 ulBMType;

    /** BM������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** BM������֯���� */
    CHAR  szOrgName[IMOS_NAME_LEN];

    /** �豸��ַ���ͣ�1-IPv4��2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** �豸��ַ */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ö��ֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** ��������ԣ�0-��ֹͣ��1-������ */
    ULONG_32 ulFullPolicy;

    /** ���ݿ�ʼʱ�� */
    CHAR  szBkStartTime[IMOS_SIMPLE_TIME_LEN];

    /** ���ݽ���ʱ�� */
    CHAR  szBkEndTime[IMOS_SIMPLE_TIME_LEN];

    /* ��ת��ý�������ԣ�0 ����Ӧ  1 ֱ������ */
    ULONG_32  ulStreamStorSvrPolicy;

    /** �Ƿ񰸼������������ʶ�� 0-���ǡ�1-�� */
    ULONG_32 ulIsCaseServer;

    /** �����ֶ� */
    CHAR  szReserve[32];
}BM_QUERY_ITEM_S;

/**
* @struct tagDMResForBMInfo
* @brief ΪBM�����DM��Դ����Ϣ�ṹ��
* @attention
*/
typedef struct tagDMResForBMInfo
{
    /** BM����, BM��Ψһ��ʶ */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** ��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ������С����MBΪ��λ */
    ULONG_32 ulCapacity;

    /** DM����, DM��Ψһ��ʶ */
    CHAR  szDMCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸���� */
    CHAR  szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** ��Դҵ�����ͣ�ö��ֵΪ#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;

    /** �����ֶ� */
    CHAR  szReserve[32];
}DM_RES_FOR_BM_INFO_S;

/**
* @struct tagThirdResForBMInfo
* @brief ΪBM����ĵ�������Դ����Ϣ�ṹ��
* @attention
*/
typedef struct tagThirdResForBMInfo
{
    /** BM����, BM��Ψһ��ʶ */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** ��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ��������Դȫ·�� */
    CHAR  szLocalPath[IMOS_FILE_PATH_LEN];

    /** ��Դҵ�����ͣ�ö��ֵΪ#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;

    /** �����ֶ� */
    CHAR  szReserve[32];
} THIRD_RES_FOR_BM_INFO_S;



/**
* @struct tagThirdResForBMInfo
* @brief ΪBM����ĵ�������Դ����Ϣ�ṹ��V2
* @attention
*/
typedef struct tagThirdResForBMInfoV2
{

	THIRD_RES_FOR_BM_INFO_S stBMResInfo;

	ULONG_32  ulLunId;                        /* LUN ID */
	
	CHAR    szBmTarget[IMOS_STRING_LEN_64];    /* Target�� */
	
	CHAR    szInitiator[IMOS_STRING_LEN_64];   /* Initiator�� */
	
	CHAR    szDevAddress[IMOS_IPADDR_LEN];     /* IPSAN�豸��ַ */

    CHAR  szReserve[256];      /** �����ֶ� */
} THIRD_RES_FOR_BM_INFO_S_V2;


/**
* @struct tagBMResQueryItem
* @brief BM������Դ����Ϣ��(��ѯBM������Դ�б�ʱ����)
* @attention ��
*/
typedef struct tagBMResQueryItem
{
    /** ������Դ���� */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** BM����, BM��Ψһ��ʶ */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ������Դ����#BAK_RES_TYPE_E */
    ULONG_32 ulResType;

    /** �洢�豸���� */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** ������Դ״̬#BAK_RES_STATUS_E */
    ULONG_32 ulResStatus;

    /** ��������С����MBΪ��λ */
    ULONG_32 ulTotalCapacity;

    /** ʣ��������С����MBΪ��λ */
    ULONG_32 ulSpareCapacity;

    /** ������Դȫ·��-��������Դ����Ч */
    CHAR  szResPath[IMOS_FILE_PATH_LEN];

    /** ��Դҵ�����ͣ�ö��ֵΪ#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;
} BM_RES_QUERY_ITEM_S;

/**
* @struct tagCamBakResInfo
* @brief Ϊ���������BM��Դ����Ϣ�ṹ��(��ѯ�����������Դʱ���ص���Ϣ��)
* @attention
*/
typedef struct tagCamBakResInfo
{
    /** ��������� */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM���� */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ���ݸ澯ǰһ��¼���ʱ��, ȡֵ��Χ[0~15����] -- ���޸� */
    ULONG_32 ulAlarmPreRecLen;

    /** ���ݸ澯��һ��¼���ʱ��, ȡֵ��Χ[1~30����] -- ���޸� */
    ULONG_32 ulAlarmPostRecLen;

    /** ����ģʽ��־λ#BAK_MODE_E */
    ULONG_32 ulCamOwnFlag;

    /** ����������С����MBΪ��λ(������ֶ���Ч) -- ���޸� */
    ULONG_32 ulCapacity;

    /** ����ʣ��������С����MBΪ��λ(������ֶ���Ч)-��ѯʱ����Ч */
    ULONG_32 ulSpareCapacity;

    /** ���������(������ֶ���Ч)��0-��ֹͣ��1-������ -- ���޸� */
    ULONG_32 ulFullPolicy;

    /** ������Դ����(������ֶ���Ч) */
    CHAR szBakResCode[IMOS_CODE_LEN];

    /** ������Դ����(������ֶ���Ч) */
    CHAR szBakResName[IMOS_NAME_LEN];

    /*ת��ģʽ��0 ��֧�֣�Ĭ��ֵ��  1 ��ת��*/
    ULONG_32    ulBkMode;

    /** �����ֶ� */
    CHAR  szReserve[32];
}CAM_BAK_RES_INFO_S;

/**
* @struct tagCamBakResQueryItem
* @brief �����������Դ�����������Ϣ��(��ѯ�����������Դ��������б�ʱ����)
* @attention ��
*/
typedef struct tagCamBakResQueryItem
{
    /** ��������� */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM���� */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ����ģʽ��־λ#BAK_MODE_E */
    ULONG_32 ulCamOwnFlag;

    /** �Ƿ��Ѿ��ƶ��˱��ݼƻ�,#BOOL_TRUE��ʾ�ƶ���BOOL_FALSE��ʾδָ�� */
    BOOL_T bPlanFlag;

    /** ���ݼƻ����� */
    CHAR szPlanCode[IMOS_RES_CODE_LEN];

    /** ���ݼƻ�״̬ */
    ULONG_32 ulPlanStatus;

    /*ת��ģʽ��0 ��֧�֣�Ĭ��ֵ��  1 ��ת��*/
    ULONG_32    ulBkMode;

    /** �����ֶ� */
    CHAR  szReserve[32];
} CAM_BAK_RES_QUERY_ITEM_S;

/**
* @struct tagBakTaskInfo
* @brief �����������Ϣ�ṹ��
* @attention ��
*/
typedef struct tagManulBakInfo
{
    /** ��������� */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ���ݲ���#BAK_POLICY_E */
    ULONG_32 ulBakPolicy;

    /** ����ʱ��:��ʼ������ */
    TIME_SLICE_S stBakTime;

    /** ����·��(����DVR��ʱ��ʹ��) */
    CHAR szBakPath[IMOS_FILE_PATH_LEN];

    /** �������� */
    CHAR szCaseDesc[IMOS_BAK_CASE_LEN];

    /** �����ֶ� */
    CHAR  szReserve[32];
} MANUL_BAK_INFO_S;

/**
* @struct tagBakTaskQueryItem
* @brief �����������Ϣ��(��ѯ��������ʱ����)
* @attention ��
*/
typedef struct tagBakTaskQueryItem
{
    /** ����������� */
    CHAR  szBakTaskCode[IMOS_CODE_LEN];

    /** ������������#BAK_TYPE_E */
    ULONG_32 ulBakType;

    /** ��������״̬#BAK_TASK_STATUS_E */
    ULONG_32 ulBakTaskStatus;

    /** ���ݲ���#BAK_POLICY_E */
    ULONG_32 ulBakPolicy;

    /** �������һ�ι���ʱ�� */
    CHAR  szLastHangupTime[IMOS_TIME_LEN];

    /** ����ʱ��:�ύ������ */
    TIME_SLICE_S stTaskTime;

    /** BM���� */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** ¼��ʱ��:��ʼ������ */
    TIME_SLICE_S stRecTime;

    /** ����ʱ��:��ʼ���������ݲ�ʹ�� */
    TIME_SLICE_S stBakTime;

    /** ����Ŀ��·�����ֶ��������Ч */
    CHAR szBakPath[IMOS_FILE_PATH_LEN];

    /** �û����� */
    CHAR  szUserCode[IMOS_USER_CODE_LEN];

    /** �û����� */
    CHAR  szUserName[IMOS_NAME_LEN];

    /** ��������-�ֶ������������Ч */
    CHAR szCaseDesc[IMOS_BAK_CASE_LEN];

    /** ����ҵ������#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32 ulTaskServiceType;
} BAK_TASK_QUERY_ITEM_S;

/**
* @struct tagBakFileHandleInfo
* @brief �����ļ��Ĳ�����Ϣ�ṹ��
* @attention ��
*/
typedef struct tagBakFileHandleInfo
{
    /** �����ļ��洢·�� */
    CHAR szBakFilePath[IMOS_FILE_PATH_LEN];

    /** BM���� */
    CHAR szBMCode[IMOS_DEVICE_CODE_LEN];

    /** �����ļ���������#BAK_FILE_OPER_E */
    ULONG_32 ulHandleType;
} BAK_FILE_HANDLE_INFO_S;
/* Begin: Added by mozhanfei(kf0149), 2013-11-15 for lock record */
/**
* @struct tagLockedRecordInfo
* @brief ¼��������Ϣ
* @attention ��
*/
typedef struct tagLockedRecordInfo
{
    /** ��������� */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** ¼����ʼʱ��*/
    CHAR  szStartTime[IMOS_TIME_LEN];

    /** ¼�����ʱ��*/
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** ����������Ϣ */
    CHAR  szDesc[IMOS_STRING_LEN_128];
}LOCK_RECORD_INFO_S;

/**
* @struct tagLockedRecordInfo
* @brief ¼�������Ϣ
* @attention ��
*/
typedef struct tagUnlockedRecordInfo
{
    /** ¼���������*/
    IN  ULONG_32   ulUnlockType;

    /** �����������߽���¼���ID */
    IN  CHAR    szUnlockKeyStr[IMOS_STRING_LEN_256];

}UNLOCK_RECORD_INFO_S;

/**
* @struct tagLockedRecordQueryItem
* @brief �����������Ϣ
* @attention ��
*/
typedef struct tagLockedCameraQueryItem
{
    /** ��������� */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** �����������֯���� */
    CHAR    szOrgName[IMOS_NAME_LEN];

    /** ¼�������ڣ��죩 */
    ULONG_32   ulRecStorageDay;

    /** ����¼����� */
    ULONG_32   ulLockRecCnt;

    /** ״̬Ϊ"������"����"������"��¼������� */
    ULONG_32   ulUnhandledRecCnt;

}LOCKED_CAMERA_QUERY_ITEM_S;

/**
* @struct tagLockedRecordQueryItem
* @brief ����¼�����Ϣ
* @attention ��
*/
typedef struct tagLockedRecordQueryItem
{
    /** ����¼��α��� */
    CHAR  szRecLockCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** ¼����ʼʱ��*/
    CHAR  szStartTime[IMOS_TIME_LEN];

    /** ¼�����ʱ��*/
    CHAR  szEndTime[IMOS_TIME_LEN];

    /** ״̬ */
    ULONG_32  ulStatus;

    /** �����룬ֻ��״̬Ϊ"������"��"������"��¼�����Ч */
    ULONG_32  ulErrCode;

    /** ��ע��Ϣ */
    CHAR  szDesc[IMOS_STRING_LEN_128];
}LOCKED_RECORD_QUERY_ITEM_S;

/**
* @struct tagASSMLockSpaceNotify
* @brief SOI ¼�������ռ���Ϣ �ṹ
* @attention ��
*/
typedef struct tagASSMLockSpaceNotify
{
    /** �û����� */
    CHAR    szUserCode[IMOS_CODE_LEN];

    /** �û���¼ID�����û���¼�����������ģ����Ǳ��һ���û���¼��Ψһ��ʶ */
    CHAR szUserLoginID[IMOS_USER_CODE_LEN];

    /** �û���¼�� */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** �û���¼IP��ַ*/
    CHAR szSrcIpAddress[IMOS_IPADDR_LEN];
}AS_SM_LOCK_SPACE_NOTIFY_S;

/**
* @struct tagASSMLockFailureNotify
* @brief SOI ¼���������������Ϣ �ṹ
* @attention ��
*/
typedef struct tagASSMLockFailureNotify
{
    /** ��������� */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** ���������������ͣ���AS_SM_STORE_ACTION_E */
    ULONG_32   ulActionType;
}AS_SM_LOCK_FAILURE_NOTIFY_S;
/* End: Added by mozhanfei(kf0149), 2013-11-15 for lock record */


/**
* @struct tagBakFileQueryItem
* @brief �����ļ�����Ϣ��(��ѯ����������ļ�ʱ����)
* @attention ��
*/
typedef struct tagBakFileQueryItem
{
    /** �����ļ����� */
    CHAR  szBakFileCode[IMOS_RES_CODE_LEN];

    /** BM���� */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR  szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32 ulCameraType;

    /** �����ļ��洢·�� */
    CHAR szBakFilePath[IMOS_FILE_PATH_LEN];

    /** �ļ�����ʱ�� */
    CHAR  szFileCreateTime[IMOS_TIME_LEN];

    /** ����ʱ��:��ʼ������ */
    TIME_SLICE_S stBakTime;

    /** �ļ���������MBΪ��λ */
    ULONG_32 ulFileCapacity;

    /** ������Դ���� */
    CHAR  szBakResCode[IMOS_CODE_LEN];

    /** �ļ�����#BAK_TYPE_E */
    ULONG_32 ulFileType;

    /** �ļ������ʽ��0-TS��1-h3crd */
    ULONG_32 ulFileFormat;

    /** �����ļ�״̬��ʶ��0-�����ļ���1-�����ļ� */
    ULONG_32 ulFileStatus;

    /** �Ƿ�������ʶ��0-δ������1-���� */
    ULONG_32 ulLockFlag;

    /** �������� */
    CHAR szCaseDesc[IMOS_BAK_CASE_LEN];
} CAM_BAK_FILE_QUERY_ITEM_S;


/**
 * @struct tagBackupBase
 * @brief ���ݼƻ�������Ϣ
 * @attention
 */
typedef struct tagBackupBase
{
    /** ���ݼƻ����룬���������� */
    CHAR    szBakPlanCode[IMOS_RES_CODE_LEN];

    /** ���ݼƻ����� */
    CHAR    szBakPlanName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ��������ƣ���ѯ�ƻ���Ϣʱ���� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** �û����� */
    CHAR    szUserCode[IMOS_USER_CODE_LEN];

    /** �ƻ�����ʱ�� */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** ���ݼ���ǰ������ */
    ULONG_32   ulBeforeDays;

    /** �ƻ����ڣ�0-�ռƻ���1-�ܼƻ� */
    ULONG_32   ulPlanCycle;

    /** ���ݿ�ʼʱ�䣬���ֶα������ݲ�ʹ�� */
    CHAR    szBakStartTime[IMOS_TIME_LEN];

    /** ���ݽ���ʱ�䣬���ֶα������ݲ�ʹ�� */
    CHAR    szBakEndTime[IMOS_TIME_LEN];

    /** ���ݲ���#BAK_POLICY_E */
    ULONG_32   ulBakPolicy;

    /** �ƻ�״̬#PLAN_OPER_MODE_E���޸ļƻ�ʱ���ֶ���Ч */
    ULONG_32   ulPlanStatus;
}BAK_PLAN_BASE_S;

/**
 * @struct tagBackupPlan
 * @brief ���ݼƻ���Ϣ
 * @attention
 */
typedef struct tagBackupPlan
{
    /** ���ݼƻ�������Ϣ */
    BAK_PLAN_BASE_S   stBakPlanBasicInfo;

    /** ���ݼƻ�ʱ����Ϣ����ʱ��ƻ� */
    PLAN_WEEKTIME_S   astPlanTime[IMOS_WEEK_DAYS];
}BAK_PLAN_INFO_S;

/**
* @struct tagGetBakUrlInfo
* @brief ��ȡ����¼���ļ�URL������ṹ
*/
typedef struct tagGetBakUrlInfo
{
    /** ��������� */
    CHAR            szCamCode[IMOS_DEVICE_CODE_LEN];

    /** ¼���ļ��� */
    CHAR            szFileName[IMOS_FILE_PATH_LEN];

    /** ¼�����ʼ/����ʱ��, ���е�ʱ���ʽΪ"YYYY-MM-DD hh:mm:ss" */
    TIME_SLICE_S    stRecTimeSlice;

    /** �ͻ���IP��ַ */
    CHAR            szClientIp[IMOS_IPADDR_LEN];

    /** ����ҵ�����ͣ�ȡֵ#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32           ulBakSrvType;

    /** ����¼����룬����ҵ������Ϊ��������ʱ��Ч */
    CHAR            szCaseRecCode[IMOS_CODE_LEN];
}GET_BAK_URL_INFO_S;

/************************************************************************/
/* ��ת��                                                             */
/************************************************************************/
/**
* @struct tagCamStreamStorInfo
* @brief �������ת��������Ϣ�ṹ��
* @attention */
typedef struct tagCamStreamStorInfo
{
    /** ��������� */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM���� */
    CHAR  szBMCode[IMOS_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ������Դ����*/
    CHAR szBakResCode[IMOS_CODE_LEN];

    /** ������Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ռ��������С����MBΪ��λ */
    ULONG_32 ulCapacity;

    /** ���������(������ֶ���Ч)��0-��ֹͣ��1-������ */
    ULONG_32 ulFullPolicy;

    /* �������ͣ�1 ������  2 ������ */
    ULONG_32   ulStreamType;

    /** �����ֶ� */
    CHAR  szReserve[32];
}CAM_STREAM_STOR_INFO_S;

/**
* @struct tagCamStreamStorQueryItem
* @brief �������ת�������������Ϣ��
* @attention ��
*/
typedef struct tagCamStreamStorQueryItem
{
    /** ��������� */
    CHAR  szCamCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** BM���� */
    CHAR  szBMCode[IMOS_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ������Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ռ������ ��MBΪ��λ */
    ULONG_32 ulCapacity;

    /** �Ƿ��Ѿ��ƶ���ת��ƻ�,#BOOL_TRUE��ʾ�ƶ���BOOL_FALSE��ʾδָ�� */
    BOOL_T bPlanFlag;

    /** ת��ƻ����� */
    CHAR szPlanCode[IMOS_CODE_LEN];

    /** ת��ƻ�״̬ */
    ULONG_32 ulPlanStatus;

    /** ��Դ������Ϣ��0�������������2����DVR��������������� */
    ULONG_32 ulResAttribute;

	/** ��Դ�Ƿ��������� */
    ULONG_32   ulIsForeign;

    /** �����ֶ� */
    CHAR  szReserve[28];
} CAM_STREAM_STOR_QUERY_ITEM_S;

 /**
 * @struct tagStreamStorBase
 * @brief ��ת��ƻ�������Ϣ
 * @attention
 */
typedef struct tagStreamStorBase
{
    /** ��ת��ƻ����룬���������� */
    CHAR    szStreamStorPlanCode[IMOS_CODE_LEN];

    /** ��ת��ƻ����� */
    CHAR    szStreamStorPlanName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /** ��������ƣ���ѯ�ƻ���Ϣʱ���� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** �û����� */
    CHAR    szUserCode[IMOS_CODE_LEN];

    /** �ƻ�����ʱ�� */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** �ƻ����ڣ�0-�ռƻ���1-�ܼƻ� */
    ULONG_32   ulPlanCycle;

    /** �Ƿ���洢(1 ��,0 ��) */
    BOOL_T  bIsDayStore;

    /** ����洢������ */
    ULONG_32   ulStoreDays;

    /** �ƻ�״̬#PLAN_OPER_MODE_E���޸ļƻ�ʱ���ֶ���Ч */
    ULONG_32   ulPlanStatus;
}STREAM_STOR_PLAN_BASE_S;

/**
 * @struct tagStreamStorPlan
 * @brief ��ת��ƻ���Ϣ
 * @attention
 */
typedef struct tagStreamStorPlan
{
    /** ��ת��ƻ�������Ϣ */
    STREAM_STOR_PLAN_BASE_S   stStreamStorPlanBasicInfo;

    /** ��ת��ƻ�ʱ����Ϣ����ʱ��ƻ� */
    PLAN_WEEKTIME_S   astPlanTime[IMOS_WEEK_DAYS];
}STREAM_STOR_PLAN_INFO_S;

/************************************************************************/
/* �澯����                                                             */
/************************************************************************/
/**
* @struct tagAlarmSendingRuleBaseInfo
* @brief �澯���Ĺ��������Ϣ
* @attention
*/
typedef struct tagAlarmSendingRuleBaseInfo
{
    /** ���� */
    CHAR                   szRuleCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR                   szRuleName[IMOS_NAME_LEN];

    /** �Ƿ�ϵͳԤ�������BOOL_TRUE��ʾϵͳԤ�������BOOL_FALSE��ϵͳԤ������� */
    BOOL_T                 bSystemRule;

    /** �澯���ࣺĿǰ��δʹ�ã���0 */
    ULONG_32                  ulEventCategory;

    /** �澯���𣺵�0λ��ʾ��������1λ��ʾ��Ҫ����2λ��ʾ��Ҫ����3λ��ʾ���棬��4λ��ʾ��ʾ */
    ULONG_32                  ulEventLevel;

    /** �澯���ͷ�ʽ����0λ��ʾUI����1λ��ʾEmail����2λ��ʾSMS, ��3λ��ʾ������ϵͳ���� */
    ULONG_32                  ulSendEventMode;
}ALARM_SENDING_RULE_BASE_INFO_S;

/**
* @struct tagAlarmSendingRuleThdSys
* @brief �澯���Ĺ��������ϵͳ������Ϣ
* @attention
*/
typedef struct tagAlarmSendingRuleThdSys
{
    /** ������ϵͳ���� */
    CHAR                    szThdSysCode[IMOS_CODE_LEN];

    /** ������ϵͳ���� */
    CHAR                    szThdSysName[IMOS_NAME_LEN];

    /** ������ϵͳ��ַ */
    CHAR                    szAddr[IMOS_IPADDR_LEN];

    /** ������ϵͳ�˿� */
    USHORT                  usPort;

    /** �����ֶ� */
    USHORT                  usReserved;

    /** Э������, �����#ALARM_SEND_TO_THD_SYS_PROC_TYPE_E */
    ULONG_32                   ulProcType;
}ALARM_SENDING_RULE_THD_SYS_S;

/**
* @struct tagAlarmSendingRule
* @brief �澯���Ĺ���
* @attention
*/
typedef struct tagAlarmSendingRule
{
    /** �澯���Ĺ��������Ϣ */
    ALARM_SENDING_RULE_BASE_INFO_S stBaseInfo;

    /** �澯Դ��Ŀ */
    ULONG_32                           ulAlarmSrcNum;

    /** �澯Դ�����б�, ��#IMOS_CODE_LENΪ��λ */
    CHAR                            *pcAlarmSrcList;

    /** ���ĸù���� �û��� */
    ULONG_32                           ulUserNum;

    /** �û��б�, ��#IMOS_CODE_LENΪ��λ */
    CHAR                            *pcUserList;

    /** ���ĸù���� ������ϵͳ�� */
    ULONG_32                           ulThdSysNum;

    /** ������ϵͳ�б� */
    ALARM_SENDING_RULE_THD_SYS_S    *pstThdList;
}ALARM_SENDING_RULE_S;

/**
* @struct tagSDKInit
* @brief SDK ��ʼ��ʱ�õĽṹ
*/
typedef struct tagSDKInit
{
    /** �������� */
    CHAR szProcName[IMOS_PROC_NAME_MAX_LEN];

    /** ����procID��IMOSϵͳ��ͳһ���䣬��ͬ���ͽ���ʹ����ͬ��procID�� */
    USHORT usProcID;

    /** �Ƿ�UI��ı�� */
    BOOL_T bUIFlag;

    /** �Ƿ����XP��� */
    BOOL_T bXPFlag;

    ULONG_32  ulSDKInitFlag;

    /** �ص�����ָ�� */
    SDK_CALL_BACK_PROC_PF pfnCallBackProc;

    /** �ص��������������ڻص���������θ�ֵ */
    VOID *pParam;

}SDK_INIT_S;

/**
* @struct tagPortRange
* @brief �˿ڷ�Χ
* @attention
*/
typedef struct tagPortRange
{
    /** �˿���ʼ��Χ */
    ULONG_32  ulPortBegin;

    /** �˿ڽ�����Χ */
    ULONG_32  ulPortEnd;

    /** Ϊ����Ԥ�� */
    ULONG_32 ulType;
}PORT_RANGE_S;

/**
* @struct tagUniversalPage
* @brief ͨ�÷�ҳ��Ϣ
* @attention
*/
typedef struct tagUniversalPage
{
    ULONG_32 ulFirstRow;               /**< ��ҳ�ӵڼ��п�ʼ��ѯ */
    ULONG_32 ulPageRowNum;             /**< ��ҳҪ��ѯ������ */
    BOOL_T bQueryCount;             /**< �Ƿ��ѯ������ */
    ULONG_32 ulActualRowCount;         /**< ʵ�ʷ��ص����� */
    ULONG_32 ulTotalRowCount;          /**< ���������������ܼ� */
}UNI_PAGE_S;
/**
* @struct tagUniversalLogicPiece
* @brief ͨ��Լ���߼���
* @attention
*/
typedef struct tagUniversalLogicPiece
{
    ULONG_32 ulPiece;                  /**< ������ */
    LOGIC_FLAG_E enLogic;           /**< �����߼�#LOGIC_FLAG_E */
    CHAR szValues[64];              /**< ����ֵ */
}UNI_LOGIC_PIECE_S;

/**
* @struct tagUniversalOrder
* @brief ͨ��������
* @attention
*/
typedef struct tagUniversalOrder
{
    ULONG_32 ulPiece;
    LOGIC_FLAG_E enLogic;           /**< �����ǽ���#LOGIC_FLAG_E */
}UNI_ORDER_S;
/**
* @struct tagUniversalConditon
* @brief ͨ��Լ������
* @attention
*/
typedef struct tagUniversalConditon
{
    ULONG_32 ulFlag;                                   /**< ��ѯ�߼���־λ#UNI_CONDITION_FLAG_E */
    ULONG_32 ulOrderNum;                               /**< ���������ĸ��� */
    UNI_ORDER_S *pstOrderPiece;                     /**< ������ */
    ULONG_32 ulANDCondNum;                             /**< ANDԼ�������ĸ��� */
    UNI_LOGIC_PIECE_S *pstANDCondtion;              /**< ANDԼ�������б� */
    ULONG_32 ulORCondNum;                              /**< ORԼ�������ĸ��� */
    UNI_LOGIC_PIECE_S *pstORCondtion;               /**< ORԼ�������б� */
}UNI_CONDITION_S;

/**
 * @struct tagOutChannelInfo
 * @brief ���ͨ����Ϣ
 * @attention
 */
typedef struct tagOutChannelInfo
{
    /** ���ͨ������,ȡֵΪ#OUT_CHANNEL_TYPE_E */
    ULONG_32 ulOutType;

    /** ���ͨ��ģʽ,ȡֵΪ#OUT_CHANNEL_MODE_E */
    ULONG_32 ulOutMode;
} OUT_CHANNEL_INFO_S;

/**
 * @struct tagOutChannelSplitScrInfo
 * @brief ���ͨ��������Ϣ
 * @attention
 */
typedef struct tagOutChannelSplitScrInfo
{
    /** ����ģʽ,ȡֵΪ#OUT_CHANNEL_MODE_E */
    ULONG_32 ulSplitScrMode;

    /** ��Ƶ���ͨ����(����ģʽΪ"ȫ��"ʱ��Ч) */
    ULONG_32 ulVideoOutChannelNo;

    /** �����ֶ� */
    CHAR szReserve[128];
} OUT_CHANNEL_SPLIT_SCR_INFO_S;

/**
 * @struct tagSplitScrInfo
 * @brief ������������Ϣ
 * @attention
 */
typedef struct tagSplitScrInfo
{
    /** ����ģʽ,ȡֵΪ#SPLIT_SCR_MODE_E */
    ULONG_32 ulSplitScrMode;

    /** ��������(ȫ��ʱ��Ч) */
    CHAR szSplitScrCode[IMOS_CODE_LEN];

    /** �Ƿ�"�Զ��л�������"(#BOOL_TRUE ��,#BOOL_FALSE ��) */
    BOOL_T bSwitchStream;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} SPLIT_SCR_INFO_S;

/*******************************************************************************
ECR33**-HF
********************************************************************************/

/**
 * @struct tagECRBasicInfo
 * @brief ECR,NVR������Ϣ
 * @attention
 */
typedef struct tagECRBasicInfo
{
    /** ECR,NVR�豸���� */
    CHAR    szECRCode[IMOS_ECR_CODE_LEN];

    /** ECR,NVR���� */
    CHAR    szECRName[IMOS_NAME_LEN];

    /** ��֯����� */
    CHAR    szOrgCode[IMOS_CODE_LEN];

    /** ECR�豸�ͺ�, ȡֵΪ#IMOS_DEVICE_TYPE_E�е�#IMOS_DT_ECR3308_HF, #IMOS_DT_ECR3316_HF #IMOS_DT_ECR3308_HF_E,
        #IMOS_DT_ECR3316_HF_E #IMOS_DT_ECR3308_HF_S, #IMOS_DT_ECR3316_HF_S, #IMOS_DT_ECR_MIN��#IMOS_DT_ECR_MAX,
        #IMOS_DT_ISC_MIN��#IMOS_DT_ISC_MAX.
        ������豸��������Ϊ#IMOS_DT_ISC_MINʱ��������豸ΪNVR */
    ULONG_32   ulECRDevType;

    /** IP��ַ����:IPV4ȡֵΪ#IMOS_IPADDR_TYPE_IPV4, IPV6ȡֵΪ#IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32   ulIPAddrType;

    /** IP��ַ */
    CHAR    szIPAddress[IMOS_IPADDR_LEN];

    /** ECR����״̬, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE. ���ڲ�ѯECR��Ϣ */
    ULONG_32   ulOnlineStatus;

    /** �������λ��ȡֵΪ#DOMAIN_STREAM_PULL_TYPE  */
    ULONG_32 ulIsSession;

    /* Begin: Added by mozhanfei(kf0149) ,2013-7-18 for ECR NVR���� */
    /** �豸���� */
    CHAR    szDevType[IMOS_STRING_LEN_64];
    /* End: Added by mozhanfei(kf0149), 2012-7-18 for ECR NVR���� */


    /** �����ֶ� */
    CHAR szReserve[252];

}ECR_BASIC_INFO_S;

/**
 * @struct tagECRCameraInfo
 * @brief ECR Camera�б��ѯ������Ϣ
 * @attention
 */
typedef struct tagECRCamInfo
{
    /** Camera����*/
    CHAR  szCameraCode[IMOS_CODE_LEN];

    /** Camera���� */
    CHAR  szCameraName[IMOS_NAME_LEN];

    /** �����ֶ� */
    CHAR szReserve[128];
}ECR_CAM_INFO_S;

/**
* @struct tagECRAlarmSrcInfo
* @brief ECR�澯Դ�б��ѯ���صĵ�Ԫ��Ϣ
*/
typedef struct tagECRAlarmSrcInfo
{
    /** �澯Դ����*/
    CHAR  szAlarmSrcCode[IMOS_CODE_LEN];

    /** �澯Դ���� */
    CHAR  szAlarmSrcName[IMOS_NAME_LEN];

    /** �����ֶ� */
    CHAR szReserve[128];

}ECR_ALARMSRC_INFO_S;

/**
 * @struct tagECRDeviceBasicInfo
 * @brief ECR�����豸������Ϣ
 * @attention
 */
typedef struct tagECRDeviceBasicInfo
{
    /** �Ƿ�֧���鲥, 1Ϊ֧��; 0Ϊ��֧�� */
    ULONG_32 ulIsMulticast;

    /** �澯ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnableAlarm;

    /** ���¸澯�¶�����, ȡֵΪ65~100 */
    LONG_32 lTemperatureMax;

    /** ���¸澯�¶�����, ȡֵΪ-100~49 */
    LONG_32 lTemperatureMin;

    /** ���ײ�, ȡֵΪ:#IMOS_STREAM_RELATION_SET_E,
        ĿǰECR֧�ֵ���:
        1��H264������(#IMOS_SR_H264_SHARE)
        11��H264+H264(#IMOS_SR_H264_H264)
    */
    ULONG_32 ulEncodeSet;

    /** ��ʽ, ȡֵΪ#IMOS_PICTURE_FORMAT_E, Ŀǰ��֧��#IMOS_PF_PAL */
    ULONG_32 ulStandard;

    /** ��Ƶ����Դ��ȡֵΪ#IMOS_AUDIO_INPUT_SOURCE_E, Ŀǰ��֧��#IMOS_AI_LR */
    ULONG_32 ulAudioinSource;

    /** ��ý���Э������,ȡֵΪ#IMOS_TRANS_TYPE_E��ĿǰECֻ֧��UDP��TCP */
    ULONG_32 ulStreamTransProtocol;

    /* Begin Added by chenyongfa for IVSD01065 2013.05.28 */
    /** ��Ƶ�����׼��ȡֵΪ#IMOS_ENCODE_STANDARD_E�� */
    ULONG_32 ulEncodeStandard;
    /* End Added by chenyongfa for IVSD01065 2013.05.28 */

    /** �����ֶ� */
    CHAR szReserve[504];
}ECR_DEVICE_BASIC_INFO_S;

/**
 * @struct tagECRVMServerInfo
 * @brief ECR�豸�ķ�������Ϣ
 * @attention
 */
typedef struct tagECRVMServerInfo
{
    /** ��������ַ����, 1-IPv4 2-IPv6 */
    ULONG_32   ulServerAddrType;

    /** ��������ַ */
    CHAR    szServerAddr[IMOS_IPADDR_LEN];

    /** ����������״̬, ָ��������ǰ���������ע���Ƿ�ɹ�, 1Ϊ�ɹ�; 0����2Ϊʧ��, ����ʱ��Ч, ���û���ѯ */
    ULONG_32   ulServerRegStatus;

    /** ����������ͨ��Э��, ȡֵΪ#INTERDOMAIN_PROTOCOL_TYPE_E, Ŀǰֻ֧��IMOS��׼ */
    ULONG_32   ulInterProtocolType;

    /** �����������������, ��Ҫ�ͷ��������õĻ��������һ��, Ŀǰֻ֧��IMOS��׼������� */
    CHAR    szInterDomainCode[IMOS_CODE_LEN];

    /** �������û�����, ��Ҫ�ͷ��������õĻ����û�����һ�� */
    CHAR    szInterUserCode[IMOS_CODE_LEN];

    /* Begin added by zhuhongyan 00342 2013-3-18 for IVSD01426�������������� */
    /** ��Ȩ���� */
    CHAR    szDigestRealm[IMOS_DOMAIN_NAME_LEN];

    /** ��Ȩ�û��� */
    CHAR    szDigestUser[IMOS_NAME_LEN];

    /** ��Ȩ���� */
    CHAR    szDigestPassword[IMOS_PASSWD_LEN];

    /** �������˿� */
    ULONG_32   ulServerPort;
    /* End added by zhuhongyan 00342 2013-3-18 for IVSD01426�������������� */

    /** �����ֶ� */
    CHAR    szReserve[364];
}ECR_VMSERVER_INFO_S;

/**
 * @struct tagECRServerMgrInfo
 * @brief ECR�豸������������Ϣ
 * @attention
 */
typedef struct tagECRServerMgrInfo
{
    /** ECR�豸����, ����Ψһ��ʶ */
    CHAR  szECRDevCode[IMOS_ECR_CODE_LEN];

    /** NVR�����û�����, ����Ψһ��ʶ��ECR��Ч��Ϊ0���� */
    CHAR  szECRInterUserCode[IMOS_CODE_LEN];

    /** ECR�豸����, ���ڱ�ʾECR�����豸, ������IPC�� */
    CHAR  szECRDevName[IMOS_NAME_LEN];

    /** ����������ģʽ����, ȡֵΪ#ECR_SERVER_MODE_TYPE_E */
    ULONG_32 ulServerModeType;

    /** ��������Ϣ, ��Ϊ��������ģʽʱ������д */
    ECR_VMSERVER_INFO_S stVMserverInfo;

    /** �����ֶ� */
    CHAR szReserve[64];
}ECR_SERVER_MGR_INFO_S;

/**
 * @struct tagRevStrategyInfo
 * @brief ��ռ������Ϣ�ṹ
 * @attention
 */
typedef struct tagRevStrategyInfo
{
    /** ��ռҵ������, ȡֵΪ# REAVE_SRV_TYPE_E  */
    ULONG_32 ulRevSrvType;

    /** ��ռ��������, ȡֵΪ# REAVE_STRATEGY_E */
    ULONG_32 ulRevStrategy;
}REV_STRATEGY_INFO_S;

/**
 * @struct tagSrvRevStrategy
 * @brief ҵ����ռ���Խṹ
 * @attention
 */
typedef struct tagSrvRevStrategy
{
    /** ��ռ�����������ֵ���ܳ���REV_SRV_MAX */
    ULONG_32 ulRevStrategyNum;

    /** ��ռ������Ϣ*/
    REV_STRATEGY_INFO_S astRevStrategyInfo[REV_SRV_MAX];
}SRV_REV_STRATEGY_S;

/**
* @struct tagCSVodReaveNotify
* @brief SOI �طű���ռ��Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSVodReaveNotify
{
    CHAR    szSessionId[IMOS_SSN_ID_LEN];        /* �ط�ҵ��ỰID�����������ʱ���ص�SessionIdƥ�� */
    CHAR    szUserName[IMOS_NAME_LEN];           /* ��ռ�������û��� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];    /* ��ռ�����û��ĵ�¼IP */
}CS_VOD_REAVE_NOTIFY_S;
/**
 * @struct tagSceneUnit
 * @brief ������Ԫ��Ϣ
 * @attention
 */
typedef struct tagSceneUnit
{
    /** ��������� */
    CHAR        szCamCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** ��������ͣ���ѯʱ��Ч */
    ULONG_32       ulCamType;

    /** ��̨Ԥ��λ */
    ULONG_32       ulPresetValue;

    /** ����:���� */
    ULONG_32       ulParam1;

    /** ����:���� */
    CHAR        szParam2[IMOS_STRING_LEN_128];

    /** ����:���� */
    CHAR        szParam3[IMOS_STRING_LEN_128];
}SCENE_UNIT_S;

/**
 * @struct tagSceneInfo
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagSceneInfo
{
    /** ����������ͣ�ĿǰΪ�����ֶ� */
    ULONG_32       ulSceneType;

    /** ������ر��� */
    CHAR        szSceneCode[IMOS_CODE_LEN];

    /** ����������� */
    CHAR        szSceneName[IMOS_NAME_LEN];

    /** ������ذ����ĵ�Ԫʵ������, ���ֵΪ#IMOS_DISPLAY_MAXNUM_PER_SALVO */
    ULONG_32       ulSceneUnitNum;

    /** ����ʾ��Ԫ���� */
    SCENE_UNIT_S astSceneUnitList[IMOS_SCENE_MAXNUM_RES];
}SCENE_INFO_S;

/**
* @struct tagSceneQueryItem
* @brief ������Ϣ��(��ѯ�����б�ʱ����)
* @attention
*/
typedef struct tagSceneQueryItem
{
    /** ������ر��� */
    CHAR        szSceneCode[IMOS_CODE_LEN];

    /** ����������� */
    CHAR        szSceneName[IMOS_NAME_LEN];

    /** ������֯�����,���ڲ�ѯ���Լ������µ�����ʾ�б�ƽ̨���ز������ֵ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������ذ����ĵ�Ԫʵ������, ���ֵΪ#IMOS_DISPLAY_MAXNUM_PER_SCENE */
    ULONG_32       ulSceneUnitNum;

}SCENE_QUERY_ITEM_S;

/**
 * @struct tagShareSceneBase
 * @brief ������������Ϣ
 * @attention
 */
typedef struct tagShareSceneBase
{
     /** �������� */
    CHAR szSceneCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR szSceneName[IMOS_NAME_LEN];

    /** ����֯�ڵ���� */
    CHAR szParentOrgCode[IMOS_CODE_LEN];

    /** �������������ʱ�Ķ������ */
    CHAR szSceneShareCode[IMOS_CODE_LEN];

 }SHARE_SCENE_BASE_S;

/**
* @struct tagShareMapInfo
* @brief ��������Ϣ
*/
typedef struct tagShareSceneInfo
{
    /** ��������������룬����Ϊ��������ʱʹ�� */
    CHAR                szExDomainCode[IMOS_CODE_LEN];

    /** �Ƿ��ѹ��������1��ʾ�ǣ�0��ʾ�� */
    BOOL_T              bIsShared;

    /** ������������Ϣ */
    SHARE_SCENE_BASE_S    stShareSceneBaseInfo;

}SHARE_SCENE_INFO_S;

/**
* @struct tagEmailSendingConfig
* @brief �ʼ�������ص�����
* @attention
*/
typedef struct tagEmailSendingConfig
{
    /** �ʼ��ķ����� */
    CHAR    szSenderName[IMOS_NAME_LEN];

    /** �û������ʼ� */
    CHAR    szEmail[IMOS_MAIL_LEN];

    /** SMTP�ʼ���������ַ */
    CHAR    szSMTPMailServer[IMOS_URL_LEN];

    /** SMTP�ʼ��������˿� */
    ULONG_32   ulPortNum;

    /** SMTP�ʼ��������Ƿ�Ҫ����֤ */
    BOOL_T  bRequireAuthentication;

    /** ��֤ʹ�õ��û��� */
    CHAR    szUserName[IMOS_NAME_LEN];

    /** ��֤ʹ�õ����� */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** ����Ⱥ����������� */
    ULONG_32   ulEmailSenderGroupNum;
} EMAIL_SENDING_CONFIG_S;

/**
* @struct tagSMSSendingConfig
* @brief ����ҵ������������Ϣ
* @attention
*/
typedef struct tagSMSSendingConfig
{
    /** IP��ַ����:IPV4ȡֵΪ#IMOS_IPADDR_TYPE_IPV4, IPV6ȡֵΪ#IMOS_IPADDR_TYPE_IPV6 */
    ULONG_32   ulIPAddrType;

    /** ���ŷ�����IP��ַ */
    CHAR    szIPAddress[IMOS_IPADDR_LEN];

    /** ���ŷ������˿� */
    USHORT  usServerPort;

    /** ����λ, �����ֽڶ���, ��ʵ�ʺ��� */
    CHAR    acReserved[2];
}SMS_SENDING_CONFIG_S;

/**
* @struct tagSMSTestSendingConfig
* @brief ���Ų��Է��͵��������
* @attention
*/
typedef struct tagSMSTestSendingConfig
{
    /** ����ҵ������������Ϣ */
    SMS_SENDING_CONFIG_S  stSMSSendingConfig;

    /** �������ֻ����� */
    CHAR  szSMSRecvMobilePhone[IMOS_MOBILE_LEN];

} SMS_TEST_SENDING_CONFIG_S;

/**
* @struct tagAssetInfo
* @brief �ʲ���Ϣ�ṹ
* @attention
*/
typedef struct tagAssetInfo
{
    /** �ʲ���� */
    CHAR    szAssetCode[IMOS_CODE_LEN];

    /** �ʲ����� */
    CHAR    szAssetName[IMOS_NAME_LEN];

    /** �ʲ����ͣ�ȡֵΪ#ASSET_TYPE_E */
    ULONG_32   ulAssetType;

    /** �ʲ�״̬��ȡֵΪ#ASSET_STATUS_E */
    ULONG_32   ulAssetStatus;

    /** �ʲ������豸���� */
    CHAR    szDevCode[IMOS_CODE_LEN];

    /** �ʲ������豸���� */
    CHAR    szDevName[IMOS_NAME_LEN];

    /** �ʲ�ֱ����֯���� */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** �ʲ�ֱ����֯���� */
    CHAR    szParOrgName[IMOS_NAME_LEN];

    /** �ʲ��ͺ� */
    CHAR    szAssetModel[IMOS_NAME_LEN];

    /** �ʲ����� */
    CHAR    szManufacturer[IMOS_NAME_LEN];

    /** �ʲ�IP */
    CHAR    szIpAddress[IMOS_IPADDR_LEN];

    /** ����ʱ�� */
    CHAR    szPurchaseTime[IMOS_TIME_LEN];

    /** ��װʱ�� */
    CHAR    szInstallTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR    szWarrantTime[IMOS_TIME_LEN];

    /** ������ */
    CHAR    szProdealer[IMOS_NAME_LEN];

    /** ��װ�ص� */
    CHAR    szLocation[IMOS_NAME_LEN];

    /** MAC��ַ */
    CHAR    szMacAddr[IMOS_MAC_ADDR_LEN];

    /** ά���� */
    CHAR    szMPerson[IMOS_NAME_LEN];

    /** ά����ϵ�绰 */
    CHAR    szTelephone[IMOS_PHONE_LEN];

    /** ���Ŀ�� */
    CHAR    szTarget[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szLongitude[IMOS_STRING_LEN_32];

    /** γ�� */
    CHAR    szLatitude[IMOS_STRING_LEN_32];

    /** ���� */
    CHAR    szaltitude[IMOS_STRING_LEN_32];
}ASSET_INFO_S;

/**
* @struct tagAssetStatistic
* @brief �ʲ�ͳ��(��ѯ�ʲ�ͳ�Ƶ�ʱ�򷵻�)
* @attention
*/
typedef struct tagAssetStatistic
{
    /** ������Ŀ(����)�����ʲ�����(ȡֵ�μ�#ASSET_TYPE_E )����ͳ��ʱʹ�� */
    ULONG_32  ulCatalog;

    /** ������Ŀ(�ַ���)�����ʲ��ͺŷ���ͳ��ʱʹ�� */
    CHAR  szCatalog[IMOS_STRING_LEN_64];

    /** ���� */
    ULONG_32  ulTotalNum;

    /** �������� */
    ULONG_32  ulNormalNum;

    /** ���ϸ��� */
    ULONG_32  ulFaultNum;

    /** ά�޸��� */
    ULONG_32  ulMaintenanceNum;

    /** ���ϸ��� */
    ULONG_32  ulRetirementNum;

    /** ������ */
    ULONG_32  ulStockNum;

    /** ����װ���� */
    ULONG_32  ulToInstallNum;

    /** �Ѱ�װ���� */
    ULONG_32  ulInstalledNum;

    /** �ѵ��Ը��� */
    ULONG_32  ulDebuggedNum;
}ASSET_STATISTIC_S;

/**
* @struct tagFaultDevInfo
* @brief �����豸��Ϣ(��ѯ�����豸�б��ʱ�򷵻�)
* @attention
*/
typedef struct tagFaultDevInfo
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸ֱ����֯���� */
    CHAR  szParOrgCode[IMOS_CODE_LEN];

    /** �豸ֱ����֯���� */
    CHAR  szParOrgName[IMOS_NAME_LEN];

    /** �豸���� */
    ULONG_32  ulDevType;

    /** �豸�ͺ� */
    CHAR  szDevModel[IMOS_NAME_LEN];

    /** �豸����״̬��ȡֵΪ#IMOS_DEV_FAULT_STATUS_E */
    ULONG_32  ulDevStatus;

    /** �豸IP��ַ */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** ����ʱ�� */
    CHAR szFaultTime[IMOS_TIME_LEN];
}FAULT_DEV_INFO_S;


/**
* @struct tagFaultStatistic
* @brief ����ͳ��(��ѯ����ͳ�Ƶ�ʱ�򷵻�)
* @attention
*/
typedef struct tagFaultStatistic
{
    /** �豸���ͣ�ȡֵ�μ�#IMOS_TYPE_E */
    ULONG_32  ulDevType;

    /** ���� */
    ULONG_32  ulTotalNum;

    /** ���ϸ��� */
    ULONG_32  ulFaultNum;

    /** ����ʱ�� */
    CHAR szFaultTime[IMOS_TIME_LEN];
}FAULT_STATISTIC_S;

/**
 * @struct tagSThirdpartyEC
 * @brief ������EC��Ϣ
 * @attention
 */
typedef struct tagThirdpartyEC
{
    /* �����������Ϣ */
    CAMERA_INFO_S  stBaseCameraInfo;

    /* ��������, 0 onvif1.0 1 onvif2.0 2 onvif2.1  9 ����*/
    ULONG_32  ulCameraManutype;

    /*�豸��ַ*/
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /*�豸�˿�*/
    ULONG_32  ulDevPort;

    /* �������ͣ�0 ����ģ������� 1 IPC   */
    ULONG_32  ulCameraAccessType;

    /* �û��� */
    CHAR szUserName[IMOS_NAME_LEN];

    /* ���� */
    CHAR szPassword[IMOS_PASSWD_LEN];

    /* ���DVRͨ��ID,���� */
    ULONG_32 ulCameraChnId;

    /* IPC״̬��1��ʾ���ߣ�0��ʾ���� */
    ULONG_32 ulStatus;

    /* �鲥��ַ */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /* �鲥�˿�, ��ΧΪ: 10002-65534, �ұ���Ϊż�� */
    ULONG_32   ulMulticastPort;

    /* IPC������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /* MSѡ�����Ӧ����, 1Ϊ����Ӧ; 0Ϊָ��MS, 2Ϊ������MS, ȡֵΪ#IMOS_STREAM_SERVER_MODE_E */
    ULONG_32 ulIsAutofit;

    /* ʹ��MS��Ŀ, ��ʵ���������, ����Ӧ����#ulIsAutofitΪ����Ӧ, ��ֵΪ0; ����Ӧ����#ulIsAutofitΪ������Ӧ(��ָ��), ��ֵΪ1 */
    ULONG_32 ulUseMSNum;

    /* MS�����б� */
    CHAR szMSCode[IMOS_MS_MAX_NUM_PER_CHANNEL][IMOS_DEVICE_CODE_LEN];

    /* ���ֱ��ý������Ŀ */
    ULONG_32 ulMaxStreamNum;

    /* �澯ʹ�� */
    BOOL_T bAlarmEnabled;

    /* ����(�û�����ONVIF���ʣ��������·��豸��������Ҫ�û����óɺ��豸һ�µ����ʣ���Ҫ����������ô洢����) */
    ULONG_32 ulFakeBitRate;

    /* ʹ��Э�����ͣ�0: UDP 1:TCP */
    ULONG_32 ulProtocalType;

    /* �����Ȩʹ�� */
    ULONG_32 ulNoAuthenticationEnabled;

    /* ʱ��ͬ��ʹ�� */
    BOOL_T bTimeSyncEnabled;

    /* �����ֶ� */
    CHAR szReserve[20];
}THIRDPARTY_EC_S;
/**
 * @struct tagCamStoreBasicQueryItem
 * @brief ������洢��ػ�����Ϣ��(��ѯ�洢�豸��������б�ʱ����)
 * @attention
 */
typedef struct tagCamStoreBasicQueryItem
{
    /** ��������� */
    CHAR        szCamName[IMOS_NAME_LEN];

    /** ��������� */
    CHAR        szCamCode[IMOS_CODE_LEN];

    /** ���������(��̨���̶�)#CAMERA_TYPE_E */
    ULONG_32       ulCamType;

    /** �洢����(ֱ��,ת��)#STORE_CONFIG_TYPE_E */
    ULONG_32       ulStoreType;

    /** �洢�����豸����(ֱ��Ĵ洢�����豸Ϊ�洢�豸,ת��Ĵ洢�����豸Ϊ�洢��Դ����BM����) */
    CHAR        szStoreCfgDevCode[IMOS_CODE_LEN];

    /** �Ƿ��ƶ�ֱ���ת��ƻ�, #BOOL_TRUEΪ�ƶ�, #BOOL_FALSEΪδ�ƶ� */
    BOOL_T      bHasStorePlan;

    /** ֱ���ת��ƻ����� */
    CHAR        szStorePlanCode[IMOS_CODE_LEN];

    /** �ƻ�״̬, #BOOL_TRUEΪ�ƻ�����, #BOOL_FALSEΪ�ƻ�δ���� */
    BOOL_T      bPlanStatus;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
}CAM_STORE_BASIC_QUERY_ITEM_S;

/**
 * @struct tagASDomainSynPushUI
 * @brief ���ͬ��������͸�UI
 * @attention
 */
typedef struct tagASDomainSynPushUI
{
    /** ����������*/
    ULONG_32 ulErrorCode;
    /** ��Ϣ��ҵ������#DOMAIN_SYN_SRVTYPE_E*/
    ULONG_32 ulServiceType;
    /** Ŀ����*/
    CHAR  szDomainCode[IMOS_CODE_LEN];
    /** ʵ������*/
    ULONG_32 ulServiceNum;
}AS_DOMAIN_SYN_PUSHUI_S;

/**
 * @struct tagTopologyServiceInfo
 * @brief VM�ļ������ҵ����Ϣ
 * @attention
 */
typedef struct tagTopologyServiceInfo
{
    /*�������������ʵ������*/
    ULONG_32 ulServiceMonitorNum;
}TOPOLOGY_SERVICE_INFO_S;

typedef struct tagTopologySrvDomain
{
    /** �û���¼��Ϣ */
    USER_LOGIN_ID_INFO_S stUserLogIDInfo;

    /** ����� */
    CHAR szParentDomainCode[IMOS_CODE_LEN];

    /** ����� */
    CHAR szSubDomainCode[IMOS_CODE_LEN];
}TOPOLOGY_SRV_DOMAIN_S;

/**
* @struct tagIMOSSystemParamInfo
* @brief ϵͳ������Ϣ
* @attention
*/
typedef struct tagIMOSSystemParamInfo
{
    /** ϵͳ�������ͣ�ȡֵΪ#IMOS_SYS_PARAM_TYPE_E */
    ULONG_32  ulSysParamType;

    /** ϵͳ����ֵ */
    CHAR  szSysParamValue[IMOS_SYS_PARAM_LEN];

    /** ϵͳ���������ֶ� */
    CHAR szReserv[64];
}IMOS_SYS_PARAM_INFO_S;

/**
* @struct tagSyncServiceInfo
* @brief ͬ��ҵ����Ϣ
* @attention
*/
typedef struct tagSyncServiceInfo
{
    /** ͬ��ҵ�����ͣ�ȡֵ�μ�#SYNCSRV_TYPE_E */
    ULONG_32  ulSyncSrvType;

    /** ͬ��ģʽ��ȡֵ�μ�#SYNCSRV_MODE_E */
    ULONG_32  ulSyncMode;

}SYNC_SERVICE_INFO;

/**
 * @struct tagGuardPositionInfo
 * @brief ����λ��Ϣ
 * @attention
 */
typedef struct tagGuardPositionInfo
{
    /** ����λ�����趨��Ԥ��λ�ı�����Ӧ */
    ULONG_32   ulGuardPosition;

    /** �Զ�����ʱ��, ��λΪ��, ��󲻳���3600��, 0��ʾ������ */
    ULONG_32   ulAutoGuard;
 }GUARD_POSITION_INFO_S;
/**
* @struct tagDevFaultDetailStatistic
* @brief �豸 ������ϸ��Ϣͳ��
* @attention
*/
typedef struct tagDevFaultDetailStatistic
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸���� */
    ULONG_32  ulDevType;

    /** �豸�ͺ� */
    CHAR  szDevModel[IMOS_NAME_LEN];

    /** �豸IP��ַ */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** ����ʱ��(��λ����) */
    ULONG_32 ulFaultInterval;

    /** ���ϴ��� */
    ULONG_32 ulFaultCount;

    /** �豸ֱ������֯���� */
    CHAR szParentCode[IMOS_CODE_LEN];

    /** �豸ֱ������֯���� */
    CHAR szParentName[IMOS_NAME_LEN];
}DEV_FAULT_DETAIL_STAT_S;

/**
* @struct tagDevFaultDetail
* @brief �豸������ϸ��Ϣ
* @attention
*/
typedef struct tagDevFaultDetail
{
    /** �豸���� */
    CHAR  szDevCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸���� */
    ULONG_32  ulDevType;

    /** �豸�ͺ� */
    CHAR  szDevModel[IMOS_NAME_LEN];

    /** �豸����״̬��ȡֵΪ#IMOS_DEV_FAULT_STATUS_E */
    ULONG_32  ulDevStatus;

    /** �豸IP��ַ */
    CHAR szIPAddr[IMOS_IPADDR_LEN];

    /** ����ʱ�� */
    CHAR szFaultTime[IMOS_TIME_LEN];

    /** ���ϻָ�ʱ�� */
    CHAR szRecoverTime[IMOS_TIME_LEN];

    /** ����ʱ��(��λ����) */
    ULONG_32 ulFaultInterval;

    /** �豸ֱ������֯���� */
    CHAR szParentCode[IMOS_CODE_LEN];

    /** �豸ֱ������֯���� */
    CHAR szParentName[IMOS_NAME_LEN];
}DEV_FAULT_DETAIL_S;

/**
 * @struct tagTimeSlice
 * @brief ����ʱ��Ƭ��Ϣ
 * @attention 00:00:00~23:59:59��ʾһ�����ʱ��Ƭ
 */
typedef struct tagQueryTimeSlice
{
    /* �Ƿ���Ҫ����ʱ��Ƭɸѡ */
    BOOL_T bIsNeed;

    /** ��ʼʱ�� ��ʽΪ"hh:mm:ss" */
    CHAR        szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� ��ʽΪ"hh:mm:ss" */
    CHAR        szEndTime[IMOS_TIME_LEN];
}QUERY_TIME_SLICE_S;

/**
* @union tagVocDstInfo
* @brief ����Ŀ�����Ͻṹ
* @attention ��
*/
typedef union tagVocDstInfo
{
    /** Ŀ���û���Ϣ */
    USER_LOGIN_ID_INFO_S stDstUserInfo;

    /** Ŀ����������� */
    CHAR szCameraCode[IMOS_CODE_LEN];
}VOC_DST_INFO_U;

/**
* @struct tagVocSrvDstInfo
* @brief ����ҵ��Ŀ����Ϣ�ṹ
* @attention ��
*/
typedef struct tagVocSrvDstInfo
{
     /** Ŀ�����ͣ���μ�IMOS_TYPE_E */
     ULONG_32  ulDstType;

     /** Ŀ�ı����й���Ϣ */
     VOC_DST_INFO_U unDstInfo;
}VOC_SRV_DST_INFO_S;

/**
* @struct tagVocSrvRecordInfo
* @brief ����ҵ���¼��Ϣ�ṹ
* @attention ��
*/
typedef struct tagVocSrvRecordInfo
{
     /** Ŀ����Ϣ */
     VOC_SRV_DST_INFO_S  stDstInfo;

     /** Ŀ������ */
     CHAR   szDstName[IMOS_NAME_LEN];

     /** Ŀ���Ƿ������з� */
     BOOL_T bCaller;

     /** ����ҵ���������к� */
     ULONG_32  ulReqSeq;

     /** ����ҵ�����ͣ���μ�SRV_TYPE_E */
     ULONG_32  ulVocSrvType;

     /** ����ҵ��״̬����μ�VOCSRV_STATUS_E */
     ULONG_32  ulVocSrvState;

     /** ����ҵ�������� */
     ULONG_32  ulVocOperResult;

}VOCSRV_RECORD_INFO_S;

/**
* @struct tagCSVocReqNotify
* @brief SOI ����ҵ������֪ͨ��Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSVocReqNotify
{
    BOOL_T  bNewReq;                     /* �Ƿ����½�����֪ͨ */
    ULONG_32   ulReqSequence;               /* �������к� */
    ULONG_32   ulVocType;                   /* ����ҵ������, ֵ�����SRV_TYPE_E */
    USER_LOGIN_ID_INFO_S  stCallerInfo;  /* �����û���Ϣ */
    CHAR    szCallerName[IMOS_NAME_LEN]; /* �����û����� */
}CS_VOC_REQ_NOTIFY_S;

/**
* @struct tagCSVocStateNotify
* @brief SOI ����ҵ��״̬ͬ־��Ϣ�ṹ
* @attention ��
*/
typedef struct tagCSVocStateNotify
{
    ULONG_32   ulEventType;                               /* �¼��������ͣ�ö��ֵΪ:VOC_EVENT_TYPE_E */
    ULONG_32   ulTroubleCode;                             /* �쳣�¼���ϸ�����룬����������뺬�� */
    CHAR    szCreatUserName[IMOS_NAME_LEN];            /* �����¼����û������� */
    CHAR    szCreatUserIpAddress[IMOS_IPADDR_LEN];     /* �����¼����û��ĵ�¼IP */
    CHAR    szCreatUserLoginCode[IMOS_CODE_LEN];       /* �����¼����û��ĵ�¼ID */

    ULONG_32   ulOrgSrvType;                              /* �¼�����ǰԭ��ҵ�����ͣ�ö��ֵΪ:SRV_TYPE_E */
    CHAR    szOrgDstCode[IMOS_CODE_LEN];               /* ԭҵ������������ */
    CHAR    szOrgDstName[IMOS_NAME_LEN];               /* ԭҵ����������� */
    CHAR    szOrgDstDomainCode[IMOS_CODE_LEN];         /* ԭҵ������������������ */
    CHAR    szOrgDstDomainName[IMOS_NAME_LEN];         /* ԭҵ����������������� */

    ULONG_32   ulCurSrvType;                              /* �¼��������ҵ�����ͣ�ö��ֵΪ:SRV_TYPE_E */
    CHAR    szCurDstCode[IMOS_CODE_LEN];               /* ��ҵ������������ */
    CHAR    szCurDstName[IMOS_NAME_LEN];               /* ��ҵ����������� */
    CHAR    szCurDstDomainCode[IMOS_CODE_LEN];         /* ��ҵ������������������ */
    CHAR    szCurDstDomainName[IMOS_NAME_LEN];         /* ��ҵ����������������� */
}CS_VOC_STATE_NOTIFY_S;

/**
* @struct tagQueryResRequestInfo
* @brief ��Դ��ѯ������Ϣ�ṹ��
* @attention
*/
typedef struct tagQueryResRequestInfo
{
    /** ��Դ���� */
    CHAR                    szResCode[IMOS_CODE_LEN];

    /** ��Դ����,ȡֵ��ΧΪ#IMOS_TYPE_E */
    ULONG_32                   ulResType;
}QUERY_RES_REQUEST_INFO_S;

/**
 * @struct tagShareResBase
 * @brief ������Դ������Ϣ
 * @attention
 */
typedef union tagShareResBase
{
    /** ������֯������Ϣ */
    SHARE_ORG_BASE_S  stOrgShareInfo;

    /** ���������������Ϣ */
    SHARE_CAMERA_BASE_V2_S stCamShareInfo;

    /** ����澯Դ������Ϣ */
    SHARE_ALARMSRC_BASE_S stAlaramSrcShareInfo;

    /** �����ͼ������Ϣ */
    SHARE_MAP_BASE_S    stMapShareInfo;

    /** ������������Ϣ */
    SHARE_SCENE_BASE_S   stShareSceneInfo;
} SHARE_RES_BASE_U;

/**
* @struct tagResShareInRecordInfo
* @brief ��Դ����������(IN)�ṹ��
* @attention
* 1.���Ǳ�����Դ����д�������ƺͱ���
*/
typedef struct tagResShareInRecordInfo
{
    /** ��Դ���������� */
    CHAR                    szResDomainName[IMOS_NAME_LEN];

    /** ��Դ��������� */
    CHAR                    szResDomainCode[IMOS_CODE_LEN];
}RES_SHARE_IN_RECORD_INFO_S;

/**
* @struct tagResShareOutRecordInfo
* @brief ��Դ��������(OUT)�ṹ��
*/
typedef struct tagResShareOutRecordInfo
{
    /** ������Դ������Ϣ */
    SHARE_RES_BASE_U        unShareResBaseInfo;

    /** ��Դ������(OUT)���� */
    CHAR                    szDomainName[IMOS_NAME_LEN];

    /** ��Դ������(OUT)���� */
    CHAR                    szDomainCode[IMOS_CODE_LEN];

    /** ��������(ֻ������:�ϼ���/ƽ����), ȡֵΪ#EX_DOMAIN_TYPE_E */
    ULONG_32   ulOuterDomainType;

    /** �����ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32   uladdrtype;

    /** �����ַ */
    CHAR    szDomainAddr[IMOS_IPADDR_LEN];

    /** ��������
        ���ڷ�OEM�汾(VM8500��H3C�豸),ȡֵΪ
            #IMOS_MANUFACTURER_TYPE_VMISC
            #IMOS_MANUFACTURER_TYPE_DA
            #IMOS_MANUFACTURER_TYPE_OTHER
        ����OEM�汾(PL/PL-S),ȡֵΪ
            #IMOS_MANUFACTURER_TYPE_PL
            #IMOS_MANUFACTURER_TYPE_PLS
            #IMOS_MANUFACTURER_TYPE_OTHER */
    CHAR szManufacturerType[IMOS_STRING_LEN_64];

    /** �����е���ȼ�����Ч��ΧΪ1��7 */
    ULONG_32 ulDomainLevel;

    /** ���ͨѶЭ�����ͣ�ȡֵΪ#INTERDOMAIN_PROTOCOL_TYPE_E */
    ULONG_32 ulProtocolType;

    /** ����ע��״̬��ָ������ǰ�������ע���Ƿ�ɹ�, 1Ϊ�ɹ�; 2Ϊʧ�� */
    ULONG_32                     ulActiveRegSta;

    /** ����ע��״̬��ָ��ǰ�����������ע���Ƿ�ɹ�, 1Ϊ�ɹ�; 2Ϊʧ�� */
    ULONG_32                     ulRecvRegSta;

    /** �����ֶ� */
    CHAR szReserve[128];
}RES_SHARE_OUT_RECORD_INFO_S;

/**
* @struct tagAlarmRecordInfo
* @brief �澯��¼
* @attention
*/
typedef struct tagAlarmRecordInfo
{
    /** �澯���� */
    CHAR szEventCode[IMOS_CODE_LEN];

    /** �澯��¼���ͣ�ȡֵΪ#ALARM_RECORD_TYPE_E */
    ULONG_32 ulAlarmRecordType;

    /** ִ���û����� */
    CHAR szExecuteUserName[IMOS_NAME_LEN];

    /** ִ��ʱ�� */
    CHAR szExecuteTime[IMOS_TIME_LEN];

    /** �û�IP��ַ */
    CHAR szUserAddr[IMOS_IPADDR_LEN];

    /** ��¼���� */
    CHAR szExecuteDesc[IMOS_STRING_LEN_512];

    /** �¸澯���룬Ϊ�ձ�ʾ���ǲ����¸澯���¸澯û�и澯�����¼ */
    CHAR szNewEventRecordCode[IMOS_CODE_LEN];
}ALARM_RECORD_INFO_S;

/**
* @struct tagEndTaskBase
* @brief �������������Ϣ
* @attention
*/
typedef struct tagEndTaskBase
{
    /** ������ţ�Ϊ0��ʾ������������ */
    ULONG_32 ulTaskSequence;

    /** ������ */
    CHAR  szTaskName[IMOS_NAME_LEN];
}END_TASK_BASE_S;

/**
* @struct tagEndTaskAction
* @brief ��������������
* @attention
*/
typedef struct tagEndTaskAction
{
    /** ������Ŀ */
    ULONG_32 ulEndTaskNum;

    /** �������������Ϣ */
    END_TASK_BASE_S astEndTaskBase[IMOS_MAX_TASK_NUM];
}END_TASK_ACTION_S;

/**
* @struct tagStartTaskBase
* @brief �������������Ϣ
* @attention
*/
typedef struct tagStartTaskBase
{
    /** ������� */
    ULONG_32 ulTaskSequence;

    /** ������ */
    CHAR  szTaskName[IMOS_NAME_LEN];

    /** �ȴ�ʱ�����������������λ:�룩*/
    ULONG_32 ulTime;
}START_TASK_BASE_S;

/**
* @struct tagStartTaskAction
* @brief ��������������
* @attention
*/
typedef struct tagStartTaskAction
{
    /** ������Ŀ */
    ULONG_32 ulStartTaskNum;

    /** �������������Ϣ */
    START_TASK_BASE_S astStartTaskBase[IMOS_MAX_TASK_NUM];
}START_TASK_ACTION_S;

/**
* @struct tagTranAlarmAction
* @brief ����ת��ԭ�澯
* @attention
*/
typedef struct tagTranAlarmAction
{
    /** ת���û���Ŀ */
    ULONG_32 ulTranUserNum;

    /** ת���û���Ϣ(����ʱ�û�������Ч��������Ч����ѯʱ�û���¼ID���û���¼��ַ���û���½ʱ�䡢�û��Ƿ�������Ч��������Ч) */
    USER_QUERY_ITEM_S astTranUserInfo[IMOS_ALARM_ACTION_TRAN_MAXNUM];
}TRAN_ALARM_ACTION_S;

/**
* @struct tagCreateNewAlarmAction
* @brief ���������¸澯
* @attention
*/
typedef struct tagCreateNewAlarmAction
{
     /** �¸澯��Ŀ */
    ULONG_32 ulNewAlarmNum;

    /** �¸澯��Ϣ */
    EVENT_TYPE_INFO_S astNewAlarmBase[IMOS_MAX_NEW_ALARM_NUM];
}CREATE_NEW_ALARM_ACTION_S;

/**
* @struct tagPlanAction
* @brief Ԥ��������������
* @attention
*/
typedef struct tagPlanAction
{
    /** ������������ */
    END_TASK_ACTION_S           stEndTaskAction;

    /** ������������ */
    START_TASK_ACTION_S         stStartTaskAction;

    /** ת��ԭ�澯 */
    TRAN_ALARM_ACTION_S         stTranAlarmAction;

    /** �����¸澯 */
    CREATE_NEW_ALARM_ACTION_S   stCreateNewAlarmAction;
}TASK_ACTION_S;

/**
* @struct tagTaskActionInfo
* @brief ��������
* @attention
*/
typedef struct tagTaskActionInfo
{
    /** �澯�������� */
    ALARM_ACTION_S stNormalAlarmAction;

    /** Ԥ�������еĶ��� */
    TASK_ACTION_S stPlanAction;
}TASK_ACTION_INFO_S;

/**
* @struct tagTaskTriggerInfo
* @brief �������ṹ
* @attention
*/
typedef struct tagTaskTriggerInfo
{
    /** ������ID��ȡֵΪ#TRIGGER_ID_E */
    ULONG_32 ulTriggerID;

    /** ���������� */
    CHAR szTriggerName[IMOS_NAME_LEN];

    /** �������������� */
    ULONG_32 ulParamNum;

    /** ��������������(��Ӣ��;�ָ�*/
    CHAR szParamName[IMOS_DESC_LEN];

    /** ����������ֵ(��Ӣ��;�ָ� */
    CHAR szParamValue[IMOS_DESC_LEN];
}TASK_TRIGGER_INFO_S;

/**
* @struct tagActionPlanTaskInfo
* @brief ����ṹ
* @attention
*/
typedef struct tagPlanTaskInfo
{
    /** ������� */
    ULONG_32 ulTaskSequence;

    /** �������� */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** ����ִ�в��ԣ�ȡֵΪ#TASK_EXEC_STRATEGY_E */
    ULONG_32 ulTaskExecStrategy;

    /** �ֶ�ִ�г�ʱʱ��(��λ:�룬�ֶ�ִ��ʱ���ֶβ���Ч) */
    ULONG_32 ulOverTime;

    /** ���������� */
    ULONG_32 ulTriggerNum;

    /** �������б� */
    TASK_TRIGGER_INFO_S astTriggerList[IMOS_MAX_TRIGGER_NUM];

    /** �������ṹ */
    TASK_ACTION_INFO_S stTaskActionInfo;
}ACTION_PLAN_TASK_INFO_S;

/**
* @struct tagActionPlanInfo
* @brief Ԥ����Ϣ
* @attention
*/
typedef struct tagActionPlanInfo
{
    /** Ԥ������ */
    CHAR szActionPlanCode[IMOS_CODE_LEN];

    /** Ԥ������ */
    CHAR szActionPlanName[IMOS_NAME_LEN];

    /** Ԥ�����ͣ�ȡֵΪ#ACTION_PLAN_TYPE_E */
    ULONG_32 ulActionPlanType;

    /** Ԥ�����ԣ�ȡֵΪ#PLAN_EXEC_STRATEGY_E */
    ULONG_32 ulExecStrategy;

    /** Ԥ������ */
    CHAR szActionPlanDesc[IMOS_DESC_LEN];

    /** Ԥ���������� */
    ULONG_32 ulTaskNum;

    /** Ԥ�������б� */
    ACTION_PLAN_TASK_INFO_S astTaskList[IMOS_MAX_TASK_NUM];
}ACTION_PLAN_INFO_S;

/**
* @struct tagPlanTaskBaseInfo
* @brief ��������ṹ
* @attention
*/
typedef struct tagPlanTaskBaseInfo
{
    /** ������� */
    ULONG_32 ulTaskSequence;

    /** �������� */
    CHAR szTaskName[IMOS_NAME_LEN];

    /** ������ʽ��ȡֵΪ#TASK_DEAL_MODE_E */
    ULONG_32 ulTaskDealMode;
}PLAN_TASK_BASE_INFO_S;

/**
* @struct tagPlanAlarmChgPushUI
* @brief ���͸�UI��Ԥ���澯�仯���ͽṹ
* @attention
*/
typedef struct tagPlanAlarmChgPushUI
{
    /** �澯��¼��Ϣ */
    EVENT_RECORD_S stEventRecord;

    /** Ԥ���澯�仯���ͣ�ȡֵΪ#PLAN_ALARM_CHG_TYPE_E */
    ULONG_32 ulChgType;
}PLAN_ALARM_CHG_PUSH_UI_S;

/**
* @struct tagPlanAlarmChgExPushUI
* @brief Ԥ���澯�仯��չ������Ϣ
* @attention
*/
typedef struct tagPlanAlarmChgExPushUI
{
    /** Ԥ���澯�仯������Ϣ */
    PLAN_ALARM_CHG_PUSH_UI_S stPlanAlarmChgPushUI;

    /** �û���½��Ϣ��id */
    CHAR    szUserLoginId[IMOS_STRING_LEN_32];

    /** SDK Module Name */
    CHAR    szSDKModuleName[IMOS_NAME_LEN];

}PLAN_ALARM_CHG_EX_PUSH_UI_S;

/**
* @struct tagQuerySysInfo
* @brief ��ѯϵͳ��Ϣ
* @attention
*/
typedef struct tagQuerySysInfo
{
    /** ��ѯ��Ϣ���֣�ȡֵΪ# QUERY_SYS_INFO_NAME_E */
    ULONG_32 ulQuerySysInfoName;

    /** ��ѯֵ */
    CHAR szQueryValue[IMOS_DESC_LEN];
}QUERY_SYS_INFO_S;

/**
* @struct tagExAutoShareInfo
* @brief ��֯�Զ������������Ϣ�ṹ
*/
typedef struct tagExAutoShareInfo
{
    /** ������� */
    CHAR szExDomainCode[IMOS_CODE_LEN];

    /** ��֯���� */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** �Ƿ��Զ����������#BOOL_TRUEΪ�Զ���������򣬷�֮ȡֵΪ#BOOL_FALSE */
    BOOL_T bIsAutoShare;

    /** (�����Ƿ��Զ����������ʱ)�Ƿ��������֯��#BOOL_TRUEΪ��������֯����֮ȡֵΪ#BOOL_FALSE */
    BOOL_T bDoesContainSub;

    /** �����ֶ� */
    CHAR szReserved[128];
} EX_AUTO_SHARE_INFO_S;

/**
 * @struct tagShareUnSucceedRes
 * @brief δ����ɹ���Դ��Ϣ
 * @attention
 */
typedef struct tagShareUnSucceedRes
{
    /** δ�ɹ�ԭ���룬#ERR_COMMON_SUCCEED��ʾ���������У�����ֵ����ʾ����ʧ�ܣ�ֵ��Ӧ�Ĵ������ͼ��������б�*/
    ULONG_32 ulDetailCode;

    /** ��Դ���� */
    ULONG_32 ulResType;

    /** ��Դ���� */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ��Դ�������� */
    CHAR  szResShareCode[IMOS_CODE_LEN];

    /** ��Դ������ */
    CHAR  szResParentCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR  szResParentName[IMOS_NAME_LEN];

    /** ��Դ�����Ȩ�� */
    ORG_AUTHORITY_V2_S  stAuthority;
}SHARE_UNSUCCEED_RES_S;

/**
* @struct tagEventEnableInfo
* @brief �¼�ʹ�ܲ�����Ϣ�ṹ
* @attention
*/
typedef struct tagEventEnableInfo
{

    /** �¼�ϵͳĬ������ */
    CHAR    szPreEventName[IMOS_NAME_LEN];

    /** �¼�ϵͳĬ�ϼ���, ȡֵΪ#ALARM_SEVERITY_LEVEL_E */
    ULONG_32   ulPreEventSecurity;

    /** �¼�ϵͳ�Զ�������, ϵͳ�¼�ʹ�ܲ�����ʾ�¼�ʹ������ */
    CHAR    szSysEventName[IMOS_NAME_LEN];

    /** �¼�ϵͳ�Զ��弶��, ȡֵΪ#ALARM_SEVERITY_LEVEL_E, ϵͳ�¼�ʹ�ܲ�����ʾ�¼�ʹ�ܼ��� */
    ULONG_32   ulSysEventSecurity;

    /** �¼�ʹ�������� */
    CHAR    szEventName[IMOS_NAME_LEN];

    /** �¼�ʹ�ܼ���, ȡֵΪ#ALARM_SEVERITY_LEVEL_E */
    ULONG_32   ulEventSecurity;

    /** �Ƿ��Զ�ȷ��, #BOOL_TRUEΪ�Զ�ȷ��, #BOOL_FALSE���Զ�ȷ��, Ĭ��Ϊ#BOOL_TRUE */
    BOOL_T   bAutoAck;

    /** �Ƿ�ʹ��, #BOOL_TRUEΪʹ��, #BOOL_FALSEΪδʹ��, Ĭ��ΪBOOL_TRUE */
    BOOL_T   bEnable;

}EVENT_ENABLE_INFO_S;

/**
* @struct tagBathEventEnableInfo
* @brief  ���������¼�ʹ�ܲ�����Ϣ�ṹ
* @attention
*/
typedef struct tagBathEventEnableInfo
{
    /** ��Ҫ�Զ���ĸ澯����, ȡֵΪ#AlARM_TYPE_E, 0��ʾΪȫ�� */
    ULONG_32       ulEventType;

    /** ������ĸ澯Դ���� */
    ULONG_32       ulDevNum;

    /** ������澯Դ��Ϣ */
    ALARM_SRC_QUERY_ITEM_S astAlarmSrcList[IMOS_PAGE_QUERY_ROW_MAX_NUM];

} BATH_EVENT_ENABLE_INFO_S;
/**
 * @struct tagSetNetworkAdaptInfo
 * @briefʵ��������Ӧ����Ϣ
 * @attention
 */
typedef struct tagSetNetworkAdaptInfo
{
     /** ʵ��������Ӧ���� 1�� 2�� */
    ULONG_32  ulMonitorNetworkAdaptEnable;

    /**�洢 ������Ӧ���� 1�� 2�� */
    ULONG_32  ulStoreNetworkAdaptEnable;

    /** ������Ӧģʽ   0:֡������ 1��ͼ������ */
    ULONG_32  ulNetworkAdaptMode;

    /** ʵ����������Ӧ�ָ�ʱ�� */
    ULONG_32  ulNetworkAdaptCount;

     /**����  */
    UCHAR   szReserved[128];
} NETWORK_ADAPT_INFO_S;

/**
* @struct tagEventTypeL2oRel
* @brief ������澯���Ͷ�Ӧ��ϵ
* @attention
*/
typedef struct tagEventTypeL2oRel
{
    /** ��ϵ����ID */
    CHAR szEventTypeL2ORelCode[IMOS_CODE_LEN];

	 /* Э������ */
    ULONG_32 ulProtocolType;

    /** �����¼����� */
    ULONG_32 ulH3cEventType;

    /** Э���¼����� */
    ULONG_32  ulProtocolEventType;

    /** �澯״̬ */
    ULONG_32   ulEventStatus;

    /** ��ϵ���� */
    CHAR   szRelDesc[IMOS_DESC_LEN];

}EVENT_TYPE_L2OREL_S;

/**
 * @struct tagMapColors
 * @brief GIS��ͼ��ɫ
 * @attention
 */
typedef struct tagMapColors
{
	/** ��ͼ�����ɫ */
    ULONG_32                   ulFillZone;

	/** ��ͼ������ɫ */
    ULONG_32                   ulLine;

	/** ɽ��������ɫ */
    ULONG_32                   ulHills;

	/** ��ˮ������ɫ */
    ULONG_32                   ulDeepWater;

	/** ����������ɫ */
	ULONG_32                   ulCity;

	/** ǳˮ������ɫ */
	ULONG_32                   ulShallowWater;
}FILE_MAP_COLORS_S;

/**
* @struct tagEventSecurityType
* @brief �¼�����
* @attention
*/
typedef struct tagEventSecurityType
{
    /** �������� */
    ULONG_32  ulSecurityType;

    /** �������� */
    CHAR   szSecurityName[IMOS_NAME_LEN];

    /** ������ʾ��ɫ����ɫRGBֵ��������(#)�� */
    CHAR  szSecurityColor[IMOS_STRING_LEN_14];

    /** ����������Ϣ */
    CHAR   szDesc[IMOS_DESC_LEN];

    /** ���� */
    UCHAR   szReserved[128];

} EVENT_SECURITY_TYPE_S;

/**
* @struct tagEventSecurityExtType
* @brief �¼�������չ��Ϣ
* @attention
*/
typedef struct tagEventSecurityExtType
{
    /** ������Ϣ */
    EVENT_SECURITY_TYPE_S stEventSecurityType;

    /** �Ƿ���ϵͳԤ����澯���� */
    BOOL_T                bSysEventType;

} EVENT_SECURITY_EXT_TYPE_S;

/**
* @struct tagEventSecurityChgPushUI
* @brief ���͸�UI�ļ�����Ϣ�仯���ͽṹ
* @attention
*/
typedef struct tagEventSecurityChgPushUI
{
    /** �澯������Ϣ */
    EVENT_SECURITY_TYPE_S stEventSecurity;

    /** �澯����仯���ͣ�ȡֵΪ#EVENT_SECURITY_CHG_TYPE_E */
    ULONG_32 ulChgType;
} EVENT_SECURITY_CHG_PUSH_UI_S;

/**
* @struct tagEventSecurityChgExPushUI
* @brief �¼�����仯��չ������Ϣ
* @attention
*/
typedef struct tagEventSecurityChgExPushUI
{
    /** �¼�����仯������Ϣ */
    EVENT_SECURITY_CHG_PUSH_UI_S stEventSecurityChgPushUI;

    /** �û���½��Ϣ��id */
    CHAR    szUserLoginId[IMOS_STRING_LEN_32];

    /** SDK Module Name */
    CHAR    szSDKModuleName[IMOS_NAME_LEN];

} EVENT_SECURITY_CHG_EX_PUSH_UI_S;

/**
/**
* @struct tagCSPtzStatusNotify
* @brief SOI ��̨״̬�����Ϣ �ṹ
* @attention ��
*/
typedef struct tagCSPtzStatusNotify
{
    CHAR    szUserName[IMOS_NAME_LEN];                  /* �û����� */
    CHAR    szUserIpAddress[IMOS_IPADDR_LEN];           /* ��ռ�����û��ĵ�¼IP */
    CHAR    szCameraCode[IMOS_DEVICE_CODE_LEN];         /* ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];                /* ��������� */
    ULONG_32   ulNotifyType;                               /* ֪ͨ���� ��Ӧö��:#PTZ_NOTIFY_UI_EVENT_TYPE */
	ULONG_32   ulAutoGuard;                                /* ��̨���ؿ���λʱ�� */
}CS_PTZ_STATUS_NOTIFY_S;

/**
* @struct tagCaseInfo
* @brief ������Ϣ�ṹ
* @attention
*/
typedef struct tagGACaseInfo
{
    /** ������� */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR    szCaseName[IMOS_STRING_LEN_256];

    /** �������ʣ�ȡֵΪ#CASE_PROPERTY_E */
    ULONG_32   ulCaseProperty;

    /** �������ͣ�ȡֵΪ#CASE_TYPE_E */
    // ULONG_32   ulCaseType;

    /** �������� */
    CHAR    szCaseType[IMOS_STRING_LEN_256];

    /** ����״̬��ȡֵΪ#CASE_STATUS_E */
    ULONG_32   ulCaseStatus;

    /** ������Դ��ȡֵΪ#POLICE_INTELLIGENCE_SOURCE_E */
    ULONG_32   ulPoliceIntSrc;

    /** �ܼ���ȡֵ#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** �Ӿ����� */
    CHAR    szReportCode[IMOS_CODE_LEN];

    /** �Ӿ�ʱ�� */
    CHAR    szReportTime[IMOS_TIME_LEN];

    /** ������ */
    CHAR    szProPerson[IMOS_NAME_LEN];

    /** ����������Ա���� */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** Σ���̶� */
    CHAR    szEndangerment[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szCaseDesc[IMOS_CASE_DESC_LEN];

    /** ������ע */
    CHAR    szCaseNote[IMOS_NOTE_LEN];

    /** ��ʼʱ�� */
    CHAR    szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR    szEndTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR    szCrimeOpporunity[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szCrimelocation[IMOS_NAME_LEN];

    /** ������λ */
    CHAR    szCrimePosition[IMOS_NAME_LEN];

    /** �������� */
    ULONG_32    ulCriminalNum;

    /** �������� */
    CHAR    szCrimeTarget[IMOS_NAME_LEN];

    /** �����ֶ� */
    CHAR    szCrimeStyle[IMOS_STRING_LEN_512];

    /** �����ص� */
    CHAR    szCrimeFeature[IMOS_STRING_LEN_512];

    /** ���� */
    CHAR    szDistrict[IMOS_NAME_LEN];

    /** �ֵ� */
    CHAR    szStreet[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szPoliceDstrict[IMOS_STRING_LEN_256];

    /** ���� */
    CHAR    szCommunity[IMOS_NAME_LEN];

    /** ��ϸ��ַ */
    CHAR    szAddress[IMOS_STRING_LEN_256];

    /** ���ű��� */
    CHAR    szDeptCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR    szDeptName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** �ư�ʱ�� */
    CHAR    szSolvedTime[IMOS_TIME_LEN];

    /** �᰸ʱ�� */
    CHAR    szClosedTime[IMOS_TIME_LEN];

    /** Դ������� */
    CHAR    szSrcCaseCode[IMOS_CODE_LEN];

    /** ת������� */
    CHAR    szTransCaseCode[IMOS_CODE_LEN];
}CASE_INFO_S;


/**
* @struct tagCaseListInfo
* @brief �����б���Ϣ�ṹ
* @attention
*/
typedef struct tagCaseListInfo
{
    /** ������� */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR    szCaseName[IMOS_STRING_LEN_256];

    /** �������ͣ�ȡֵΪ#CASE_TYPE_E */
    //ULONG_32   ulCaseType;

    /** �������� */
    CHAR    szCaseType[IMOS_STRING_LEN_256];

    /** ����״̬��ȡֵΪ#CASE_STATUS_E */
    ULONG_32   ulCaseStatus;

    /* �Ƿ���ڴ�������0:�Ǵ�������1:���ڴ����� */
    BOOL_T  bIsSeries;

    /** �������ʣ�ȡֵΪ#CASE_PROPERTY_E */
    ULONG_32   ulCaseProperty;

    /** ������Դ��ȡֵΪ#POLICE_INTELLIGENCE_SOURCE_E */
    ULONG_32   ulPoliceIntSrc;

    /** Σ���̶� */
    CHAR    szEndangerment[IMOS_NAME_LEN];

    /** ������ */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** ��ʼʱ�� */
    CHAR    szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR    szEndTime[IMOS_TIME_LEN];

    /** ֱ�����ű��� */
    CHAR    szParDeptCode[IMOS_CODE_LEN];

    /** ֱ���������� */
    CHAR    szParDeptName[IMOS_NAME_LEN];
}CASE_LIST_INFO_S;

/**
* @struct tagCasePersonnelExtraInfo
* @brief ������Ա������Ϣ�ṹ
* @attention
*/
typedef struct tagCasePersonnelExtraInfo
{
    /** ��Ϊ */
    CHAR    szBehavior[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szAccent[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szBodyShape[IMOS_NAME_LEN];

    /** ��� */
    CHAR    szHeight[IMOS_NAME_LEN];

    /** ��ɫ */
    CHAR    szSkinColor[IMOS_NAME_LEN];

    /** ��� */
    CHAR    szBodySurface[IMOS_NAME_LEN];

    /** ���¿�ʽ */
    CHAR    szShirtStyle[IMOS_NAME_LEN];

    /** ������ɫ */
    CHAR    szShirtColor[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szShirtFeature[IMOS_NAME_LEN];

    /** ���䳤�� */
    CHAR    szSleeveLength[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szCollar[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szTrousers[IMOS_NAME_LEN];

    /** �㳤 */
    CHAR    szTrousersLength[IMOS_NAME_LEN];

    /** ��ɫ */
    CHAR    szTrousersColor[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szHairstyle[IMOS_NAME_LEN];

    /** ��ɫ */
    CHAR    szHairColor[IMOS_NAME_LEN];

    /** �۾� */
    CHAR    szEyeglasses[IMOS_NAME_LEN];

    /** ñ�� */
    CHAR    szCap[IMOS_NAME_LEN];

    /** Χ�� */
    CHAR    szScarf[IMOS_NAME_LEN];

    /** �� */
    CHAR   szBag[IMOS_NAME_LEN];

    /** Ь�� */
    CHAR   szShoeType[IMOS_NAME_LEN];

    /** Ьɫ*/
    CHAR   szShoeColor[IMOS_NAME_LEN];
}CASE_PERSONNEL_EXTRA_INFO_S;

/**
* @struct tagCasePersonnelInfo
* @brief ������Ա��Ϣ�ṹ
* @attention
*/
typedef struct tagCasePersonnelInfo
{
    /** ������� */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** ������Ա��ţ���ѯʱ�ɺ�̨���� */
    CHAR    szPersCode[IMOS_CODE_LEN];

    /** ��Ա���ȡֵΪ#CASE_PERSONNEL_TYPE_E */
    ULONG_32   ulPersonnelType;

    /** ���� */
    CHAR    szName[IMOS_NAME_LEN];

    /** �Ա�ȡֵΪ#GENDER_TYPE_E */
    ULONG_32   ulGender;

    /** ���䣬���� */
    ULONG_32   ulMinAge;

    /** ���䣬���� */
    ULONG_32   ulMaxAge;

    /** ���� */
    CHAR   szNativePlace[IMOS_NAME_LEN];

    /** ��ϵ�绰 */
    CHAR    szTelephone[IMOS_PHONE_LEN];

    /** ������λ */
    CHAR    szCompany[IMOS_NAME_LEN];

    /** ������ */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];

    CASE_PERSONNEL_EXTRA_INFO_S stCasePerExInfo;
}CASE_PERSONNEL_INFO_S;

/**
* @struct tagCaseVehicleInfo
* @brief ����������Ϣ�ṹ
* @attention
*/
typedef struct tagCaseVehicleInfo
{
    /** ������� */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** ����������� */
    CHAR    szVehicleCode[IMOS_CODE_LEN];

    /** ���ƺ��� */
    CHAR    szPlateCode[IMOS_CODE_LEN];

    /** ������ɫ*/
    CHAR    szVehicleColor[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szVehicleType[IMOS_NAME_LEN];

    /** ������Ϊ*/
    CHAR    szBehavior[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szVehicleFeature[IMOS_NAME_LEN];

    /** �������� */
    CHAR   szlocalization[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szClassification[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szManufacturer[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szPlateType[IMOS_NAME_LEN];

    /** ������ɫ */
    CHAR    szPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �����ڵ� */
    CHAR    szPlateCover[IMOS_NAME_LEN];

    /** ������Ĥ */
    CHAR    szWindowFilm[IMOS_NAME_LEN];

    /** ������ */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_VEHICLE_INFO_S;


/**
* @struct tagCaseStuffInfo
* @brief ������Ʒ��Ϣ�ṹ
* @attention
*/
typedef struct tagCaseStuffInfo
{
    /** ������� */
    CHAR    szCaseCode[IMOS_CODE_LEN];

    /** ������Ʒ��ţ���ѯʱ�ɷ��������� */
    CHAR    szStuffCode[IMOS_CODE_LEN];

    /** ��Ʒ���� */
    CHAR    szStuffName[IMOS_NAME_LEN];

    /** �永��Ʒ���ȡֵΪ#CASE_STUFF_TYPE_E */
    ULONG_32   ulCaseStuffType;

    /** �永��Ʒ���ʣ�ȡֵΪ#CASE_STUFF_PROPERTY_E */
    ULONG_32   ulCaseStuffProperty;

    /** ������ */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_STUFF_INFO_S;

/**
* @struct tagCaseRecordInfo
* @brief ����¼����Ϣ�ṹ
* @attention
*/
typedef struct tagCaseRecordInfo
{
    /** ¼����룬��ѯʱ���� */
    CHAR    szRecCode[IMOS_CODE_LEN];

    /** ��Ƶ��ص� */
    CHAR    szTarget[IMOS_NAME_LEN];

    /** ��������� */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** ��ʼʱ�� */
    CHAR    szBegintime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR    szEndtime[IMOS_TIME_LEN];

    /** �ܼ���ȡֵ#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_RECORD_INFO_S;

/**
* @struct tagCaseRecordListInfo
* @brief ����¼���б���Ϣ�ṹ
* @attention
*/
typedef struct tagCaseRecordListInfo
{
    /** ¼����� */
    CHAR    szRecordCode[IMOS_CODE_LEN];

    /** ��Ƶ��ص� */
    CHAR    szTarget[IMOS_NAME_LEN];

    /** ��������� */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** ��ʼʱ�� */
    CHAR    szBegintime[IMOS_TIME_LEN];

    /** ����ʱ�� */
    CHAR    szEndtime[IMOS_TIME_LEN];

    /** ¼���С */
    ULONG_32    ulRecordSize;

    /** ¼�񱸷�״̬��0:δ��ɣ�1:��� */
    ULONG_32    ulBakStatus;

    /** �ϴ��û� */
    CHAR    szUploadUser[IMOS_NAME_LEN];

    /** �ϴ�ʱ�� */
    CHAR    szUploadtime[IMOS_TIME_LEN];

    /** ����¼���ļ�ȫ·������ѯ�б�ʱ�ɷ��������� */
    //CHAR    szFilePath[IMOS_FILE_MAXNUM_PER_CASERECORD][IMOS_FILE_PATH_LEN];

    /** ���������� */
    CHAR szDecoderTag[IMOS_STRING_LEN_64];

}CASE_RECORD_LIST_INFO_S;

/**
* @struct tagCaseFileInfo
* @brief ���������ļ���Ϣ�ṹ
* @attention
*/
typedef struct tagCaseFileInfo
{
    /** �ļ����� */
    CHAR    szFileCode[IMOS_CODE_LEN];

    /** �ļ��� */
    CHAR    szFileName[IMOS_FILE_NAME_LEN];

    /** �ļ�����,ȡֵ#CASE_FILE_TYPE_E */
    ULONG_32    ulFileType;

    /** �ļ���С */
    ULONG_32    ulFileSize;

    /** �ܼ���ȡֵ#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** �ϴ��û� */
    CHAR    szUploadUser[IMOS_NAME_LEN];

    /** �ϴ�ʱ�� */
    CHAR    szUploadtime[IMOS_TIME_LEN];

    /** ��������¼��Ϊ¼��ʼʱ��
        �԰���ͼƬ��Ϊ����ʱ�� */
    CHAR    szBeginTime[IMOS_TIME_LEN];

    /** ����ʱ�䣬��������¼��*/
    CHAR    szEndTime[IMOS_TIME_LEN];

    /** ����ص�--���� */
    CHAR    szLongitude[IMOS_COORDINATE_LEN];

    /** ����ص�--γ�� */
    CHAR    szLatitude[IMOS_COORDINATE_LEN];

    /** ���ط�����IP����ѯ�б�ʱ�ɷ��������� */
    CHAR    szDLServerIP[IMOS_IPADDR_LEN];

    /** �ļ�ȫ·������ѯ�б�ʱ�ɷ��������� */
    CHAR    szFilePath[IMOS_FILE_PATH_LEN];

    /** ͼƬ����룬�ļ�����ΪͼƬ��ͼƬʱʹ�� */
    CHAR    szPicGrpCode[IMOS_CODE_LEN];

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];

}CASE_FILE_INFO_S;

/**
* @struct tagFileDownloadInfo
* @brief �ļ�������Ϣ���ݽṹ
*/
typedef struct tagFileDownloadInfo
{
    /** ��������ַ*/
    CHAR    szServerIP[IMOS_IPADDR_LEN];

    /** �ļ�ȫ·��  */
    CHAR    szFilePath[IMOS_FILE_PATH_LEN];

    /** ����ʱ��:��ʼ������ */
    TIME_SLICE_S stBakTime;

}FILE_DOWNLOAD_INFO_S;

/**
* @struct tagSeriesCaseInfo
* @brief ��������Ϣ�ṹ
* @attention
*/
typedef struct tagSeriesCaseInfo
{
    /** ���������ͣ�ȡֵΪ#SERIES_CASE_TYPE_E */
    ULONG_32   ulSeriesCaseType;

    /** ��������� */
    CHAR    szSeriesCaseCode[IMOS_CODE_LEN];

    /** ���������� */
    CHAR    szSeriesCaseName[IMOS_NAME_LEN];

    /** �ܼ���ȡֵ#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** ������ */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR    szCreateTime[IMOS_TIME_LEN];

    /** ������ */
    CHAR    szProPerson[IMOS_NAME_LEN];

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];

    /** ���ű��� */
    CHAR    szDeptCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR    szDeptName[IMOS_NAME_LEN];

    /** �����������İ���ʵ������, ���ֵΪ#IMOS_CASE_MAXNUM_PER_SERIESCASE */
    ULONG_32       ulCaseNum;

    /** �����б����� */
    CASE_LIST_INFO_S astCaseList[IMOS_CASE_MAXNUM_PER_SERIESCASE];
}SERIES_CASE_INFO_S;


/**
* @struct tagSeriesCaseList
* @brief �������б���Ϣ�ṹ
* @attention
*/
typedef struct tagSeriesCaseList
{
    /** ���������ͣ�ȡֵΪ#SERIES_CASE_TYPE_E */
    ULONG_32   ulSeriesCaseType;

    /** ��������� */
    CHAR    szSeriesCaseCode[IMOS_CODE_LEN];

    /** ���������� */
    CHAR    szSeriesCaseName[IMOS_NAME_LEN];

    /** ������ */
    CHAR    szCreator[IMOS_NAME_LEN];

    /** ������ */
    CHAR    szProPerson[IMOS_NAME_LEN];

    /** �����������İ���ʵ������, ���ֵΪ#IMOS_CASE_MAXNUM_PER_SERIESCASE */
    ULONG_32       ulCaseNum;

    /** ֱ�����ű��� */
    CHAR    szParDeptCode[IMOS_CODE_LEN];

    /** ֱ���������� */
    CHAR    szParDeptName[IMOS_NAME_LEN];
}SERIES_CASE_lIST_S;


/**
* @struct tagCaseShareDstInfo
* @brief ��������Ŀ����Ϣ�ṹ
* @attention
*/
typedef struct tagCaseShareDstInfo
{
    /** ��Դ���� */
    CHAR    szResCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR    szResName[IMOS_NAME_LEN];

    /** �����������ͣ�ȡֵΪ#CASE_SHARE_TYPE_E */
    ULONG_32   ulShareType;

    /** ֱ����֯���� */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** ֱ����֯���� */
    CHAR    szParOrgName[IMOS_NAME_LEN];
}CASE_SHAREDST_INFO_S;

/**
* @struct tagElectronicBulletinInfo
* @brief ���ӹ�����Ϣ�ṹ
* @attention
*/
typedef struct tagElectronicBulletinInfo
{
    /** ������� */
    CHAR    szBulletinCode[IMOS_CODE_LEN];

    /** ��Ч�� */
    ULONG_32    ulExpDate;

    /** �������� */
    CHAR    szContent[IMOS_DESC_LEN];

    /** ������ */
    CHAR    szPublisher[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR    szPubTime[IMOS_TIME_LEN];
}ELECTRONIC_BULLETIN_INFO_S;

/**
* @struct tagCaseProcessStatistic
* @brief ��������ͳ��
* @attention
*/
typedef struct tagCaseProcessStatistic
{
    /** ��Ա���� */
    CHAR  szUserName[IMOS_NAME_LEN];

    /** ¼��������� */
    ULONG_32  ulRecordNum;

    /** �᰸���� */
    ULONG_32  ulClosedNum;

    /** ֱ����֯���� */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** ֱ����֯���� */
    CHAR    szParOrgName[IMOS_NAME_LEN];

}CASE_PROCESS_STATISTIC_S;

/**
* @struct tagElecBulletinPushUI
* @brief ���͸�UI�ĵ��ӹ���仯���ͽṹ
* @attention
*/
typedef struct tagElecBulletinPushUI
{
    /** ���ӹ������ */
    CHAR   szEBCode[IMOS_CODE_LEN];

    /** ���ӹ���仯���ͣ�0:������1:ɾ�� */
    ULONG_32       ulChangeType;

    /** ����ʱ�� */
    CHAR   szPubTime[IMOS_TIME_LEN];

    /** �������� */
    CHAR    szContent[IMOS_DESC_LEN];

}ELEC_BULLETIN_PUSH_UI_S;

#if 0
#endif

/**
* @struct tagIMOSUploadADDR
* @brief �����ļ��ϴ���ַ�ṹ
* @attention
*/
typedef struct tagIMOSUploadADDR
{
    /**< ��ַ����#IMOS_UPLOAD_ADDR_TYPE_E */
    ULONG_32   ulAddrType;

    /**< ��ַ����ָ��, �ɵ�ַ���;��� */
    VOID    *pAddr;

    /**< ��ַ���ݳ���, �ɵ�ַ���;���, ����У�� */
    ULONG_32   ulAddrLen;
}IMOS_UPLOAD_ADDR_S;

/* �ϴ��ص������ӿڶ���, ulUploadRet����ֵ�ο�#BP_FILETRANS_ERR_CODE_E */
typedef VOID (* IMOS_UPLOAD_FILE_PF)(IN IMOS_HANDLE hHandle, IN ULONG_32 ulUploadRet, INOUT VOID *pParam);

/**
* @struct tagIMOSUploadOption
* @brief �����ļ��ϴ�ѡ����Ϣ�ṹ
* @attention
*/
typedef struct tagIMOSUploadOption
{
    /**< ҵ������#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32   ulServiceType;

    /** ���������, kbps */
    ULONG_32   ulTransRate;

    /** �����ʱ��, ��λ�� */
    ULONG_32   ulTransTimeout;

    /* ������ID, ΪDAO_INVALID_IMOSIDʱ��ʾû�й����κ�ID */
    IMOS_ID idIMOSID;

    /* ������ID����#IMOS_ID_TYPE_E */
    ULONG_32   ulIDType;

    /* �ص�����, ���ڻص�ʱ���� */
    VOID *pParam;

    /* �ϴ�������Ļص�����, �ṩ����Ҫ֧�ֶ��̵߳���, �û�����ȡ������ʱ�ýӿڲ������� */
    IMOS_UPLOAD_FILE_PF pfnUploadEnd;
}IMOS_UPLOAD_OPTION_S;

/**
* @struct tagIMOSLocalFileInfo
* @brief ׼���ϴ��ı����ļ���Ϣ�ṹ
* @attention
*/
typedef struct tagIMOSLocalFileInfo
{
    /** �����ļ�ȫ·�� */
    CHAR    szFilePath[IMOS_FILE_PATH_LEN];

    /** �ϴ����������ĵ�ַ·��, ���԰����ļ���, Ϊ��������ɷ�����ָ��. �ݲ�֧�� */
    CHAR    szSrvPath[IMOS_FILE_PATH_LEN];

    /** �ļ�����,ȡֵ#CASE_FILE_TYPE_E */
    ULONG_32   ulFileType;

    ULONG_32   ulFileSubType;

    /* �ϴ���ʼƫ����(�ݲ�֧��) */
    ULONG_32   ulOffset;

    /** �ϴ�����(�ݲ�֧��, Ŀǰ�����ļ�һ���ϴ�) */
    ULONG_32   ulUploadLen;

    /** ��ע */
    CHAR    szNote[IMOS_NOTE_LEN];
}IMOS_LOCAL_FILE_INFO_S;

/**
* @struct tagIMOSUploadFileInfo
* @brief �����ļ��ϴ���չ��Ϣ�ṹ, ���ڿͻ��˸��ļ�����������
* @attention
*/
typedef struct tagIMOSUploadFileInfo
{
    /* �ļ����ͣ����������TS�ļ���ֵΪ0; ���ڿͻ����ϴ�, ֵΪ1 */
    ULONG_32   ulUploadType;

    /**< ҵ������#BAK_TASK_SERVICE_TYPE_E */
    ULONG_32   ulServiceType;

    /* �ļ���С, ���ֽ�Ϊ��λ */
    DULONG     dulFileSize;

    /* ������ID */
    IMOS_ID idIMOSID;

    /* ������ID����#IMOS_ID_TYPE_E */
    ULONG_32   ulIDType;

    /* ���ͻ���ʹ��, �������ֲ�ͬ�Ļص� */
    ULONG_32   ulSeq;

    /* �ϴ�����ļ�ID, �ݲ�ʹ��; ��Ҫ��������������Խ��ļ�idͨ����Ϣ���ظ��ͻ��˽����ص� */
    /* Ŀǰֻ�ܸ��ݹ���ID�����ļ�����ѯ */
    IMOS_ID idUploadFile;

    /* �û���¼��Ϣ */
    USER_LOGIN_ID_INFO_S stUserLogin;

    /* Ŀǰ�Ͱ��տͻ����ϴ��ı����ļ�����д, ���ļ��� */
    CHAR    szSrvFilePath[IMOS_FILE_PATH_LEN];
}IMOS_UPLOAD_FILE_INFO_S;


/**
* @struct tagPictureGroupInfo
* @brief ͼƬ����Ϣ�ṹ
* @attention
*/
typedef struct tagPictureGroupInfo
{
    /** ͼƬ����룬�ɺ�̨���ɴ��� */
    CHAR    szPicGrpCode[IMOS_CODE_LEN];

    /** ͼƬ������ */
    CHAR    szPicGrpName[IMOS_NAME_LEN];

    /** �ܼ���ȡֵ#CASE_CLASSIFICATION_TYPE_E */
    ULONG_32    ulClassification;

    /** ����¼����� */
    CHAR    szCaseRecCode[IMOS_CODE_LEN];

    /** ͼƬ������ */
    CHAR    szPicGrpDesc[IMOS_DESC_LEN];

}PICTURE_GROUP_INFO_S;

/**
* @struct tagDeptInfo
* @brief ������Ϣ�ṹ
* @attention
*/
typedef struct tagDeptInfo
{
    /** ���ű��� */
    CHAR    szDeptCode[IMOS_CODE_LEN];

    /** �������� */
    CHAR    szDeptName[IMOS_NAME_LEN];

    /** �������� */
    CHAR    szDeptDesc[IMOS_DESC_LEN];

}DEPT_INFO_S;

/**
 * @struct tagCaseInfoAnalysisStat
 * @brief ������Ϣ����ͳ��
 * @attention
 */
typedef struct tagCaseInfoAnalysisStat
{
    /** ��λ���� */
    CHAR szDepartmentCode[IMOS_CODE_LEN];

    /** ��λ���� */
    CHAR szDepartmentName[IMOS_NAME_LEN];

    /** �������� */
    ULONG_32 ulCaseTotalNum;

    /** �ϴ���Ƶ���� */
    ULONG_32 ulCaseVideoNum;

    /** �����ư��İ�������Ƶ���� */
    ULONG_32 ulEndCaseVideoNum;

    /** �ư��İ������� */
    ULONG_32 ulEndCaseTotalNum;

    /** ������Ƶ���ư��İ������� */
    ULONG_32 ulVideoEndCaselNum;

}CASE_ANALYSIS_STAT_S;
/**
 * @struct tagCaseDepartmentStat
 * @brief ������Ϣ�ֲ���ͳ��
 * @attention
 */
typedef struct tagCaseDepartmentStat
{
    /** ��λ���� */
    CHAR szDepartmentCode[IMOS_CODE_LEN];

    /** ��λ���� */
    CHAR szDepartmentName[IMOS_NAME_LEN];

    /** ƽ̨¼���������߰���ƽ̨¼��İ������� */
    ULONG_32 ulIMOSVideoCount;

    /** �ϴ�¼���������߰����ϴ�¼��İ������� */
    ULONG_32 ulUploadVideoCount;

    /** �ϴ�ͼƬ�������߰����ϴ�ͼƬ�İ������� */
    ULONG_32 ulUploadPicturCount;

    /** �ϴ������������߰����ϴ������İ������� */
    ULONG_32 ulUploadOtherCount;

}CASE_DEPARTMENT_STAT_S;

/**
 * @struct tagCaseUserStat
 * @brief ������Ϣ���û�ͳ��
 * @attention
 */
typedef struct tagCaseUserStat
{
    /** ��λ���� */
    CHAR szDepartmentCode[IMOS_CODE_LEN];

    /** ��λ���� */
    CHAR szDepartmentName[IMOS_NAME_LEN];

    /** �û����� */
    CHAR szUserName[IMOS_NAME_LEN];

    /** �û�ȫ�� */
    CHAR szUserFullName[IMOS_NAME_LEN];

    /** ƽ̨¼���������߰���ƽ̨¼��İ������� */
    ULONG_32 ulIMOSVideoCount;

    /** �ϴ�¼���������߰����ϴ�¼��İ������� */
    ULONG_32 ulUploadVideoCount;

    /** �ϴ�ͼƬ�������߰����ϴ�ͼƬ�İ������� */
    ULONG_32 ulUploadPicturCount;

    /** �ϴ������������߰����ϴ������İ������� */
    ULONG_32 ulUploadOtherCount;

    /** ����������Ϣ�ļ�¼��(�����ˣ���������Ʒ��������) */
    ULONG_32 ulCaseItemCount;
}CASE_USER_STAT_S;
/**
 * @struct tagCaseStatFlag
 * @brief ������Ϣͳ�Ʊ�־λ
 * @attention
 */
typedef enum tagCaseStatFlag
{
    /** ���յ�λͳ�ư�����Ϣ */
    STAT_DEPARTMENT_CASE_FLAG,

    /** ���յ�λͳ��������Ϣ */
    STAT_DEPARTMENT_DATA_FLAG,

    /** �����û�ͳ�ư�����Ϣ */
    STAT_USER_CASE_FLAG,

    /** �����û�ͳ�ư�����Ϣ */
    STAT_USER_DATA_FLAG,

    STAT_FLAG_INVAILD = 0XFFFF
}CASE_STAT_FLAG_S;

/* added by z06806 for tollgate struct */
/**
 * @struct tagReservedInfo
 * @brief Ԥ���ֶνṹ
 * @attention
 */
typedef struct tagReservedInfo
{
    /** Ԥ���ֶ�1:��ʹ�ã����ڱ�ʾ����ԭ�� */
    ULONG_32 ulReserved1;

    /** Ԥ���ֶ�2 */
    ULONG_32 ulReserved2;

    /** Ԥ���ֶ�3 */
    ULONG_32 ulReserved3;

    /** Ԥ���ֶ�4 */
    CHAR szReserved4[IMOS_RESERVED_LEN];

    /** Ԥ���ֶ�5 */
    CHAR szReserved5[IMOS_RESERVED_LEN];

    /** Ԥ���ֶ�6 */
    CHAR szReserved6[IMOS_RESERVED_LEN];
} RESERVED_INFO_S;

/**
 * @struct tagVehicleAlarmData
 * @brief ����������¼
 * @attention
 */
typedef struct tagVehicleAlarmData
{
    /** ����������Ϣ��� */
    CHAR  szVehicleAlarmCode[IMOS_CODE_LEN];

    /** ������Ϣ��ţ���ѯ���أ���������¿��Բ��� */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** �������ͣ�ȡֵΪDISPOSITION_INTER_TYPE_LOCAL����DISPOSITION_INTER_TYPE_LOWER */
    ULONG_32 ulInterType;

    /** ���ڱ�ţ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** �������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** �����ţ���ѯ���أ���������¿��Բ��� */
    ULONG_32 ulLaneNumber;

    /** ��ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection;

    /** ��ʻ�������ƣ��ѷ��� */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** ͨ��ʱ��/�澯���Ϊ������ٸ澯ʱ��Ϊʻ�뿨��ʱ�� */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** �������� */
    ULONG_32 ulLicensePlateNum;

    /** ���ƺ��� */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** �������࣬�ο������ֵ� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �����ٶȣ���λKm/h���澯���Ϊ������ٸ澯ʱ��Ϊ����ƽ����ʻ�ٶ� */
    ULONG_32 ulVehicleSpeed;

    /** ��ʾ���٣���λKm/h����ѯ���أ���������¿��Բ��� */
    ULONG_32 ulMarkedSpeed;

    /** �������٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** ����Ʒ�ƣ��ο������ֵ� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ��������λ: ���� */
    ULONG_32 ulVehicleLen;

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ� */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** �澯��𣬲ο�#VEHICLE_ALARM_TYPE_E */
    ULONG_32 ulAlarmType;

    /** ���ݸ澯�����д������ǲ��ر�������Ϊ���ر�ţ�����Ǻ�������������Ϊ��������š��������������Ϊ�� */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** ������𣬲ο������ֵ䣬���ر�������ֵ������Ϊ�� */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** ����ʱ�䣬�澯���Ϊ������ٸ澯ʱ��Ϊʻ������ʱ�� */
    CHAR  szAlarmTime[IMOS_TIME_LEN];

    /** �����ǣ��ο�#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** ͼ������ */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of �������� */
    /** ͼ������(����·��)�б��澯���Ϊ������ٸ澯ʱ����0��ͼƬΪ�ϳ�ͼƬ����1��ͼƬΪʻ��ͼƬ����2��ͼƬΪʻ��ͼƬ */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊ������룬�������Ϊ�� */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊ�������ƣ��������Ϊ�� */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ�����ڱ�ţ��������Ϊ�� */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ���������ƣ��������Ϊ�� */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ�����ڳ����ţ��������Ϊ0 */
    ULONG_32 ulLaneNumber2;

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection2;

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ�������ƣ��������Ϊ�� */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ������ʱ�䣬�������szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊ������룬��λ:�ף��������Ϊ0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of �������� */

    /** �Ƿ�Ϊ����ͼƬ��1:����ͼƬ; 0:����ͼƬ��������λ�ӵ͵��ߣ�ÿ������λ��ʾһ��ͼƬ
    aszImgList:1 ~ 4, ���Ʋ�ɫ����ͼƬ:5, ���ƶ�ֵ������ͼƬ:6, ��ʻ������ͼƬ:7, ����ʻ������ͼƬ:8, ��������ͼƬ:9 */
    ULONG_32 ulIsForeign;

    /** Υ�µص���� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** Υ�µص����� */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** �ɼ��豸���� */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** У���û����� */
    CHAR szCorrectUserCode[IMOS_CODE_LEN];

    /** У��ʱ�� */
    CHAR szCorrectTime[IMOS_TIME_LEN];

    /** �����û����� */
    CHAR szDoneUserCode[IMOS_CODE_LEN];

    /** ����ʱ�� */
    CHAR szDoneTime[IMOS_TIME_LEN];

    /** �ɼ����ر��� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** �ɼ��������� */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** ��ʻ����,�澯���Ϊ������ٸ澯ʱ��Ϊʻ�뿨����ʻ���� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʻ����2,ͨ������szDirection,�澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ���� */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** �������� */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** �������� */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** �ϳ�ͼƬ��ʶ��BOOL_TRUE:aszImgList[0]Ϊ�ϳ�ͼƬ��BOOL_FALSE:�޺ϳ�ͼƬ */
    ULONG_32 ulCombineFlag;

    /** �������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** β���������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** ������������λkg */
    ULONG_32 ulVehicleWeight;

    /** ͨ��ʱ��/������������Ϊ�������ʱ��Ϊʻ�뿨��ʱ�� ֧�ֺ��� */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ������ʱ�䣬�������szPassTime ֧�ֺ��� */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** ����ʱ�䣬�澯���Ϊ������ٸ澯ʱ��Ϊʻ������ʱ�� ֧�ֺ��� */
    CHAR  szAlarmTimeEx[IMOS_TIME_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[64];

} VEHICLE_ALARM_DATA_S;

/**
 * @struct tagVehicleAlarmDataV2
 * @brief ����������¼V2���ڲ�ʹ��
 * @attention
 */
typedef struct tagVehicleAlarmDataV2
{
    /** ����������Ϣ��� */
    CHAR  szVehicleAlarmCode[IMOS_CODE_LEN];

    /** ������Ϣ��ţ���ѯ���أ���������¿��Բ��� */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** �������ͣ�ȡֵΪDISPOSITION_INTER_TYPE_LOCAL����DISPOSITION_INTER_TYPE_LOWER */
    ULONG_32 ulInterType;

    /** ���ڱ�ţ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** �������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** �����ţ���ѯ���أ���������¿��Բ��� */
    ULONG_32 ulLaneNumber;

    /** ��ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection;

    /** ��ʻ�������ƣ��ѷ��� */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** ͨ��ʱ��/�澯���Ϊ������ٸ澯ʱ��Ϊʻ�뿨��ʱ�� */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** �������� */
    ULONG_32 ulLicensePlateNum;

    /** ���ƺ��� */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** �������࣬�ο������ֵ� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �����ٶȣ���λKm/h���澯���Ϊ������ٸ澯ʱ��Ϊ����ƽ����ʻ�ٶ� */
    ULONG_32 ulVehicleSpeed;

    /** ��ʾ���٣���λKm/h����ѯ���أ���������¿��Բ��� */
    ULONG_32 ulMarkedSpeed;

    /** �������٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** ����Ʒ�ƣ��ο������ֵ� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ��������λ: ���� */
    ULONG_32 ulVehicleLen;

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ� */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** �澯��𣬲ο�#VEHICLE_ALARM_TYPE_E */
    ULONG_32 ulAlarmType;

    /** ���ݸ澯�����д������ǲ��ر�������Ϊ���ر�ţ�����Ǻ�������������Ϊ��������š��������������Ϊ�� */
    CHAR  szDispositionCode[IMOS_CODE_LEN];

    /** ������𣬲ο������ֵ䣬���ر�������ֵ������Ϊ�� */
    CHAR  szDispositionType[IMOS_DICTIONARY_KEY_LEN];

    /** ����ʱ�䣬�澯���Ϊ������ٸ澯ʱ��Ϊʻ������ʱ�� */
    CHAR  szAlarmTime[IMOS_TIME_LEN];

    /** �����ǣ��ο�#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** ͼ������ */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of �������� */
    /** ͼ������(����·��)�б��澯���Ϊ������ٸ澯ʱ����0��ͼƬΪ�ϳ�ͼƬ����1��ͼƬΪʻ��ͼƬ����2��ͼƬΪʻ��ͼƬ */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊ������룬�������Ϊ�� */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊ�������ƣ��������Ϊ�� */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ�����ڱ�ţ��������Ϊ�� */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ���������ƣ��������Ϊ�� */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ�����ڳ����ţ��������Ϊ0 */
    ULONG_32 ulLaneNumber2;

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection2;

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ�������ƣ��������Ϊ�� */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊʻ������ʱ�䣬�������szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** �澯���Ϊ������ٸ澯ʱ��Ϊ������룬��λ:�ף��������Ϊ0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of �������� */

    /** �Ƿ�Ϊ����ͼƬ��1:����ͼƬ; 0:����ͼƬ��������λ�ӵ͵��ߣ�ÿ������λ��ʾһ��ͼƬ
    aszImgList:1 ~ 4, ���Ʋ�ɫ����ͼƬ:5, ���ƶ�ֵ������ͼƬ:6, ��ʻ������ͼƬ:7, ����ʻ������ͼƬ:8, ��������ͼƬ:9 */
    ULONG_32 ulIsForeign;

    /** Υ�µص���� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** Υ�µص����� */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** �ɼ��豸���� */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** У���û����� */
    CHAR szCorrectUserCode[IMOS_CODE_LEN];

    /** У��ʱ�� */
    CHAR szCorrectTime[IMOS_TIME_LEN];

    /** �����û����� */
    CHAR szDoneUserCode[IMOS_CODE_LEN];

    /** ����ʱ�� */
    CHAR szDoneTime[IMOS_TIME_LEN];

    /** �ɼ����ر��� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** �ɼ��������� */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** ��ʻ����,�澯���Ϊ������ٸ澯ʱ��Ϊʻ�뿨����ʻ���� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʻ����2,ͨ������szDirection,�澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ���� */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** �������� */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** �������� */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** �ϳ�ͼƬ��ʶ��BOOL_TRUE:aszImgList[0]Ϊ�ϳ�ͼƬ��BOOL_FALSE:�޺ϳ�ͼƬ */
    ULONG_32 ulCombineFlag;

    /** ���Ʋ�ɫ����ͼƬ */
    CHAR szPlatePic[IMOS_URL_LEN];

    /** ���ƶ�ֵ������ͼƬ */
    CHAR szBinaryPlatePic[IMOS_URL_LEN];

    /** ��ʻ������ͼƬ */
    CHAR szDriveCabPic[IMOS_URL_LEN];

    /** ����ʻ������ͼƬ */
    CHAR szAssistDriveCabPic[IMOS_URL_LEN];

    /** ��������ͼƬ */
    CHAR szVehicleLogoPic[IMOS_URL_LEN];

    /** ����¼���ַ */
    CHAR szRelateVideoAddr[IMOS_URL_LEN];

    /** �������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** β���������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** ������������λkg */
    ULONG_32 ulVehicleWeight;

    /** ͨ��ʱ��/������������Ϊ�������ʱ��Ϊʻ�뿨��ʱ�� ֧�ֺ��� */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ������ʱ�䣬�������szPassTime ֧�ֺ��� */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** ����ʱ�䣬�澯���Ϊ������ٸ澯ʱ��Ϊʻ������ʱ�� ֧�ֺ��� */
    CHAR  szAlarmTimeEx[IMOS_TIME_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[156];

} VEHICLE_ALARM_DATA_V2_S;

/**
 * @struct tagVehicleData
 * @brief ������ʻ��¼
 * @attention
 */
typedef struct tagVehicleData
{
    /** ������Ϣ��� */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ�ţ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** �������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** �����ţ���ѯ���أ���������¿��Բ��� */
    ULONG_32 ulLaneNumber;

    /** ��ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection;

    /** ��ʻ�������ƣ��ѷ��� */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** ͨ��ʱ��/������������Ϊ�������ʱ��Ϊʻ�뿨��ʱ�� */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** �������� */
    ULONG_32 ulLicensePlateNum;

    /** ���ƺ��� */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** �������࣬�ο������ֵ� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �����ٶȣ���λKm/h */
    ULONG_32 ulVehicleSpeed;

    /** ��ʾ���٣���λKm/h����ѯ���أ���������¿��Բ��� */
    ULONG_32 ulMarkedSpeed;

    /** �������٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** ����Ʒ�ƣ��ο������ֵ� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ��������λ: ���� */
    ULONG_32 ulVehicleLen;

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ� */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ʶ��ʱ�䣬��λ: ���� */
    ULONG_32 ulIdentifyTime;

    /** ʶ��״̬���ο�#VEHICLE_IDENTIFY_STATUS_E */
    ULONG_32 ulIdentifyStatus;

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** �����ǣ��ο�#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** ͼ������ */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of �������� */
    /** ͼ������(����·��)�б�������������Ϊ�������ʱ����0��ͼƬΪʻ��ͼƬ����1��ͼƬΪʻ��ͼƬ */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** �����������ͣ��ο�#VEHICLE_RECORD_TYPE_E */
    ULONG_32 ulVehicleDataType;

    /** ������������Ϊ�������ʱ��Ϊ�����ţ��������Ϊ�� */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** ������������Ϊ�������ʱ��Ϊ�������ƣ��������Ϊ�� */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ�����ڱ�ţ��������Ϊ�� */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ���������ƣ��������Ϊ�� */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ�����ڳ����ţ��������Ϊ0 */
    ULONG_32 ulLaneNumber2;

    /** ������������Ϊ�������ʱ��Ϊʻ��������ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection2;

    /** ������������Ϊ�������ʱ��Ϊʻ��������ʻ�������ƣ��������Ϊ�� */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ������ʱ�䣬�������szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** ������������Ϊ�������ʱ��Ϊ������룬��λ:�ף��������Ϊ0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of �������� */

    /** �Ƿ�Ϊ����ͼƬ��1:����ͼƬ; 0:����ͼƬ��������λ�ӵ͵��ߣ�ÿ������λ��ʾһ��ͼƬ
    aszImgList:1 ~ 4, ���Ʋ�ɫ����ͼƬ:5, ���ƶ�ֵ������ͼƬ:6, ��ʻ������ͼƬ:7, ����ʻ������ͼƬ:8, ��������ͼƬ:9 */
    ULONG_32 ulIsForeign;

    /** �ص���� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** �ص����� */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** �ɼ����� */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** �ɼ����ر��� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** �ɼ��������� */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** ��ʻ����,�澯���Ϊ������ٸ澯ʱ��Ϊʻ�뿨����ʻ���� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʻ����2,ͨ������szDirection,�澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ���� */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** �������� */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** �������� */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** �������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** β���������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** ������������λkg */
    ULONG_32 ulVehicleWeight;

    /** ͨ��ʱ��/������������Ϊ�������ʱ��Ϊʻ�뿨��ʱ�� ֧�ֺ��� */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ������ʱ�䣬�������szPassTime ֧�ֺ��� */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[100];
} VEHICLE_DATA_S;


/**
 * @struct tagVehicleDataV2
 * @brief ������ʻ��¼V2���ڲ�ʹ��
 * @attention
 */
typedef struct tagVehicleDataV2
{
    /** ������Ϣ��� */
    CHAR  szVehicleDataCode[IMOS_CODE_LEN];

    /** ���ڱ�ţ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateCode[IMOS_CODE_LEN];

    /** �������ƣ���ѯ���أ���������¿��Բ��� */
    CHAR  szTollgateName[IMOS_NAME_LEN];

    /** �����ţ���ѯ���أ���������¿��Բ��� */
    ULONG_32 ulLaneNumber;

    /** ��ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection;

    /** ��ʻ�������ƣ��ѷ��� */
    CHAR szDirectionName[IMOS_NAME_LEN];

    /** ͨ��ʱ��/������������Ϊ�������ʱ��Ϊʻ�뿨��ʱ�� */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** �������� */
    ULONG_32 ulLicensePlateNum;

    /** ���ƺ��� */
    CHAR  aszLicensePlateList[IMOS_MAX_LICENSE_PLATE_NUM][IMOS_CODE_LEN];

    /** �������࣬�ο������ֵ� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �����ٶȣ���λKm/h */
    ULONG_32 ulVehicleSpeed;

    /** ��ʾ���٣���λKm/h����ѯ���أ���������¿��Բ��� */
    ULONG_32 ulMarkedSpeed;

    /** �������٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** ����Ʒ�ƣ��ο������ֵ� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ��������λ: ���� */
    ULONG_32 ulVehicleLen;

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ� */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** ʶ��ʱ�䣬��λ: ���� */
    ULONG_32 ulIdentifyTime;

    /** ʶ��״̬���ο�#VEHICLE_IDENTIFY_STATUS_E */
    ULONG_32 ulIdentifyStatus;

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** �����ǣ��ο�#VEHICLE_DEAL_STATUS_E */
    ULONG_32 ulDealStatus;

    /** ͼ������ */
    ULONG_32 ulImgNum;

    /* Begin modified by b02795, 2011-11-08 of �������� */
    /** ͼ������(����·��)�б�������������Ϊ�������ʱ����0��ͼƬΪʻ��ͼƬ����1��ͼƬΪʻ��ͼƬ */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_URL_LEN];

    /** �����������ͣ��ο�#VEHICLE_RECORD_TYPE_E */
    ULONG_32 ulVehicleDataType;

    /** ������������Ϊ�������ʱ��Ϊ�����ţ��������Ϊ�� */
    CHAR szSectionCode[IMOS_CODE_LEN];

    /** ������������Ϊ�������ʱ��Ϊ�������ƣ��������Ϊ�� */
    CHAR szSectionName[IMOS_NAME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ�����ڱ�ţ��������Ϊ�� */
    CHAR  szTollgateCode2[IMOS_CODE_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ���������ƣ��������Ϊ�� */
    CHAR  szTollgateName2[IMOS_NAME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ�����ڳ����ţ��������Ϊ0 */
    ULONG_32 ulLaneNumber2;

    /** ������������Ϊ�������ʱ��Ϊʻ��������ʻ�����ţ��ѷ��� */
    ULONG_32 ulDirection2;

    /** ������������Ϊ�������ʱ��Ϊʻ��������ʻ�������ƣ��������Ϊ�� */
    CHAR szDirectionName2[IMOS_NAME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ������ʱ�䣬�������szPassTime */
    CHAR  szPassTime2[IMOS_TIME_LEN];

    /** ������������Ϊ�������ʱ��Ϊ������룬��λ:�ף��������Ϊ0 */
    ULONG_32 ulSectionDistance;
    /* End modified by b02795, 2011-11-08 of �������� */

    /** �Ƿ�Ϊ����ͼƬ��1:����ͼƬ; 0:����ͼƬ��������λ�ӵ͵��ߣ�ÿ������λ��ʾһ��ͼƬ
    aszImgList:1 ~ 4, ���Ʋ�ɫ����ͼƬ:5, ���ƶ�ֵ������ͼƬ:6, ��ʻ������ͼƬ:7, ����ʻ������ͼƬ:8, ��������ͼƬ:9 */
    ULONG_32 ulIsForeign;

    /** �ص���� */
    CHAR szPlaceCode[IMOS_CODE_LEN];

    /** �ص����� */
    CHAR szPlaceName[IMOS_NAME_LEN];

    /** �ɼ����� */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** �ɼ����ر��� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** �ɼ��������� */
    CHAR szDeptName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /** ��ʻ����,�澯���Ϊ������ٸ澯ʱ��Ϊʻ�뿨����ʻ���� */
    CHAR szDirection[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʻ����2,ͨ������szDirection,�澯���Ϊ������ٸ澯ʱ��Ϊʻ��������ʻ���� */
    CHAR szDirection2[IMOS_DICTIONARY_KEY_LEN];

    /** �������� */
    CHAR szPlateCoordinate[IMOS_COORDINATE_LEN];

    /** �������� */
    CHAR szLogoCoordinate[IMOS_COORDINATE_LEN];

    /** ���Ʋ�ɫ����ͼƬ */
    CHAR szPlatePic[IMOS_URL_LEN];

    /** ���ƶ�ֵ������ͼƬ */
    CHAR szBinaryPlatePic[IMOS_URL_LEN];

    /** ��ʻ������ͼƬ */
    CHAR szDriveCabPic[IMOS_URL_LEN];

    /** ����ʻ������ͼƬ */
    CHAR szAssistDriveCabPic[IMOS_URL_LEN];

    /** ��������ͼƬ */
    CHAR szVehicleLogoPic[IMOS_URL_LEN];

    /** ����¼���ַ */
    CHAR szRelateVideoAddr[IMOS_URL_LEN];

    /** �������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulPlateConfidence;

    /** β���������Ŷȣ�ȡֵ��Χ[0, 100] */
    ULONG_32 ulRearPlateConfidence;

    /** ������������λkg */
    ULONG_32 ulVehicleWeight;

    /** ͨ��ʱ��/������������Ϊ�������ʱ��Ϊʻ�뿨��ʱ�� ֧�ֺ��� */
    CHAR  szPassTimeEx[IMOS_TIME_LEN];

    /** ������������Ϊ�������ʱ��Ϊʻ������ʱ�䣬�������szPassTime ֧�ֺ��� */
    CHAR  szPassTime2Ex[IMOS_TIME_LEN];

    /** Ԥ���ֶ� */
    CHAR szReserve[188];
} VEHICLE_DATA_V2_S;

/**
 * @struct tagVehicleRealTimeData
 * @brief ����ʵʱ��ʾ��¼
 * @attention
 */
typedef struct tagVehicleRealTimeData
{
    /** XP������� */
    CHAR szXPWinCode[IMOS_CODE_LEN];

    /** ������� */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /** ����������Ϣ */
    VEHICLE_DATA_S stVehicleData;
}VEHICLE_REAL_TIME_DATA_S;

/**
 * @struct tagDeviceGISStatusData
 * @brief �豸GIS״̬��Ϣ
 * @attention
 */
typedef struct tagDeviceGISStatusData
{
    /** �豸���� */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** �豸����״̬���ο�#DEVICE_GIS_STATUS_E */
    ULONG_32 ulDevStatus;
}DEVICE_GIS_STATUS_DATA_S;


/**
* @struct tagNeighborCameraInfo
* @brief �ܱ������λ����Ϣ�ṹ
* @attention
*/
typedef struct tagNeighborCameraInfo
{
    /** ��������� */
    CHAR    szCamCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR    szCamName[IMOS_NAME_LEN];

    /** ���� */
    CHAR    szLongitude[IMOS_COORDINATE_LEN];

    /** γ�� */
    CHAR    szLatitude[IMOS_COORDINATE_LEN];

    /** ���������, ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32    ulCameraType;

    /** ��ǰ���룬��λ:m */
    ULONG_32    ulDistance;

    /** ��ǰ��λ��ȡ1~12���ӷ��� */
    ULONG_32    ulAzimuth;

}NEIGHBOR_CAMERA_INFO_S;

/**
 * @struct tagWebGisScaleInfo
 * @brief WebGIS ��ͼ��������Ϣ
 * @attention
 */
typedef struct tagWebgisScaleInfo
{
    /** ������ID */
    ULONG_32 ulScaleID;

    /** ���������� */
    CHAR    szScaleName[IMOS_NAME_LEN];

    /** �����߲㼶 */
    ULONG_32   ulScaleNum;

    /** �����ߵ����ݣ���Ÿ�ʽ"100,200"����λ����  */
    CHAR    szScaleInfo[256];

}WEBGIS_SCALE_INFO_S;

/**
 * @struct tagWebGisBaseInfo
 * @brief WebGIS ��ͼ��Ϣ
 * @attention
 */
typedef struct tagWebGisBaseInfo
{
    /** ��ͼ���� */
    CHAR        szGISCode[IMOS_CODE_LEN];

    /** ��ͼ���� */
    CHAR        szGISName[IMOS_NAME_LEN];

    /** �Ƿ��ǵ�������ͼ��1:��������ͼ��0:�ǵ�������ͼ */
    BOOL_T      bIsThirdParty;

    /** ��ͼ���ͣ�ȡֵ#WEBGIS_MAP_TYPE */
    ULONG_32       ulGisMapType;

    /** Ĭ�ϵ�ͼ���λ��1:Ĭ�ϵ�ͼ��0:��Ĭ�ϵ�ͼ */
    BOOL_T      bIsDefaultMap;

    /** Map����URL */
    CHAR        szMapServiceUrl[IMOS_URL_LEN];

    /** Feature����URL,�ɲ�����ڲ�ѯ������Ҫ�� */
    CHAR        szFeatureSrvUrl[IMOS_URL_LEN];

    /** ͼ������ */
    CHAR        szBaseLayerName[IMOS_WEBGIS_LAYER_NAME_LEN];

    /** .map�ļ�Name */
    CHAR        szConfigName[IMOS_NAME_LEN];

    /** ��ɫ���� */
    CHAR        szColorScheme[IMOS_DESC_LEN];

    /** ��ͼ��С���� */
    CHAR        szMinLongitude [IMOS_COORDINATE_LEN];

    /** ��ͼ��Сγ�� */
    CHAR        szMinlatitude [IMOS_COORDINATE_LEN];

    /** ��ͼ��󾭶� */
    CHAR        szMaxLongitude [IMOS_COORDINATE_LEN];

    /** ��ͼ���γ�� */
    CHAR        szMaxlatitude [IMOS_COORDINATE_LEN];

    /** TMS��ͼ������ID */
    ULONG_32       ulTmsScaleID;

    /** �����ֶ� */
    CHAR        szReserve[252];
}WEBGIS_BASE_INFO_S;


/**
 * @struct tagWebGisAttentivePoint
 * @brief WebGIS ��ע����Ϣ
 * @attention
 */
typedef struct tagWebGisAttentivePoint
{
    /** ��ע����� */
    CHAR    szPointCode[IMOS_CODE_LEN];

    /** ��ע������ */
    CHAR    szPointName[IMOS_NAME_LEN];

    /** �Ƿ���Ĭ�ϵ㣬1:Ĭ�ϵ㣬0:��Ĭ�ϵ� */
    BOOL_T  bIsDefaultPoint;

    /** ������ͼ���� */
    CHAR    szGisCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR    szLongitude [IMOS_COORDINATE_LEN];

    /** γ�� */
    CHAR    szlatitude [IMOS_COORDINATE_LEN];

    /** ���ż��� */
    ULONG_32   ulZoomLevel;

    /** ���� */
    CHAR    szPointDesc[IMOS_DESC_LEN];

    /** �����ֶ� */
    CHAR    szReserve[128];

}WEBGIS_ATTENTIVE_POINT_S;


/**
* @struct tagCommunityCameraInfo
* @brief ����������Դ��Ϣ�ṹ
* @attention
*/
typedef struct tagCommunityCameraInfo
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** ��������ͣ�ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32   ulCameraType;

    /** �����ʹ��״̬��ȡֵΪ#COMMUNITY_CAMERA_STATUS_E */
    ULONG_32   ulCameraStatus;

    /** �����ֱ����֯���� */
    CHAR    szParOrgCode[IMOS_CODE_LEN];

    /** �����ֱ����֯���� */
    CHAR    szParOrgName[IMOS_NAME_LEN];

    /** ������ͺ� */
    CHAR    szCameraModel[IMOS_NAME_LEN];

    /** ��������� */
    CHAR    szManufacturer[IMOS_NAME_LEN];

    /** ��װ�ص� */
    CHAR    szLocation[IMOS_STRING_LEN_256];

    /** ������λ */
    CHAR    szDepartment[IMOS_NAME_LEN];

    /** �����������ϵ������ */
    CHAR    szMPerson[IMOS_NAME_LEN];

    /** �����������ϵ�绰 */
    CHAR    szTelephone[IMOS_PHONE_LEN];

    /** ���� */
    CHAR    szLongitude[IMOS_COORDINATE_LEN];

    /** γ�� */
    CHAR    szLatitude[IMOS_COORDINATE_LEN];

    /** ���� */
    CHAR    szaltitude[IMOS_COORDINATE_LEN];

    /** ���������� */
    CHAR szDecoderTag[IMOS_STRING_LEN_64];

    /** ָ�� */
    CHAR    szDirection[IMOS_STRING_LEN_32];

    /** �ӽ� */
    CHAR    szViewAngle[IMOS_STRING_LEN_32];

    /** ���Ӿ��� */
    CHAR    szVisibleRange[IMOS_STRING_LEN_32];

}COMMUNITY_CAMERA_INFO_S;

/**
* @struct tagDatabaseInfo
* @brief ���ݿ���Ϣ
* @attention
*/
typedef struct tagDatabaseInfo
{
    /** ���ݿ�IP��ַ */
    CHAR    szDatabaseIp[IMOS_IPADDR_LEN];

    /** ���ݿ����� */
    CHAR    szDatabaseName[IMOS_NAME_LEN];

    /** ���ݿ�˿� */
    ULONG_32   ulPort;

    /** ���ݿ��û� */
    CHAR    szUser[IMOS_NAME_LEN];

    /** ���ݿ����� */
    CHAR    szPassword[IMOS_PASSWD_LEN];

    /** ���ݿ������:"SQLServer";"Oracle","PostgreSQL";"Sqlite" */
    CHAR    szDBType[IMOS_NAME_LEN];

    /** �����ֶ� */
    CHAR    szReserve[256];
}DATABASE_INFO_S;

/**
* @struct tagCameraViewInfo
* @brief ��������ӽ���Ϣ
* @attention
*/
typedef struct tagCameraViewInfo
{
    /** ��������� */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /** ָ�� */
    CHAR    szDirection[IMOS_STRING_LEN_32];

    /** �ӽ� */
    CHAR    szViewAngle[IMOS_STRING_LEN_32];

    /** ���Ӿ��� */
    CHAR    szVisibleRange[IMOS_STRING_LEN_32];
}CAMERA_VIEW_INFO_S;

 /**
 * @struct tagCenterStoreActionInfo
 * @brief ����ģ�鷢����������������洢������Ϣ�ṹ
 * @attention
 */
typedef struct tagCenterStoreActionInfo
{
    /** �澯Դ���� */
    CHAR    szAlarmSrcCode[IMOS_CODE_LEN];

    /** �澯���� */
    ULONG_32   ulAlarmType;

    /** ��Ϣ�ܸ��� */
    ULONG_32 ulTotalNum;

    /** �ڼ�����Ϣ */
    ULONG_32 ulCurrentNum;

    /** �洢���������д洢������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM */
    ULONG_32  ulCenterStoreActionNum;

    /** ������洢�������� */
    STORE_ACTION_S  astCenterStoreAction[IMOS_ALARM_CENTER_STORE_ACTION_MAXNUM];

}CENTER_STORE_ACTION_INFO_S;

/**
* @struct tagThirdDeviceError
* @brief �������豸����ṹ
* @attention
*/
typedef  struct  tagThirdDeviceError
{
    /** ����Դ���� */
    CHAR    szDevCode[IMOS_CODE_LEN];

    /** ����Դ�� */
    CHAR    szDevName[IMOS_NAME_LEN];

    /** ����ʱ�� */
    CHAR   szTime[IMOS_TIME_LEN];

    /** �������� */
    CHAR  szDesc[IMOS_DESC_LEN];
}THIRD_DEVICE_ERROR_S;

/**
* @struct tagMgSessionStatusEx
* @brief ������洢��Դ�ͷ��ϱ��ṹ
* @attention
*/
typedef struct tagFreeStoreResSucceed
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_CODE_LEN];
}FREE_STORE_RES_SUCCEED_S;

/**
 * @struct tagLinkWallLabel
 * @brief �澯������ǽ��ע��Ϣ
 * @attention
 */
typedef struct tagLinkWallLabel
{
    /** ������ע��0Ϊ�����ã�1Ϊ���� */
    ULONG_32 ulEnabledFlag;

    /** ����OSD����*/
    CHAR szOsdString[IMOS_NAME_LEN];

    /** ����OSD�������� */
    AREA_SCOPE_S stAreaScope;

    /** OSD��ɫ, ȡֵΪ#IMOS_OSD_COLOR_E */
    ULONG_32 ulOsdColor;

    /**�л�ʱ��, ��λΪ��, ȡֵΪ0~300��ȡֵΪ0, ����˸*/
    ULONG_32 ulSwitchIntval;

    /** Ԥ���ֶ� */
    CHAR szReserve[128];
} LINK_WALL_LABEL_INFO_S;


/**
 * @struct  tagAlarmLinkageStoreInfo
 * @brief �澯����¼��洢��Ϣ
 * @attention
 */
typedef struct tagAlarmLinkageStoreInfo
{
    /** ��ʼ�洢ʱ�� */
    CHAR    szBeginStoreTime[IMOS_TIME_LEN];

    /** �澯Դ���� */
    CHAR    szAlarmSrcCode[IMOS_CODE_LEN];

    /** �����ֶ� */
    CHAR    szReserved[128];
}ALARM_LINKAGE_STORE_INFO_S;

/**
 * @struct  tagExDomainCamStoreInfo
 * @brief ���������¼��洢��Ϣ
 * @attention
 */
typedef struct tagExDomainCamStoreInfo
{
    /** ��������� */
    CHAR    szCameraCode[IMOS_CODE_LEN];

    /** ��������� */
    CHAR    szCameraName[IMOS_NAME_LEN];

    /** ¼��洢�Ƿ���� */
    BOOL_T  bStoreExist;

    /** �����ֶ� */
    CHAR    szReserved[128];
}EXDOMAIN_CAM_STORE_INFO_S;

/**
* @struct tagIpAddressInfo
* @brief �û���¼����IP��ַ�ṹ
* @attention
*/
typedef struct tagIpAddressInfo
{
    /** ��ַ���ͣ�#IMOS_IPADDR_TYPE_IPV4ΪIPv4����; #IMOS_IPADDR_TYPE_IPV6ΪIPv6���� */
    ULONG_32 ulIpAddrType;

    /** ��ʼIP��ַ */
    CHAR szStartIpAddress[IMOS_IPADDR_LEN];

    /** ����IP��ַ�����ֻ��һ����ַ����Ϊ�� */
    CHAR szEndIpAddress[IMOS_IPADDR_LEN];
}IP_ADDRESS_INFO_S;

/**
* @struct tagMacAddressInfo
* @brief �û���¼����MAC��ַ�ṹ
* @attention
*/
typedef struct tagMacAddressInfo
{
    /** MAC��ַ */
    CHAR szMacAddress[IMOS_MAC_ADDR_LEN];
}MAC_ADDRESS_INFO_S;

/**
* @struct tagLoginExtInfo
* @brief �û���¼��չ��Ϣ
* @attention
*/
typedef struct tagLoginExtInfo
{
    /** IP��ַ */
    CHAR szIpAddress[IMOS_IPADDR_LEN];

    /** MAC��ַ���� */
    ULONG_32 ulOperMachineMacNum;

    /** MAC��ַ�б� */
    MAC_ADDRESS_INFO_S astOperMachineMac[IMOS_MAX_LOGIN_ADDRESS_NUM];

    /** �û���¼������, �������û�����/�û�����, ȡֵ#USER_LOGIN_NAME_TYPE */
    ULONG_32 ulLoginNameType;

    /** �û�ǰ�˵����� ȡֵ#USER_CLIENT_TYPE_E */
    ULONG_32 ulLoginType;

    /** ����ϵͳ���� ���� */
    ULONG_32 ulOSType;

    /** �����ֶ� */
    CHAR  szReserve[116];
}LOGIN_EXT_INFO_S;

/**
* @struct tagUserLoginBindInfo
* @brief �û���¼���ư���Ϣ
* @attention
*/
typedef struct tagUserLoginBindInfo
{
    /** �Ƿ��������¼, #BOOL_TRUEʱ����; #BOOL_FALSEʱ������ */
    BOOL_T bAllowLoginAtSameTime;

    /** �Ƿ��IP, #BOOL_TRUEʱ��; #BOOL_FALSEʱ���� */
    BOOL_T bBindIP;

    /** IP��ַ���� */
    ULONG_32 ulOperMachineIpNum;

    /** IP��ַ�б� */
    IP_ADDRESS_INFO_S astOperMachineIp[IMOS_MAX_BINDING_ADDRESS_NUM];

    /** �Ƿ��MAC, #BOOL_TRUEʱ��; #BOOL_FALSEʱ���� */
    BOOL_T bBindMac;

    /** MAC��ַ���� */
    ULONG_32 ulOperMachineMacNum;

    /** MAC��ַ�б� */
    MAC_ADDRESS_INFO_S astOperMachineMac[IMOS_MAX_BINDING_ADDRESS_NUM];

    /** �󶨲��� 1: ʹ��ȫ������ 2: ʹ���������� 3: �����κ����� */
    ULONG_32 ulBindPolicy;

    /** �����ֶ� */
    CHAR  szReserve[128];
}USER_LOGIN_BIND_INFO_S;

/**
* @struct tagXpLayoutInfo
* @brief XP���񲼾���Ϣ
* @attention
*/
typedef struct tagXpLayoutInfo
{
    /** ���ֱ��� */
    CHAR szXpLayoutCode[IMOS_CODE_LEN];

    /** ���������ַ��� */
    CHAR szXpLayoutDesc[IMOS_XP_LAYOUT_DESC_LEN];

    /** Ԥ���ֶ� */
    CHAR  szReserved[128];
}XP_LAYOUT_INFO_S;

/**
* @struct tagMediaStatusNotify
* @brief ý��״̬֪ͨ��Ϣ
* @attention
*/
typedef struct tagMediaStatusNotify
{
    ULONG_32 ulReleaseCode;            /* �ͷ�ԭ�� */
    CHAR szSrcUAID[IMOS_UAID_LEN];  /* ԴUAID */
    CHAR szDstUAID[IMOS_UAID_LEN];  /* Ŀ��UAID */
}MEDIA_STATUS_NOTIFY_S;

/**
* @struct tagSerialAllInfoQueryItem
* @brief ���������豸������Ϣ��ѯ�б�ṹ�� for UI �����������
* @attention ��
*/
typedef struct tagSerialAllInfoQueryItem
{
    /** �������� */
    ULONG_32   ulSerialIndex;

    /** �������� */
    ULONG_32   ulSerialType;

    /* ����ģʽ */
    ULONG_32       ulSerialMode;

    /* �����豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸���� */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /* �豸���� */
     ULONG_32 ulDevType;

     /* �豸������ */
     ULONG_32 ulSubDevType;

     /* �����ֶ�0 */
     ULONG_32 ulSpare0;

     /* �豸�ֶ�1 */
     ULONG_32 ulSpare1;
}SERIAL_ALLINFO_QUERY_ITEM_S;

/**
* @struct tagSemaOutAllInfoQueryItem
* @brief ���������豸�����������Ϣ��ѯ�б�ṹ��for UI �����������
* @attention ��
*/
typedef struct tagSemaOutAllInfoQueryItem
{
     /** ���������� */
    ULONG_32       ulSemaOutputIndex;

    /** ���������״̬  */
    ULONG_32       ulSemaOutputStatus;  /* 1��ʾ������2��ʾ���� */

    /** �Ƿ�ʹ�� */
    ULONG_32       ulEnabledFlag;   /* 0��ʾʹ�ܣ�1��ʾ��ʹ�ܣ��������������ʹ����д0 */

    /* �����豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸���� */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /* �豸���� */
     ULONG_32 ulDevType;

     /* �豸������ */
     ULONG_32 ulSubDevType;

     /* �����ֶ�0 */
     ULONG_32 ulSpare0;

     /* �豸�ֶ�1 */
     ULONG_32 ulSpare1;

}SEMAOUT_ALLINFO_QUERY_ITEM_S;

/**
* @struct tagSemaInAllInfoQueryItem
* @brief ���������豸���뿪������Ϣ��ѯ�б�ṹ��for UI �����������
* @attention ��
*/
typedef struct tagSemaInAllInfoQueryItem
{
     /** ���������� */
    ULONG_32       ulSemaInputIndex;

    /** ���뿪����״̬  */
    ULONG_32       ulSemaInputStatus;  /* 1��ʾ������2��ʾ���� */

    /** �Ƿ�ʹ�� */
    ULONG_32       ulEnabledFlag;   /* 0��ʾʹ�ܣ�1��ʾ��ʹ��*/

    /* �����豸���� */
    CHAR  szDevName[IMOS_NAME_LEN];

    /** �豸���� */
    CHAR    szDevCode[IMOS_DEVICE_CODE_LEN];

    /* �豸���� */
     ULONG_32 ulDevType;

     /* �豸������ */
     ULONG_32 ulSubDevType;

     /* �����ֶ�0 */
     ULONG_32 ulSpare0;

     /* �豸�ֶ�1 */
     ULONG_32 ulSpare1;

}SEMAIN_ALLINFO_QUERY_ITEM_S;

/**
 * @struct tagSThirdpartyIPC
 * @brief ������IPC��Ϣ
 * @attention
 */
typedef struct tagThirdpartyIPC
{
    /* �����������Ϣ */
    CAMERA_INFO_S  stBaseCameraInfo;

    /* ��������*/
    ULONG_32  ulCameraManutype;

    /* �豸��ַ*/
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /* �豸�˿�*/
    ULONG_32  ulDevPort;

    /* �������ͣ�0 ����ģ������� 1 IPC   */
    ULONG_32  ulCameraAccessType;

    /* �û��� */
    CHAR szUserName[IMOS_NAME_LEN];

    /* ���� */
    CHAR szPassword[IMOS_PASSWD_LEN];

    /* ���DVRͨ��ID,���� */
    ULONG_32 ulCameraChnId;

    /* IPC״̬��1��ʾ���ߣ�0��ʾ���� */
    ULONG_32 ulStatus;

    /** �鲥��ַ */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�,��ΧΪ��10002-65534���ұ���Ϊż�� */
    ULONG_32   ulMulticastPort;

    /* Added by zhuhongyan 00342 2013-3-18 for IVSD01426�������������� */
    /** ���ֱ��ý������Ŀ */
    ULONG_32 ulMaxStreamNum;

    /** �����ֶ� */
    CHAR szReserve[24];
} THIRDPARTY_IPC_S;

/**
 * @struct tagECInfoEx
 * @brief EC����������������Ϣ
 * @attention
 */
typedef struct tagECInfoEx
{
    /** EC����, EC��Ψһ��ʶ */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC���� */
    CHAR  szECName[IMOS_NAME_LEN];

    /** EC���ͣ�ȡֵΪ#IMOS_DEVICE_TYPE_E, �Ϸ�ȡֵ�μ�#ulChannum������˵�� */
    ULONG_32 ulECType;

    /** ECͨ������:
        ���ֳ���EC���Ͷ�Ӧ��ͨ����������:
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

    /** �Ƿ�֧���鲥, 1Ϊ֧��; 0Ϊ��֧�� */
    ULONG_32 ulIsMulticast;

    /** ���¸澯�¶�����, ȡֵΪ-100~49 */
    LONG_32 lTemperatureMax;

    /** ���¸澯�¶�����, ȡֵΪ50~100 */
    LONG_32 lTemperatureMin;

    /** �澯ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnableAlarm;

    /** EC������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ʱ��ͬ����ʽ��Ĭ��Ϊ1����ʾʹ��H3C��˽��ͬ����ʽ��2��ʾNTP��ͬ����ʽ(Ŀǰ�ݲ�֧��) */
    ULONG_32 ulTimeSyncMode;

    /** ʱ��, ȡֵΪ-12~12 */
    LONG_32 lTimeZone;

    /** �������ã������ķ����������ã�ȡֵΪ:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** �Ƿ����ñ��ػ��棬1��ʾ����; 0��ʾ��������Ĭ��ֵΪ0 */
    ULONG_32 ulEnableLocalCache;

    /** ���ײ�, ȡֵΪ:#IMOS_STREAM_RELATION_SET_E
        0��MPEG4+MPEG4(#IMOS_SR_MPEG4_MPEG4)
        1��H264������(#IMOS_SR_H264_SHARE)
        2��MPEG2+MPEG4(#IMOS_SR_MPEG2_MPEG4)
        3��H264+MJPEG(#IMOS_SR_H264_MJPEG)
        4��MPEG4������(#IMOS_SR_MPEG4_SHARE)
        5��MPEG2������(#IMOS_SR_MPEG2_SHARE)
        8: MPEG4������_D1(#IMOS_SR_STREAM_MPEG4_8D1)
        9��MPEG2+MPEG2(#IMOS_SR_MPEG2_MPEG2)
        11��H264+H264(#IMOS_SR_H264_H264)
    */
    ULONG_32 ulEncodeSet;

    /** ��ʽ, ȡֵΪ#IMOS_PICTURE_FORMAT_E */
    ULONG_32 ulStandard;

    /** ��Ƶ����Դ��ȡֵΪ#IMOS_AUDIO_INPUT_SOURCE_E */
    ULONG_32 ulAudioinSource;

    /** �����Խ���Դ���� */
    CHAR szAudioCommCode[IMOS_RES_CODE_LEN];

    /** �����㲥��Դ���� */
    CHAR szAudioBroadcastCode[IMOS_RES_CODE_LEN];

    /** �豸�������� */
    CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

    /** �豸����, Ŀǰ���ֶ�δʹ�� */
    CHAR    szDevDesc[IMOS_DESC_LEN];

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevaddrtype;

    /** EC��IP��ַ, ��Ӽ��޸�EC������д�ò���, ��ѯEC��Ϣʱ���ظ��ֶ� */
    CHAR szECIPAddr[IMOS_IPADDR_LEN];

    /** EC������״̬,��Ӽ��޸�EC������д�ò���, ��ѯEC��Ϣʱ���ظ��ֶ�, 1Ϊ����; 0Ϊ���� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��ȡֵΪ#DEV_EXT_STATUS_E */
    ULONG_32 ulDevExtStatus;

    /** ��ý���Э������,ȡֵΪ#IMOS_TRANS_TYPE_E��ĿǰECֻ֧��UDP��TCP */
    ULONG_32 ulStreamTransProtocol;
    /** �豸�汾��Ϣ */
    CHAR szECVer[IMOS_STRING_LEN_64];

    /* �������ֶΣ���ǰEC�µ�������б�,�����������ֵ����̬���䲻����ʣ��˻�������Ҫ���ȷ���ģ� */
    CAM_AND_CHANNEL_QUERY_ITEM_S astCameraInfo[IMOS_CAM_MAX_NUM];

    /** �����ֶ� */
    CHAR szReserve[28];

}EC_INFO_EX_S;

/**
*@ struct tagMMIScreenMapInfoForECR
*@ brief �����˻�Ԥ������������Ϣ�ṹ
*@ attention ��Ӧ�ڱ�tbl_mmi_preview_window_config
*/
typedef struct tagMMIScreenMapInfoForECR
{
    /** �������*/
    ULONG_32 ulWindowID;

    /** ���������*/
    CHAR szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ����ʶ 1-������2-����,Ŀǰ���ֶ���δʹ��,Ĭ������*/
    ULONG_32 ulStreamFlag;

    /** �����ֶ�*/
    ULONG_32 ulReserve;

}MMI_SCREEN_MAP_INFO_FOR_ECR_S;

/**
 *@ struct tagMMIVoutWinListInfoForECR
 *@ brief �˻�Ԥ�����������������Ϣ�ṹ(��������˿������Ϣ)
 *@ attention ��
 */
typedef struct tagMMIVoutWinListInfoForECR
{
    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1��������-���뿨 */
    /** ��λ�� */
    ULONG_32 ulSlotID;

    /** �˻�����˿����,ȡֵ�ο�#MMI_VEDIO_OUT_ID_E */
    ULONG_32 ulMMIVoutID;

    /** �˻�Ԥ��������� */
    ULONG_32 ulWindowNum;     /*added by t00764, 2013.2.25 of V5R2 -- IVSD00541 */

    /** �˻�Ԥ���������������������Ϣ */
    MMI_SCREEN_MAP_INFO_FOR_ECR_S astMMIScreenMap[IMOS_MAX_WINDOW_NUMBER];

} MMI_VOUT_WINLIST_INFO_FOR_ECR_S;

/**
 *@ struct tagMMIVoutInfoForECR
 *@ brief �˻�����˿ڱ������Ϣ�ṹ��
 *@ attention  ��Ӧ��tb1_mmi_vout
 */
typedef struct tagMMIVoutInfoForECR
{
    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1��������-���뿨 */
    /** ��λ�� */
    ULONG_32 ulSlotID;

    /** �˻�����˿����*/
    ULONG_32 ulMMIVoutID;

    /** ����ģʽ*/
    ULONG_32 ulSplitScn;

    /** �л�ʱ��*/
    ULONG_32 ulInterval;

    /** �Ƿ��������б�ʶ*/
    ULONG_32 ulSwitchFlag;

    /** �������������ȱ�־λ,1-��������, 0-��������*/
    ULONG_32 ulSubStreamFlag;

    /** �����ֶ�*/
    ULONG_32 ulReserve;

}MMI_VOUT_INFO_FOR_ECR_S;

/**
*@struct tagVirtualChannelBindStatusForECR
*@biref ����ͨ����״̬������Ϣ�ṹ��
*@attention ��Ӧ�� tbl_virtual_channel, tbl_device
*/
typedef struct tagVirtualChannelBindStatusForECR
{
    /** ����ͨ����� */
    ULONG_32 ulVirtualChannelID;

    /** ��ʶλ��#BOOL_FALSE-δ������ͨ�� #BOOL_TRUE-������ͨ��������δ������ͨ����������������� */
    ULONG_32 ulBindFlag;

    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1��������-���뿨 */
    /** ��λ�� */
    ULONG_32 ulSlotID;

    /** ��������˿���� */
    ULONG_32 ulVoutID;

    /** ����ͨ������Ӧ����Ƶͨ������ */
    ULONG_32 ulVinChannelIndex;

    /** ��Ӧ��������������� */
    CHAR szVirtualCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ������������� */
    CHAR szVirtualCameraName[IMOS_NAME_LEN];

    /** �����ֶ� */
    ULONG_32 ulReserve;

}VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S;
/* Begin: Added by chenyongfa, 2013-05-03 of IVSD00832 */
/**
*@struct tagVirtualChannelInfoForECR
*@biref �޸�����ͨ���ֱ���/֡��NOTIFY��Ϣ�ṹ��
*@attention
*/
typedef struct tagVirtualChannelInfoForECR
{
    /** �ֱ���, ȡֵΪ#IMOS_PICTURE_SIZE_E */
    ULONG_32       ulResolution;

    /** ֡��,��ȡ��ֵ��1, 3, 5, 8, 10, 15, 20, 25, 30 */
    ULONG_32       ulFrameRate;

    /** ����ͨ����� */
    VIRTUAL_CHANNEL_BIND_STATUS_FOR_ECR_S stVirtualChannelStatus;

}VIRTUAL_CHANNEL_INFO_FOR_ECR_S;
/* End: Added by chenyongfa, 2013-05-03 of IVSD00832 */

/**
*@struct tagBindVirtualChannel
*@brief ����ͨ���󶨻�����Ϣ�ṹ��
*@attention ��
*/
typedef struct tagVirtualChannelBindInfoForECR
{
    /** ����������ͨ����Ϣ */
    VINCHNL_BIND_CAMERA_FOR_ECR_S stVinChnAndCamInfo;

    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1��������-���뿨 */
    /** ��λ�� */
    ULONG_32 ulSlotID;

    /** ��������˿���� */
    ULONG_32 ulMMIVoutID;

    /** ����ͨ����ţ�Ŀǰ�̶�Ϊ1(ֻ֧��һ������ͨ��) */
    ULONG_32 ulVirtualChannelID;

}VIRTUAL_CHANNEL_BIND_INFO_FOR_ECR_S;

/**
*@struct tagReBindVirtualChannel
*@brief ����ͨ�����°󶨻�����Ϣ�ṹ��
*@attention ��
*/
typedef struct tagVirtualChannelReBindInfoForECR
{
    /* Added by hechengcheng00275, 2013.09.10 of IVSD02729 for V2R1��������-���뿨 */
    /** ��λ�� */
    ULONG_32 ulSlotID;

    /** ��������˿���� */
    ULONG_32 ulMMIVoutID;

    /** ����ͨ����ţ�Ŀǰ�̶�Ϊ1(ֻ֧��һ������ͨ��) */
    ULONG_32 ulVirtualChannelID;

}VIRTUAL_CHANNEL_REBIND_INFO_FOR_ECR_S;

/**
*@ CAM_SHARE_INFO_S
*@ brief ������Լ�ͨ����Ϣ��(��ѯ������Լ�ͨ���б�ʱ����)
*@ attention
*/
typedef struct tagCamShareInfo
{
    /** �豸ͨ��������Ϣ */
    DEV_CHANNEL_INDEX_S  stECChannelIndex;

    /** ��������� */
    CHAR szCamCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR szCamName[IMOS_NAME_LEN];

    /** ��������ͣ�ȡֵΪ#CAMERA_TYPE_E */
    ULONG_32 ulCamType;

    /** ��Դ�������� */
    CHAR szInterCode[IMOS_CODE_LEN];

    /** ���������״̬��1��ʾ����ɹ���0��ʾ���� */
    ULONG_32 ulState;

    /** �����ֶ� */
    CHAR szReserve[IMOS_CAM_SHARE_RESERVED_LEN];

    /** ��Դ������֯�ڵ� */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ��Դ�����豸���� */
    CHAR szDeviceName[IMOS_NAME_LEN];

}CAM_SHARE_INFO_S;

/**
*@ struct tagSemaShareInfo
*@ brief������������Ϣ��
*@ attention
*/
typedef struct tagSemaShareInfo
{
    /** ��Դ�����豸����*/
    CHAR szDeviceCode[IMOS_CODE_LEN];

    /** ��Դ�����豸����*/
    CHAR szDeviceName[IMOS_NAME_LEN];

    /** ͨ������*/
    ULONG_32 ulIndex;

    /** ����������״̬��1��ʾ����ʧ�ܣ�0��ʾ���� */
    ULONG_32 ulState;

    /** ���������ͣ�0��Ч��1��ʾ���룬2��ʾ��� */
    ULONG_32 ulSemaType;

    /** ��Դ���� */
    CHAR szResCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR szResName[IMOS_NAME_LEN];

    /** ��Դ�������� */
    CHAR szInterCode[IMOS_CODE_LEN];

    /** ��Դ������֯�ڵ� */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];
}SEMA_SHARE_INFO_S;

/**
* @struct tagSDKMUInit
* @brief SDK ��ʼ��ʱ�õĽṹ
*/
typedef struct tagSDKMUInit
{
    /** �������� */
    CHAR szProcName[IMOS_PROC_NAME_MAX_LEN];

    /** ����procID��IMOSϵͳ��ͳһ���䣬��ͬ���ͽ���ʹ����ͬ��procID�� */
    USHORT usProcID;

    /** �Ƿ�UI��ı�� */
    BOOL_T bUIFlag;

    /** �Ƿ����XP��� */
    BOOL_T bXPFlag;

    ULONG_32  ulSDKInitFlag;

    /* ������IP */
    CHAR    szServerAddr[IMOS_IPADDR_LEN];

    /* �������˿� */
    ULONG_32   ulServerPort;

    /** �ص�����ָ�� */
    SDK_CALL_BACK_PROC_PF pfnCallBackProc;

    /** �ص��������������ڻص���������θ�ֵ */
    VOID *pParam;

}SDK_MU_INIT_S;

/**
 * @struct tagDevInst
 * @brief DC�豸��ͨ������
 * @attention
 */
typedef struct  tagDevInst
{
    /**�������� �μ�#DEV_INST_TYPE_E */
    ULONG_32    ulInstType;

   /** ����ֵ1������ʱ��ƴ����Ϊ[a]x[b]��ʽ����a*b������Ϊƴ�ӵľ���ͨ����","�ָ���
    *  ģ��������Ϊģ��ö��ֵ0(��)/1(VGA)/2(DVI)����ѯʱ��ģ�����뷵��ģ��ö��ֵ */
    CHAR   szPara1[IMOS_STRING_LEN_256];

   /** ����ֵ2������ʱ��ƴ���µľ���ͨ����","�ָ���ģ��������Ϊ���������ͨ���š�
    *  ��ѯʱ������ÿ��ͨ���������ž���ͨ����","�����ƴ������ƴ�ӷ���0�� */
    CHAR   szPara2[IMOS_STRING_LEN_256];

   /** ����ֵ3������ */
    CHAR   szPara3[IMOS_STRING_LEN_256];

    /** �����ֶ� */
    CHAR szReserve[IMOS_STRING_LEN_128];
} DEVINST_S;

/*@brief ������Ϣ����ص��������ͣppstUserLoginIDInfoΪ�û���¼ID��Ϣ��ulProcTypeΪ�������ͣ�ö��ֵΪCALL_BACK_PROC_TYPE_E */
typedef VOID (STDCALL *CALL_BACK_PROC_EX_PF)(IN USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN ULONG_32 ulProcType, IN VOID *pParam);

/*@brief ������Ϣ����ص��������ͣppstUserLoginIDInfoΪ�û���¼ID��Ϣ��ulProcTypeΪ�������ͣ�ö��ֵΪCALL_BACK_PROC_TYPE_E��pClientParamΪ�û����õ�ָ����Ϣ */
typedef VOID (STDCALL *CALL_BACK_PROC_PF_V2)(IN USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo, IN ULONG_32 ulProcType, IN VOID *pParam, IN VOID *pClientParam);

/**
 * @struct tagVideoStreamExtendForECR
 * @brief ��Ƶ������չ��Ϣ
 * @attention
 */
typedef struct tagVideoStreamExtendForECR
{

    /** ��������, ȡֵΪ#IMOS_STREAM_TYPE_E, Ŀǰ��֧��#IMOS_ST_TS */
    ULONG_32       ulStreamType;

    /** ��������1Ϊ������2Ϊ���� */
    ULONG_32       ulStreamIndex;

    /** ��ʹ�ܱ�ʶ, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** �����䷽ʽ, ȡֵΪ#IMOS_TRANS_TYPE_E */
    ULONG_32       ulTranType;

    /** �����ʽ, ȡ���ھ�������ײ�ֵ, ȡֵΪ#IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /** �ֱ���, ȡֵΪ#IMOS_PICTURE_SIZE_E */
    ULONG_32       ulResolution;

    /** ���� */
    ULONG_32       ulBitRate;

    /** ֡��,��ȡ��ֵ��1, 3, 5, 8, 10, 15, 20, 25, 30 */
    ULONG_32       ulFrameRate;

    /** GOPģʽ, ȡֵΪ#IMOS_GOP_TYPE_E */
    ULONG_32       ulGopMode;

    /** I֡���, ȡ����GOPģʽֵ, ��GOPģʽΪ#IMOS_GT_Iʱ, I֡���Ϊ1; ��GOPģʽΪ#IMOS_GT_IPʱ, I֡���Ϊ10~50 */
    ULONG_32       ulIFrameInterval;

    /** ͼ������, ȡֵΪ#IMOS_VIDEO_QUALITY_E */
    ULONG_32       ulImageQuality;

    /** ������ģʽ, ȡֵΪ#IMOS_ENC_MODE_E */
    ULONG_32       ulEncodeMode;

    /** ���ȼ�, ���ڱ���ģʽΪ#IMOS_EM_CBRʱ�����ø�ֵ, ȡֵΪ#IMOS_CBR_ENC_MODE_E */
    ULONG_32       ulPriority;

    /** ����ƽ����ȡֵΪ#IMOS_STREAM_SMOOTH_E */
    ULONG_32       ulSmoothValue;

    /** �ֱ��ʵ�X��ֵ */
    ULONG_32       ulXValue;

    /** �ֱ��ʵ�Y��ֵ */
    ULONG_32       ulYValue;

}VIDEO_STREAM_EXTEND_FORECR_S;

/**
 * @struct tagIPCCamInfo
 * @brief  IPC�������Ϣ
 * @attention
 */
typedef struct tagIPCCamInfoForECR
{
    /** ����������豸����*/
    CHAR szDeviceCode[IMOS_CODE_LEN];

    /** ����������豸����*/
    CHAR szDeviceName[IMOS_NAME_LEN];

    /** ����������豸������Ϣ */
    CHAR szManufactureName[IMOS_NAME_LEN];

    /** ����������豸�ͺţ�����,720p���壬1080p����*/
    ULONG_32 ulDeviceType;

    /** ����������豸���ͺ� */
    CHAR szDeviceSubType[IMOS_NAME_LEN];

    /** ����������豸��ַ  */
    CHAR szDeviceAddress[IMOS_IPADDR_LEN];

    /** ����������豸�˿�  */
    ULONG_32 ulPort;

    /** ���������*/
    CHAR szCamCode[IMOS_CODE_LEN];

    /** ���������*/
    CHAR szCamName[IMOS_NAME_LEN];

    /** ��������ͣ�0 ��ʶ��˾IPC �������1��ʶ������IPC �����������Ԥ��*/
    ULONG_32 ulCamType;

    /** �����״̬��2��ʶ���ߣ�1��ʶ���ߣ�����Ԥ��  */
    ULONG_32 ulCamState;

     /** �豸����״̬��0��ʾδ��ʼ����1��ʾ�ѳ�ʼ�� */
    ULONG_32 ulDevState ;

    /** �鲥��ַ */
    CHAR szMultiCastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�  */
    ULONG_32 ulMultiCastPort;

    /** ��չԤ�� */
    CHAR szReversed[IMOS_IPC_CAM_INFO_REVERSED_LEN];
}IPC_CAM_INFO_FORECR_S;


/**
 * @struct tagUnitedRecDomainCfg
 * @brief ����������¼�����������Ϣ�ṹ
 * @attention
 */
typedef struct tagUnitedRecDomainCfg
{
    /** �������� 0:���ȼ���ע����¼�� 1:ֻ������ǰ��¼�� 2:��¼����� */
    ULONG_32 ulRecPolicy;

    /** ¼�����ȼ� 0:��ǰ��¼������ 1:ע����¼������
        ���ֶ�ֻ�е���������Ϊ��¼�����ʱ����Ч */
    ULONG_32 ulRecPriority;

     /** �����ֶ� */
    CHAR   szReserve[32];
}UNITED_REC_DOMAIN_CFG_S;

/**
*@struct tagDeviceVersionForECR
*@brief ����:��ȡ�豸�����״̬��Ϣ
*/
typedef struct tagDeviceVersionForECR
{
    CHAR szSoftwareVer[IMOS_VERSION_LENTH + 4];          /* program�汾 */
    CHAR szSoftwareInnerVer[IMOS_VERSION_LENTH + 4];     /* program�ڲ��汾 */
    CHAR szProuductVer[IMOS_VERSION_LENTH + 4];          /* uimage�汾 */
    CHAR szProuductInnerVer[IMOS_VERSION_LENTH + 4];     /* uimage�ڲ��汾 */
    CHAR szPCBVer[IMOS_VERSION_LENTH + 4];               /* PCB�汾 */
    CHAR szCPLDVer[IMOS_VERSION_LENTH + 4];              /* CPLD�汾 */
    CHAR szDSPVer[IMOS_VERSION_LENTH + 4];               /* DSP�汾 */
    CHAR szUbootVer[IMOS_VERSION_LENTH + 4];             /* UBOOT�����汾 */
    CHAR szFPGAVer[IMOS_VERSION_LENTH + 4];              /* FPGA�汾 */
    CHAR szMCUVer[IMOS_VERSION_LENTH + 4];               /* MCU�汾 */
}DEVICE_VERSION_FOR_ECR_S;

/**
* @struct tagDevBaseInfoForECR
* @brief  �豸������Ϣ
* @attention
*/
typedef struct tagDevBaseInfoForECR
{
    DEVICE_TYPE_FOR_ECR_E       enDeviceType;                                 /* �豸���� */
    CHAR                        szDeviceName[IMOS_DEVICE_CODE_LEN];           /* �豸���� */
    CHAR                        szDeviceSerialNumber[IMOS_DEVICE_CODE_LEN];   /* �豸���к� */
    DEVICE_VERSION_FOR_ECR_S    stDeviceVer;                                  /* �汾��Ϣ */
}DEV_BASE_INFO_FOR_ECR_S;

/**
*@struct tagDevHeatStatusForECR
*@brief ����ģ�鹤��״̬
*/
typedef enum tagDevHeatStatusForECR
{
    IMOS_HEAT_NO = 0,    /* δ���� */
    IMOS_HEAT_LOW,       /* �͹��ʼ��� */
    IMOS_HEAT_HIGH,      /* �߹��ʼ��� */
    IMOS_HEAT_NULL,      /* û�м���ģ�� */
    IMOS_HEAT_BUTT
} DEV_HEAT_STATUS_FOR_ECR_E;

/**
* @struct tagDevRunStatusForECR
* @brief  �豸������Ϣ
* @attention
*/
typedef struct tagDevRunStatusForECR
{
    TIME_T                      stSystemTime;           /* ϵͳʱ�� */
    ULONG_32                       ulRunTime;              /* �豸����ʱ�� ��λ������*/
    LONG_32                        lDeviceTemperature;     /* �豸�¶� */
    BOOL_T                      bDeviceIsOnline;        /* �豸����״̬ */
    ULONG_32                       ulCPUUtilization;       /* CPUʹ���� */
    ULONG_32                       ulMemFree;              /* �����ڴ�������λ��M */
    ULONG_32                       ulMemMax;               /* ����ڴ�������λ��M */
    ULONG_32                       ulIORead;                   /* IO������λ��kB/s */
    ULONG_32                       ulIOWrite;                  /* IOд����λ��kB/s */
    DEV_FANS_STATUS_FOR_ECR_E   enFansStatus;         /* ����״̬ */
    DEV_HEAT_STATUS_FOR_ECR_E   enHeatStatus;         /* ����״̬ */
}DEV_RUN_STATUS_FOR_ECR_S;

/**
* @struct tagNicNumberForECR
* @brief  �豸����������
* @attention
*/
typedef struct tagNicNumberForECR
{
    ULONG_32    ulNICNumber;                          /* �������� */
}NIC_NUMBER_FOR_ECR_S;

/**
* @struct tagLinkInfoForECR
* @brief  ��·״��
* @attention
*/
typedef struct tagLinkInfoForECR
{
    NET_LINK_MODE_FOR_ECR_E     enLinkType;    /* ��·���� */
    CHAR    szLinkName[IMOS_NAME_LEN];      /* �ӿ����ƣ����豸���˿ӡ����һ��*/
    CONNECTION_STATUS_FOR_ECR_E         enConnectionStatus;    /* ����״̬ δ���Ӻ���Ĳ���������*/
    ETH_SPEED_FOR_ECR_E     enBandwidth;    /* ����*/
    ETH_DUPLEX_FOR_ECR_E   enOperatingMode;  /* ����ģʽ*/
}LINK_INFO_FOR_ECR_S;

/**
* @struct tagIPInfoForECR
* @brief  IP��Ϣ
* @attention
*/
typedef struct tagIPInfoForECR
{
    IP_GET_TYPE_FOR_ECR_E     enIPObtain;                       /* IP��ȡ��ʽ */
    CHAR    szIpAddress[IMOS_IPADDR_LENTH + 4];            /* IP��ַ */
    CHAR    szIpNetmask[IMOS_IPADDR_LENTH + 4];            /* �������� */
    CHAR    szIpGateway[IMOS_IPADDR_LENTH + 4];            /* ���� */
}IP_INFO_FOR_ECR_S;

/**
* @struct tagNicInfoForECR
* @brief  �豸������������Ϣ
* @attention
*/
typedef struct tagNicInfoForECR
{
    ULONG_32                   ulNICIndex;                                 /* ��������� */
    CHAR                    szMacAddress[IMOS_STRING_LEN_32];           /* ��������Mac��ַ��32λ�����������ʽ���� */
    CHAR                    szNICName[IMOS_NETWORK_CARD_NAME_LEN_FOR_ECR]; /* �������� */
    ULONG_32                   ulLinkNumber;            /* ������������ӿ����� ���ֵΪ16*/
    LINK_INFO_FOR_ECR_S         astLinkInfo[IMOS_NETWORK_CARD_PHY_MAXNUM_FOR_ECR];    /* ��·״�������ֵΪ16 */
    ULONG_32                               ulIPNumber;         /* ��������IP��ַ���� ���ֵΪ4*/
    IP_INFO_FOR_ECR_S       astIPInfo[IMOS_NETWORK_CARD_IP_ADDR_MAXNUM_FOR_ECR];  /* IP״�������ֵΪ4 */
}NIC_INFO_FOR_ECR_S;

/**
* @struct tagVehicleDataForECR
* @brief ������¼�ṹ
* @attention
*/
typedef struct tagVehicleDataForECR
{
    /** ������Ϣ��� */
    CHAR  szVehicleRecodeId[IMOS_TOLLGATE_SPECIAL_ID_LEN];

    /** ��������� */
    CHAR  szCameraCode[IMOS_TOLLGATE_CODE_LEN];

    /** ���ڱ�� */
    CHAR  szTollgateCode[IMOS_TOLLGATE_CODE_LEN];

    /** �����ţ������޸� */
    CHAR  szLaneNumber[IMOS_TOLLGATE_SPECIAL_LEN];

    /** ��ʻ���� */
    CHAR szDirectionName[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** ͨ��ʱ�� */
    CHAR  szPassTime[IMOS_TIME_LEN];

    /** �������� */
    ULONG_32 ulLicensePlateNum;

    /** ���ƺ��� */
    CHAR  szLicensePlatCode[IMOS_TOLLGATE_CODE_LEN];

    /** ������ɫ���ο������ֵ� */
    CHAR  szLicensePlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������࣬�ο������ֵ� */
    CHAR  szLicensePlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ����һ�� */
    BOOL_T bLicensePlateCoincide;

    /** ����Ʒ�ƣ��ο������ֵ� */
    CHAR  szVehicleLogo[IMOS_DICTIONARY_KEY_LEN];

    /** ������ɫ��ǳ���ο�#VEHICLE_COLOR_DEPTH_E */
    ULONG_32 ulVehicleColorDepth;

    /** ������ɫ���ο������ֵ� */
    CHAR  szVehicleColor[IMOS_DICTIONARY_KEY_LEN];

    /** �������Σ��ݲ�ʹ�� */
    CHAR  szVehicleFiguration[IMOS_DICTIONARY_KEY_LEN];

    /** �������ͣ��ο������ֵ� */
    CHAR  szVehicleType[IMOS_DICTIONARY_KEY_LEN];

    /** ��������λ: ���� */
    ULONG_32 ulVehicleLen;

    /** �����Ƿ���� */
    ULONG_32 ulIsVehicleLen;

    /** �����ٶȣ���λKm/h */
    ULONG_32 ulVehicleSpeed;

    /** �����ٶ��Ƿ���� */
    ULONG_32 ulIsVehicleSpeed;

    /** �������٣���λKm/h */
    ULONG_32 ulLimitedSpeed;

    /** ���������Ƿ���� */
    ULONG_32 ulIsLimitedSpeed;

    /** ��ʻ״̬���ο������ֵ� */
    CHAR  szVehicleStatus[IMOS_DICTIONARY_KEY_LEN];

    /** ͼ������ */
    ULONG_32 ulImgNum;

    /** ͼ�������б� */
    CHAR  aszImgList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** ͼ��·���б�����Tware�ڲ�ʹ�ã������ͼ�����ƿ��ܺ�xml�в�һ�� */
    CHAR  aszImgPathList[IMOS_MAX_VEHICLE_IMG_NUM][IMOS_MAX_VEHICLE_IMG_NAME_LEN];

    /** ͼ�������б� */
    ULONG_32 aulImgTypeList[IMOS_MAX_VEHICLE_IMG_NUM];

    /** ͼ���Ӻϳɱ�־�б� */
    CHAR szImgSubComposeList[IMOS_MAX_VEHICLE_IMG_NUM];

    /** ͼ���Ӻϳɱ�־�Ƿ�����б� */
    CHAR szImgIsSubComposeList[IMOS_MAX_VEHICLE_IMG_NUM];

    /** ʶ��ʱ�䣬��λ: ���� */
    ULONG_32 ulIdentifyTime;

    /** ʶ��ʱ���Ƿ���� */
    ULONG_32 ulIsIdentifyTime;

    /** ʶ��״̬���ο�#VEHICLE_IDENTIFY_STATUS_E */
    ULONG_32 ulIdentifyStatus;

    /** ������ */
    CHAR  szDealStatus[IMOS_TOLLGATE_SPECIAL_LEN];

    /** �����������ͣ��ο�#VEHICLE_RECORD_TYPE_E */
    ULONG_32 ulVehicleDataType;

    /** ���ڱ��2 */
    CHAR  szTollgateCode2[IMOS_TOLLGATE_CODE_LEN];

    /** ���ڳ�����2 */
    CHAR  szLaneNumber2[IMOS_TOLLGATE_SPECIAL_LEN];

    /** ��ʻ����2 */
    CHAR szDirectionName2[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** ͨ��ʱ��2 */
    CHAR szPassTime2[IMOS_TIME_LEN];

    /** �Ƿ����ϴ� */
    ULONG_32 ulTransFlag;

    /** Υ�µص���� */
    CHAR szPlaceCode[IMOS_TOLLGATE_CODE_LEN];

    /** �ɼ��豸���� */
    CHAR szEquipmentType[IMOS_DICTIONARY_KEY_LEN];

    /** �ɼ����ر��� */
    CHAR szDeptCode[IMOS_CODE_LEN];

    /** ����ʱ�� */
    CHAR szUpdateTime[IMOS_TIME_LEN];

    /* begin added by suzhijie for change */
    /** �������� */
    CHAR  szTollgateName[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** ��������2 */
    CHAR  szTollgateName2[IMOS_TOLLGATE_SPECIAL_NAME_LEN];

    /** �ص����� */
    CHAR szSectionName[IMOS_PLACE_NAME_LEN];

    /** �Ƿ�ʵʱ��¼�������� */
    ULONG_32 ulCommand;

    /** ���ڳ������� */
    CHAR  szLaneType[IMOS_TOLLGATE_SPECIAL_LEN];

    /** ���ڳ�������2 */
    CHAR  szLaneType2[IMOS_TOLLGATE_SPECIAL_LEN];

    /** ������ */
    CHAR szDirectNumber[IMOS_TOLLGATE_SPECIAL_LEN];

    /** ������2 */
    CHAR szDirectNumber2[IMOS_TOLLGATE_SPECIAL_LEN];

    /** β�����ƺ��� */
    CHAR  szBackendPlatCode[IMOS_TOLLGATE_CODE_LEN];

    /** β��������ɫ���ο������ֵ� */
    CHAR  szBackendPlateColor[IMOS_DICTIONARY_KEY_LEN];

    /** β���������࣬�ο������ֵ� */
    CHAR  szBackendPlateType[IMOS_DICTIONARY_KEY_LEN];

    /** ��ʶ���� */
    ULONG_32 ulMarkedSpeed;

    /** ��ʶ�����Ƿ���� */
    ULONG_32 ulIsMarkedSpeed;

    /** ����������ɫ���ο������ֵ� */
    CHAR  szDressColor[IMOS_DICTIONARY_KEY_LEN];

    /** ���ʱ�� */
    ULONG_32 ulRedLightTime;

    /** ���ʱ���Ƿ���� */
    ULONG_32 ulIsRedLightTime;

    /** Ӧ������ */
    ULONG_32 ulApplycationType;

    /** Ӧ�������Ƿ���� */
    ULONG_32 ulIsApplycationType;

    /** ȫ�ֺϳɱ�ʶ */
    ULONG_32 ulGlobalComposeFlag;

    /** ȫ�ֺϳɱ�ʶ�Ƿ���� */
    ULONG_32 ulIsGlobalComposeFlag;

    /* end added by suzhijie for change */
} VEHICLE_DATA_FOR_ECR_S;

/**
*@ struct tagAudioResShareInfo
*@ brief����ҵ����Դ������Ϣ��
*@ attention
*/
typedef struct tagAudioResShareInfo
{
    /** ����ҵ����Դ����*/
    ULONG_32 ulIndex;

    /** ����ҵ����Դ����״̬��1��ʾ����ʧ�ܣ�0��ʾ���� */
    ULONG_32 ulState;

    /** ����ҵ����Դ���� �Խ�:IMOS_TYPE_MICROPHONE; �㲥:IMOS_TYPE_SPEAKER */
    ULONG_32 ulAudioResType;

    /** ��Դ���� */
    CHAR szAudioResCode[IMOS_CODE_LEN];

    /** ��Դ���� */
    CHAR szAudioResName[IMOS_NAME_LEN];

    /** ��Դ�������� */
    CHAR szInterCode[IMOS_CODE_LEN];

    /* ��Դ������֯�ڵ� */
    CHAR szParentOrgCode[IMOS_DOMAIN_CODE_LEN];
}AUDIO_RES_SHARE_INFO_S;

/**
 *@struct tagAudioInAndChannelInfoForECR
 *@brief������Ƶ���뼰ͨ����Ϣ�ṹ��(��ѯ��Ƶ���뼰ͨ����Ϣʱ����)
 *@attention
 */
typedef struct tagAudioInAndChannelInfoForECR
{
	/** �豸ͨ��������Ϣ  */
	DEV_CHANNEL_INDEX_S        stChannelIndex;

    /** �Ƿ�ʹ�� 0/1:��ʹ��/ʹ�� */
    ULONG_32       ulAudioEnabled;

    /** ��Ƶ���룬ȡֵ��ΧΪ #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** ��Ƶ������ȡֵ��ΧΪ #IMOS_AUDIO_CHANNEL_TYPE_E  */
    ULONG_32       ulTrack;

    /** �����ʣ�ȡֵ��ΧΪ #IMOS_AUDIO_SAMPLING_E */
    ULONG_32       ulSamplingRate;

    /** ���� */
    ULONG_32       ulEncodeRate;

    /** ��������ֵ��ȡֵ��ΧΪ0-255��Ĭ��0  */
    ULONG_32       ulIncrement;

    /** ��Ƶ�������� */
    CHAR        szDesc[IMOS_DESC_LEN];
}AUDIO_IN_AND_CHANNEL_INFO_FOR_ECR_S;

/**
 *@struct tagAudioOutAndChannelInfoForECR
 *@brief������Ƶ�����ͨ����Ϣ�ṹ��(��ѯ��Ƶ�����ͨ����Ϣʱ����)
 *@attention
 */
typedef struct tagAudioOutAndChannelInfoForECR
{
	/** �豸ͨ��������Ϣ  */
	DEV_CHANNEL_INDEX_S        stChannelIndex;

    /** ʹ�ܱ�ʶ */
    ULONG_32       ulAudioEnabled;

    /** ��Ƶ���룬ȡֵ��ΧΪ #IMOS_AUDIO_FORMAT_E */
    ULONG_32       ulEncodeType;

    /** ��Ƶ������ȡֵ��ΧΪ #IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32       ulTrack;

    /** ����ֵ */
    ULONG_32       ulVolume;

    /** ��Ƶ������� */
    CHAR        szDesc[IMOS_DESC_LEN];
}AUDIO_OUT_AND_CHANNEL_INFO_FOR_ECR_S;

/**
 *@struct tagAudioResInfoForECR
 *@brief����ҵ����Դ��Ϣ�ṹ��
 *@attention
 */
typedef struct tagAudioResInfoForECR
{
    /** ����ҵ����Դ���� */
    ULONG_32       ulAudioResIndex;

    /** ����ҵ����Դ���� */
    CHAR        szAudioResName[IMOS_NAME_LEN];

    /** ����ҵ����Դ���� */
    CHAR        szAudioResCode[IMOS_RES_CODE_LEN];

    /** �����豸���� */
    CHAR        szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �����豸���� */
    CHAR        szDevName[IMOS_NAME_LEN];

    /** ����ҵ����Դ���ͣ�ȡֵΪ��8001--�Խ�, 8002--�㲥, ����ֵ��Ч */
    ULONG_32       ulAudioResType;

    /** ��Ƶ�������ͣ�ȡֵΪ��AUDIO_INPUT_TYPE_FOR_ECR_E */
    ULONG_32       ulAudioInType;

    /** ��Ƶ�������� */
    ULONG_32       ulAudioInputIndex;

    /** ��Ƶ������� */
    ULONG_32       ulAudioOutputIndex;
}AUDIO_RES_INFO_FOR_ECR_S;

/**
 *@struct tagCamBindAudioResInfoForECR
 *@brief �������������Դ��Ϣ�ṹ��
 *@attention
 */
typedef struct tagCamBindAudioResInfoForECR
{
    /** ��������� */
    CHAR        szCameraCode[IMOS_RES_CODE_LEN];

    /** ��������� */
    CHAR        szCameraName[IMOS_NAME_LEN];

    /** �����Խ�ҵ����Դ���� */
    CHAR        szAudioTalkResCode[IMOS_RES_CODE_LEN];

    /** �����Խ�ҵ����Դ���� */
    CHAR        szAudioTalkResName[IMOS_NAME_LEN];

    /** �����㲥ҵ����Դ���� */
    CHAR        szAudioBrdcastResCode[IMOS_RES_CODE_LEN];

    /** �����㲥ҵ����Դ���� */
    CHAR        szAudioBrdcastResName[IMOS_NAME_LEN];

    /** ����ҵ����Դ���� */
    ULONG_32       ulAudioResIndex;
}CAM_BIND_AUDIO_RES_INFO_FOR_ECR_S;

/**
 *@struct tagSdkSerialToIOInfo
 * @brIEf IO��Ϣ�崮������
 * @attention
 */
 typedef struct tagSerialOfIOInfoForECR
{
    /** �豸��� */
    CHAR  szDevCode[IMOS_DEVICE_CODE_LEN];

    /** �������� */
    ULONG_32 ulSerialIndex;

}SERIAL_OF_IO_INFO_FOR_ECR_S;

/**
 * @struct tagMsgFromUMPInfo
 * @brIEf UMP������IO����������Ϣ�����·�װ����Ϣ����
 * @attention
 */
 typedef struct tagMsgFromUMPInfoForECR
{
    /** ������Ϣ */
    SERIAL_OF_IO_INFO_FOR_ECR_S stSerialInfo;

    /** ��Ϣ���� */
    ULONG_32 ulInfoLen;

    /**  ռλ�� */
    CHAR szIOMsgInfo [4];
}MSG_FROM_UMP_INFO_FOR_ECR_S;

/**
 * @struct tagSdkMsgToIOInfo
 * @brIEf UMP������IO����������Ϣ�����·�װ��OSD��Ϣ���ݽṹ��
 * @attention
 */
 typedef struct tagMsgFromUMPOSDInfoForECR
{
    /** OSDͨ���� */
    ULONG_32 ulOSDCode;

    /** ����OSD������ */
    ULONG_32                   ulOSDNameNum;

    /** ����OSD */
    OSD_NAME_S              astOSDName[1];
}MSG_FROM_UMP_OSD_INFO_FOR_ECR_S;

/**
 * @struct tagUMPLOGINCFGLogin
 * @brief �û���¼����IE��ṹ
 * @attention ��
 */
typedef struct tagUMPLOGINCFGLoginForECR
{
    /** �û���¼�� */
    CHAR  szUserLoginName[IMOS_NAME_LEN];

    /** �û����� */
    CHAR  szPassword[IMOS_PASSWD_ENCRYPT_LEN];

    /** ��¼IP��ַ */
    CHAR  szIpAddress[IMOS_IPADDR_LEN];

} UMP_LOGINCFG_LOGIN_FOR_ECR_S;

/**
 * @struct tagSdkSerialToIOInfo
 * @brIEf ��IO������Ϣ������
 * @attention
 */
typedef struct tagMsgOFIOInfoForECR
{
    /** ��Ϣ���� */
    ULONG_32 ulMsgLen;

    /** ��Ϣ��ʼָ�� */
    CHAR  szIOMsgInfo[4];

}MSG_OF_IO_INFO_FOR_ECR_S;

/**
 * @struct tagSdkMsgToIOInfo
 * @brIEf ��IO������Ϣ
 * @attention
 */
 typedef struct tagSdkMsgToIOInfoForECR
{
    /** �û���¼��Ϣ */
    USER_LOGIN_ID_INFO_S               stUserInfo;

    /** ������Ϣ */
    SERIAL_OF_IO_INFO_FOR_ECR_S stSerialInfo;

    /** ��Ϣ�� */
    MSG_OF_IO_INFO_FOR_ECR_S stIOMsgInfo;

}SDK_MSG_TO_IO_INFO_FOR_ECR_S;

/**
 *@struct tagIOMSGInfoForECR
 * @brIEf IO��Ϣ������
 * @attention
 */
 typedef struct tagIOMSGInfoForECR
{
    /** ��Ϣ���� */
    ULONG_32 ulInfoLen;

    /**  ռλ�� */
    CHAR szIOMsgInfo [4];

}IO_MSG_INFO_FOR_ECR_S;

/**
* @struct tagUniversalPage
* @brief ͨ�÷�ҳ��Ϣ
* @attention
*/
typedef struct tagUniversalPageInfo
{
    ULONG_32 ulFirstRow;               /**< ��ҳ�ӵڼ��п�ʼ��ѯ */
    ULONG_32 ulPageRowNum;             /**< ��ҳҪ��ѯ������ */
    ULONG_32 ulFiledNum;                    /* ��ѯ���ֶ���Ŀ*/
    ULONG_32 ulActualRowCount;         /**< ʵ�ʷ��ص����� */
    ULONG_32 ulTotalRowCount;          /**< ���������������ܼ� */
    ULONG_32 ulVecNum;                      /**< vector �����д�����ַ�������*/
}UNI_PAGE_INFO_S;

/* Begin Added by liuhongjieKF0170,2013-8-28 of ֧������OSD */
/**
 * @struct tagThreeDimensionCoverAreaInfo
 * @brief 3D�ڸ�������Ϣ
 * @attention
 */
typedef struct tagThreeDimensionCoverAreaInfo
{
    /* �������� */
    ULONG_32            ulAreaIndex;

    /* ����ʹ�ܱ�־λ */
    ULONG_32            ulEnableFlag;

    /* �������� */
    AREA_SCOPE_S     stArea;

}THREE_DIM_COVER_AREA_INFO_S;

/**
 * @struct tagThreeDimensionCoverPositionState
 * @brief 3D�ڸ�����λ��״̬��Ϣ
 * @attention
 */
typedef struct tagThreeDimensionCoverPositionState
{
   /* ������� */
   ULONG_32  ulAreaNum;

   /* 3D�ڸ�������Ϣ*/
   VIDEO_AREA_S    ast3DCoverAreaInfo[IMOS_MAX_3D_COVER_AREA_NUM];

}THREE_DIM_COVER_POSITION_STATE_S;
/* End Added by liuhongjieKF0170,2013-8-28 of ֧������OSD */

/* Begin Added by liuhongjieKF0170,2013-9-4 of ֧������OSD */
/**
 * @struct tagNewOSDRowCommonParam
 * @brief NewOSD ͨ�ò���
 * @attention
 */
typedef struct tagNewOSDRowCommParam
{
    ULONG_32  ulFontEffect;                  /** ����Ч�� */

    ULONG_32  ulFontSize;                    /** �����С */

}NEW_OSD_ROW_COMM_PARAM_S;

/**
 * @struct tagNewOsd
 * @brief  �µ�OSD��Ϣ
 * @attention
 */
typedef struct tagNewOsd
{
    ULONG_32  ulEnabledFlag;                 /** �Ƿ�ʹ�ܳ���OSD, 1Ϊʹ��; 2Ϊ��ʹ�� */
    ULONG_32  ulOsdIndex;                    /** OSD���� */
    ULONG_32  ulAreaIndex;                   /** ������������ */
    ULONG_32  ulOsdColor;                    /** ����OSD��ɫ */
    ULONG_32  ulTransparence;                /** ����OSD͸���� */
    ULONG_32  ulFontEffect;                  /** ����Ч�� */
    ULONG_32  ulFontSize;                    /** �����С */
    ULONG_32  ulOsdType;                     /** OSD���� */
    CHAR   szOsdString[IMOS_NAME_LEN];    /** OSD���� */
    ULONG_32       ulOsdDateFormat;         /* OSDʱ���ʽ */       
    ULONG_32       ulOsdMinMargin;         /* ��С��� */
    CHAR   szReserve[56];               /** �����ֶ� */
}NEW_OSD_S;
/* End Added by liuhongjieKF0170,2013-9-4 of ֧������OSD */

/* Begin Added by lw0581,2013-11-6 for  VVD06374*/
/**
 * @struct tagSdkOperLogInfoForECR
 * @brief ͼƬOSD ���ӷ�ʽ
 * @attention
 */
 typedef struct tagSdkOperLogInfoForECR
{
    /** ҵ������ */
    ULONG_32 ulOperateType;

    /** �������� */
    ULONG_32 ulServiceType;

    /** ������� */
    ULONG_32   ulResult;

    /** �������� */
    CHAR szOperateObject[IMOS_STRING_LEN_128];
}SDK_OPER_LOG_INFO_FOR_ECR_S;

typedef struct tagGuardAgentInfoForECR
{
    /** ��ܴ����ID��*/
    CHAR szAgentID[IMOS_CODE_LEN];

    /** ��ܴ��������*/
    CHAR szAgentName[IMOS_NAME_LEN];

    /** ���ƽ̨���ñ��*/
    ULONG_32 ulServerEnableFlag;

    /** ���ƽ̨״̬���*/
    ULONG_32 ulServerIsOnline;

    /** ���ƽ̨IP��ַ���� 1 IPV4 2 IPV6*/
    ULONG_32 ulServerAddrType;

    /** ���ƽ̨IP��ַ  */
    CHAR szServerAddr[IMOS_IPADDR_LEN];

    /** ���ƽ̨�˿�  */
    ULONG_32 ulServerPort;

    /** ��չԤ�� */
    CHAR szReserved[IMOS_NAME_LEN];
}GUARD_AGENT_INFO_FOR_ECR_S;

/**
*@ struct tagCameraMaintainInfoForECR
*@ brief �ϱ�ͼƬ�����Ϣ
*@ attention
*/
typedef struct tagCameraMaintainInfoForECR
{
    /** ���������*/
    CHAR szCameraCode[IMOS_RES_CODE_LEN];

    /** ���������*/
    ULONG_32 ulCameraIndex;

    /** �������� 1-���� 2-���� 3-�ճ�ά��*/
    ULONG_32 ulActionType;

    /** ������Ϣ*/
    CHAR szDesc[IMOS_DESC_LEN];

    /** ͼƬ����*/
    CHAR szPictureName[IMOS_NAME_LEN];

    /** ͼ���ʽ  1-JPEG, base64���� */
    ULONG_32 ulPictureFormat;

    /** ͼ��ߴ磬Ŀǰ���512  */
    ULONG_32 ulPictureSize;

    /** ͼƬ�������ݣ�������pictureSizeΪ׼ */
    CHAR astPicture[1];
}CAMERA_MAINTAIN_INFO_FOR_ECR_S;

/**
 * @struct tagAddIPCInfo
 * @brief  ���IPC��Ϣ
 * @attention
 */
typedef struct tagAddIPCInfo
{
    /** EC����, EC��Ψһ��ʶ */
    CHAR  szECCode[IMOS_DEVICE_CODE_LEN];

    /** EC���� */
    CHAR  szECName[IMOS_NAME_LEN];

    /** �Ƿ�֧���鲥, 1Ϊ֧��; 0Ϊ��֧�� */
    ULONG_32 ulIsMulticast;

    /** �澯ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnableAlarm;

    /** EC������֯���� */
    CHAR  szOrgCode[IMOS_DOMAIN_CODE_LEN];

    /** ʱ��ͬ����ʽ��Ĭ��Ϊ1����ʾʹ��H3C��˽��ͬ����ʽ��2��ʾNTP��ͬ����ʽ(Ŀǰ�ݲ�֧��) */
    ULONG_32 ulTimeSyncMode;

    /** ʱ��, ȡֵΪ-12~12 */
    LONG_32 lTimeZone;

    /** �������ã������ķ����������ã�ȡֵΪ:#TD_LANGUAGE_E */
    ULONG_32 ulLanguage;

    /** �Ƿ����ñ��ػ��棬1��ʾ����; 0��ʾ��������Ĭ��ֵΪ0 */
    ULONG_32 ulEnableLocalCache;

    /*��������*/
    ULONG_32  ulCameraManutype;   /*0��˾��1������*/

    /** IPC��IP��ַ, ��ӵ���������д�ò���*/
    CHAR szECIPAddr[IMOS_IPADDR_LEN];

    /*�豸�˿�*/
    ULONG_32  ulDevPort;

   /* �û��� */
   CHAR szUserName[IMOS_NAME_LEN];

   /** �豸�������� */
   CHAR szDevPasswd[IMOS_PASSWD_ENCRYPT_LEN];

   /* �������ͣ�1 ONVIF1.0  ��2  ONVIF2.0 */
   ULONG_32  ulCameraAccessType;

   /** �����ֶ� */
   CHAR szReserve[64];

}ADD_IPC_INFO_S;

/**
 * @struct tagDAOIPCSerialPortInfo
 * @brief  IPC����������Ϣ
 * @attention
 */
typedef struct tagIPCSerialPortInfo
{
   /* ���ڸ���*/
   ULONG_32 ulSerialPortNum;

   /* ����������xml�нڵ����� */
   CHAR  aszSerialExpand[IMOS_IPC_SERIAL_PORT_MAX_NUM][IMOS_XML_EXPAND_DESC_LEN];
}IPC_SERIAL_PORT_INFO_S;


typedef struct tagIPCCapabilities
{
    CHAR    szOSDVersion[IMOS_XML_EXPAND_DESC_LEN];                   /** OSD�汾 */
    ULONG_32   ulOSDBlockNum;                                            /** OSD����� */
    ULONG_32   ulOSDNum;                                                  /** OSD���� */

    CHAR    szROIVersion[IMOS_XML_EXPAND_DESC_LEN];                   /** ROI�汾 */
    ULONG_32   ulROINum;                                                 /** ������ǿ���� */

    CHAR    szMaskVersion[IMOS_XML_EXPAND_DESC_LEN];                  /** �ڸ�����汾 */
    ULONG_32   ulMaskAreaNum;                                            /** �ڸ�������� */

    CHAR    szMotionDetectVersion[IMOS_XML_EXPAND_DESC_LEN];          /** �ƶ����汾 */
    ULONG_32   ulMotionDetectNum;                                        /** �ƶ����������� */

    CHAR    szSemaphoreInputVersion[IMOS_XML_EXPAND_DESC_LEN];        /** ���뿪�����汾 */
    ULONG_32   ulSemaphoreInputNum;                                      /** ���뿪�������� */

    CHAR    szSemaphoreOutputVersion[IMOS_XML_EXPAND_DESC_LEN];       /** ����������汾 */
    ULONG_32   ulSemaphoreOutputNum;                                     /** ������������� */

    ULONG_32   ulEncodeCapacity;                                         /** �������� �ݲ�ʹ�� */
    CHAR    szCamTypeBas[IMOS_XML_EXPAND_DESC_LEN];                   /** ������������� */

    CHAR    szTempAlarm[IMOS_XML_EXPAND_DESC_LEN];                    /** �¶ȸ澯�汾 */
    LONG_32    lTempMax;                                                 /** ����¶�  */
    LONG_32    lTempMin;                                                 /** ����¶�  */

    CHAR    szAudioCodeSet[IMOS_XML_EXPAND_DESC_LEN];                 /** ��Ƶ���� */
    CHAR    szVideoEncodeSet[IMOS_XML_EXPAND_DESC_LEN];                /** ��Ƶ���ײ�*/

    CHAR    szTransProtocol[IMOS_XML_EXPAND_DESC_LEN];                 /** ������Э��*/

    IPC_SERIAL_PORT_INFO_S stSerialPortInfo;                       /** ������Ϣ */

    CHAR    szMirrorVersion[IMOS_XML_EXPAND_DESC_LEN];                /*����ģʽ*/
}IPC_CAPABILITIES_S;

/**
 * @struct tagMotionDetectArea
 * @brief  �ƶ����������Ϣ(V2.0)
 * @attention
 */
typedef struct tagMotionDetectArea
{
    ULONG_32           ulDruation;                      /** ����ʱ�� */
    ULONG_32           ulTargetSize;                    /** Ŀ���С */
    VIDEO_AREA_S    stVideoArea;                     /** �������� */
    CHAR            szReserve[IMOS_RESERVED_LEN];    /** �����ֶ� */
}MOTION_DETECT_AREA_S;

/**
 * @struct tagAreaScopeV2
 * @brief ����Χ��������������(�����Ǿ��ε�)
 * @attention
 */
typedef struct tagAreaScopeV2
{
    /** ���Ͻ�x����, ȡֵΪ0~10000 */
    ULONG_32       ulTopLeftX;

    /** ���Ͻ�y����, ȡֵΪ0~10000 */
    ULONG_32       ulTopLeftY;

    /** ���½�x����, ȡֵΪ0~10000 */
    ULONG_32       ulBottomRightX;

    /** ���½�y����, ȡֵΪ0~10000 */
    ULONG_32       ulBottomRightY;

}AREA_SCOPE_V2_S;

/**
* @struct tagROIArea
* @brief ������ǿ��Ϣ
* @attention
*/
typedef struct tagROIArea
{
 /** �������� */
 ULONG_32            ulAreaIndex;

 /** ʹ�ܱ�� */
 ULONG_32            ulEnabledFlag;

 /** �������� */
 AREA_SCOPE_V2_S  stAreaScope;

}ROI_AREA_S;

/**
 * @struct tagVideoInChannelExtend
 * @brief ����Ƶ����ͨ����Ϣ
 * @attention
 */
typedef struct tagVideoInChannelExtend
{

    /** ��Ƶ����ͨ������ */
    CHAR szVinChannelDesc[IMOS_DESC_LEN];

    /** �鲥��ַ */
    CHAR szMulticastAddr[IMOS_IPADDR_LEN];

    /** �鲥�˿�,��ΧΪ��10002-65534���ұ���Ϊż�� */
    ULONG_32   ulMulticastPort;

    /** MSѡ�����Ӧ����, 1Ϊ����Ӧ; 0Ϊ������Ӧ */
    ULONG_32 ulIsAutofit;

    /** ʹ��MS��Ŀ, ��ʵ���������, ����Ӧ����#ulIsAutofitΪ����Ӧ, ��ֵΪ0;
        ����Ӧ����#ulIsAutofitΪ������Ӧ(��ָ��), ��ֵΪ1 */
    ULONG_32 ulUseMSNum;

    /** MS�����б� */
    CHAR aszMSCode[IMOS_MS_MAX_NUM_PER_CHANNEL][IMOS_DEVICE_CODE_LEN];

    /** �Ƿ�����ͼ���ڵ����澯, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulEnableKeepout;

    /** �Ƿ������˶����澯, 1Ϊ�����˶����澯; 0Ϊ�������˶����澯 */
    ULONG_32 ulEnableMotionDetect;

    /** �Ƿ�������Ƶ��ʧ�澯, 1Ϊ������Ƶ��ʧ�澯; 0Ϊ��������Ƶ��ʧ�澯 */
    ULONG_32 ulEnableVideoLost;

    /** �󶨵Ĵ��ڱ�ţ���������д0 */
    ULONG_32 ulSerialIndex;

    /** ���ȣ�ȡֵΪ��0~255�� */
    ULONG_32 ulBrightness;

    /** �Աȶȣ�ȡֵΪ��0~255�� */
    ULONG_32 ulContrast;

    /** ���Ͷȣ�ȡֵΪ��0~255�� */
    ULONG_32 ulSaturation;

    /** ɫ����ȡֵΪ��0~255�� */
    ULONG_32 ulTone;

    /** ͼ���Ż�ģʽ  */
    ULONG_32 ulProcessingMode;

    /**  ���ģʽ  */
    ULONG_32 ulSharpnessMode;

    /**  ���ֵ  */
    ULONG_32   ulSharpnessValue;

    /**  2D����ȼ�  */
    ULONG_32  ul2DLevel;

    /**  3D����ȼ�  */
    ULONG_32 ul3DLevel;

    /**   ����ģʽ */
    ULONG_32 ulMirrorMode;

    /** �Ƿ���������, 1Ϊ������; 0Ϊ���� */
    ULONG_32 ulAudioEnabled;

    /** ��Ƶ����, ȡֵΪ#IMOS_AUDIO_FORMAT_E */
    ULONG_32 ulAudioCoding;

    /** ��Ƶ����, ȡֵΪ#IMOS_AUDIO_CHANNEL_TYPE_E */
    ULONG_32 ulAudioTrack;

    /** ��Ƶ������, ȡֵΪ#IMOS_AUDIO_SAMPLING_E */
    ULONG_32 ulSamplingRate;

    /** ��Ƶ����, �������� */
    ULONG_32 ulAudioCodeRate;

    /** ��Ƶ����ֵ��ȡֵΪ��0~255�� */
    ULONG_32 ulIncrement;
}VIN_CHANNEL_EXTEND_S;

/**
 * @struct tagExportProcessInfoForECR
 * @brief ������Ϣ
 * @attention
 */
typedef struct tagExportProcessInfoForECR
{
    /** ����״̬��0�������У�1���쳣��2�����*/
    ULONG_32 ulProcessState;

    /** ����ֵ���Խ����еĽ�����Ч*/
    ULONG_32 ulProcessValue;
}EXPORT_PROCESS_FOR_ECR_S;

/**
 * @struct tagUMUsbDiskMessageForECR
 * @brief ����U����Ϣ
 * @attention
 */
typedef struct tagUMUsbDiskMessageForECR
{
    ULONG_32                           ulUsbDiskIdx;               /* U������ */
    BOOL_T                          bIsOnLine;                  /* U���Ƿ����� */
    ULONG_32                           ulUsbDiskTotalSpace;        /* U��������:MB */
    ULONG_32                           ulUsbDiskFreeSpace;         /* U��ʣ������:MB */
}UM_USB_DISK_MESSAGE_FOR_ECR_S;

/**
 * @struct tagUMUsbDiskInfoForECR
 * @brief ����U����Ϣ
 * @attention
 */
typedef struct tagUMUsbDiskInfoForECR
{

    ULONG_32                           ulUsbDiskNum;                                       /* U�̸��� */
    UM_USB_DISK_MESSAGE_FOR_ECR_S        astUsbDiskMessage[USB_DISK_MAX_NUMBER];     /* U����Ϣ */
 }UM_USB_DISK_INFO_FOR_ECR_S;

/**
*@struct tagUMUsbDirInfoForECR
*@brief USBĿ¼��Ϣ
*/
typedef struct tagUMUsbDirInfoForECR
{
    UM_USB_DIR_TYPE_E                  enDirType;                                      /* Ŀ¼���� */
    CHAR                            aszDirName[IMOS_FILE_NAME_LEN];                  /* Ŀ¼���� */
}UM_USB_DIR_INFO_FOR_ECR_S;

/**
*@struct tagUMUsbDirListForECR
*@brief USBĿ¼�б�
*/
typedef struct tagUMUsbDirListForECR
{
    ULONG_32                           ulNum;
    UM_USB_DIR_INFO_FOR_ECR_S                  astDirInfo[UM_USB_DIR_NUM];
}UM_USB_DIR_LIST_FOR_ECR_S;

/**
 * @struct tagDictionaryDataForECR
 * @brief �����ֵ�ṹ
 * @attention
 */
typedef struct tagDictionaryDataForECR
{

    /** �����ֵ���� */
    CHAR  szDataCode[IMOS_DICTIONARY_KEY_LEN];

    /** �����ֵ����� */
    CHAR  szDataName[IMOS_NAME_LEN];

    /** �Ƿ�ϵͳԤ�����ϵͳԤ���������ɾ�����޸ģ�BOOL_TRUE:ϵͳԤ���壬BOOL_FALSE:��ϵͳԤ���� */
    BOOL_T bPreDefined;

} DICTIONARY_DATA_FOR_ECR_S;

/* End Added by lw0581,2013-11-6 for  VVD06374*/
/* Begin Added by lw0581,2013-11-12 for  VVD05864*/
/**
 * @struct tagMasStoreResInfoForECR
 * @brief �洢��Դ��Ϣ
 * @attention ��.
 */
typedef struct tagMasStoreResInfoForECR
{


    /** �洢�豸����, ȡֵΪ#STORE_DEV_TYPE_E */
    ULONG_32       ulStoreDevType;

    /** �洢�豸���� */
    CHAR        szStoreDevCode[IMOS_DEVICE_CODE_LEN];

    /** �洢�豸���� */
    CHAR        szStoreDevName[IMOS_NAME_LEN];

    /** ������������ԣ�ȡֵΪ#AS_DEVCM_DISK_FULL_POLICY_E */
    ULONG_32       ulDiskFullPolicy;

    /** �洢�ռ�(��IMOS_AssignMasStoreResForECR��,ָ��һ�η���Ĵ洢�ռ�; ��IMOS_ExpandMasStoreResForECR��,ָ��չ�ռ�[�����ѷ���ռ�]), ��ֵȡֵ������, ��λΪMB */
    ULONG_32       ulStoreSize;

}MAS_STORE_RES_INFO_FOR_ECR_S;


/**
 * @struct tagTMSInfoForECR
 * @brief TMS(��ͨý�彻��������)��Ϣ
 * @attention
 */
typedef struct tagTMSInfoForECR
{
    /** ���� */
    CHAR szTMSCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szTMSName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** TMS���ͣ�Ŀǰ��д0 */
    ULONG_32 ulType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /*�豸�˿�*/
    ULONG_32 ulDevPort;

    /** �豸�Ƿ�����, 1Ϊ����; 0Ϊ������ */
    ULONG_32 ulDevEnabled;

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ����, �ݲ�ʹ�ã���� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

} TMS_INFO_FOR_ECR_S;

/*Begin Modified by lw0581, 2013-11-12 for VVD06485*/
/** ͼƬ�ϳɷ�ʽ���� */
typedef enum tagTollgateCompositeType
{
    TOLLGATE_COMPOSITE_TYPE_ADAPT = 0,                 /**< ����Ӧ���� */
    TOLLGATE_COMPOSITE_TYPE_LINE,                 /**<���ε��� */

    TOLLGATE_COMPOSITE_TYPE_MAX,                   /**< ���ֵ */
    TOLLGATE_COMPOSITE_TYPE_INVALID = 0xFFFF       /**< ��Чֵ */
}TOLLGATE_COMPOSITE_TYPE_E;
/*End Modified by lw0581, 2013-11-12 for VVD06485*/


/** �羯ͼƬ�ϳɷ�ʽ���� */
typedef enum tagEPoliceCompositeType
{
    EPOLICE_COMPOSITE_TYPE_SQUARE = 0,            /**< ���ֺϳ� */
    EPOLICE_COMPOSITE_TYPE_HORIZONTAL,            /**< ͼƬ���� */
    EPOLICE_COMPOSITE_TYPE_VERTICAL,              /**< ͼƬ���� */
    EPOLICE_COMPOSITE_TYPE_ADAPT,                 /**< ����Ӧ���� */

    EPOLICE_COMPOSITE_TYPE_MAX,                   /**< ���ֵ */
    EPOLICE_COMPOSITE_TYPE_INVALID = 0xFFFF       /**< ��Чֵ */
}EPOLICE_COMPOSITE_TYPE_E;

/**
 * @struct tagPicCompositeInfoForECR
 * @brief ͼƬ�ϳɷ�ʽ
 * @attention
 */
typedef struct tagPicCompositeInfoForECR
{
    /** ��������� */
    CHAR szCamCode[IMOS_CODE_LEN];

    /** ͼƬ�ϳɷ������ͣ��ο�#TOLLGATE_COMPOSITE_TYPE_E */
    ULONG_32 ulTollgatePicCompositeType;

    /** �羯ͼƬ�ϳɷ������ͣ����ֶ��ݲ�ʹ�ã��ο�#EPOLICE_COMPOSITE_TYPE_E */
    ULONG_32 ulEPolicePicCompositeType;

     /** �ϳ��������ο�#COMPOSITE_QUALITY_E */
    ULONG_32 ulPicQuality;

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;
} PIC_COM_INFO_FOR_ECR_S;

/** �羯ͼƬOSD�������� */
typedef enum tagEpoliceOSDOverlayType
{
    EPOLICE_OSD_OVERLAY_TYPE_INNER = 0,             /**< ͼƬ�ڵ��� */
    EPOLICE_OSD_OVERLAY_TYPE_OUTSIDE_TOP,           /**< ͼƬ�Ϸ����� */
    EPOLICE_OSD_OVERLAY_TYPE_OUTSIDE_BOTTOM,        /**< ͼƬ�·����� */

    EPOLICE_OSD_OVERLAY_TYPE_MAX,                   /**< ���ֵ */
    EPOLICE_OSD_OVERLAY_TYPE_INVALID = 0xFFFF       /**< ��Чֵ */
}EPOLICE_OSD_OVERLAY_TYPE_E;

/**
 * @struct tagPicOsdSpliceInfoForECR
 * @brief ͼƬOSD ���ӷ�ʽ
 * @attention
 */
typedef struct tagPicOsdSpliceInfoForECR
{
    /** ��������� */
    CHAR szCamCode[IMOS_CODE_LEN];

    /** ʹ��ʱ����Ϣ */
    ULONG_32 ulEnableTimeInfo;

     /** ʹ�ܵص���Ϣ */
    ULONG_32 ulEnableDestinatonInfo;

    /** ʹ�ܷ�����Ϣ */
    ULONG_32 ulEnableDirectionInfo;

    /** ʹ�ܳ�����Ϣ */
    ULONG_32 ulEnableLaneInfo;

    /** ʹ�ܳ��ƺ���Ϣ */
    ULONG_32 ulEnablePlateCodeInfo;

    /** ʹ�ܳ�����ɫ��Ϣ */
    ULONG_32 ulEnablePlateColorInfo;

    /** ʹ����ʻ״̬��Ϣ */
    ULONG_32 ulEnableDriveStatusInfo;

    /** ʹ�ܺ��ʱ����Ϣ */
    ULONG_32 ulEnableRedlightTimeInfo;

    /** ʹ�ܳ����ٶ���Ϣ */
    ULONG_32 ulEnableVehicleSpeedInfo;

    /** ʹ�ܳ�����Ϣ*/
    ULONG_32 ulEnableVehicleBrand;

    /** ʹ�ܳ�����Ϣ*/
    ULONG_32 ulEnableVehicleType;

    /** ʹ�ܳ�����ɫ */
    ULONG_32 ulEnableVehicleColor;

    /** OSD �����С */
    ULONG_32 ulOSDFontSize;

     /** OSD ������ɫ*/
    ULONG_32 ulOSDColor;

    /** OSD ����͸����*/
    ULONG_32 ulOSDTransparence;

    /** OSD ���������*/
    ULONG_32 ulLineCharNum;

    /** OSD ��������X */
    ULONG_32 ulTopLeftX;

    /** OSD ��������Y */
    ULONG_32 ulTopLeftY;

    /** OSD ��������X */
    ULONG_32 ulBottomRightX;

    /** OSD ����y���� */
    ULONG_32 ulBottomRightY;

    /** ����1 */
    ULONG_32 ulOSDType1;

    /** ����1 */
    CHAR szOsdValue1[IMOS_NAME_LEN];

    /** ����2 */
    ULONG_32 ulOSDType2;

    /** ����2 */
    CHAR szOsdValue2[IMOS_NAME_LEN];

    /** �л�ʱ�� */
    ULONG_32 ulSwitchInterval;

    /** �Ƿ��Զ����� */
    ULONG_32 ulEnableChangeLine;

    /** ͼƬ��/����� ����Ӧö��EPOLICE_OSD_OVERLAY_TYPE_E */
    ULONG_32 ulPicInOrOut;

    /** ʹ��������Ϣ */
   ULONG_32 ulEnableLimitSpeed;

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;
}PIC_OSD_SPLICE_INFO_FOR_ECR_S;
/* End Added by lw0581,2013-11-12 for  VVD05864*/

/**
 * @struct tagDeviceInfo
 * @brief �����豸��ϸ��Ϣ
 * @attention
 */
typedef struct tagDeviceInfo
{
    /** �豸�������ȡֵΪ����#RESULT_TYPE_OK���쳣#RESULT_TYPE_ERROR */
    ULONG_32 ulResultType;

    /** �豸������ */
    CHAR szManufacturer[IMOS_STRING_LEN_128];

    /** �豸�ͺ� */
    CHAR szModel[IMOS_STRING_LEN_64];

    /** �豸�̼��汾 */
    CHAR szFirmware[IMOS_STRING_LEN_256];

    /** ��Ƶ����ͨ����Ŀ */
    CHAR szChannel[IMOS_STRING_LEN_32];
}DEVICE_INFO_S;

/**
 * @struct tagDeviceStatus
 * @brief �����豸״̬��Ϣ
 * @attention
 */
typedef struct tagDeviceStatus
{
    /** �豸�������ȡֵΪ����#RESULT_TYPE_OK���쳣#RESULT_TYPE_ERROR */
    ULONG_32 ulResultType;

    /** �Ƿ����ߣ�BOOL_TRUE�������ߣ� BOOL_FALSE�������� */
    BOOL_T bIsOnline;

    /** �Ƿ�������������ȡֵΪ����#RESULT_TYPE_OK���쳣#RESULT_TYPE_ERROR */
    ULONG_32 ulStatusType;

    /** ����������ԭ�� */
    CHAR szAbnormalReson[IMOS_DESC_LEN];

    /** �Ƿ���¼��BOOL_TRUE�����У� BOOL_FALSE����û�� */
    BOOL_T bIsRecord;
}DEVICE_STATUS_S;

#define SDK_GAI_MSG_LEN(Msg)                ((Msg)->ulBodyLen + sizeof(SDK_GAI_MSG_S) - sizeof(ULONG_32)) /**< GAI��Ϣ���� */
#define SDK_GAI_MSG_BODY_LEN(Msg)           ((Msg)->ulBodyLen)                      /**< GAI��Ϣ�峤�� */
#define SDK_GAI_IE_LEN(Ie)                  ((Ie)->ulBodyLen + sizeof(SDK_GAI_IE_S) - sizeof(ULONG_32))   /**< GAI IE���� */
#define SDK_GAI_IE_HEADDER_LEN              (sizeof(SDK_GAI_IE_S) - 4 * sizeof(UCHAR))
typedef struct tagSDKGAIMsg
{
    ULONG_32   ulFlag;                                 /**< ��ʼ��ʶ */
    UCHAR   ucMainVer;                              /**< �汾��, ��ǰΪ0x01  */
    UCHAR   ucSubVer;                               /**< �Ӱ汾����ǰΪ0x00 */
    UCHAR   ucListFlag;                             /**< ��Ϣ��������������ı�־λ */
    UCHAR   ucRerv;                                 /**< �����ֶ� */
    ULONG_32   ulMsgID;                                /**< ��Ϣ��ID, �μ� #GAI_MSG_ID_E */
    ULONG_32   ulMsgType;                              /**< ��Ϣ����, �μ� #GAI_MSG_TYPE_E */
    ULONG_32   ulSequence;                             /**< ��Ϣ���, ��ӦҪ������һ�� */
    CHAR    szSrcSysID[IMOS_MODULE_NAME_LEN];          /**< ����ϵͳID, ��ӦҪ������һ�� */
    CHAR    szDstSysID[IMOS_MODULE_NAME_LEN];          /**< ��ӦϵͳID, ��ӦҪ������һ�� */
    CHAR    szSrcSubSysID[8];    /**< ������ϵͳID, ��ӦҪ������һ�� */
    CHAR    szDstSubSysID[8];    /**< ��Ӧ��ϵͳID, ��ѡ */
    ULONG_32   ulSrcHandel;                            /**< ����ϵͳ���, ��ӦҪ������һ�� */
    ULONG_32   ulDstHandel;                            /**< ��Ӧϵͳ���, ��ѡ */
    ULONG_32   ulBodyLen;                              /**< ��Ϣ�峤�� */
    UCHAR   aucBody[4];                             /**< ��Ϣ������ */
}SDK_GAI_MSG_S;


#define SDK_GAI_IE_HEADER                                                               \
    ULONG_32       ulIEID;                             /**< IE��ID, �μ� #GAI_IE_ID_E */   \
    ULONG_32       ulBodyLen;                          /**< IE�峤�� */

/**
* @struct tagGAIIE
* @brief GAI��ϢIEͨ�� IE�ṹ
*/
typedef struct tagSDKGAIIE
{
    SDK_GAI_IE_HEADER
    UCHAR       aucBody[4];                         /**< IE������ */
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
    BOOL_T   bIsLocalDomain;                     /**< �Ƿ��� */
    ULONG_32    ulDstMsgID;                         /**< Ŀ����Ϣ���ͣ����DIM_MSG_ID_E */
}SDK_GAI_IE_DOM_INFO_S;

typedef struct tagSDKGAIIEData
{
    SDK_GAI_IE_HEADER

    UCHAR       ucHasDataType ;                   /**< �Ƿ�Я�� BOOL_TRUE��BOOL_FALSE */
    UCHAR       ucTypeVal;                        /**< DATA��Ϣ ý������ #GAI_MEDIA_TYPE_E */
    USHORT      usTypeLen;

    UCHAR       aucType[32];         /**< DATA��Ϣ ý�������ַ��� */

    UCHAR       ucSubTypeVal;                     /**< DATA��Ϣ ý�������� #GAI_SUB_MEDIA_TYPE_E */
    UCHAR       ucSpare1;
    USHORT      usSubTypeLen;

    UCHAR       aucSubType[32];   /**< DATA��Ϣ ý���������ַ��� */

    ULONG_32       ulDataLen;
    UCHAR       aucData[4];
}SDK_GAI_IE_DATA_S;

/* Begin Add by zhouquanwei/z01364 2013-11-08 of onvif֧�ֶ�profile */
/**
 * @struct tagVideoResolution
 * @brief �ֱ���
 * @attention
 */
typedef struct tagVideoResolution
{
    /* �ֱ��ʵĿ�� */
    ULONG_32 ulWidth;

    /* �ֱ��ʵĸ߶� */
    ULONG_32 ulHeight;
}VIDEO_RESOLUTION_S;

/**
 * @struct tagOnvifProfile
 * @brief onvif�����profile
 * @attention
 */
typedef struct tagOnvifProfile
{
    /* profile���� */
    CHAR       szName[IMOS_NAME_LEN];

    /* �����ʽ, ȡ���ھ�������ײ�ֵ, ȡֵΪ#IMOS_VIDEO_FORMAT_E */
    ULONG_32       ulEncodeFormat;

    /* �����ֱ��� */
    VIDEO_RESOLUTION_S      stVideoResolution;

    /* ���� */
    ULONG_32       ulBitRate;

    /* ����֡��:1, 3, 5, 8, 10, 15, 20, 25, 30, 60 */
    ULONG_32       ulFrameRate;
}ONVIF_Profile_S;

/**
 * @struct tagOnvifProfiles
 * @brief onvif�����profile����
 * @attention
 */
typedef struct tagOnvifProfiles
{
    /* profile���� */
    ULONG_32 ulOnvifProfileCount;

    /* profile */
    ONVIF_Profile_S stOnvifProfile[IMOS_ONVIF_PROFILE_MAX];
}ONVIF_PROFILES_S;

/**
 * @struct tagOnvifStreamCFGS
 * @brief ��������Ӧprofile����
 * @attention
 */
typedef struct tagOnvifStreamCFGS
{
    /* ��������� */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /* ������Profile���� */
    CHAR szStreamFirst[IMOS_NAME_LEN];

    /* ������Profile���� */
    CHAR szStreamSecond[IMOS_NAME_LEN];
}ONVIF_STREAM_CFGS_S;
/* End Add by zhouquanwei/z01364 2013-11-08 of onvif֧�ֶ�profile */

/* Begin added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */
/**
* @struct tagAlarmLinkageVocTalkToUI
* @brief �澯�����������Խ��ϱ�UI�ṹ
* @attention ��
*/
typedef struct tagAlarmLinkageVocTalkToUI
{
    /** ��������� */
    CHAR szCameraCode[IMOS_CODE_LEN];

    /** ���������Խ����û����� */
    CHAR szUserCode[IMOS_CODE_LEN];

}ALARM_LINKAGE_VOCTALK_TO_UI_S;
/* End added by liuzhikun/01420, 2013-11-12 for �澯�����������Խ� */

/** Begin:add by lw0581, 2013-8-16 for MPPD07153 �������澯�ָ�ֹͣ�洢 **/
typedef struct tagStoreActionForECRV2
{
    CHAR       szCamCode[IMOS_RES_CODE_LEN];    /** ������������� */

    CHAR       szCamName[IMOS_NAME_LEN];        /** ������������ƣ�ֻ���ڸ澯�������Բ�ѯ�ӿڣ� */

    ULONG_32      ulStorageStopFlag;               /** �澯�ָ���¼���Զ�ֹͣ��ʶ  0-���Զ�ֹͣ 1-�Զ�ֹͣ */

    ULONG_32      ulDelayTime;                     /** �澯�ָ���¼���ӳ�ʱ�䣬ֻ�е�ulStorageStopFlagȡֵΪ1����Ч��
                                                    ȡֵ��Χ0~1800��Ĭ��ֵ��0 */
    ULONG_32      ulReserver1;                     /** �����ֶΣ���ʼ��Ϊ0 */

    CHAR       szReserver2[32];                 /** �����ֶΣ���ʼ��Ϊ0*/
}STORE_ACTION_FOR_ECR_S;

/**
 * @struct tagAlarmActionForECRV2
 * @brief �澯��������(for ECR&NVR buzzer)
 * @attention
 */
typedef struct tagAlarmActionForECRV2
{

    /** �洢���������д洢������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_STORE_ACTION_MAXNUM */
    ULONG_32                       ulStoreActionNum;

    /** �洢�������� */
    STORE_ACTION_FOR_ECR_S     astStoreAction[IMOS_ALARM_STORE_ACTION_MAXNUM];

    /** Ԥ��λ����������Ԥ��λ������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_PRESET_ACTION_MAXNUM */
    ULONG_32                       ulPresetActionNum;

    /** Ԥ��λ�������� */
    PRESET_ACTION_S         astPresetAction[IMOS_ALARM_PRESET_ACTION_MAXNUM];

    /** ����ʵ��������������������ʵ������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM */
    ULONG_32                       ulScreenLiveActionNum;

    /** ����ʵ�������������� */
    SCREENLIVE_ACTION_FOR_ECR_S     astScreenLiveAction[IMOS_ALARM_SCREENLIVE_ACTION_MAXNUM];

    /** ����ʵ������������������������ʵ����������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM */
    ULONG_32                   ulMonitorLiveActionNum;

    /** ����ʵ������������������ */
    MONITORLIVE_ACTION_FOR_ECR_S    astMonitorLiveAction[IMOS_ALARM_MONITORLIVE_ACTION_MAXNUM];

    /** ������ͼ��˸����������������ͼ��˸������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_GIS_ACTION_MAXNUM */
    ULONG_32                   ulGISActionNum;

    /** ������ͼ��˸�������� */
    GIS_ACTION_S            astGISAction[IMOS_ALARM_GIS_ACTION_MAXNUM];

    /** ������������������������������������������ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM */
    ULONG_32                   ulSwitchOUTActionNum;

    /** ��������������������� */
    SWITCHOUT_ACTION_S      astSwitchOUTAction[IMOS_ALARM_SWITCHOUT_ACTION_MAXNUM];

    /** �������ݶ����������������ݶ�����ʵ����Ŀ, ȡֵ���ֵΪ#IMOS_ALARM_BACKUP_ACTION_MAXNUM */
    ULONG_32                   ulBackupActionNum;

    /** �������ݶ������� */
    BACKUP_ACTION_S         astBackupAction[IMOS_ALARM_BACKUP_ACTION_MAXNUM];

    /** �����������澯������Ŀ */
    ULONG_32                   ulBuzzerActionNum;

    /** �����������澯�����б� */
    BUZZER_ACTION_S         astBuzzerAction[IMOS_ALARM_BUZZER_ACTION_MAXNUM];

    /** �澯�����ʼ�ʹ�ܱ��, BOOL_TRUEΪʹ��; BOOL_FALSEΪ��ʹ�� */
    BOOL_T  bEmailActionEnabled;
}ALARM_ACTION_FOR_ECR_V2_S;
/** End:add by lw0581, 2013-8-16 for MPPD07153 �������澯�ָ�ֹͣ�洢 **/

/* Begin: added by lw0581, 2013.12.19 for  MPPD06992 */
/**
* @struct tagResAuthorityForECR
* @brief ��Դ��Ȩ����Ϣ
* @attention ��
*/
typedef struct tagResAuthorityForECR
{
    /** Ȩ���б� */
    ORG_AUTHORITY_S  stAuthorities;

    /** ��ԴID,ȫ��Ȩ��Ϊ�ַ���"0" */
    CHAR            szResId[IMOS_CODE_LEN];

} RES_AUTHORITY_FORECR_S;

/**
 * @struct tagOrgNodeInfoExtend
 * @brief ��֯��ڵ���Ϣ����֯������Ϣ+��ϵ��ʽ��Ϣ��
 * @attention
 */
typedef struct tagOrgNodeInfoExtend
{
    /** ��֯������Ϣ */
    ORG_NODE_INFO_S stOrgInfo;

    /** ��֯�����͵�������, 0Ϊ��Чֵ */
    ULONG_32 ulSubTypeofSubType;
}ORG_NODE_INFO_EXTEND_FORECR_S;

/**
* @struct tagResAuthorityQueryItemForECR
* @brief ��Դ��Ȩ���б�
* @attention ��
*/
typedef struct tagResAuthorityQueryItemForECR
{
    /** Ȩ���б� */
    ORG_AUTHORITY_S stAuthorities;

    /** ��Դ��Ϣ */
    RES_INFO_S stResInfo;
} RES_AUTHORITY_QUERY_ITEM_FORECR_S;

/** ������������״̬���� */
typedef enum tagBuzzerLinkedAlarmStatusForECR
{
    BUZZER_LINKED_ALARM_STATUS_DISABLE      = 0,        /**< ������������״̬δʹ�� */
    BUZZER_LINKED_ALARM_STATUS_ENABLE       = 1,        /**< ������������״̬ʹ�� */
    BUZZER_LINKED_ALARM_STATUS_UNSUPPORT    = 2,        /**< ���������������ܲ�֧�� */

    BUZZER_LINKED_ALARM_STATUS_MAX,                     /**< ���ֵ */
    BUZZER_LINKED_ALARM_STATUS_INVALID = 0xFFFF         /**< ��Чֵ */
}BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E;

/**
 * @struct tagCameraMotionDetectAlarmInfoForECR
 * @brief ��������챨��״̬��Ϣ
 * @attention
 */
 typedef struct tagCameraMotionDetectAlarmInfoForECR
{
    /** ��������� */
    CHAR  szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** ͨ��������Ϣ,�豸����Ϊ����ͷ���豸���� */
    DEV_CHANNEL_INDEX_S stDevChannelIndex;

    /** �澯������ʶ, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnabledFlag;

    /** �����ƻ�״̬, 1Ϊ�ƻ��Ѿ�����; 0Ϊ�ƻ�δ���� */
    ULONG_32 ulGuardPlanStatus;

}CAMERA_MOTION_DETECT_ALARM_INFO_FOR_ECR_S;

/**
 * @struct tagCameraMaskDetectAlarmInfoForECR
 * @brief ������ڵ�����״̬��Ϣ
 * @attention
 */
 typedef struct tagCameraMaskDetectAlarmInfoForECR
{
    /** ��������� */
    CHAR  szCameraCode[IMOS_DEVICE_CODE_LEN];

    /** ��������� */
    CHAR  szCamName[IMOS_NAME_LEN];

    /** ͨ��������Ϣ,�豸����Ϊ����ͷ���豸���� */
    DEV_CHANNEL_INDEX_S stDevChannelIndex;

    /** �澯������ʶ, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32 ulEnabledFlag;

    /** �����ƻ�״̬, 1Ϊ�ƻ��Ѿ�����; 0Ϊ�ƻ�δ���� */
    ULONG_32 ulGuardPlanStatus;

}CAMERA_MASK_DETECT_ALARM_INFO_FOR_ECR_S;

/**
 * @struct tagBuzzerLinkedAlarmInfoForECR
 * @brief �豸��澯����������״̬��Ϣ
 * @attention
 */
 typedef struct tagBuzzerLinkedAlarmInfoForECR
{
    /** �豸���� */
    CHAR szDeviceCode[IMOS_CODE_LEN];

    /** �豸���� */
    CHAR szDeviceName[IMOS_NAME_LEN];

    /** ������������״̬, �����BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulHighTemperatureLinkBuzzerStatus;

    /** ������������״̬, �����BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulLowTemperatureLinkBuzzerStatus;

    /** ������������״̬, �����BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulAntiRemoveLinkBuzzerStatus;

    /** ���ȹ�����������״̬, �����BUZZER_LINKED_ALARM_STATUS_FOR_ECR_E */
    ULONG_32 ulFanFaultLinkBuzzerStatus;

}BUZZER_LINKED_ALARM_INFO_FOR_ECR_S;
/* End: added by lw0581, 2013.12.19 for  MPPD06992 */

/**
 * @struct tagMapPointInfo
 * @brief  ������ľ�γ��
 * @attention
 */
typedef struct tagMapPointInfo
{
    /* �����꾭�� */
    CHAR szPointLon[IMOS_STRING_LEN_32];

    /* �����꾭�� */
    CHAR szPointLat[IMOS_STRING_LEN_32];
}MAP_POINT_INFO_S;

/**
 * @struct tagMapRoadInfo
 * @brief ��ͼ��·��Ϣ�ṹ
 * @attention
 */
typedef struct tagMapRoadInfo
{
    /**< ��·ID,ϵͳ�Զ����� */
    DULONG  dulRoadID;

    /**< ��·���� */
    CHAR    szRoadDesc[IMOS_DESC_LEN];

    /**< ��·����(����/����)#MAP_ROAD_DIRECTION_E*/
    ULONG_32   ulDirection;

    /**< ��·�����ĵ����� */
    ULONG_32   ulPointNum;

    /**< ��·�ľ����㣬�ݶ�Ϊ���64���㣬��Ϊ���·����ʾ */
    MAP_POINT_INFO_S    astPointList[IMOS_MAP_ROAD_POINT_MAX_NUM];
}MAP_ROAD_INFO_S;


/**
 * @struct tagMapRoadFlowmeter
 * @brief ��·����ͳ�����ýṹ
 * @attention
 */
typedef struct tagMapRoadFlowmeter
{
    /**< ͳ������ID����̨�Լ����� */
    DULONG dulFlowmeterID;

    /**< ��·ID */
    DULONG dulRoadID;

    /**< ��·������,2��һ�� */
    MAP_POINT_INFO_S    astSectionPoint[IMOS_MAP_LINT_POINT_NUM];

    /**< ��·�Ĺյ㣬2��һ�ε�· */
    MAP_POINT_INFO_S    astRoadPoint[IMOS_MAP_LINT_POINT_NUM];

    /**<  ӵ���ٶȷ�ֵ,��λ����ÿСʱ */
    ULONG_32   ulBlockSpeed;

    /**< �����ٶȷ�ֵ����λ����ÿСʱ */
    ULONG_32   ulSlowSpeed;
}MAP_ROAD_FLOWMETER_S;

/**
 * @struct tagMAPMInfo
 * @brief MAPM(��ͼ������)��Ϣ
 * @attention
 */
typedef struct tagMAPMInfo
{
    /** ���� */
    CHAR szMAPMCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szMAPMName[IMOS_NAME_LEN];

    /** ������֯ */
    CHAR szOrgCode[IMOS_CODE_LEN];

    /** ������֯���ƣ���ѯ���أ���������¿��Բ��� */
    CHAR szOrgName[IMOS_NAME_LEN];

    /** MAPM���ͣ�Ŀǰ��д0��ΪMAP8500 */
    ULONG_32 ulType;

    /** �豸��ַ���ͣ�1-IPv4 2-IPv6 */
    ULONG_32 ulDevAddrType;

    /** �豸��ַ����ѯ���أ���������¿��Բ��� */
    CHAR  szDevAddr[IMOS_IPADDR_LEN];

    /** �豸�Ƿ�����, ȡֵΪ#IMOS_DEV_STATUS_ONLINE��#IMOS_DEV_STATUS_OFFLINE����imos_def.h�ж��� */
    ULONG_32 ulIsOnline;

    /** �豸��չ״̬��Ԥ�� */
    ULONG_32 ulDevExtStatus;

    /** ����, �ݲ�ʹ�ã���� */
    CHAR szDevDesc[IMOS_DESC_LEN];

    /** Ԥ���ֶ���Ϣ */
    RESERVED_INFO_S stReservedInfo;

} MAPM_INFO_S;

/**
 * @struct tagDevInst
 * @brief �豸��WEBGIS��λ��Ϣ
 * @attention
 */
typedef struct tagDevWebGisInfo
{
    /** ���� */
    CHAR szDevCode[IMOS_CODE_LEN];

    /** ���� */
    CHAR szLongitude[IMOS_STRING_LEN_32];

    /** γ�� */
    CHAR szLatitude[IMOS_STRING_LEN_32];

    /** ָ�� */
    CHAR    szDirection[IMOS_STRING_LEN_32];

    /** �ӽ� */
    CHAR szViewAngle[IMOS_STRING_LEN_32];

    /** �豸���� */
    ULONG_32 ulDevType;

    /** ��ͼ����-���ߵ�ͼ��4 */
    ULONG_32 ulMapType;
}DEV_WEBGIS_INFO_S;


/**
* @struct tagBMResQueryItemV2
* @brief BM������Դ����Ϣ��(��ѯBM������Դ�б�ʱ����)
* @attention ��
*/
typedef struct tagBMResQueryItemV2
{
    /** ������Դ���� */
    CHAR  szResCode[IMOS_CODE_LEN];

    /** BM����, BM��Ψһ��ʶ */
    CHAR  szBMCode[IMOS_DEVICE_CODE_LEN];

    /** BM���� */
    CHAR  szBMName[IMOS_NAME_LEN];

    /** ��Դ���� */
    CHAR  szResName[IMOS_NAME_LEN];

    /** ������Դ����#BAK_RES_TYPE_E */
    ULONG_32 ulResType;

    /** �洢�豸���� */
    CHAR  szStoreDevName[IMOS_NAME_LEN];

    /** ������Դ״̬#BAK_RES_STATUS_E */
    ULONG_32 ulResStatus;

    /** ��������С����MBΪ��λ */
    ULONG_32 ulTotalCapacity;

    /** ʣ��������С����MBΪ��λ */
    ULONG_32 ulSpareCapacity;

    /** ������Դȫ·��-��������Դ����Ч */
    CHAR  szResPath[IMOS_FILE_PATH_LEN];

    /** ��Դҵ�����ͣ�ö��ֵΪ#RES_SERVICE_TYPE_E */
    ULONG_32 ulResServiceType;

    /** LUN ID */
    ULONG_32  ulLunId;                        

    /** Target�� */
    CHAR    szBmTarget[IMOS_STRING_LEN_64];    

    /** Initiator�� */
    CHAR    szInitiator[IMOS_STRING_LEN_64];   

    /* IPSAN�豸��ַ */
    CHAR    szDevAddress[IMOS_IPADDR_LEN];     

    /** �����ֶ� */
    CHAR  szReserve[256];      
    
} BM_RES_QUERY_ITEM_S_V2;

typedef struct tagDomainProtocolInfo
{
    /** Э������*/
    ULONG_32    ulProtocolType;
    
    /** Э������ */
    CHAR    szProtocolDesc[IMOS_CODE_LEN];

    /** SG ����*/
    CHAR    szSGCode[IMOS_DEVICE_CODE_LEN];
    
    /** ֧�ָ�Э���SG IP��ַ */
    CHAR    szSGIp[IMOS_IPADDR_LEN];

    /** ֧�ָ�Э���SG �˿� */
    ULONG_32   ulSGPort;

    /** ��SG�Ƿ�ΪĬ��SG */
    ULONG_32   IsDefaultSG;
}DOMAIN_PROTOCOL_INFO_S;



/**
 * @struct tagNewOSDRowCommonParamV2
 * @brief NewOSD ͨ�ò���
 * @attention
 */
typedef struct tagNewOSDRowCommParamV2
{
    ULONG_32  ulFontEffect;                  /** ����Ч�� */

    ULONG_32  ulFontSize;                    /** �����С */
    
    ULONG_32       ulOsdDateFormat;          /* OSDʱ���ʽ */
    
    ULONG_32       ulOsdMinMargin;           /* ��С��� */
    
   
    CHAR  szReserve[128];                   /** �����ֶ� */

}NEW_OSD_ROW_COMM_PARAM_S_V2;


/**
 * @struct tagVideoArea
 * @brief ��Ƶ������Ϣ
 * @attention
 */
typedef struct tagVideoAreaV2
{
    /** ��������, ȡֵΪ1~4 */
    ULONG_32       ulAreaIndex;

    /** �Ƿ�ʹ��, 1Ϊʹ��; 0Ϊ��ʹ�� */
    ULONG_32       ulEnabledFlag;

    /** ������, 1��5����1����������ߡ���ֵ�����˶����������Ч */
    ULONG_32       ulSensitivity;

    /** �������� */
    AREA_SCOPE_S stAreaScope;
    
    /* ���뷽ʽ */
    ULONG_32       ulFontAlign;

    /** �����ֶ� */
    CHAR  szReserve[128]; 

}VIDEO_AREA_S_V2;

typedef struct tagDnsInfo
{
    CHAR szPreferredDNS[IMOS_IPADDR_LEN];    /** ��ѡDNS������IP��ַ */
    CHAR szAlternateDNS[IMOS_IPADDR_LEN];    /** ��ѡDNS������IP��ַ*/
}DNS_INFO_S;

typedef struct tagNicInfo
{
    ULONG       ulNicIndex;             /** ������� */
    ULONG       ulNicModeType;          /** ������������ ��Ӧö��ETH_SPEED_E Ĭ������Ӧ�����治������*/
    CHAR        szIPv4Addr[IMOS_IPADDR_LEN];        /** IPv4IP��ַ */
    CHAR        szIPv4NetMask[IMOS_IPADDR_LEN];     /** IPv4�������� */
    CHAR        szIPv4Gateway[IMOS_IPADDR_LEN];     /** IPv4Ĭ������ */
    CHAR        szMacAddr[IMOS_MAC_ADDR_LEN];       /** MAC��ַ*/
    ULONG       ulMtu;          /** MTU Ĭ��1500 */
    ULONG       ulVirtualIPEnabled; /** �Ƿ�������IP��ַ 0-������(Ĭ��) 1-����*/
    CHAR        szVirtualIPAddr[IMOS_IPADDR_LEN];   /** ����IP��ַ */
    CHAR        szVirtualIPNetMask[IMOS_IPADDR_LEN];        /** ����IP�������� */
    CHAR        szVirtualIPGateWay[IMOS_IPADDR_LEN];        /** ����IP���� */
}NIC_INFO_S;

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

