//Programa para el funcionamiento de la maqueta de una tolva

boolean encendido=0; //Determina si esta funcionando o no
int a;
void setup() {

  pinMode (8, OUTPUT);   //Diretion
  pinMode (9, OUTPUT);   //Step
  pinMode (2, INPUT);    //Pulsador Parada
  pinMode (3, INPUT);    //Pulsador Arranque
  pinMode(10, OUTPUT);   //Led Rojo Parada
  pinMode(11, OUTPUT);   //Led Verde Funcionando
  
  digitalWrite(9, LOW);   //Pasos del Motor PaP en 0 
  digitalWrite(8, LOW);   //Dirección del Motor PaP en 0

  digitalWrite(11, LOW);
    for(a==0; a<=4; a++){
    digitalWrite(10, HIGH);
    delay(300);
    digitalWrite(10, LOW);
    delay(300);
    }
  digitalWrite(10, HIGH);
}
// Programa Blik: Con dos pulsadores controlamos la marcha y paro del motor NEMA 17
void loop() {
  
  while(encendido==1){
    digitalWrite(9, HIGH);    // Blink Encendido
    delay(5);                 // Velocidad Movimiento del Motor
    
    if(digitalRead(2)==1){    // Si pulsamos el 2 para el Blink
      encendido=0;
      digitalWrite(10, HIGH);  //Encendemos Led Rojo
      digitalWrite(11, LOW);   //Apagamos Led Verde
    }
    digitalWrite(9, LOW);     // Blink apagado
    delay(5);                 // Velocidad Movimiento del Motor
  }
  if(digitalRead(3)==1){      // Si pulsamos el 3 vuelve a funcionar
    encendido=1;
     digitalWrite(11, HIGH);  // Encendemos Led Verde
     digitalWrite(10, LOW);   // Apagamos Led Rojo
  }
}
