# -*- coding: utf-8 -*-
"""
Created on Wed Sep 29 19:35:19 2021

@author: gongou00@gmail.com
"""

#import libraries

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from numpy import random,sqrt, log, sin, cos, pi, array
from pylab import show,hist,subplot,figure
import pandas as pd

numArrows=100000
random.seed(68  )
bins =30


#set random numbers
r1 = random.rand(numArrows)*2*pi
r2 = random.rand(numArrows)*pi
    
#coordenadas esfericas
x= cos(r1)*sin(r2)
y= sin(r1)*sin(r2)
z= cos(r2)
size= sqrt(x**2+y**2+z**2)


# set plots
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.quiver([0],[0],[0],[x],[y],[z],linewidths=0.1,edgecolors= "k",length=2)


ax.set_xlim3d([-2.0, 2.0])
ax.set_xlabel('X')

ax.set_ylim3d([-2.0, 2.0])
ax.set_ylabel('Y')

ax.set_zlim3d([-2, 2])
ax.set_zlabel('Z')

ax.set_title('isotropic source') 
plt.show()


figure(figsize=(10,10))
ax4=subplot(211)    
hist(x,bins,histtype="step")  
hist(y,bins,histtype="step")     
hist(z,bins,histtype="step")     
ax4.legend(["x","y","z"], frameon=True, loc=1)

ax4.set_title("r3 dataset - seed 64 ")
show()


#
A=[]
for i in range(numArrows):
    A.append([round(x[i],3),round(y[i],3),round(z[i],3), round(size[i],3)])

numpy_array = array(A)

df = pd.DataFrame(numpy_array, columns=["x","y","z","length"])
df.loc[:4].style.set_properties(**{'background-color': 'black',
                           'color': 'lawngreen',
                           'border-color': 'white'})

#prient first 40 dataset points
print(df.head(40))

