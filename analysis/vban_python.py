import socket
import time
import numpy as np
#from matplotlib import plot as plt

if __name__ == "__main__":
    UDP_IP = "127.0.0.1"
    UDP_PORT = 6969
    sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    sock.bind((UDP_IP, UDP_PORT))
    print("Starting Script")
    for run in range(100):
        print(f"itteration {run}")
        data, addr = sock.recvfrom(540)
        if addr == "192.168.1.111":
            print(f"Recieved message: {data[0:4]}")
        else: 
            time.sleep(1)
