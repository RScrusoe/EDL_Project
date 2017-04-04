
#### FINAL ###

from time import sleep
import serial
arduino = serial.Serial('/dev/ttyACM1', 9600) # Establish the connection on a specific port
counter = 32 # Below 32 everything in ASCII is gibberish
arduino.write(b"My name is Crusoe!")
while True:
    counter +=1
    x = bytes([counter]) 
    arduino.write(x)
    inData = str(arduino.readline()) # Convert the decimal number to ASCII then send it to the Arduino
    inData = inData[2:-5]
    print (inData) # Read the newest output from the Arduino
    #sleep(.1) # Delay for one tenth of a second
    if counter == 128:
        counter = 32




# import serial

# ser = serial.Serial('/dev/ttyACM0',9600)
# x = []
# while(len(x) < 5):
#   x.append(str(ser.readline()))

# print(x)


# import serial, time
# arduino = serial.Serial('/dev/ttyACM0',9600, timeout=.1)
# time.sleep(1) #give the connection a second to settle
# arduino.write(b"Hello from Python!")
# while True:
#   data = str(arduino.read())
#   data = str(data)
#   data = data + data
#   if data:
#       print (data[2:]) #strip out the new lines for now
#                    # (better to do .read() in the long run for this reason

