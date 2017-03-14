# import serial

# ser = serial.Serial('/dev/ttyACM0',9600)
# x = []
# while(len(x) < 5):
# 	x.append(str(ser.readline()))

# print(x)


import serial, time
arduino = serial.Serial('/dev/ttyACM0',9600, timeout=.1)
time.sleep(1) #give the connection a second to settle
arduino.write(b"Hello from Python!")
while True:
	data = arduino.readline()
	if data:
		print (data) #strip out the new lines for now
		# (better to do .read() in the long run for this reason