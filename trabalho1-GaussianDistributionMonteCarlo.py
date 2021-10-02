from numpy import random, sqrt, log, sin, cos, pi
from pylab import show,hist,subplot,figure

# transformation function
def gaussian(u1,u2,mu,sigma):
  gauss = sqrt(-2*log(u1))*cos(2*pi*u2)
  gauss= mu+gauss*sigma
  return gauss


# numebr of iterations
iterations = 10000000;
seed = 64
bins = 100
figSize = 7
# uniformly distributed values between 0 and 1

random.seed(seed)
u1 = random.rand(iterations)
u2 = random.rand(iterations)
# run the transformation
g1 = gaussian(u1,u2,0,0.5)
g2 = gaussian(u1,u2,1,1.8)
g3 = gaussian(u1,u2,-1,1)
g4 = gaussian(u1,u2,2,0.1)
# plotting the values before and after the transformation
figure(figsize=(figSize,figSize))
ax1=subplot(221)   
hist(u1,bins)     
ax1.set_title("r1 dataset")

ax2=subplot(222)     
hist(u2,100)    
ax2.set_title("r2 dataset")


ax3=subplot(212)    
hist(g1,bins,histtype="step") 
hist(g2,bins,histtype="step") 
hist(g3,bins,histtype="step") 
hist(g4,bins,histtype="step") 
ax3.set_xlim([-4, 5]) 
ax3.legend(["mu 0 sig 0.5","mu 1 sig 1.8","mu -1 sig 1","mu 2 sig 0.1"], frameon=False)   
ax3.set_title("Monte Carlo Gaussian")




#the exponential distribution


def exp(u3,lamb):
    #e = sqrt(-2*log(u3))
    e = -log(1-u3)/lamb
    return e

# uniformly distributed values between 0 and 1
u3 = random.rand(iterations)
# run the transformation
z2 = exp(u3,2)
z3 = exp(u3,4)
z4 = exp(u3,7)
z5 = exp(u3,3)


figure(figsize=(figSize,figSize))
ax4=subplot(211)    
hist(u1,150)     
ax4.set_title("r3 dataset - seed 64 ")

ax5=subplot(212)  
hist(z5,bins,histtype="step")    
hist(z2,bins,histtype="step")  
hist(z3,bins,histtype="step") 
hist(z4,bins,histtype="step")   
ax5.set_xlim([0, 3.5])     
ax5.legend(["lambda = 1.5","lambda = 3","lambda = 4","lambda = 7"], frameon=False, loc=1)
ax5.set_title("Monte Carlo inverted exponential ")

show()
