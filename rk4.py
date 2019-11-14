import numpy as np
import matplotlib.pylab as plt

data = np.loadtxt("rk4.dat")
data2 = np.loadtxt("Pro.dat")
                  
plt.figure(figsize=(12,4))
plt.subplot(1,2,1)
plt.title("Proyectil")
plt.xlabel("x")
plt.ylabel("y")

x = data[:,0]
y = data[:,1]

x1 = data2[:,0]
y1 = data2[:,1]

plt.plot(x,y, label = Drag)
plt.plot(x1,y1, label = Sin Drag)
    
plt.legend()
plt.savefig("friccion.png")