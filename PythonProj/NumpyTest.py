
import numpy as np

a = np.array([[[1,3,2],[3,4,5]]])
# a = np.linspace(1,10,10)
b = a[0][0]
c = np.ones((3,2,1),dtype=int)
d = np.arange(1,10,1)
print(a)
print(a.ndim)
print(c.ndim)
