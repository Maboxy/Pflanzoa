#include <ArduinoSTL.h>

using namespace std;

//Pflanzen Klasse mittler der einzelnen Pflanzen erstellt und relevamte Paramater vergeben werden können
class Pflanze {
  private:
    String name;
    //In Prozent
    int Feuchtigkeit;
    //In s
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

int Pflanze::getSensorPin() {
  return SensorPin;
}



void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);

  vector<Pflanze*> *Pflanzen = new vector<Pflanze*>;

  Pflanzen->push_back(new Pflanze("Basili", 50, 3, 12, A0));
  // Pflanzen->push_back(new Pflanze("Bonsi", 50, 2, 13, A1));
  // Pflanzen->push_back(new Pflanze("Minzi", 50, 2, 8, A2));
  // Pflanzen->push_back(new Pflanze("Risi", 50, 2, 7, A3));
  digitalWrite(12, HIGH);


  RunScript(Pflanzen);
}


//Funktion enthaehlt den eigentlichen Programablauf
void RunScript(vector<Pflanze*> *Pflanzen) {

  const int trocken = 775;

  const int nass = 408;

  //Endlosschleife bis zum Reset des Controllers
  while (true) {
    //Schleife geht alle Pflanzen durch
    for (int i = 0; i < Pflanzen->size(); i++) {
      //Feuchte Wert des Sensors zur Pflanze

      double Wert = 0;

      double pWert = 0;


      Wert = analogRead(Pflanzen->at(i)->getSensorPin());



      pWert = map(Wert, nass, trocken, 100, 0);





      Serial.println("pWert:");
      Serial.println(pWert);


      //Fuer jede Pflanze die Feuchtigkeit ueberpruefen und ggf. Waessern ´
      if (pWert < Pflanzen->at(i)->getFeuchtigkeit() ) {
        Serial.println("Zu trocken!");
        digitalWrite(Pflanzen->at(i)->getPin(), LOW);
        //Von s auf ms
        delay(Pflanzen->at(i)->getDauer() * 1000);
        digitalWrite(Pflanzen->at(i)->getPin(), HIGH);
      }
  

      delay(1000);

    }
    //ca. 24h warten.
   // delay(87400);
  }
}
