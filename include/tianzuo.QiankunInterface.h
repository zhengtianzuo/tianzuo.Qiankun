
// *@file tianzuo_QiankunInterface.h
// *@brief 天佐.乾坤袋 (tianzuo.Qiankun)
// *@version 1.0
// *@section LICENSE Copyright © 2003-2103 郑天佐 Corporation
// *@author 郑天佐 (zhengtianzuo)
// *@date 2013-4-3
#pragma once

//!@brief 导出函数定义(define dllexport)
#undef tianzuo_Qiankun_lib
#if defined (WIN32)
#define tianzuo_Qiankun_atr
#if defined (tianzuo_Qiankun_dllexport)
#define tianzuo_Qiankun_lib _declspec(dllexport)
#else
#define tianzuo_Qiankun_lib _declspec(dllimport)
#endif
#else
#define tianzuo_Qiankun_atr __attribute__((visibility("default")))
#define tianzuo_Qiankun_lib
#endif
#include "tianzuo.Qiankun.h"

//!@brief 数据库验证
//!@struct Qiankun_db_verify
typedef struct Qiankun_db_verify {
    const char *m_db_file_name;
    const char *m_db_password;
    Qiankun_db_verify(const char *db_file_name, const char *db_password) {
        m_db_file_name = db_file_name;
        m_db_password = db_password;
    }
} Qiankun_db_verify_struct, *Qiankun_db_verify_pointer;

//!@brief 数据类型
//!@struct Qiankun_data_type_tag
typedef struct Qiankun_data_type_tag {
    Qiankun_data_type_tag(int data_type, int data_index, const char *data_name) {
        m_data_type = data_type;
        m_data_index = data_index;
        m_data_name = data_name;
    }

    int get_data_type() {
        return (m_data_type);
    }

    int get_data_index() {
        return (m_data_index);
    }

    const char *get_data_name() {
        return (m_data_name);
    }

 private:
    int m_data_type;
    int m_data_index;
    const char *m_data_name;
} Qiankun_data_type_struct, *Qiankun_data_type_pointer;

//!@brief 用户数据
//!@struct Qiankun_user_data_tag
typedef struct Qiankun_user_data_tag {
    void *m_user_data;
    int m_user_size;
    Qiankun_user_data_tag(void *user_data, int user_size) {
        m_user_data = user_data;
        m_user_size = user_size;
    }
} Qiankun_user_data_struct, *Qiankun_user_data_pointer;

//!@brief 返回用户数据
//!@struct Qiankun_get_user_data_tag
typedef struct Qiankun_get_user_data_tag {
    void **m_user_data;
    int *m_user_size;
    Qiankun_get_user_data_tag(void *&userData, int *nUserSize) {
        m_user_data = &userData;
        m_user_size = nUserSize;
    }
} Qiankun_get_user_data_struct, *Qiankun_get_user_data_pointer;

//!@brief 回调函数
//!@struct Qiankun_function_tag
typedef struct Qiankun_function_tag {
    void *m_function;
    void *m_context;
    Qiankun_function_tag(void *function, void *context) {
        m_function = function;
        m_context = context;
    }
} Qiankun_function_struct, *Qiankun_function_pointer;

//!@brief 乾坤袋模块类 for c++
//!@class tianzuo_QiankunInt for c++
class tianzuo_Qiankun_lib tianzuo_QiankunInt {
 public:
    tianzuo_QiankunInt() {}
    virtual ~tianzuo_QiankunInt() {}

