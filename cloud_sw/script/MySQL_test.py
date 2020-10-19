import mysql

#source https://www.w3schools.com/python/python_mysql_getstarted.asp

mydb = mysql.connector.connect(
  host="localhost",
  user="yourusername",
  password="yourpassword"
  #database="mydatabase"
)

mycursor = mydb.cursor() #Look into difference of if it is declared once or multiple times

#Checks existing databases
mycursor.execute("SHOW DATABASES")

#Creates Database
if 'mydatabase' in mycursor
    mydb = mysql.connector.connect(
      host="localhost",
      user="yourusername",
      password="yourpassword"
      database="mydatabase"
    )
    mycursor = mydb.cursor()
else
    mycursor.execute("CREATE DATABASE mydatabase")

#Creates table
mycursor = mydb.cursor()
mycursor.execute("CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))")

#Inserts into databse
mycursor = mydb.cursor()
sql = "INSERT INTO customers (name, address) VALUES (%s, %s)"
val = ("John", "Highway 21")
mycursor.execute(sql, val)

mydb.commit()

print(mycursor.rowcount, "record inserted.")

#Selects from database
mycursor = mydb.cursor()
mycursor.execute("SELECT * FROM customers")

myresult = mycursor.fetchall()

for x in myresult:
  print(x)

#Where
mycursor = mydb.cursor()
sql = "SELECT * FROM customers WHERE address ='Park Lane 38'"

mycursor.execute(sql)

myresult = mycursor.fetchall()

for x in myresult:
  print(x)
