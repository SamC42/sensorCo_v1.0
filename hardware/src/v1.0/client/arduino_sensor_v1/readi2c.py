import smbus
import time
import Adafruit_ADS1x15
import socket

client = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
client.connect('/tmp/mysocket')

adc = Adafruit_ADS1x15.ADS1015()

#bus = smbus.SMBus(1)
#addr = 0x48

def readSingleReg():
    val = adc.read_adc(0,gain=1)
    time.sleep(0.5)
    return val


def buildPacket():
    packet = "eid" + str(readSingleReg()) + "ins" +"dat" + "ins" + "dat" #sending 12 e's for testing
    return packet

def sendPac2Soc():
    client.send(buildPacket())


#print hex(readSingleReg()) # Gives 3 bytes
sendPac2Soc()
client.close()
    