    /*!
    *@name initialize
    *@brief 组件初始化
    *@param[in] 无
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int initialize() = 0;

    /*!
    *@name terminate
    *@brief 组件销毁
    *@param[in] 无
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int terminate() = 0;

    /*!
    *@name db_create_database
    *@brief 创建数据库
    *@param[in] db_verify 验证信息
    *@param[in] db_name 数据库名称
    *@param[in] over_write 是否重写
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_create_database(Qiankun_db_verify_pointer db_verify, const char *db_name, bool const over_write) = 0;

    /*!
    *@name db_open_database
    *@brief 打开数据库
    *@param[in] db_verify 验证信息
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_open_database(Qiankun_db_verify_pointer db_verify) = 0;

    /*!
    *@name db_close_database
    *@brief 关闭数据库
    *@param[in] db_verify 验证信息
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_close_database(Qiankun_db_verify_pointer db_verify) = 0;

    /*!
    *@name db_change_password
    *@brief 修改密码
    *@param[in] db_verify 验证信息
    *@param[in] new_password 新的数据库密码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_change_password(Qiankun_db_verify_pointer db_verify, const char *new_password) = 0;

    /*!
    *@name db_get_name
    *@brief 获取数据库名称
    *@param[in] db_verify 验证信息
    *@param[out] db_name 数据库名称
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_get_name(Qiankun_db_verify_pointer db_verify, char*& db_name) = 0;

    /*!
    *@name db_get_total_number
    *@brief 获取数据库数据总数
    *@param[in] db_verify 验证信息
    *@param[out] file_number 数据库数据总数
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_get_total_number(Qiankun_db_verify_pointer db_verify, int *file_number) = 0;

    /*!
    *@name db_rebuild
    *@brief 重建数据库
    *@param[in] db_verify 验证信息
    *@param[in] new_db_file_name 新的数据库文件路径
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_rebuild(Qiankun_db_verify_pointer db_verify, const char *new_db_file_name) = 0;

    /*!
    *@name db_set_name
    *@brief 设置数据库名称
    *@param[in] db_verify 验证信息
    *@param[in] db_name 数据库名称
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_set_name(Qiankun_db_verify_pointer db_verify, const char *db_name) = 0;

    /*!
    *@name db_set_total_number
    *@brief 设置数据库总数
    *@param[in] db_verify 验证信息
    *@param[in] add_file_number 数据库总数
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int db_set_total_number(Qiankun_db_verify_pointer db_verify, int const add_file_number) = 0;

    /*!
    *@name data_check
    *@brief 检测数据有效性
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_check(Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type) = 0;

    /*!
    *@name data_combine
    *@brief 加入数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] remark 数据备注
    *@param[in] user_data 数据内容
    *@param[in] compress 是否压缩
    *@param[in] data_index 数据序号
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_combine(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        const char *remark, Qiankun_user_data_pointer user_data,
        bool const compress, int const data_index) = 0;

    /*!
    *@name data_combine_list
    *@brief 加入数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] name_list 数据名称列表
    *@param[in] data_list 数据内容列表
    *@param[in] compress 是否压缩
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_combine_list(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_user_data_pointer name_list, Qiankun_user_data_pointer data_list, bool const compress) = 0;

    /*!
    *@name data_modify
    *@brief 修改数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] user_data 数据内容
    *@param[in] compress 是否压缩
    *@param[in] update_index 是否更新序号
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_modify(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_user_data_pointer user_data, bool const compress, bool const update_index = true) = 0;

    /*!
    *@name data_modify_list
    *@brief 修改数据列表
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] name_list 数据名称列表
    *@param[in] data_list 数据内容列表
    *@param[in] compress 是否压缩
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_modify_list(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_user_data_pointer name_list, Qiankun_user_data_pointer data_list, bool const compress) = 0;

    /*!
    *@name data_modify_file
    *@brief 修改文件
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] remark 数据备注
    *@param[in] file_name 文件路径
    *@param[in] compress 是否压缩
    *@param[in] update_index 是否更新序号
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_modify_file(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        const char *remark, char *file_name, bool const compress, bool const update_index = true) = 0;

    /*!
    *@name data_extract
    *@brief 获取数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] function 获取数据函数指针
    *@param[out] get_user_data 返回数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_extract(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_function_pointer function, Qiankun_get_user_data_pointer get_user_data) = 0;

    /*!
    *@name data_extract_list
    *@brief 获取数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] name_list 数据名称列表
    *@param[out] data_list 数据内容列表
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_extract_list(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_user_data_pointer name_list, Qiankun_user_data_pointer data_list) = 0;

    /*!
    *@name data_extract_bytes
    *@brief 获取数据流
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] function 获取数据函数指针
    *@param[out] get_user_data 返回数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_extract_bytes(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_function_pointer function, Qiankun_get_user_data_pointer get_user_data) = 0;

    /*!
    *@name data_extract_file
    *@brief 获取文件
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] file_name 文件路径
    *@param[in] over_write 是否重写
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_extract_file(Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type, char *file_name, bool const over_write) = 0;

    /*!
    *@name data_extract_file
    *@brief 获取文件
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] name_list 数据名称列表
    *@param[in] data_list 数据内容列表
    *@param[in] over_write 是否重写
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_extract_file_list(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        Qiankun_user_data_pointer name_list, Qiankun_user_data_pointer data_list, bool const over_write) = 0;

    /*!
    *@name data_delete
    *@brief 删除数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] update_index 是否更新序号
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_delete(Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type, bool update_index = true) = 0;

    /*!
    *@name data_delete
    *@brief 删除数据
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] name_list 数据名称列表
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_delete_list(Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type, Qiankun_user_data_pointer name_list) = 0;

    /*!
    *@name data_get_index
    *@brief 获取序号
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[out] data_index_code 数据序号代码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_index(Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type, int *data_index_code) = 0;

    /*!
    *@name data_get_index_list
    *@brief 获取序号列表
    *@param[in] db_verify 验证信息
    *@param[in] function 获取数据函数指针
    *@param[out] user_data 数据内容指针
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_index_list(Qiankun_db_verify_pointer db_verify, Qiankun_function_pointer function, Qiankun_user_data_pointer user_data) = 0;

    /*!
    *@name data_set_index
    *@brief 设置序号
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] new_data_index 新的数据序号
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_set_index(Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type, int const new_data_index) = 0;

    /*!
    *@name data_get_name
    *@brief 获取数据名称
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] name_type 名称类型
    *@param[out] data_name 数据名称
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_name(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        int const name_type, char*& data_name) = 0;

    /*!
    *@name data_rename
    *@brief 修改数据名称
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[in] new_data_name 新的数据名称
    *@param[in] new_remark 新的数据备注
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_rename(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        const char *new_data_name, const char *new_remark) = 0;

    /*!
    *@name data_get_name_list
    *@brief 获取数据名称列表
    *@param[in] db_verify 验证信息
    *@param[in] name_type 名称类型
    *@param[in] function 获取数据函数指针
    *@param[out] user_data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_name_list(
        Qiankun_db_verify_pointer db_verify, int const name_type,
        Qiankun_function_pointer function, Qiankun_user_data_pointer user_data) = 0;

    /*!
    *@name data_get_type
    *@brief 获取数据类型
    *@param[in] db_verify 验证信息
    *@param[in] data_type 数据类型
    *@param[out] data_type_code 数据类型
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_type(
        Qiankun_db_verify_pointer db_verify, Qiankun_data_type_pointer data_type,
        int *data_type_code) = 0;

    /*!
    *@name data_get_type_list
    *@brief 获取数据类型列表
    *@param[in] db_verify 验证信息
    *@param[in] function 获取数据函数指针
    *@param[out] user_data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_type_list(
        Qiankun_db_verify_pointer db_verify, Qiankun_function_pointer function,
        Qiankun_user_data_pointer user_data) = 0;

    /*!
    *@name data_get_type_total_number
    *@brief 获取数据类型总数
    *@param[in] db_verify 验证信息
    *@param[in] data_type_code 数据类型
    *@param[out] data_type_total_number 数据类型总数
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_type_total_number(
        Qiankun_db_verify_pointer db_verify, int const data_type_code,
        int *data_type_total_number) = 0;

    /*!
    *@name data_get_type_total_number_list
    *@brief 获取数据类型总数列表
    *@param[in] db_verify 验证信息
    *@param[in] function 获取数据函数指针
    *@param[out] user_data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_type_total_number_list(
        Qiankun_db_verify_pointer db_verify, Qiankun_function_pointer function,
        Qiankun_user_data_pointer user_data) = 0;

    /*!
    *@name data_get_size
    *@brief 获取数据大小
    *@param[in] db_verify 验证信息
    *@param[in] size_type 数据大小类型
	*@param[in] data_type 数据类型
    *@param[out] data_size 数据大小
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_size(
        Qiankun_db_verify_pointer db_verify, int const size_type,
        Qiankun_data_type_pointer data_type, int *data_size) = 0;

    /*!
    *@name data_get_size_list
    *@brief 获取数据大小列表
    *@param[in] db_verify 验证信息
    *@param[in] size_type 数据大小类型
    *@param[in] function 获取数据函数指针
    *@param[out] user_data 数据内容
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int data_get_size_list(
        Qiankun_db_verify_pointer db_verify, int const size_type,
        Qiankun_function_pointer function, Qiankun_user_data_pointer user_data) = 0;
};

//!@brief 乾坤袋接口 for c++
//!@class tianzuo_QiankunInterface for c++
class tianzuo_Qiankun_lib tianzuo_QiankunInterface {
 public:
    tianzuo_QiankunInterface();
    virtual ~tianzuo_QiankunInterface();

    /*!
    *@name initialize
    *@brief 接口初始化
    *@param[in] 无
    *@return 模块类指针
    *@author 郑天佐
    *@date 2013-4-3
    */
    static tianzuo_QiankunInt *initialize();

