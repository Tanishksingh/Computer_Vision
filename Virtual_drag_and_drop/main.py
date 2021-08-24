import cvzone
import cv2
import numpy as np
from cvzone.HandTrackingModule import HandDetector
cap= cv2.VideoCapture(0)
cap.set(3,1180)
cap.set(4,720)
detector=HandDetector(detectionCon=0.8)
colorR=(255,0,0)

cx , cy , w , h =100 , 100 , 150 , 150

class DragShape():
    def __init__(self,posCenter,size=[150,150]):
        self.posCenter =posCenter
        self.size =size

    def update(self,cursor):
        cx,cy=self.posCenter
        w,h =self.size

        #if the finger tip(index) is in the rectangle area
        if cx - w // 2 < cursor[0] < cx + w // 2 and \
                cy - h // 2 < cursor[1] < cy + w // 2:

            self.posCenter = cursor
rectList=[]
for x in range(5):
    rectList.append(DragShape([x*200+150,150]))

while True:
    sucess, img= cap.read()
    img= cv2.flip(img,1)
    img= detector.findHands(img)
    lmList, _ =detector.findPosition(img)
    if lmList:

        l, _ ,_=detector.findDistance(8,12,img,draw=False)
        print(l)
        if l<20:
            cursor=lmList[8]#index finger tip pos
            #call the update herer
            for rect in rectList:
                rect.update(cursor)
   #draw for solid
    # for rect in rectList:
    #     cx, cy = rect.posCenter
    #     w, h = rect.size
    #     cv2.rectangle(img,(cx-w//2,cy-h//2),(cx+w//2,cy+h//2),colorR,cv2.FILLED)
    #     cvzone.cornerRect(img,(cx-w//2,cy-h//2,w,h),20,rt=0)

    #draw with transparent blockss
    imgNew=np.zeros_like(img,np.uint8)
    for rect in rectList:
        cx, cy = rect.posCenter
        w, h = rect.size
        cv2.rectangle(imgNew,(cx-w//2,cy-h//2),(cx+w//2,cy+h//2),colorR,cv2.FILLED)
        cvzone.cornerRect(imgNew,(cx-w//2,cy-h//2,w,h),20,rt=0)
    out =img.copy()
    alpha = 0.3
    mask= imgNew.astype(bool)
    out[mask]= cv2.addWeighted(img,alpha,imgNew, 1-alpha, 0)[mask]



    cv2.imshow('IMAGE',out)
    cv2.waitKey(1)
