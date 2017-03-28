from time import sleep
import matplotlib.pyplot as plt
import serial
arduino = serial.Serial('/dev/ttyACM1', 9600) # Establish the connection on a specific port
#counter = 32 # Below 32 everything in ASCII is gibberish
#arduino.write(b"My name is Crusoe!")
data =[]
while True:
    #x = bytes([counter]) 
    #arduino.write(x)
    inData = str(arduino.readline()) # Convert the decimal number to ASCII then send it to the Arduino
    inData = inData[2:-5]
    inData = inData.replace("\\t"," ")
    inData = inData.split()
    
    print (inData) # Read the newest output from the Arduino
    #sleep(.1) # Delay for one tenth of a second
    data.append(inData)
    if(float(inData[0]) >= 4.90):
    	
    	print('End of series detected.')
    	break

print('Extracting x values... ')

x = [float(i[1]) for i in data]
print('Extracting y values... ')
y = [float(i[2]) for i in data]


plt.plot(x,y)
plt.show()