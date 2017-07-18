/*******************************************************************************
 Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              sdk_tollgate_func.h

  Project Code: IMOS_SDK
   Module Name: SDK
  Date Created: 2011-03-14
        Author: baoyihui/02795
   Description: ����SDK����ӿ�
                ע��: 1)���з�ҳ��ѯʱ�������б�ռ����ⲿ���룬
                        ��С���ݷ�ҳ��ѯʱһҳ�ĸ����������롣
                      2)�����ֵ�����˵���ο�IMOS_QueryDictionaryDataList�ӿ�˵��

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/


#ifndef _IMOS_SDK_TOLLGATE_FUNC_H_
#define _IMOS_SDK_TOLLGATE_FUNC_H_

#ifdef  __cplusplus
extern "C"{
#endif

/** @defgroup groupSDKTollgate ����SDK
*   ����SDK
*   @{
*/

/**
* ��ѯ���� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode          ���ڱ���
* @param [OUT]  pstTollgateInfo         ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgate
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    OUT  TOLLGATE_INFO_S                *pstTollgateInfo
);

/**
* ��ѯ�����б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szOrgCode               ��֯����
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#NAME_TYPE[��������])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateList         �����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szOrgCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_INFO_S                *pstTollgateList
);

#if 0
#endif

/**
* ��ѯ��/���ص�λ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionDeptCode   ��/���ص�λ����
* @param [OUT]  pstDispositionDept      ��/���ص�λ��Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDispositionDept
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionDeptCode[IMOS_CODE_LEN],
    OUT  DISPOSITION_DEPT_S             *pstDispositionDept
);

/**
* ��ѯ��/���ص�λ�б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������Ϊ#CODE_TYPE[��λ����]��#NAME_TYPE[��λ����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDispositionDeptList  ��/���ص�λ�б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDispositionDeptList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DISPOSITION_DEPT_S             *pstDispositionDeptList
);

#if 0
#endif

/**
* ���Ӳ������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDispositionInfo      ������Ϣ
* @param [IN]   pstMapAreaDisposeResInfo���򲼿���Դ��Ϣ
* @parma [IN]   pstDisposePlanInfo      ���ؼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ������Ƭ��Ҫͨ��FTP�ϴ�����������ͨ��IMOS_GetFTPInfoByOper�ӿڻ�ȡFTP���������
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STATEMENT_DISPOSITION_INFO_S    *pstDispositionInfo,
    IN  MAP_AREA_DISPOSE_RES_INFO_S     *pstMapAreaDisposeResInfo,
    IN  DISPOSE_PLAN_INFO_S             *pstDisposePlanInfo
);

/**
* ɾ���������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode       ���ر��
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ɾ��ʱ��̨��ͬʱɾ��������Ƭ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN]
);

/**
* �޸Ĳ������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDispositionInfo      ������Ϣ
* @parma [IN]   pstDisposePlanInfo      ���ؼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  STATEMENT_DISPOSITION_INFO_S    *pstDispositionInfo,
    IN  DISPOSE_PLAN_INFO_S             *pstDisposePlanInfo
);

/**
* ���� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode       ���ر��
* @param [IN]   pstUndoDispositionInfo  ������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UndoStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  STATEMENT_DISPOSITION_UNDO_INFO_S  *pstUndoDispositionInfo
);

/**
* �����򳷿� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode       ���ر��
* @param [IN]   szDomainCode            �����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UndoDomainStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  CHAR                               szDomainCode[IMOS_CODE_LEN]
);

/**
* ���������²��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode       ���ر��
* @param [IN]   szDomainCode            �����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_RedoDomainStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S               *pstUserLogIDInfo,
    IN  CHAR                               szDispositionCode[IMOS_CODE_LEN],
    IN  CHAR                               szDomainCode[IMOS_CODE_LEN]
);

/**
* ��ѯ�������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode       ���ر��
* @param [OUT]  pstDispositionInfo      ������Ϣ
* @param [OUT]  pstMapAreaDisposeResInfo���򲼿���Դ��Ϣ
* @param [OUT]  pstDisposePlanInfo      ���ؼƻ���Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDisposition
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN],
    OUT  STATEMENT_DISPOSITION_INFO_S   *pstDispositionInfo,
    OUT  MAP_AREA_DISPOSE_RES_INFO_S    *pstMapAreaDisposeResInfo,
    OUT  DISPOSE_PLAN_INFO_S            *pstDisposePlanInfo
);

/**
* ��ѯ�����������б� \n
* @param [IN]   pstUserLogIDInfo          �û���¼ID��Ϣ��ʶ
* @param [IN]   szDispositionCode         ���ر��
* @param [IN]   pstQueryCondition         ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo          �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo            ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDispositionDomainList  ���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[�����]
* - #NAME_TYPE[������]
* - #DISPOSITION_STATUS[����״̬]
* - #DISPOSITION_RESULT[���ش�����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDispositionDomainList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDispositionCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  STATEMENT_DISPOSITION_DOMAIN_S *pstDispositionDomainList
);

/**
* ��ѯ�����б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDispositionList      �����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #DOMAIN_CODE[�����]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #DISPOSITION_DEPT[���ص�λ����]
* - #DISPOSITION_USER[������Ա����]
* - #PRIORITY_TYPE[�������ȼ�]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_STATUS[����״̬]
* - #DISPOSITION_UNDO_DEPT[���ص�λ����]
* - #DISPOSITION_UNDO_USER[������Ա����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryStatementDispositionList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  STATEMENT_DISPOSITION_INFO_S   *pstDispositionList
);

#if 0
#endif

/**
* ��Ӻ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleBlacklist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_BLACKLIST_S             *pstVehicleBlacklist
);

/**
* ɾ�������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szBlacklistCode         ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBlacklistCode[IMOS_CODE_LEN]
);

/**
* �޸ĺ����� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleBlacklist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_BLACKLIST_S             *pstVehicleBlacklist
);

/**
* ��ѯ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szBlacklistCode         ���������
* @param [OUT]  pstVehicleBlacklist     ��������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleBlacklist
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szBlacklistCode[IMOS_CODE_LEN],
    OUT  VEHICLE_BLACKLIST_S            *pstVehicleBlacklist
);

/**
* ��ѯ�������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleBlacklistList �������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #PRIORITY_TYPE[�������ȼ�]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_DEPT[¼�뵥λ����]
* - #DISPOSITION_USER[¼����Ա����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleBlacklistList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_BLACKLIST_S            *pstVehicleBlacklistList
);

#if 0
#endif

/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleDataList      ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DATA_TYPE[������������]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - VEHICLE_DATA_TYPE[������������]�����������ʱ����ʹ��SECTION_CODE��ѯ����
* - VEHICLE_DATA_TYPE[������������]���ڹ�������ʱ����ʹ��DOMAIN_CODE��TOLLGATE_CODE��ѯ����
* - DOMAIN_CODE��TOLLGATE_CODEֻ����EQUAL_FLAG�߼���ϵ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_S                 *pstVehicleDataList
);

/**
* ��ѯ���������б�(�ڲ��ӿڣ�����ʹ��) \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulResNum                ��Դ����
* @param [IN]   pstResList              ��Դ�б�
* @param [IN]   ulNestConditionNum      Ƕ�ײ�ѯ��������
* @param [IN]   pstNestConditionList    Ƕ�ײ�ѯ�����б�
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleDataV2List    ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_IDENTIFY_STATUS[ʶ��״̬]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #VEHICLE_DATA_TYPE[������������]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - VEHICLE_DATA_TYPE[������������]�����������ʱ����ʹ��SECTION_CODE��ѯ����
* - VEHICLE_DATA_TYPE[������������]���ڹ�������ʱ����ʹ��DOMAIN_CODE��TOLLGATE_CODE��ѯ����
* - DOMAIN_CODE��TOLLGATE_CODEֻ����EQUAL_FLAG�߼���ϵ
* - Ƕ�ײ�ѯ����֮������Ĺ�ϵ����ѯ����ȡֵ�б��ȡֵ֮���ǻ�Ĺ�ϵ
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleDataListV3
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulResNum,
    IN  RES_INFO_S                      *pstResList,
    IN  ULONG_32                           ulNestConditionNum,
    IN  NEST_QUERY_CONDITION_S          *pstNestConditionList,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_DATA_V2_S              *pstVehicleDataV2List
);

/**
* ������ϢУ�� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleData          ������ʻ��¼
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_DATA_S                  *pstVehicleData
);

/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstVehicleAlarmDataList ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #CODE_TYPE[����������Ϣ���]
* - #VEHICLE_DATA_CODE[������Ϣ���]
* - #DOMAIN_CODE[����������֯���]
* - #IS_QUERY_SUB[�Ƿ�����¼���֯]
* - #TOLLGATE_CODE[���ڱ��]
* - #LANE_NUMBER[������]
* - #LANE_DIRECTION[��ʻ������]
* - #PASS_TIME[ͨ��ʱ��/ʻ������ʱ��]
* - #VEHICLE_LICENSE_PLATE[���ƺ���]
* - #VEHICLE_LICENSE_PLATE_TYPE[��������]
* - #VEHICLE_LICENSE_PLATE_COLOR[������ɫ]
* - #SPEED_TYPE[�����ٶ�]
* - #LIMIT_SPEED[��������]
* - #VEHICLE_LOGO[����Ʒ��]
* - #VEHICLE_TYPE[��������]
* - #VEHICLE_COLOR_DEPTH[������ɫ��ǳ]
* - #VEHICLE_COLOR[������ɫ]
* - #VEHICLE_STATUS[��ʻ״̬]
* - #ALARM_TYPE[�澯���]
* - #DISPOSITION_CODE[���ر��]
* - #DISPOSITION_TYPE[�������]
* - #DISPOSITION_DEPT[���ص�λ����]
* - #DISPOSITION_USER[������Ա����]
* - #EVENT_TIME[����ʱ��]
* - #VEHICLE_DEAL_STATUS[������]
* - #SECTION_CODE[����������]
* - #PASS_TIME2[ʻ������ʱ��]
* - #PLACE_CODE[Υ�µص����]
* - #EQUIPMENT_TYPE[�ɼ�����]
* - #DEPT_CODE[���ű���]
* - #COMBINE_FLAG[�ϳɱ�ʶ]
* @attention
* - DOMAIN_CODE��TOLLGATE_CODE����ͬʱʹ��
* - ALARM_TYPE[�澯���]���ڲ��ظ澯ʱ��DISPOSITION_CODE��д�������ر�ţ���ʹ��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER
* - ALARM_TYPE[�澯���]���ں������澯ʱ��DISPOSITION_CODE��д��������ţ�DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - ALARM_TYPE[�澯���]����������ٸ澯ʱ��DISPOSITION_CODE��DISPOSITION_TYPE��DISPOSITION_DEPT��DISPOSITION_USER��Ч
* - DOMAIN_CODE��TOLLGATE_CODE��DISPOSITION_DEPT��DISPOSITION_USERֻ����EQUAL_FLAG�߼���ϵ
* - COMBINE_FLAG[�ϳɱ�ʶ]��֧�ֵ���/�����ڣ�����0����ʾ�Ѻϳɣ�������0����ʾδ�ϳ�
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryVehicleAlarmDataList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  VEHICLE_ALARM_DATA_S           *pstVehicleAlarmDataList
);

/**
* ������������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVehicleAlarmData     ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyVehicleAlarmData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  VEHICLE_ALARM_DATA_S            *pstVehicleAlarmData
);

#if 0
#endif

/**
* �����������Ͳ�ѯ�����ֵ�ö���б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����(֧�ֵĲ�ѯ��������:#CODE_TYPE[�����ֵ����];NAME_TYPE[�����ֵ�����])
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDictionaryDataList   �����ֵ�ö���б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDictionaryDataList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  DICTIONARY_DATA_S              *pstDictionaryDataList
);

/**
* ���ݲ������ͻ�ȡFTP������Ϣ \n
* @param [IN]   pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   ulFtpOperType                  FTP�������ͣ��ο�#FTP_OPER_TYPE_E
* @param [OUT]  pstFtpInfo                     FTP������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_GetFTPInfoByOper
(
    IN  USER_LOGIN_ID_INFO_S    *pstUserLogIDInfo,
    IN  ULONG_32                   ulFtpOperType,
    OUT FTP_INFO_S              *pstFtpInfo
);

#if 0
#endif

/**
* ���ӿ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateCameraInfo   �����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_CAMERA_INFO_S          *pstTollgateCameraInfo
);

/**
* ɾ��������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCameraCode    �������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCameraCode[IMOS_CODE_LEN]
);

/**
* �޸Ŀ������ \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstTollgateCameraInfo   �����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  TOLLGATE_CAMERA_INFO_S          *pstTollgateCameraInfo
);

/**
* ��ѯ������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCameraCode    �������
* @param [OUT]  pstTollgateCameraInfo   �����Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCameraCode[IMOS_CODE_LEN],
    OUT  TOLLGATE_CAMERA_INFO_S         *pstTollgateCameraInfo
);

/**
* ��ѯ��������б� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode          �������ڱ���
* @param [IN]   pstQueryCondition       ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo        �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo          ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateCameraList   ����б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ/������������Ϊ#NAME_TYPE[�������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateCameraList
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S        *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S               *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                *pstRspPageInfo,
    OUT  TOLLGATE_CAMERA_INFO_S         *pstTollgateCameraList
);

#if 0
#endif

/**
* ��ʼ����ʵʱ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode            �������
* @param [IN]   szMonitorCode           �������
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StartTollgateMonitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN],
    IN  CHAR                            szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

/**
* ֹͣ����ʵʱ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szMonitorCode           �������
* @param [IN]   ulOperateCode           ����ԭ����, ȡֵΪ#CS_OPERATE_CODE_E
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_StopTollgateMonitor
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szMonitorCode[IMOS_CODE_LEN],
    IN  ULONG_32                           ulOperateCode
);

#if 0
#endif

/**
* �󶨿�������� \n
* @param [IN]   pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVideoCameraBindInfo   �������������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ץ�ĵĿ��ڳ��������ͼ�صĿ��ڳ�����������ͬʱΪ0
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_BindTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_VIDEO_CAMERA_BIND_INFO_S   *pstVideoCameraBindInfo
);

/**
* ��󶨿�������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode          ���ڱ���
* @param [IN]   szCameraCode            ���������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_UnbindTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szTollgateCode[IMOS_CODE_LEN],
    IN  CHAR                            szCameraCode[IMOS_CODE_LEN]
);

/**
* �޸Ŀ������������Ϣ \n
* @param [IN]   pstUserLogIDInfo         �û���¼ID��Ϣ��ʶ
* @param [IN]   pstVideoCameraBindInfo   �������������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �����޸İ󶨵ĳ���
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  TOLLGATE_VIDEO_CAMERA_BIND_INFO_S   *pstVideoCameraBindInfo
);

/**
* ��ѯ��������� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szCameraCode                �������������
* @param [OUT]  pstTollgateVideoCameraItem  �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateVideoCamera
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szCameraCode[IMOS_CODE_LEN],
    OUT TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S  *pstTollgateVideoCameraItem
);


/**
* ��ѯ����������б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode                  �������ڱ���
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstTollgateVideoCameraItemList  ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ/������������Ϊ#NAME_TYPE[���������]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateVideoCameraList
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  CHAR                                 szTollgateCode[IMOS_CODE_LEN],
    IN  COMMON_QUERY_CONDITION_S             *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                    *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT  TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S  *pstTollgateVideoCameraItemList
);

/**
* ���ݿ��ںͳ�����ѯ����� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szTollgateCode              �������ڱ���
* @param [IN]   ulLaneNumber                ������
* @param [OUT]  pstTollgateVideoCameraItem  �����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryTollgateVideoCameraByTollgateAndLane
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szTollgateCode[IMOS_CODE_LEN],
    IN  ULONG_32                               ulLaneNumber,
    OUT TOLLGATE_VIDEO_CAMERA_QUERY_ITEM_S  *pstTollgateVideoCameraItem
);

#if 0
#endif

/**
* ���������ֵ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       �����ֵ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDictionaryData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_S               *pstDictionaryData
);

/**
* ɾ�������ֵ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   szDictionaryDataCode    �����ֵ����
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDictionaryData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  CHAR                            szDictionaryDataCode[IMOS_DICTIONARY_KEY_LEN]
);

/**
* �޸������ֵ��� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDictionaryDataType    �����ֵ����ͣ��ο�#DICTIONARY_TYPE_E
* @param [IN]   pstDictionaryData       �����ֵ���
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note �������޸������ֵ�����
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDictionaryData
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  ULONG_32                           ulDictionaryDataType,
    IN  DICTIONARY_DATA_S               *pstDictionaryData
);

#if 0
#endif

/**
* ��Ӳ������� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDetectionRoadSection     ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_AddDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DETECTION_ROAD_SECTION_S        *pstDetectionRoadSection
);

/**
* ɾ���������� \n
* @param [IN]   pstUserLogIDInfo            �û���¼ID��Ϣ��ʶ
* @param [IN]   szDetectionRoadSectionCode  ����������
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_DelDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  CHAR                            szDetectionRoadSectionCode[IMOS_CODE_LEN]
);

/**
* �޸Ĳ������� \n
* @param [IN]   pstUserLogIDInfo        �û���¼ID��Ϣ��ʶ
* @param [IN]   pstDetectionRoadSection ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S            *pstUserLogIDInfo,
    IN  DETECTION_ROAD_SECTION_S        *pstDetectionRoadSection
);

/**
* ��ѯ�������� \n
* @param [IN]   pstUserLogIDInfo               �û���¼ID��Ϣ��ʶ
* @param [IN]   szDetectionRoadSectionCode     ����������
* @param [OUT]  pstDetectionRoadSectionItem    ����������Ϣ
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDetectionRoadSection
(
    IN  USER_LOGIN_ID_INFO_S                *pstUserLogIDInfo,
    IN  CHAR                                szDetectionRoadSectionCode[IMOS_CODE_LEN],
    OUT DETECTION_ROAD_SECTION_QUERY_ITEM_S *pstDetectionRoadSectionItem
);

/**
* ��ѯ���������б� \n
* @param [IN]   pstUserLogIDInfo                �û���¼ID��Ϣ��ʶ
* @param [IN]   pstQueryCondition               ͨ�ò�ѯ����
* @param [IN]   pstQueryPageInfo                �����ҳ��Ϣ
* @param [OUT]  pstRspPageInfo                  ��Ӧ��ҳ��Ϣ
* @param [OUT]  pstDetectionRoadSectionItemList ���������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ֧�ֵĲ�ѯ��������
* - #SECTION_CODE[������]
* - #NAME_TYPE[��������]
* - #TOLLGATE_CODE_IN[���ڱ�ţ�ʻ�룩]
* - #TOLLGATE_CODE_OUT[���ڱ�ţ�ʻ����]
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDetectionRoadSectionList
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    IN  COMMON_QUERY_CONDITION_S             *pstQueryCondition,
    IN  QUERY_PAGE_INFO_S                    *pstQueryPageInfo,
    OUT  RSP_PAGE_INFO_S                     *pstRspPageInfo,
    OUT  DETECTION_ROAD_SECTION_QUERY_ITEM_S *pstDetectionRoadSectionItemList
);

/**
* �޸Ĳ������䳬�ٰٷֱ����� \n
* @param [IN]   pstUserLogIDInfo                       �û���¼ID��Ϣ��ʶ
* @param [IN]   ulDetectionRoadSectionVioConfNum       �������䳬�ٰٷֱ���������
* @param [IN]   pstDetectionRoadSectionVioConfList     �������䳬�ٰٷֱ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_ModifyDetectionRoadSectionVioConf
(
    IN  USER_LOGIN_ID_INFO_S                  *pstUserLogIDInfo,
    IN  ULONG_32                                 ulDetectionRoadSectionVioConfNum,
    IN  DETECTION_ROAD_SECTION_VIO_CONF_S     astDetectionRoadSectionVioConfList[IMOS_DETECTION_ROAD_SECTION_VIO_CONF_MAX_NUM]
);

/**
* ��ѯ�������䳬�ٰٷֱ����� \n
* @param [IN]   pstUserLogIDInfo                         �û���¼ID��Ϣ��ʶ
* @param [OUT]  pulDetectionRoadSectionVioConfNum        �������䳬�ٰٷֱ���������
* @param [OUT]  pstDetectionRoadSectionVioConfList       �������䳬�ٰٷֱ������б�
* @return �������½����
* - �ɹ���
* - #ERR_COMMON_SUCCEED
* - ʧ�ܣ�
* -     ���ز�������룬���������ļ�
* @note ��
*/
IMOS_EXPORT ULONG_32 STDCALL IMOS_QueryDetectionRoadSectionVioConf
(
    IN  USER_LOGIN_ID_INFO_S                 *pstUserLogIDInfo,
    OUT ULONG_32                                *pulDetectionRoadSectionVioConfNum,
    OUT DETECTION_ROAD_SECTION_VIO_CONF_S    astDetectionRoadSectionVioConfList[IMOS_DETECTION_ROAD_SECTION_VIO_CONF_MAX_NUM]
);

/** @} */ /* end of groupSDKTollgate */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif

