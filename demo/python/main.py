from ctypes import *
from enum import Enum
import ctypes

tianzuo_QiankunLib = cdll.LoadLibrary('./tianzuo.Qiankun.dll')

class Qiankun_error_code(Enum):
    Qiankun_errorcode_success           = 1 # 正确的值
    Qiankun_errorcode_normal            = 2 # 错误的值
    Qiankun_errorcode_differ            = 3 # 数据库文件数效验未通过 (The number of database files fails to be verified)
    Qiankun_errorcode_no_rights         = 4 # 数据库密码效验未通过 (The database password verification failed)
    Qiankun_errorcode_db_not_exist      = 5 # 数据库文件不存在 (The database file does not exist)
    Qiankun_errorcode_exist             = 6 # 数据已存在 (Data already exists)
    Qiankun_errorcode_not_exist         = 7 # 数据不存在 (Data does not exist)
    Qiankun_errorcode_out_of_range      = 8 # 超出范围 (out of range)
    Qiankun_errorcode_type              = 9 # 类型不符 (wrong type)
    Qiankun_errorcode_param             = 10 # 参数错误 (parameter error)
    Qiankun_errorcode_compress          = 11 # 压缩错误 (compression error)
    Qiankun_errorcode_get_array         = 12 # 数组错误 (arrary error)
    Qiankun_errorcode_out_of_memory     = 13 # 内存溢出 (memory overflow)
    Qiankun_errorcode_handle            = 14 # 句柄错误 (error handle)
    Qiankun_errorcode_io                = 15 # IO错误 (io error)

class tianzuo_QiankunInt:
    def __init__(self):
        tianzuo_QiankunLib.tianzuo_QiankunInterface_initialize.restype = c_void_p
        self.obj = tianzuo_QiankunLib.tianzuo_QiankunInterface_initialize()

    def __del__(self):
        tianzuo_QiankunLib.tianzuo_QiankunInterface_terminate.argtypes = [c_void_p]
        tianzuo_QiankunLib.tianzuo_QiankunInterface_terminate(self.obj)

    def initialize(self):
        tianzuo_QiankunLib.tianzuo_QiankunInterface_initialize.restype = c_int
        tianzuo_QiankunLib.tianzuo_QiankunInt_initialize.argtypes = [c_void_p]
        return tianzuo_QiankunLib.tianzuo_QiankunInt_initialize(self.obj)

    def db_create_database(self, db_file_name, db_password, db_name, over_write):
        tianzuo_QiankunLib.tianzuo_QiankunInt_db_create_database.argtypes = [c_void_p, c_char_p, c_char_p, c_char_p, c_int]
        return tianzuo_QiankunLib.tianzuo_QiankunInt_db_create_database(self.obj, db_file_name, db_password, db_name, over_write)

    def db_open_database(self, db_file_name, db_password):
        tianzuo_QiankunLib.tianzuo_QiankunInt_db_open_database.argtypes = [c_void_p, c_char_p, c_char_p]
        return tianzuo_QiankunLib.tianzuo_QiankunInt_db_open_database(self.obj, db_file_name, db_password)

    def db_close_database(self, db_file_name, db_password):
        tianzuo_QiankunLib.tianzuo_QiankunInt_db_close_database.argtypes = [c_void_p, c_char_p, c_char_p]
        return tianzuo_QiankunLib.tianzuo_QiankunInt_db_close_database(self.obj, db_file_name, db_password)

    def data_int_combine(self, db_file_name, db_password, data_name, remark, data):
        tianzuo_QiankunLib.tianzuo_QiankunInt_data_int_combine.argtypes = [c_void_p, c_char_p, c_char_p, c_char_p, c_char_p, c_int]
        return tianzuo_QiankunLib.tianzuo_QiankunInt_data_int_combine(self.obj, db_file_name, db_password, data_name, remark, data)

    def data_int_extract(self, db_file_name, db_password, data_name, data):
        tianzuo_QiankunLib.tianzuo_QiankunInt_data_int_extract.argtypes = [c_void_p, c_char_p, c_char_p, c_char_p, ctypes.POINTER(ctypes.c_int)]
        return tianzuo_QiankunLib.tianzuo_QiankunInt_data_int_extract(self.obj, db_file_name, db_password, data_name, data)

def main():

    # 初始化接口 initialize the interface
    print("initialize the interface")

    # 创建实例 create an instance
    qiankun = tianzuo_QiankunInt()
    error_code = qiankun.initialize()
    if error_code != Qiankun_error_code.Qiankun_errorcode_success.value:
        print("initialize error:", error_code)
        return

    # 创建数据库 create database
    db_file_name = b"qiankunDataBase.Ztz"
    db_password = b"password"
    error_code = qiankun.db_create_database(db_file_name, db_password, b"qiankunDataBase", True)
    if error_code != Qiankun_error_code.Qiankun_errorcode_success.value:
        print("db_create_database error:", error_code)
        return

    # 打开数据库 open database
    error_code = qiankun.db_open_database(db_file_name, db_password)
    if error_code != Qiankun_error_code.Qiankun_errorcode_success.value:
        print("db_open_database error:", error_code)
        return

    # 向数据库写入一个整型数据 writes an integer to the database
    intInt = 12345678
    error_code = qiankun.data_int_combine(db_file_name, db_password, b"integer", None, intInt)
    if error_code != Qiankun_error_code.Qiankun_errorcode_success.value:
        print("data_combine error:", error_code)
        return

    # 读取刚写入的数据 read the data just written
    return_data = ctypes.c_int()
    error_code = qiankun.data_int_extract(db_file_name, db_password, b"integer", ctypes.byref(return_data))
    if error_code != Qiankun_error_code.Qiankun_errorcode_success.value:
        print("data_extract error:", error_code)
        return

    integer = return_data.value
    print("get integer data: {}".format(integer))

    # 关闭数据库 close database
    error_code = qiankun.db_close_database(db_file_name, db_password)
    if error_code != Qiankun_error_code.Qiankun_errorcode_success.value:
        print("db_close_database error:", error_code)
        return

    print("test done -------------------")

if __name__ == '__main__':
    main()
