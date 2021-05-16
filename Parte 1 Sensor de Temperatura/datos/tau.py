import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def calcular_tau(t,a,b,tau):
	return 1 - (a*np.exp(-t/tau) + b)

temperaturas = np.loadtxt('./datos_tomados.txt')

#Note que la posicion i-esima corresponde a los ms transcurridos.
#Por ejemplo, para el decimo dato (posicion 9) significa que ha pasado 1 segundo desde que inicio la toma de datos.

tiempo = np.linspace(1/10, len(temperaturas)/10, len(temperaturas))
tiempo_fit = tiempo[99:]
temperaturas_fit = temperaturas[99:]

popt, pcov = curve_fit(calcular_tau, tiempo_fit, temperaturas_fit)

print('El valor de Tau es de {} s'.format(popt[2]))
plt.figure(figsize=(8,8))
ax = plt.gca()
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
#plt.plot(tiempo, temperaturas, '.')
ax.plot(tiempo, temperaturas, color="pink")
ax.plot(tiempo_fit, calcular_tau(tiempo_fit, *popt), 'r-')
plt.title('')
plt.xlabel(r'Tiempo [s]')
plt.ylabel(r'Temperatura [ºC]')
plt.title(r'Temperatura en función del tiempo al ponerle el secador de pelo al sensor')
plt.savefig('./tau.png')

print('La grafica ha sido guardada exitosamente en la ruta: ./tau.png')
print()
"""Podemos considerar el tiempo en que se prendio el secador como el tiempo inicial, t_i, 
a la temperatura T_0. Este tiempo es aproximadamente a los 10 segundos. 
Asimismo, podemos tomar el ultimo dato como el tiempo en que se estabilizo la señal, t_f, a la
temperatura final, t_f. 
"""
#Por una regla de 3 sencilla, podemos darnos cuenta que si el dato en la posicion 9 corresponde a
#1 segundo, el dato en la posicion 99 sera cuando hayan transcurrido 10 segundos. 
t_i = tiempo[99]
t_f = tiempo[-1]
"""
Definimos el tiempo de estabilizacion como el tiempo que tarda el sensor en estabilizarse,
desde el momento en que se empezo a cambiar la temperatura. 
"""
print('El tiempo de estabilizacion del sensor es: {0:.2f} s'.format(t_f - t_i))

