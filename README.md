<h1 align="center">:snowflake: ArduinoUno X HC-05 :snowflake:</h1>
<p align="center"> 
Esta proyecto Tiene el Proposito de Comunicar Correctamente un ArduinoUno(Original o Clon) con un Modulo Bluetooth HC-05 o HC-06
<p/>

</div>

# Diagrama de Referencia
![](./img/img-referencia.png)

<p/>
# Components
| *ArduinoUno*                          |
| *Modulo HC-05*                        |
| *Diodos Led(Rojo, Verde, Amarillo)*   |
| *Resistencias de 230 Ohms*            |
| *Jumpers(Cables)*                     |

# A Tomar En Cuenta
## Debido a que uso la Libreria SoftwareSerial, se liberaron los pines 0 (RX) y 1 (TX) para cargar código sin necesidad de Desconectarlos durante la subida del codigo al Arduino(Ya que de lo contrario habrian problemas con el Puerto USB, impidiendo la Subida del Codigo).
## Es necesaria una Aplicacion para Controlar todo Esto desde tu un Dispositivo con Bluetooth, unicamente lo Probe en Android y la unica Pieza de Software que me dejaba conectar correctamente el Modulo HC-05 era [Serial Bluetooth Terminal][Serial Bluetooth Terminal]



[Serial Bluetooth Terminal]: https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=es_MX&pli=1
