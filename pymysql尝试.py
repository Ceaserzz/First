import pymysql


def create_db():    #创建数据库
    conn = pymysql.connect(host='localhost', user='root', passwd='010309', port=3306, charset='utf8mb4')
    cursor = conn.cursor()
    sql = 'CREATE DATABASE FIST DEFAULT CHARACTER SET utf8mb4'
    cursor.execute(sql)
    conn.close()


create_db()


def create_table2():  # 创建数据表
    conn = pymysql.connect(host='localhost', user='root', passwd='010309', db='fist', port=3306, charset='utf8mb4')
    cursor = conn.cursor()
    sql = 'CREATE TABLE stu(num int, name VARCHAR(255),birthday VARCHAR(16),PRIMARY KEY (num))'
    cursor.execute(sql)
    conn.close()


create_table2()


def create_table():  # 创建数据表
    conn = pymysql.connect(host='localhost', user='root', passwd='010309', db='fist', port=3306, charset='utf8mb4')
    cursor = conn.cursor()
    sql = ("CREATE TABLE income (\n"
           "      id int(11) NOT NULL AUTO_INCREMENT,\n"
           "      datetime varchar(20) DEFAULT NULL,\n"
           "      ironincome decimal(20,2) DEFAULT NULL,\n"
           "      generalincome decimal(20,2) DEFAULT NULL,\n"
           "      baiincome decimal(20,2) DEFAULT NULL,\n"
           "      PRIMARY KEY (id)\n"
           "    )")
    cursor.execute(sql)
    conn.close()


create_table()

#插入数据
conn = pymysql.connect(host='localhost', user='root', passwd='010309', db='fist', port=3306, charset='utf8mb4')
cursor = conn.cursor()
sql = """INSERT INTO income (id,datetime,ironincome,generalincome,baiincome)
         VALUES (1,"02.03","测试","测试","测试")"""
cursor.execute(sql)
cursor.close()
conn.commit()
conn.close()

#遍历数据
conn = pymysql.connect(host='localhost', user='root', passwd='010309', db='fist', port=3306, charset='utf8mb4')
cursor = conn.cursor()
sql = "select * from student"
cursor.execute(sql)  # 执行sql语句
conn.close()  # 关闭连接


#修改数据
sql_update = "update student set name = '%s' where num = %s"
cursor.execute(sql_update % ("xiongda", 1))
conn.commit()
conn.close()


sql_delete = "delete from student where num= %d"
cursor.execute(sql_delete % (1))
conn.commit()
conn.close()
