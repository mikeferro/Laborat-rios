    ##tratamento de imagem
    import os
    from os import path
    import numpy as np
    #from PIL import Image
    import cv2
    from pathlib import Path
    import sys
    import array as arr
    
    
    def  findcircles():
    #     
    #     cv2.imshow('red',r)
    #     
    #     
    #     img = cv2.medianBlur(gray,5)
    #     cimg = cv2.cvtColor(img,cv2.COLOR_GRAY2BGR)
    #     
    #     #HoughCircles(imageGray, circles, CV_HOUGH_GRADIENT, 1, imageGray.rows /4, 100, 30, 0, 20);
    #     #circles = cv2.HoughCircles(img,cv2.HOUGH_GRADIENT,1,gray.rows /4, 100, 30, 0, 20)
    #     circles = cv2.HoughCircles(img,cv2.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=5,maxRadius=5)
    #   
    #     circles = np.uint16(np.around(circles))
    #     for i in circles[0,:]:
    #         # draw the outer circle
    #         cv2.circle(cimg,(i[0],i[1]),i[2],(0,255,0),2)
    #         # draw the center of the circle
    #         cv2.circle(cimg,(i[0],i[1]),2,(0,0,255),3)
    #     cv2.imshow('detected circles',cimg)
        
    #    output = src.copy()
    #    gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
    #    circles = cv2.HoughCircles(gray,cv2.HOUGH_GRADIENT, 1.2, 100)
    #    
    #    # ensure at least some circles were found
    #    if circles is not None:
    #	     # convert the (x, y) coordinates and radius of the circles to integers
    #       circles = np.round(circles[0, :]).astype("int")
    #       print("aqui")
    #	        # loop over the (x, y) coordinates and radius of the circles
    #       for (x, y, r) in circles:
    #                 # draw the circle in the output image, then draw a rectangle
    #		         # corresponding to the center of the circle
    #		      cv2.circle(output, (x, y), r, (0, 255, 0), 4)
    #		      cv2.rectangle(output, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)
    # 
    #    cv2.imshow("output", np.hstack([src, output]))
         gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
         cv2.imshow('gray',gray)
         cv2.imshow('src',src)
         img = cv2.medianBlur(gray,5)
         cimg = cv2.cvtColor(img,cv2.COLOR_GRAY2BGR)
         circles=[]
    #    circles = cv2.HoughCircles(src,cv2.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=5,maxRadius=5)
         circles = cv2.HoughCircles(gray,circles,cv2.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=5,maxRadius=5)
         circles = np.uint16(np.around(circles))
         for i in circles[0,:]:
             # draw the outer circle
             cv2.circle(cimg,(i[0],i[1]),i[2],(0,255,0),2)
             # draw the center of the circle
             cv2.circle(cimg,(i[0],i[1]),2,(0,0,255),3)
         cv2.imshow('detected circles',cimg)
         
         
         
         
         
         
    def loadImage():
        #path
        path1 = 'C:\\ImagensPeca\opencv.png'
        #Check for item existence and type
        existe = str(path.exists(path1))
        if (existe=="True"):
            print ("Loading image")
            # Load an color image
            src = cv2.imread(path1)
            return src
        else:
            print ("Error loading image")
            sys.exit(0)
            
    if __name__== "__main__":
      # Load an color image 
      src = loadImage() 
      
      
      # Do an split of image 
      b,g,r = cv2.split(src)
      #call a findcirles funtion 
      findcircles()
      #show all imshow
      cv2.waitKey(0)
      #print end when finish the cod
      print("end")
      
