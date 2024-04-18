
// *@file tianzuo_QiankunInterface.h
// *@brief 天佐.乾坤袋 (tianzuo.Qiankun)
// *@version 1.0
// *@section LICENSE Copyright © 2003-2103 郑天佐 Corporation
// *@author 郑天佐 (zhengtianzuo)
// *@date 2013-4-3
#pragma once
#include <stdbool.h>


//!@brief 乾坤袋接口 for python java csharp javascript php visualbasic go
//!@class tianzuo_QiankunInterface for python java csharp javascript php visualbasic go
#ifdef __cplusplus
extern "C"
{
#endif
    /*!
    *@name initialize
    *@brief 接口初始化
    *@param[in] 无
    *@return 模块类指针
    *@author 郑天佐
    *@date 2013-4-3
    */
	void* tianzuo_QiankunInterface_initialize();

    /*!
    *@name terminate
    *@brief 接口销毁
    *@param[in] QiankunInt_pointer 模块类指针
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
	void tianzuo_QiankunInterface_terminate(void* *QiankunInt_pointer);

    /*!
    *@name initialize
    *@brief 组件初始化
    *@param[in] QiankunInt_pointer 模块类指针
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_initialize(void* QiankunInt_pointer);

    /*!
    *@name db_create_database
    *@brief 创建数据库
    *@param[in] QiankunInt_pointer 模块类指针
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] db_name 数据库名称
    *@param[in] over_write 是否重写
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_create_database(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* db_name, bool const over_write);

    /*!
    *@name db_open_database
    *@brief 打开数据库
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_open_database(void* QiankunInt_pointer, const char* db_file_name, const char* db_password);

    /*!
    *@name db_close_database
    *@brief 关闭数据库
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_close_database(void* QiankunInt_pointer, const char* db_file_name, const char* db_password);

    /*!
    *@name db_change_password
    *@brief 修改密码
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] new_password 新的数据库密码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_change_password(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* new_password);

    /*!
    *@name db_get_name
    *@brief 获取数据库名称
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[out] db_name 数据库名称
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_get_name(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, char** db_name);

    /*!
    *@name db_get_total_number
    *@brief 获取数据库数据总数
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[out] file_number 数据库数据总数
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_get_total_number(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, int* file_number);

    /*!
    *@name db_rebuild
    *@brief 重建数据库
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] new_db_file_name 新的数据库文件路径
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_rebuild(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* new_db_file_name);

    /*!
    *@name db_set_name
    *@brief 设置数据库名称
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] db_name 数据库名称
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_set_name(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* db_name);

    /*!
    *@name db_set_total_number
    *@brief 设置数据库总数
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] add_file_number 数据库总数
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_db_set_total_number(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, int const add_file_number);

    /*!
    *@name data_check
    *@brief 检测数据有效性
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data_type 数据类型
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    int tianzuo_QiankunInt_data_check(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int data_type);

    /*!
    *@name data_delete
    *@brief 删除数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_delete(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name);

    /*!
    *@name data_deletes
    *@brief 删除多个数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称 json: "{\"data\":[\"name1\",\"name2\",\"name3\"]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_deletes(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name);

    /*!
    *@name data_get_size
    *@brief 获取数据大小
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] size_type 数据大小类型
    *@param[in] data_name 数据名称
    *@param[in] data_type 数据类型
    *@param[out] data 数据大小
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_get_size(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, int size_type, const char* data_name, int data_type, int* data);

    /*!
    *@name data_get_size_list
    *@brief 获取数据大小
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] size_type 数据大小类型
    *@param[in] data_name 数据名称
    *@param[in] data_type 数据类型
    *@param[out] data 数据大小 json: {'data': [4, 2, 4, 4, 8, 8, 8, 37, 258560, 258560, 258560, 258560, 12, 24, 24, 48, 48, 48, 30]}
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_get_size_list(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, int size_type, char** data);

    /*!
    *@name data_get_name_list
    *@brief 获取数据名称列表
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] name_type 名称类型
    *@param[out] data 数据内容 json: {\"data\":[\"name1\",\"name2\",\"name3\"]}
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_get_name_list(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, int name_type, char** data);

    /*!
    *@name data_get_type_list
    *@brief 获取数据类型列表
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[out] data 数据内容 json: {\"data\": [2, 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 8, 11, 12, 13, 14, 15, 16, 17]}
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_get_type_list(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, char** data);

    /*!
    *@name data_get_type_total_number_list
    *@brief 获取数据类型总数列表
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[out] data 数据内容 json: {\"data\": [1, 2, 1, 1, 1, 1, 1, 4, 0, 1, 1, 1, 1, 1, 1, 1]}
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_get_type_total_number_list(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, char** data);

    /*!
    *@name data_get_index_list
    *@brief 获取序号列表
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_get_index_list(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, char** data);

    /*!
    *@name data_short_combine
    *@brief 加入短整型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_short_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, short data);

    /*!
    *@name data_short_modify
    *@brief 修改短整型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_short_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, short data);

    /*!
    *@name data_short_extract
    *@brief 获取短整型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_short_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, short* data);

    /*!
    *@name data_int_combine
    *@brief 加入整型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_int_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, int data);

    /*!
    *@name data_int_modify
    *@brief 修改整型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_int_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int data);

    /*!
    *@name data_int_extract
    *@brief 获取整型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_int_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int* data);

    /*!
    *@name data_float_combine
    *@brief 加入浮点型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_float_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, float data);

    /*!
    *@name data_float_modify
    *@brief 修改浮点型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_float_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, float data);

    /*!
    *@name data_float_extract
    *@brief 获取浮点型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_float_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, float* data);

    /*!
    *@name data_double_combine
    *@brief 加入双浮点型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_double_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, double data);

    /*!
    *@name data_double_modify
    *@brief 修改双浮点型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_double_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double data);

    /*!
    *@name data_double_extract
    *@brief 获取双浮点型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_double_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double* data);

    /*!
    *@name data_currency_combine
    *@brief 加入货币型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_currency_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, double data);

    /*!
    *@name data_currency_modify
    *@brief 修改货币型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_currency_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double data);

    /*!
    *@name data_currency_extract
    *@brief 获取货币型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_currency_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double* data);

    /*!
    *@name data_date_combine
    *@brief 加入日期型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_date_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, double data);

    /*!
    *@name data_date_modify
    *@brief 修改日期型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_date_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double data);

    /*!
    *@name data_date_extract
    *@brief 获取日期型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_date_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double* data);

    /*!
    *@name data_string_combine
    *@brief 加入字符串型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_string_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_string_modify
    *@brief 修改字符串型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_string_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_string_extract
    *@brief 获取字符串型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_string_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_file_combine
    *@brief 加入文件型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] file_name 文件名
    *@param[in] compress 是否压缩
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_file_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* file_name, bool const compress);

    /*!
    *@name data_file_modify
    *@brief 修改文件型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] file_name 文件名
    *@param[in] compress 是否压缩
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_file_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* file_name, bool const compress);

    /*!
    *@name data_file_extract
    *@brief 获取文件型数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] file_name 文件名
    *@param[in] over_write 是否覆盖
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_file_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* file_name, bool over_write);

    /*!
    *@name data_shorts_combine
    *@brief 加入短整型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[111,222,333,444,555,666]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_shorts_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_shorts_modify
    *@brief 修改短整型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[111,222,333,444,555,666]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_shorts_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_shorts_extract
    *@brief 获取短整型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[111,222,333,444,555,666]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_shorts_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_ints_combine
    *@brief 加入整型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[111,222,333,444,555,666]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_ints_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_ints_modify
    *@brief 修改整型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[111,222,333,444,555,666]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_ints_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_ints_extract
    *@brief 获取整型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[111,222,333,444,555,666]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_ints_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_floats_combine
    *@brief 加入浮点型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_floats_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_floats_modify
    *@brief 修改浮点型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_floats_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_floats_extract
    *@brief 获取浮点型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_floats_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_doubles_combine
    *@brief 加入双浮点型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_doubles_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_doubles_modify
    *@brief 修改双浮点型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_doubles_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_doubles_extract
    *@brief 获取双浮点型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_doubles_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_currencys_combine
    *@brief 加入货币型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_currencys_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_currencys_modify
    *@brief 修改货币型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_currencys_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_currencys_extract
    *@brief 获取货币型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_currencys_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_dates_combine
    *@brief 加入日期型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_dates_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_dates_modify
    *@brief 修改日期型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_dates_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_dates_extract
    *@brief 获取日期型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[1234.56,2345.67,3456.78,44.4,55.5,66.6]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_dates_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_strings_combine
    *@brief 加入字符串型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] remark 数据备注
    *@param[in] data 数据内容 json: "{\"data\":[\"abc1\",\"英文1\",\"英文abc1\",\"444\",\"555\",\"666\"]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_strings_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

    /*!
    *@name data_strings_modify
    *@brief 修改字符串型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"data\":[\"abc1\",\"英文1\",\"英文abc1\",\"444\",\"555\",\"666\"]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_strings_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

    /*!
    *@name data_strings_extract
    *@brief 获取字符串型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[out] data 数据内容 json: "{\"data\":[\"abc1\",\"英文1\",\"英文abc1\",\"444\",\"555\",\"666\"]}"
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_strings_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

    /*!
    *@name data_files_combine
    *@brief 加入文件型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"file\":[\"filename1\",\"filename2\",\"filename3\"],\"path\":[\"tianzuo.Qiankun.dll\",\"tianzuo.Qiankun.dll\",\"tianzuo.Qiankun.dll\"]}"
    *@param[in] compress 是否压缩
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_files_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data, bool const compress);

    /*!
    *@name data_files_modify
    *@brief 修改文件型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"file\":[\"filename1\",\"filename2\",\"filename3\"],\"path\":[\"tianzuo.Qiankun.dll\",\"tianzuo.Qiankun.dll\",\"tianzuo.Qiankun.dll\"]}"
    *@param[in] compress 是否压缩
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_files_modify(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data, bool const compress);

    /*!
    *@name data_files_extract
    *@brief 获取文件型数组数据
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@param[in] data_name 数据名称
    *@param[in] data 数据内容 json: "{\"file\":[\"filename1\",\"filename2\",\"filename3\"],\"path\":[\"tianzuo.Qiankun.dll\",\"tianzuo.Qiankun.dll\",\"tianzuo.Qiankun.dll\"]}"
    *@param[in] over_write 是否覆盖
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	int tianzuo_QiankunInt_data_files_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data, bool over_write);

#ifdef __cplusplus
}
#endif
