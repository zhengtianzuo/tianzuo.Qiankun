
// *@file tianzuo.Qiankun.h
// *@brief 天佐.乾坤袋 (tianzuo.Qiankun)
// *@version 1.0
// *@section LICENSE Copyright © 2003-2103 郑天佐 Corporation
// *@author 郑天佐 (zhengtianzuo)
// *@date 2013-4-3
#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

const unsigned int Qiankun_file_name_size = 48;         ///<  文件名长度 (Filename length)

//!@enum 数据操作
enum Qiankun_data_operation {
    Qiankun_get_index_list             = 0x00000101,    ///<  获取数据序号列表 (Gets a list of data ordinals)
    Qiankun_get_type_list              = 0x00000102,    ///<  获取数据类型列表 (Gets a list of data types)
    Qiankun_get_type_total_number_list = 0x00000103,    ///<  获取数据各类型总数列表 (Gets a list of total types of data)
    Qiankun_get_name_list              = 0x00000104,    ///<  获取数据名称列表 (Gets a list of data names)
    Qiankun_get_size_list              = 0x00000105,    ///<  获取数据大小列表 (Gets a list of data sizes)
};

//!@enum 数据类型
enum Qiankun_data_type {
    Qiankun_data_type_short            = 0x00000001,    ///<  短整型
    Qiankun_data_type_integer          = 0x00000002,    ///<  整型
    Qiankun_data_type_float            = 0x00000003,    ///<  单精度浮点型
    Qiankun_data_type_double           = 0x00000004,    ///<  双精度浮点型
    Qiankun_data_type_currency         = 0x00000005,    ///<  货币型
    Qiankun_data_type_date             = 0x00000006,    ///<  日期型
    Qiankun_data_type_string           = 0x00000007,    ///<  字符串型
    Qiankun_data_type_file             = 0x00000008,    ///<  文件型
    Qiankun_data_type_byte_array       = 0x0000000A,    ///<  字节数组
    Qiankun_data_type_short_array      = 0x0000000B,    ///<  短整型数组
    Qiankun_data_type_integer_array    = 0x0000000C,    ///<  整型数组
    Qiankun_data_type_float_array      = 0x0000000D,    ///<  单精度浮点型数组
    Qiankun_data_type_double_array     = 0x0000000E,    ///<  双精度浮点型数组
    Qiankun_data_type_currency_array   = 0x0000000F,    ///<  货币型数组
    Qiankun_data_type_date_array       = 0x00000010,    ///<  日期型数组
    Qiankun_data_type_string_array     = 0x00000011,    ///<  字符串型数组
};

//!@enum 返回数据名称类型
enum Qiankun_name_type {
    Qiankun_name_type_name             = 0x00000001,    ///<  数据名称 (data name)
    Qiankun_name_type_remark           = 0x00000002,    ///<  数据备注 (data remark)
};

//!@enum 返回数据大小类型
enum Qiankun_size_type {
    Qiankun_size_type_data_all_size     = 0x00000001,   ///<  总数据大小 (Total data size)
    Qiankun_size_type_data_delete_size  = 0x00000002,   ///<  删除的数据大小 (The size of the deleted data)
    Qiankun_size_type_data_size         = 0x00000003,   ///<  数据实际大小 (Actual data size)
};

//!@enum 错误码
enum Qiankun_error_code {
    Qiankun_errorcode_success           = 0x00000001,   ///<  正确的值
    Qiankun_errorcode_normal            = 0x00000002,   ///<  错误的值
    Qiankun_errorcode_differ            = 0x00000003,   ///<  数据库文件数效验未通过 (The number of database files fails to be verified)
    Qiankun_errorcode_no_rights         = 0x00000004,   ///<  数据库密码效验未通过 (The database password verification failed)
    Qiankun_errorcode_db_not_exist      = 0x00000005,   ///<  数据库文件不存在 (The database file does not exist)
    Qiankun_errorcode_exist             = 0x00000006,   ///<  数据已存在 (Data already exists)
    Qiankun_errorcode_not_exist         = 0x00000007,   ///<  数据不存在 (Data does not exist)
    Qiankun_errorcode_out_of_range      = 0x00000008,   ///<  超出范围 (out of range)
    Qiankun_errorcode_type              = 0x00000009,   ///<  类型不符 (wrong type)
    Qiankun_errorcode_param             = 0x0000000A,   ///<  参数错误 (parameter error)
    Qiankun_errorcode_compress          = 0x0000000B,   ///<  压缩错误 (compression error)
    Qiankun_errorcode_get_array         = 0x0000000C,   ///<  数组错误 (arrary error)
    Qiankun_errorcode_out_of_memory     = 0x0000000D,   ///<  内存溢出 (memory overflow)
    Qiankun_errorcode_handle            = 0x0000000E,   ///<  句柄错误 (error handle)
    Qiankun_errorcode_io                = 0x0000000F,   ///<  IO错误 (io error)
};

