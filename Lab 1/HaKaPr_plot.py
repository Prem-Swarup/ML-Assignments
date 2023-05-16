# importing libraries
import numpy as np 
import matplotlib.pyplot as plt


# reading the run time of various method calls
filename_a = "t_a.txt"
times_a = np.loadtxt(filename_a)

filename_b = "t_b.txt"
times_b = np.loadtxt(filename_b)

filename_c = "t_c.txt"
times_c = np.loadtxt(filename_c)

filename_d = "t_d.txt"
times_d = np.loadtxt(filename_d)

filename_x = "HaKaPr_x.txt"
x = np.loadtxt(filename_x)

# list of run times of square matrices multiplication
t_a_sq = []
t_b_sq = []
t_c_sq = []
t_d_sq = []
x_sq = []

for i in range (25):
    t_a_sq.append(times_a[i])
    t_b_sq.append(times_b[i])
    t_c_sq.append(times_c[i])
    t_d_sq.append(times_d[i])
    x_sq.append(x[i])


# list of run times of rectangular matrices multiplication
t_a_rec = []
t_b_rec = []
t_c_rec = []
t_d_rec = []
x_rec = []


for i in range (26, 35):
    t_a_rec.append(times_a[i])
    t_b_rec.append(times_b[i])
    t_c_rec.append(times_c[i])
    t_d_rec.append(times_d[i])
    x_rec.append(x[i])



# plot for run time of square matrices 
plt.figure(1)
plt.plot(x_sq, t_a_sq, color = 'red', label='Using native cpp')
plt.plot(x_sq, t_b_sq, color = 'blue', label="Using native python")
plt.plot(x_sq, t_c_sq, color = 'green', label="Using numpy in python")
plt.plot(x_sq, t_d_sq, color = 'yellow', label="Using boost library in cpp invoked from python")
plt.xlabel("row/column size of square matrix")
plt.ylabel("time in ms")
plt.legend(loc ="upper left")
plt.title("time v/s row size of square matrix for multiplication")
plt.show()

# plot for run time of rectangular matrices 
plt.figure(2)
plt.plot(x_rec, t_a_rec, color = 'red', label="Using native cpp")
plt.plot(x_rec, t_b_rec, color = 'blue', label="Using native python")
plt.plot(x_rec, t_c_rec, color = 'green', label="Using numpy in python")
plt.plot(x_rec, t_d_rec, color = 'yellow', label="Using boost library in cpp invoked from python")
plt.xlabel("row1*col1*col2 of matrix1 and matrix2")
plt.legend(loc ="upper left")
plt.ylabel("time in ms")
plt.title("time v/s row1*col1*row2 of rectangular matrices for multiplication")
plt.show()
