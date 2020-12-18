import mysql

username = input("Please enter your user name: ")
user_password = input("Please enter your password: ")

mydb = mysql.connector.connect(
  host="localhost",
  user=username,
  password=user_password
)

mycursor = mydb.cursor() #Look into difference of if it is declared once or multiple times

#Checks existing databases
mycursor.execute("SHOW DATABASES")

#Creates Database
if 'tcom_database' in mycursor
    mydb = mysql.connector.connect(
      host="localhost",
      user=username,
      password=user_password,
      database="tcom_database"
    )
    mycursor = mydb.cursor()
else
    mycursor.execute("CREATE DATABASE tcom_database")
    mycursor = mydb.cursor()
    mycursor.execute("CREATE TABLE events (eventId INT, eventType VARCHAR(255))")
    mycursor.execute("CREATE TABLE messages (messageId INT, messageType VARCHAR(255))")
    mycursor.execute("CREATE TABLE rho (eventId INT, messageId INT, rho INT)")
