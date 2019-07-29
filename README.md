# PRÁCTICA 1 - PROCESOS #

# Santiago Bedoya Betancur
# Lina María Uribe

## 1. Objetivos ##
- [x] Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
- [x] Codificar programas que hagan uso del API de procesos.

## 2. Actividades previas al laboratorio ##
- [x] Leer el capítulo 5 del libro guía y comprender las diapositivas de clase asociadas a este capitulo.

## 3. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
	  > El valor de la variable del proceso hijo es el mismo, ```x = 100```
	  
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
	  > Cuando el proceso hijo y el padre cambian el valor de ```x```, es indiferente, independiente para cada uno. Esto se da por lo que la función ```fork()``` crea una copia exacta del padre en el hijo (a excepción de su PID) en el momento que es llamado, y de ahí en adelante continúan como procesos totalmente independientes.

2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
	  > Si, tanto el padre como el hijo pueden acceder al file descriptor dada la misma razón de la pregunta anterior *("la función ```fork()``` crea una copia exacta del padre en el hijo (a excepción de su PID) en el momento que es llamado, y de ahí en adelante continúan como procesos totalmente independientes")*.
	  
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
	  >  Cuando se hace un ```fork()``` el proceso hijo hereda una copia del file descriptor. El kernel agenda los procesos de manera independiente, por tanto, puede llegar a tener líneas del archivo escritas de manera intercalada por el padre y sus procesos hijos.

3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar;
* ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
	>	Se podría asegurar que el proceso hijo imprima en primer lugar si después de la llamada fork() se usa un sleep() en el padre, haciendo que este último imprima su mensaje tiempo después.

4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?

5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. 
*	¿Cuál es el valor de retorno de la función ```wait()```? 
	>	Se tiene como pre requisito la llamada a un ```fork()```. El valor de retorno de la función ```wait()``` es el PID del hijo.
	
*	¿Qué pasa si usted usa la función ```wait``` en el hijo?
	>	Al usar la función ```wait()``` en el hijo, inmediatamente retorna **-1**, y esto sucede porque el proceso hijo no tiene ningún proceso secundario.

6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. 
*	¿Cuándo podría ser ```waitpid()``` útil?
	>	Podría ser de mucha utilidad cuando un proceso padre, tiene más de un proceso hijo, dado a que la función ```waitpid()```espera a que termine un proceso hijo especifico, esto lo hace mediante uno de sus argumentos, el cual solicita el PID del proceso hijo que se va a esperar.

7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estándar (```STDOUT FILENO```). 
*	¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
	> Cuando el hijo cierra su salida estándar e intenta ejecutar un ```printf()```, no se imprime nada en la consola.

8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```
	> ¡Hecho!
