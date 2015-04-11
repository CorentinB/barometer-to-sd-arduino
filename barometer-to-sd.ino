#include <SD.h>
#include "Wire.h" 
#include "Adafruit_BMP085.h"  // librairie spéciale pour cette famille de capteurs
Adafruit_BMP085 mySensor;  // on crée un objet du type souhaité

float tempC;  // variable qui contiendra la température 
float pression; //variable pour la pression
 
 //A noter : la pression est renvoyé en Pa (Pascal), la météo donne la pression en hectoPascal, suffit d'enlever les 2 derniers chiffres 

File myFile;

void setup()
{
  Serial.begin(9600);
  mySensor.begin();   // communication capteur-arduino
  Serial.println("Capteurs -> SD v1.0");

  Serial.println("Initializing SD card...");

  pinMode(53, OUTPUT);
   
  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  Serial.println("Suppression de l'ancien fichier capteurs.csv...");
  SD.remove("capteurs.csv");
 
  myFile = SD.open("capteurs.csv", FILE_WRITE);
 
  // if open = ok
  if (myFile) {
    Serial.print("Debut de l'ecriture sur capteur.csv...");
    myFile.println("Capteurs -> SD v1.0");
    myFile.println("Recuperation des donnees des capteurs :");
    myFile.println(" ");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Erreur lors de l'ouverture de capteur.csv");
  }
}

void loop()
{
  // Début de l'écriture des données
  tempC = mySensor.readTemperature(); //On lit la temperature 
  pression = mySensor.readPressure(); //et on lit la pression
  
  myFile = SD.open("capteurs.csv", FILE_WRITE);
  myFile.print(millis());
  myFile.println(";");
  myFile.print(tempC);
  myFile.print(";");
  myFile.print(pression);
  myFile.print(";");
  myFile.close();
  //delay(50); //Délai entre 2 relevés
}
