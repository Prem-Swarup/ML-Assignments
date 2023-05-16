import time
import numpy as np



def multipyUsingNp(a, b):
    #function to multiply matrices using numpy
    assert len(a[0]) == len(b)
    return np.dot(a, b)





f1 = open("HaKaPr_input.txt", "r") #input file which contain matrices to multiply
tb = open("t_c.txt", "w")   #file to write time taken for multiplying various matrices using simply user defined python function


c1, c2 = map(int, f1.readline().split())    #total input matrices = c1+c2
total = int((c1+c2)/2)  #total multiplication that will occur = (c1+c2)/2


t_b = time.time()

for i in range(total):
    #reading matrices from input file and multiplying them using various methods and recording time taken in milliseconds
    n, m = map(int, f1.readline().split())
    m1 = np.random.randint(1,2,size=(n, m))
    for j in range(n) :
        m1[j] = f1.readline().split() ;
    

    n, m = map(int, f1.readline().split())
    m2 = np.random.randint(1,2,size=(n, m))
    for j in range(n) :
        m2[j] = f1.readline().split() ;
    

    t_b = 0     
    for j in range(5) : #running loop 5 times to get proper average
        t_b -= time.time()
        multipyUsingNp(m1, m2)
        t_b += time.time() 
        
       
    t_b *= 200  #multiplying time recorder by 200 to get time in milliseconds
    
    tb.write(str(t_b)+" ")  #writing recorded time in file
    
