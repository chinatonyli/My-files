#!/usr/bin/env python3
import mysql.connector
import gnupg
from functools import lru_cache
from getpass import getpass


gpg = gnupg.GPG(gnupghome="/home/biergaizi/.gnupg")

@lru_cache(maxsize=128)
def decrypt(string):
    de = gpg.decrypt(string)
    return de

password = getpass("Please enter the password: ")
conn = mysql.connector.connect(user="hosting", password=password,
                               host="biergaizi.com", database="hosting")
cursor = conn.cursor()
SQL = "SELECT domain,email,username,password FROM hosting"
cursor.execute(SQL)

for i in cursor:
    print("./create %s -d %s -p %s -q 1024000" % (i[2], i[0], decrypt(i[3])))
    print("./gen_mail %s %s %s" % (i[2], decrypt(i[3]), i[0]))
    print("Email: %s" % i[1])
    print("")

conn.close()
