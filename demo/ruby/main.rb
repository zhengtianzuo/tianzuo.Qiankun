require 'fiddle'

lib = Fiddle::dlopen('C:/Users/zhengtianzuo/RubymineProjects/tianzuo.QiankunTest/tianzuo.Qiankun.dll')
tianzuo_QiankunInterface_initialize = Fiddle::Function.new(lib['tianzuo_QiankunInterface_initialize'], [], Fiddle::TYPE_VOIDP)
tianzuo_QiankunInterface_terminate = Fiddle::Function.new(lib['tianzuo_QiankunInterface_terminate'], [Fiddle::TYPE_VOIDP], Fiddle::TYPE_VOID)
tianzuo_QiankunInt_initialize = Fiddle::Function.new(lib['tianzuo_QiankunInt_initialize'], [Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)
tianzuo_QiankunInt_db_create_database = Fiddle::Function.new(lib['tianzuo_QiankunInt_db_create_database'], [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_INT], Fiddle::TYPE_INT)
tianzuo_QiankunInt_db_open_database = Fiddle::Function.new(lib['tianzuo_QiankunInt_db_open_database'], [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)
tianzuo_QiankunInt_data_int_combine = Fiddle::Function.new(lib['tianzuo_QiankunInt_data_int_combine'], [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_INT], Fiddle::TYPE_INT)
tianzuo_QiankunInt_data_int_extract = Fiddle::Function.new(lib['tianzuo_QiankunInt_data_int_extract'], [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)
tianzuo_QiankunInt_db_close_database = Fiddle::Function.new(lib['tianzuo_QiankunInt_db_close_database'], [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)

# 初始化接口 initialize the interface
print("initialize the interface\n")

# 创建实例 create an instance
qiankun = tianzuo_QiankunInterface_initialize.call()
error_code = tianzuo_QiankunInt_initialize.call(qiankun)
if error_code != 1
  print("initialize error:", error_code, "\n")
  return
end

# 创建数据库 create database
db_file_name = "qiankunDataBase.Ztz"
db_password = "password"
error_code = tianzuo_QiankunInt_db_create_database.call(qiankun, db_file_name, db_password, "qiankunDataBase", 1)
if error_code != 1
  print("db_create_database error:", error_code, "\n")
  return
end

# 打开数据库 open database
error_code = tianzuo_QiankunInt_db_open_database.call(qiankun, db_file_name, db_password)
if error_code != 1
  print("db_open_database error:", error_code, "\n")
return
end

# 向数据库写入一个整型数据 writes an integer to the database
intInt = 12345678
error_code = tianzuo_QiankunInt_data_int_combine.call(qiankun, db_file_name, db_password, "integer", "", intInt)
if error_code != 1
  print("data_combine error:", error_code, "\n")
return
end

# 读取刚写入的数据 read the data just written
return_data = Fiddle::Pointer.malloc(Fiddle::SIZEOF_INT)
error_code = tianzuo_QiankunInt_data_int_extract.call(qiankun, db_file_name, db_password, "integer", return_data)
if error_code != 1
  print("data_extract error:", error_code, "\n")
return
end

integer = return_data[0, Fiddle::SIZEOF_INT].unpack('I')[0]
print("get integer data: ", integer, "\n")

# 关闭数据库 close database
error_code = tianzuo_QiankunInt_db_close_database.call(qiankun, db_file_name, db_password)
if error_code != 1
  print("db_close_database error:", error_code)
return
end

print("test done -------------------")
