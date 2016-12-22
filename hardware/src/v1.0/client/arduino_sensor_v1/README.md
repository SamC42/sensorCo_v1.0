sudo raspi-config
sudo apt-get install i2c-tools
sudo i2cdetect -y 1
add 
 i2c-bcm2708
 i2c-dev
to sudo nano /etc/modules

add
dtparam=i2c1=on
dtparam=i2c_arm=on

sudo apt-get install python-smbus
