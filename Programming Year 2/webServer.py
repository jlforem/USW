from socket import *
import sys
import time
import os
import threading

myHost = ""
myPort = 2000

s = socket(AF_INET, SOCK_DGRAM)
s.bind((myHost, myPort))

def handle_request(data, addr):
    print("UDP Server: ", data, "from", addr)
    if data:
        start_time = time.time()
        print("Processing request received")
        time.sleep(5)
        end_time = time.time()
        print("Request processed in", end_time - start_time, "seconds")
        s.sendto(("echo->" + data.decode('utf-8')).encode('utf-8'), addr)
        print("Response sent")

while True:
    data, addr = s.recvfrom(1024)
    threading.Thread(target=handle_request, args=(data, addr)).start()
