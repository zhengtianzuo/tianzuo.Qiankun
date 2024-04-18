package main

/*
#include "tianzuo.QiankunInterface.h"
*/
import "C"
import (
	"fmt"
	"syscall"
	"unsafe"
)

const (
	Qiankun_errorcode_success       = 1  //  正确的值
	Qiankun_errorcode_normal        = 2  //  错误的值
	Qiankun_errorcode_differ        = 3  //  数据库文件数效验未通过 (The number Of database files fails To be verified)
	Qiankun_errorcode_no_rights     = 4  //  数据库密码效验未通过 (The database password verification failed)
	Qiankun_errorcode_db_not_exist  = 5  //  数据库文件不存在 (The database file does Not exist)
	Qiankun_errorcode_exist         = 6  //  数据已存在 (Data already exists)
	Qiankun_errorcode_not_exist     = 7  //  数据不存在 (Data does Not exist)
	Qiankun_errorcode_out_of_range  = 8  //  超出范围 (out Of range)
	Qiankun_errorcode_type          = 9  //  类型不符 (wrong type)
	Qiankun_errorcode_param         = 10 //  参数错误 (parameter Error)
	Qiankun_errorcode_compress      = 11 //  压缩错误 (compression Error)
	Qiankun_errorcode_get_array     = 12 //  数组错误 (arrary Error)
	Qiankun_errorcode_out_of_memory = 13 //  内存溢出 (memory overflow)
	Qiankun_errorcode_handle        = 14 //  句柄错误 (Error handle)
	Qiankun_errorcode_io            = 15 //  IO错误 (io Error)
)

func main() {
	// 初始化接口 initialize the interface
	dll := syscall.MustLoadDLL("tianzuo.Qiankun.dll")

	// 创建实例 create an instance
	tianzuo_QiankunInterface_initialize := dll.MustFindProc("tianzuo_QiankunInterface_initialize")
	qiankun, _, _ := tianzuo_QiankunInterface_initialize.Call()

	tianzuo_QiankunInt_initialize := dll.MustFindProc("tianzuo_QiankunInt_initialize")
	error_code, _, _ := tianzuo_QiankunInt_initialize.Call(qiankun)
	if error_code != Qiankun_errorcode_success {
		fmt.Println("tianzuo_QiankunInt_initialize error: ", error_code)
	}

	// 创建数据库 create database
	db_file_name := C.CString("qiankunDataBase.Ztz")
	db_password := C.CString("password")
	tianzuo_QiankunInt_db_create_database := dll.MustFindProc("tianzuo_QiankunInt_db_create_database")
	error_code, _, _ = tianzuo_QiankunInt_db_create_database.Call(qiankun, uintptr(unsafe.Pointer(db_file_name)), uintptr(unsafe.Pointer(db_password)), uintptr(unsafe.Pointer(C.CString("qiankunDataBase"))), 1)
	if error_code != Qiankun_errorcode_success {
		fmt.Println("tianzuo_QiankunInt_db_create_database error: ", error_code)
	}

	// 打开数据库 open database
	tianzuo_QiankunInt_db_open_database := dll.MustFindProc("tianzuo_QiankunInt_db_open_database")
	error_code, _, _ = tianzuo_QiankunInt_db_open_database.Call(qiankun, uintptr(unsafe.Pointer(db_file_name)), uintptr(unsafe.Pointer(db_password)))
	if error_code != Qiankun_errorcode_success {
		fmt.Println("tianzuo_QiankunInt_db_open_database error: ", error_code)
	}

	// 向数据库写入一个整型数据 writes an integer to the database
	intInt := C.int(12345678)
	tianzuo_QiankunInt_data_int_combine := dll.MustFindProc("tianzuo_QiankunInt_data_int_combine")
	error_code, _, _ = tianzuo_QiankunInt_data_int_combine.Call(qiankun, uintptr(unsafe.Pointer(db_file_name)), uintptr(unsafe.Pointer(db_password)), uintptr(unsafe.Pointer(C.CString("integer"))), uintptr(unsafe.Pointer(C.CString(""))), uintptr(intInt))
	if error_code != Qiankun_errorcode_success {
		fmt.Println("tianzuo_QiankunInt_data_int_combine error: ", error_code)
	}

	// 读取刚写入的数据 read the data just written
	return_int := C.int(0)
	tianzuo_QiankunInt_data_int_extract := dll.MustFindProc("tianzuo_QiankunInt_data_int_extract")
	error_code, _, _ = tianzuo_QiankunInt_data_int_extract.Call(qiankun, uintptr(unsafe.Pointer(db_file_name)), uintptr(unsafe.Pointer(db_password)), uintptr(unsafe.Pointer(C.CString("integer"))), uintptr(unsafe.Pointer(&return_int)))
	if error_code != Qiankun_errorcode_success {
		fmt.Println("tianzuo_QiankunInt_data_int_extract error: ", error_code)
	}

	fmt.Println("get integer data: ", return_int)

	// 关闭数据库 close database
	tianzuo_QiankunInt_db_close_database := dll.MustFindProc("tianzuo_QiankunInt_db_close_database")
	error_code, _, _ = tianzuo_QiankunInt_db_close_database.Call(qiankun, uintptr(unsafe.Pointer(db_file_name)), uintptr(unsafe.Pointer(db_password)))
	if error_code != Qiankun_errorcode_success {
		fmt.Println("tianzuo_QiankunInt_db_close_database error: ", error_code)
	}

	fmt.Println("test done -------------------")
}
