import smbus
import time
import Adafruit_ADS1x15

adc = Adafruit_ADS1x15.ADS1015()

#bus = smbus.SMBus(1)
#addr = 0x48

def readSingleReg():
    val = adc.read_adc(0,gain=1)
    time.sleep(0.5)
    return val

while True:
    print readSingleReg();
    
    

    
