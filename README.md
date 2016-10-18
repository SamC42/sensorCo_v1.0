# sensor_co


Command to insert data into a collection from a meteor mongo console
db.sensors.insert({name: "Sense 1", val: "2"});

Command to get Mongdbc connect example working: (As sudo)
su -c "echo /usr/local/lib > /etc/ld.so.conf.d/mongoc.conf"
su -c "ldconfig"
