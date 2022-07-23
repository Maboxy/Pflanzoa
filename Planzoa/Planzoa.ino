#include <ArduinoSTL.h>

using namespace std;

//Pflanzen Klasse mittler der einzelnen Pflanzen erstellt und relevamte Paramater vergeben werden können
class Pflanze {
  private:
    String name;
    int Feuchtigkeit;
    int Dauer;
    int Pin;
    int SensorPin;

  public:
    Pflanze(String name_ = "Test", int Feuchtigkeit_ = 50, int Dauer_ = 1000, int Pin_ = 0, int SensorPin_ = A0);
    ~Pflanze();
    int getDauer();
    int getFeuchtigkeit();
    int getPin();
    int getSensorPin();



};

//Konstruktor
Pflanze::Pflanze(String name_, int Feuchtigkeit_, int Dauer_, int Pin_, int SensorPin_) {
  name = name_;
  Feuchtigkeit = Feuchtigkeit_;
  Dauer = Dauer_;
  Pin = Pin_;
  SensorPin = SensorPin_;
}

int Pflanze::getDauer() {
  return Dauer;
}

int Pflanze::getFeuchtigkeit() {
  return Feuchtigkeit;
}

int Pflanze::getPin() {
  return Pin;
}

int Pflanze::getSensorPin(){
  return SensorPin;
  }



void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);

  vector<Pflanze*> *Pflanzen = new vector<Pflanze*>;

  Pflanzen->push_back(new Pflanze("Basili", 500, 3000, 12, A0));
  Pflanzen->push_back(new Pflanze("Boni", 500, 2000, 13, A1));
  Pflanzen->push_back(new Pflanze("Minzi", 500, 2000, 8, A2));
  Pflanzen->push_back(new Pflanze("Risi", 500, 2000, 7, A3));
  digitalWrite(12, HIGH);


  RunScript(Pflanzen);
}

//Funktion enthaehlt den eigentlichen Programablauf
void RunScript(vector<Pflanze*> *Pflanzen) {

  //Endlosschleife bis zum Reset des Controllers
  while (true) {
    //Schleife geht alle Pflanzen durch
    for (int i = 0; i < Pflanzen->size(); i++) {
      //Feuchte Wert des Sensors zur Pflanze
      int Wert = analogRead(Pflanzen->at(i)->getSensorPin());

      //Ausgabe des Wertes an den SerialMonitor
      Serial.println(Wert);

      //Mittelwert aus 5 Werten ermittlen
      for(int a = 0; a < 4; a++){
        Wert += analogRead(Pflanzen->at(i)->getSensorPin());
        }

        Wert = Wert/ 5;

        Serial.println("Mittelwert= "+ Wert);
       

      //Fuer jede Pflanze die Feuchtigkeit ueberpruefen und ggf. Waessern ´
      if (analogRead(Wert) > Pflanzen->at(i)->getFeuchtigkeit() ) {
        Serial.println(Wert);
        digitalWrite(Pflanzen->at(i)->getPin(), LOW);
        delay(Pflanzen->at(i)->getDauer());
        digitalWrite(Pflanzen->at(i)->getPin(), HIGH);
      }

      

    }



  }
}