    /*!
    *@name terminate
    *@brief 接口销毁
    *@param[in] QiankunInt_pointer 模块类指针
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
    static void terminate(tianzuo_QiankunInt **QiankunInt_pointer);
};

//!@brief 乾坤袋数据模块类 for c++
//!@class tianzuo_QiankunDataInt for c++
class tianzuo_Qiankun_lib tianzuo_QiankunDataInt {
 public:
    tianzuo_QiankunDataInt() {}
    virtual ~tianzuo_QiankunDataInt() {}

    /*!
    *@name initialize
    *@brief 接口初始化
    *@param[in] 无
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int initialize() = 0;

    /*!
    *@name terminate
    *@brief 接口销毁
    *@param[in] 无
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
    virtual int terminate() = 0;
};

//!@brief 乾坤袋数据接口 for c++
//!@class tianzuo_QiankunDataInterface for c++
class tianzuo_Qiankun_lib tianzuo_QiankunDataInterface {
 public:
    tianzuo_QiankunDataInterface();
    virtual ~tianzuo_QiankunDataInterface();

    /*!
    *@name initialize
    *@brief 接口初始化
    *@param[in] 无
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
    static tianzuo_QiankunDataInt *initialize();

    /*!
    *@name terminate
    *@brief 接口销毁
    *@param[in] QiankunDataInt_pointer 模块类指针
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
    static void terminate(tianzuo_QiankunDataInt **QiankunDataInt_pointer);
};

//!@brief 乾坤袋接口 for python java csharp javascript php visualbasic go rust ruby
//!@class tianzuo_QiankunInterface for python java csharp javascript php visualbasic go rust ruby
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
	tianzuo_Qiankun_lib tianzuo_QiankunInt * tianzuo_QiankunInterface_initialize();

    /*!
    *@name terminate
    *@brief 接口销毁
    *@param[in] QiankunInt_pointer 模块类指针
    *@return 无
    *@author 郑天佐
    *@date 2013-4-3
    */
	tianzuo_Qiankun_lib void tianzuo_QiankunInterface_terminate(tianzuo_QiankunInt * *QiankunInt_pointer);

