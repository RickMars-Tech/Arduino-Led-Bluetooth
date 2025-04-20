//     ___             __      _                __  ___   ______ 
//    /   |  _________/ /_  __(_)___  ____     / / / / | / / __ \
//   / /| | / ___/ __  / / / / / __ \/ __ \   / / / /  |/ / / / /
//  / ___ |/ /  / /_/ / /_/ / / / / / /_/ /  / /_/ / /|  / /_/ / 
// /_/  |_/_/   \__,_/\__,_/_/_/ /_/\____/   \____/_/ |_/\____/                                                              
//
// By @RickMars-Tech
// https://github.com/RickMars-Tech

#include <SoftwareSerial.h>  // Incluye la biblioteca SoftwareSerial

// Configuración de SoftwareSerial: RX en pin 2, TX en pin 3
SoftwareSerial bluetooth(2, 3);  // Pin 2: RX, Pin 3: TX

String Incoming_value = "";  // Variable para almacenar el mensaje recibido

// Variables de estado para rastrear el estado de cada LED
bool estadoRojo = false;    // Estado del LED Rojo (false = apagado, true = encendido)
bool estadoVerde = false;   // Estado del LED Verde
bool estadoAmarillo = false; // Estado del LED Amarillo

void setup() 
{
  Serial.begin(9600);        // Inicializa la comunicación serial para el monitor
  bluetooth.begin(9600);     // Inicializa la comunicación serial para el módulo Bluetooth

  pinMode(13, OUTPUT);       // Configura el pin 13 como salida (LED Rojo)
  pinMode(12, OUTPUT);       // Configura el pin 12 como salida (LED Verde)
  pinMode(11, OUTPUT);       // Configura el pin 11 como salida (LED Amarillo)

  //Serial.println("Sistema listo. Usa el monitor serial o el Bluetooth para enviar comandos.");
}

void loop()
{
  // Verifica si hay datos disponibles desde el Bluetooth
  if (bluetooth.available() > 0)  
  {
    Incoming_value = bluetooth.readString();  // Lee la cadena completa enviada por Bluetooth
    Incoming_value.trim();                    // Elimina espacios en blanco o saltos de línea adicionales
    procesarComando(Incoming_value);          // Procesa el comando recibido
  }

  // Verifica si hay datos disponibles desde el monitor serial
  if (Serial.available() > 0)  
  {
    Incoming_value = Serial.readString();     // Lee la cadena completa enviada por el monitor serial
    Incoming_value.trim();                    // Elimina espacios en blanco o saltos de línea adicionales
    procesarComando(Incoming_value);          // Procesa el comando recibido
  }
}

// Función para procesar los comandos recibidos
void procesarComando(String comando)
{
  Serial.print("Recibido: ");
  Serial.println(comando);

  if (comando == "Rojo") {
    estadoRojo = !estadoRojo;                 // Alterna el estado del LED Rojo
    digitalWrite(13, estadoRojo ? HIGH : LOW); // Enciende o apaga el LED Rojo
  } 
  else if (comando == "Verde") {
    estadoVerde = !estadoVerde;               // Alterna el estado del LED Verde
    digitalWrite(12, estadoVerde ? HIGH : LOW); // Enciende o apaga el LED Verde
  } 
  else if (comando == "Amarillo") {
    estadoAmarillo = !estadoAmarillo;         // Alterna el estado del LED Amarillo
    digitalWrite(11, estadoAmarillo ? HIGH : LOW); // Enciende o apaga el LED Amarillo
  } 
  else if (comando == "Todos") {
    // Enciende todos los LEDs
    estadoRojo = true;
    estadoVerde = true;
    estadoAmarillo = true;
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
  } 
  else if (comando == "Ninguno") {
    // Apaga todos los LEDs
    estadoRojo = false;
    estadoVerde = false;
    estadoAmarillo = false;
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
}
