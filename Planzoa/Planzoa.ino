#include <ArduinoSTL.h>

using namespace std;

class Pflanze {
  private:
    String name;
    int Feuchtigkeit;
    int Dauer;

  public:
    Pflanze(String name_ = "Test", int Feuchtigkeit_ = 50, int Dauer_ = 1000);
    ~Pflanze();
    int getDauer();



};

Pflanze::Pflanze(String name_, int Feuchtigkeit_, int Dauer_) {
  name = name_;
  Feuchtigkeit = Feuchtigkeit_;
  Dauer = Dauer_;
}

int Pflanze::getDauer() {
  return Dauer;
}


void setup() {
  // put your setup code here, to run once:

  Pflanze* Basili = new Pflanze("Basili", 10, 500);
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);

  vector<Pflanze*> *Pflanzen = new vector<Pflanze*>;

  Pflanzen->pushBack(new Pflanze("Basili", 1000, 2000));

  

  test(Basili);
}

void test(Pflanze *Basili) {

  while (true) {
    /*
      digitalWrite(12, HIGH);
      delay(Basili->getDauer());
      digitalWrite(12, LOW);
      delay(Basili->getDauer()); */

    int Wert = analogRead(A0);

    Serial.println(Wert);



  }
}