    /*!
    *@name initialize
    *@brief 组件初始化
    *@param[in] QiankunInt_pointer 模块类指针
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_initialize(tianzuo_QiankunInt * QiankunInt_pointer);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_create_database(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* db_name, bool const over_write);

    /*!
    *@name db_open_database
    *@brief 打开数据库
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_open_database(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password);

    /*!
    *@name db_close_database
    *@brief 关闭数据库
    *@param[in] db_file_name 数据库文件
    *@param[in] db_password 数据库密码
    *@return int
    *@author 郑天佐
    *@date 2013-4-3
    */
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_close_database(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_change_password(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* new_password);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_get_name(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, char*& db_name);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_get_total_number(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, int* file_number);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_rebuild(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* new_db_file_name);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_set_name(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* db_name);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_db_set_total_number(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, int const add_file_number);

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
    tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_check(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int data_type);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_delete(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_deletes(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_get_size(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, int size_type, const char* data_name, int data_type, int* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_get_size_list(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, int size_type, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_get_name_list(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, int name_type, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_get_type_list(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_get_type_total_number_list(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_get_index_list(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_short_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, short data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_short_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, short data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_short_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, short* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_int_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, int data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_int_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_int_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_float_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, float data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_float_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, float data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_float_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, float* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_double_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, double data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_double_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_double_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_currency_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, double data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_currency_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_currency_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_date_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, double data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_date_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_date_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, double* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_string_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_string_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_string_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_file_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* file_name, bool const compress);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_file_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* file_name, bool const compress);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_file_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* file_name, bool over_write);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_shorts_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_shorts_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_shorts_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_ints_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_ints_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_ints_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_floats_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_floats_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_floats_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_doubles_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_doubles_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_doubles_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_currencys_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_currencys_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_currencys_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_dates_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_dates_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_dates_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_strings_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_strings_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_strings_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char** data);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_files_combine(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data, bool const compress);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_files_modify(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data, bool const compress);

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
	tianzuo_Qiankun_lib int tianzuo_QiankunInt_data_files_extract(tianzuo_QiankunInt * QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, char* data, bool over_write);

#ifdef __cplusplus
}
#endif
