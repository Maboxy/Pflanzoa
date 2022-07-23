

using namespace std;

class Pflanze{
    private:
      String name;
      int Feuchtigkeit;
      int Dauer;
      
    public:
      Pflanze();
      ~Pflanze();
      void getDauer();
      
    
     
  };

 Pflanze::Pflanze(String name_, int Feuchtigkeit_, int Dauer_){
  name = name_;
  Feuchtigkeit = Feuchtigkeit_;
  Dauer = Dauer_;
  }

 void Pflanze::getDauer(){
  return Dauer;
  }


void setup() {
  // put your setup code here, to run once:

  Pflanze* Basili = new Pflanze();
  pinMode(12, OUTPUT);
  

}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);


}
