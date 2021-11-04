import os
import random
archivo = open("datos.txt", "w")
for i in range (100000000):
    x=str(random.randint(1,100000000))
    archivo.write(x+'\n')

archivo.close()
