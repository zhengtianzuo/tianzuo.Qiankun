#include <iostream>
#include <memory>
#include "../../include/tianzuo.QiankunInterface.h" // 接口头文件 interface heaher file

int main() {
    // 准备数据 prepare data
    Qiankun_db_verify_struct db_verify("qiankunDataBase.Ztz", "password");
    int integer = 12345678;
    Qiankun_data_type_struct data_type(Qiankun_data_type_integer, -1, "integer");
    Qiankun_user_data_struct user_data(&integer, 0);
    int data_size = 0;
    Qiankun_get_user_data_struct get_user_data(reinterpret_cast<void*&>(integer), &data_size);

    // 初始化接口 initialize the interface
    std::unique_ptr<tianzuo_QiankunInterface> qiankun_interface(new tianzuo_QiankunInterface());

    // 创建实例 create an instance
    tianzuo_QiankunInt* qiankun = qiankun_interface->initialize();

    // 初始化实例 initialize the instance
    int error_code = qiankun->initialize();
    if (error_code != Qiankun_errorcode_success) {
        std::cout << "initialize error: " << error_code;
        goto return_error;
        return -1;
    }
    
    // 创建数据库 create database
    error_code = qiankun->db_create_database(&db_verify, "qiankunDataBase", true);
    if (error_code != Qiankun_errorcode_success) {
        std::cout << "db_create_database error: " << error_code;
        goto return_error;
        return -1;
    }

    // 打开数据库 open database
    error_code = qiankun->db_open_database(&db_verify);
    if (error_code != Qiankun_errorcode_success) {
        std::cout << "db_open_database error: " << error_code;
        goto return_error;
        return -1;
    }

    // 向数据库写入一个整型数据 writes an integer to the database
    error_code = qiankun->data_combine(&db_verify, &data_type, nullptr, &user_data, false, -1);
    if (error_code != Qiankun_errorcode_success) {
        std::cout << "data_combine error: " << error_code;
        goto return_error;
        return -1;
    }


    // 读取刚写入的数据 read the data just written
    integer = -1;
    error_code = qiankun->data_extract(&db_verify, &data_type, nullptr, &get_user_data);
    if (error_code != Qiankun_errorcode_success) {
        std::cout << "data_extract error: " << error_code;
        goto return_error;
        return -1;
    }

    std::cout << "get integer data: " << integer;

    // 关闭数据库 close database
    error_code = qiankun->db_close_database(&db_verify);
    if (error_code != Qiankun_errorcode_success) {
        std::cout << "db_close_database error: " << error_code;
        goto return_error;
        return -1;
    }

return_error:

    // 释放接口 terminate the interface
    if (qiankun_interface != nullptr && qiankun != nullptr) {
        qiankun_interface->terminate(&qiankun);
    }

    return 0;
}
