#include <ArduinoSTL.h>

using namespace std;

//Pflanzen Klasse mittler der einzelnen Pflanzen erstellt und relevamte Paramater vergeben werden können
class Pflanze {
  private:
    String name;
    int Feuchtigkeit;
    int Dauer;
    int Pin;

  public:
    Pflanze(String name_ = "Test", int Feuchtigkeit_ = 50, int Dauer_ = 1000, int Pin_ = 0);
    ~Pflanze();
    int getDauer();
    int getFeuchtigkeit();
    int getPin();



};

//Konstruktor
Pflanze::Pflanze(String name_, int Feuchtigkeit_, int Dauer_, int Pin_) {
  name = name_;
  Feuchtigkeit = Feuchtigkeit_;
  Dauer = Dauer_;
  Pin = Pin_;
  }

int Pflanze::getDauer() {
  return Dauer;
}

int Pflanze::getFeuchtigkeit() {
  return Feuchtigkeit;
}

int Pflanze::getPin(){
  return Pin;
  }


void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);

  vector<Pflanze*> *Pflanzen = new vector<Pflanze*>;

  Pflanzen->push_back(new Pflanze("Basili", 1000, 3000, 12));
  Pflanzen->push_back(new Pflanze("Boni", 1000, 2000, 13));
  digitalWrite(12, HIGH);


  test(Pflanzen);
}

void test(vector<Pflanze*> *Pflanzen) {

  while (true) {
    /*
      digitalWrite(12, HIGH);
      delay(Basili->getDauer());
      digitalWrite(12, LOW);
      delay(Basili->getDauer()); */

    int Wert = analogRead(A0);

    Serial.println(Wert);



    for (int i = 0; i < Pflanzen->size(); i++) {

      if (Wert > Pflanzen->at(i)->getFeuchtigkeit() ) {
        digitalWrite(Pflanzen->at(i)->getPin(), LOW);
        delay(Pflanzen->at(i)->getDauer());
        digitalWrite(Pflanzen->at(i)->getPin(), HIGH);
      }
      
    }



  }
}
