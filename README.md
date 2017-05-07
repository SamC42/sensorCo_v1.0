# Sensor Co System
This is a Sensor system to practice with IOT based protocols. The model is based on the CAN protocol.

#### Ensure you have the following installed
1. Meteor: https://install.meteor.com/ | sh


#### Steps to Run 
1. Start the Server: 
	* `cd /hardware/src/v1.0/server`
	* `./Server`
2. Start the Client
	* `cd /hardware/src/v1.0/client`
	* `./client -s`
	*  Enter 16 bytes starting with 'e' (i.e. eeeeeeeeeeeeeeee)


**What you are seeing currently is the client or 'sensor' sending data to the server.**


### Version 1
<hr>
1. Working Server on the RPi Two
2. Working Sensor Sending Data to the RPi via wired connection

#### Useful Help

Command to insert data into a collection from a meteor mongo console
db.sensors.insert({name: "Sense 1", val: "2"});

Command to get Mongdbc connect example working: (As sudo)
su -c "echo /usr/local/lib > /etc/ld.so.conf.d/mongoc.conf"
su -c "ldconfig"

Installing on RPi

1. Download Code from github
2. Download Meteor: curl https://install.meteor.com/ | sh