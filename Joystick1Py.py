import serial
import pydirectinput
running = True


arduino = serial.Serial('COM3', 9600, timeout=.1) #COM Port(may need changing), baud rate

pydirectinput.PAUSE = 0

#Key Key: 1:W, 2:A, 3:S, 4:D  (subtract one to get list index)
keys = ['up', 'left', 'down', 'right']
currentInput = 0

def newInput(num):
    try:
        for i in range(4):
            if i==(num-1):
                pydirectinput.keyDown(keys[i])
                continue
            pydirectinput.keyUp(keys[i])
        #pydirectinput.keyUp(keys[num-1])
    except:
        pass

while running:
    try:
        rawData = arduino.readline()
        data = str(rawData.decode('utf-8'))
    except:
        print("Issue reading/decoding arduino")
        running = False

    try:
        inputNum = int(data)
        if(inputNum != currentInput):
            newInput(inputNum)
            currentInput = inputNum
    
    except:
        pass #Sometimes serial port reads nothing, why? Who knows?!