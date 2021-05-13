# **PRACTICA 8 : Buses de comunicación IV**

## **EJERCICIO PRÁCTICO 1: BUCLE COMUNICACIÓN UART**
  
Para esta práctica hemos tenido que desarrollar un código sencillo con el cual poder enviar datos por el bus UART0 que hay en el esp32 y recibirlos por el UART2 conectado a las salidas *GPIO 16,17*.
Una vez recibidos, enviarlos otra vez al UART0.  
Vamos a proceder a explicar el void setup() que en esta práctica es muy sencillo.
  
  ### **void setup()**

  ```cs
#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);
    Serial.write("Inicializando...");
}
  ```

Creamos dos objetos de la clase Serial y les llamamos Serial y Serial2. Los configuramos con un baut rate de 9600.

En el void loop() es donde voy a proceder a hacer la función principal de esta práctica.
  
  ### **void loop()**
  ```cs
void loop() {
  if(Serial.available()){
    Serial2.write(Serial.read());
    delay(10);
    if(Serial2.available()){
      Serial.write(Serial2.read());
    }
  }
}
  ```
Primero de todo con la función available(), miramos si hay algo disponible para leer desde el serial port del UART0.
En este momento nosotros podemos escribir cualquier cosa y se guardará en el buffer.
Eso que está en el buffer lo escribirá el UART2 con la función *write()*. Como tenemos los puertos de recepción y transmisión del UART2 cortocircuitados, eso que se transmita con *write()* se recibirá al mismo UART2 con *available()*, eso es precisamente lo que hacemos en este momento.
Hasta este punto tenemos guardado en el buffer lo que hemos enviado y nuevamente con la función *read()* leemos lo que hay en el buffer del UART2 y lo escribimos por el puerto serie del UART0.
  
  ## **CONCLUSIONES**
  
  No he tenido muchos problemas a la hora de realizar esta práctica ya que una vez pensado el funcionamiento del código era bastante sencillo llegar a escribirlo.
  He estado un rato pensando que funciones debería usar y como usarlas pero al poco tiempo he sabido como aplicarlas y no he tenido mayores problemas.
  Algunos compañeros los han tenido a causa del ruido y cuando desconectaban el cortocircuito hecho entre la transmisión y la recepción del UART2 seguían recibiendo datos cuando no debería pasar. Lo dicho, yo no me he encontrado con problemas de ese estilo por lo que ha sido bastante sencillo llegar al resultado final.

Me gustaría haber podido hacer los otros ejercicios ya que me resultaron interesantes, pero me di cuenta tarde de los componentes que hacían falta y no me llegaron a tiempo, de todas formas me lo reservo para proyectos futuros el aprender como funcionan sus librerías y los componentes en si.

  ## Salidas y entradas por consola
  En esta práctica, la salida por consola es la misma que la de la entrada por todo lo explicado anteriormente:
  ### Salidas  

  Inicializando...�Esto es una prueba de la practica 8.

  ### Entradas  

  Esto es una prueba de la practica 8.