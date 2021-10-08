# -*- coding: utf-8 -*-
"""
Created on Wed Sep 29 19:35:19 2021

"""

#import libraries
from numpy import random,sqrt, sin, cos, pi
from pylab import show,hist,subplot,figure
from matplotlib import pyplot
from mpl_toolkits.mplot3d import Axes3D


numPoints=100000
random.seed(68)
bins =25
A=[]  

#Uniform Spherical Distribution Generator
def generator(numPoints):
    theta = random.rand(numPoints)*2*pi
    z = random.rand(numPoints)*2-1
    
    x = sqrt(1-z**2)*cos(theta)
    y = sqrt(1-z**2)*sin(theta)
    return[x,y,z]



A = generator(numPoints)
    
#Drawing histogram
figure(figsize=(10,10))
ax4=subplot(211)    
hist(A[0],bins,histtype="step")  
hist(A[1],bins,histtype="step")        
hist(A[2],bins,histtype="step")     
ax4.legend(["x","y","z"], frameon=True, loc=1)
ax4.set_title("r3 dataset - seed 64 ")
show()


#Drawing spherical distribution
fig = pyplot.figure()
ax = Axes3D(fig)
ax.scatter(A[0],A[1],A[2],s=1, color="k")
ax.legend(["Uniform Datapoints"], frameon=True, loc=1)
ax.set_title('isotropic source') 
show()





