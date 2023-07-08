import cv2
import serial

###### constants #####
ser = serial.Serial('/dev/ttyACM0', 9600)
frameWidth = 640
frameHeight = 480
color = (255,0,255)
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

##### set camera #####
cap = cv2.VideoCapture(0)
cap.set(3,frameWidth)
cap.set(4,frameHeight)
cap.set(10,100)

##### take input #####
while True:
    success, img = cap.read()
    img_gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    num_faces = face_cascade.detectMultiScale(img_gray,1.1,4)

    if len(num_faces)>0:
        (x,y,w,h) = num_faces[0]
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        write = '(' + str(x) + ',' + str(y) + ')\n'
        write_encoded = write.encode('utf-8')
        print(write_encoded)
        ser.write(write_encoded)
        
    
    cv2.imshow('result',img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
ser.close()