//!@brief 数据回调函数
//!@brief data_callback_function
typedef unsigned(*Qiankun_callback_data)(int m_function, void *context, void *user_data, int user_size, void *return_data, int return_size);
typedef unsigned(*Qiankun_callback_bytes)(int m_function, void *context, void *&user_data, int *user_size, void *return_data, int return_size);
typedef void(Qiankun_callback)(void *&, void *);

//!@brief 数据类型转换
//!@brief data_type_conversion
static void Qiankun_data2string(void *&user_data, void *return_data) {
    *reinterpret_cast<std::string*>(user_data) = *reinterpret_cast<std::string*>(return_data);
}

static void Qiankun_data2vshort(void *&user_data, void *return_data) {
    *reinterpret_cast<std::vector<int16_t>*>(user_data) = *reinterpret_cast<std::vector<int16_t>*>(return_data);
}

static void Qiankun_data2vint(void *&user_data, void *return_data) {
    *reinterpret_cast<std::vector<int>*>(user_data) = *reinterpret_cast<std::vector<int>*>(return_data);
}

static void Qiankun_data2vfloat(void *&user_data, void *return_data) {
    *reinterpret_cast<std::vector<float>*>(user_data) = *reinterpret_cast<std::vector<float>*>(return_data);
}

static void Qiankun_data2vdouble(void *&user_data, void *return_data) {
    *reinterpret_cast<std::vector<double>*>(user_data) = *reinterpret_cast<std::vector<double>*>(return_data);
}

static void Qiankun_data2vstring(void *&user_data, void *return_data) {
    *reinterpret_cast<std::vector<std::string>*>(user_data) = *reinterpret_cast<std::vector<std::string>*>(return_data);
}

//!@brief 数据回调命令
//!@struct Qiankun_command
typedef struct Qiankun_command {
    int m_function;
    Qiankun_callback *m_callback;
} Qiankun_command_struct, *Qiankun_command_pointer;

//!@brief 数据回调函数
//!@brief data_callback_function
static const Qiankun_command_struct Qiankun_command_info[] = {
    { Qiankun_data_type_string, &Qiankun_data2string },
    { Qiankun_data_type_short_array, &Qiankun_data2vshort },
    { Qiankun_data_type_integer_array, &Qiankun_data2vint },
    { Qiankun_get_index_list, &Qiankun_data2vint },
    { Qiankun_get_size_list, &Qiankun_data2vint },
    { Qiankun_get_type_list, &Qiankun_data2vint },
    { Qiankun_get_type_total_number_list, &Qiankun_data2vint },
    { Qiankun_data_type_float_array, &Qiankun_data2vfloat },
    { Qiankun_data_type_double_array, &Qiankun_data2vdouble },
    { Qiankun_data_type_currency_array, &Qiankun_data2vdouble },
    { Qiankun_data_type_date_array, &Qiankun_data2vdouble },
    { Qiankun_data_type_string_array, &Qiankun_data2vstring },
    { Qiankun_get_name_list, &Qiankun_data2vstring },
};

//!@brief 数据回调初始化
//!@brief data_callback_initialization
static std::map<int, Qiankun_command_struct> Qiankun_command_map;
static void Qiankun_command_init() {
    for (unsigned int i = 0; i < sizeof(Qiankun_command_info) / sizeof(Qiankun_command_struct); ++i) {
        (void)Qiankun_command_map.insert(std::make_pair(Qiankun_command_info[i].m_function, Qiankun_command_info[i]));
    }
}
